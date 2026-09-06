## Problem

Given a lowercase string `s`, calculate its reverse degree.

In the reversed alphabet:

`a = 26, b = 25, ..., z = 1`

For every character, multiply its reversed alphabet value by its 1-indexed position in the string.

Return the sum of all these products.

## My Approach

I traversed the string from left to right.

For each character, I converted it into its normal alphabet index using:

`s[i] - 'a'`

This gives:

`a = 0, b = 1, ..., z = 25`

To get the reversed alphabet value, I used:

`26 - (s[i] - 'a')`

I then multiplied this value by `i + 1` because the string positions are 1-indexed.

Finally, I added everything to `sum`.

## Key Logic

The expression:

`26 - (s[i] - 'a')`

converts the normal alphabet position into the reversed alphabet position.

For example:

`'a' - 'a' = 0`

so:

`26 - 0 = 26`

For `c`:

`'c' - 'a' = 2`

so:

`26 - 2 = 24`

The final contribution is:

`reversedValue * (i + 1)`

## Solution

```c
int reverseDegree(char* s) {
    int sum = 0, i;

    for(i = 0; s[i] != '\0'; i++) {
        sum += (26 - (s[i] - 'a')) * (i + 1);
    }

    return sum;
}
```

## Complexity

Time: `O(n)`

Space: `O(1)`

## What I Learned

I learned how ASCII character arithmetic can be used to convert lowercase letters into numerical alphabet positions.

I also learned the importance of correctly checking the null terminator in a C string:

`s[i] != '\0'`

A small mistake in the loop condition caused my earlier solution to stop before reaching the end of a long string.