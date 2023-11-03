N = int(input())
numbers = []

input_numbers = input()
numbers = list(map(int,input_numbers.split()))

maximum = max(numbers)
minimum = min(numbers)

result = maximum - minimum

print(result)
