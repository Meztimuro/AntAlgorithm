#pragma once
#include "Ant.h"

class Graph
{
	int vert = 7; // ���������� ������
	int Distance[7][7]; // ������� ����������
	double Pheromone[7][7]; // ������� ���������

public:
	friend class Ant;
	Graph(); // �����������
	~Graph(); // ����������
	void input(); // ���� ������
	void Update_Ph(); // ���������� ��������
};

