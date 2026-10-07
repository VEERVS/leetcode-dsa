## Problem

Given an array of strings `operations`, each operation increments or decrements the value of a variable `X`.

Initially:

```text
X = 0
```

Return the final value of `X` after performing all operations.

## My Approach

I created an integer `ans` initialized to `0`.

Then I traversed every operation and checked which operation was performed.

- `"--X"` and `"X--"` decrease the value by `1`.
- `"++X"` and `"X++"` increase the value by `1`.

After processing all operations, I return `ans`.

## Key Logic

Decrement operations:

```cpp
if(x == "--X"){
    --ans;
}

if(x == "X--"){
    ans--;
}
```

Increment operations:

```cpp
if(x == "++X"){
    ++ans;
}

if(x == "X++"){
    ans++;
}
```

The position of `++` or `--` does not matter here because we only need the final value.

## Solution

```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;

        for(auto x : operations){
            if(x == "--X"){
                --ans;
            }

            if(x == "X--"){
                ans--;
            }

            if(x == "++X"){
                ++ans;
            }

            if(x == "X++"){
                ans++;
            }
        }

        return ans;
    }
};
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)` auxiliary space.

We process every operation exactly once.

## What I Learned

- String comparison can directly identify different operations.
- Prefix and postfix increment/decrement both have the same effect here because we only care about the final value.
- A simple simulation is enough when each operation has a direct effect.
- The problem can be solved with a single pass through the array.