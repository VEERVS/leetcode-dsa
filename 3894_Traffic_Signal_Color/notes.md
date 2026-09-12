## Problem

Given an integer `timer` representing the remaining time in seconds on a traffic signal, determine the current signal color.

The rules are:

- If `timer == 0`, return `"Green"`.
- If `timer == 30`, return `"Orange"`.
- If `30 < timer <= 90`, return `"Red"`.
- Otherwise, return `"Invalid"`.

## My Approach

I used an `if-else if-else` structure to check each condition.

First, I check the two exact values:

```cpp
timer == 0
timer == 30
```

Then I check the range:

```cpp
timer > 30 && timer <= 90
```

If none of the conditions match, I return `"Invalid"`.

## Key Logic

The order of the conditions is important.

```cpp
if(timer == 0)
```

handles the Green signal.

```cpp
else if(timer == 30)
```

handles the Orange signal.

Then:

```cpp
else if(timer > 30 && timer <= 90)
```

handles every value from `31` to `90`, which represents the Red signal.

Any value outside these conditions is invalid.

For example:

```text
timer = 60

60 > 30 && 60 <= 90
        ↓
      true
        ↓
     "Red"
```

## Solution

```cpp
class Solution {
public:
    string trafficSignal(int timer) {
        if(timer == 0) {
            return "Green";
        }
        else if(timer == 30) {
            return "Orange";
        }
        else if(timer > 30 && timer <= 90) {
            return "Red";
        }
        else {
            return "Invalid";
        }
    }
};
```

## Complexity

**Time:** `O(1)`

**Space:** `O(1)`

Only a constant number of comparisons are performed regardless of the value of `timer`.

## What I Learned

- `if-else if-else` is useful for handling multiple mutually exclusive conditions.
- Exact values and ranges can be checked together.
- `&&` allows multiple conditions to be true simultaneously.
- Conditional problems with a fixed number of checks have `O(1)` time complexity.