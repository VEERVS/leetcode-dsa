## Problem

Given an unsorted integer array, find the smallest positive integer that is not present in the array.

The solution must run in O(n) time and use O(1) extra space.

## My Approach

I use the array itself to place positive numbers at their correct indexes.

The rule is:

```text
value 1 → index 0
value 2 → index 1
value 3 → index 2
...
value x → index x - 1
```

For every index, I keep swapping the current value into its correct position using a `while` loop.

I only consider values between `1` and `n`, because the answer must always be between `1` and `n + 1`.

After placing the values, I scan the array.

The first index where:

```cpp
nums[i] != i + 1
```

means that `i + 1` is missing.

## Key Logic

The placement condition is:

```cpp
while(nums[i] > 0 &&
      nums[i] <= n &&
      nums[i] != nums[nums[i] - 1])
```

The three conditions mean:

- `nums[i] > 0` → ignore zero and negative numbers.
- `nums[i] <= n` → ignore numbers that cannot affect the answer.
- `nums[i] != nums[nums[i] - 1]` → prevents unnecessary swaps when duplicates already exist.

The important part is using `while`, not just `if`.

One swap can bring another misplaced value into the current index, so we continue placing values until the current position cannot be improved further.

After placement:

```cpp
for(int i = 0; i < n; i++) {
    if(nums[i] != i + 1) {
        return i + 1;
    }
}
```

If every position is correct, then all values from `1` to `n` exist, so the answer is:

```cpp
n + 1
```

## Solution

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 &&
                  nums[i] <= n &&
                  nums[i] != nums[nums[i] - 1]) {

                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
```

## Complexity

- Time: O(n)
- Space: O(1) auxiliary space

Although there is a `while` loop inside the `for` loop, the overall time is O(n) because every successful swap places a value into its correct position.

## What I Learned

- An array can be used as its own hash/index structure.
- The rule `value x → index x - 1` is the core idea.
- This is an index-placement/cyclic-sort style technique, not normal sorting.
- Duplicates require the condition `nums[i] != nums[nums[i] - 1]` to avoid infinite swapping.
- Values outside `1...n` can safely be ignored.
- O(1) space does not mean we cannot modify the input array.