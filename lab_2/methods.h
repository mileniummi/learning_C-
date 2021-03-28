#pragma once
#include <string>
#include <fstream>
#include<iostream>
using namespace std;
class file {
private:
	string File_name;
	ifstream fin;
public:
	file() {
	}
	file(string name);
	void Open(string name);
	void Close();
	string Get_file_name();
	string IF_open();
	string IF_end();
	string Get_next_line();
	string get_next_world();
};
class file_Menu {
public:
	void Get_menu();
};