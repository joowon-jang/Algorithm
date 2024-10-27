#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for(int i=0; i<s.size(); i++) {
        if(st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
    }
    
    answer = st.empty();

    return answer;
}