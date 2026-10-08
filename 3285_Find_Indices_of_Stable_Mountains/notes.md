## Problem

Given an array `height` where `height[i]` represents the height of mountain `i`, and an integer `threshold`, find all indices of stable mountains.

A mountain at index `i` is stable if the mountain immediately before it has a height strictly greater than `threshold`.

Mountain `0` is never stable because it has no previous mountain.

## My Approach

I start from index `1` because index `0` cannot be stable.

For every index `i`, I check the previous mountain:

```cpp
height[i - 1]
```

If its height is greater than `threshold`, then index `i` is stable and I add it to the answer.

## Key Logic

The condition for a stable mountain is:

```cpp
if(height[i - 1] > threshold)
```

Notice that we are checking the **previous mountain**, not the current one.

For example:

```text
height = [1,2,3,4,5]
threshold = 2
```

Check:

```text
i = 1 → height[0] = 1 → not stable
i = 2 → height[1] = 2 → not stable
i = 3 → height[2] = 3 → stable
i = 4 → height[3] = 4 → stable
```

Answer:

```text
[3,4]
```

## Solution

```cpp
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;

        for(int i = 1; i < height.size(); i++){
            if(height[i - 1] > threshold){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)` auxiliary space, excluding the output array.

We traverse the array once.

## What I Learned

- When a condition depends on the previous element, start the loop from index `1`.
- `height[i - 1]` represents the mountain immediately before index `i`.
- The first index can sometimes need special handling because it has no previous element.
- This is a simple **single-pass array traversal** pattern.