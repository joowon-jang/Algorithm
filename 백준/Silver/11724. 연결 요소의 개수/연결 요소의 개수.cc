#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
bool visit[1001];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visit[x] = 1;
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        for(int i=0; i<graph[f].size(); i++) {
            if(visit[graph[f][i]] == 0) {
                visit[graph[f][i]] = 1;
                q.push(graph[f][i]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int from, to;
    int cnt = 0;
    
    cin >> n >> m;
    for(int i=0; i<=n; i++) {
        vector<int> v;
        graph.push_back(v);
    }
    
    for(int i=0; i<m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=1; i<=n; i++) {
        if(visit[i] == 0) {
            bfs(i);
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}