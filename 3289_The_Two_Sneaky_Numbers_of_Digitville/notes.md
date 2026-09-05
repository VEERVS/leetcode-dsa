## Problem

Given an array `nums` containing integers from `0` to `n - 1`, every number should appear exactly once.

However, two numbers appear an additional time.

Return the two numbers that appear twice.

## My Approach

I used a frequency array to count how many times each number appears.

First, I created:

```c
int freq[101] = {0};
```

Then I traversed the input array and incremented the frequency of each number:

```c
freq[nums[i]]++;
```

After that, I traversed the array again.

Whenever:

```c
freq[nums[i]] == 2
```

the number is one of the two sneaky numbers, so I store it in `ans`.

I increment the frequency after finding it so that the same number is not added to the answer again.

## Key Logic

The important idea is **frequency counting**.

For example:

```text
nums = [0, 3, 2, 1, 3, 2]
```

Frequencies:

```text
0 → 1
1 → 1
2 → 2
3 → 2
```

The numbers whose frequency is `2` are:

```text
2, 3
```

So the answer is:

```text
[2, 3]
```

Since exactly two numbers appear twice, we only need to find the two values with frequency `2`.

## Solution

```c
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;

    int* ans = malloc((*returnSize) * sizeof(int));
    int freq[101] = {0};
    int k = 0;

    for(int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    for(int i = 0; i < numsSize; i++) {
        if(freq[nums[i]] == 2) {
            ans[k] = nums[i];
            k++;
            freq[nums[i]]++;
        }
    }

    return ans;
}
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the frequency array and returned array.

## What I Learned

- Frequency arrays are useful when values fall within a small known range.
- `freq[value]++` is a simple way to count occurrences.
- Instead of comparing every pair of elements, I can count occurrences and directly identify duplicates.
- This is another application of the frequency-counting technique I used in the Good Pairs problem.