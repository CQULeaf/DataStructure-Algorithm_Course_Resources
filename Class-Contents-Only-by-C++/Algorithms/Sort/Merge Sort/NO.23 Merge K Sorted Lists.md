# Merge K Sorted Lists

<!-- toc -->
- [Merge K Sorted Lists](#merge-k-sorted-lists)
  - [Talk about the "Custom comparator"](#talk-about-the-custom-comparator)
  - [Clarify the `pair`, `map`, `unordered_map` and `set`](#clarify-the-pair-map-unordered_map-and-set)

## Talk about the "Custom comparator"

```cpp
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        };
```

1. **Lambda Functions**:

   ```cpp
   auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
       ...
   };
   ```

   - A lambda function is a concise way to define an anonymous function (i.e., a function without a name) directly in the place where it's used.
   - The `[]` is the capture clause. It can be used to specify which outside variables are available for the lambda.
        - The square brackets `[]` at the beginning of a lambda function are known as the *capture clause*. The capture clause defines how the lambda function can access variables from the enclosing scope. Here's a breakdown of its uses:

           - `[]`: Capture nothing. This means the lambda cannot access local variables outside of its own scope.
           - `[x]`: Capture the variable `x` by value. This means the lambda has its own copy of `x` and changes to `x` inside the lambda do not affect the outside variable.
           - `[&x]`: Capture the variable `x` by reference. This means the lambda can access and modify the actual `x` variable from the outside scope.
           - `[=]`: Capture all local variables by value. This makes a copy of all local variables for the lambda.
           - `[&]`: Capture all local variables by reference. The lambda can access and modify all local variables from the outside scope.
           - We can also mix and match, e.g., `[x, &y]` would capture `x` by value and `y` by reference.

   - The parameters of the lambda function are defined inside the `()`. Here, the lambda takes two `pair<int, int>` parameters `a` and `b`.
   - The lambda's body is inside `{ ... }`.
   - `auto compare` means the variable `compare` will automatically take on the type of whatever is assigned to it—in this case, the lambda function.

2. **decltype**:

   ```cpp
   decltype(compare)
   ```

   - `decltype` is a keyword that queries the type of an expression. In this case, it queries the type of the `compare` lambda function.
   - It's used to specify the type of the comparator for the priority queue without having to manually write out the complex type of the lambda function.

3. **Priority Queue**:

   ```cpp
   priority_queue<...> pq(compare);
   ```

   - `priority_queue` is a template class. We provide type parameters inside the angle brackets `<...>`.
   - The constructor `pq(compare)` initializes the priority queue with the `compare` function as the comparator.

***

## Clarify the `pair`, `map`, `unordered_map` and `set`

**1. `std::pair`:**

- **Header File**: `<utility>`
- **Description**: `std::pair` is a templated structure designed to hold two different items. It's a simple way to connect together two values of any type, which might be different.
- **Use Cases**: Common scenarios include returning two values from a function, representing key-value pairs in maps, representing ranges (like the start and end iterators), or simply storing two related pieces of data together.
- **Example**:

```cpp
std::pair<int, std::string> p = {1, "one"};
```

**2. `std::map`:**

- **Header File**: `<map>`
- **Description**: `std::map` is an associative container that associates values with keys, allowing fast retrieval of the value given the key. The keys are sorted, and each key can appear only once.
- **Complexity**:
- **Insert, Delete, Find**: These operations run in \(O(log n)\) time due to the Red-Black tree structure internally.
- **Use Cases**: Useful when we need to store and retrieve data associated with a unique key, especially when the order of the keys is essential. It's particularly handy when frequent lookups based on a key are needed.
- **Example**:

```cpp
std::map<std::string, int> ageMap;
ageMap["Alice"] = 25;
```

**3. `std::unordered_map`:**

- **Header File**: `<unordered_map>`
- **Description**: Like `std::map`, it associates keys with values. However, it uses hashing, meaning the keys aren't stored in any particular order, but retrieval can be faster.
- **Complexity**:
  - **Insert, Delete, Find (average)**: \(O(1)\) since it uses hashing.
  - **Insert, Delete, Find (worst-case)**: \(O(n)\) if many keys collide to the same hash value. *(Hash Collision)*

- **Use Cases**: When rapid average-case operations are vital and there's no need to maintain order.
- **Example**:

```cpp
std::unordered_map<std::string, int> ageMap;
ageMap["Bob"] = 30;
```

**4. `std::set`:**

- **Header File**: `<set>`
- **Description**: `std::set` is an associative container that contains a sorted set of unique objects of type Key. It's typically implemented as a Red-Black tree.
- **Complexity**:
  - **Insert, Delete, Find**: \(O(log n)\) due to its balanced tree structure.
- **Use Cases**: When we need a collection of unique items, and we want them to be automatically sorted as we insert them. It's also beneficial for operations like set union, intersection, and difference.
- **Example**:

```cpp
std::set<int> s;
s.insert(1);
s.insert(2);
s.insert(1);  // won't insert since 1 already exists
```

**Comparisons**:

- **Data Structure vs. Algorithm**: It's crucial to note that `std::pair`, `std::map`, `std::unordered_map`, and `std::set` are all data structures. These structures are designed to store and organize data in specific ways to facilitate different operations and use-cases.

- **Ordered vs. Unordered**: `std::map` and `std::set` both maintain the order of their keys or elements, respectively, due to their typical implementation as balanced trees (Red-Black trees). In contrast, `std::unordered_map` does not maintain order since it uses hashing to store the key-value pairs.

- **Unique Elements**: While both `std::map` and `std::unordered_map` store key-value pairs with unique keys, `std::set` specifically stores unique elements without any associated values.

- **Usage**:

  - If we need to store pairs of items without the need for lookups, `std::pair` is appropriate.
  - For storing key-value pairs with fast lookups based on a key and maintaining order, we'd use `std::map`.
  - If order isn't important but we want faster average-case lookup times, lean towards `std::unordered_map`.
  - For a collection of unique items that are automatically sorted as they are inserted, `std::set` is the preferred choice.
