#include <iostream>
#include <algorithm>

using namespace std;

int n;
int table[20][20];
bool visit[20]={0};
int gap=0x7fffffff;

void dfs(int startsum, int current, int num) {
    if(current==(n/2)) {
        int linksum=0;
        for(int i=1; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(!visit[i] && !visit[j]) {
                    linksum+=table[i][j];
                    linksum+=table[j][i];
                }
            }
        }
        if(startsum > linksum) gap=min(gap, startsum-linksum);
        else gap=min(gap, linksum-startsum);
    }
    else {
        for(int i=num; i<n; i++) {
            if(!visit[i]) {
                int sum = startsum;
                for(int j=0; j<i; j++) {
                    if(visit[j]) {
                        sum+=table[i][j];
                        sum+=table[j][i];
                    }
                }
                visit[i]=true;
                dfs(sum,current+1,i+1);
                visit[i]=false;
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
        for(int j=0; j<n; j++) {
            cin >> table[i][j];
        }
    }
    
    visit[0]=true;
    dfs(0, 1, 1);
    
    cout << gap;
    
    return 0;
}