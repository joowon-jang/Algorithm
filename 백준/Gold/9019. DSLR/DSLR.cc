#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

queue<pair<string, int>> q;
bool visit[10001];

int D(int a) {
    return a*2%10000;
}
int S(int a) {
    if(a == 0) return 9999;
    else return a-1;
}
int L(int a) {
    int tmp = a%1000;
    tmp *= 10;
    tmp += a/1000;
    
    return tmp;
}
int R(int a) {
    int tmp = a%10;
    tmp *= 1000;
    tmp += a/10;
    
    return tmp;
}

void DSLR(int now, string str, int b) {
    int d = D(now);
    if(!visit[d]) {
        q.push({str + "D", d});
        visit[d] = true;
    }
    int s = S(now);
    if(!visit[s]) {
        q.push({str + "S", s});
        visit[s] = true;
    }
    int l = L(now);
    if(!visit[l]) {
        q.push({str + "L", l});
        visit[l] = true;
    }
    int r = R(now);
    if(!visit[r]) {
        q.push({str + "R", r});
        visit[r] = true;
    }
}

void solution(int b) {
    memset(visit, false, sizeof(visit));
    while(!q.empty()) {
        int now = q.front().second;
        string str = q.front().first;
        q.pop();
        DSLR(now, str, b);
        if(now == b) {
            cout << str << "\n";
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int a, b;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        q.push({"", a});
        visit[a] = true;
        solution(b);
        while(!q.empty()) {
            q.pop();
        }
    }

    return 0;
}