#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int dp[1001][100001] = {0,};
vector<pair<int, int>> things;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    things.push_back({0,0});
    for(int i=0; i<n; i++) {
        int w, v;
        cin >> w >> v;
        things.push_back({w,v});
    }
    
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(things[j].first > i){
                dp[j][i] = dp[j-1][i];
            }
            else{
                dp[j][i] = max(dp[j-1][i-things[j].first]+things[j].second,  dp[j-1][i]);
            }
        }
    }
    cout << dp[n][k];

    return 0;
}