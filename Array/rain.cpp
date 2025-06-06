#include <iostream>
using namespace std;

bool containsDuplicate(int nums[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] == nums[j]) {
                return true; 
            }
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 1, 3, 4};  
    int size = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, size)) {
        cout << "true" << endl;  
    } else {
        cout << "false" << endl;
    } 

    return 0;
}