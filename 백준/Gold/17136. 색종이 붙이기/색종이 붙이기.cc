#include <iostream>
#include <algorithm>

using namespace std;

int board[10][10];
int paper[5];
int ans = 100;

bool check_board() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(board[i][j] == 1) return false;
        }
    }

    return true;
}

void fill_board(int r, int c, int size, int elem) {
    for(int i=r; i<=r+size; i++) {
        for(int j=c; j<=c+size; j++) {
            board[i][j] = elem;
        }
    }
}

bool check_range(int r, int c, int size) {
    for(int i=r; i<=r+size; i++) {
        for(int j=c; j<=c+size; j++) {
            if(board[i][j] != 1) return false;
        }
    }

    return true;
}

bool isIn(int r, int c) {
    return (r>=0 && r<10 && c>=0 && c<10);
}

void solution(int cnt) {
    if(check_board()) {
        ans = min(ans, cnt);
        return;
    }

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(board[i][j] == 1) {
                for(int k=4; k>=0; k--) {
                    if(paper[k] >= 5) continue;
                    if(!isIn(i + k, j + k)) continue;
                    if(!check_range(i,j,k)) continue;

                    paper[k]++;
                    fill_board(i,j,k,0);

                    solution(cnt+1);

                    fill_board(i,j,k,1);
                    paper[k]--;
                }
                
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> board[i][j];
        }
    }

    solution(0);

    if(ans == 100) cout << -1;
    else cout << ans;

    return 0;
}