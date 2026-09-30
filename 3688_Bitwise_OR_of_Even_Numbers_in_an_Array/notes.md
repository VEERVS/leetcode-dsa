## Problem

Given an integer array, return the bitwise OR of all even numbers in the array.

If there are no even numbers, return 0.

## My Approach

I iterate through the array and check whether each number is even using bit manipulation.

Instead of:

```cpp
x % 2 == 0
```

I use:

```cpp
!(x & 1)
```

The least significant bit of every even number is `0`, while every odd number has a `1`.

For every even number, I combine it with the answer using bitwise OR:

```cpp
ans |= x;
```

I initialize `ans` to `0` because:

```text
0 | x = x
```

So if there are no even numbers, the answer naturally remains `0`.

## Key Logic

```cpp
x & 1
```

checks the least significant bit.

```text
Even → ...0 → x & 1 = 0
Odd  → ...1 → x & 1 = 1
```

Therefore:

```cpp
if(!(x & 1))
```

means `x` is even.

Then:

```cpp
ans |= x;
```

sets every bit that is set in the current even number.

For `[1,2,3,4,5,6]`:

```text
2 = 010
4 = 100
6 = 110

2 | 4 | 6 = 110 = 6
```

## Solution

```cpp
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;

        for(int x : nums) {
            if(!(x & 1)) {
                ans |= x;
            }
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n)
- Space: O(1)

## What I Learned

- `x & 1` can check whether a number is odd or even.
- Even numbers have a `0` as their least significant bit.
- `|=` is useful for accumulating bits from multiple numbers.
- Starting a bitwise OR accumulator with `0` handles the empty case naturally.