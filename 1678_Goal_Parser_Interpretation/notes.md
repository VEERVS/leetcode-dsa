## Problem

Given a string `command`, interpret it according to these rules:

- `G` becomes `G`
- `()` becomes `o`
- `(al)` becomes `al`

Return the final interpreted string.

## My Approach

I used JavaScript's built-in `replaceAll()` method.

First I replaced every `()` with `o`.

Then I replaced every `(al)` with `al`.

The resulting string is returned.

## Key Logic

JavaScript strings are immutable, so `replaceAll()` does not directly modify the original string.

It returns a new string.

Therefore I assigned the result back to `command`:

`command = command.replaceAll('()', 'o')`

and then performed the second replacement.

## Solution

```javascript
var interpret = function(command) {
    command = command.replaceAll('()', 'o');
    command = command.replaceAll('(al)', 'al');
    return command;
};
```

## Complexity

Time: `O(n)`

Space: `O(n)`

## What I Learned

I learned how to use JavaScript's `replaceAll()` method for string manipulation.

I also learned that JavaScript strings are immutable, so methods that return modified strings need to be assigned back to a variable.

This was another step in getting comfortable with solving string problems in JavaScript.