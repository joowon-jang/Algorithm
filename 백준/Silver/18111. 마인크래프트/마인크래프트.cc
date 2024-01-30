#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, b;
    int lt = 0x7f7f7f7f;
    int ground[500][500];
    int heightest = 0;
    
    cin >> n >> m >> b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ground[i][j];
        }
    }
    
    for(int h=0; h<=256; h++) {
        int build=0;
        int crash=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int height = ground[i][j] - h;
                if(height > 0) {
                    crash+=height;
                }
                else if(height < 0) {
                    build-=height;
                }
            }
        }
        
        if(crash + b >= build) {
            int t = crash*2 + build;
            if(lt >= t) {
                lt = t;
                heightest = h;
            }
        }
    }
    
    cout << lt << " " << heightest;

    return 0;
}