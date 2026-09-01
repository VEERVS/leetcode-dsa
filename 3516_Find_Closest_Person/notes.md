## Problem

Given three positions `x`, `y`, and `z` on a number line, determine which of Person 1 (`x`) or Person 2 (`y`) reaches Person 3 (`z`) first.

Both move at the same speed.

Return:
- `1` if Person 1 is closer.
- `2` if Person 2 is closer.
- `0` if both are equally far.

## My Approach

Calculate the distance of both people from `z` using the absolute difference.

Then compare the two distances.

## Key Logic

```c
int one = abs(x - z);
int two = abs(y - z);
```

If `one < two`, Person 1 is closer.

If `two < one`, Person 2 is closer.

Otherwise, both are at the same distance.

## Solution

```c
#include <math.h>

int findClosest(int x, int y, int z) {
    int one = abs(x - z);
    int two = abs(y - z);

    if(one < two) {
        return 1;
    }
    else if(two < one) {
        return 2;
    }
    else {
        return 0;
    }
}
```

## Complexity

Time: O(1)

Space: O(1)

## What I Learned

- Distance between two positions can be found using `abs(a - b)`.
- Since both people move at the same speed, the person with the smaller distance arrives first.
- Simple comparison problems can often be solved directly without loops.