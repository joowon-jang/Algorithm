#include <iostream>
#include <algorithm>

using namespace std;

int n;
int house[1001][3] = {0,};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
        house[i][0] += min(house[i-1][1], house[i-1][2]);
        house[i][1] += min(house[i-1][0], house[i-1][2]);
        house[i][2] += min(house[i-1][0], house[i-1][1]);
    }
    
    cout << min(house[n][0], min(house[n][1], house[n][2]));

    return 0;
}