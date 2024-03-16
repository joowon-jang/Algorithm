#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int ans = 0;
int field[15][15]={0};

bool isIn(int r, int c) {
    if(r<0 || r>=n || c<0 || c>=n) return false;
    else return true;
}

void checkMap(int r, int c, int mark) {
    for(int i=0; i<n; i++) {
        field[i][c] += mark;
        field[r][i] += mark;
        if(isIn(r+i,c+i)) field[r+i][c+i] += mark;
        if(isIn(r-i,c-i)) field[r-i][c-i] += mark;
        if(isIn(r+i,c-i)) field[r+i][c-i] += mark;
        if(isIn(r-i,c+i)) field[r-i][c+i] += mark;
    }
}

void dfs(int r, int c, int depth) {
    
    if(depth == n) {
        ans++;
        return;
    }
    
    checkMap(r, c, 1);
    for(int i=0; i<n; i++) {
        if(!field[r+1][i]) dfs(r+1,i,depth+1);
    }
    checkMap(r, c, -1);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        dfs(0, i, 1);
    }
    
    cout << ans;
    
    return 0;
}