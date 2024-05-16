#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string binaryTransform(int n) {
    string newS = "";
    while(n > 1) {
        newS += (n%2) + '0';
        n /= 2;
    }
    newS += '1';
    
    return newS;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    while(s != "1") {
        string tmp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') tmp += s[i];
            else answer[1]++;
        }
        s = binaryTransform(tmp.size());
        answer[0]++;
    }
    return answer;
}