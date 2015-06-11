#include "stdafx.h"
#include "Graph.h"
#include <iostream>


Graph::Graph()
{
	for (int i = 0; i <  7; i++)
	{
		for (int j = 0; j <  7; j++)
		{
			Distance[i][j] = 999;
			Pheromone[i][j] = 0.5;
		}
	}
}


Graph::~Graph()
{
	//std::cout << "destr";
}

void Graph::input()
{
	
	for (int i = 0; i <  7; i++)
	{
		for (int j = i + 1; j <  7; j++)
		{
			std::cout << "insert distance " << i  << " " << j  << " = ";
			std::cin >> Distance[i][j];
			if (Distance[i][j] == 0) 
			{ 
				Distance[i][j] = 999;
				Pheromone[i][j] = 0;
			}
			Distance[j][i] = Distance[i][j];
			Pheromone[j][i] = Pheromone[i][j];
		}
		std::cout << "--------------------\n";
	}
	std::cout << "Distance Array\n";
	for (int i = 0; i <  7; i++)
	{
		for (int j = 0; j <  7; j++)
		{
			std::cout << Distance[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl ;
	std::cout << "Pheromone Array\n";
	for (int i = 0; i <  7; i++)
	{
		for (int j = 0; j <  7; j++)
		{
			std::cout << Pheromone[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}

void Graph::Update_Ph()
{
	/**/
}