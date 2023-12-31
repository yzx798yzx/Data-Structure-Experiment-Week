#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef struct s{
	int n;
	struct s *left;
	struct s *right;
	int k=1;
}S;
void create(S **t,int a[][3],int y){
	int x1,x2;
	if(y==-1){
		*t=NULL;
	}
	else{
		x1=a[y-1][1];
		x2=a[y-1][2];
		*t = (S *)malloc(sizeof(S));
		(*t)->n=y;
		create(&((*t)->left), a,x1);
        create(&((*t)->right),a,x2);
	}
}
void prePreint(S*t){
	stack<S*> l;
	S*h=t;
	if(h!=NULL){
		l.push(h);
		while(!l.empty()){
			h=l.top();
			l.pop();
			cout<<h->n<<" ";
			if(h->right!=NULL){
				l.push(h->right);
			}
			if(h->left!=NULL){
				l.push(h->left);
			}
		}
	}
}
void inPrint(S*t){
	stack<S*> l;
	S* h=t;
	while(h!=NULL||!l.empty()){
		if(h!=NULL){
			l.push(h);
			h=h->left;
		}
		else{
			h=l.top();
			cout<<h->n<<" ";
			l.pop();
			h=h->right;
		}
	}
}
void postPrint(S *t) {
    stack<S*> l;
    S* h = t;
    S* v = NULL;
    while (h != NULL || !l.empty()) {
        if (h != NULL) {
            l.push(h);
            h = h->left;
        } else {
            S* p = l.top();
            if (p->right != NULL && p->right != v) {
                h = p->right;
            } else {
                cout << p->n << " ";
                v = p;
                l.pop();  // 弹出已经访问过的节点
                h = NULL;  // 将 h 设置为 NULL，以便下一次循环时可以正确更新 h 的值
            }
        }
    }
}

int main(){
	S *t; 
	int a[100][3];
	int n,i,j=0;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	create(&t,a,a[0][0]); 
	cout<<"前序遍历"<<endl;
	prePreint(t);
	cout<<endl;
	cout<<"中序遍历"<<endl;
	inPrint(t);
	cout<<endl;
	cout<<"后序遍历"<<endl;
	postPrint(t);
	
}

