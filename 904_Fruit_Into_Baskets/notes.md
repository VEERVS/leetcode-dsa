## Problem

Given an integer array `fruits`, return the maximum number of fruits that can be collected from a contiguous range of trees.

You have two baskets, and each basket can hold only one type of fruit. Therefore, the selected range can contain at most two distinct fruit types.

## My Approach

Use a variable-size sliding window with an `unordered_map<int, int>` to track the frequency of each fruit type.

Expand the window by moving `right` forward and adding the current fruit to the map.

If the map contains more than two distinct fruit types, shrink the window from the left until only two types remain.

Update the maximum window length after each valid window.

## Key Logic

- Add the current fruit using `mp[fruits[right]]++`.
- Check whether the number of distinct types exceeds two using `mp.size() > 2`.
- Decrease the frequency of the outgoing fruit when shrinking.
- Erase a fruit type when its frequency reaches zero.
- Update the answer using `ans = max(ans, right - left + 1)`.

Example: `[1, 2, 1, 2, 3]`

The longest valid window is `[1, 2, 1, 2]`, containing four fruits and two distinct types.

## Solution

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, left = 0;
        unordered_map<int, int> mp;

        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
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

- Time: O(n) average, because each element enters and leaves the window at most once.
- Space: O(1) auxiliary space under the two-distinct-types constraint; the map contains at most three types momentarily before shrinking.

## What I Learned

- How to use a frequency map to track distinct elements in a sliding window.
- Why `mp.size()` represents the number of distinct fruit types.
- Why an entry should be erased when its frequency reaches zero.
- How to find the longest contiguous range satisfying a limit on distinct values.