## Problem

Implement `pow(x, n)`, which calculates `x` raised to the power `n`, i.e. `x^n`.

The exponent `n` can be positive, zero, or negative.

## My Approach

I used C++'s built-in `pow()` function from the standard library.

Instead of manually calculating the power, I directly passed `x` and `n` to:

`pow(x, n)`

This also automatically handles negative exponents, such as:

`2^-2 = 0.25`

## Key Logic

The built-in function already performs the required power calculation.

The solution is simply:

`return pow(x, n);`

For the actual DSA approach to this problem, the important concept to learn is **Binary Exponentiation (Fast Power)**, which can calculate powers in `O(log n)` time instead of repeatedly multiplying `x` `n` times.

## Solution

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};
```

## Complexity

Time: `O(log n)` for the standard efficient power implementation used by the library.

Space: `O(1)` from the perspective of the solution.

## What I Learned

I learned that C++ provides a built-in `pow()` function for calculating powers.

However, this problem is mainly useful for learning **Binary Exponentiation**, so I should revisit it later and implement the algorithm myself rather than relying on the library function.