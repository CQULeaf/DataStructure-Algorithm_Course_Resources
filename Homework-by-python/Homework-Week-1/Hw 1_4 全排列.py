def generate_permutations(arr, n, curr_permutation):
    if len(curr_permutation) == n:
        print(" ".join(map(str, curr_permutation)))
        return
    
    seen = set()
    for i in range(len(arr)):
        if arr[i] not in seen:
            seen.add(arr[i])
            curr_permutation.append(arr[i])
            next_arr = arr[:i] + arr[i+1:]
            generate_permutations(next_arr, n, curr_permutation)
            curr_permutation.pop()

N = int(input())
arr = list(map(int, input().split()))

generate_permutations(arr, N, [])
