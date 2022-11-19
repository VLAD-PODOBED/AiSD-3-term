#pragma once
#include <iostream>
using namespace std;

class Graph
{
public:
	Graph input(Graph G);
	void output(Graph G);

	int number_of_point;
	int** point;

	void create_graph()
	{
		point = new int* [number_of_point];
		for (int i = 0; i < number_of_point; i++)
		{
			point[i] = new int[number_of_point];
			for (int j = 0; j < number_of_point; j++)
			{
				point[i][j] = -1;
				if (j + 1 == number_of_point) point[i][j] = 0;
			}
		}
	}

	Graph(int number_of_point)
	{
		this->number_of_point = number_of_point;
		create_graph();
	}


};

Graph Graph::input(Graph G)
{
	cout << endl << "укажите пары соединеных вершин(в конце укажите 0 0 для вывода графа)" << endl;
	while (true)
	{
		int first, second;
		bool first_flag, second_flag;
		cin >> first >> second;
		if (first == 0 || second == 0) break;

		try
		{
			if (first == second) throw exception("Такой пары не может быть");
			if (first > G.number_of_point || second > G.number_of_point) throw exception("Такой пары не может быть");
			first_flag = false, second_flag = false;
			first--; second--;
			for (int i = 0; i < G.number_of_point; i++)
			{
				if (G.point[first][i] == -1) first_flag = true;
				if (G.point[second][i] == -1) second_flag = true;
				if (G.point[first][i] == second + 1) throw exception("Такой пары не может быть");
				if (G.point[second][i] == first + 1) throw exception("Такой пары не может быть");
				if (first_flag && second_flag) break;
			}
			if (first_flag && second_flag)
			{
				for (int i = 0; i < G.number_of_point; i++)
				{
					if (G.point[first][i] == -1)
					{
						G.point[first][i] = second + 1;
						break;
					}
				}
				for (int i = 0; i < G.number_of_point; i++)
				{

					if (G.point[second][i] == -1)
					{
						G.point[second][i] = first + 1;
						break;
					}
				}
			}
			else { throw exception("Такой пары не может быть"); }

		}
		catch (const std::exception e)
		{
			cout << e.what() << endl;
		}
		cin.clear();
		cin.ignore('123', '\n');


	}
	return G;

}

void Graph::output(Graph G)
{
	cout << endl << "Вывод графа:" << endl;
	for (int i = 0; i < G.number_of_point; i++)
	{
		cout << i + 1 << "={";
		for (int j = 0; G.point[i][j] != 0; j++)
		{
			if (G.point[i][j] == -1) break;
			cout << " " << G.point[i][j] << " ";
		}
		cout << "}" << endl;
	}
}
