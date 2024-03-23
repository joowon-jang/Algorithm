#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isIn(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=m) return false;
    else return true;
}

int bfs(vector<vector<int>> map, queue<pair<int,int>> q) {
    int cnt = 0;
    while(!q.empty()) {
        int cR = q.front().first;
        int cC = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nR = cR + dir[i][0];
            int nC = cC + dir[i][1];
            
            if(!isIn(nR,nC) || map[nR][nC] > 0) continue;
            map[nR][nC] = 2;
            q.push({nR,nC});
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 0) cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    int ans=0;
    
    cin >> n >> m;
    vector<vector<int>> map(n,vector<int>(0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int tmp;
            cin >> tmp;
            if(tmp == 2) q.push({i,j});
            if(tmp == 0) v.push_back({i,j});
            map[i].push_back(tmp);
        }
    }
    
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            for(int k=j+1; k<v.size(); k++) {
                map[v[i].first][v[i].second] = 1;
                map[v[j].first][v[j].second] = 1;
                map[v[k].first][v[k].second] = 1;
                ans = max(ans, bfs(map, q));
                map[v[i].first][v[i].second] = 0;
                map[v[j].first][v[j].second] = 0;
                map[v[k].first][v[k].second] = 0;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}