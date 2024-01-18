#include <iostream>
#include <queue>

using namespace std;

struct current {
    int x;
    int cnt;
};

int n, k;
bool visit[100001]={0};

void bfs(int x) {
    queue<current> q;
    
    visit[x]=true;
    q.push({x, 0});
    
    while(!q.empty()){
        int fX=q.front().x;
        int fcnt=q.front().cnt;
        q.pop();
        
        if(fX==k) {
            cout << fcnt << "\n";
            return;
        }
        
        if(fX+1 >= 0 && fX+1 < 100001){
            if(!visit[fX+1]){
                visit[fX+1] = true;
                q.push({fX+1, fcnt+1});
            }
        }
        if(fX-1 >= 0 && fX-1 < 100001){
            if(!visit[fX-1]){
                visit[fX-1] = true;
                q.push({fX-1, fcnt+1});
            }
        }
        if(2*fX >= 0 && 2*fX < 100001){
            if(!visit[2*fX]){
                visit[2*fX] = true;
                q.push({2*fX, fcnt+1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    bfs(n);

    return 0;
}