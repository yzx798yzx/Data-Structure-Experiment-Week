#include<iostream>
#include<string>
#include<stdlib.h>
#define MAX 5
using namespace std;
int t=0;
typedef struct s{
    int a[MAX][MAX];
    int vn;
}S;

S* creat(S *G, int arc[][MAX]){
    for(int i=0; i<G->vn; i++){
        for(int j=0; j<G->vn; j++){
            G->a[i][j] = arc[i][j];
        }
    } 
    return G;
}
void DFS(S*G,int v[],int index){
	v[index]=1;
	for(int i=0;i<G->vn;i++){
		if(G->a[index][i]==1){
			if(!v[i]){
				DFS(G,v,i);
			}
			else if(v[i]){
				t=1;
				return ;
			}
		}
	}
}
int main(){
    S *G = new S;
    G->vn = MAX;
    int i,j;
    int arc[MAX][MAX];
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cin>>arc[i][j];
		}
	} 
    /*int arc[5][5] = {
0 1 0 1 0
0 0 1 0 0
0 0 0 1 0
1 0 0 0 1
1 0 0 0 0
    };*/
    G = creat(G, arc);
    int v[MAX]={0};
    DFS(G,v,0);
    if(t==1){
    	cout<<"yes";
	}
	else{
		cout<<"no";
	}
    return 0;
}

