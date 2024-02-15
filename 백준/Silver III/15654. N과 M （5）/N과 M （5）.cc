#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int v[8];
int arr[8];
bool visit[8] = {0};

void solution(int cnt) {
    if(cnt==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++) {
        if(!visit[i]) {
            arr[cnt] = v[i];
            visit[i] = true;
            solution(cnt+1);
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v, v+n);
    
    solution(0);
    
    return 0;
}