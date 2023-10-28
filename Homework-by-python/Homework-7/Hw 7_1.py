def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        
        # Recursively sort first half and second half
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        
        # Merge the sorted halves
        merge(arr, left, mid, right)

# Wrapper function to initiate the sort
def initiate_merge_sort(arr):
    merge_sort(arr, 0, len(arr) - 1)

# Define a merge function
def merge(arr, left, mid, right):
    temp = []
    i, j = left, mid + 1
    
    while i <= mid and j <= right:
        if arr[i] < arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1
    
    temp.extend(arr[i:mid+1])
    temp.extend(arr[j:right+1])
    
    arr[left:right+1] = temp

    # Display the entire array after each merge operation
    print(" ".join(map(str, arr)))

# Loop to read multiple sets of test data
while True:
    try:
        n = int(input())
        unsorted_arr = list(map(int, input().split()))
        initiate_merge_sort(unsorted_arr)
    except EOFError:
        break