#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct s{
	int a;
	struct s *left ;
	struct s *right;
}S;
S* inserT(S* t,int k){
	if(t==NULL){
		t=new S;
		t->a=k;
		t->left=NULL;
		t->right=NULL;
	}
	else if(k<t->a){
		t->left=inserT(t->left,k);
	}
	else if(k>t->a){
		t->right=inserT(t->right,k);
	}
	return t;
}
S* create(int c[],int n){
	S*t=NULL;
	int i=0;
	while(i<n){
		t=inserT(t,c[i]);
		i++;
	}
	return t;
}
bool Find(S *t,int k){
	if(t==NULL){
		return false;
	}
	if(k==t->a){
		return true;
	}
	if(k<t->a){
		cout<<t->a<<"->";
		return Find(t->left,k);
	}
	else if(k>t->a){
		cout<<t->a<<"->";
		return Find(t->right,k);
	}
}
int main(){
	S *t;
	int c[100];
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>c[i];
	}
	t=create(c,n);
	int k;
	cin>>k;
	if(Find(t,k)){
		cout<<k<<endl;
	}
	else{
		cout<<"not found";
	}
}
