#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;
int ans = 0;

void solution(int x, int y, int len) {
    if(y == r && x == c) {
        cout << ans;
        return;
    }
    else if(r >= y && r < y + len && c >= x && c < x + len){
        solution(x, y, len/2);
        solution(x + len/2, y, len/2);
        solution(x, y + len/2, len/2);
        solution(x + len/2, y+ len/2, len/2);
    }
    else {
        ans += len*len;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> r >> c;
    
    int len = pow(2,n);
    solution(0, 0, len);
    
    return 0;
}