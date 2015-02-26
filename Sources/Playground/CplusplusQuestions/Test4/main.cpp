#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Country
{
private:
	string name;
	long population;
	double area;

public:
	Country ();
	void setName (string);
	void setPopulation (long);
	void setArea (double);
	string getName ();
	int getPopulation ();
	double getArea ();
};

void calcCountry (Country [], int);

Country::Country ()
{
	population=0;
	area=0;
	name="NULL";
}

//=============================================
void Country::setName (string cname)
{
	name=cname;
}
//============================================
void Country::setPopulation(long pop)
{
	if (pop >= 0)
		population=pop;
	else
	{ population=0;
		cout << "Invalid population. Using a default value of 0";
	}
}
//==============================================
void Country::setArea(double a)
{
	if (a >= 0.0)
		area=a;
	else
	{ area=0;
		cout << "Invalid area. Using a default value of 0";
	}
}
//==============================================
string Country::getName ()
{
	return name;
}
//================================================
int Country::getPopulation()
{
	return population;
}
//==================================================
double Country::getArea()
{
	return area;
}
//=====================================================

void calcCountry (Country country[], int k)
{
	int maxpos1 = 0;

	for (int i=0; i<k; i++){
		if (country[i].getArea() > country[maxpos1].getArea()){
			maxpos1=i;
		}
	}
	cout << "The country " << country[maxpos1].getName() << " has the biggest area of " <<country[maxpos1].getArea() << endl;;

	int maxpos2=0;

	for (int i=0; i<k; i++){
		if (country[i].getPopulation() > country[maxpos2].getPopulation()){
			maxpos2=i;
		}
	}
	cout << "The country " << country[maxpos2].getName() << " has the biggest population of " <<country[maxpos2].getPopulation() << endl;;


	int maxpos3=0;

	for (int i=0; i<k; i++){
		if ((country[i].getPopulation()/country[i].getArea()) > country[maxpos3].getPopulation()/country[maxpos3].getArea()){
			maxpos3=i;
		}
	}
	cout << "The country " << country[maxpos3].getName() << " has the biggest density of " << (country[maxpos3].getPopulation()/country[maxpos3].getArea()) << endl;
}

//==============================================================================================================================================================
const int n=6;

int main()
{
	ifstream infile;
	infile.open("myCountrydata.txt");

	string cname;
	long pop;
	double a;

	Country country [n];

	if (!infile) {
		cout << "File could not open for reading." << endl;
		exit(1);
	}

	int i=0;

	while (i < n && !infile.eof())
	{
		infile >> cname >> pop >> a;
		country[i].setName(cname);
		country[i].setPopulation(pop);
		country[i].setArea(a);
		i++;
	}

	calcCountry(country, n);

	infile.close();
	return 0;
}
