# Given the root to a binary tree, implement serialize(root),
# which serializes the tree into a string, and deserialize(s),
# which deserializes the string back into the tree.

# For example, given the following Node class

# class Node:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# The following test should pass:

# node = Node('root', Node('left', Node('left.left')), Node('right'))
# assert deserialize(serialize(node)).left.left.val == 'left.left'

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def __repr__(self):
        return f'Node({repr(self.val)}, {repr(self.left)}, {repr(self.right)})'

serialize = repr
deserialize = eval

node = Node('root', Node('left', Node('left.left')), Node('right'))
print(serialize(node))
print(deserialize(serialize(node)).left.left.val == 'left.left')
