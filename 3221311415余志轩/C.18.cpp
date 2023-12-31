#include <iostream>
using namespace std;
#include<stdlib.h> 
typedef struct s {
    int n;
    struct s* next;
} S;

S* creat(S* head,int m) {
    S* p, * t = NULL;
    head = NULL;
    int i=1;
    while (i<=m) {
        p = (S*)malloc(sizeof(S));
        p->n = i;
        i++;
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
    t->next = head;
    return head;
}

void delet(S* head, int mun) {
    S* x = head, * y = NULL;
    int i = 0;
    while (1) {
        i++;
        if (i % 3 == 0) {
            y->next = x->next;
            i = 0;
            mun--;
            cout <<x->n<<" ";
        }
        else {
            y = x;
        }
        x = x->next;
        if (mun == 1) {
            cout <<"最后的数："<< x->n;
            break;
        }
    }
}

int main() {
    S* head = NULL;
    int n;
    cin >> n;
    head = creat(head, n);
    delet(head, n);
    return 0;
}

