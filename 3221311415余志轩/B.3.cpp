#include<iostream>
#include<queue>
#define max 100
using namespace std;
typedef struct s{
	int x;
	int y;
	int n;
}S;
void bfs(int a[][max],S start ,int x2,int y2,int n,int m){
	queue<S> q;
	int v[max][max]={0};
	v[start.x][start.y]=1;
	q.push(start);
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		if(x==x2&&y==y2){
			cout<<q.front().n<<endl;
			break;
		}
		for(int i=0;i<=3;i++){
			int x3=x+dx[i],y3=y+dy[i];
			if(1<=x3&&n>=x3&&1<=y3&&m>=y3){
				if(a[x3][y3]==0&&v[x3][y3]==0){
					S t;
					t.x=x3;
					t.y=y3;
					t.n=q.front().n+1;
					q.push(t);
					v[x3][y3]==1;
				}
			}
		}
		q.pop();
	}
}
void digui(int a[][max],int x1,int y1,int x2,int y2,int *l,int n,int m){
	if(x1==x2&&y1==y2){
		cout<<*l<<endl;
		return ;
	}
	else if(1<=x1&&n>=x1&&1<=y1&&m>=y1&&a[x1][y1]==0){
		(*l)++;
		a[x1][y1]=1;
		digui(a,x1,y1+1,x2,y2,l,n,m);
		digui(a,x1+1,y1,x2,y2,l,n,m);
		digui(a,x1,y1-1,x2,y2,l,n,m);
		digui(a,x1-1,y1,x2,y2,l,n,m);
	}
}
int main(){
	int n,m,l=0;
	cin>>n>>m;
	int i,j;
	int a[max][max];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	S start;
	start.x=x1;
	start.y=y1;
	start.n=0;
	bfs(a,start,x2,y2,n,m);
	digui(a,x1,y1,x2,y2,&l,n,m);
} 
