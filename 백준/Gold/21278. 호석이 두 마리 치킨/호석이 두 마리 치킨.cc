#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int curr;
    int cnt;
};

vector<vector<int>> graph;

int bfs(int a, int b) {
    int totalT=0;
    bool visit[101]={0};
    queue<Node> q;
    
    visit[a]=true;
    visit[b]=true;
    q.push({a,0});
    q.push({b,0});
    
    while(!q.empty()) {
        int fCurr = q.front().curr;
        int fCnt = q.front().cnt;
        totalT+=fCnt;
        q.pop();
        
        for(int i=0; i<graph[fCurr].size(); i++) {
            if(!visit[graph[fCurr][i]]) {
                visit[graph[fCurr][i]]=true;
                q.push({graph[fCurr][i],fCnt+2});
            }
        }
    }
    
    return totalT;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    int ans1, ans2;
    int minT=0x7f7f7f7f;
    
    cin >> n >> m;
    graph.resize(n+1,vector<int>(0));
    
    for(int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            int t=bfs(i,j);
            if(t<minT) {
                ans1=i;
                ans2=j;
            }
            minT=min(t,minT);
        }
    }
    
    cout << ans1 << " " << ans2 << " " << minT;
    
    return 0;
}