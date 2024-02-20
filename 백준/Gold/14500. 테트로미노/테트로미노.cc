#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int field[500][500];
bool visit[500][500] = {false};
int answer = 0;


void DFS(int r, int c, int depth, int sum) {
    if(depth >= 3) {
        answer = max(answer, sum);
        return;
    }
    for(int i=0; i<4; i++) {
        int nR = r + dir[i][0];
        int nC = c + dir[i][1];
        if(nR < 0 || nR >= n || nC < 0 || nC >=m) continue;
        if(visit[nR][nC]) continue;
        visit[nR][nC] = true;
        DFS(nR, nC, depth+1, sum+field[nR][nC]);
        visit[nR][nC] = false;
    }
}

void shape1(int r, int c) {
    int sum = field[r][c] + field[r+1][c] + field[r+2][c] + field[r+1][c+1];
    answer = max(answer, sum);
}
void shape2(int r, int c) {
    int sum = field[r][c] + field[r+1][c] + field[r+2][c] + field[r+1][c-1];
    answer = max(answer, sum);
}
void shape3(int r, int c) {
    int sum = field[r][c] + field[r][c+1] + field[r][c+2] + field[r-1][c+1];
    answer = max(answer, sum);
}
void shape4(int r, int c) {
    int sum = field[r][c] + field[r][c+1] + field[r][c+2] + field[r+1][c+1];
    answer = max(answer, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> field[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visit[i][j] = true;
            DFS(i, j, 0, field[i][j]);
            visit[i][j] = false;
            if(i+2 < n && j+1 < m) shape1(i,j);
            if(i+2 < n && j-1 >= 0) shape2(i,j);
            if(i-1 >= 0 && j+2 < m) shape3(i,j);
            if(i+1 < n && j+2 < m) shape4(i,j);
        }
    }
    
    cout << answer;

    return 0;
}