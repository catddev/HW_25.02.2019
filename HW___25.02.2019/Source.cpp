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
		cout << "������ � ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{

		}
		break;
		case 2:
		{

		}
		break;
		default:
			cout << "��� ����� ������" << endl << endl;
		}
	}
	system("pause");
	return 0;
}