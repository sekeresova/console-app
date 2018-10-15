// app.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iterator>
#include<sstream>
#include"counterr.h"
#include <algorithm>


using namespace std;

int main(int argc, char *argv[])
{
	int prepinac;
	string str;
	
	if (argc == 1)
		cout << "Nebol zadany ziadny retazec!" << endl;
	else if (argc == 2)
	{
		string nazov, *file = new string[20];
		cout << "Zadajte nazov suboru (pre nacitanie retazca z konzoly stlacte enter)\n";
		getline(cin, nazov);
		fstream subor((nazov + ".txt").c_str(), fstream::in);

		if ("-c" == (string)argv[argc - 1])
		{
			cout << "-----------POCITANIE ZNAKOV-----------" << endl;

			if (subor.is_open()) {
				getline(subor, str);
				cout << "Pocet znakov v subore je:" << spocitaj<_char>(str) << endl;
			}
			else {
				cout << "Zadajte retazec" << endl;
				getline(cin, str);
				cout << "Pocet znakov je:" << spocitaj<_char>(str) << endl;
			}
		}
		
		if ("-w" == (string)argv[argc - 1])
		{
			cout << "-----------POCITANIE SLOV-----------" << endl;

			if (subor.is_open()) {
				getline(subor, str);
				cout << "Pocet slov v subore je:" << spocitaj<_word>(str) << endl;
			}
			else {

				cout << "Zadajte retazec" << endl;
				getline(cin, str);
				cout << "Pocet slov je:" << spocitaj<_word>(str) << endl;
			}
		}

		if ("-l" == (string)argv[argc - 1])
		{
			cout << "-----------POCITANIE RIADKOV-----------" << endl;

			if (subor.is_open()) {
				prepinac = 0;
				cout << "Pocet riadkov je:" << spocitaj<_line>(str) << endl;
			}
			else {
				cout << "Zadajte retazec" << endl;
				prepinac = 1;
				cout << "Pocet riadkov je:" << spocitaj<_line>(str) << endl;
			}
		}	
		subor.close();
		delete[] file;
	}

	return 0;
}
