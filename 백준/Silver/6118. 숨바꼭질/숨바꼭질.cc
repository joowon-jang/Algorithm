#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x7f7f7f7f

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    int maxDist = 0;
    
    int cnt = 0;
    int ans;
    
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(0));
    vector<int> dist(n+1, INF);
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    
    for(int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()) {
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int i=0; i<graph[curr].size(); i++) {
            int next = graph[curr][i];
            if(dist[next] > cost + 1) {
                dist[next] = cost + 1;
                pq.push({cost+1, next});
                maxDist = max(cost+1, maxDist);
            }
        }
    }
    
    for(int i=n; i>=1; i--) {
        if(maxDist == dist[i]) {
            ans = i;
            cnt++;
        }
    }
    
    cout << ans << " " << maxDist << " " << cnt;

    return 0;
}