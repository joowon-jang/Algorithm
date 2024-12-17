#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int answer = -9999;
    int N, K;
    vector<int> v;
    cin >> N >> K;
    
    v.push_back(0);
    for(int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp + v.back());
    }
    
    for(int i = K; i <= N; i++) {
        answer = max(answer, v[i] - v[i - K]);
    }
    
    cout << answer;
    
    return 0;
}