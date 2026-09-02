## Problem

Given `n` teams in a tournament, determine the total number of matches played until one winner remains.

The tournament has special rules for odd and even numbers of teams, but every match eliminates exactly one team.

## My Approach

Instead of simulating every round, observe what happens to the number of teams.

Initially there are `n` teams.

At the end, only `1` team remains.

Every match eliminates exactly **one team**.

Therefore, the total number of matches is simply:

```text
n - 1
```

## Key Logic

```c
return n - 1;
```

For example, if:

```text
n = 7
```

The tournament goes:

```text
7 → 4 → 2 → 1
```

Number of matches:

```text
3 + 2 + 1 = 6
```

And:

```text
7 - 1 = 6
```

## Solution

```c
int numberOfMatches(int n) {
    return n - 1;
}
```

## Complexity

Time: O(1)

Space: O(1)

## What I Learned

- Don't simulate a process when a direct mathematical observation can solve it.
- Every match eliminates exactly one team.
- If `n` teams must become `1` winner, exactly `n - 1` teams must be eliminated.
- This gives an O(1) solution instead of simulating every tournament round.