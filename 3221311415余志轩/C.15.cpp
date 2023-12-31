#include <iostream>
using namespace std;

int main() {
    int n,a[100], i = 0, j, l = 0,k=0;
    cin>>n;
    while (n--) {
    	cin>>a[i++];
    }
    for (j = 0; j < i - 1; j++) {
        if (a[j] > a[j + 1]) {
            l--;
            if(l<=-2){
            	k++;
			}
        } 
        else if (a[j] < a[j + 1]) {
            l++;
            if(l>=2){
            	k++;
			}
        }
    }
   if(k==0){
   	cout<<"是摆动数列"; 
   }
   else {
   	cout<<"不是摆动数列，需要删除"<<k<<"个字符";
   } 
    return 0;
}

