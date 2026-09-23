## Problem

Given an integer `n`, return any array containing `n` **unique integers** such that they add up to `0`.

For example, for `n = 5`, one valid answer is:

`[-2, -1, 0, 1, 2]`

All numbers are unique and their sum is `0`.

## My Approach

I used a simple symmetric approach.

I loop from `-n/2` to `n/2` and add every number to the answer.

- For **odd `n`**, this naturally gives a symmetric set containing `0`.
- For **even `n`**, the range would contain `0` and have one extra number, so I skip `0`.

The positive and negative numbers cancel each other:

`-2 + (-1) + 0 + 1 + 2 = 0`

For an even value like `n = 4`:

`-2 + (-1) + 1 + 2 = 0`

## Key Logic

```cpp
for(int i = -n/2; i <= n/2; i++) {
    if(n % 2 == 0 && i == 0) {
        continue;
    }

    ans.push_back(i);
}
```

The important idea is **symmetry**.

Every positive number has its corresponding negative number:

```text
-3 + 3 = 0
-2 + 2 = 0
-1 + 1 = 0
```

So the total sum automatically becomes `0`.

The `0` is only skipped when `n` is even because an even-sized answer cannot contain the center `0` while maintaining the required number of elements.

## Solution

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        for(int i = -n/2; i <= n/2; i++) {
            if(n % 2 == 0 && i == 0) {
                continue;
            }

            ans.push_back(i);
        }

        return ans;
    }
};
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the returned array

## What I Learned

- Symmetry can make sum problems extremely simple.
- Pairing `x` with `-x` automatically makes their sum `0`.
- For odd `n`, we can include `0`.
- For even `n`, we skip `0` and use equal numbers of positive and negative values.
- The `continue` statement is useful when one specific value needs to be skipped while keeping the loop structure simple.