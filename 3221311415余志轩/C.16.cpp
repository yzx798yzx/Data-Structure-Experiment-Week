#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct s{
	int a;
	struct s *next;
	struct s *pre;
}S; 
S* create(S* head, int n) {
    S *p, *t = NULL;
    while (n--) {
        p = (S*)malloc(sizeof(S));
        cin >> p->a;
        p->next = NULL;
        p->pre = t;
        if (head == NULL) {
            head = p;
        } else {
            t->next = p;
        }
        t = p;
    }
    return head;
}
bool com(S*A,S*B){
	if(B==NULL){
		return true;
	}
	if(A==NULL){
		return false;
	}
	if(A->a==B->a){
		return com(A->next,B->next);
	}
	return com(A->next,B);
}
int main(){
	S *A=NULL,*B=NULL;
	int n,m;
	cin>>n;
	A=create(A,n);
	cin>>m;
	B=create(B,m);
	if(com(A,B)){
		cout<<"是子序列";
	}
	else{
		cout<<"不是子序列";
	}

}

