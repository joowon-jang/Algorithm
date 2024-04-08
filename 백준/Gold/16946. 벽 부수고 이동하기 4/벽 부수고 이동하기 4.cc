#include <iostream>
#include <queue>

using namespace std;

int n, m;
char board[1000][1000];
int ans[1000][1000];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visited[1000][1000];

bool isIn(int r, int c) {
    return (r>=0 && r<n && c>=0 && c<m);
}

int bfs1(queue<pair<int,int>>& loc, int r, int c) {
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;

    while(!q.empty()) {
        int cR = q.front().first;
        int cC = q.front().second;
        q.pop();

        if(board[cR][cC] == '1') {
            loc.push({cR,cC});
            continue;
        }

        cnt++;

        for(int i=0; i<4; i++) {
            int nR = cR + dir[i][0];
            int nC = cC + dir[i][1];

            if(!isIn(nR,nC)) continue;
            if(visited[nR][nC]) continue;
            visited[nR][nC] = true;
            q.push({nR,nC});
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == '1') ans[i][j] = 1;
            else ans[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int cnt;
            if(board[i][j] == '0' && !visited[i][j]) {
                queue<pair<int,int>> loc;
                cnt = bfs1(loc, i,j);
                
                while(!loc.empty()) {
                    int cR = loc.front().first;
                    int cC = loc.front().second;
                    ans[cR][cC] += cnt;
                    visited[cR][cC] = false;
                    loc.pop();
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ans[i][j] % 10;
        }
        cout << "\n";
    }

    return 0;
}