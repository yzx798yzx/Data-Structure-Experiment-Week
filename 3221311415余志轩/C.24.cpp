#include<iostream>
#include<stack>
using namespace std;
//Õ» 
void A(int n){
	stack<int>A;
	while(n>0){
		A.push(n%2);
		n=n/2;
	}
	while(!A.empty()){
		cout<<A.top();
		A.pop();
	}
	cout << endl;
}
void B(int n){
	stack<int>B;
	while(n>0){
		B.push(n%8);
		n=n/8;
	}
	while(!B.empty()){
		cout<<B.top();
		B.pop();
	}
	cout << endl;
}
void C(int n){
	stack<char>C;
	 char c[] = "0123456789ABCDEF";
	while(n>0){
		C.push(c[n%16]);
		n=n/16;
	}
	while(!C.empty()){
		cout<<C.top();
		C.pop();
	}
	cout << endl;
}
//µÝ¹é
void A2(int n){
	if(n==0){
		cout<<endl;
		return;
	}
	else{
		A2(n/2);
		cout<<n%2;
	}
} 
int main(){
	int n;
	cin>>n;
	A(n);
	B(n);
	C(n);
	A2(n);
 } 
