## Problem

Given:
- `order`, containing every participant ID in their finishing order.
- `friends`, containing only the IDs of our friends.

Return the IDs of the friends in the same finishing order as they appear in `order`.

## My Approach

I noticed that `order` already contains everyone in the correct finishing order.

So I simply scan `order` from left to right.

For every element in `order`, I check whether that ID exists in `friends`.

If it does, I add it to the answer.

This automatically preserves the finishing order.

## Key Logic

For:

```text
order   = [3, 1, 2, 5, 4]
friends = [1, 3, 4]
```

Scan `order`:

```text
3 → friend → ans = [3]
1 → friend → ans = [3, 1]
2 → not a friend
5 → not a friend
4 → friend → ans = [3, 1, 4]
```

Therefore:

```text
ans = [3, 1, 4]
```

The important observation is that **we don't need to sort anything**. The `order` array is already sorted according to finishing position.

## Solution

```c
int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
    *returnSize = friendsSize;

    int *ans = malloc((*returnSize) * sizeof(int));
    int k = 0;

    for(int i = 0; i < orderSize; i++) {
        for(int j = 0; j < friendsSize; j++) {
            if(order[i] == friends[j]) {
                ans[k] = friends[j];
                k++;
                break;
            }
        }
    }

    return ans;
}
```

## Complexity

- Time: `O(orderSize × friendsSize)`
- Space: `O(friendsSize)` for the returned array.

## What I Learned

- When one array is already in the required order, don't unnecessarily sort it.
- A simple nested search can be enough when the constraints allow it.
- `break` is useful once the required match has been found.
- The main problem-solving step was identifying that I only needed to **filter `order` using `friends`**.