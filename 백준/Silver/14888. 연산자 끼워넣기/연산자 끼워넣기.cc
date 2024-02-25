#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[11]={0,};
int calc[4]={0,};
int maxN=-0x80000000;
int minN=0x7fffffff;

void dfs(int result, int idx) {
    if(idx==n-1) {
        maxN=max(maxN, result);
        minN=min(minN, result);
    }
    else {
        for(int i=0; i<4; i++) {
            if(calc[i]>0) {
                calc[i]--;
                if(i==0) dfs(result+num[idx+1], idx+1);
                if(i==1) dfs(result-num[idx+1], idx+1);
                if(i==2) dfs(result*num[idx+1], idx+1);
                if(i==3) dfs(result/num[idx+1], idx+1);
                calc[i]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    for(int i=0; i<4; i++) {
        cin >> calc[i];
    }
    
    dfs(num[0], 0);
    
    cout << maxN << "\n" << minN;

    return 0;
}