#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateArray(int** Q, const int rowCount, const int colCount, const int Low, const int High);
void PrintArray(int** Q, const int rowCount, const int colCount);
void Sort(int** Q, const int rowCount, const int colCount);
void Change(int** Q, const int row1, const int row2, const int colCount);
void Calc(int** Q, const int rowCount, const int colCount, int& k);
int Sum(int** Q, const int rowCount, const int colCount, int& S);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;//найменше значення
	int High = 23;//найбільше значення
	int rowCount = 8;//висота
	int colCount = 6;//ширина
	int** Q = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		Q[i] = new int[colCount];
	CreateArray(Q, rowCount, colCount, Low, High);
	PrintArray(Q, rowCount, colCount);
	Sort(Q, rowCount, colCount);
	PrintArray(Q, rowCount, colCount);
	int S = Sum(Q, rowCount, colCount, S);
	int k = 0;
	Calc(Q, rowCount, colCount, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	PrintArray(Q, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] Q[i];
	delete[] Q;
	return 0;
}

void CreateArray(int** Q, const int rowCount, const int colCount, const int Low, const int High) //done
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			Q[i][j] = Low + rand() % (High - Low + 1);
}

void PrintArray(int** Q, const int rowCount, const int colCount) //done
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << Q[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** Q, const int rowCount, const int colCount) //done
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((Q[0][i1] > Q[0][i1 + 1]))
				Change(Q, i1, i1 + 1, rowCount);
			else if
				(Q[0][i1] == Q[0][i1 + 1] &&
					Q[1][i1] < Q[1][i1 + 1])
				Change(Q, i1+1, i1, rowCount);
			else if
				(Q[0][i1] == Q[0][i1 + 1] &&
					Q[1][i1] == Q[1][i1 + 1] &&
					Q[2][i1] > Q[2][i1 + 1])
				Change(Q, i1, i1 + 1, rowCount);
}

void Change(int** Q, const int col1, const int col2, const int rowcount) //done
{
	int tmp;
	for (int j = 0; j < rowcount; j++)
	{
		tmp = Q[j][col1];
		Q[j][col1] = Q[j][col2];
		Q[j][col2] = tmp;
	}
}

void Calc(int** Q, const int rowCount, const int colCount, int& k) //done
{
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (Q[i][j] % 2 == 0 && Q[i][j] > 0)
			{
				k++;
				Q[i][j] = 0;
			}
}

int Sum(int** Q, const int rowCount, const int colCount, int& S) //done
{
	S = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (Q[i][j] % 2 == 0 && Q[i][j] > 0)
			{
				S += Q[i][j];
			}
	return S;
}