#include <iostream>
#include <algorithm>

using namespace std;

struct X{
    char ch;
    int num=1000000;
};

int main()
{
    int n;
    char str[1001];
    X dp[1001];
    
    int dist=0;
    
    cin >> n;
    str[0]='J';
    for(int i=1; i<=n; i++) {
        cin >> str[i];
    }
    
    dp[0].ch='J';
    dp[0].num=1000000;
    dp[1].ch='B';
    dp[1].num=0;
    
    for(int i=2; i<=n; i++) {
        if(str[i]=='B') {
            dp[i].ch='B';
            for(int j=0; j<i; j++) {
                if(dp[j].ch=='J' && dp[j].num!=1000000) {
                    dp[i].num=min(dp[j].num+(i-j)*(i-j),dp[i].num);
                }
            }
        }
        if(str[i]=='O') {
            dp[i].ch='O';
            for(int j=0; j<i; j++) {
                if(dp[j].ch=='B' && dp[j].num!=1000000) {
                    dp[i].num=min(dp[j].num+(i-j)*(i-j),dp[i].num);
                }
            }
        }
        if(str[i]=='J') {
            dp[i].ch='J';
            for(int j=0; j<i; j++) {
                if(dp[j].ch=='O' && dp[j].num!=1000000) {
                    dp[i].num=min(dp[j].num+(i-j)*(i-j),dp[i].num);
                }
            }
        }
    }
    
    if(dp[n].num==1000000) cout << -1;
    else cout << dp[n].num;
    
    return 0;
}