#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	string c;
	cin>>c;
	stack<char> s;
	int k=0;
	for(int i=0;i<c.length();i++){
		char x;
		cin>>x;
		while(s.empty()||s.top()!=x){
			 if (k >= c.length()) {
                break; 
            }
			s.push(c[k++]);
		}
		s.pop();
	}
	if(s.empty()){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
} 
