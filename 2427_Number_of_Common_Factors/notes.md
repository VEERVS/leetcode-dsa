## 2427. Number of Common Factors

### Problem

Given two positive integers `a` and `b`, return the number of factors that divide both `a` and `b`.

### My Approach

Find the larger number and check every number from `1` to `max`.

If a number divides both `a` and `b`, increment `count`.

### Key Logic

if(a % i == 0 && b % i == 0)
    count++;

### Optimized Approach

First find the **GCD** of `a` and `b`.

Every common factor of `a` and `b` is also a factor of their GCD.

Then count the factors of the GCD by checking only up to `sqrt(gcd)`.

### GCD Using Loop

int gcd = a;

while(b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
}

gcd = a;

### Counting Factors

int count = 0;

for(int i = 1; i * i <= gcd; i++) {
    if(gcd % i == 0) {
        count++;

        if(i != gcd / i)
            count++;
    }
}

The second `if` counts the paired factor `gcd / i`.

It prevents counting the same factor twice when `gcd` is a perfect square.

### Example

a = 12, b = 6

GCD = 6

Factors of 6:

1, 2, 3, 6

Answer = 4

### Complexity

My Approach:

Time: O(max(a, b))
Space: O(1)

Optimized Approach:

Time: O(log(min(a,b)) + sqrt(gcd))
Space: O(1)

### What I Learned

- Common factors can be found through GCD.
- Euclidean Algorithm efficiently finds GCD.
- Factors come in pairs: `i` and `n / i`.
- We only need to check up to `sqrt(n)`.
- Mathematical observations can make a solution much faster.