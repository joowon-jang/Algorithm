#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1000001]={0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4; i<=n; i++) {
        int dp1=100001;
        int dp2=100001;
        int dp3=100001;
        if(i%3==0) {
            dp3=dp[i/3]+1;
        }
        if(i%2==0) {
            dp2=dp[i/2]+1;
        }
        dp1=dp[i-1]+1;
        dp[i]=min(min(dp1,dp2),dp3);
    }
    
    cout << dp[n];
    
    return 0;
}