## Problem

Given an integer `num`, repeatedly add all of its digits until only a single digit remains.

Example:

```text
38 → 11 → 2
```

## My Approach

Calculate the sum of the digits using `% 10` and `/ 10`.

If the sum is still greater than 9, recursively call the function again with the new sum.

## Key Logic

```c
digit = temp % 10;
sum += digit;
temp /= 10;
```

## Recursion

The first attempt calculated the digit sum only once:

`38 → 11`

Then I realized another round was needed:

`38 → 11 → 2`

The important part is:

```c
return addDigits(sum);
```

`return` passes the result of the recursive call back to the previous call.

## Complexity

**Time:** O(log n)  
**Space:** O(log n) due to recursion.

## What I Learned

- `% 10` extracts the last digit.
- `/ 10` removes the last digit.
- A loop processing digits is O(log n), not O(n).
- Recursion can repeat the same operation until a base condition is reached.
- `return` is necessary to pass the recursive result back.

## Solution

```c
int addDigits(int num) {
    int temp = num, sum = 0;

    while(temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if(sum < 10) {
        return sum;
    } else {
        return addDigits(sum);
    }
}
```

## Milestone

⭐ First LeetCode problem solved independently.