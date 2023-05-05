#include <iostream>
using namespace std;

int binarySearch(int nums[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[] = { 1, 3, 5, 7, 19};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target1 = 7;
    int target2 = 11;
    int index1 = binarySearch(nums, n, target1);
    int index2 = binarySearch(nums, n, target2);

    if (index1 >= 0) {
        cout << "Element found at index " << index1;
    }
    else {
        cout << "Element not found in the array";
    }
    cout << endl;
    
    if (index2 >= 0) {
        cout << "Element found at index " << index2;
    }
    else {
        cout << "Element not found in the array";
    }
    cout << endl;

    return 0;
}
