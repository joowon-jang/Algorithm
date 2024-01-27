#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visit[200001]={0};
int ans=0;

void bfs() {
    queue<pair<int,int>> q;
    q.push({n,0});
    visit[n]=true;
    
    while(!q.empty()) {
        int loc=q.front().first;
        int t=q.front().second;
        q.pop();
        
        if(loc==k) {
            ans=t;
            return;
        }
        if(loc*2<=100000 && !visit[loc*2]) {
            visit[loc*2]=true;
            q.push({loc*2,t});
        }
        if(loc-1>=0 && !visit[loc-1]) {
            visit[loc-1]=true;
            q.push({loc-1,t+1});
        }
        if(loc+1<=100000 && !visit[loc+1]) {
            visit[loc+1]=true;
            q.push({loc+1,t+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    
    bfs();
    
    cout << ans;

    return 0;
}