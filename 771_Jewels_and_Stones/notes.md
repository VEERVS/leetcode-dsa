## Problem

Given a string `jewels` representing the types of stones that are jewels and a string `stones` representing the stones we have, return the number of stones that are also jewels.

Each character in `stones` represents one stone.

## My Approach

I stored the characters from `jewels` in an `unordered_map`.

Then I traversed every character in `stones`.

If the current stone exists in the frequency map, it is a jewel, so I increment the count.

The important realization was that we need to count **every matching stone**, not just every jewel type.

## Key Logic

Store the jewel characters:

```cpp
for(char c : jewels){
    freq[c]++;
}
```

Then check every stone:

```cpp
for(char c : stones){
    if(freq[c] > 0){
        count++;
    }
}
```

For example:

```text
jewels = "aA"
stones = "aAAbbbb"
```

The three matching stones are:

```text
a, A, A
```

So the answer is `3`.

## Solution

```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_map<char, int> freq;

        for(char c : jewels){
            freq[c]++;
        }

        for(char c : stones){
            if(freq[c] > 0){
                count++;
            }
        }

        return count;
    }
};
```

## Complexity

- **Time:** `O(n + m)`
- **Space:** `O(1)`

There are only 52 possible English letters, so the map has bounded size.

## What I Learned

- We must identify whether each **stone** is a jewel, rather than counting jewel types.
- `unordered_map` can also be used as a simple existence lookup.
- Frequency maps are useful even when we only care whether a key exists.
- An `unordered_set` would also be a natural choice when only existence matters.