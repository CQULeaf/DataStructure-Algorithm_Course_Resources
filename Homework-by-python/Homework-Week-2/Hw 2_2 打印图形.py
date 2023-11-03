def print_diamond(n):
    size = 2 * n - 1  # Calculate the size of the diamond
    
    # Print the upper half including the middle row
    for i in range(1, size + 1, 2):
        # Calculate the number of spaces needed on each side
        spaces = (size - i) // 2
        
        # Print leading spaces, stars, and trailing spaces
        print(" " * spaces + "*" * i + " " * spaces)
    
    # Print the lower half
    for i in range(size - 2, 0, -2):
        # Calculate the number of spaces needed on each side
        spaces = (size - i) // 2
        
        # Print leading spaces, stars, and trailing spaces
        print(" " * spaces + "*" * i + " " * spaces)

# Input: Get the value of n from the user
n = int(input())

# Output: Print the diamond shape
print_diamond(n)
