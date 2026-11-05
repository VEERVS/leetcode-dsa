# 1385. Find the Distance Value Between Two Arrays

## Problem
Given two integer arrays `arr1` and `arr2`, and an integer `d`, return the number of elements in `arr1` such that there is no element in `arr2` satisfying:

`|arr1[i] - arr2[j]| <= d`

## My Approach
Used nested loops to compare every element of `arr1` with every element of `arr2`.

1. Traverse each element of `arr1`.
2. Initialize a `found` counter to zero.
3. Compare the current element with every element of `arr2`.
4. If the absolute difference is greater than `d`, increment `found`.
5. After checking all elements of `arr2`, if `found == arr2.size()`, the current element satisfies the condition.
6. Increment the final answer.

## Key Logic
- `abs(arr1[i] - arr2[j]) > d`: This particular element of `arr2` does not violate the condition.
- `found == arr2.size()`: Every element in `arr2` is at a distance greater than `d` from the current `arr1[i]`.
- Only then do we increment the answer.

## Solution

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for (int i = 0; i < arr1.size(); i++) {
            int found = 0;

            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) > d) {
                    found++;
                }
            }

            if (found == arr2.size()) {
                count++;
            }
        }

        return count;
    }
};
```

## Complexity
- **Time Complexity:** O(n × m), where n is the size of `arr1` and m is the size of `arr2`.
- **Space Complexity:** O(1), as only a constant number of variables are used.

## What I Learned
- How to use nested loops to compare two arrays.
- How absolute difference helps measure the distance between two integers.
- How to verify that an element satisfies a condition against every element of another array.