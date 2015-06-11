#pragma once
#include "Ant.h"

class Graph
{
	int vert = 7; // количество вершин
	int Distance[7][7]; // матрица расстояний
	double Pheromone[7][7]; // матрица феромонов

public:
	friend class Ant;
	Graph(); // конструктор
	~Graph(); // деструктор
	void input(); // ввод матриц
	void Update_Ph(); // обновление феромона
};

