# What does the below code snippet print out?
# How can we fix the anonymous functions to behave as we'd expect?

functions = []
for i in range(10):
    functions.append(lambda : i)

for f in functions:
    print(f())

# output:
# 9
# 9
# 9
# 9
# 9
# 9
# 9
# 9
# 9
# 9

# This is because the variable i is not local to lambda.
# At the end of the loop the  value of variable i in 9.
# So, when the function is called it is returning 9.
# We can get the expected behaviour by storing the value of i
# in a local variable (say x) and then returning that local variable
# Here is the modified code --

functions = []
for i in range(10):
    functions.append(lambda x=i : x)

for f in functions:
    print(f())

# output:
# 0
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# 9