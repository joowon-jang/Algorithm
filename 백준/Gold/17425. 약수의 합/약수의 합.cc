#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    long long sum[1000001]={0,};
    int t;
    long long ans=0;
    
    for(int i=1; i<1000001; i++) {
        for(int j=i; j<1000001; j+=i) {
            sum[j]+=i;
        }
    }
    for(int i=1; i<1000001; i++) {
        sum[i]+=sum[i-1];
    }
    
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        cout << sum[n] << "\n";
    }

    return 0;
}