#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;


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

			int choice, index, i = 0, newRand=0;
			int *tmp = new int[4];
			for (int k = 0; k < 4; k++)
				tmp[k] = -1;

			while (i < 4)
			{
				if (newRand == 0)
				{
					cout << "Enter 0 to exit" << endl;
					cout << "Enter 1 to continue" << endl;
					cin >> choice;
				}

				if (choice == 0) break;
				else
				{
						index = rand() % 4;
						newRand = 0;
						for (int j = 0; j < 4; j++)
						{
							if (tmp[j] == index)
							{
								newRand++;
								break;
							}
						}
					
						if (newRand > 0) continue;
						else
							tmp[i] = index;
					
						i++;
				
						cout << "д - дождь" << endl;
						cout << "г - град" << endl;
						cout << "с - снег" << endl;
						cout << "т - туман" << endl;

						vol[index] = rand() % 10 + 1.0 / (rand() % 10);

						cout << osadki[index] << ": " << vol[index] << endl;
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