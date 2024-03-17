#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    
    while(t--) {
        int x, y;
        cin >> x >> y;
        
        int k=1;
        int ans=0;
        
        while(y>x) {
            x+=k;
            ans++;
            if(y>x) {
                y-=k;
                ans++;
            }
            k++;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
