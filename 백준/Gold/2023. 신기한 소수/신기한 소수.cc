#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;

bool isPrime(int n) {
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) return false;
    }
    return true;
}

void makePrime(int cnt, int num) {
    if(cnt==n) {
        cout << num << "\n";
    }
    else {
        num*=10;
        for(int i=1; i<=9; i++) {
            if(isPrime(num+i)) {
                makePrime(cnt+1,num+i);
            }
        }
    }
}

int main()
{
    cin >> n;
    
    for(int i=2; i<=9; i++) {
        if(isPrime(i)) {
            makePrime(1,i);
        }
    }

    return 0;
}