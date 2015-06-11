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
	int flag = 0; // ���� // �������� �� ��� �������

	for (int k = 0; k < 7; k++)
	{
		if (k = Location)
		{
			List[k] = -1; // ������� ��������
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

double Ant::Heu(int x, Graph G) // ������������� �������
{
	return pow( (1.0) / (G.Distance [Location][x]) , beta) ;
}

double Ant::Move_Sum(Graph G) // ����������� � ������� ����������� ��������
{
	double Sum = 0; // �����

	for (int j = 0; j < 7; j++)
	{

		//Sum += ( pow( G.Pheromone[Location][j], alpha ) * pow( ( 1.0 / ( G.Distance[Location][j] ) ) , beta) ) ;
		Sum += (pow(G.Pheromone[Location][j], alpha) * Heu(j, G));
		
	}

	return Sum;
}

double Ant::Move(Graph G) // ������� ������� ����������� ��������
{
	double P = 0; // ����������� �������� 
	double P_Max = 0; // ���������� ����������� �������� 
	int P_Max_Location = -1; // ������� � ���������� ������������ ��������
	double S = Move_Sum(G); // ��� ���������� ��������

	for (int i = 0; i < 7; i++)
	{
		if ((List[i] == i) && (i != Location)) // ���� ������� ��� �� ���� ��������
		{
			P = (pow(G.Pheromone[Location][i], alpha) * Heu(i, G)) / S; // ������ ����������� ��������

			if (P > P_Max) // ���� ������� � ������ ������� �������� ��������
			{
				P_Max = P;
				P_Max_Location = i;
			}
		}
	}

	if (P_Max_Location != -1) // ���� P_Max_Location ����� -1, �� ������� ��������� ����������
	{
		//price += G.Distance[Location][P_Max_Location];
		Location = P_Max_Location; // ����������� �������
		Update_List(); // �������� ������ ������ ������� ��� �� ��������
		Update_Path(); // ������� ��������� ����
	}

	return P_Max;
}