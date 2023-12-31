#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
typedef struct s{
	char a;
	struct s *left;
	struct s *right;
}S; 
void create(S **t, string c, int *i) {
    char ch;
    ch = c[*i];
    (*i)++;
    if (ch == '#') {
        *t = NULL;
    } else {
        *t = (S *)malloc(sizeof(S));
        (*t)->a = ch;
        create(&((*t)->left), c, i);
        create(&((*t)->right), c, i);
    }
}
void findt(S* t,string f,char d,int *l){
	if(t==NULL){
		return;
	}
	f+=t->a;
	f+=' ';
	if(t->a==d){
		cout<<f;
		*l=1;
	}
	findt(t->left,f,d,l);
	findt(t->right,f,d,l);	
}  
int main(){
	S *t;
	string c,f;
	char d;
	cin>>c;
	cin>>d;
	int i=0,l=0;
	create(&t,c,&i);
	findt(t,f,d,&l);
	if(l==0){
		cout<<d<<"不是叶子节点";
	}
}
