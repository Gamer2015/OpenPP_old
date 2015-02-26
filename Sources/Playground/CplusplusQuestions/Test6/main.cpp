#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	char c, response;
	std::string line;
	string vowels("aeiouAEIOU");

	cout << "I can count the number of upper case, lower case, vowels and words" << endl;
	do
	{
		int Uc = 0, Dc=0, Vc=0, Wc=0;
		cout << "Enter a sentence: ";
		getline(std::cin, line);

		for(int i = 0; i < line.length(); ++i)
		{
			c = line[i];

			if(isupper(c))
				Uc++;
			if(isdigit(c))
				Dc++;
			if(vowels.find(c) != string::npos)
				Vc++;
			if (isspace(c))
				Wc++;
		}

		cout << setfill ('.');
		cout << "  Number of uppercase letters: " << Uc << endl;
		cout << "  Number of digits: " << Dc << endl;
		cout << "  Number of vowels: " << Vc << endl;
		cout << "  Number of words: " << Wc << endl;

		cout << "CONTINUE(y/n)? ";
		cin >> response;

	} while(response == 'Y' || response=='y') ;

	std::cout << std::endl;
	system("pause");
}
