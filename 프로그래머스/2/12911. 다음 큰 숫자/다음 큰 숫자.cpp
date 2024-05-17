#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int nCnt = 0;
    int nextCnt = 0;
    int nextN = n + 1;
    
    while(n >= 1) {
        if(n % 2 == 1) nCnt++;
        n /= 2;
    }
    
    while(nextCnt != nCnt) {
        int tmp = nextN;
        int cnt = 0;
        while(tmp >= 1) {
            if(tmp % 2 == 1) cnt++;
            tmp /= 2;
        }
        nextCnt = cnt;
        nextN++;
    }
    
    answer = nextN - 1;
    
    return answer;
}