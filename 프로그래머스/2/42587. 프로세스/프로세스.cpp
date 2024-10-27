#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    
    for(int i=0; i<priorities.size(); i++) {
        q.push({i,priorities[i]});
    }
    
    while(!q.empty()) {
        int fi = q.front().first;
        int fp = q.front().second;
        q.pop();
        
        for(int i=0; i<priorities.size(); i++) {
            if(priorities[i] > fp) {
                q.push({fi,fp});
                break;
            }
            if(i == priorities.size() - 1) {
                priorities[fi] = -1;
                answer++;
                if(location == fi) return answer;
            }
        }
    }
    
    return answer;
}