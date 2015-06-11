#pragma once
#include "Graph.h"

class Ant
{
	int List[7]; //������ ������ ������� ����� ��������
	int price = 0; //���� ���������� ����
	

public:
	int Path[7]; // ��������� �������
	int Location; // ��������� �������

	friend class Graph;
	Ant();
	~Ant();
	void Update_List(); // ������������ ���������� �������
	void Update_Path(); // ���������� ���������� ����
	double Heu(int x, Graph G); // ������������� �������
	double Move_Sum(Graph G); // ����������� � ������� ����������� ��������
	double Move(Graph G); // ������� ������� ����������� ��������
};

