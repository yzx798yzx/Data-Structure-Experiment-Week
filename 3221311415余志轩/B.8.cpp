#include<iostream>
#include<string>
#include<stdlib.h>
#define MAX 5
using namespace std;
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
		}
	}
}
bool BianLi(S*G,int n){
	int i,j;
	for(i=0;i<n;i++){
		int v[MAX]={0};
		DFS(G,v,i);
		for(j=0;j<MAX;j++){
			//cout<<v[j];
			if(v[j]==0){
				return false;
			}
		}
	}
	return true;
}
int main(){
    S *G = new S;
    G->vn = MAX;
    int n;
    int j,i,m,k,l,t;
    cin>>n;
    int a[5][5] = {0};
    while(n--){
    	cin>>m>>k;
    	for(i=1;i<=m;i++){
    		cin>>l;
    		a[k][l]=1;
		}
	}
	/*for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
    G = creat(G, a);
   if(BianLi(G,MAX)){
    	cout<<"yes";
	}
	else{
		cout<<"no";
	}
   
    return 0;
}

