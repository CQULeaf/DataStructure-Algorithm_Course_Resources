# KEY POINTS ANALYSIS

## The `max()` function in python

The `max()` function in Python is used to find the largest item among two or more arguments, or the largest item in an iterable like a list or a tuple. If you pass multiple individual values to `max()`, it returns the largest one. If you pass an iterable, it returns the largest item in that iterable.

### 1、With *individual arguments*

```python
largest_number = max(3, 9, 5)
# largest_number will be 9
```

### 2、With an *iterable*

```python
my_list = [1, 2, 3, 4, 5]
largest_number = max(my_list)
# largest_number will be 5
```

### 3、With a *custom key function*

We can also use a key function to customize the comparison. For example, to find the longest string in a list:

```python
my_list = ["apple", "banana", "cherry"]
longest_string = max(my_list, key=len)
# longest_string will be 'banana'
```

Here, `key=len` specifies that the function `len` should be used for determining the "largeness" of each item.

### 4、With strings

When used with strings, `max()` returns the string with the greatest lexicographical order (i.e., appears last in a dictionary).

```python
largest_string = max("apple", "banana", "cherry")
# largest_string will be 'cherry'
```

***Notice: The `min()` function is the same***
