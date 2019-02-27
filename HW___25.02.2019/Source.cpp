#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

int determine_index(char*str, char c) {
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == c)
			return i;

	return -1;
}
double osad(char*str, double *a, char type) {
	int index = determine_index(str, type);
	a[index] = rand() % 10 + 1.0 / (rand() % 10);
	return a[index];
}
int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		// 1.	Написать программу, которая переводит введенное десятичное число в восьмеричное число.
        // Результат перевода сохранить в массив минимально возможного размера.
		{
			int n;
			cin >> n;
			int *p;
			int count = 0;

			int tmp = n;
			while (tmp)
			{
				tmp /= 8;
				count++;
			}
			
			p = new int[count];
			tmp = n;
			int j = count;
			while (tmp)
			{
				p[--j] = tmp % 8;
				tmp /= 8;
			}
			for (int i = 0; i < count; i++)
				cout << p[i];
			cout << endl;

			delete[] p;
		}
		break;
		case 2:
		// 2.	**Написать программу «Прогноз погоды».Создать два массива : массив символов и массив вещественных чисел.
		// Массив символов описывает тип осадков, массив вещественных чисел – объем осадков.
		// При каждом запуске программы генерируется разное количество осадков.
		// Рекомендации:
		// Тип осадков можно выбирать из перечня(для этого создать статический массив с перечнем осадков, а генерировать позицию из массива).
		// Следите, чтобы один и тот же осадок не повторился более одного раза. Количество осадков генерируется случайным образом.
		{
			char osadki[4] = { 'д', 'г', 'с', 'т' };
			double vol[4];

			char tmp[9] = { -1 };
			int k[4] = { 0 };
			int choice, count = 4;
			char type;

			for (int i = 0; i < 4; i++)
				tmp[i] = osadki[i];

			while (true)
			{
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to continue" << endl;
				cin >> choice;

				if (choice == 0) break;
				else
				{
					cout << "Выберите символ, чтобы увидеть объем осадков по типу:" << endl;
					cout << "д - дождь" << endl;
					cout << "г - град" << endl;
					cout << "с - снег" << endl;
					cout << "т - туман" << endl;

					cin >> type;

						tmp[count++] = type;
						for (int j = 0; j < 9; j++)
						{
							if (tmp[j] == type)
								k[determine_index(osadki, type)]++;

							if (k[determine_index(osadki, type)] > 2)
							{
								cout << "Повторный запрос объема данного типа осадков" << endl;
								break;
							}
						}
					cout << osad(osadki, vol, type) << endl;
				}
			}
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}