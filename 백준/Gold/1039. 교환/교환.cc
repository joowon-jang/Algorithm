#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string n;
    int k;
    int ans=0;
    int cnt=0;
    queue<string> q;
    
    cin >> n >> k;
    q.push(n);
    
    int len = n.size();
    
    while(cnt < k) {
        int qSize = q.size();
        map<string,int> visit;
        while(qSize--) {
            string curr = q.front();
            q.pop();
            
            for(int i=0; i<len-1; i++) {
                for(int j=i+1; j<len; j++) {
                    if(i==0 && curr[j] == '0') continue;
                    string newNum = curr;
                    swap(newNum[i], newNum[j]);
                    
                    if(visit.find(newNum) != visit.end()) continue;
                    if(cnt==k-1) ans = max(ans, stoi(newNum));
                    q.push(newNum);
                    visit.insert({newNum,1});
                }
            }
        }
        cnt++;
    }
    
    
    if(ans==0) cout << -1;
    else cout << ans;

    return 0;
}
