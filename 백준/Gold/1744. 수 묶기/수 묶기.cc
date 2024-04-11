#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int ans = 0;
    vector<int> plus, minus;

    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp > 0) plus.push_back(tmp);
        else minus.push_back(tmp);
    }

    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(),minus.end());
    
    for(int i=0; i<plus.size(); i++) {
        if(i==plus.size()-1) ans += plus[i];
        else {
            if(plus[i+1] == 1) ans += plus[i] + plus[i+1];
            else ans += plus[i]*plus[i+1];
            i++;
        }
    }
    
    for(int i=0; i<minus.size(); i++) {
        if(i==minus.size()-1) ans += minus[i];
        else {
            ans += minus[i]*minus[i+1];
            i++;
        }
    }
    
    cout << ans;
    
    return 0;
}