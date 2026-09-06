## Problem

Given two integers `n` and `start`, construct an array where:

`nums[i] = start + 2 * i`

Return the bitwise XOR of all elements in the array.

## My Approach

I noticed that I don't actually need to create the array.

I can directly generate each element using:

`start + 2 * i`

and XOR it with the current answer.

I initialized `ans` to `0` because:

`0 ^ x = x`

Then I used the XOR assignment operator:

`ans ^= value`

## Key Logic

For every index `i`:

`nums[i] = start + 2 * i`

So instead of storing `nums[i]`, I directly XOR it:

`ans ^= start + 2 * i`

For example, if:

`n = 5, start = 0`

the generated values are:

`0, 2, 4, 6, 8`

and the operation becomes:

`0 ^ 2 ^ 4 ^ 6 ^ 8`

which gives `8`.

## Solution

```c
int xorOperation(int n, int start) {
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans ^= start + (2 * i);
    }

    return ans;
}
```

## Complexity

Time: `O(n)`

Space: `O(1)`

## What I Learned

I learned how the XOR operator can be accumulated over an array without actually storing the array.

I also learned that when an array follows a predictable formula, I can generate its elements directly instead of creating unnecessary storage.