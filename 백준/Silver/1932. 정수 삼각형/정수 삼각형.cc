#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int tri[500][500];
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin >> tri[i][j];
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(j==0) {
                tri[i][j] += tri[i-1][j];
            }
            else if(j==i) {
                tri[i][j] += tri[i-1][j-1];
            }
            else {
                tri[i][j] += max(tri[i-1][j], tri[i-1][j-1]);
            }
        }
    }
    sort(tri[n-1], tri[n-1] + n);
    cout << tri[n-1][n-1];
    

    return 0;
}
