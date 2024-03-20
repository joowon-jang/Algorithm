#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string str1,str2;
    int ans=0;
    
    cin >> str1;
    cin >> str2;
    
    while(str2.length() >= str1.length() && str1 != str2) {
        if(str2.back() == 'A') {
            str2.pop_back();
        }
        else {
            str2.pop_back();
            reverse(str2.begin(),str2.end());
        }
        if(str1==str2) ans = 1;
    }
    
    cout << ans;

    return 0;
}
