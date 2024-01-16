#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,v;
vector<int> graph[10001];
vector<bool> visited;
queue<int> q;

void DFS(int v) {
    cout << v << " ";
    visited[v] = true;
    for(int i=0; i<graph[v].size(); i++) {
        if(!visited[graph[v][i]]) {
            DFS(graph[v][i]);
        }
    }
}

void BFS(int v){
    q.push(v);
    visited[v] = true;
    cout << v << " ";
    
    while(!q.empty()) {
        v = q.front();
        q.pop();
        
        for(int i = 0; i<graph[v].size(); i++) {
            if(!visited[graph[v][i]]) {
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
                cout << graph[v][i] << " ";
            }
        }
    }
}
    

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s,e;
    
    cin >> n >> m >> v;
    visited.assign(n + 1, false);
    for(int i=0; i<m; i++) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    for(int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    DFS(v);
    cout << "\n";
    visited.assign(n+1,false);
    BFS(v);

    return 0;
}