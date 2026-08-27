## Problem

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` **in-place** and return the number of elements that are not equal to `val`.

Example:

```text
nums = [3,2,2,3], val = 3

Result → [2,2,...]
Return → 2
```

## My Approach

Use two variables:

```text
i     → reads/scans the array
count → writes/places valid elements
```

`i` goes through every element, while `count` only moves when we find an element that should be kept.

If:

```c
nums[i] != val
```

copy that element to the position indicated by `count`:

```c
nums[count] = nums[i];
count++;
```

This effectively **compacts all valid elements toward the beginning of the same array**.

## Key Logic

```c
for(int i = 0; i < numsSize; i++) {
    if(nums[i] != val) {
        nums[count] = nums[i];
        count++;
    }
}
```

Think of the pointers as:

```text
i      → READ
count  → WRITE
```

Example:

```text
nums = [3,2,2,3]
val = 3

i = 0 → 3 ❌ skip
i = 1 → 2 ✅ nums[0] = 2
i = 2 → 2 ✅ nums[1] = 2
i = 3 → 3 ❌ skip

First `count` elements:

[2,2]
```

Finally:

```c
return count;
```

returns the number of valid elements.

## Solution

```c
int removeElement(int* nums, int numsSize, int val) {
    int count = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[count] = nums[i];
            count++;
        }
    }

    return count;
}
```

## Complexity

**Time:** O(n) — each element is scanned once.

**Space:** O(1) — the array is modified in-place and no extra array is created.

## What I Learned

- `i` and `count` have different jobs: **read vs write**.
- `count` only moves when an element is worth keeping.
- An array can be modified in-place without creating another array.
- We don't actually need to "delete" elements; we can overwrite the beginning with valid elements.
- This is a classic **two-pointer / read-write pointer technique**.