#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


void printMatrix(int a[SIZE][SIZE]) {
	// Вывод матрицы связей
  	for (int i = 0; i<SIZE; i++) {
		for (int j = 0; j<SIZE; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
}


int main() {

  	int minDistances[SIZE]; // минимальное расстояние
  	int visited[SIZE];      // посещенные вершины
  	int temp, minindex, min;
  	int begin_index = 0;

  int a[SIZE][SIZE] = 
  {
	{0,2,10000,2,10000},
	{2,0,4,10000,10000},
	{10000,4,0,2,1},
	{2,10000,2,0,7},
	{10000,10000,1,7,0},
  };

  printMatrix(a);

  //Инициализация вершин и расстояний
  for (int i = 0; i<SIZE; i++)
  {
	minDistances[i] = 10000;
	visited[i] = 1;
  }
  minDistances[begin_index] = 0;
  // Шаг алгоритма
  do {
	minindex = 10000;
	min = 10000;
	for (int i = 0; i<SIZE; i++)
	{ // Если вершину ещё не обошли и вес меньше min
	  if ((visited[i] == 1) && (minDistances[i]<min))
	  { // Переприсваиваем значения
		min = minDistances[i];
		minindex = i;
	  }
	}
	// Добавляем найденный минимальный вес
	// к текущему весу вершины
	// и сравниваем с текущим минимальным весом вершины
	if (minindex != 10000)
	{
	  for (int i = 0; i<SIZE; i++)
	  {
		if (a[minindex][i] > 0)
		{
		  temp = min + a[minindex][i];
		  if (temp < minDistances[i])
		  {
			minDistances[i] = temp;
		  }
		}
	  }
	  visited[minindex] = 0;
	}
  } while (minindex < 10000);

  // Вывод кратчайших расстояний до вершин
  printf("\nКратчайшие расстояния до вершин: \n");
  for (int i = 0; i<SIZE; i++)
	printf("%5d ", minDistances[i]);
  return 0;
}