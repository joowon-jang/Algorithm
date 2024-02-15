#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l, c;
char arr[16];
vector<char> pw;

bool check() {
    int vowel = 0;
    for(int i=0; i<l; i++)
    {
        if(pw[i]=='a' || pw[i]=='e' || pw[i]=='i' || pw[i]=='o' || pw[i]=='u')
           vowel++;
    }
    if(vowel>=1 && l-vowel>=2) {
        return true;
    }
    else {
        return false;
    }
}

void dfs(int n) {
    if(pw.size()==l) {
        if(check()){
            for(int i = 0 ; i<l ; i++)
            {
                cout << pw[i];
            }
            cout << '\n';
        }
    }
    else {
        for(int i=n; i<c; i++) {
            pw.push_back(arr[i]);
            dfs(i+1);
            pw.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> l >> c;
    
    for(int i=0; i<c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+c);
    
    dfs(0);

    return 0;
}