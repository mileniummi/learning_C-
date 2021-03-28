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
		cout << "Ошибка открытия файла\n";
	}
	else {
		cout << "Файл успешно открыт\n";
	}
}

void file::Close()
{
	if (!fin.is_open()) {
		cout << "Файл не открыт чтобы его закрыть\n ";
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
		return "Конец файла, считывание невозможно";
	}
	getline(fin, temp);
	return temp;
}

string file::get_next_world()
{
	string temp;
	if (fin.eof()) {
		return "Конец файла, считывание невозможно";
	}
	fin >> temp;
	return temp;
}

void file_Menu::Get_menu()
{
	file Myfile;
	int act;
	while (true) {
		cout << "__________МЕНЮ___________      \n";
		cout << "1.Открытие файла.\n";
		cout << "2.Закрытие файла.\n";
		cout << "3.Получение имени файла.\n";
		cout << "4.Открыт ли файл.\n";
		cout << "5.Проверка не закончился ли файл.\n";
		cout << "6.Получение из файла следующей строки.\n";
		cout << "7.Получение из файла следующего слова.\n";
		cout << "0.Завершение работы.\n";
		cin >> act;
		switch (act)
		{
		case 1: {
			string name;
			cout << "Введите название файла\n";
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
				cout << "Файл еше не открыт";
			}
			else {
				cout << "Название файла\n" << Myfile.Get_file_name() << "\n";
			}
			break;
		}
		case 4: {
			cout << Myfile.IF_open() << "\n";
			break;
		}
		case 5: {
			if (Myfile.IF_open() == "NO") {
				cout << "Файл еше не открыт\n";
			}
			else {
				cout << Myfile.IF_end() << "\n";
			}
			break;
		}
		case 6: {
			if (Myfile.IF_open() == "NO") {
				cout << "Файл еше не открыт\n";
			}
			else {
				cout << Myfile.Get_next_line() << "\n";
			}
			break;
		}
		case 7: {
			if (Myfile.IF_open() == "NO") {
				cout << "Файл еше не открыт\n";
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
			cout << "Введенное вами не соответсвует пунктам из меню\n";
			break;
		}
		}
	}
finish:;
}
