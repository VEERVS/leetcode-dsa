## Problem

Given an integer `n`, return `true` if `n` has exactly **three positive divisors**.

Otherwise, return `false`.

For example:

```text
n = 4

Divisors:
1, 2, 4

Total = 3

Answer = true
```

## My Approach

I used a **brute-force divisor counting** approach.

I loop from `1` to `n` and check whether each number divides `n`.

If:

```cpp
n % i == 0
```

then `i` is a divisor, so I increase `count`.

At the end, I return:

```cpp
return count == 3;
```

## Key Logic

A number `i` is a divisor of `n` when:

```cpp
n % i == 0
```

For example, with:

```text
n = 4
```

we check:

```text
4 % 1 = 0 → divisor
4 % 2 = 0 → divisor
4 % 3 ≠ 0
4 % 4 = 0 → divisor
```

So:

```text
count = 3
```

and the answer is `true`.

## Solution

```cpp
class Solution {
public:
    bool isThree(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                count++;
            }
        }

        return count == 3;
    }
};
```

## Complexity

**Time:** `O(n)` because we check every number from `1` to `n`.

**Space:** `O(1)`

## What I Learned

- A divisor can be checked using the modulo operator.
- Brute-force divisor counting is straightforward and easy to understand.
- We can determine whether a number has exactly three divisors by counting them.
- A useful mathematical optimization exists: a number has exactly three divisors **only if it is the square of a prime number**.
- The current solution uses the straightforward `O(n)` approach, while the mathematical observation can lead to a faster solution.