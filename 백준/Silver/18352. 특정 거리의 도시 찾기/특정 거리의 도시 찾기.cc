#include <iostream>
#include <vector>
#include <queue>

#define INF 0x7f7f7f7f

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, k, x;
    int cnt=0;
    
    cin >> n >> m >> k >> x;
    
    vector<vector<int>> graph(n+1,vector<int>(0));
    vector<int> dist;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    
    for(int i=0; i<=n; i++) {
        dist.push_back(INF);
    }
    pq.push({x,0});
    dist[x]=0;
    
    while(!pq.empty()) {
        int curr=pq.top().first;
        int cost=pq.top().second;
        pq.pop();
        
        for(int i=0; i<graph[curr].size(); i++) {
            int next=graph[curr][i];
            if(dist[next] > cost+1) {
                dist[next] = cost+1;
                pq.push({next,cost+1});
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(dist[i]==k) {
            cout << i << "\n";
            cnt++;
        }
    }
    if(cnt==0) cout << -1;
    
    return 0;
}