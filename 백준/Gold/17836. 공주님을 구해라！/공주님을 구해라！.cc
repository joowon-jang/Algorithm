#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, t;
pair<int,int> gramPos;
int map[101][101];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool isIn(int y, int x) {
    if(y<=0 || x<=0 || y>n || x>m) return false;
    else return true;
}

void bfs() {
    queue<pair<int,int>> q;
    
    map[1][1]=0;
    q.push({1,1});
    
    while(!q.empty()) {
        int cR = q.front().first;
        int cC = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nR = cR + dir[i][0];
            int nC = cC + dir[i][1];
            if(isIn(nR,nC)) {
                if(map[nR][nC]>map[cR][cC]+1) {
                    map[nR][nC]=map[cR][cC]+1;
                    q.push({nR,nC});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> t;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];

            if(map[i][j]==2) gramPos={i,j};
            if(map[i][j]==1) map[i][j]=-1;
            else map[i][j]=10001;
        }
    }
    
    bfs();
    
    if(min(map[n][m], map[gramPos.first][gramPos.second] + (n-gramPos.first) + (m-gramPos.second))>t) cout << "Fail";
    else cout << min(map[n][m], map[gramPos.first][gramPos.second] + (n-gramPos.first) + (m-gramPos.second));
    
    return 0;
}