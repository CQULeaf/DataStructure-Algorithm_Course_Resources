# Merge Two Sorted Lists with cpp

<!-- toc -->
- [Merge Two Sorted Lists with cpp](#merge-two-sorted-lists-with-cpp)
  - [Pointer: the most crucial concept (Basic Knowledge)](#pointer-the-most-crucial-concept-basic-knowledge)
    - [What is a Pointer?](#what-is-a-pointer)
    - [Declaring Pointers](#declaring-pointers)
    - [Initializing Pointers](#initializing-pointers)
    - [Dereferencing Pointers](#dereferencing-pointers)
    - [Pointer Arithmetic](#pointer-arithmetic)
    - [Pointers and Functions](#pointers-and-functions)
    - [Pointer to Pointer](#pointer-to-pointer)
    - [Null Pointer](#null-pointer)
  - [Talk about the `*` and `->` operators](#talk-about-the--and---operators)
  - [Understand the `if (!list1)` statement](#understand-the-if-list1-statement)
  - [The line `ListNode* dummy = new ListNode(-1);`](#the-line-listnode-dummy--new-listnode-1)
    - [Why `new`?](#why-new)
    - [Dummy Node](#dummy-node)
    - [Deleting Dynamically Allocated Memory](#deleting-dynamically-allocated-memory)
  - [What about the `sturct` part](#what-about-the-sturct-part)
    - [The three Constructors](#the-three-constructors)
    - [Logic Behind Constructors](#logic-behind-constructors)
  - [`heap` VS `stack`](#heap-vs-stack)
    - [Stack](#stack)
    - [Heap](#heap)
    - [In Summary](#in-summary)

## Pointer: the most crucial concept (Basic Knowledge)

Pointers are a crucial concept in languages like C and C++, and they allow us to directly interact with memory addresses.

### What is a Pointer?

A pointer is a variable that stores the memory address of another variable. This allows us to indirectly manipulate the data stored at that address.

### Declaring Pointers

We declare a pointer by specifying its data type, followed by an asterisk (`*`). For example:

```cpp
int *p; // pointer to an integer
char *c; // pointer to a character
ListNode *node; // pointer to a ListNode object
```

### Initializing Pointers

I can initialize a pointer by assigning it the address of a variable using the address-of operator (`&`):

```cpp
int x = 10;
int *p = &x; // p now points to x
```

### Dereferencing Pointers

The dereference operator (`*`) is used to access the value at the address a pointer is pointing to:

```cpp
int x = 10;
int *p = &x;
int y = *p; // y will be 10, the value at the address p is pointing to
```

### Pointer Arithmetic

We can perform arithmetic operations on pointers. For example, incrementing a pointer (`p++`) will make it point to the next memory location for its data type.

```cpp
int arr[] = {1, 2, 3};
int *p = arr;
p++; // Now points to the second element (2) in arr
```

### Pointers and Functions

Pointers can be passed to functions to modify variables indirectly:

```cpp
void increment(int *p) {
    (*p)++;
}

int main() {
    int x = 5;
    increment(&x); // x becomes 6
}
```

### Pointer to Pointer

We can also have pointers to pointers, usually denoted by multiple asterisks:

```cpp
int x = 10;
int *p = &x;
int **pp = &p; // pointer to pointer
```

### Null Pointer

A pointer that doesn't point to anything is called a null pointer. It's good practice to initialize pointers to `nullptr` if we don't have an address to assign yet:

```cpp
int *p = nullptr;
```

Understanding pointers opens up a world of low-level memory manipulation and efficient data handling.

## Talk about the `*` and `->` operators

In C++, the `*` and `->` operators have specific roles, especially when dealing with pointers and objects.

1. `*` (Dereference Operator):
   - When used with a pointer, the `*` operator dereferences the pointer, meaning it gives us access to the value the pointer is pointing to.
   - Example: If `ListNode *node = new ListNode(5);`, then `*node` will give us access to the object that `node` points to.

2. `->` (Arrow Operator):
   - The `->` operator is used to access members (variables, methods) of an object through a pointer to that object.
   - Example: If I have a pointer `ListNode *node` pointing to a `ListNode` object, then `node->val` would access the `val` member variable of the object pointed to by `node`.

In my code:

- `ListNode* list1, *list2;`: Here `ListNode*` declares a pointer to a `ListNode` object. `list1` and `list2` will store the addresses of these objects.
  
- `current->next = list1;`: In this line, `current` is a pointer to a `ListNode` object. `current->next` accesses the `next` member variable of the object pointed to by `current`. You're setting it to point to the node referred to by `list1`.

- `list1 = list1->next;`: Here, `list1->next` accesses the `next` member of the object `list1` is pointing to. Then `list1 = list1->next;` updates `list1` to point to its next node.

## Understand the `if (!list1)` statement

In C++, the expression `if (!list1)` is a shorthand way to check if `list1` is a null pointer.

In C++ (and many other C-like languages), **a null pointer equates to `false` when used in a boolean context, and a non-null pointer equates to `true`.**

So, the expression `if (!list1)` translates to "if `list1` is null". The `!` operator negates the condition, so it effectively checks for a null pointer.

Here's how it works:

- If `list1` is null (`nullptr`), then `!list1` evaluates to `true`, and the code inside the `if` block executes.
- If `list1` is pointing to some memory location (i.e., it is non-null), then `!list1` evaluates to `false`, and the code inside the `if` block is skipped.

In the context of linked lists, checking for a null pointer is a common way to determine whether I've reached the end of the list or whether the list is empty to begin with.

## The line `ListNode* dummy = new ListNode(-1);`

1. `new ListNode(-1)` dynamically allocates memory for a new `ListNode` object and initializes its value to `-1`. The `new` operator returns the address of this new object.
    · The `(-1)` in `new ListNode(-1)` is an argument being passed to a constructor of the `ListNode` class. It initializes the value of the newly created node.

    From the code in the beginning:

    ```cpp
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ```

    There are three constructors for the `ListNode`:

   1. `ListNode() : val(0), next(nullptr) {}` – Default constructor that initializes the node with a value of `0` and a `nullptr` for the next node.
   2. `ListNode(int x) : val(x), next(nullptr) {}` – Constructor that takes an integer `x` and initializes the node with that value. The next pointer is set to `nullptr`.
   3. `ListNode(int x, ListNode *next) : val(x), next(next) {}` – Constructor that takes an integer `x` and a pointer to another `ListNode`. It initializes the node with the given value and next pointer.

    In the line `new ListNode(-1)`, the second constructor is being used. It creates a new `ListNode` object with a value of `-1` and a next pointer set to `nullptr`.

    The `-1` value in the context of merging the linked lists isn't significant. It's just a placeholder value. The main purpose of the `dummy` node is to provide a consistent starting point for building the merged list, so we don't need to handle edge cases separately. The actual value `-1` in the `dummy` node is discarded in the final merged list.

2. `ListNode* dummy` declares a pointer to a `ListNode` type.

3. `ListNode* dummy = new ListNode(-1);` combines both actions: it declares a pointer named `dummy` and initializes it with the address of the newly allocated `ListNode` object.

### Why `new`?

The `new` operator is used to allocate memory on the heap, as opposed to the stack. Memory allocated on the heap persists outside the function call, which is crucial when we're working with data structures like linked lists that must persist across different scopes.

### Dummy Node

The `dummy` node acts as a placeholder and makes the list manipulation easier. We don't have to deal with edge cases separately (like inserting at the beginning of the list), and it simplifies the code.

### Deleting Dynamically Allocated Memory

Because `new` allocates memory on the heap, we should eventually `delete` this memory to prevent memory leaks. In the given code, `delete dummy;` performs this action, freeing the memory allocated for the `dummy` node.

## What about the `sturct` part

```cpp
struct ListNode {
    ...
};
```

In C++, a `struct` is a composite data type that groups together variables under a single name. These variables can be of different data types, and each has a name which is used to access it.

In the context of the `ListNode` struct:

```cpp
int val;
ListNode *next;
```

There are two members:

1. `val` - an integer that stores the value of the node.
2. `next` - a pointer to another `ListNode` that points to the next node in the linked list. If there's no next node, it's set to `nullptr`.

### The three Constructors

Constructors are special member functions that are executed whenever a new object of the structure (or class) is created. For `ListNode`, three constructors are defined to provide flexibility in creating nodes.

**Default Constructor**:

```cpp
ListNode() : val(0), next(nullptr) {}
```

This constructor takes no arguments. It initializes the node with a default value of `0` for `val` and sets the `next` pointer to `nullptr`. The colon (`:`) begins the member initialization list, which is a C++ feature to efficiently initialize members of an object.

***Usage***:

```cpp
ListNode* node = new ListNode();
```

**Single Argument Constructor**:

```cpp
ListNode(int x) : val(x), next(nullptr) {}
```

This constructor takes a single integer argument `x`. It initializes the `val` member with `x` and sets the `next` pointer to `nullptr`.

***Usage***:

```cpp
ListNode* node = new ListNode(5); // Creates a node with value 5
```

**Two Argument Constructor**:

```cpp
ListNode(int x, ListNode *next) : val(x), next(next) {}
```

This constructor takes an integer `x` and a pointer to a `ListNode`. It initializes the node's `val` with `x` and its `next` pointer with the given pointer.

***Usage***:

```cpp
ListNode* anotherNode = new ListNode(7);
ListNode* node = new ListNode(5, anotherNode); // Creates a node with value 5 pointing to anotherNode
```

### Logic Behind Constructors

The logic behind providing multiple constructors is to offer flexibility:

- Sometimes we only want to set a value without worrying about the next node, so we use the single argument constructor.
- Sometimes we want to quickly create an empty node, so we use the default constructor.
- Other times, especially when manually building a linked list, we want to set both value and next pointer at once, so we use the two-argument constructor.

By providing these options, it simplifies the creation of `ListNode` objects based on different requirements.

## `heap` VS `stack`

Both the **heap** and the **stack** are areas of memory used by programs, but they serve different purposes and have different characteristics.

### Stack

1. **Purpose**: The stack is used for static memory allocation. It's where local variables are allocated and stored. It's also used to keep track of function calls.

2. **Memory Management**: Memory is managed in a Last-In-First-Out (LIFO) manner. This means that the most recently reserved block is the first to be freed. This makes it really simple to keep track of the stack; freeing a block from the stack is a simple decrement of the stack's pointer.

3. **Size**: The size of the stack is set when the program starts, and it can't be changed during the execution. This means that there's a limit to the amount of memory we can use on the stack. If we exceed this limit (like in a deep or infinite recursion), we'll get a stack overflow.

4. **Access Speed**: Accessing memory on the stack is very fast because the data is stored in a contiguous block of memory and managed in a LIFO manner.

5. **Life Cycle**: Variables created on the stack will go out of scope and be automatically deallocated. This means we don't have to manage memory yourself; it's handled for us.

### Heap

1. **Purpose**: The heap is used for dynamic memory allocation. It's where we allocate memory for variables that we need to exist for a longer period of time than local variables.

2. **Memory Management**: You have full control over the heap, which means we're responsible for allocating memory when we need it and freeing it when we're done. This is done using operators like `new` (or `malloc` in C) to allocate and `delete` (or `free` in C) to deallocate.

3. **Size**: The heap is typically much larger than the stack. Its size is limited only by the size of the addressable memory.

4. **Access Speed**: Accessing memory on the heap is a bit slower than the stack. Since the heap can have holes (due to the process of allocation and deallocation), finding a suitable block of memory can take a bit more time.

5. **Life Cycle**: Variables created on the heap will remain there until we deallocate them or the program ends. If we forget to free memory we've allocated on the heap, it results in a memory leak.

### In Summary

- **Stack**: Fast, automatic memory management, used for local variables, limited in size.
- **Heap**: Slower, manual memory management, used for dynamically allocated variables, larger in size.

Think of the **stack** as a stack of plates. When we add a plate (a local variable), it goes on top. When we're done with a plate, it gets removed from the top. We can't remove a plate from the middle or bottom without first removing the plates above it.

The **heap**, on the other hand, is like a large room where we can place objects wherever we want. We have to keep track of where we've put everything, and we're responsible for cleaning up.
