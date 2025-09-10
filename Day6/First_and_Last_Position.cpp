#include <bits/stdc++.h>
using namespace std;


int firstOccurrence(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1, ans = -1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] == target) {
            ans = mid;
            high = mid - 1; // search left side
        } else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return ans;
}

int lastOccurrence(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1, ans = -1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid] == target) {
            ans = mid;
            low = mid + 1; // search right side
        } else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return ans;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    int first = firstOccurrence(nums, target);
    int last = lastOccurrence(nums, target);
    cout << "First Occurrence: " << first << endl;
    cout << "Last Occurrence: " << last << endl;
    return 0;
}