
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define V 8
int parent[V];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST(int cost[][V])
{
    int mincost = 0; 
    for (int i = 0; i < V; i++)
        parent[i] = i;
    cout << "Edge" << " : " << "Weight"<<endl;
    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);

        printf("%d - %d :%d \n",
            edge_count++, a, b, min);
        mincost += min;
    }

}

int main()
{

    int cost[][V] = {
       
            //    1  2  3  4  5  6  7  8 
            /*1*/{INT_MAX, 2, INT_MAX, 8, 2, INT_MAX, INT_MAX, INT_MAX},
            /*2*/{2,INT_MAX, 3, 10, 5, INT_MAX, INT_MAX, INT_MAX},
            /*3*/{INT_MAX, 3,INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 7},
            /*4*/{8, 10,INT_MAX, INT_MAX, 14, 3, 1, INT_MAX},
            /*5*/{2, 5, 12, 14, INT_MAX, 11, 4, 8},
            /*6*/{INT_MAX, INT_MAX, INT_MAX, 3, 11, INT_MAX, 6, INT_MAX},
            /*7*/{INT_MAX, INT_MAX, INT_MAX, 1, 4, 6, INT_MAX, 9},
            /*8*/{INT_MAX, INT_MAX, 7, INT_MAX, 8,INT_MAX, 9, INT_MAX},
            };

    kruskalMST(cost);

    return 0;
}