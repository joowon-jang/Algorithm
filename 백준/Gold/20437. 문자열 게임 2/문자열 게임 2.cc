#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution(string& str, int k) {
    vector<vector<int>> v(26,vector<int>(0,0));
    int minlen=10001;
    int maxlen=1;
    for(int i=0; i<str.length(); i++) {
        v[str[i]-'a'].push_back(i);
    }
    for(int i=0; i<26; i++) {
        if(v[i].size()>=k) {
            for(int j=0; j<=v[i].size()-k; j++) {
                minlen=min(minlen,v[i][j+k-1]-v[i][j]+1);
                maxlen=max(maxlen,v[i][j+k-1]-v[i][j]+1);
            }
        }
    }
    if(minlen!=10001) cout << minlen << " " << maxlen;
    else cout << -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        string str;
        int k;
        
        cin >> str;
        cin >> k;
        
        solution(str,k);
        cout << "\n";
    }
    
    return 0;
}