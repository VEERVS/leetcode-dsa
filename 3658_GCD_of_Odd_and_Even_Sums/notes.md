## 3658. GCD of Odd and Even Sums

### Problem

Given an integer `n`, find the GCD of:

- The sum of the first `n` positive odd numbers.
- The sum of the first `n` positive even numbers.

### My Approach

Instead of calculating both sums using loops, find their mathematical formulas.

The sum of the first `n` odd numbers is:

sumOdd = n²

The sum of the first `n` even numbers is:

sumEven = n(n + 1)

Therefore we need:

GCD(n², n(n + 1))

### Key Logic

Factor out `n`:

GCD(n × n, n × (n + 1))

= n × GCD(n, n + 1)

Since `n` and `n + 1` are consecutive numbers:

GCD(n, n + 1) = 1

Therefore:

GCD = n

### Solution

int gcdOfOddEvenSums(int n) {
    return n;
}

### Example

For `n = 4`:

sumOdd = 1 + 3 + 5 + 7 = 16

sumEven = 2 + 4 + 6 + 8 = 20

GCD(16, 20) = 4

Therefore the answer is simply:

n = 4

### Complexity

Time: O(1)
Space: O(1)

### What I Learned

- The sum of the first `n` odd numbers is `n²`.
- The sum of the first `n` even numbers is `n(n + 1)`.
- Consecutive numbers always have GCD `1`.
- Mathematical observations can completely eliminate loops.
- Sometimes the optimal solution comes from proving what the answer must be rather than calculating it.