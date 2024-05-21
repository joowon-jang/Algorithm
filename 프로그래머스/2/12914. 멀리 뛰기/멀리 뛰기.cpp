#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> dp;
    
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    
    for(int i=3; i<=n; i++) {
        dp.push_back((dp[i-2] + dp[i-1]) % 1234567);
    }
    
    answer = dp[n];
    
    return answer;
}