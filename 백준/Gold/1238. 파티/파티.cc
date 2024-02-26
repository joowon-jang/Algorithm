#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x7f7f7f7f

using namespace std;

int n, m, x;

vector<int> dijkstra(vector<vector<pair<int,int>>>& graph, int start) {
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> dist(n+1,INF);
    
    dist[start]=0;
    pq.push({0,start});
    
    while(!pq.empty()) {
        int curr = pq.top().second;
        int currCost = pq.top().first;
        pq.pop();
        
        for(int i=0; i<graph[curr].size(); i++) {
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;
            
            if(dist[next] > currCost+nextCost) {
                dist[next] = currCost+nextCost;
                pq.push({currCost+nextCost, next});
            }
        }
    }
    
    return dist;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int ans=0;
    
    cin >> n >> m >> x;
    
    vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>(0));
    vector<vector<int>> dists;
    
    for(int i=0; i<m; i++) {
        int from, to, t;
        cin >> from >> to >> t;
        graph[from].push_back({to,t});
    }
    
    vector<int> v(0);
    dists.push_back(v);
    for(int i=1; i<=n; i++) {
        dists.push_back(dijkstra(graph, i));
    }
    
    for(int i=1; i<=n; i++) {
        ans = max(ans, dists[i][x]+dists[x][i]);
    }
    
    cout << ans;
    
    return 0;
}