#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include "../counterr.h"
#include <string>

TEST_CASE("Test na pocet znakov", "Znaky") {

	string str;

	str = "ahoj";
	REQUIRE(PocitanieZnakov(str) == 4);

	str = "pondelok";
	REQUIRE(PocitanieZnakov(str) == 8);

}

TEST_CASE("Test na pocet slov", "Slova") {
	string str;

	str = "pondelok streda stvrtok";
	REQUIRE(PocitanieSlov(str) == 3);

	str = "ako sa";
	REQUIRE(PocitanieSlov(str) == 2);
}

TEST_CASE("Test na pocet riadkov", "Riadky") {
	string str="";
	int pom = 1;

	cout << "Zadajte dva riadky, nacitavanie skoncite retazcom 'end' (retazec end sa do poctu riadkov nerata)" << endl;
	REQUIRE(PocitanieRiadkov(pom, str) == 2);
}
