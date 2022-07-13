
#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::vector;
using std::pair;
using std::endl;
int n = 4;

// Функция прореживания. thin - проредить1
// lineNum - содержит координаты входных данных 

void thin(vector <pair <int,int>> &lineNum)
{
	//vector<pair <int, int>> v = lineNum;
	auto v = lineNum;
	int i = 0, cont = 1; // cont - номер в текущей последовательности, начинается с 1
	int f;

	f = lineNum.size();  // размерность вектора

	auto  initNum = lineNum.begin();
	auto NextNum = initNum;
	auto listend = v.end();
	auto iter = v.begin();
	auto cor = 0;

	while (i < (f + 1)) // условие выполняется пока i не становится больше чем элементов в массиве
	{
		NextNum++;
		if ((*initNum).second != (*NextNum).second) // Если элементы различаются, то последовательности нет или она закончилась
		{
			cont = 0;
		}
		else

		{

			cont++;   // последовательность соблюдена.

		}
		if ((cont > 1) && (listend != (iter + i)) && (cont % n != 0))
		{
			v.erase(iter + i - cor);
			cor++;  // так как мы работаем с вектором на прямую, при удалении элемента все позиции смещаются влево на 1

			f = v.size();

		}

		i++;
		initNum++;
		



	}
	
	cout << endl;
	for (auto coordRes : v)
	{
		cout << "(" << coordRes.first << "," << coordRes.second << "); ";
	}
 

}
// вывод

int main()
{
	vector < pair<int, int> > lineNum{ {1, 10}, {2, 11}, {3, 11}, {4, 11}, {5, 11}, {6, 10}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 10} };
	for (auto coord : lineNum)
	{
		cout << "(" << coord.first << "," << coord.second << "); ";
	}
	if (n < 2)
	{
		cout << "Erron n>2 ";
	} // Проверка n
	else
	{
		thin(lineNum);
	}
	return 0;
}

