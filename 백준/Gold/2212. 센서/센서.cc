#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int ans=0;
    int n, k;
    cin >> n;
    cin >> k;
    
    vector<int> v;
    vector<int> dist;
    
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<n-1; i++) {
        dist.push_back(v[i+1] - v[i]);
    }
    
    sort(dist.begin(), dist.end());
    for(int i=0; i<n-k; i++) {
        ans+=dist[i];
    }
    
    cout << ans;

    return 0;
}
