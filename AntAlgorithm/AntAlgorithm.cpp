// AntAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "Ant.h"
#include <iostream>
#include <conio.h>

double alpha = 1; //���������, ��� 0 - �������� ������
double beta = 1; // ���������, ��� 0 - ����������� � ��������� ���������

int _tmain(int argc, _TCHAR* argv[])
{
	double Q = 1; // �������� ������� ���� ������������ �������
	int e = 100; // ���-�� ��������
	//Graph *AntsList[7]; // ������ ��������
	Graph *List[7];

	
	Graph One;
	One.Graph::input();
	Ant Two;
	for (int c = 0; c < 7; c++)
	{
		if (c>0 && Two.Location == 0)
		{
			break;
		}
		Two.Move(One);
	}
	std::cout << std::endl;
	for (int c = 0; c < 7; c++)
	{
		std::cout << Two.Path[c] << "-->";
	}




	_getch();
	return 0;
}


//std::cout <<  Two.Move(One);
//Two.Move(One);
//One.Graph::input();
//One.~Graph();
//One.Graph::input();


/*
AntsList = new Graph[7];
AntsList[0].input();
AntsList[1].input();
delete [0] AntsList;
AntsList[0].input();
AntsList[1].input();
*/

/*
������ ������ ����� ������� 
AntsList = new Graph[7];
AntsList[0].input();
delete [] AntsList;
AntsList[0].input();
*/

/* ������� ������ ������ ����������
List[0] = new Graph;
(*List[0]).Graph::input();
List[1] = new Graph;
(*List[1]).Graph::input();
delete List[0];
(*List[1]).Graph::input();
(*List[0]).Graph::input();
List[0] = new Graph;
(*List[0]).Graph::input();
*/