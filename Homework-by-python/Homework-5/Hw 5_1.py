def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print(" ".join(map(str, arr)))

if __name__ == "__main__":
    N = int(input())
    arr = list(map(int, input().split()))
    insertion_sort(arr)