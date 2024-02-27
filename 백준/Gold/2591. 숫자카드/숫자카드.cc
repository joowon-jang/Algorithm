#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string str;
    int dp[41];
    vector<int> v(1,0);
    
    cin >> str;
    
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='0') {
            int tmp = v[v.size()-1];
            v.pop_back();
            v.push_back(100);
            v.push_back(tmp*10);
        }
        else {
            v.push_back(str[i]-'0');
        }
    }
    
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<v.size(); i++) {
        if(v[i] == 100) {
            dp[i] = dp[i-1];
        }
        else if(v[i-1]*10 + v[i] <= 34) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        else {
            dp[i] = dp[i-1];
        }
    }
    
    cout << dp[v.size()-1];

    return 0;
}