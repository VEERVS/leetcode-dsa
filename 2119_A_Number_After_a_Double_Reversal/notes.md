## Problem

Given an integer `num`, reverse it twice.

Return `true` if the final result is equal to the original `num`, otherwise return `false`.

The important detail is that **leading zeros are not retained** when reversing.

For example:

```text
12300 → 321 → 123
```

So `12300` does not remain the same after a double reversal.

## My Approach

Instead of actually reversing the number twice, I looked for the condition that causes the number to change.

There are only two special cases:

- If `num == 0`, return `true`.
- If `num` ends in `0`, return `false` because the trailing zero is lost during the first reversal.

For every other positive number, reversing twice gives the original number.

So I directly return the condition:

```cpp
return num == 0 || num % 10 != 0;
```

## Key Logic

The last digit tells us everything.

```cpp
num % 10
```

gives the last digit of `num`.

If it is `0`, reversing removes that zero:

```text
1800
 ↓
81
 ↓
18
```

which is not equal to `1800`.

If the number does not end in `0`, double reversal restores the original number.

`0` is a special case because the problem considers:

```text
0 → 0 → 0
```

so the answer is `true`.

## Solution

```cpp
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};
```

## Complexity

**Time:** `O(1)`

**Space:** `O(1)`

## What I Learned

- Sometimes a problem can be solved without performing the operation described in the problem.
- Looking for the condition that causes a transformation to lose information can lead to an `O(1)` solution.
- `% 10` can be used to check the last digit of a number.
- Special cases like `0` need to be handled carefully.