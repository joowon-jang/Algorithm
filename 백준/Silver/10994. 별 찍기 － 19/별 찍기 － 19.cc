#include <iostream>

using namespace std;

char arr[400][400];
int n;

void recursion(int n, int r, int c) {
    for(int i=r; i<r+4*n-3; i++) {
        if(i==r || i==r+4*n-4) {
            for(int j=c; j<c+4*n-3; j++) {
                arr[i][j]='*';
            }
        }
        else {
            arr[i][c]='*';
            arr[i][c+4*n-4]='*';
        }
    }
    
    if(n>0) recursion(n-1, r+2, c+2);
}

int main()
{
    cin >> n;
    
    for(int i=0; i<4*n-3; i++) {
        for(int j=0; j<4*n-3; j++) {
            arr[i][j]=' ';
        }
    }
    
    recursion(n, 0, 0);
    
    for(int i=0; i<4*n-3; i++) {
        for(int j=0; j<4*n-3; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}