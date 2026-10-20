## Problem
Given a string `blocks` containing `B` (black) and `W` (white), and an integer `k`, return the minimum number of white blocks that must be recolored black to obtain at least `k` consecutive black blocks.

## My Approach
I counted the white blocks in the first window of size `k` and initialized `minRecolors` with that count.

Then I slid the window through the string. Whenever a white block entered the window, I incremented `wCount`. Whenever a white block left the window, I decremented `wCount`.

After every slide, I updated the minimum number of recolors needed.

## Key Logic
- Count the white blocks in the first `k` characters.
- Initialize `minRecolors = wCount`.
- Start the sliding loop at `i = k`.
- Add one if the incoming character `blocks[i]` is `W`.
- Subtract one if the outgoing character `blocks[i-k]` is `W`.
- Update the minimum using `min(minRecolors, wCount)`.

The number of recolors required for a window equals the number of white blocks in that window.

## Solution
```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wCount = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                wCount++;
            }
        }

        int minRecolors = wCount;

        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                wCount++;
            }

            if (blocks[i-k] == 'W') {
                wCount--;
            }

            minRecolors = min(minRecolors, wCount);
        }

        return minRecolors;
    }
};
```

## Complexity
- Time: `O(n)`.
- Auxiliary space: `O(1)`.

## What I Learned
- Counting the unwanted elements in a fixed-size window can solve minimization problems.
- Here, white blocks are the unwanted elements.
- Adding the incoming element and removing the outgoing element maintains the correct count.
- Taking the minimum across all windows gives the optimal answer.
- The same sliding-window pattern can solve different problems by changing what we track.