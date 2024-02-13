#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    char map[1001][1001];
    int n, m;
    int ans=0;

    cin >> m >> n;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i=0; i<m-1; i++) {
        int cntBottom=0;
        int cntTop=0;
        for(int j=0; j<n; j++) {
            if(map[i][j]=='X' && map[i+1][j]=='.') {
                cntBottom++;
                if(cntBottom==2) {
                    ans++;
                    cntBottom=0;
                }
            }
            else {
                cntBottom=0;
            }
            
            if(map[i][j]=='.' && map[i+1][j]=='X') {
                cntTop++;
                if(cntTop==2) {
                    ans++;
                    cntTop=0;
                }
            }
            else {
                cntTop=0;
            }
        }
    }
    
    for(int j=0; j<n-1; j++) {
        int cntLeft=0;
        int cntRight=0;
        for(int i=0; i<m; i++) {
            if(map[i][j]=='X' && map[i][j+1]=='.') {
                cntLeft++;
                if(cntLeft==2) {
                    ans++;
                    cntLeft=0;
                }
            }
            else {
                cntLeft=0;
            }
            
            if(map[i][j]=='.' && map[i][j+1]=='X') {
                cntRight++;
                if(cntRight==2) {
                    ans++;
                    cntRight=0;
                }
            }
            else {
                cntRight=0;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}