#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct s{
	int a;
	struct s *next;
	struct s *pre;
}S;
S* create(S* head,int n){
	S* t=NULL,*p;
	while(n--){
		p=new S;
		cin>>p->a;
		p->next=NULL;
		p->pre=t;
		if(head==NULL){
			head=p;
		}
		else{
			t->next=p;
		}
		t=p;
	}
	return head;
} 
void FindA(S* h,S* t){
	while(t!=NULL){
		S *p=h;
		while(p!=NULL){
			if(p->a==t->a){
				cout<<p->a<<" ";
			}
			p=p->next;
		}
		t=t->next;
	}
	cout<<endl;
}
void FindB(S* h, S* t) {
    S* p = h;
    while (p != NULL) {
        cout << p->a << " ";
        p = p->next;
    }
    while (t != NULL) {
        p = h;
        int l = 0;
        while (p != NULL && p->a != t->a) {
            p = p->next;
            l = 1;
        }
        if (p == NULL && l == 1) {
            cout << t->a << " ";
        }
        t = t->next;
    }
}

int main(){
	int n,m;
	cin>>n;
	S* head=NULL;
	head=create(head,n);
	cin>>m;
	S* t=NULL;
	t=create(t,m);
	cout<<"交集:";
	FindA(head,t);
	cout<<"并集:";
	FindB(head,t);
	 
}
