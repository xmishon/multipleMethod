#include <stdio.h>;
using namespace std;

public class Multiple
{
private: int* a;
		 int* b;

public: void Mul(int* a, int* b, int* res, int sizeA, int sizeB)
		{
			this->a = new int[sizeA];
			this->b = new int[sizeB];

			int **res1 = new int*[sizeB];
			for (int i = 0; i < sizeB; i++)
			{
				res1[i] = new int[sizeA + sizeB];
			}
			for (int i = 0; i < sizeB; i++)
				for (int j = 0; j < sizeA + sizeB; j++)
					res1[i][j] = 0;
			int aux = 0;
			//Part one
			for (int j = 0; j < sizeB; j++)
			{
				for (int i = 0; i < sizeA; i++)
				{
					res1[j][i + j] = a[i] * b[j];
					res1[j][i + j] += aux;
					aux = res1[j][i + j] / 10;
					res1[j][i + j] %= 10;
					if (i == sizeA - 1)
					{
						res1[j][i + j + 1] = aux;
						aux = 0;
					}
				}
			}
			//Part two
			aux = 0;
			for (int j = 0; j < (sizeA + sizeB); j++) 
			{
				for (int i = 0; i < sizeB; i++)
					res[j] += res1[i][j];
				res[j] += aux;
				aux = res[j] / 10;
				res[j] %= 10;
				if (j == sizeA + sizeB - 1)
				{
					res[j + 1] = aux;
					aux = 0;
				}
			}
		}
};