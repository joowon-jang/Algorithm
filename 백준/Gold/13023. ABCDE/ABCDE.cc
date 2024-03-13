#include <iostream>
#include <vector>

using namespace std;

bool visit[2000];
int ans=0;

void dfs(vector<vector<int>>& graph, int curr, int cnt) {
    if(cnt==4) {
        ans=1;
        return;
    }
    for(int i=0; i<graph[curr].size(); i++) {
        if(!visit[graph[curr][i]]) {
            visit[graph[curr][i]]=true;
            dfs(graph, graph[curr][i], cnt+1);
            visit[graph[curr][i]]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n,vector<int>(0));
    
    for(int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visit[j] = false;
        }
        visit[i] = true;
        dfs(graph,i,0);
        if(ans) break;
    }
    
    cout << ans;
    
    return 0;
}