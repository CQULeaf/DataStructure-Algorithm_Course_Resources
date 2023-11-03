def hail_conjecture(n, score):
    # Initialize an empty list to store the sequence
    sequence = []
    
    # Add the initial value of n to the list
    sequence.append(str(n))
    
    while n > 1:
        if n % 2 != 0:
            n = n * 3 + 1
        else:
            n = n // 2
        
        # Add the updated value of n to the list
        sequence.append(str(n))
        
        score += 1
    
    # Convert the list to a string and print it
    # using list can avoid the trailing space at the end
    print(" ".join(sequence))
    
    # Print the count on a new line
    print("count =", score)

n = int(input())
hail_conjecture(n, 1)
