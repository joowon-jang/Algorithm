#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    vector<int> v;
    vector<int> ans;
    stack<int> st;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i=0; i<n; i++) {
        while(1) {
            if(st.empty()) {
                st.push(i);
                break;
            }
            int idx=st.top();
            if(v[i]>v[idx]) {
                v[idx]=v[i];
                st.pop();
            }
            else {
                st.push(i);
                break;
            }
        }
    }
    
    while(!st.empty()) {
        int idx = st.top();
        v[idx] = -1;
        st.pop();
    }
    
    for (int i=0; i<n; i++) {
        cout << v[i] << ' ';
    }
    
    return 0;
}