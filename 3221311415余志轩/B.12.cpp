#include <iostream>
#include <string>
using namespace std;

int  A(string s, string p) {
    if (s[0] == '\0' && p[0] == '\0') {
        return 1;
    }

    int i = 0, j = 0;

    while (i < s.length() && j < p.length()) {
        if (p[j] == '.') {
            j++;
            i++;
        } else if (s[i] == p[j]) {
            j++;
            i++;
        } else if (p[j] == '*') {
            if (s[i] == p[j - 1]) {
                i++;
            } else {
                j++;
            }
        } else {
            return 0;
        }
    }

    if (s[i] == '\0' && p[j] == '\0') {
        return 1;
    }
    else if(s[i]=='\0'&&p[p.length()]=='*'){
    	return 1;
	}
	else {
        return 0;
    }
}

int main() {
    string s, p;
    cin >> s >> p;
    if (A(s, p)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
    /*
mississippi
mis*is*ip..
*/
}

