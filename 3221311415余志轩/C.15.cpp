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
   	cout<<"�ǰڶ�����"; 
   }
   else {
   	cout<<"���ǰڶ����У���Ҫɾ��"<<k<<"���ַ�";
   } 
    return 0;
}

