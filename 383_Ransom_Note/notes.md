## Problem

Given two strings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed using the letters from `magazine`.

Each letter in `magazine` can only be used once.

## My Approach

I used an `unordered_map` to store the frequency of every character in `magazine`.

Then I traversed `ransomNote` and tried to consume one occurrence of each required character.

- If `freq[c] == 0`, there are no remaining copies of that character → return `false`.
- Otherwise, decrease its frequency by `1`.

If every character can be constructed, return `true`.

## Key Logic

First build the frequency map:

```cpp
for(char x : magazine){
    freq[x]++;
}
```

Then consume characters from `ransomNote`:

```cpp
if(freq[x] == 0){
    return false;
}

freq[x]--;
```

The important idea is that every character from the magazine can only be used once, so its frequency must decrease when used.

## Solution

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        for(char x : magazine){
            freq[x]++;
        }

        for(char x : ransomNote){
            if(freq[x] == 0){
                return false;
            }

            freq[x]--;
        }

        return true;
    }
};
```

## Complexity

- **Time:** `O(n + m)`
- **Space:** `O(1)`

The map can contain at most 26 lowercase English characters, so its size is bounded.

## What I Learned

- `unordered_map` can be used for frequency counting.
- `freq[x]++` counts occurrences.
- Decreasing a frequency allows us to model consuming an available character.
- A frequency of `0` means that character is no longer available.
- This is a classic **frequency hashing** pattern.