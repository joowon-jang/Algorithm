#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int field[100][100];
bool visit[100][100];
int cnt=0;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isIn(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=n) return false;
    else return true;
}

void dfs(int r, int c, int h) {
    visit[r][c]=true;
    
    for(int i=0; i<4; i++) {
        int nR=r+dir[i][0];
        int nC=c+dir[i][1];
        if(isIn(nR,nC) && field[nR][nC] >= h && !visit[nR][nC]) {
            visit[nR][nC]=true;
            dfs(nR, nC, h);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int maxNum=0;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> field[i][j];
        }
    }
    
    for(int i=1; i<=100; i++) {
        memset(visit, false, sizeof(visit));
        cnt=0;
        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) {
                if (field[r][c] >= i && !visit[r][c]) {
                    dfs(r, c, i);
                    cnt++;
                }
            }
        }
        maxNum=max(maxNum,cnt);
        if(cnt==0) break;
    }
    
    cout << maxNum;
    
    return 0;
}