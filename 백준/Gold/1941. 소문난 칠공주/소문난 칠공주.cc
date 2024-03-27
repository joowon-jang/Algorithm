#include <iostream>
#include <queue>

using namespace std;

char map[5][5];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int ans=0;
int arr[7] ={0,};

bool isIn(int r, int c) {
    if(r<0 || r>=5 || c<0 || r>=5) return false;
    else return true;
}

void bfs(int r, int c) {
    queue<pair<int,int>> q;
    bool visit[5][5] = {false};
    
    visit[r][c] = true;
    q.push({r,c});
    
    while(!q.empty()) {
        int cR = q.front().first;
        int cC = q.front().second;
        q.pop();
        
        int flag=0;
        for(int i=0; i<7; i++) {
            if(cR == arr[i]/5 && cC == arr[i]%5) flag = 1;
        }
        if(!flag) continue;
        
        visit[cR][cC] = true;
        
        for(int i=0; i<4; i++) {
            int nR = cR + dir[i][0];
            int nC = cC + dir[i][1];
            
            if(!isIn(nR,nC) || visit[nR][nC]) continue;
            q.push({nR,nC});
        }
    }
    
    for(int i=0; i<7; i++) {
        if(!visit[arr[i]/5][arr[i]%5]) return;
    }
    ans++;
}

void combination(int depth, int next) {
    if(depth == 7){
        int sCnt=0;
        for(int i=0; i<7; i++) {
            if(map[arr[i]/5][arr[i]%5] == 'S') sCnt++;
        }
        if(sCnt>=4) bfs(arr[0]/5, arr[0]%5);
        return;
    }

    for(int i = next; i < 25; i++){
        arr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> map[i][j];
        }
    }
    
    combination(0,0);
    
    cout << ans;

    return 0;
}