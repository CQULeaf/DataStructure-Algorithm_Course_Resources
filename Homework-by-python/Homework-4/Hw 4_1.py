def is_valid(s):
    stack = []
    mapping = {
        ')': '(',
        ']': '[',
        '}': '{',
        '>': '<'
    }
    order = ['<', '(', '[', '{']

    for char in s:
        if char in mapping.values():
            if stack and order.index(stack[-1]) < order.index(char):
                return "NO"
            stack.append(char)
        elif char in mapping.keys():  
            if not stack or mapping[char] != stack.pop():
                return "NO"
        else:
            return "NO"
    
    return "YES" if not stack else "NO"

if __name__ == "__main__":
    n = int(input())
    results = []
    for _ in range(n):
        s = input()
        results.append(is_valid(s))
    for res in results:
        print(res)
