## Problem

Given an even length integer array `nums`, count the cyclic rotations where the sum of the first `n / 2` elements is strictly greater than the sum of the last `n / 2` elements.

A cyclic rotation moves a prefix of the array to the end.

## My Approach

I first calculated the total sum of the entire array.

For the first rotation, I calculated the sum of the first half.

Then instead of recalculating the first half sum for every rotation, I used a sliding window.

When the array rotates by one position:

- The old first element leaves the first half.
- The element at `(i + h) % n` enters the first half.

So I update the current half sum using:

`sum += nums[(i + h) % n] - nums[i]`

I then compare twice the first-half sum with the total sum.

If:

`2 * sum > total`

then the first half has a greater sum than the second half.

## Key Logic

Let:

`h = n / 2`

If the first half has sum `sum`, then the second half has:

`total - sum`

We need:

`sum > total - sum`

which becomes:

`2 * sum > total`

This avoids calculating the second half separately.

The sliding window lets us move from one rotation to the next in constant time.

## Solution

```c
int countGoodRotations(int* nums, int n) {
    int h = n / 2, ans = 0;
    long long total = 0, sum = 0;

    for(int i = 0; i < n; i++) {
        total += nums[i];
    }

    for(int i = 0; i < h; i++) {
        sum += nums[i];
    }

    for(int i = 0; i < n; i++) {
        if(2 * sum > total) {
            ans++;
        }

        sum += nums[(i + h) % n] - nums[i];
    }

    return ans;
}
```

## Complexity

Time: `O(n)`

Space: `O(1)`

## What I Learned

I learned how to use a sliding window with cyclic arrays.

Instead of calculating the sum of every rotation from scratch, I can remove the element leaving the window and add the element entering it.

I also learned how an inequality involving two halves can be simplified using the total sum.