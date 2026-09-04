## Problem

Given a valid IPv4 address, return its defanged version.

A defanged IP address replaces every period `.` with `[.]`.

For example:

```text
"1.1.1.1" → "1[.]1[.]1[.]1"
```

## My Approach

Since the problem only asks us to replace every `.` in the string with `[.]`, I used JavaScript's built-in `replaceAll()` method.

```js
address.replaceAll('.', '[.]')
```

`replaceAll()` replaces every occurrence of the specified character/string.

So instead of manually traversing the string, I can directly perform the replacement and return the resulting string.

## Key Logic

The main JavaScript method used is:

```js
replaceAll(oldValue, newValue)
```

For this problem:

```js
address.replaceAll('.', '[.]')
```

This means:

```text
Find every "." 
        ↓
Replace it with "[.]"
```

Example:

```text
"255.100.50.0"

        ↓

"255[.]100[.]50[.]0"
```

## Solution

```js
var defangIPaddr = function(address) {
    return address.replaceAll('.', '[.]');
};
```

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the resulting string.

## What I Learned

- This is my first JavaScript LeetCode problem.
- JavaScript provides useful built-in string methods that can greatly simplify string problems.
- `replaceAll()` replaces every occurrence of a value in a string.
- Unlike C, I don't need to manually traverse the string character by character for simple replacement operations.
- The syntax for calling a string method is:

```js
string.method(arguments)
```

For this problem:

```js
address.replaceAll('.', '[.]')
```