## Problem
There are `n` passengers and exactly `n` seats on an airplane.

The first passenger has lost their ticket and chooses a seat randomly.

Every other passenger:
- Takes their assigned seat if it is available.
- Otherwise, chooses another available seat randomly.

Return the probability that the nth passenger gets their own seat.

**LeetCode:** 1227. Airplane Seat Assignment Probability

## My Approach
I used the mathematical observation that the probability is independent of the number of passengers once `n` is greater than 1.

There are two important possibilities:
- If the first passenger chooses their own seat, everyone gets their assigned seat.
- If the first passenger chooses the nth passenger's seat, the nth passenger cannot get their own seat.

For all other initially chosen seats, the problem reduces to the same situation with fewer passengers.

This symmetry results in a probability of exactly `0.5` for every `n > 1`.

## Key Logic
1. If `n == 1`, return `1.0`.
2. If `n > 1`, return `0.5`.

## Solution
```cpp
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};
```

## Complexity
- **Time Complexity:** `O(1)` — only one condition is checked.
- **Space Complexity:** `O(1)` — no additional data structures are used.

## What I Learned
- Mathematical observation can eliminate the need for simulation.
- Symmetry and probability can simplify seemingly complicated random processes.
- For one passenger, the probability is `1.0`.
- For two or more passengers, the probability is always `0.5`.
- Not every problem requires loops, recursion, or data structures.