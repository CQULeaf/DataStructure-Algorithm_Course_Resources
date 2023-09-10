# Step 1: Read N (the integer input from the user)
N = int(input())

# Step 2: Initialize an empty list to store N integers
numbers = []

# Step 3: Loop to read N integers
input_numbers = input()
numbers = list(map(int,input_numbers.split()))

# Step 4: Find the maximum and minimum values in the list
# TODO: Implement this part
maximum = max(numbers)
minimum = min(numbers)

# Step 5: Output the maximum value minus the minimum value
# TODO: Implement this part
result = maximum - minimum

print(result)
