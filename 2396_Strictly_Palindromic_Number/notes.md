## Problem

An integer `n` is strictly palindromic if its representation is a palindrome in every base `b` from `2` to `n - 2`.

Return `true` if `n` is strictly palindromic, otherwise return `false`.

## My Approach

Initially, the problem looks like we need to:
- convert `n` into every base from `2` to `n - 2`
- check whether each representation is a palindrome.

But there is a mathematical observation that eliminates all of that.

We only need to find **one base** where `n` is not palindromic.

Choose the largest required base:

```text
b = n - 2
```

Now:

```text
n = (n - 2) + 2
```

Therefore:

```text
n = 1 × (n - 2) + 2
```

So in base `n - 2`, the representation of `n` is always:

```text
12
```

And `12` is not a palindrome.

Therefore, `n` can never be strictly palindromic.

## Key Logic

For example, if:

```text
n = 9
```

choose:

```text
base = 9 - 2 = 7
```

Then:

```text
9 = 1 × 7 + 2
```

So:

```text
9 = 12₇
```

`12` is not a palindrome.

Therefore:

```text
false
```

The same argument works for every valid `n`.

## Solution

```c
bool isStrictlyPalindromic(int n) {
    return false;
}
```

## Complexity

- Time: `O(1)`
- Space: `O(1)`

## What I Learned

- A universal condition ("must work for every base") can be disproved by finding one guaranteed counterexample.
- Choosing `base = n - 2` gives a representation of `12`.
- This problem is a great example of mathematical observation replacing brute force.
- Not every Medium problem requires complicated code. Sometimes the hardest part is recognizing the pattern.