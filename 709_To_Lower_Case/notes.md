## Problem

Given a string `s`, return the string after replacing every uppercase letter with its corresponding lowercase letter.

Examples:

- `"Hello"` → `"hello"`
- `"here"` → `"here"`
- `"LOVELY"` → `"lovely"`

## My Approach

I used JavaScript's built-in `toLowerCase()` method.

It automatically converts every uppercase letter in the string to lowercase while keeping characters that are already lowercase unchanged.

## Key Logic

The main operation is:

```js
s.toLowerCase()
```

Examples:

```text
"Hello".toLowerCase() → "hello"
"LOVELY".toLowerCase() → "lovely"
"here".toLowerCase() → "here"
```

There is no need to manually traverse the string because JavaScript already provides the required string operation.

## Solution

```js
var toLowerCase = function(s) {
    return s.toLowerCase();
};
```

## Complexity

Let `n` be the length of the string.

- Time: `O(n)`
- Space: `O(n)` for the resulting string

## What I Learned

- JavaScript has built-in methods for common string operations.
- `toLowerCase()` converts uppercase characters to lowercase.
- Built-in methods can make simple string problems much cleaner.
- I don't always need to manually implement an operation when the language already provides it.