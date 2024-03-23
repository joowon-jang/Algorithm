#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
char field[101][101];
int cnt = 0;
bool visit[100][100] = {false};

void DFS(int x, int y) {
    visit[x][y] = true;
    if(x>0 && !visit[x-1][y] && field[x][y] == field[x-1][y]) DFS(x-1,y);
    if(x<n-1 && !visit[x+1][y] && field[x][y] == field[x+1][y]) DFS(x+1,y);
    if(y>0 && !visit[x][y-1] && field[x][y] == field[x][y-1]) DFS(x,y-1);
    if(y<n-1 && !visit[x][y+1] && field[x][y] == field[x][y+1]) DFS(x,y+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> field[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visit[i][j]) {
                DFS(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    
    memset(visit, false, sizeof(visit));
    cnt = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(field[i][j] == 'G') field[i][j] = 'R';
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visit[i][j]) {
                DFS(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}