## Problem

Given an integer `n`, return a string array according to the following rules:

- If `i` is divisible by both `3` and `5`, add `"FizzBuzz"`.
- If `i` is divisible by `3`, add `"Fizz"`.
- If `i` is divisible by `5`, add `"Buzz"`.
- Otherwise, add the number itself as a string.

The array should contain results for every number from `1` to `n`.

## My Approach

I loop from `1` to `n`.

For every number, I check the conditions in order:

1. First check whether it is divisible by both `3` and `5`.
2. Otherwise, check whether it is divisible by `3`.
3. Otherwise, check whether it is divisible by `5`.
4. If none of these conditions are true, convert the number to a string using `to_string()`.

The `"FizzBuzz"` condition is checked first because numbers divisible by both `3` and `5` would otherwise match the individual conditions.

## Key Logic

The order of the conditions is important.

For example, `15` is divisible by both `3` and `5`.

If we checked `i % 3 == 0` first, `15` would become `"Fizz"` instead of `"FizzBuzz"`.

So the combined condition must come first:

`i % 3 == 0 && i % 5 == 0`

For normal numbers, `to_string(i)` converts the integer into the required string.

## Solution

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }
            else if(i % 3 == 0) {
                ans.push_back("Fizz");
            }
            else if(i % 5 == 0) {
                ans.push_back("Buzz");
            }
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the output vector

## What I Learned

- The order of `if-else` conditions can be important.
- Multiple conditions can be combined using `&&`.
- `to_string()` converts an integer into a `string`.
- This is a good example of straightforward conditional logic and simulation.