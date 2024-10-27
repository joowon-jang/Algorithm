#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    
    for(int i=0; i<numbers.size(); i++) {
        strs.push_back(to_string(numbers[i]));
    }
    
    sort(strs.begin(),strs.end(),compare);
    
    for(int i=0; i<strs.size(); i++) {
        answer += strs[i];
    }
    
    if (answer[0] == '0') {
        answer = '0';
    }
    
    return answer;
}