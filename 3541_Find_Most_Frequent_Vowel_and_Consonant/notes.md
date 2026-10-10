## Problem

Given a string `s` containing lowercase English letters, find:

1. The maximum frequency of any vowel (`a`, `e`, `i`, `o`, `u`).
2. The maximum frequency of any consonant.

Return the sum of these two maximum frequencies.

If there are no vowels or no consonants, their corresponding maximum frequency is `0`.

## My Approach

I created two hash maps:

- `vowels` stores frequencies of vowels.
- `conso` stores frequencies of consonants.

I traverse the string and classify each character as either a vowel or a consonant. Then I traverse both maps to find their maximum frequencies.

Finally, I return the sum of the two maximum frequencies.

## Key Logic

First, classify each character:

```cpp
if(c == 'a' || c == 'e' || c == 'i' ||
   c == 'o' || c == 'u'){
    vowels[c]++;
}
else{
    conso[c]++;
}
```

Next, find the maximum frequency in each map:

```cpp
int max1 = 0;
int max2 = 0;

for(auto& c : vowels){
    max1 = max(max1, c.second);
}

for(auto& c : conso){
    max2 = max(max2, c.second);
}
```

Here, `c.second` represents the frequency stored in the map.

Finally:

```cpp
return max1 + max2;
```

## Solution

```cpp
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char, int> conso;

        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u'){
                vowels[c]++;
            }
            else{
                conso[c]++;
            }
        }

        int max1 = 0;
        int max2 = 0;

        for(auto& c : vowels){
            max1 = max(max1, c.second);
        }

        for(auto& c : conso){
            max2 = max(max2, c.second);
        }

        return max1 + max2;
    }
};
```

## Complexity

- **Time:** `O(n)` average
- **Space:** `O(1)` because each map can contain at most 26 distinct lowercase letters.

## What I Learned

- Multiple hash maps can track different categories of data.
- Character classification can be performed during a single traversal.
- In a map, `.first` represents the key and `.second` represents the value.
- `max(currentMaximum, frequency)` updates the maximum efficiently.
- Initializing maximum frequencies to `0` naturally handles a missing category.