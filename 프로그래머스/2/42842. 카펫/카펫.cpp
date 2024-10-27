#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    brown -= 4;
    for(int i=1; i<brown/2; i++) {
        if((brown/2 - i) * i == yellow) {
            answer.push_back(brown/2 - i + 2);
            answer.push_back(i + 2);
            break;
        }
    }
    
    return answer;
}