#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
int arr[301][301];

void rotate(int a, int b, int c, int d) {
    vector<int> v;
    int i=a;
    int j=b;

    while(1) {
        v.push_back(arr[i][j]);
        if(i==a && j<d-1) {
            j++;
        }
        else if(j==d-1 && i<c-1) {
            i++;
        }
        else if(i==c-1 && j>b) {
            j--;
        }
        else {
            i--;
        }
        if(i==a && j==b) break;
    }
    
    int curr=r%((n-i*2)*2 + (m-i*2)*2 -4);
    
    while(1) {
        arr[i][j]=v[curr];
        if(i==a && j<d-1) {
            j++;
        }
        else if(j==d-1 && i<c-1) {
            i++;
        }
        else if(i==c-1 && j>b) {
            j--;
        }
        else {
            i--;
        }
        if(i==a && j==b) break;
        curr++;
        if(curr>=v.size()) curr=0;
    }
}

int main()
{
    ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<min(n,m)/2; i++) {
        rotate(i,i,n-i,m-i);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}