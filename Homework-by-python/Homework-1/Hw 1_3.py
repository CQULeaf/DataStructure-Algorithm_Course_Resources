# Function to count the mines around a given cell
def count_mines(x, y, grid):
    count = 0
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    for dx, dy in directions:
        new_x, new_y = x + dx, y + dy
        if 0 <= new_x < len(grid) and 0 <= new_y < len(grid[0]):
            if grid[new_x][new_y] == '*':
                count += 1
    return str(count)

# Number of test cases
T = int(input())

all_outputs = []

for _ in range(T):
    # Read the dimensions of the grid
    x, y = map(int, input().split())
    
    # Read the grid
    grid = [list(input()) for _ in range(x)]
    
    # Output grid
    output = []
    
    for i in range(x):
        row = []
        for j in range(y):
            if grid[i][j] == '*':
                row.append('*')
            else:
                row.append(count_mines(i, j, grid))
        output.append(''.join(row))
    all_outputs.append(output)
        
for index, output in enumerate(all_outputs):
    for row in output:
        print(row)
    if index < len(all_outputs) - 1:
        print()  # Print a newline between test cases, but not after the last one