


class Token:
    def __init__(self, type, value=None):
        self.type = type
        self.value = value

    def __str__(self):
        return f"Token({self.type}, {self.value})"

class NumberToken(Token):
    def __init__(self, value):
        super().__init__('NUMBER', value)

class OperatorToken(Token):
    def __init__(self, value):
        super().__init__('OPERATOR', value)

class IdentifierToken(Token):
    def __init__(self, value):
        super().__init__('IDENTIFIER', value)

class ParenthesisToken(Token):
    def __init__(self, value):
        super().__init__('PARENTHESIS', value)

class FunctionToken(Token):
    def __init__(self, value):
        super().__init__('FUNCTION', value)

class KeywordToken(Token):
    def __init__(self, value):
        super().__init__('KEYWORD', value)
