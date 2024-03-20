#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,k;
    int cnt=0;
    string str;
    stack<char> stack;
    string ans;
    
    cin >> n >> k;
    cin >> str;

    stack.push(str[0]);
    for(int i=1; i<str.length(); i++) {
        while(cnt<k && !stack.empty() && str[i] > stack.top()) {
            stack.pop();
            cnt++;
        }
        stack.push(str[i]);
    }
    
    while(cnt<k) {
        stack.pop();
        cnt++;
    }
    
    while(!stack.empty()) {
        ans.push_back(stack.top());
        stack.pop();
    }
    
    reverse(ans.begin(),ans.end());
    
    cout << ans;

    return 0;
}
