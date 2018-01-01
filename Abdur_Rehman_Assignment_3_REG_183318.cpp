
#include<iostream>
using namespace std;
#define size 5
class Prim {

public:
	int minimum_Key(int key[], bool MST[]);
	int display(int parent[], int n, int array[size][size]);
	void prim(int array[size][size]);

};

int Prim::minimum_Key(int key[], bool MST[])
{

	int min = INT_MAX;
	int min_index;

	for (int k = 0; k < size; k++)
	{

		if (MST[k] == false && key[k] < min)
		{
			min = key[k], min_index = k;
		}

	}

	return min_index;
}


int Prim::display(int parent[], int n, int array[size][size])
{
	cout << "Edge   Weight\n";
	for (int i = 1; i < size; i++)
	{
		cout << parent[i] << " -" << i << " - " << array[i][parent[i]] << "\n";
	}
	return 1;
}

void Prim::prim(int array[size][size])
{
	int parent[size];
	int key[size];
	bool MST[size];

	for (int i = 0; i < size; i++)
	{
		key[i] = INT_MAX, MST[i] = false;
	}


	key[0] = 0;
	parent[0] = -1;


	for (int count = 0; count < size - 1; count++)
	{

		int temp = minimum_Key(key, MST);


		MST[temp] = true;


		for (int k = 0; k < size; k++)
		{


			if (array[temp][k] && MST[k] == false && array[temp][k] < key[k])
			{
				parent[k] = temp, key[k] = array[temp][k];
			}
		}
	}


	display(parent, size, array);
}

class Kruskal
{
public:

	int search(int);
	int function(int, int);

};
int var1, var2, var3, var4, var5, var6, n;
int key = 1;
int min, mincost = 0;
int cost[9][9], parent[9];


int  Kruskal::search(int i)
{
	while (parent[i])
		i = parent[i];
	return i;
}
int Kruskal::function(int i, int j)
{
	if (i != j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}


int main()
{
	int i, j, k;
	int sizee;
	int array[10][10];
	int count = 0;
	int array2[10];
	int array1[10];
	int choice;
	while (1)
	{
		cout << "\n-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "Implementation of Topological Sort, Prim’s and Kruskal's Algorithm in C++ " << endl;
		cout << "\n-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "1.topological" << endl;
		cout << "2. Kruskal's algorithm" << endl;
		cout << "3.Prim" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "\n";
			cout << "Implementation of topological algorithm\n\n";

			cout << "Enter the number of vertices:\n";
			cin >> sizee;

			cout << "Enter the adjacency matrix:\n";
			for (i = 0; i < sizee; i++)
			{
				cout << "Enter row " << i + 1 << "\n";
				for (j = 0; j < sizee; j++)
					cin >> array[i][j];
			}

			for (i = 0; i < sizee; i++)
			{
				array1[i] = 0;
				array2[i] = 0;
			}

			for (i = 0; i < sizee; i++)

				for (j = 0; j < sizee; j++)
					array1[i] = array1[i] + array[j][i];
			cout << "\n";
			cout << "The topological order is:";

			while (count < sizee)
			{
				for (k = 0; k < sizee; k++)
				{
					if ((array1[k] == 0) && (array2[k] == 0))
					{
						cout << k + 1 << " ";
						array2[k] = 1;
					}

					for (i = 0; i < sizee; i++)
					{
						if (array[i][k] == 1)
							array1[k]--;
					}
				}

				count++;
			}
			cout << "\n";
			break;
		}
		case 2:
		{
			Kruskal ob;
			cout << "\n";
			cout << "Implementation of Kruskal's algorithm\n\n";
			cout << "Enter the no. of vertices:";
			cin >> n;
			cout << "\n";
			cout << "So here matrix will be of order" << n << "x" << n;
			cout << "\n";
			cout << "\n\nEnter the cost adjacency matrix:\n";
			for (var1 = 1; var1 <= n; var1++)
			{
				for (var2 = 1; var2 <= n; var2++)
				{
					cin >> cost[var1][var2];
					if (cost[var1][var2] == 0)
						cost[var1][var2] = 999;
				}
			}
			cout << "\n\nSo now the edges of Minimum Cost Spanning Tree are as follow:\n\n";
			while (key < n)
			{
				for (var1 = 1, min = 999; var1 <= n; var1++)
				{
					for (var2 = 1; var2 <= n; var2++)
					{
						if (cost[var1][var2] < min)
						{
							min = cost[var1][var2];
							var3 = var5 = var1;
							var4 = var6 = var2;
						}
					}
				}
				var5 = ob.search(var5);
				var6 = ob.search(var6);
				if (ob.function(var5, var6))
				{
					cout << key++ << "." << " edge " << "(" << var3 << "," << var4 << " )" << " = " << min << "\n";
					mincost += min;
				}
				cost[var3][var4] = cost[var4][var3] = 999;
			}
			cout << "\n\tMinimum cost = " << mincost << "\n\n";
			break;
		}
		case 3:
		{
			cout << "\n\nImplementation of Prim algorithm\n\n";
			cout << "\n\nFor PRIM we are implementing for defined inputs in main function we are not implementing it for user input\n\n";
			Prim obj;
			/* Let us create the following array
			2    3
			(0)--(1)--(2)
			|   / \   |
			6| 8/   \5 |7
			| /     \ |
			(3)-------(4)
			9          */
			int array[size][size] = { { 0, 2, 0, 6, 0 },{ 2, 0, 3, 8, 5 },
			{ 0, 3, 0, 0, 7 },{ 6, 8, 0, 0, 9 },{ 0, 5, 7, 9, 0 }, };

			obj.prim(array);
			break;
		}
		case 4:
			exit(1);
		default:
			cout << "\nYou have entered wrong key\n";




		}

	}
}