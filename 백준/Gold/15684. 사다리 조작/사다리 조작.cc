#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x7f7f7f7f

using namespace std;

int n, m, h;
vector<int> curr;
int ans = INF;

void dfs(vector<vector<int>>& ladder, int depth, int cnt) {
    if(cnt > 3) return;
    if(depth == h+1) {
        for(int i=1; i<=n; i++) {
            if(curr[i] != i) return;
        }
        ans = min(cnt,ans);
        return;
    }
    
    for(int i=1; i<=n; i++) {
        if(ladder[depth][curr[i]-1] == 1) {
            curr[i]--;
        }
        else if(ladder[depth][curr[i]] == 1) {
            curr[i]++;
        }
    }
    dfs(ladder, depth+1, cnt);
    for(int i=1; i<=n; i++) {
        if(ladder[depth][curr[i]-1] == 1) {
            curr[i]--;
        }
        else if(ladder[depth][curr[i]] == 1) {
            curr[i]++;
        }
    }
    
    for(int i=1; i<n; i++) {
        if(ladder[depth][i-1] == 0 && ladder[depth][i] == 0) {
            if(ladder[depth][i+1] == 0) {
                ladder[depth][i] = 1;
                dfs(ladder, depth, cnt+1);
                ladder[depth][i] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> h;
    vector<vector<int>> ladder(h+1, vector<int>(n+1,0));
    
    for(int i=0; i<=n; i++) {
        curr.push_back(i);
    }
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    
    dfs(ladder, 1, 0);
    
    if(ans > 3) ans = -1;
    cout << ans;
    
    return 0;
}