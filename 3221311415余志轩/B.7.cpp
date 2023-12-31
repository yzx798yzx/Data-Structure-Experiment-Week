#include<iostream>
using namespace std;
int main(){
	int n;
	int a[100];
	int i,j,s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	} 
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				s++;
			}
		}
	}
	cout<<s;
} 
