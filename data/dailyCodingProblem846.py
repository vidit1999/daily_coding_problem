# cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
# For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

# Given this implementation of cons:

# def cons(a, b):
    # def pair(f):
        # return f(a, b)
    # return pair
# Implement car and cdr.

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair):
    def ret_first(a, b):
        return a
    return pair(ret_first)

def cdr(pair):
    def ret_last(a, b):
        return b
    return pair(ret_last)

print(car(cons(3, 4)), cdr(cons(3, 4)))