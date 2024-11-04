#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int, vector<int>, less<int>> max_pq;
map<int,int> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, k;
    char order;
    int tmp;
    
    cin >> t;
    for(int i=0; i<t; i++) {
        while(!min_pq.empty()) min_pq.pop();
        while(!max_pq.empty()) max_pq.pop();
        cnt.clear();
        
        cin >> k;
        for(int j=0; j<k; j++) {
            cin >> order >> tmp;
            if(order == 'I') {
                min_pq.push(tmp);
                max_pq.push(tmp);
                cnt[tmp]++;
            }
            if(order == 'D') {
                if(tmp == 1) {
                    if(!max_pq.empty()) {
                        cnt[max_pq.top()]--;
                        max_pq.pop();
                    }
                }
                if(tmp == -1) {
                    if(!min_pq.empty()) {
                        cnt[min_pq.top()]--;
                        min_pq.pop();
                    }
                }
                while(!min_pq.empty() && cnt[min_pq.top()] == 0) min_pq.pop();
                while(!max_pq.empty() && cnt[max_pq.top()] == 0) max_pq.pop();
            }
        }
        if(max_pq.empty() || min_pq.empty()) cout << "EMPTY\n";
        else cout << max_pq.top() << " " << min_pq.top() << "\n";
    }

    return 0;
}