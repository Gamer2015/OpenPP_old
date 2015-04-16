#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QMessageBox>

#include <iostream>
#include <fstream>

#include <Utility/String.hpp>

namespace LU = Openpp::Utility;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	mIsScanning(false),
	mIsTesting(false),
	mFailedTest(-1),
	mAllSuccess(false)
{
	ui->setupUi(this);

	SetRangedWidgetVisibility(false);

	mpValidator = new QIntValidator(1, -1, this);
	ui->leBegin->setValidator(mpValidator);
	ui->leEnd->setValidator(mpValidator);
	ui->cbRange->setEnabled(false);

	mpTester = new TesterThread();

	connect(mpTester, SIGNAL(FoundTest(QString)), this, SLOT(FoundTest(QString)));
	connect(mpTester, SIGNAL(Tested(int, bool)), this, SLOT(Tested(int, bool)));

	connect(mpTester, SIGNAL(StartedScanning()), this, SLOT(StartedScanning()));
	connect(mpTester, SIGNAL(FinishedScanning()), this, SLOT(FinishedScanning()));
	connect(mpTester, SIGNAL(StartedTesting()), this, SLOT(StartedTesting()));
	connect(mpTester, SIGNAL(FinishedTesting()), this, SLOT(FinishedTesting()));

	connect(this, SIGNAL(SendCommand(int,int,int)), mpTester, SLOT(GetCommand(int,int,int)));

	emit SendCommand(READ_FILE);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::FoundTest(QString Name)
{
    std::string ItemName = Name.toStdString();

#if defined(_WIN16)||defined(_WIN32)||defined(_WIN64)
	LU::ReplacePattern(ItemName, "..\\..\\", "");
#else
	LU::ReplacePattern(ItemName, "../../", "");
#endif

	ui->lstTests->addItem(QString(QString::number(ui->lstTests->count() + 1) + ": " + ItemName.c_str()));
	mTestSuccesses.push_back(-1);

	mpValidator->setTop(ui->lstTests->count());
	ui->cbRange->setEnabled(true);

}
void MainWindow::Tested(int TestID, bool Success)
{
	mTestSuccesses[TestID] = Success;

	QColor bgColor[] = { Qt::red, Qt::green };
	QColor fgColor[] = { Qt::white, Qt::black};

	ui->lstTests->item(TestID)->setBackgroundColor(bgColor[Success]);
	ui->lstTests->item(TestID)->setTextColor(fgColor[Success]);


	mFailedTest = -1;
	mAllSuccess = true;
	for(int i = 0; i < mTestSuccesses.size(); i++)
	{
		if(mTestSuccesses[i] == 0)
		{
			if(mFailedTest < 0)
			{
				mFailedTest = i;
				mAllSuccess = false;
			}
		}
		else if(mTestSuccesses[i] == -1)
		{
			mAllSuccess = false;
		}
	}

	if(mAllSuccess == true)
	{
		ui->btnStatus->setStyleSheet("background-color: #58FA58"); // Green
		ui->btnStatus->setDisabled(true);
	}
	else if(mFailedTest < 0)
	{
		ui->btnStatus->setStyleSheet(""); // Default
		ui->btnStatus->setDisabled(true);
	}
	else
	{
		ui->btnStatus->setStyleSheet("background-color: #FE2E2E"); // Red
		ui->btnStatus->setDisabled(false);
	}
}


void MainWindow::StartedScanning()
{
	ui->lstTests->clear();
	mTestSuccesses.clear();

	ui->btnScan->setText("Stop");
	ui->btnTest->setDisabled(true);

	ui->lblInfo->setText("Scanning ...");
	mIsScanning = true;
}
void MainWindow::FinishedScanning()
{
	ui->btnScan->setText("Scan");

	if(ui->lstTests->count() != 0)
		ui->btnTest->setDisabled(false);

	ui->lblInfo->setText("Finished Scanning!");
	mIsScanning = false;
}

void MainWindow::StartedTesting()
{
	ui->btnScan->setDisabled(true);
	ui->btnTest->setText("Stop");

	ui->lblInfo->setText("Testing ...");
	mIsTesting = true;
}
void MainWindow::FinishedTesting()
{
	ui->btnScan->setDisabled(false);
	ui->btnTest->setText("Start");

	ui->lblInfo->setText("Finished Testing!");
	mIsTesting = false;
}

void MainWindow::on_lstTests_itemDoubleClicked(QListWidgetItem *item)
{
	emit SendCommand(TEST_ALL, ui->lstTests->currentRow() + 1, ui->lstTests->currentRow() + 1);
}

void MainWindow::on_btnStatus_clicked()
{
	ui->lstTests->setCurrentRow(mFailedTest);
}
void MainWindow::on_btnScan_clicked()
{
	if(mIsScanning == false)
	{
		emit SendCommand(START_SCANNING);
	}
	else
	{
		emit SendCommand(STOP);
	}
}
void MainWindow::on_btnTest_clicked()
{
	if(mIsTesting == false)
	{
		int COMMANDS = (ui->cbAutoTest->isChecked() * TEST_FOREVER |
						ui->cbUntested->isChecked() * TEST_UNTESTED_TESTS |
						ui->cbFailures->isChecked() * TEST_FAILED_TESTS |
						ui->cbSuccess->isChecked() * TEST_SUCCESSFUL_TESTS |
						TESTING);

		if(ui->cbRange->isChecked())
		{
			int begin = ui->leBegin->text().toInt();
			int end = ui->leEnd->text().toInt();

			if(begin < 1 || end < 1)
				QMessageBox::information(this, tr("Error"), "Please Enter a valid Range.\n\nStart and End have to be greater than 0\n");
			else
				emit SendCommand(COMMANDS, begin, end);
		}
		else
			emit SendCommand(COMMANDS);
	}
	else
	{
		emit SendCommand(STOP);
	}
}

void MainWindow::on_cbRange_clicked(bool checked)
{
	if(checked)
	{
		SetRangedWidgetVisibility(true);
	}
	else
	{
		SetRangedWidgetVisibility(false);
	}
}
void MainWindow::SetRangedWidgetVisibility(bool visible)
{
	ui->lblEnd->setVisible(visible);
	ui->lblStart->setVisible(visible);
	ui->leBegin->setVisible(visible);
	ui->leEnd->setVisible(visible);
}
