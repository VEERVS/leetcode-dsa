## Problem

Given a function `argumentsLength`, return the number of arguments passed to it.

The function can receive any number of arguments, including values of different types.

## My Approach

I used the JavaScript **rest parameter** `...args` to collect all arguments passed to the function into an array.

Then I simply returned `args.length`, which gives the number of arguments.

## Key Logic

```js
var argumentsLength = function(...args) {
    return args.length;
};
```

- `...args` collects all passed arguments into an array.
- `args.length` gives the number of elements in that array.
- The actual values of the arguments do not matter.

For example:

```js
argumentsLength(1, 2, 3);
```

Here `args` becomes `[1, 2, 3]`, so `args.length` is `3`.

## Solution

```js
var argumentsLength = function(...args) {
    return args.length;
};
```

## Complexity

- Time Complexity: `O(1)`
- Space Complexity: `O(n)`

`n` is the number of arguments passed. The rest parameter stores those arguments in an array.

## What I Learned

- Learned how JavaScript **rest parameters (`...args`)** work.
- Rest parameters allow a function to accept any number of arguments.
- The collected arguments behave like an array, so `.length` can be used directly.
- This is much cleaner than manually counting arguments.