// Check if Array is Sorted

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool isSorted = true;

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            isSorted = false;
            break;
        }
    }

    if (isSorted) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}
