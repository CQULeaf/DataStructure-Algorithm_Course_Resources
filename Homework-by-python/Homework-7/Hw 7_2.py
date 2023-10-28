def main():
    n = int(input())
    students = []

    for i in range(n):
        student = list(map(int, input().split()))
        students.append(student)

    sorted_students = sorted(students, key = lambda x : (-x[1], -x[2], x[0]))

    for student in sorted_students:
        print(student[0])

if __name__ == "__main__":
    main()