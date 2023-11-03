def evaluate_postfix(expression):
    stack = []

    for token in expression:
        if token.isdigit() or (token[0] == '-' and token[1:].isdigit()):  
            stack.append(int(token))
        else:
            if len(stack) < 2:
                return f"Expression Error: {stack[-1]}" if stack else "Expression Error"
            b = stack.pop()
            a = stack.pop()

            if token == '+':
                result = a + b
            elif token == '-':
                result = a - b
            elif token == '*':
                result = a * b
            elif token == '/':
                if b == 0:
                    return f"Error: {a}/0"
                result = int(a / b) 
            else:
                return "Unknown operator"

            stack.append(result)

    if len(stack) != 1:
        return f"Expression Error: {stack[-1]}"

    return stack[0]


if __name__ == "__main__":
    postfix_expression = input().split()
    postfix_expression.pop()  

    result = evaluate_postfix(postfix_expression)

    print(result)
