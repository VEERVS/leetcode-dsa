## Problem

Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`s in the array if we can flip at most `k` zeros into ones.

Example:

```text
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
```

We can flip two zeros to `1`, giving a longest valid subarray of length `6`.

## My Approach

I used the **sliding window / two-pointer technique**.

The window represents a subarray that can be converted completely into `1`s using at most `k` flips.

I maintain:

- `left` → starting point of the window
- `right` → ending point of the window
- `zeros` → number of zeros currently inside the window
- `ans` → maximum valid window length found

For every `right`:

1. If `nums[right] == 0`, increase `zeros`.
2. If `zeros > k`, the window is invalid.
3. Move `left` forward until the number of zeros becomes at most `k`.
4. Update the maximum window length.

## Key Logic

```cpp
if(nums[right] == 0) {
    zeros++;
}

while(zeros > k) {
    if(nums[left] == 0) {
        zeros--;
    }

    left++;
}

ans = max(ans, right - left + 1);
```

The important idea is that we don't actually flip the zeros.

We only count how many zeros are inside the current window.

If there are at most `k` zeros, all of them **could** be flipped, so the entire window can become consecutive `1`s.

### Example

```text
nums = [1,1,0,0,1]
k = 1
```

Start expanding:

```text
[1]          zeros = 0
[1,1]        zeros = 0
[1,1,0]      zeros = 1
```

We can still use this window because:

```text
zeros <= k
```

Next:

```text
[1,1,0,0]
```

Now:

```text
zeros = 2 > k
```

So we move `left` forward until one zero leaves the window.

This keeps the window valid.

## Solution

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0;
        int zeros = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) {
                zeros++;
            }

            while(zeros > k) {
                if(nums[left] == 0) {
                    zeros--;
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

## Complexity

- Time: `O(n)`
- Space: `O(1)`

Each element enters the window once and leaves the window at most once.

## What I Learned

- Sliding window is useful when we need the longest/shortest subarray satisfying a condition.
- We don't need to actually perform the zero-to-one flips.
- We only need to track how many zeros are inside the current window.
- `zeros <= k` means the current window can be made entirely of `1`s.
- When `zeros > k`, move `left` forward until the window becomes valid again.
- `right - left + 1` gives the current window length.
- This converts what could be an `O(n²)` brute-force approach into an `O(n)` solution.