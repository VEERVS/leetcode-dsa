## Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers whose sum equals `target`.

Example:

```text
nums = [2,7,11,15], target = 9

2 + 7 = 9
→ [0,1]
```

## My Approach

I used two nested loops to check every possible pair.

```c
if(nums[i] + nums[j] == target)
```

Once the pair is found, store its two indices in a dynamically allocated array and return it.

## Key Logic

```c
int *result = malloc(2 * sizeof(int));

result[0] = i;
result[1] = j;

*returnSize = 2;

return result;
```

`malloc()` allocates memory for the two integers that need to be returned.

`returnSize` is an output parameter. Since Two Sum always returns exactly two indices:

```c
*returnSize = 2;
```

## Solution

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i, j;

    int *result = malloc(2 * sizeof(int));

    *returnSize = 2;

    for(i = 0; i < numsSize; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }

    return result;
}
```

## Complexity

**Time:** O(n²) — two nested loops check every pair.

**Space:** O(1) auxiliary space — only two integers are returned.

## What I Learned

- `int*` can represent an array.
- `returnSize` is a pointer used as an output parameter.
- `*returnSize = 2` changes the value at the address passed by LeetCode.
- A local array cannot safely be returned from a function.
- `malloc()` dynamically allocates memory that remains available after the function returns.
- `sizeof(int)` is used to allocate the correct amount of memory.
- Nested loops can be used to check every possible pair.
- This was my first proper use of dynamic memory allocation in a LeetCode problem.