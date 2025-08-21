#include <iostream>
#include <string.h>
using namespace std;

char rot13(char n){
	if ((n >= 'A' && n <= 'M') || (n >= 'a' && n <= 'm'))
		n += 13;
	else if ((n >= 'N' && n <= 'Z') || (n >= 'n' && n <= 'z'))
		n -= 13;
	return n;
}

int main(){
    char s[256];
    cin >> s;
    int len = strlen(s) - 1;
    for (int i = 0; i <= len; i++){
    	cout << rot13(s[i]);
	}
    return 0;
}
