#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x7f7f7f7f

using namespace std;

int n, m;
vector<pair<int,int>> chicken(1,{0,0});
vector<pair<int,int>> house;
vector<int> v;
int visit[51]={0};
int chickenDist = INF;

void calcDist() {
    int totalDist = 0;
    for(int i=0; i<house.size(); i++) {
        int dist = INF;
        for(int j=0; j<m; j++) {
            dist = min(dist, abs(chicken[v[j]].first - house[i].first) + abs(chicken[v[j]].second - house[i].second));
        }
        totalDist += dist;
    }
        
    chickenDist = min(chickenDist, totalDist);
}

void combi(int total, int start, int cnt) {
    if(cnt==m) {
        calcDist();
    }
    else {
        for(int i=start; i<=total; i++) {
            if(!visit[i]) {
                visit[i] = true;
                v.push_back(i);
                combi(total, i, cnt+1);
                v.pop_back();
                visit[i] = false;
            }
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int tmp;
            cin >> tmp;
            if(tmp==2) chicken.push_back({i,j});
            if(tmp==1) house.push_back({i,j});
        }
    }
    
    combi(chicken.size()-1,1,0);
    
    cout << chickenDist;

    return 0;
}