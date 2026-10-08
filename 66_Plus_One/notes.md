## Problem

You are given a large integer represented as an array of digits.

Each element represents one digit of the number, from the most significant digit to the least significant digit.

Increment the number by `1` and return the resulting array.

## My Approach

I start from the last digit because addition begins from the least significant digit.

For each digit:

- If it is `9`, changing it to `0` creates a carry that must continue to the previous digit.
- Otherwise, increment it by `1` and immediately return the result because there is no carry left.

If every digit was `9`, all digits become `0`. In that case, I insert `1` at the beginning.

## Key Logic

Start from the last index:

```cpp
for(int i = n - 1; i >= 0; i--)
```

If the current digit is `9`:

```cpp
digits[i] = 0;
```

The carry continues to the left.

Otherwise:

```cpp
digits[i] += 1;
return digits;
```

For example:

```text
[1,2,9]
```

Process from right:

```text
9 → 0
2 → 3
```

Result:

```text
[1,3,0]
```

For:

```text
[9,9,9]
```

every digit becomes `0`:

```text
[0,0,0]
```

So we insert `1` at the beginning:

```text
[1,0,0,0]
```

## Solution

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n - 1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else{
                digits[i] += 1;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)` auxiliary space, excluding the output array.

In the worst case, we traverse all `n` digits.

## What I Learned

- Addition to a digit array should start from the **rightmost digit**.
- `9 + 1` produces `0` with a carry.
- If a digit is less than `9`, incrementing it ends the carry chain.
- Returning immediately avoids unnecessary traversal.
- The all-`9` case requires inserting a new leading `1`.
- This is essentially **manual carry propagation**, just like normal addition.