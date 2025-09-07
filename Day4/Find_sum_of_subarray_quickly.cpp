#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 6, 8, 10};
    int n = arr.size();

    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    int l = 1, r = 3; 
    int sum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
    cout << "Sum from " << l << " to " << r << " = " << sum << endl;
}
