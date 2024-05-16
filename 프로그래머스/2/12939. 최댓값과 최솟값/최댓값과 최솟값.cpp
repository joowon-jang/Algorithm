#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int largest = -0x7f7f7f7f;
    int smallest = 0x7f7f7f7f;
    string tmp = "";
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            largest = max(largest, stoi(tmp));
            smallest = min(smallest, stoi(tmp));
            tmp = "";
        }
        else if(i == s.size() - 1) {
            tmp += s[i];
            largest = max(largest, stoi(tmp));
            smallest = min(smallest, stoi(tmp));
            tmp = "";
        }
        else {
            tmp += s[i];
        }
        
    }
    
    answer += to_string(smallest);
    answer += " ";
    answer += to_string(largest);
    
    return answer;
}