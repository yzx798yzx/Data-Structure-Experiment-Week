#include<iostream>
using namespace std;
int main(){
	int n,i=0,j=0,m,a=0,b=0;
	cin>>n;
	while(n>0){
		if(n>=25){
			n=n-25;
			i++;
		}
		else if(n>=10){
			n=n-10;
			j++;
		}
		else if(n>=5){
			n=n-5;
			a++;
		}
		else  if(n>=1){
			n=n-1;
			b++;
		}
	} 
	if(i>0){
		cout<<i<<"��25�� "; 
	}
	if(j>0){
		cout<<j<<"��10�� ";
	}
	if(a>0){
		cout<<a<<"��5�� ";
	}
	if(b>0){
		cout<<b<<"��1�� ";
	} 
	return 0;
} 
