#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q, q2;
    
    for(int i=0; i<progresses.size(); i++) {
        q.push(progresses[i]);
        q2.push(speeds[i]);
    }
    
    int t=1;
    while(!q.empty()) {
        int cnt=0;
        while(!q.empty() && q.front() + q2.front() * t >= 100) {
            q.pop();
            q2.pop();
            cnt++;
        }
        if(cnt > 0) {
            answer.push_back(cnt);
            cnt = 0;
        }
        t++;
    }
    
    return answer;
}