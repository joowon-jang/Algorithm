#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct current {
    int r;
    int c;
    int cnt;
};

int n, m;

char field[100][100];
bool visit[100][100];

bool isIn(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=m) return false;
    else return true;
}

void bfs(int r, int c) {
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<current> q;
    
    visit[r][c]=true;
    q.push({r, c, 1});
    
    while(!q.empty()){
        int fR=q.front().r;
        int fC=q.front().c;
        int fcnt=q.front().cnt;
        q.pop();
        if(fR==n-1 && fC==m-1) {
            cout << fcnt << "\n";
            return;
        }
        for(int i=0; i<4; i++) {
            int nR = fR + dir[i][0];
            int nC = fC + dir[i][1];
            if(isIn(nR,nC) && field[nR][nC]!='0') {
                if(!visit[nR][nC]) {
                    visit[nR][nC]=true;
                    q.push({nR, nC, fcnt+1});
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
        for(int j=0; j<m; j++) {
            cin >> field[i][j];
        }
    }

    memset(visit,false,sizeof(visit));
    bfs(0, 0);

    return 0;
}