## Problem

Given two non-negative integers `num1` and `num2`, repeatedly subtract the smaller number from the larger number.

- If `num1 >= num2`, subtract `num2` from `num1`.
- Otherwise, subtract `num1` from `num2`.
- Stop when either number becomes `0`.

Return the total number of operations.

## My Approach

I used **recursion**.

First, I check the base case:

```cpp
if(num1 == 0 || num2 == 0) {
    return 0;
}
```

If `num1` is greater than `num2`, I subtract `num2` from `num1` and make a recursive call.

Otherwise, I subtract `num1` from `num2` and make a recursive call.

Each recursive call represents **one operation**, so I add `1` to the result of the recursive call.

## Key Logic

The important part is deciding which number to subtract:

```cpp
if(num1 > num2) {
    return 1 + countOperations(num1 - num2, num2);
}
else {
    return 1 + countOperations(num1, num2 - num1);
}
```

For example:

```text
num1 = 2, num2 = 3

(2,3)
→ (2,1)   operation 1
→ (1,1)   operation 2
→ (0,1)   operation 3

Answer = 3
```

The recursion continues until one of the numbers becomes `0`.

## Solution

```cpp
class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0) {
            return 0;
        }

        if(num1 > num2) {
            return 1 + countOperations(num1 - num2, num2);
        }
        else {
            return 1 + countOperations(num1, num2 - num1);
        }
    }
};
```

## Complexity

**Time:** `O(number of operations)`  
Worst case: `O(max(num1, num2))`

**Space:** `O(number of operations)` due to the recursive call stack.

## What I Learned

- How to convert a repeated operation into a recursive solution.
- The importance of having a **base case** to stop recursion.
- Each recursive call can represent one operation.
- The larger number is reduced by the smaller number until one reaches `0`.
- This problem is closely related to the **Euclidean Algorithm for GCD**.