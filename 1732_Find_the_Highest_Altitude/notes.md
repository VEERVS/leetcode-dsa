## Problem

There is a biker traveling through a road trip with `n + 1` points.

The biker starts at altitude `0`, and `gain[i]` represents the net change in altitude between point `i` and point `i + 1`.

Return the highest altitude reached during the trip.

## My Approach

I first created a vector `ans` and stored the starting altitude `0`.

Then I maintained a variable `sum` to represent the current altitude.

For every value in `gain`, I added it to `sum` and stored the resulting altitude in `ans`.

After generating all the altitudes, I used `max_element()` to find the highest altitude.

For example:

`gain = [-5, 1, 5, 0, -7]`

The altitudes become:

`[0, -5, -4, 1, 1, -6]`

So the highest altitude is `1`.

## Key Logic

The current altitude can be calculated using a running sum:

`current altitude = previous altitude + gain[i]`

Starting from `0`, repeatedly adding each gain gives the altitude at every point.

Then the maximum value among those altitudes is the answer.

## Solution

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        ans.push_back(0);

        int sum = 0;

        for(int i = 0; i < gain.size(); i++) {
            sum += gain[i];
            ans.push_back(sum);
        }

        int max = *max_element(ans.begin(), ans.end());

        return max;
    }
};
```

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I Learned

- A running sum can be used to track changes over a sequence.
- The starting value must be included because the biker begins at altitude `0`.
- `max_element()` can find the maximum value in a vector.
- This problem is a simple application of prefix sums.