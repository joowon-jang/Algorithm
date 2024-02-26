#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x7f7f7f7f

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    int ans=0;
    
    cin >> n;
    cin >> m;
    
    vector<vector<long long>> dists(n+1,vector<long long>(n+1,INF));
    for(int i=1; i<=n; i++) {
        dists[i][i] = 0;
    }
    
    for(int i=0; i<m; i++) {
        int from, to;
        long long t;
        cin >> from >> to >> t;
        dists[from][to] = min(dists[from][to], t);
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(dists[i][j] > dists[i][k]+dists[k][j]) dists[i][j] = dists[i][k]+dists[k][j];
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dists[i][j]==INF) cout << 0 << " ";
            else cout << dists[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}