#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int arr[200];
    int dp[200];
    vector<int> v;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    v.push_back(arr[0]);
    for(int i=1; i<n; i++) {
        for(int j=0; j<v.size(); j++) {
            if(v[j]>arr[i]) {
                v[j]=arr[i];
                break;
            }
            if(j==v.size()-1) {
                v.push_back(arr[i]);
                break;
            }
        }
    }
    
    cout << n-v.size();
    
    return 0;
}