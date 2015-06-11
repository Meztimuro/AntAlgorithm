#pragma once
#include "Graph.h"

class Ant
{
	int List[7]; //список вершин которые нужно посетить
	int price = 0; //цена пройденого пути
	

public:
	int Path[7]; // Проиденый маршрут
	int Location; // положение муравья

	friend class Graph;
	Ant();
	~Ant();
	void Update_List(); // Вычёркивание посещённой вершины
	void Update_Path(); // Обновление пройденого пути
	double Heu(int x, Graph G); // Эвристическое желание
	double Move_Sum(Graph G); // Знаменатель в формуле вероятности перехода
	double Move(Graph G); // Формула расчёта вероятности перехода
};

