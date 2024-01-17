#include <iostream>
#include <vector>

using namespace std;

int n, m;
int cnt = -1;
vector<int> computer;
vector<vector<int>> graph;

void solution(int x) {
    computer[x] = 1;
    cnt++;
    for(int i=0; i<graph[x].size(); i++) {
        if(computer[graph[x][i]] != 1) solution(graph[x][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int from, to;
    
    cin >> n;
    for(int i=0; i<=n; i++) {
        computer.push_back(0);
        vector<int> v;
        graph.push_back(v);
    }
    cin >> m;
    
    for(int i=0; i<m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    solution(1);
    cout << cnt;

    return 0;
}