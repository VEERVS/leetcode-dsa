# 1282. Group the People Given the Group Size They Belong To

## Problem
There are `n` people, each identified by a unique ID from `0` to `n-1`.

Given an integer array `groupSizes`, where `groupSizes[i]` represents the required group size for person `i`, divide everyone into groups such that:

- Each person belongs to exactly one group.
- Every group contains exactly the required number of people for its members.

Return any valid grouping.

## My Approach
Used an `unordered_map` to temporarily group people according to their required group size.

1. Create a result vector to store completed groups.
2. Create an unordered map where the key represents the required group size and the value stores people waiting to form that group.
3. Traverse every person using index `i`.
4. Get their required group size using `groupSizes[i]`.
5. Add the person's ID to the corresponding group in the map.
6. Whenever the temporary group's size becomes equal to its required size:
   - Move that group into the result.
   - Clear the temporary group so it can collect people for the next group of the same size.
7. Return the completed groups.

## Key Logic
- `groups[size].push_back(i)`: Adds person `i` to the group requiring `size` members.
- `groups[size].size() == size`: Checks whether the group is complete.
- `result.push_back(move(groups[size]))`: Transfers the completed group into the result without copying its elements.
- `groups[size].clear()`: Resets the temporary group for the next group of the same size.

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];

            groups[size].push_back(i);

            if (groups[size].size() == size) {
                result.push_back(move(groups[size]));
                groups[size].clear();
            }
        }

        return result;
    }
};
```

## Complexity
- **Time Complexity:** O(n) — Every person is processed once. Insertion and group completion operations take O(1) amortized time per person.
- **Space Complexity:** O(n) — The map and result together store all n people.

## What I Learned
- How to use an unordered map with vectors as values.
- How to group elements based on a common property.
- How to detect when a group has reached its required size.
- How `move()` transfers a vector into the result efficiently.
- How to reuse a temporary group after clearing it.