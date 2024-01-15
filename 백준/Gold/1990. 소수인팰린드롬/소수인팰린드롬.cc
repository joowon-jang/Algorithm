#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPalinDrome(int n) {
    string str=to_string(n);
    
    string original=str;
    reverse(str.begin(),str.end());
    
    if(original==str) return true;
    else return false;
}

bool isPrime(int n) {
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    
    for(int i=a; i<=b; i++) {
        if(i>10000000) break;
        if(isPalinDrome(i) && isPrime(i)) {
            cout << i << "\n";
        }
    }
    
    cout << "-1";
    
    return 0;
}