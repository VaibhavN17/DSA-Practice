#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3};
    unordered_map<int, int> freq;

    for(int num : arr) {
        freq[num]++;
    }

    for(auto it : freq) {
        cout << it.first << " occurs " << it.second << " times\n";
    }
}
