## Problem

Given an array of positive integers, Alice can choose either:

- All **single-digit numbers** (`1` to `9`), or
- All **double-digit numbers** (`10` to `99`).

The remaining numbers are given to Bob.

Alice wins if the sum of her chosen numbers is **strictly greater** than Bob's sum.

Return `true` if Alice can win, otherwise return `false`.

## My Approach

I divided the numbers into two groups:

- `single` → sum of all single-digit numbers
- `dob` → sum of all double-digit numbers

For every element, I check whether it lies between `1` and `9`.

```cpp
if(nums[i] >= 1 && nums[i] <= 9)
```

If it is single-digit, I add it to `single`.

Otherwise, I add it to `dob`.

At the end, Alice can choose the better group, so she can win exactly when the two sums are different.

Therefore:

```cpp
return single != dob;
```

## Key Logic

Alice has only two possible choices:

```text
Choose all single-digit numbers
OR
Choose all double-digit numbers
```

Let:

```text
single = sum of single-digit numbers
dob    = sum of double-digit numbers
```

If:

```text
single > dob
```

Alice chooses the single-digit group.

If:

```text
dob > single
```

Alice chooses the double-digit group.

If they are equal, Alice cannot have a strictly greater sum.

Therefore, Alice wins whenever:

```cpp
single != dob
```

## Solution

```cpp
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0, dob = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 1 && nums[i] <= 9) {
                single += nums[i];
            } else {
                dob += nums[i];
            }
        }

        return single != dob;
    }
};
```

## Complexity

**Time:** `O(n)` because every element is checked once.

**Space:** `O(1)` because only two sum variables are used.

## What I Learned

- Sometimes a game problem can be reduced to comparing two possible outcomes.
- Instead of storing the numbers in separate arrays, I only need their sums.
- A boolean condition can directly represent the final answer.
- `single != dob` works because Alice wins whenever one of the two possible groups has a strictly larger sum.