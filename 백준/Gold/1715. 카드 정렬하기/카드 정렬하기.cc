#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans=0;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    
    while(pq.size() > 1) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        int sum = n1 + n2;
        ans+=sum;
        pq.push(sum);
    }
    
    cout << ans;

    return 0;
}