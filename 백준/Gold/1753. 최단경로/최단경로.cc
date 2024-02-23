#include <iostream>
#include <vector>
#include <queue>

#define INF 0x7f7f7f7f

using namespace std;

int v, e, k;
vector<pair<int,int>> graph[20001];

void solution() {
    vector<int> dist;
    dist.push_back(INF);
    for(int i=1; i<=v; i++) {
        dist.push_back(INF);
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[k]=0;
    pq.push({0,k});
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        for(int i=0; i<graph[curr].size(); i++) {
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;
            
            if(dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                pq.push({dist[next], next});
            }
        }
    }
    
    for(int i=1; i<=v; i++) {
        if(dist[i]==INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> v >> e;
    cin >> k;
    
    for(int i=0; i<e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to,weight});
    }
    
    solution();

    return 0;
}