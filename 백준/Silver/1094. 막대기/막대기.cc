#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int cnt=0;
    cin >> n;
    
    while(n>0) {
        if(n & 1) cnt++;
        n = n >> 1;
    }
    
    cout << cnt;

    return 0;
}