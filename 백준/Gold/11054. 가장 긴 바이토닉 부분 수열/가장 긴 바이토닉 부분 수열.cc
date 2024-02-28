#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int arr[1000];
    int dp[1000];
    int rdp[1000];
    int ans=0;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        dp[i]=1;
        rdp[i]=1;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>=i; j--) {
            if(arr[j] < arr[i]) {
                rdp[i] = max(rdp[j]+1, rdp[i]);
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i] + rdp[i] - 1);
    }
    cout << ans;

    return 0;
}