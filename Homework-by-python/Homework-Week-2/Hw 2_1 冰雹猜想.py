def hail_conjecture(n, score):
    sequence = []
    
    sequence.append(str(n))
    
    while n > 1:
        if n % 2 != 0:
            n = n * 3 + 1
        else:
            n = n // 2
        
        sequence.append(str(n))
        
        score += 1
    
    print(" ".join(sequence))

    print("count =", score)

n = int(input())
hail_conjecture(n, 1)
