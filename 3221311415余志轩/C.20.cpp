#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;

typedef struct Node {
    int num;
    struct Node* next;
} S;

S* create(S* head, int n) {
    S* p, * t = NULL;
    while (n--) {
        p = (S*)malloc(sizeof(S));
        cin >> p->num;
        if (head == NULL) {
            head = p;
            head->next = NULL;
        }
        if (t != NULL) {
            t->next = p;
        }
        t = p;
        t->next = NULL;
    }
    return head;
}
void display(S* head, S** x, S** y) {
    S* p1 = NULL; 
    S* p2 = NULL; 
    int a = 0, b = 0;
    while (head != NULL) {
        if (head->num % 2 != 0) { 
            if (a == 0) {
                *x = head;
                p1 = head;
                a = 1;
            } else {
                p1->next = head;
                p1 = head;
            }
        } else { 
            if (b == 0) {
                *y = head;
                p2 = head;
                b = 1;
            } else {
                p2->next = head;
                p2 = head;
            }
        }
        head = head->next;
    }
    if(p1!=NULL)
    p1->next=NULL;
    if(p2!=NULL)
    p2->next=NULL;
}

int main(){
	S *head=NULL,*x=NULL,*y=NULL;
	int n,i,j;
	cin>>n;
	head=create(head,n);
	display(head,&x,&y);
	if(x!=NULL){
		cout<<"L1: ";
	    while(x->next){
			cout<<x->num<<" -> ";
			x=x->next;
		}
		cout<<x->num<<endl;
	}
	if(y!=NULL){
		cout << "L2: ";
		while(y->next){
			cout<<y->num<<" -> ";
			y=y->next;
		}
		cout<<y->num<<endl;
	}
	
}
