#include <iostream>
#include <string>

using namespace std;

int n;

void dfs(string str, int last, int num, int res) {
    int curr = res+last;
    if(num==n+1) {
        if(curr==0) cout << str << "\n";
    }
    else {
        if(last<0) dfs(str+" "+to_string(num), last*10 - num, num+1, res);
        else dfs(str+" "+to_string(num), last*10 + num, num+1, res);
        dfs(str+"+"+to_string(num), num, num+1, curr);
        dfs(str+"-"+to_string(num), -num, num+1, curr);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        dfs("1",1,2,0);
        cout << "\n";
    }

    return 0;
}