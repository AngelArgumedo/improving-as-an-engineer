#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Tu solución aquí
    vector<int> solve(vector<int>& nums) {
        // Implementación
        return {};
    }
};

// Helper para imprimir vectores
void printVector(const vector<int>& v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    auto result1 = sol.solve(nums1);
    cout << "Test 1: ";
    printVector(result1);

    // Test case 2
    // ...

    return 0;
}
