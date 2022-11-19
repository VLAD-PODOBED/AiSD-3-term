#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999

#define V 8

int G[V][V] = {
//    1  2  3  4  5  6  7  8 
/*1*/{0, 2, 0, 8, 2, 0, 0, 0},
/*2*/{2, 0, 3, 10, 5, 0, 0, 0},
/*3*/{0, 3, 0, 0, 12, 0, 0, 7},
/*4*/{8, 10, 0, 0, 14, 3, 1, 0},
/*5*/{2, 5, 12, 14, 0, 11, 4, 8},
/*6*/{0, 0, 0, 3, 11, 0, 6, 0},
/*7*/{0, 0, 0, 1, 4, 6, 0, 9},
/*8*/{0, 0, 7, 0, 8, 0, 9, 0},
};

int main() {

    int no_edge;            

    int selected[V];

    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;

    int x;            
    int y;            

    cout << "Edge" << " : " << "Weight";
    cout << endl;
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { 
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }

    return 0;
}