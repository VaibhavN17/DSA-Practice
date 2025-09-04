#include <bits/stdc++.h>
using namespace std;

// Define the twoSum function OUTSIDE main
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) return {left+1, right+1}; // +1 because LeetCode expects 1-based
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {
    // Example usage
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    cout << "Indices: " << ans[0] << ", " << ans[1] << endl;

    return 0;
}
