#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    vector<string> v;
    int ans=0;
    int alphabet[26] = {0,};
    
    cin >> n;
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    for(int i=0; i<v.size(); i++) {
        int cal = 1;
        for(int j=1; j<=v[i].size(); j++) {
            alphabet[v[i][v[i].size() - j] - 'A'] += cal;
            cal *= 10;
        }
    }
    
    sort(alphabet, alphabet + 26, greater<int>());
    
    for(int i=0; i<10; i++) {
        ans += alphabet[i] * (9-i);
    }
    
    cout << ans;
    
    return 0;
}