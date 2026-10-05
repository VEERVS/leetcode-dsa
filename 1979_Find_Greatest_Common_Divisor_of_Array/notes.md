## Problem

Given an integer array `nums`, find the greatest common divisor (GCD) of the smallest number and the largest number in the array.

## My Approach

First, I found the smallest and largest elements using:

```cpp
min_element()
max_element()
```

Then I calculated their GCD using the built-in `gcd()` function.

For example:

```text
nums = [2,5,6,9,10]

minimum = 2
maximum = 10

gcd(2,10) = 2
```

## Key Logic

Find the minimum:

```cpp
int min = *min_element(nums.begin(), nums.end());
```

Find the maximum:

```cpp
int max = *max_element(nums.begin(), nums.end());
```

Then:

```cpp
return gcd(min, max);
```

The `*` is needed because `min_element()` and `max_element()` return iterators.

## Solution

```cpp
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        return gcd(min, max);
    }
};
```

## Complexity

- **Time:** `O(n + log(max(nums)))`
- **Space:** `O(1)`.

Finding the minimum and maximum takes `O(n)`, while the Euclidean GCD algorithm takes `O(log(max(nums)))`.

Overall, the dominant complexity is:

```text
O(n)
```

## What I Learned

- `min_element()` finds the iterator pointing to the smallest element.
- `max_element()` finds the iterator pointing to the largest element.
- Dereferencing with `*` gives the actual value.
- `gcd(a, b)` calculates the greatest common divisor using the Euclidean algorithm.
- STL algorithms can simplify common operations without implementing them manually.