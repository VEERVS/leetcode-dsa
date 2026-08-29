## Problem

Given a temperature in Celsius, convert it into Kelvin and Fahrenheit and return both values in an array.

Formulas:

```text
Kelvin = Celsius + 273.15
Fahrenheit = Celsius × 1.80 + 32.00
```

## My Approach

Calculate both temperatures directly using the given formulas.

Since the answer must be returned as an array, dynamically allocate space for 2 `double` values using `malloc()`.

Store:

```text
array[0] → Kelvin
array[1] → Fahrenheit
```

## Key Logic

```c
k = celsius + 273.15;
f = celsius * 1.80 + 32.00;

array[0] = k;
array[1] = f;
```

Since the returned array has exactly 2 elements:

```c
*returnSize = 2;
```

## Solution

```c
double* convertTemperature(double celsius, int* returnSize) {
    *returnSize = 2;

    double k, f;
    double *array = malloc(2 * sizeof(double));

    k = celsius + 273.15;
    f = celsius * 1.80 + 32.00;

    array[0] = k;
    array[1] = f;

    return array;
}
```

## Complexity

**Time:** O(1) — only two calculations are performed.

**Space:** O(1) — only 2 `double` values are allocated.

## What I Learned

- Temperature conversion can be done directly using mathematical formulas.
- `double` is used because the calculations contain decimal values.
- `malloc()` can allocate memory for an array of `double`.
- `sizeof(double)` ensures the correct amount of memory is allocated.
- `returnSize` tells LeetCode that the returned array contains 2 elements.
- Reused the dynamic-array technique learned from **Two Sum**.