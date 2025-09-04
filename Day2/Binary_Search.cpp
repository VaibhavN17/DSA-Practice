#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) 
{
    int left = 0, right = arr.size() - 1;
    while(left <= right) 
    {
        int mid = left + (right - left)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 11;
    int no;
    cout << "Index: " << binarySearch(arr, target) << endl;
    // cout<<"Enter Value:";
    // cin>>no;
}
