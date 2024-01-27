#include <iostream>

using namespace std;

int n;
int white=0, blue=0;
int arr[128][128];

void recursion(int r, int c, int len) {
    int curr=arr[r][c];
    for(int i=r; i<r+len; i++) {
        for(int j=c; j<c+len; j++) {
            if(arr[i][j] != curr) {
                recursion(r,c,len/2);
                recursion(r+len/2,c,len/2);
                recursion(r,c+len/2,len/2);
                recursion(r+len/2,c+len/2,len/2);
                return;
            }
        }
    }
    if(curr) blue++;
    else white++;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    recursion(0,0,n);
    
    cout << white << "\n" << blue;

    return 0;
}