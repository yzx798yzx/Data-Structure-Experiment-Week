#include<iostream>
#include<stdlib.h>
#define MAX 6
using namespace std;
typedef struct A{
	int adjvex;
	struct A *next;
}AN;

typedef struct g{
	AN *adjlist[MAX];
	int n,e;
}Graph;
Graph *creat(Graph *G, int n, int e, int A[MAX][MAX]) {
    int i, j;
    AN *p;
    G = (Graph *)malloc(sizeof(Graph));
    for (i = 0; i < MAX; i++) {
        G->adjlist[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 ) {
                p = (AN *)malloc(sizeof(AN));
                p->adjvex = j;
                p->next = G->adjlist[i];
                G->adjlist[i] = p;
            }
        }
    }
    G->n = n;
    G->e = e;
    return G;
}
void printfG(Graph *G){
	int i;
	AN *p;
	cout<<"ÁÚ½Ó±í"<<endl;
	for(i=0;i<G->n;i++){
		p=G->adjlist[i];
		cout<<i<<":->";
		while(p!=NULL){
			cout<<p->adjvex<<"->";
			p=p->next;
		}
		cout<<endl;
	}
}
int main(){
	Graph *G;
	int n=MAX;
	int e=6;
	int A[MAX][MAX] = {
		{0,1,0,0,1,0},
		{0,0,0,1,0,0},
		{1,0,0,0,0,0},
		{1,1,0,0,0,0},
		{0,1,1,1,0,0},
		{1,0,1,0,0,0}
	};
	G=creat(G,n,e,A);
	printfG(G);
	int B[MAX][MAX]={0};
	int i,j;
		AN *p;
	for(i=0;i<G->n;i++){
		p=G->adjlist[i];
		while(p){
			B[i][p->adjvex]=1;
			p=p->next;
		}
	}
	cout<<"ÁÚ½Ó¾ØÕó"<<endl;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
}
