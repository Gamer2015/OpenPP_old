#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include "../Testing/TesterThread.h"

#include "../Commands.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:
	/// Send a Command to the TesterThread
	void SendCommand(int Command, int begin=-1, int end=-1);


private slots:
	/// Add a Test to the QListWidget
	void FoundTest(QString Name);

	/// Set the Test TestID to "Success"
	void Tested(int TestID, bool Success);


	/// Disable/Enable allowed Buttons after testing has Started
	void StartedScanning();

	/// Disable/Enable allowed Buttons after Scanning has Started
	void FinishedScanning();


	/// Disable/Enable allowed Buttons after testing has Started
	void StartedTesting();

	/// Disable/Enable allowed Buttons after testing has Finished
	void FinishedTesting();


	/// Send Signal to test the Test that has been double clicked
	void on_lstTests_itemDoubleClicked(QListWidgetItem *item);

	/// Select the first Failed Test in lstTests
	void on_btnStatus_clicked();

	/// Sends Stop if the Thread is currently Testing
	/// Sends Start_Scanning otherwise
	void on_btnScan_clicked();

	/// Sends Stop if the Thread is currently Testing
	/// Sends Command according to checkboxes otherwise
	void on_btnTest_clicked();

	/// Sets the Start & End Listbox + Label invisible or visible
	void on_cbRange_clicked(bool checked);

private:
	Ui::MainWindow *ui;

	void SetRangedWidgetVisibility(bool visible);

	QIntValidator* mpValidator;

	TesterThread* mpTester;
	bool mIsScanning;
	bool mIsTesting;

	std::vector<short> mTestSuccesses;
	bool mAllSuccess;
	int mFailedTest;
};

#endif // MAINWINDOW_H
