#include<iostream>
#include<string>
using namespace std;
typedef struct s{
	string a;
	int l;
}S;
void KMP(int next[],S t){
	int j=0,k=-1;
	next[0]=-1;
	while(j<t.l-1){
		if(k==-1||t.a[j]==t.a[k]){
			j++;
			k++;
			if(t.a[j]==t.a[k]){
				next[j]=next[k];
			}
			else{
				next[j]=k;
			}
		}
		else{
			k=next[k];
		}
	}
}
void find(S t,S h){
	int next[100],i=0,j=0,n=0;
	KMP(next,t);
	while(j<t.l&&i<h.l){
		if(j==-1||h.a[i]==t.a[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>=t.l){
		cout<<i-t.l<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
}
int main(){
	S t,h;
	cin>>h.a;
	cin>>t.a;
	h.l=h.a.length();
	t.l=t.a.length();
	find(t,h);
	return 0;
}
