#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	vector<IFigure*> objects;
	int act;
	int i = 0;
	while (true) {
		cout << "-----=====МЕНЮ=====----\n";
		cout << "1.Добавление фигуры.\n";
		cout << "2.Отобразить все фигуры.\n";
		cout << "3.Суммарная площадь всех фигур.\n";
		cout << "4.Суммарный периметр всех фигур.\n";
		cout << "5.Центр масс всей системы.\n";
		cout << "6.Память занимаемая всеми экземплярами классов.\n";
		cout << "7.Сортировка фигур между собой по массе.\n";
		cout << "0.Завершение работы.\n";
		cin >> act;
		switch (act)
		{
		case 1: {
		cout << "Выберите фигуру" << "\n" "1:круг" << "\n" <<  "2:трапеция"  << "\n";
			int oper;
			cin >> oper;
			switch (oper)
			{
			case 1: {
				objects.resize(i + 1);
				objects[i] = new Circle;
				objects[i]->initFromDialog();
				i++;
				break;
			}
			case 2: {
				objects.resize(i + 1);
				objects[i] = new Trapezium;
				objects[i]->initFromDialog();
				i++;
				break;
			}
			default:
				cout << "Неверное число" << "\n";
				break;
			}
			break;
		}
		case 2: {
			for (int i = 0; i < objects.size(); i++) {
				objects[i]->draw();
			}
			break;
		}
		case 3: {
			double square = 0;
			for (int i = 0; i < objects.size(); i++) {
				square += objects[i]->square();
			}
			cout << "Общая сумма площадей: " << square << "\n";
			break;
		}
		case 4: {
			double  perimetr = 0;
			for (int i = 0; i < objects.size(); i++) {
				perimetr += objects[i]->perimeter();
			}
			cout << "Общая сумма периметров: " << perimetr << "\n";
			break;
		}
		case 5: {
			CVector2D mass_center;
			mass_center.x = 0;
			mass_center.y = 0;
			for (int i = 0; i < objects.size(); i++) {
				CVector2D temp = objects[i]->position();
				mass_center.x += temp.x;
				mass_center.y += temp.y;
			}
			cout << mass_center.x << " " << mass_center.y << "" << " \n";
			break;
		}
		case 6: {
			int used_memory = 0;
			for (int i = 0; i < objects.size(); i++) {
				used_memory += objects[i]->size();
			}
			cout << "Память занимаемая экземплярами классов " << used_memory << " \n";
			break;
		}
		case 7: {
				sort(objects.begin(), objects.end(), cmp);
				for (int i = 0; i < objects.size(); i++) {
					objects[i]->draw();
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