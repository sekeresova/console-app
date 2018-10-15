#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<sstream>
#include<stdlib.h>

using namespace std;

template <typename T>
size_t spocitaj(string str) {
	T obj(str);
	return obj.spocitaj();
}

struct _char :public string {

	_char(string str) :string(str) {};
	size_t spocitaj() {
		return size();
	}
};

struct _word :public string {

	_word(string str) :string(str) {};
	size_t spocitaj() {
		int pocet = 0;

		for (int i = 0; i < length(); i++) {
			if (at(i) == ' ')
				pocet++;
		}
		return pocet + 1;
	}
};

struct _line :public string {
	
	_line(string str) :string(str) {};
	size_t spocitaj() {
		int riadky = 0;
		string str;

		while (getline(cin, str)) {
			if (str != "end")
				riadky++;
			else return riadky;
		}
	}
};



int PocitanieZnakov(string s) {

	return s.length();
}

int PocitanieSlov(string s) {
	int pocet = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ')
			pocet++;
	}
	return pocet + 1;
}

int PocitanieRiadkov(int pom, string nazov) {
	int riadky = 0;
	string str;
	
	if (pom == 0) {

		ifstream in((nazov + ".txt"));
		while (in.good()) {
			getline(in, str);
			++riadky;
		}
		return riadky;
	}
	else if (pom == 1) {

		while (getline(cin, str)) {
			if (str != "end")
				riadky++;
			else return riadky;
		}
	}	
}

int PocitanieRiadkovConsole() {
	int riadky = 0;
	string str;

	while (getline(cin, str)) {
		if (str != "end")
				riadky++;
		else return riadky;
		}
	}