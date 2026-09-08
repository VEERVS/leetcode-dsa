## Problem

Given an integer `num`, return the number of steps required to reduce it to zero.

In one step:

- If `num` is even, divide it by `2`.
- If `num` is odd, subtract `1`.

## My Approach

I solved the problem using recursion.

The base case is:

```cpp
if(num == 0)
    return 0;
```

For every other value, one operation is performed, so I add `1` and recursively solve the smaller number.

If the number is even:

```cpp
1 + numberOfSteps(num / 2)
```

If the number is odd:

```cpp
1 + numberOfSteps(num - 1)
```

## Key Logic

The recursive function represents:

> "How many steps are needed to reduce the current `num` to zero?"

Every recursive call reduces the problem:

```text
even → num / 2
odd  → num - 1
```

For example, `14`:

```text
14 → 7 → 6 → 3 → 2 → 1 → 0
```

There are `6` operations.

## Solution

```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) {
            return 0;
        }

        if(num % 2 == 0) {
            return 1 + numberOfSteps(num / 2);
        } else {
            return 1 + numberOfSteps(num - 1);
        }
    }
};
```

## Complexity

Time: `O(log n)` on average because even values are repeatedly divided by `2`, with at most an additional subtraction for odd values.

Space: `O(log n)` because of the recursive call stack.

## What I Learned

I practiced converting a simple iterative process into recursion.

The important recursive pattern is:

```cpp
return 1 + recursiveCall(smallerProblem);
```

I also learned how to identify a proper base case so the recursion eventually stops.