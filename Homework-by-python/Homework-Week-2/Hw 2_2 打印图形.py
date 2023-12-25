def print_diamond(n):
    size = 2 * n - 1

    for i in range(1, size + 1, 2):
        spaces = (size - i) // 2
        
        print(" " * spaces + "*" * i + " " * spaces)
    
    for i in range(size - 2, 0, -2):
        spaces = (size - i) // 2

        print(" " * spaces + "*" * i + " " * spaces)

n = int(input())

print_diamond(n)
