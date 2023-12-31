#include<iostream>
#include<cstdlib>
#define Max 100
#define INF 9999
using namespace std;
typedef struct {
	int s;
    int e;
    int weight;
} S;

S adj[Max];
int lmax[Max];

void ford(int end ,int n,int m) {
	for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = adj[j].s;
            int v = adj[j].e;
            int w = adj[j].weight;
            if (lmax[u] != INF && lmax[v] > lmax[u] + w) {
                lmax[v] = lmax[u] + w;
            }
        }
    }
}
void A(int n, int m,int end) {
    for (int i = 1; i <= n; i++) {
        lmax[i] = INF;
    }
    lmax[end] = 0;
    ford(end, n,m);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
       cin>>adj[i].s>>adj[i].e>>adj[i].weight;
    }
    int  end;
    cin >> end;
    A(n,m,end);
	for (int i = 1; i <= n; i++) {
        if (lmax[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << lmax[i] << endl;
        }
    }
    return 0;
    /*
7 8
0 1 2
0 2 4
1 3 3
2 3 5
3 4 7
3 5 3
4 5 2
5 6 1
0 6
*/
    
}

