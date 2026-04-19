class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = ['+', '-', '*', '/']
        for token in tokens:
            if token in operators:
                operand_1 = stack.pop()
                operand_2 = stack.pop()
                if token != '/':
                    new_val = eval(str(operand_2) + token + str(operand_1))
                else:
                    new_val = int(int(operand_2) / int(operand_1))
                print(f"{operand_2} {token} {operand_1} = {new_val}")
                stack.append(new_val)
            else:
                stack.append(token)
        return int(stack[-1])