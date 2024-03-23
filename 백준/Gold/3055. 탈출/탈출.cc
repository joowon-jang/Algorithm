#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CURR {
    int r;
    int c;
    int cnt;
};

int n, m;
pair<int,int> cave;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char map[50][50];
queue<CURR> q;

bool isIn(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=m) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'S') {
                q.push({i,j,0});
            }
            if(map[i][j] == 'D') {
                cave = {i,j};
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == '*') {
                q.push({i,j,-1});
            }
        }
    }
    
    while(!q.empty()) {
        
        int cR = q.front().r;
        int cC = q.front().c;
        int cCnt = q.front().cnt;
        q.pop();
        
        
        
        for(int i=0; i<4; i++) {
            int nR = cR + dir[i][0];
            int nC = cC + dir[i][1];
            
            if(!isIn(nR,nC) || map[nR][nC]=='X') continue;
            
            if(cCnt >= 0 && map[cR][cC] == 'S' && map[nR][nC] != 'S' && map[nR][nC] != '*') {
                if(map[nR][nC] == 'D') {
                    cout << cCnt+1;
                    return 0;
                }
                map[nR][nC] = 'S';
                q.push({nR,nC,cCnt+1});
            }
            if(cCnt < 0 && map[nR][nC] != 'D' && map[nR][nC] != '*') {
                map[nR][nC] = '*';
                q.push({nR,nC,-1});
            }
        }
    }
    
    cout << "KAKTUS";
    
    return 0;
}