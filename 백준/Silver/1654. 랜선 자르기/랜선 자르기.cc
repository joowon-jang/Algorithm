#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k, n;
    int i;
    unsigned int left, right, mid;
    int maxn = 0;
    int len[10001];
    int cnt = 0;
    unsigned int ans = 0;
    
    cin >> k >> n;
    
    for(i=0; i<k; i++) {
        cin >> len[i];
        maxn = max(maxn, len[i]);
    }
    left = 1;
    right = maxn;
    
    while(left <= right) {
        mid = (left+right)/2;
        cnt = 0;
        for(i=0; i<k; i++) {
            cnt += len[i]/mid;
        }
        if(cnt >= n) {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}