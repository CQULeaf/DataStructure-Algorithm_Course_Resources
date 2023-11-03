# True-or-False of Homework 2 Key Points

## Some Common Notations Used to Evaluate the Alogrithms' Time Complexity

### Big-O Notation (O) - Upper Bound

This is the most commonly used notation. It describes an upper bound on the time complexity, giving the worst-case scenario.

\[ O(f(n)) \]

For example, if an algorithm takes \(O(n^2)\) time, the time complexity is at most proportional to \(n^2\) for large \(n\).

### Big-Omega Notation (\( \Omega \)) - Lower Bound

This notation provides a lower bound on the time complexity, indicating the best-case scenario.

\[ \Omega(f(n)) \]

If an algorithm takes \( \Omega(n) \) time, then its time complexity is at least \( n \) for large \(n\).

### Big-Theta Notation (\( \Theta \)) - Tight Bound

This notation provides both an upper and lower bound, implying that the algorithm is neither better nor worse than \( \Theta(f(n)) \).

\[ \Theta(f(n)) \]

If an algorithm takes \( \Theta(n^2) \) time, its time complexity is exactly \( n^2 \) for large \(n\).

### Small-o Notation (o) - Upper Bound, but Not Tight

This notation describes an upper bound, but unlike Big-O, it's not a tight bound.

\[ o(f(n)) \]

An algorithm with \( o(n^2) \) time complexity will be faster than \( n^2 \) for sufficiently large \(n\).

### Small-omega Notation (\( \omega \)) - Lower Bound, but Not Tight

This is the lower bound counterpart to small-o notation.

\[ \omega(f(n)) \]

An algorithm with \( \omega(n) \) time complexity will eventually be slower than \( n \) for sufficiently large \(n\).

***

To evaluate these notations, we often look at **the code's loops**, **recursive calls**, and **other operations** and evaluate them mathematically.

Here are some common examples:

- A `for` loop that runs \( n \) times: \( O(n) \)
- A nested `for` loop: \( O(n^2) \)
- A divide-and-conquer algorithm like merge sort: \( O(n \log n) \)
- An iterative fibonacci sequence: \( O(n) \)
- A naive recursive fibonacci sequence : \( O(2^n) \)
