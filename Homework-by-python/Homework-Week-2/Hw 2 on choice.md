# Calculate the time complexity

```c
int  sum = 0;
for(int i=1;i<n;i*=2)
    for(int j=0;j<i;j++)
        sum++;
```

## Outer Loop

The outer loop has `i` starting at 1, and `i` doubles in each iteration. So, the values of `i` are \(1, 2, 4, 8, 16, \ldots\) until \(i < n\).

The number of times this outer loop will run can be represented as \(\log_2{n}\).

## Inner Loop

The inner loop runs \(i\) times, where \(i\) is the current value from the outer loop.

### Total Iterations of inner loop

The total number of iterations the inner loop will make across all iterations of the outer loop is:

\[
1 + 2 + 4 + 8 + \ldots + 2^{\log_2{n}} = 2^0 + 2^1 + 2^2 + \ldots + 2^{\log_2{n}}
\]

This is a geometric series whose sum can be computed as \(2^{\log_2{n}+1} - 1\), or more simply \(2n - 1\).

Therefore, the time complexity of the entire piece of code is \(O(n)\).
