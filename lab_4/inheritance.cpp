#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	vector<IFigure*> objects;
	int act;
	int i = 0;
	while (true) {
		cout << "-----=====����=====----\n";
		cout << "1.���������� ������.\n";
		cout << "2.���������� ��� ������.\n";
		cout << "3.��������� ������� ���� �����.\n";
		cout << "4.��������� �������� ���� �����.\n";
		cout << "5.����� ���� ���� �������.\n";
		cout << "6.������ ���������� ����� ������������ �������.\n";
		cout << "7.���������� ����� ����� ����� �� �����.\n";
		cout << "0.���������� ������.\n";
		cin >> act;
		switch (act)
		{
		case 1: {
		cout << "�������� ������" << "\n" "1:����" << "\n" <<  "2:��������"  << "\n";
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
				cout << "�������� �����" << "\n";
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
			cout << "����� ����� ��������: " << square << "\n";
			break;
		}
		case 4: {
			double  perimetr = 0;
			for (int i = 0; i < objects.size(); i++) {
				perimetr += objects[i]->perimeter();
			}
			cout << "����� ����� ����������: " << perimetr << "\n";
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
			cout << "������ ���������� ������������ ������� " << used_memory << " \n";
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
			cout << "��������� ���� �� ������������ ������� �� ����\n";
			break;
		}
		}

	}
finish:;
}