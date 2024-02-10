#include <iostream>
#include <queue>

using namespace std;

int n, k, l;
int map[101][101]={0,};
int dir[2][2]={{0,1},{0,1}};
int head[2]={1,1};
int tail[2]={1,1};
int t=0;
queue<pair<char,pair<int,int>>> q;

bool isIn(int row, int col) {
    if(row<1 || col<1 || row>n || col>n) return false;
    else return true;
}

void curve_head(char c) {
    if(c=='L') {
        if(dir[0][0]==0) {
            dir[0][0]=-dir[0][1];
            dir[0][1]=0;
        }
        else {
            dir[0][1]=dir[0][0];
            dir[0][0]=0;
        }
    }
    if(c=='D') {
        if(dir[0][0]==0) {
            dir[0][0]=dir[0][1];
            dir[0][1]=0;
        }
        else {
            dir[0][1]=-dir[0][0];
            dir[0][0]=0;
        }
    }
}

void curve_tail(char c) {
    if(c=='L') {
        if(dir[1][0]==0) {
            dir[1][0]=-dir[1][1];
            dir[1][1]=0;
        }
        else {
            dir[1][1]=dir[1][0];
            dir[1][0]=0;
        }
    }
    if(c=='D') {
        if(dir[1][0]==0) {
            dir[1][0]=dir[1][1];
            dir[1][1]=0;
        }
        else {
            dir[1][1]=-dir[1][0];
            dir[1][0]=0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    map[1][1]=1;
    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++) {
        int row, col;
        cin >> row >> col;
        map[row][col]=-1;
    }
    cin >> l;
    for(int i=0; i<l; i++) {
        int x;
        char c;
        cin >> x >> c;
        
        while(t<x) {
            t++;
            head[0]+=dir[0][0];
            head[1]+=dir[0][1];
            
            if(!isIn(head[0],head[1]) || map[head[0]][head[1]]==1) {
                cout << t;
                return 0;
            }
            if(map[head[0]][head[1]]!=-1) {
                map[tail[0]][tail[1]]=0;
                if(!q.empty()) {
                    if(q.front().second.first==tail[0] && q.front().second.second==tail[1]) {
                        curve_tail(q.front().first);
                        q.pop();
                    }
                }
                tail[0]+=dir[1][0];
                tail[1]+=dir[1][1];
            }
            map[head[0]][head[1]]=1;
        }
        curve_head(c);
        q.push({c,{head[0],head[1]}});
    }
    
    while(1) {
        t++;
        head[0]+=dir[0][0];
        head[1]+=dir[0][1];
        if(!isIn(head[0],head[1]) || map[head[0]][head[1]]==1) {
            cout << t;
            break;
        }
        if(map[head[0]][head[1]]!=-1) {
            map[tail[0]][tail[1]]=0;
            if(!q.empty()) {
                if(q.front().second.first==tail[0] && q.front().second.second==tail[1]) {
                    curve_tail(q.front().first);
                    q.pop();
                }
            }
            tail[0]+=dir[1][0];
            tail[1]+=dir[1][1];
        }
        map[head[0]][head[1]]=1;
    }

    return 0;
}