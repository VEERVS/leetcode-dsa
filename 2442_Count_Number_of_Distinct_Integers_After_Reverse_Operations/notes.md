## Problem

You are given an array `nums` consisting of positive integers.

Reverse the digits of every integer in the array and add each reversed integer to the array.

Return the number of distinct integers in the final array.

## My Approach

I created a helper function `reverse()` to reverse the digits of an integer.

Inside this function, I use a `long long` variable `rev` to construct the reversed number. I repeatedly extract the last digit using `% 10`, append it to `rev`, and remove the last digit from `n` using `/ 10`.

In the main function, I initialize an `unordered_set<int>` with all the original elements of `nums`.

Then, I traverse the array and insert the reverse of every element into the set.

Since an `unordered_set` stores only unique values, its size gives the number of distinct integers after all reverse operations.

## Key Logic

Extract the last digit and append it to the reversed number:

```cpp
rev = (rev * 10) + (n % 10);
n /= 10;
```

Initialize a set with the original elements:

```cpp
unordered_set<int> ans(nums.begin(), nums.end());
```

Insert every reversed integer:

```cpp
for(int x : nums) {
    ans.insert(reverse(x));
}
```

**Example:**

```text
Input: [1,13,10,12,31]

Reversed values:
1 → 1
13 → 31
10 → 1
12 → 21
31 → 13

Distinct values:
1, 10, 12, 13, 21, 31

Output: 6
```

Note that reversing `10` produces `1`, because leading zeros are not preserved in integers.

## Solution

```cpp
class Solution {
public:
    int reverse(int n) {
        long long rev = 0;

        while(n > 0) {
            rev = (rev * 10) + (n % 10);
            n /= 10;
        }

        return rev;
    }

    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> ans(nums.begin(), nums.end());

        for(int x : nums) {
            ans.insert(reverse(x));
        }

        return ans.size();
    }
};
```

## Complexity

Let `n` be the number of elements and `d` be the maximum number of digits in an element.

- **Time:** `O(n * d)` average, including reversing each number and inserting into the set.
- **Space:** `O(n)` for the set of distinct integers.

## What I Learned

- `% 10` extracts the last digit of an integer.
- `/ 10` removes the last digit.
- `rev * 10 + digit` builds a number in reverse order.
- An `unordered_set` automatically removes duplicates.
- Initializing a set with `nums.begin()` and `nums.end()` inserts all original elements.
- Reversing an integer does not preserve leading zeros.