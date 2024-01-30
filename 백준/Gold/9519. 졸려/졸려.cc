#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    string str;
    int cnt=0;
    
    cin >> t;
    cin >> str;
    
    string newstr=str;
    
    int len=str.length();
    
    while(t--) {
        string tmp;
        for(int i=0; i<len; i+=2) {
            tmp.push_back(newstr[i]);
        }
        for(int i=len-1; i>0; i-=2) {
            if(i%2==0) i--;
            tmp.push_back(newstr[i]);
        }
        
        newstr=tmp;
        cnt++;
        
        if(newstr==str) t%=cnt;
    }
    
    cout << newstr;
    
    return 0;
}