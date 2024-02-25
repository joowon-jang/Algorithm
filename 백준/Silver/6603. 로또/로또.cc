#include <iostream>
#include <algorithm>

using namespace std;

int k=1;
int arr[12];
int ans[12];

void dfs(int curr, int cnt) {
    if(cnt==6) {
        for(int i=0; i<6; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        for(int i=curr; i<k; i++) {
            ans[cnt]=arr[i];
            dfs(i+1,cnt+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(k!=0) {
        cin >> k;
        for(int i=0; i<k; i++) {
            cin >> arr[i];
        }
        dfs(0,0);
        cout << "\n";
    }
    
    
    return 0;
}