#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    int total = 0;
    for(int i=0; i<number.size(); i++) {
        total += number[i];
    }
    
    int n = discount.size() - total;
    for(int i=0; i <= n; i++) {
        vector<int> newNumber = number;
        for(int j=i; j<i+total; j++) {
            bool flag = false;
            for(int k=0; k<want.size(); k++) {
                if(want[k] == discount[j]) {
                    newNumber[k]--;
                    break;
                }
                if(k == want.size() - 1) flag = true;
            }
            for(int k=0; k<want.size(); k++) {
                if(newNumber[k] < 0) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            if(j == i+total - 1) {
                answer++;
            }
        }
    }
    
    return answer;
}