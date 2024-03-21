#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    long long ans = 0;
    vector<pair<int,int>> v;
    vector<int> bag;
    priority_queue<int, vector<int>, less<int>> pq;
    
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0; i<k; i++) {
        int w;
        cin >> w;
        bag.push_back(w);
    }
    
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    
    int idx = 0;
    for(int i=0; i<k; i++) {
        while(idx < n && bag[i] >= v[idx].first) {
            pq.push(v[idx].second);
            idx++;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    
    cout << ans;

    return 0;
}