#include "stdafx.h"
#include "Ant.h"
#include <iostream>
#include <math.h>


extern double alpha;
extern double beta;
//extern int vert;

Ant::Ant()
{
	Location = 0;
	for (int i = 0; i < 7; i++)
	{
		List[i] = i;
		Path[i] = -1;
	}
	List[0] = -1;
}


Ant::~Ant()
{
}

void Ant::Update_List()
{
	int flag = 0; // флаг // посещены ли все вершины

	for (int k = 0; k < 7; k++)
	{
		if (k = Location)
		{
			List[k] = -1; // вершина посещена
			break;

		}

	}
}

void Ant::Update_Path()
{
	for (int k = 0; k < 7; k++)
	{
		if (Path[k] == -1)
		{
			Path[k] = Location;
			break;
		}
	}
}

double Ant::Heu(int x, Graph G) // Эвристическое желание
{
	return pow( (1.0) / (G.Distance [Location][x]) , beta) ;
}

double Ant::Move_Sum(Graph G) // Знаменатель в формуле вероятности перехода
{
	double Sum = 0; // Сумма

	for (int j = 0; j < 7; j++)
	{

		//Sum += ( pow( G.Pheromone[Location][j], alpha ) * pow( ( 1.0 / ( G.Distance[Location][j] ) ) , beta) ) ;
		Sum += (pow(G.Pheromone[Location][j], alpha) * Heu(j, G));
		
	}

	return Sum;
}

double Ant::Move(Graph G) // Формула расчёта вероятности перехода
{
	double P = 0; // вероятность перехода 
	double P_Max = 0; // наибольшая вероятность перехода 
	int P_Max_Location = -1; // вершина с наибольшей вероятностью перехода
	double S = Move_Sum(G); // Для сокращения расчётов

	for (int i = 0; i < 7; i++)
	{
		if ((List[i] == i) && (i != Location)) // если вершина еще не была посещена
		{
			P = (pow(G.Pheromone[Location][i], alpha) * Heu(i, G)) / S; // расчёт вероятности перехода

			if (P > P_Max) // если переход в данную вершину наиболее вероятен
			{
				P_Max = P;
				P_Max_Location = i;
			}
		}
	}

	if (P_Max_Location != -1) // Если P_Max_Location равен -1, то переход совершить невозможно
	{
		//price += G.Distance[Location][P_Max_Location];
		Location = P_Max_Location; // переместить муравья
		Update_List(); // Обновить список вершин которые еще не посещены
		Update_Path(); // Обновит пройденый путь
	}

	return P_Max;
}