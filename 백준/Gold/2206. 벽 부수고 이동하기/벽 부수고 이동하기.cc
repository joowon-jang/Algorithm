#include <iostream>
#include <queue>

using namespace std;

int n, m;
char board[1001][1001];
int dist[1001][1001][2];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct Element {
    int r;
    int c;
    int cnt;
};

bool isIn(int r, int c) { return (r>0 && r<=n && c>0 && c<=m); }

int bfs() {
    queue<Element> q;
    q.push({1,1,0});
    dist[1][1][0] = 1;
    
    while(!q.empty()) {
        int cR = q.front().r;
        int cC = q.front().c;
        int cCnt = q.front().cnt;
        
        q.pop();
        
        if(cR==n && cC==m) {
            return dist[n][m][cCnt];
        }
        
        for(int i=0; i<4; i++) {
            int nR = cR + dir[i][0];
            int nC = cC + dir[i][1];
            int nCnt = cCnt;
            
            if(board[nR][nC] == '1') nCnt++;
            if(nCnt > 1) continue;
            if(!isIn(nR,nC)) continue;
            if(dist[nR][nC][nCnt] != 0) continue;
            
            dist[nR][nC][nCnt] = dist[cR][cC][cCnt] + 1;
            q.push({nR,nC,nCnt});
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> board[i][j];
        }
    }
    cout << bfs();
    
    return 0;
}