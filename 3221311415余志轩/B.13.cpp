#include<iostream>
#include<cstdlib>
#include<climits>
#define Max 100
#define INF -9999
using namespace std;
typedef struct {
    int e;
    int weight;
} S;
S adj[Max][Max]={-1};
int lmax[Max];
int p[Max];

void Printf(int start, int end) {
    if (start == end) {
        cout << start;
    }
    else {
        Printf(start, p[end]);
        cout << " " << end;
    }
}

void dfs(int start, int n) {
    for (int i = 0; i < n; i++) {
        if (adj[start][i].e != -1) {
            int v = adj[start][i].e;
            int w = adj[start][i].weight;
            if (lmax[start] + w > lmax[v]) {
                lmax[v] = lmax[start] + w;
                p[v] = start;
                if (lmax[v] > lmax[start]) {
                    dfs(v, n);
                }
            }
        }
    }
}


void A(int n, int start, int end) {
    for (int i = 0; i < n; i++) {
        lmax[i] = INF;
        p[i] = -1;
    }
    lmax[start] = 0;
    dfs(start, n);
    Printf(start, end);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s][e].e = e;
        adj[s][e].weight = w;
    }
    int start, end;
    cin >> start >> end;
    A(n, start, end);

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

