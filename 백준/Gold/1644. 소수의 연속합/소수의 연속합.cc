#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int l=0, r=0;
    int sum=0;
    int ans=0;
    vector<int> primes;
    
    cin >> n;
    vector<bool> visit(n+1,0);
    
    for(int i=2; i<=n; i++) {
        if(visit[i]) continue;
        else {
            primes.push_back(i);
            for(int j=i; j<=n; j+=i) {
                visit[j]=true;
            }
        }
    }
    
    while(n!=1 && sum<n) {
        sum+=primes[r];
        r++;
    }
    
    int vlength=primes.size();
    
    while(l<r && r<=vlength) {
        if(sum==n) {
            ans++;
        }
        if(sum>=n) {
            sum-=primes[l];
            l++;
        }
        else {
            if(r>=vlength) break;
            sum+=primes[r];
            r++;
        }
    }
    
    cout << ans;

    return 0;
}