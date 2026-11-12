
class CFGParser:
    def __init__(self, expression):
        self.expression = expression.replace(" ", "")
        self.position = 0

    # N -> digit+
    def parse_number(self):
        if self.position >= len(self.expression):
            return False

        if not self.expression[self.position].isdigit():
            return False

        while (
            self.position < len(self.expression)
            and self.expression[self.position].isdigit()
        ):
            self.position += 1

        return True

    # F -> (E) | N
    def parse_factor(self):
        if self.position < len(self.expression) and self.expression[self.position] == '(':
            self.position += 1

            if not self.parse_expression():
                return False

            if self.position < len(self.expression) and self.expression[self.position] == ')':
                self.position += 1
                return True

            return False

        return self.parse_number()

    # T -> T * F | T / F | T % F | F
    def parse_term(self):
        if not self.parse_factor():
            return False

        while (
            self.position < len(self.expression)
            and self.expression[self.position] in ('*', '/', '%')
        ):
            self.position += 1

            if not self.parse_factor():
                return False

        return True

    # E -> E + T | E - T | T
    def parse_expression(self):
        if not self.parse_term():
            return False

        while (
            self.position < len(self.expression)
            and self.expression[self.position] in ('+', '-')
        ):
            self.position += 1

            if not self.parse_term():
                return False

        return True

    # Starting symbol: E
    def is_valid_expression(self):
        if not self.expression:
            return False

        if not self.parse_expression():
            return False

        return self.position == len(self.expression)


# Main program
user_input = input("Enter an arithmetic expression: ")

parser = CFGParser(user_input)

if parser.is_valid_expression():
    print("Valid Expression")
else:
    print("Invalid Expression")
