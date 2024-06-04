#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> myMap;
    
    for(int i=0; i<clothes.size(); i++) {
        myMap[clothes[i][1]]++;
    }
    
    map<string, int>::iterator iter;
    
    for (iter = myMap.begin(); iter != myMap.end(); iter++) {
        answer *= (iter->second + 1);
    }
    
    
    
    return answer - 1;
}