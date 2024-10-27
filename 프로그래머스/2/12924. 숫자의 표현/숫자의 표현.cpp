#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int left = 1;
    int right = 2;
    
    while(right <= n) {
        int sum = 0;
        for(int i=left; i<right; i++) {
            sum += i;
        }
        if(sum == n) {
            answer ++;
        }
        if(sum >= n) left++;
        else right++;
    }
    
    return answer+1;
}