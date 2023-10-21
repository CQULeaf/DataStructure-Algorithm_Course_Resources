def exchange(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def compare(arr, i, j, exchanged):
    if arr[i] > arr[j]:
        exchange(arr, i, j)
        exchanged[0] = True  # Use a mutable type like a list to reflect changes

def display(arr):
    print(" ".join(map(str, arr)))

def main():
    N = int(input())
    arr = list(map(int, input().split()))

    for i in range(N-1):
        exchanged = [False]
        for j in range(N-1-i):
            compare(arr, j, j+1, exchanged)
        if not exchanged[0]:
            break
        display(arr)

if __name__ == "__main__":
    main()