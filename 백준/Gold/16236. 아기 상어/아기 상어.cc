#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int by, bx;
int bulk = 2;
int eatcnt = 0;
int field[20][20] = {-1};
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int t = 0;

bool eat = false;
bool stop = false;

bool visit[20][20] = {0};

bool isInside(int r, int c) {
    if(r>=n || r<0 || c>=n || c<0) return false;
    return true;
}

void bfs() {
    memset(visit,false,sizeof(visit));
    queue<pair<pair<int,int>,int>> q;
    q.push({{by,bx},0});
    visit[by][bx] = true;
    int temp = 0;
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(field[r][c] > 0 && field[r][c] < bulk && temp == cnt) {
            if((by > r) || (by == r && bx > c)){
                by = r;
                bx = c;
                continue;
            }
        }
        
        for(int i=0; i<4; i++) {
            int nR = r+dir[i][0];
            int nC = c+dir[i][1];
            if(!isInside(nR,nC)) continue;
            if(visit[nR][nC]) continue;
            if(field[nR][nC] <= bulk) {
                q.push({{nR,nC},cnt+1});
                visit[nR][nC] = true;
            }
            if(field[nR][nC] <= bulk) {
                if(field[nR][nC] > 0 && field[nR][nC] < bulk && !eat) {
                    eat = true;
                    bx = nC;
                    by = nR;
                    temp = cnt + 1;
                    t += temp;
                }
                else{
                    q.push({{nR, nC}, cnt + 1});
                    visit[nR][nC] = true;  
                }                      
            }
        }
    }
}

void solution() {
    while(!stop) {
        bfs();
        if(eat) {
            eat = false; 
            eatcnt += 1;
            field[by][bx] = 0;
            if(eatcnt == bulk){
                bulk++;
                eatcnt = 0;
            }
        }
        else stop = true;
    }
    cout << t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cin >> field[i][j];
            if(field[i][j] == 9) {
                by = i;
                bx = j;
                field[i][j] = 0;
            }
        }
    }
    solution();

    return 0;
}