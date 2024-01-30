#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m ,b;
    int map[500][500];
    int mint=0x7f7f7f7f;
    int highest=0;
    
    cin >> n >> m >> b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int h=0; h<=256; h++) {
        int crash=0;
        int build=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int height=map[i][j]-h;
                if(height>=0) {
                    crash+=height;
                }
                else {
                    build-=height;
                }
            }
        }
        
        if(crash+b>=build) {
            int t=crash*2+build;
            if(mint>=t) {
                mint=t;
                highest=h;
            }
        }
    }
    
    cout << mint << " " << highest;

    return 0;
}