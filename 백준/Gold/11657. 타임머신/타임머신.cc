#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> dist(n+1,INF);
    vector<vector<int>> edges(m,vector<int>(0));
    
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i].push_back(a);
        edges[i].push_back(b);
        edges[i].push_back(c);
    }
    dist[1]=0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int curr=edges[j][0];
            int next=edges[j][1];
            int cost=edges[j][2];
            
            if(dist[curr] != INF && dist[next] > dist[curr] + cost) {
                if(i==n-1) {
                    cout << -1;
                    return 0;
                }
                dist[next] = dist[curr] + cost;
            }
        }
    }
    
    
    for(int i=2; i<=n; i++) {
        if(dist[i]==INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
    
    return 0;
}