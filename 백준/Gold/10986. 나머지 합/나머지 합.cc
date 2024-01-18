#include <iostream>

using namespace std;

long long combi(long long a) {
    return a*(a-1)/2;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    int tmp;
    long long csum=0;
    long long mod[1000]={0,};
    long long ans=0;
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        csum+=tmp;
        csum%=m;
        mod[csum]++;
    }
    for(int i=0; i<m; i++) {
        ans+=combi(mod[i]);
    }
    ans+=mod[0];
    
    cout << ans;

    return 0;
}