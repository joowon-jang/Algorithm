#include <iostream>

using namespace std;

char arr[10000][10000];
bool visit[10000][10000]={0};
int n;

void recursion(int a, int r, int c) {
    for(int i=r+a/3; i<r+a*2/3; i++) {
        for(int j=c+a/3; j<c+a*2/3; j++) {
            arr[i][j]=' ';
        }
    }
    
    if(a<=3) return;
    
    for(int i=r; i<r+a; i+=a/3) {
        for(int j=c; j<c+a; j+=a/3) {
            recursion(a/3,i,j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j]='*';
        }
    }
    
    recursion(n,0,0);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}