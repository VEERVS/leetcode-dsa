## Problem

Given an integer `x`, return `true` if `x` is a palindrome, otherwise return `false`.

A palindrome reads the same forward and backward.

Example:

```text
121 → true
123 → false
```

## My Approach

My first approach was to reverse the entire number and compare it with the original.

For each digit:

```c
rem = temp % 10;
rev = rev * 10 + rem;
temp /= 10;
```

Then:

```c
return rev == x;
```

Negative numbers are immediately rejected because they cannot be palindromes.

## Key Logic

```text
12321
↓
reverse
↓
12321

12321 == 12321
→ true
```

The `% 10` operation extracts the last digit, `/ 10` removes it, and `rev * 10 + digit` builds the reversed number.

## My Original Solution

```c
bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    } else {
        long long rem, rev = 0, temp = x;

        while(temp != 0) {
            rem = temp % 10;
            rev = (rev * 10) + rem;
            temp /= 10;
        }

        return rev == x;
    }
}
```

## Optimization — Reverse Only Half

I later learned that the entire number doesn't need to be reversed.

For a palindrome, we only need to compare the left half with the reversed right half.

Example:

```text
1221
 ↓
12 | 21
     ↓
12 | 12
```

For odd-length numbers, the middle digit can be ignored:

```text
12321
 ↓
12 | 321
     ↓
12 | 123
```

So compare:

```text
x == rev
```

for even digits, or:

```text
x == rev / 10
```

for odd digits.

The loop stops when `x <= rev`, meaning we have reached the middle.

## Optimized Solution

```c
bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int rev = 0;

    while(x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return x == rev || x == rev / 10;
}
```

## Complexity

**Original:**  
Time: O(log n)  
Space: O(1)

**Half-reversal:**  
Time: O(log n)  
Space: O(1)

The half-reversal approach still has the same Big-O complexity, but processes only about half the digits and avoids reversing the entire number.

## What I Learned

- `% 10` extracts the last digit.
- `/ 10` removes the last digit.
- `rev * 10 + digit` builds a reversed number.
- A loop can stop at the halfway point instead of processing the entire number.
- `x % 10 == 0` helps identify numbers that cannot be palindromes.
- Two solutions can have the same Big-O but one can still do less work.