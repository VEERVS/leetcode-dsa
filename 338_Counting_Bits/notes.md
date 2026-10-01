## Problem

Given an integer `n`, return an array where `ans[i]` is the number of `1`s in the binary representation of `i`.

For example:

```text
n = 5

0 → 000 → 0
1 → 001 → 1
2 → 010 → 1
3 → 011 → 2
4 → 100 → 1
5 → 101 → 2

ans = [0,1,1,2,1,2]
```

## My Approach

For every number from `0` to `n`, I count its set bits.

I use the bit manipulation trick:

```cpp
num = num & (num - 1);
```

This operation removes the lowest set bit (`1`) from `num`.

Therefore, I repeatedly perform this operation and increment `count`.

When `num` becomes `0`, `count` is the total number of set bits.

## Key Logic

The important operation is:

```cpp
num & (num - 1)
```

For example:

```text
num = 13

13 = 1101
12 = 1100

1101
1100
----
1100
```

One set bit is removed.

Repeating:

```text
1101
 ↓
1100
 ↓
1000
 ↓
0000
```

There were 3 operations, so `13` contains 3 set bits.

I apply this independently to every number from `0` through `n`.

## Solution

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++) {
            int count = 0;
            int num = i;

            while(num != 0) {
                num = num & (num - 1);
                count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n log n) in the worst case
- Space: O(n)

The outer loop processes `n + 1` numbers, and each number can require up to O(log n) set-bit removals.

The `O(n)` space is for the returned answer array.

## What I Learned

- `num & (num - 1)` removes the lowest set bit.
- The number of times this operation can be performed is exactly the number of set bits.
- This is often more efficient than checking every bit individually.
- A bit manipulation trick learned in one problem can be reused in many different problems.