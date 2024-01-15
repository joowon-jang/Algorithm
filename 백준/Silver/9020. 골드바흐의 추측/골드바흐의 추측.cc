#include <iostream>
#include <cmath>

using namespace std;

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
    
    int t;
    int n;
    int num1, num2;
    
    cin >> t;
    while(t--) {
        cin >> n;
        num1=n/2;
        num2=n/2;
        while(num1>=2) {
            if(isPrime(num1) && isPrime(num2)) {
                cout << num1 << " " << num2 << "\n";
                break;
            }
            num1--;
            num2++;
        }
    }
    

    return 0;
}