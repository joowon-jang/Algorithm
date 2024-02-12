#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    vector<int> v;
    int ans=0;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    
    for(int i=0; i<n; i++) {
        int left=0;
        int right=n-1;
        while(left<right) {
            if(v[left]+v[right]==v[i] && left!=i && right!=i) {
                ans++;
                break;
            }
            else if(v[left]+v[right]<v[i]) {
                left++;
            }
            else if(v[left]+v[right]>v[i]) {
                right--;
            }
            if(left==i) left++;
            if(right==i) right--;
        }
    }
    
    cout << ans;

    return 0;
}