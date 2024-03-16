#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
bool visit[20][20]={0};
char field[20][20];
map<char,int> dic;

int ans = 0;

bool isIn(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=m) return false;
    else return true;
}

void dfs(int r, int c, int depth) {
    if(dic[field[r][c]] == 1) return;
    
    ans = max(ans, depth);
    
    dic[field[r][c]] = 1;
    for(int i=0; i<4; i++) {
        int nR = r + dir[i][0];
        int nC = c + dir[i][1];
        
        if(!isIn(nR,nC)) continue;
        if(visit[nR][nC]) continue;
        visit[nR][nC] = true;
        dfs(nR, nC, depth+1);
        visit[nR][nC] = false;
    }
    dic[field[r][c]] = 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=0; i<26; i++) {
        dic['a'+i] = 0;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> field[i][j];
        }
    }
    
    visit[0][0] = true;
    dfs(0,0,1);
    
    cout << ans;

    return 0;
}