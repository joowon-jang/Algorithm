#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    int gap=0x7f7f7f7f;
    vector<int> v;
    int ans1, ans2;

    cin >> n;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    
    int left=0;
    int right=n-1;
    while(left<right) {
        int sum=v[left]+v[right];
        if(gap>abs(sum)) {
            gap=abs(sum);
            ans1=left;
            ans2=right;
        }
        if(gap==0) {
            break;
        }
        else if(sum>0) {
            right--;
        }
        else if(sum<0) {
            left++;
        }
    }
    
    cout << v[ans1] << " " << v[ans2];

    return 0;
}