# The 24 game is played as follows. You are given a list of four integers, each between 1 and 9, 
# in a fixed order. By placing the operators +, -, *, and / between the numbers,
# and grouping them with parentheses, determine whether it is possible to reach the value 24.

# For example, given the input [5, 2, 7, 8], you should return True, since (5 * 2 - 7) * 8 = 24.

# Write a function that plays the 24 game.

from itertools import permutations, product

def check24(config : str) -> bool:
    try:
        if eval(config) == 24:
            return True
    except ZeroDivisionError:
        return False
    return False

def game24(lst : list) -> bool:
    for perm in permutations(map(str, lst)):
        for conf in product(*[['+', '-', '*', '/']]*3):
            try:
                # try diffrerent groupings by parentheses
                if any((
                    check24('('+perm[0]+conf[0]+''+perm[1]+')'+conf[1]+'('+perm[2]+''+conf[2]+perm[3]+')'), # [(5, 2), (7, 8)]
                    check24('('+perm[0]+conf[0]+''+perm[1]+')'+conf[1]+''+perm[2]+''+conf[2]+perm[3]+''), # [(5, 2), 7, 8]
                    check24(''+perm[0]+conf[0]+''+perm[1]+''+conf[1]+'('+perm[2]+''+conf[2]+perm[3]+')'), # [5, 2, (7, 8)]
                    check24(''+perm[0]+conf[0]+'('+perm[1]+''+conf[1]+''+perm[2]+')'+conf[2]+perm[3]+''), # [5, (2, 7), 8]
                    check24('('+perm[0]+conf[0]+''+perm[1]+''+conf[1]+''+perm[2]+')'+conf[2]+perm[3]+''), # [(5, 2, 7), 8]
                    check24(''+perm[0]+conf[0]+'('+perm[1]+''+conf[1]+''+perm[2]+''+conf[2]+perm[3]+')'), # [5, (2, 7, 8)]
                    check24('('+perm[0]+conf[0]+''+perm[1]+''+conf[1]+''+perm[2]+''+conf[2]+perm[3]+')'), # [(5, 2, 7, 8)]
                )):
                    return True
            except ZeroDivisionError:
                pass
    return False

print(game24([5, 2, 7, 8]))
print(game24([4, 1, 8, 7]))
print(game24([1, 2, 1, 2]))