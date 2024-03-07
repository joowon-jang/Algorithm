#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int drink[10001]={0,};
    int dp[10001]={0,};
    
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> drink[i];
    }
    dp[1]=drink[1];
    dp[2]=drink[1]+drink[2];
    dp[3]=max({drink[1]+drink[2],drink[1]+drink[3],drink[2]+drink[3]});
    for(int i=4; i<=n; i++) {
        dp[i]=max({dp[i-1],dp[i-3]+drink[i-1]+drink[i],dp[i-2]+drink[i]});
    }
    
    cout << dp[n];

    return 0;
}