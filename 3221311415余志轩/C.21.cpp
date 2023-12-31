#include<iostream>
using namespace std;
int main(){
	int n,m,i,j=0;
	int a[100],b[100],c[100];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	i=0;
	int k=0;
	while(i<n&&j<n){
		if(a[i]<=b[j]){
			c[k++]=a[i++];
		}
		else{
			c[k++]=b[j++];
		}
	}
	if(i>=n){
		while(j<n){
			c[k++]=b[j++];
		}
	}
	else{
		while(i<n){
			c[k++]=a[i++];
		}
	}
	double s;
	s=c[n-1]+c[n];
	printf("%.1f",s/2);
} 
