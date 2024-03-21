#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b) {
    if(a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int ans = 0;
    int day = 0;
    vector<pair<int,int>> v;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int d,w;
        cin >> d >> w;
        v.push_back({d,w});
        day = max(day, d);
    }
    
    sort(v.begin(), v.end(), compare);
    
    while(day>0) {
        for(int i=0; i<n; i++) {
            if(v[i].first >= day) {
                ans += v[i].second;
                v[i].first = -1;
                break;
            }
        }
        day--;
    }
    
    cout << ans;

    return 0;
}