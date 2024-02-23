#include <iostream>
#include <queue>

using namespace std;

int n;
int graph[100][100];
int newGraph[100][100]={0,};

void solution(int a, int b) {
    newGraph[a][b]=1;
    queue<int> q;
    q.push(b);
    
    while(!q.empty()) {
        int curr=q.front();
        q.pop();
        
        for(int i=0; i<n; i++) {
            if(graph[curr][i]==1) {
                if(newGraph[a][i]!=1) {
                    newGraph[a][i]=1;
                    if(i!=a) q.push(i);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> graph[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(graph[i][j]==1) {
                solution(i,j);
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << newGraph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}