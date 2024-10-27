#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool flag = true;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            flag = true;
            answer += s[i];
            continue;
        }
        if(flag) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                answer += s[i] + ('A' - 'a');
            }
            else answer += s[i];
            flag = false;
        }
        else {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                answer += s[i] - ('A' - 'a');
            }
            else answer += s[i];
        }
    }
    
    return answer;
}