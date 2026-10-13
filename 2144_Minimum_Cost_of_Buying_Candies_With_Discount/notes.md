## Problem

A shop is selling candies at a discount. For every two candies bought, the customer gets a third candy for free.

The free candy must have a cost less than or equal to the minimum cost of the two candies bought.

Given a 0-indexed integer array `cost`, return the minimum cost of buying all the candies.

## My Approach

I sort the `cost` array in descending order so that the most expensive candies come first.

After sorting, I traverse the array using an index `i`.

For every group of three candies:

- The first two candies are paid for.
- The third candy is free.

Therefore, I skip the elements at indices where `i % 3 == 2` and add the costs of all other candies to `sum`.

This works because buying the two most expensive candies in each group makes the third, cheapest candy free while satisfying the discount condition.

## Key Logic

Sort the array in descending order:

```cpp
sort(cost.begin(), cost.end(), greater<int>());
```

Skip every third candy:

```cpp
if(i % 3 == 2) {
    continue;
}
```

Add the costs of the remaining candies:

```cpp
sum += cost[i];
```

**Example:**

```text
Input:  [1,2,3]
Sorted: [3,2,1]

3 and 2 are paid for.
1 is free.

Minimum cost = 3 + 2 = 5
Output: 5
```

## Solution

```cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum = 0;

        sort(cost.begin(), cost.end(), greater<int>());

        for(int i = 0; i < cost.size(); i++) {
            if(i % 3 == 2) {
                continue;
            }

            sum += cost[i];
        }

        return sum;
    }
};
```

## Complexity

- **Time:** `O(n log n)` because sorting takes `O(n log n)` and the traversal takes `O(n)`.
- **Space:** Typically `O(log n)` auxiliary stack space for `std::sort`, excluding the input array.

## What I Learned

- Sorting in descending order helps apply the discount optimally.
- `greater<int>()` sorts elements from largest to smallest.
- The modulo operator `%` helps identify every third element.
- For every three candies, the two most expensive are paid for and the cheapest is free.
- Greedy algorithms make locally optimal choices to achieve the overall minimum cost.