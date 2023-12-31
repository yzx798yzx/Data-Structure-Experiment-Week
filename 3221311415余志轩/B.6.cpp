#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct s{
	int start;
	int end;
	int weight;
}S;
void Printf(int n,int p[]){
	if(n==0){
		cout<<"0"<<" "; 
		return ;
	}
	else{
		Printf(p[n],p);
		cout<<n<<" ";
	}
	
}
void A(S G[],int n,int m){
	int p[n]={-1},lmax[n]={0};
	int i,j,s,e,w;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			s=G[j].start;
			e=G[j].end;
			w=G[j].weight;
			if(w+lmax[s]>lmax[e]){
				p[e]=s;
				lmax[e]=w+lmax[s];
			}
		}
	}
	cout << "关键路径上的节点：";
    Printf(n-1, p); 
    cout << endl;

}
int main(){
	int n,m,i,j;
	cin>>n>>m;
	S G[m];
	for(i=0;i<m;i++){
		cin>>G[i].start>>G[i].end>>G[i].weight;
	}
	A(G, n, m);
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
*/
}
