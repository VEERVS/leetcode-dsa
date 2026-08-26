## Problem

Given an array `hours` representing the number of hours each employee worked and an integer `target`, return the number of employees who worked at least `target` hours.

Example:

```text
hours = [0,1,2,3,4], target = 2

Employees with hours >= 2:
2, 3, 4

Answer = 3
```

## My Approach

Traverse the array once and check whether each employee's hours are greater than or equal to `target`.

If:

```c
hours[i] >= target
```

increment the count.

## Solution

```c
int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target) {

    int count = 0;

    for(int i = 0; i < hoursSize; i++) {
        if(hours[i] >= target) {
            count++;
        }
    }

    return count;
}
```

## Complexity

**Time:** O(n) — each element is checked once.

**Space:** O(1) — only the counter and loop variable are used.

## What I Learned

- Some problems are already optimal with a simple linear scan.
- Don't overcomplicate an easy problem looking for a mathematical optimization.
- `>=` is important because employees who worked exactly `target` hours also count.