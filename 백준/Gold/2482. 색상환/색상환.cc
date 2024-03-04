#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    int dp[1001][1001] = {0};
    
    cin >> n;
    cin >> k;
    
    for(int i=1; i<=n; i++) {
        dp[i][1] = i;
    }
    
    for(int i=4; i<=n; i++) {
        for(int j=2; j<=i/2; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1])%1000000003;
        }
    }
    
    cout << dp[n][k];

    return 0;
}