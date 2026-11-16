# 2243. Calculate Digit Sum of a String

## Problem
Given a numeric string `s` and an integer `k`, repeatedly perform the following operation while the length of `s` is greater than `k`:

1. Divide the string into consecutive groups of size `k`. The last group may contain fewer than `k` characters.
2. Calculate the sum of digits in each group.
3. Replace each group with its digit sum represented as a string.
4. Concatenate the resulting strings to form the new string.

Return the final string after all rounds are completed.

## My Approach
Used string simulation with nested loops.

1. Continue processing while `s.length() > k`.
2. Create an empty string `next_s` to store the result of the current round.
3. Divide the string into consecutive groups of size `k`.
4. For each group:
   - Initialize `sum = 0`.
   - Traverse its characters.
   - Convert each character into its numeric value using `s[j] - '0'`.
   - Add the values to `sum`.
5. Convert the group sum into a string using `to_string(sum)`.
6. Append it to `next_s`.
7. Replace `s` with `next_s` and repeat until its length is at most `k`.
8. Return `s`.

## Key Logic
- `i += k`: Moves to the next group.
- `j < i + k && j < s.length()`: Ensures the group does not exceed the string boundaries.
- `s[j] - '0'`: Converts a digit character into its integer value.
- `to_string(sum)`: Converts the calculated sum back into a string.
- `s = next_s`: Updates the string after completing one full round.

## Solution

```cpp
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_s = "";

            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;

                for (int j = i; j < i + k && j < s.length(); j++) {
                    sum += s[j] - '0';
                }

                next_s += to_string(sum);
            }

            s = next_s;
        }

        return s;
    }
};
```

## Complexity
- **Time Complexity:** O(n log_k n) — Each round processes the current string once, and the string length decreases by at least a factor of approximately `k` for `k > 1`.
- **Space Complexity:** O(n) — A new string is created to store the result of each round.

## What I Learned
- How to divide a string into consecutive groups.
- How to convert digit characters into integers using `s[i] - '0'`.
- How to convert integers back into strings using `to_string()`.
- How to simulate repeated operations until a stopping condition is reached.
- How nested loops can process groups within a string.