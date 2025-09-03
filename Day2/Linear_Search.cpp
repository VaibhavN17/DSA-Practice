#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i <arr.size(); i++) {
        if (arr[i] == target)
            return i; // return index if found
    }
    return -1; // not found
}

int main() {
    vector<int> arr = {4, 2, 7, 1, 3};
    int target = 7;
    int index = linearSearch(arr, target);
    if(index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
}
// This code implements a simple linear search algorithm to find the index of a target element in an array.