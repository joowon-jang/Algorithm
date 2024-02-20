#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int s, e, t;
};

vector<edge> edges;
int dist[501];

void solution(int n) {
    for(int i=0; i<n; i++) {
        for(int pos=0; pos<edges.size(); pos++) {
            int s = edges[pos].s;
            int e = edges[pos].e;
            int t = edges[pos].t;
            
            if(dist[s] + t < dist[e]) {
                dist[e] = dist[s] + t;
            }
        }
    }
    
    for(int pos=0; pos<edges.size(); pos++) {
        int s = edges[pos].s;
        int e = edges[pos].e;
        int t = edges[pos].t;
        if(dist[s] + t < dist[e]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    int n, m, w;
    int s, e, t;
    
    cin >> tc;
    while(tc--) {
        edges.clear();
        cin >> n >> m >> w;
        for(int i=1; i<=n; i++) {
            dist[i] = 987654321;
        }
        for(int i=0; i<m; i++) {
            cin >> s >> e >> t;
            edges.push_back({s,e,t});
            edges.push_back({e,s,t});
        }
        for(int i=0; i<w; i++) {
            cin >> s >> e >> t;
            edges.push_back({s,e,-t});
        }
        
        solution(n);
    }
    

    return 0;
}