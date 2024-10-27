#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LCM(int a, int b) {
    
    int i = max(a,b);
    while(i % a != 0 || i % b != 0) {
        i++;
    }
    
    return i;
}

int solution(vector<int> arr) {
    int answer = 0;
    
    for(int i=1; i<arr.size(); i++) {
        arr[i] = LCM(arr[i-1], arr[i]);
    }
    
    answer = arr[arr.size() - 1];
    
    return answer;
}