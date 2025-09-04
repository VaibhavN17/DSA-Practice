#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, sum = 0, ans = INT_MAX;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {   // shrink window
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return (ans == INT_MAX) ? 0 : ans;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Minimum subarray length: " << minSubArrayLen(target, nums) << endl;
    return 0;
}
