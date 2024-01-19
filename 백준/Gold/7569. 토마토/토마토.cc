#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct loc {
    int z, y, x;
};

int m, n, h;
int box[100][100][100];
int dir[6][3] = {{-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1}};

int days = 0;

queue<loc> q;

bool isInside(int z, int y, int x) {
    if(z<0 || z>=h || y<0 || y>=n || x<0 || x>=m) return false;
    return true;
}

void bfs() {
    while(!q.empty()) {
        int z = q.front().z;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        for(int i=0; i<6; i++) {
            int nZ = z + dir[i][0];
            int nY = y + dir[i][1];
            int nX = x + dir[i][2];
            if(!isInside(nZ,nY,nX)) continue;
            if(box[nZ][nY][nX]) continue;
            q.push({nZ,nY,nX});
            box[nZ][nY][nX] = box[z][y][x] + 1;
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n >> h;
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    q.push({i,j,k});
                }
            }
        }
    }
    
    bfs();
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(box[i][j][k] == 0) {
                    cout << "-1";
                    return 0;
                }
                days = max(days, box[i][j][k]);
            }
        }
    }
    cout << days-1;

    return 0;
}