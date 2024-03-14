#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int table[4][6][3];
int res[6][3]={0,};
vector<pair<int,int>> v;

void dfs(int k, int depth) {
    if(depth==15) {
        for(int i=0; i<6; i++) {
            for(int j=0; j<3; j++) {
                if(table[k][i][j] != res[i][j]) return;
            }
        }
        ans = 1;
        return;
    }
    
    int a=v[depth].first;
    int b=v[depth].second;
    
    res[a][0]++;
    res[b][2]++;
    dfs(k, depth+1);
    res[a][0]--;
    res[b][2]--;
    
    res[a][1]++;
    res[b][1]++;
    dfs(k, depth+1);
    res[a][1]--;
    res[b][1]--;
    
    res[a][2]++;
    res[b][0]++;
    dfs(k, depth+1);
    res[a][2]--;
    res[b][0]--;

    
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int k=0; k<4; k++) {
        for(int i=0; i<6; i++) {
            for(int j=0; j<3; j++) {
                cin >> table[k][i][j];
            }
        }
    }
    
    for(int i=0; i<6; i++) {
        for(int j=i+1; j<6; j++) {
            v.push_back({i,j});
        }
    }
    
    int t=4;
    while(t--) {
        ans = 0;
        dfs(3-t,0);
        cout << ans << " ";
    }

    return 0;
}
