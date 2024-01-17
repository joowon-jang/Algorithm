#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
vector<string> field;
string str;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<int> cnt;
int tmp = 1;
int num = 0;

bool isInside(int y, int x) {
    if(y<0 || y>=n || x<0 || x>=n) return false;
    return true;
}

void dfs(int y, int x) {
    field[y][x] = '0';
    for(int i=0; i<4; i++) {
        int nY = y + dir[i][0];
        int nX = x + dir[i][1];
        if(isInside(nY,nX) && field[nY][nX] == '1') {
            dfs(nY,nX);
            tmp++;
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        field.push_back(str);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(field[i][j] == '1') {
                dfs(i,j);
                cnt.push_back(tmp);
                tmp = 1;
                num++;
            }
        }
    }
    
    sort(cnt.begin(),cnt.end());
    
    cout << num << "\n";
    for(int i=0; i<cnt.size(); i++) {
        cout << cnt[i] << "\n";
    }

    return 0;
}