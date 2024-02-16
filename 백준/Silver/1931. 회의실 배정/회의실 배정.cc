#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

int main()
{
    int n;
    vector<pair<int,int>> conf;
    int ans=0;
    int last=0;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int s, e;
        cin >> s >> e;
        conf.push_back({s,e});
    }
    sort(conf.begin(), conf.end(), compare);
    
    for(int i=0; i<n; i++) {
        if(conf[i].first >= last) {
            ans++;
            last=conf[i].second;
        }
    }
    
    cout << ans;

    return 0;
}