## Problem
A bookstore owner is grumpy during certain minutes. Given two arrays, `customers` and `grumpy`, and an integer `minutes`, return the maximum number of satisfied customers throughout the day.

- `customers[i]` represents the number of customers entering at minute `i`.
- `grumpy[i] == 1` means the owner is grumpy.
- `grumpy[i] == 0` means the customers are already satisfied.
- The owner can use a technique once to avoid being grumpy for `minutes` consecutive minutes.

**LeetCode:** 1052. Grumpy Bookstore Owner

## My Approach
I used a fixed-size sliding window to find the maximum number of additional customers who can be satisfied.

First, I calculated the customers who were already satisfied when `grumpy[i] == 0`.

Then, I calculated the extra customers saved in the first window of length `minutes`, counting only positions where `grumpy[i] == 1`.

I slid the window across the array by:
- Subtracting the outgoing customer's contribution if the outgoing minute was grumpy.
- Adding the incoming customer's contribution if the incoming minute was grumpy.
- Updating the maximum extra customers saved.

Finally, I added the already-satisfied customers to the maximum extra customers saved.

## Key Logic
1. Calculate `total`, the number of customers already satisfied.
2. Calculate `winSum`, the extra customers saved in the first window.
3. Initialize `maxExtra = winSum`.
4. Slide the fixed-size window:
   - Remove `customers[right - minutes]` if its corresponding `grumpy` value is `1`.
   - Add `customers[right]` if its corresponding `grumpy` value is `1`.
   - Update `maxExtra = max(maxExtra, winSum)`.
5. Return `total + maxExtra`.

## Solution
```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int winSum = 0, total = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                total += customers[i];
            }
        }

        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                winSum += customers[i];
            }
        }

        int maxExtra = winSum;

        for (int right = minutes; right < customers.size(); right++) {
            if (grumpy[right - minutes] == 1) {
                winSum -= customers[right - minutes];
            }

            if (grumpy[right] == 1) {
                winSum += customers[right];
            }

            maxExtra = max(maxExtra, winSum);
        }

        return total + maxExtra;
    }
};
```

## Complexity
- **Time Complexity:** `O(n)` — each array is traversed a constant number of times.
- **Space Complexity:** `O(1)` — only a constant number of extra variables are used.

## What I Learned
- Separate the contribution that is already guaranteed from the contribution that can be gained.
- Fixed-size sliding windows can efficiently find the maximum sum over consecutive elements.
- Only grumpy minutes contribute additional customers when applying the technique.
- When sliding a window, subtract the outgoing contribution and add the incoming contribution.
- The final answer is the already-satisfied total plus the maximum extra customers saved.