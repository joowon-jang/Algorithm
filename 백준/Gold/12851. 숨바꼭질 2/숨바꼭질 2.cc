#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool isIn(int x) {
    if(x<0 || x>100000) return false;
    else return true;
}

void bfs(int n, int k) {
    queue<pair<int,int>> q;
    int visit[100000];
    int cnt=0;
    int ans=200000;
    
    for(int i=0; i<=100000; i++) {
        visit[i]=200000;
    }
    
    visit[n]=0;
    q.push({n,0});
    
    while(!q.empty()) {
        int curr = q.front().first;
        int t = q.front().second;
        q.pop();
        
        if(curr==k && t<=ans) {
            ans=t;
            cnt++;
        }
        
        if(isIn(curr-1) && t+1<=visit[curr-1]) {
            visit[curr-1]=t+1;
            if(t<=ans) q.push({curr-1, t+1});
        }
        if(isIn(curr+1) && t+1<=visit[curr+1]) {
            visit[curr+1]=t+1;
            if(t<=ans) q.push({curr+1, t+1});
        }
        if(isIn(curr*2) && t+1<=visit[curr*2]) {
            visit[curr*2]=t+1;
            if(t<=ans) q.push({curr*2, t+1});
        }
    }
    
    cout << ans << "\n" << cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    
    cin >> n >> k;
    
    bfs(n, k);

    return 0;
}