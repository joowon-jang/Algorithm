#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int m,n;
int box[1000][1000] = {-1,};
queue<pair<int,int>> q;
int result = 0;

void bfs() {
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(r>0 && box[r-1][c]==0) {
            box[r-1][c] = box[r][c]+1;
            q.push({r-1, c});
        }
        if(r<n-1 && box[r+1][c]==0) {
            box[r+1][c] = box[r][c]+1;
            q.push({r+1, c});
        }
        if(c>0 && box[r][c-1]==0) {
            box[r][c-1] = box[r][c]+1;
            q.push({r, c-1});
        }
        if(c<m-1 && box[r][c+1]==0) {
            box[r][c+1] = box[r][c]+1;
            q.push({r, c+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) {
                q.push({i,j});
            }
        }
    }
    bfs();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(box[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            if(box[i][j] > result) {
                result = box[i][j];
            }
        }
    }
    
    cout << result - 1;

    return 0;
}