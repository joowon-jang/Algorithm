#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    int coin[100];
    int dp[10001];
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }
    
    for(int i=1; i<=k; i++) {
        dp[i]=10001;
    }
    
    dp[0]=0;
    for(int i=0; i<n; i++) {
        for(int j=coin[i]; j<=k; j++) {
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    
    if(dp[k]==10001) cout << -1;
    else cout << dp[k];
    
    return 0;
}