#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int tmp;
    int arr[41] = {0, 1, 1};
    
    for(int i=3; i<41; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> tmp;
        if(tmp == 0) {
            cout << "1 0\n";
        }
        else {
            cout << arr[tmp-1] << " " << arr[tmp] << "\n";
        }
    }

    return 0;
}