#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct horse {
    int x;
    int y;
    int cnt;
};

bool visit[300][300];

bool isIn(int n, int x, int y) {
    if(x<0 || x>=n || y<0 || y>=n) return false;
    else return true;
}

void bfs(int n, int cx, int cy, int tox, int toy) {
    int dir[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
    queue<horse> q;
    
    visit[cx][cy]=true;
    q.push({cx,cy,0});
    
    while(!q.empty()){
        int fx=q.front().x;
        int fy=q.front().y;
        int fcnt=q.front().cnt;
        q.pop();
        if(fx==tox && fy==toy) {
            cout << fcnt << "\n";
            return;
        }
        for(int i=0; i<8; i++) {
            int nx = fx + dir[i][0];
            int ny = fy + dir[i][1];
            if(isIn(n,nx,ny)) {
                if(!visit[nx][ny]) {
                    visit[nx][ny]=true;
                    q.push({nx,ny,fcnt+1});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    
    cin >> t;
    
    while(t--) {
        int n, cx, cy, tox, toy;
        
        cin >> n;
        cin >> cx >> cy;
        cin >> tox >> toy;
        
        memset(visit,false,sizeof(visit));
        bfs(n, cx, cy, tox, toy);
    }

    return 0;
}