#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    getline(cin, a);
    int i, j = 0, x = 0;
    for (i = 0; i < a.length(); i++) {
        if (a[i] != ' ' || x == 0) { 
            if (a[i] != ' ') {
                cout << a[i];
                x = 0;
            }
            else if (x == 0) {
                cout << ' '; 
                x = 1;
            }
        }
    }
    return 0;
}

