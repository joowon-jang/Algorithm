#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<int>());
    
    int from = 0;
    int to = people.size() - 1;
    
    while(from <= to) {
        if(people[from] + people[to] <= limit) {
            answer++;
            from++;
            to--;
        }
        else {
            answer++;
            from++;
        }
    }
    
    return answer;
}