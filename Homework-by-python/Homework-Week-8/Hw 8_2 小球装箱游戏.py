N = int(input())
balls = []

for _ in range(N):
    ball = list(map(int, input().split()))
    balls.append(ball)

sorted_balls = sorted(balls, key = lambda x : (x[0], -x[1]), reverse=True)

redA, greenA, redB, greenB = 0, 0, 0, 0

for ball in sorted_balls[:N//2]:
    if ball[1] == 0: redA += 1
    else: greenA +=1

for ball in sorted_balls[N//2:]:
    if ball[1] == 0: redB +=1
    else: greenB += 1

print(redA, greenA)
print(redB, greenB)
