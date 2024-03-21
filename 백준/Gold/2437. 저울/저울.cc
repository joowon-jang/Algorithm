#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int ans=0;
    int sum = 1;
    vector<int> v;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int w;
        cin >> w;
        v.push_back(w);
    }
    
    sort(v.begin(), v.end());
    
    if(v[0] != 1) ans = 1;
    else {
        for(int i=1; i<n; i++) {
            if(sum + 1 < v[i]) {
                ans = sum + 1;
                break;
            }
            sum += v[i];
            ans = sum + 1;
        }
    }
    
    cout << ans;

    return 0;
}