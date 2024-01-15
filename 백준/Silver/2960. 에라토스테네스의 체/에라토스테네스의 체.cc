#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num[1001]={0,};
    int n, k;
    int ans;
    int cnt=0;
    
    cin >> n >> k;
    for(int i=2; i<=n; i++) {
        int j=i;
        while(j<=n) {
            if(num[j]==0) {
                num[j]=1;
                cnt++;
                if(cnt==k) {
                    ans=j;
                    break;
                }
            }
            j+=i;
        }
        if(cnt==k) {
            break;
        }
    }
    
    cout << ans;

    return 0;
}