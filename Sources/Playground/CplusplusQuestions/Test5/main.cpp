#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int main()

{
int month, day, year;
int u,v,m,y,w,dayofweek;
bool leap;
string monthname;
string dayname;

cout<< "Enter numeric values for month, day and year of a date>" <<endl;
cin>>month>>day>>year;

if (month == 01)
monthname = "January ";
else if (month == 02)
monthname = "February ";
else if (month==03)
monthname = "March ";
else if (month==04)
monthname = "April ";
else if (month==05)
monthname = "May ";
else if (month==06)
monthname = "June ";
else if (month==07)
monthname = "July ";
else if (month==8)
monthname = "August ";
else if (month==9)
monthname = "September ";
else if (month==10)
monthname = "October ";
else if (month==11)
monthname = "November ";
else if (month==12)
monthname = "December ";




if (year % 400 == 0)
{
leap = true;
}
else if (year % 100 == 0)
{
leap = false;
}

else if (year % 4 == 0)
{
leap = true;
}



if (month == 01)
{
if (leap) m = 6;
else m = 0;
}
if (month == 02)
{
if (leap) m = 2;
else m = 3;
}
if (month == 03)
{
m = 3;
}
if (month == 04)
{
m = 6;
}
if (month == 05)
{
m = 1;
}
if (month == 06)
{
m = 4;
}
if (month == 07)
{
m = 6;
}
if (month == 8)
{
m = 2;
}
if (month == 9)
{
m = 5;
}
if (month == 10)
{
m = 0;
}
if (month == 11)
{
m = 3;
}
if (month == 12)
{
m = 5;
}
u = (2*(3-(year/100%4)));
v = year-(year/100)*100;
w = (v/4);
y = u+v+w+m+day;
dayofweek=y%7;


if (dayofweek == 0)
dayname = "Sunday, ";
else if (dayofweek == 1)
dayname = "Monday, ";
else if (dayofweek == 2)
dayname = "Tuesday, ";
else if (dayofweek == 3)
dayname = "Wednesday, ";
else if (dayofweek == 4)
dayname = "Thursday, ";
else if (dayofweek == 5)
dayname = "Friday, ";
else if (dayofweek == 6)
dayname = "Saturday, ";

cout<< dayname << monthname << day << "," << year << "occured in a";
if (leap)
cout<< "leap year.";

}
