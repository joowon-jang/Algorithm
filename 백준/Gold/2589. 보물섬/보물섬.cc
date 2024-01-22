#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct location {
    int r;
    int c;
    int cnt;
};

int n, m;
char map[51][51];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int res=0;

bool isIn(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=m) return false;
    else return true;
}

void bfs(int r, int c) {
    bool visit[51][51]={0};
    queue<location> q;
    
    visit[r][c]=true;
    q.push({r,c,0});
    
    while(!q.empty()) {
        int curR=q.front().r;
        int curC=q.front().c;
        int curCnt=q.front().cnt;
        res=max(res,curCnt);
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nR=curR+dir[i][0];
            int nC=curC+dir[i][1];
            if(isIn(nR,nC) && map[nR][nC]=='L') {
                if(!visit[nR][nC]) {
                    visit[nR][nC]=true;
                    q.push({nR,nC,curCnt+1});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> map[i];
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]=='L') bfs(i,j);
        }
    }
    
    cout << res;

    return 0;
}