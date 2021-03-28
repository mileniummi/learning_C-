#include "methods.h"

file::file(string name)
{
	File_name = name;
}

void file::Open(string name)
{
	File_name = name;
	fin.open(File_name);
	if (!fin.is_open()) {
		cout << "������ �������� �����\n";
	}
	else {
		cout << "���� ������� ������\n";
	}
}

void file::Close()
{
	if (!fin.is_open()) {
		cout << "���� �� ������ ����� ��� �������\n ";
	}
	fin.close();
}

string file::Get_file_name()
{
	return File_name;
}

string file::IF_open()
{
	if (fin.is_open()) {
		return "YES";
	}
	else {
		return "NO";
	}
}

string file::IF_end()
{
	if (fin.eof()) {
		return"YES";
	}
	else
	{
		return "NO";
	}
}

string file::Get_next_line()
{
	string temp;
	if (fin.eof()) {
		return "����� �����, ���������� ����������";
	}
	getline(fin, temp);
	return temp;
}

string file::get_next_world()
{
	string temp;
	if (fin.eof()) {
		return "����� �����, ���������� ����������";
	}
	fin >> temp;
	return temp;
}

void file_Menu::Get_menu()
{
	file Myfile;
	int act;
	while (true) {
		cout << "__________����___________      \n";
		cout << "1.�������� �����.\n";
		cout << "2.�������� �����.\n";
		cout << "3.��������� ����� �����.\n";
		cout << "4.������ �� ����.\n";
		cout << "5.�������� �� ���������� �� ����.\n";
		cout << "6.��������� �� ����� ��������� ������.\n";
		cout << "7.��������� �� ����� ���������� �����.\n";
		cout << "0.���������� ������.\n";
		cin >> act;
		switch (act)
		{
		case 1: {
			string name;
			cout << "������� �������� �����\n";
			cin >> name;
			Myfile.Open(name);
			break;
		}
		case 2: {
			Myfile.Close();
			break;
		}
		case 3: {
			if (Myfile.IF_open() == "NO") {
				cout << "���� ��� �� ������";
			}
			else {
				cout << "�������� �����\n" << Myfile.Get_file_name() << "\n";
			}
			break;
		}
		case 4: {
			cout << Myfile.IF_open() << "\n";
			break;
		}
		case 5: {
			if (Myfile.IF_open() == "NO") {
				cout << "���� ��� �� ������\n";
			}
			else {
				cout << Myfile.IF_end() << "\n";
			}
			break;
		}
		case 6: {
			if (Myfile.IF_open() == "NO") {
				cout << "���� ��� �� ������\n";
			}
			else {
				cout << Myfile.Get_next_line() << "\n";
			}
			break;
		}
		case 7: {
			if (Myfile.IF_open() == "NO") {
				cout << "���� ��� �� ������\n";
			}
			else
			{
				cout << Myfile.get_next_world() << "\n";
			}
			break;
		}
		case 0: {
			goto finish;
		}
		default: {
			cout << "��������� ���� �� ������������ ������� �� ����\n";
			break;
		}
		}
	}
finish:;
}
