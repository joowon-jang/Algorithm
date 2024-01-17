#include <iostream>

using namespace std;

int flag = 0;
int m, n, k;
int field[50][50] = {0,};

void DFS(int x, int y) {
    if(field[x][y] == 1) {
        flag = 1;
        field[x][y] = 0;
        if(x>0) DFS(x-1,y);
        if(x<49) DFS(x+1,y);
        if(y>0) DFS(x,y-1);
        if(y<49) DFS(x,y+1);
    }
}
int solution() {
    int cnt=0;
    for(int i=0; i<50; i++) {
        for(int j=0; j<50; j++) {
            DFS(i,j);
            if(flag == 1) cnt++;
            flag = 0;
        }
    }
    
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    int x, y;
    
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> m >> n >> k;
        for(int j=0; j<k; j++) {
            cin >> x >> y;
            field[x][y] = 1;
        }
        cout << solution() << "\n";
    }

    return 0;
}