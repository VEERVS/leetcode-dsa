## Problem

Given an array of three integers representing the sides of a triangle, determine whether the sides form a valid triangle.

If valid, return:

- `"equilateral"` if all three sides are equal.
- `"isosceles"` if exactly two sides are equal.
- `"scalene"` if all three sides are different.

If the sides cannot form a triangle, return `"none"`.

## My Approach

I first check the triangle inequality.

For three sides `a`, `b`, and `c`, a valid triangle must satisfy:

```text
a + b > c
a + c > b
b + c > a
```

If any condition fails, the answer is `"none"`.

If the triangle is valid, I then check the side equality:

- All three equal → `"equilateral"`
- Any two equal → `"isosceles"`
- All different → `"scalene"`

## Key Logic

The triangle inequality is the important part.

For example, `[3, 4, 5]`:

```text
3 + 4 > 5
3 + 5 > 4
4 + 5 > 3
```

So it is a valid triangle.

Since all three sides are different, the result is `"scalene"`.

Checking the triangle validity first prevents classifying invalid side combinations.

## Solution

```cpp
class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums.at(0) == nums.at(1) &&
           nums.at(0) == nums.at(2) &&
           nums.at(1) + nums.at(2) > nums.at(0)) {
            return "equilateral";
        }
        else if(nums.at(0) + nums.at(1) > nums.at(2) &&
                nums.at(0) + nums.at(2) > nums.at(1) &&
                nums.at(1) + nums.at(2) > nums.at(0)) {

            if(nums.at(0) != nums.at(1) &&
               nums.at(0) != nums.at(2) &&
               nums.at(1) != nums.at(2)) {
                return "scalene";
            }
            else {
                return "isosceles";
            }
        }
        else {
            return "none";
        }
    }
};
```

## Complexity

- Time Complexity: `O(1)`
- Space Complexity: `O(1)`

There are always exactly three sides, so the number of operations does not grow with the input size.

## What I Learned

- The triangle inequality is necessary for determining whether three sides form a triangle.
- Conditions can be combined using logical `&&`.
- Classification problems can be solved cleanly by checking validity first and type second.
- `vector::at()` can be used to access vector elements with bounds checking.