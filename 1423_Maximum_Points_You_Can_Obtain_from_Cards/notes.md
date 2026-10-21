## Problem
Given an integer array `cardPoints` and an integer `k`, take exactly `k` cards from either the beginning or the end of the array.

Return the maximum possible sum of the selected cards.

## My Approach
Instead of checking every combination of cards taken from the two ends, I calculated the total sum of all cards and found the minimum sum of a contiguous window of size `n - k`.

The cards left unselected always form one contiguous middle segment. Minimizing the sum of these leftover cards maximizes the score of the selected cards.

## Key Logic
- Calculate `n = cardPoints.size()`.
- The leftover window size is `n - k`.
- Calculate the total sum of the array.
- Calculate the sum of the first `n - k` elements.
- Slide the window through the array:
  - Add the incoming element `cardPoints[i]`.
  - Remove the outgoing element `cardPoints[i - windowSize]`.
  - Update the minimum window sum.
- Return `totalSum - minSum`.

If `k == n`, the window size is zero, so the answer is the total sum.

## Solution
```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int winSize = n - k;
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }

        if (winSize == 0) {
            return total;
        }

        int winSum = 0;

        for (int i = 0; i < winSize; i++) {
            winSum += cardPoints[i];
        }

        int minSum = winSum;

        for (int i = winSize; i < n; i++) {
            winSum = winSum + cardPoints[i]
                           - cardPoints[i - winSize];

            minSum = min(minSum, winSum);
        }

        return total - minSum;
    }
};
```

## Complexity
- Time: `O(n)`.
- Auxiliary space: `O(1)`.

## What I Learned
- The window size is not always `k`; it depends on what the window represents.
- Taking `k` cards from the ends leaves `n - k` consecutive cards in the middle.
- Maximizing the selected sum is equivalent to minimizing the leftover sum.
- The rolling-window update is `winSum += incoming - outgoing`.
- If the window size is zero, no cards are left behind.