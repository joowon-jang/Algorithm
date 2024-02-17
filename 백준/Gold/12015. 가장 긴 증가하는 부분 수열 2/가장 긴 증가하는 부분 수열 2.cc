#include <iostream>
#include <vector>

using namespace std;

vector<int> res;

int getPos(int x) {
    int l=0;
    int r=res.size();
    int mid=(l+r)/2;
    
    while(l<r) {
        if(res[mid]>=x) {
            r=mid;
            mid=(l+r)/2;
            continue;
        }
        l=mid+1;
        mid=(l+r)/2;
    }
    
    return mid;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n;
    vector<int> v;
    cin >> n;
    int tmp;
    for(int i=0; i<n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    res.push_back(v[0]);
    
    for(int i=1; i<n; i++) {
        if(res[res.size()-1] < v[i]) {
            res.push_back(v[i]);
            continue;
        }
        int pos=getPos(v[i]);
        res[pos]=v[i];
    }
    
    cout << res.size();

    return 0;
}