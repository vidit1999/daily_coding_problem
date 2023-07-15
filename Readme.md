# Daily Coing Problem Solutions

Solutions of *daily coding problems*. This is for educational purpose only.
Most of the files contain corresponding questions in it.

Solutions are licensed under [MIT License](License.md).

Questions(and/or problem statements) are taken from [dailycodingproblem.com](https://www.dailycodingproblem.com/).
So, if anyone wants to use the questions(and/or problem statements), they may go through their [Terms and Conditions](https://www.dailycodingproblem.com/terms-of-service).

---

#### Problem No. 1

```
Given a list of numbers and a number k, return
whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17,
return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
```
[Solution](data/dailyCodingProblem1.cpp)

---


#### Problem No. 2

```
Given an array of integers, return a new array such that each element at index i of
the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
```
[Solution](data/dailyCodingProblem2.cpp)

---


#### Problem No. 3

```
Given the root to a binary tree, implement serialize(root),
which serializes the tree into a string, and deserialize(s),
which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```
[Solution](data/dailyCodingProblem3.py)

---


#### Problem No. 4

```
Given an array of integers, find the first missing positive integer in linear time
and constant space. In other words, find the lowest positive integer that does not
exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2.
The input [1, 2, 0] should give 3.

You can modify the input array in-place.
```
[Solution](data/dailyCodingProblem4.cpp)

---


#### Problem No. 5

```
cons(a, b) constructs a pair, and car(pair) and cdr(pair)
returns the first and last element of that pair.
For example, car(cons(3, 4)) returns 3,
and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
```
[Solution](data/dailyCodingProblem5.py)

---


#### Problem No. 6

```
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field
named both, which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the
element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can
assume you have access to get_pointer and dereference_pointer
functions that converts between nodes and memory addresses.
```
[Solution](data/dailyCodingProblem6.c)

---


#### Problem No. 7

```
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3,
since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable.
For example, '001' is not allowed.
```
[Solution](data/dailyCodingProblem7.cpp)

---


#### Problem No. 8

```
A unival tree (which stands for "universal value") is a
tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
```
[Solution](data/dailyCodingProblem8.cpp)

---


#### Problem No. 9

```
Given a list of integers, write a function that returns the largest
sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.
[5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
```
[Solution](data/dailyCodingProblem9.cpp)

---


#### Problem No. 10

```
Implement a job scheduler which takes in a function f and an integer n,
and calls f after n milliseconds.
```
[Solution](data/dailyCodingProblem10.cpp)

---


#### Problem No. 11

```
Implement an autocomplete system. That is, given a query string s and a set
of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of
strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a
more efficient data structure to speed up queries.
```
[Solution](data/dailyCodingProblem11.cpp)

---


#### Problem No. 12

```
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time,
you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
```
[Solution](data/dailyCodingProblem12.cpp)

---


#### Problem No. 13

```
Given an integer k and a string s, find the length of the
longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2,
the longest substring with k distinct characters is "bcb".
```
[Solution](data/dailyCodingProblem13.cpp)

---


#### Problem No. 14

```
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
```
[Solution](data/dailyCodingProblem14.cpp)

---


#### Problem No. 15

```
Given a stream of elements too large to store in memory,
pick a random element from the stream with uniform probability.
```
[Solution](data/dailyCodingProblem15.cpp)

---


#### Problem No. 16

```
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
```
[Solution](data/dailyCodingProblem16.cpp)

---


#### Problem No. 17

```
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a
sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2.
subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1.
subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute
path to a file within our file system. For example, in the second example above,
the longest absolute path is "dir/subdir2/subsubdir2/file2.ext",
and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format,
return the length of the longest absolute path to a file in the
abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
```
[Solution](data/dailyCodingProblem17.cpp)

---


#### Problem No. 18

```
Given an array of integers and a number k, where 1 <= k <= length of the array,
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3,
we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array
in-place and you do not need to store the results. You can simply print them out as you compute them.
```
[Solution](data/dailyCodingProblem18.cpp)

---


#### Problem No. 19

```
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents
the cost to build the nth house with kth color,
return the minimum cost which achieves this goal.
```
[Solution](data/dailyCodingProblem19.cpp)

---


#### Problem No. 20

```
Given two singly linked lists that intersect at some point, find the intersecting node.
The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and
B = 99 -> 1 -> 8 -> 10,
return the node with value 8.

In this example, assume nodes with the same
value are the exact same node objects.

Do this in O(M + N) time (where M and N are
the lengths of the lists) and constant space.
```
[Solution](data/dailyCodingProblem20.cpp)

---


#### Problem No. 21

```
Given an array of time intervals (start, end) for classroom lectures
(possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
```
[Solution](data/dailyCodingProblem21.cpp)

---


#### Problem No. 22

```
Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list. If there is more than one possible reconstruction, return any of them.
If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and
the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and
the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
```
[Solution](data/dailyCodingProblem22.cpp)

---


#### Problem No. 23

```
You are given an M by N matrix consisting of booleans that represents a board.
Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate,
return the minimum number of steps required to reach the end
coordinate from the start. If there is no possible path,
then return null. You can move up, left, down, and right.
You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]

and start = (3, 0) (bottom left) and end = (0, 0) (top left),
the minimum number of steps required to reach the end is 7,
since we would need to go through (1, 2) because there is
a wall everywhere else on the second row.
```
[Solution](data/dailyCodingProblem23.cpp)

---


#### Problem No. 24

```
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:
is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like.
You may assume the class is used in a single-threaded program,
so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
```
[Solution](data/dailyCodingProblem24.cpp)

---


#### Problem No. 25

```
Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element

That is, implement a function that takes in a string and a valid regular
expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray",
your function should return true. The same regular expression on the
string "raymond" should return false.

Given the regular expression ".*at" and the string "chat",
your function should return true. The same regular expression
on the string "chats" should return false.
```
[Solution](data/dailyCodingProblem25.cpp)

---


#### Problem No. 26

```
Given a singly linked list and an integer k,
remove the kth last element from the list.
k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than
one pass is prohibitively expensive.

Do this in constant space and in one pass.
```
[Solution](data/dailyCodingProblem26.cpp)

---


#### Problem No. 27

```
Given a string of round, curly, and square open and closing brackets,
return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
```
[Solution](data/dailyCodingProblem27.cpp)

---


#### Problem No. 28

```
Write an algorithm to justify text. Given a sequence of words and an integer line length k,
return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line.
There should be at least one space between each word. Pad extra spaces when
necessary so that each line has exactly length k. Spaces should be
distributed as equally as possible, with the extra spaces, if any,
distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words
["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
```
[Solution](data/dailyCodingProblem28.cpp)

---


#### Problem No. 29

```
Run-length encoding is a fast and simple method of encoding strings.
The basic idea is to represent repeated successive characters as a single count and character.
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be
encoded have no digits and consists solely of alphabetic characters.
You can assume the string to be decoded is valid.
```
[Solution](data/dailyCodingProblem29.cpp)

---


#### Problem No. 30

```
You are given an array of non-negative integers that represents a two-dimensional
elevation map where each element is unit-width wall and the integer is the height.
Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index,
2 in the second, and 3 in the fourth index (we cannot hold 5 since it would
run off to the left), so we can trap 8 units of water.
```
[Solution](data/dailyCodingProblem30.cpp)

---


#### Problem No. 31

```
The edit distance between two strings refers to the minimum number
of character insertions, deletions, and substitutions required to
change one string to the other. For example, the edit distance
between “kitten” and “sitting” is three: substitute the “k” for “s”,
substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
```
[Solution](data/dailyCodingProblem31.cpp)

---


#### Problem No. 32

```
Suppose you are given a table of currency exchange rates, represented as a 2D array.
Determine whether there is a possible arbitrage: that is, whether there is some
sequence of trades you can make, starting with some amount A of any currency,
so that you can end up with some amount greater than A of that currency.

There are no transaction costs and you can trade fractional quantities.
```
[Solution](data/dailyCodingProblem32.cpp)

---


#### Problem No. 33

```
Compute the running median of a sequence of numbers.
That is, given a stream of numbers, print out the median
of the list so far on each new element.

Recall that the median of an even-numbered list is
the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5],
your algorithm should print out:

2
1.5
2
3.5
2
2
2
```
[Solution](data/dailyCodingProblem33.cpp)

---


#### Problem No. 34

```
Given a string, find the palindrome that can be made by inserting
the fewest number of characters as possible anywhere in the word.
If there is more than one palindrome of minimum length that can
be made, return the lexicographically earliest one
(the first one alphabetically).

For example, given the string "race", you should return "ecarace",
since we can add three letters to it (which is the smallest amount
to make a palindrome). There are seven other palindromes that can
be made from "race" by adding three letters, but "ecarace" comes
first alphabetically.

As another example, given the string "google",
you should return "elgoogle".
```
[Solution](data/dailyCodingProblem34.cpp)

---


#### Problem No. 35

```
Given an array of strictly the characters 'R', 'G', and 'B',
segregate the values of the array so that all the Rs come first,
the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'],
it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
```
[Solution](data/dailyCodingProblem35.cpp)

---


#### Problem No. 36

```
Given the root to a binary search tree,
find the second largest node in the tree.
```
[Solution](data/dailyCodingProblem36.cpp)

---


#### Problem No. 37

```
The power set of a set is the set of all its subsets.
Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should
return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
```
[Solution](data/dailyCodingProblem37.cpp)

---


#### Problem No. 38

```
You have an N by N board. Write a function that, given N,
returns the number of possible arrangements of the board
where N queens can be placed on the board without
threatening each other, i.e. no two queens share
the same row, column, or diagonal.
```
[Solution](data/dailyCodingProblem38.cpp)

---


#### Problem No. 39

```
Conway's Game of Life takes place on an infinite two-dimensional board of square cells.
Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a starting
list of live cell coordinates and the number of steps it should run for.
Once initialized, it should print out the board state at each step.
Since it's an infinite board, print out only the relevant coordinates,
i.e. from the top-leftmost live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
```
[Solution](data/dailyCodingProblem39.cpp)

---


#### Problem No. 40

```
Given an array of integers where every integer occurs three
times except for one integer, which only occurs once,
find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1.
Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
```
[Solution](data/dailyCodingProblem40.cpp)

---


#### Problem No. 41

```
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs,
and a starting airport, compute the person's itinerary. If no such itinerary exists, return null.
If there are multiple possible itineraries, return the lexicographically smallest one.
All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A',
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C']
is also a valid itinerary. However, the first one is lexicographically smaller.
```
[Solution](data/dailyCodingProblem41.cpp)

---


#### Problem No. 42

```
Given a list of integers S and a target number k, write a function that returns a
subset of S that adds up to k. If such a subset cannot be made, then return null.

Integers can appear more than once in the list.
You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24,
return [12, 9, 2, 1] since it sums up to 24.
```
[Solution](data/dailyCodingProblem42.cpp)

---


#### Problem No. 43

```
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack

pop(), which pops off and returns the topmost element of the stack.
If there are no elements in the stack, then it should throw an error or return null.

max(), which returns the maximum value in the stack currently.
If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.
```
[Solution](data/dailyCodingProblem43.cpp)

---


#### Problem No. 44

```
We can determine how "out of order" an array A is by counting the number of inversions it has.
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller
element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three
inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions:
every distinct pair forms an inversion.
```
[Solution](data/dailyCodingProblem44.cpp)

---


#### Problem No. 45

```
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability,
implement a function rand7() that returns an integer from 1 to 7 (inclusive).
```
[Solution](data/dailyCodingProblem45.cpp)

---


#### Problem No. 46

```
Given a string, find the longest palindromic contiguous substring.
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb".
The longest palindromic substring of "bananas" is "anana".
```
[Solution](data/dailyCodingProblem46.cpp)

---


#### Problem No. 47

```
Given a array of numbers representing the stock prices of a company in chronological order,
write a function that calculates the maximum profit you could have made
from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5,
since you could buy the stock at 5 dollars and sell it at 10 dollars.
```
[Solution](data/dailyCodingProblem47.cpp)

---


#### Problem No. 48

```
Given pre-order and in-order traversals of a binary tree,
write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g
```
[Solution](data/dailyCodingProblem48.cpp)

---


#### Problem No. 49

```
Given an array of numbers, find the maximum sum of any
contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86],
the maximum sum would be 137,
since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0,
since we would not take any elements.

Do this in O(N) time.
```
[Solution](data/dailyCodingProblem49.cpp)

---


#### Problem No. 50

```
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer
and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).
```
[Solution](data/dailyCodingProblem50.cpp)

---


#### Problem No. 51

```
Given a function that generates perfectly random numbers between 1 and k (inclusive),
where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
```
[Solution](data/dailyCodingProblem51.cpp)

---


#### Problem No. 52

```
Implement an LRU (Least Recently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

set(key, value): sets key to value. If there are already n items
in the cache and we are adding a new item, then it should also
remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
```
[Solution](data/dailyCodingProblem52.cpp)

---


#### Problem No. 53

```
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out)
data structure with the following methods: enqueue, which inserts an element into the queue,
and dequeue, which removes it.
```
[Solution](data/dailyCodingProblem53.cpp)

---


#### Problem No. 54

```
Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits.
The objective is to fill the grid with the constraint that every row, column,
and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.

Implement an efficient sudoku solver.
```
[Solution](data/dailyCodingProblem54.cpp)

---


#### Problem No. 55

```
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.

restore(short), which expands the shortened string into the original url.
If no such shortened string exists, return null.

Hint: What if we enter the same URL twice?
```
[Solution](data/dailyCodingProblem55.cpp)

---


#### Problem No. 56

```
Given an undirected graph represented as an adjacency matrix and an integer k,
write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors.
```
[Solution](data/dailyCodingProblem56.cpp)

---


#### Problem No. 57

```
Given a string s and an integer k, break up the string into multiple texts
such that each text has a length of k or less. You must break it up so that
words don't break across lines. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that
there is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog"
and k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"].
No string in the list has a length of more than 10.
```
[Solution](data/dailyCodingProblem57.cpp)

---


#### Problem No. 58

```
An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in
faster than linear time. If the element doesn't exist in the array,
return null.

For example, given the array [13, 18, 25, 2, 8, 10]
and the element 8,
return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
```
[Solution](data/dailyCodingProblem58.cpp)

---


#### Problem No. 60

```
Given a multiset of integers, return whether it
can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10},
it would return true, since we can split it up into
{15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false,
since we can't split it up into two subsets that add up to the same sum.
```
[Solution](data/dailyCodingProblem60.cpp)

---


#### Problem No. 61

```
Implement integer exponentiation. That is, implement the pow(x, y)
function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
```
[Solution](data/dailyCodingProblem61.cpp)

---


#### Problem No. 62

```
There is an N by M matrix of zeroes. Given N and M, write a function
to count the number of ways of starting at the top-left corner and
getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2,
since there are two ways to get to the bottom-right:

Right, then down
Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
```
[Solution](data/dailyCodingProblem62.cpp)

---


#### Problem No. 63

```
Given a 2D matrix of characters and a target word,
write a function that returns whether the word can
be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true,
since it's the leftmost column. Similarly, given the
target word 'MASS', you should return true,
since it's the last row.
```
[Solution](data/dailyCodingProblem63.cpp)

---


#### Problem No. 64

```
A knight's tour is a sequence of moves by a knight
on a chessboard such that all squares are visited once.

Given N, write a function to return the number
of knight's tours on an N by N chessboard.
```
[Solution](data/dailyCodingProblem64.cpp)

---


#### Problem No. 65

```
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
```
[Solution](data/dailyCodingProblem65.cpp)

---


#### Problem No. 66

```
Assume you have access to a function toss_biased()
which returns 0 or 1 with a probability that's not
50-50 (but also not 0-100 or 100-0).
You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.
```
[Solution](data/dailyCodingProblem66.cpp)

---


#### Problem No. 67

```
Implement an LRU (Least Recently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

set(key, value): sets key to value. If there are already n items
in the cache and we are adding a new item, then it should also
remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
```
[Solution](data/dailyCodingProblem67.cpp)

---


#### Problem No. 68

```
On our special chessboard, two bishops attack each other if
they share the same diagonal. This includes bishops that
have another bishop located between them, i.e. bishops
can attack through pieces.

You are given N bishops, represented as (row, column)
tuples on a M by M chessboard. Write a function to count
the number of pairs of bishops that attack each other.
The ordering of the pair doesn't matter:
(1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)

The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]

You should return 2, since bishops 1 and 3
attack each other, as well as bishops 3 and 4.
```
[Solution](data/dailyCodingProblem68.cpp)

---


#### Problem No. 69

```
Given a list of integers, return the largest product
that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2],
we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.
```
[Solution](data/dailyCodingProblem69.cpp)

---


#### Problem No. 70

```
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
```
[Solution](data/dailyCodingProblem70.cpp)

---


#### Problem No. 71

```
Using a function rand7() that returns an integer from 1 to 7 (inclusive)
with uniform probability, implement a function rand5() that
returns an integer from 1 to 5 (inclusive).
```
[Solution](data/dailyCodingProblem71.cpp)

---


#### Problem No. 72

```
In a directed graph, each node is assigned an uppercase letter.
We define a path's value as the number of most frequently-occurring
letter along that path. For example, if a path in the graph goes
through "ABACA", the value of the path is 3, since there are 3 occurrences of 'A' on the path.

Given a graph with n nodes and m directed edges, return the
largest value path of the graph. If the largest value is infinite, then return null.

The graph is represented with a string and an edge list.
The i-th character represents the uppercase letter of
the i-th node. Each tuple in the edge list (i, j) means
there is a directed edge from the i-th node to the j-th node.
Self-edges are possible, as well as multi-edges.

For example, the following input graph:

ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]

Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).

The following input graph:

A
[(0, 0)]

Should return null, since we have an infinite loop.
```
[Solution](data/dailyCodingProblem72.cpp)

---


#### Problem No. 73

```
Given the head of a singly linked list, reverse it in-place.
```
[Solution](data/dailyCodingProblem73.cpp)

---


#### Problem No. 74

```
Suppose you have a multiplication table that is N by N.
That is, a 2D array where the value at the i-th row and
j-th column is (i + 1) * (j + 1) (if 0-indexed) or i * j (if 1-indexed).

Given integers N and X, write a function that returns
the number of times X appears as a value in an N by N
multiplication table.

For example, given N = 6 and X = 12, you should return 4,
since the multiplication table looks like this:

| 1 | 2 | 3 | 4 | 5 | 6 |

| 2 | 4 | 6 | 8 | 10 | 12 |

| 3 | 6 | 9 | 12 | 15 | 18 |

| 4 | 8 | 12 | 16 | 20 | 24 |

| 5 | 10 | 15 | 20 | 25 | 30 |

| 6 | 12 | 18 | 24 | 30 | 36 |

And there are 4 12's in the table.
```
[Solution](data/dailyCodingProblem74.cpp)

---


#### Problem No. 75

```
Given an array of numbers, find the length of the longest increasing
subsequence in the array. The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15],
the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
```
[Solution](data/dailyCodingProblem75.cpp)

---


#### Problem No. 76

```
You are given an N by M 2D matrix of lowercase letters.
Determine the minimum number of columns that can be
removed to ensure that each row is ordered from top
to bottom lexicographically. That is, the letter at
each column is lexicographically later as you go down
each row. It does not matter whether each row itself
is ordered lexicographically.

For example, given the following table:

cba
daf
ghi

This is not ordered because of the a in the center.
We can remove the second column to make it ordered:

ca
df
gi

So your function should return 1,
since we only needed to remove 1 column.

As another example, given the following table:

abcdef

Your function should return 0,
since the rows are already ordered (there's only one row).

As another example, given the following table:

zyx
wvu
tsr

Your function should return 3,
since we would need to remove all the columns to order it.
```
[Solution](data/dailyCodingProblem76.cpp)

---


#### Problem No. 77

```
Given a list of possibly overlapping intervals,
return a new list of intervals where all overlapping
intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)],
you should return [(1, 3), (4, 10), (20, 25)].
```
[Solution](data/dailyCodingProblem77.cpp)

---


#### Problem No. 78

```
Given k sorted singly linked lists, write a function
to merge all the lists into one sorted singly linked list.
```
[Solution](data/dailyCodingProblem78.cpp)

---


#### Problem No. 79

```
Given an array of integers, write a function to determine whether the array
could become non-decreasing by modifying at most 1 element.

For example, given the array [10, 5, 7], you should return true,
since we can modify the 10 into a 1 to make the array non-decreasing.

Given the array [10, 5, 1], you should return false, since we
can't modify any one element to get a non-decreasing array.
```
[Solution](data/dailyCodingProblem79.cpp)

---


#### Problem No. 80

```
Given the root of a binary tree, return a deepest node.
For example, in the following tree, return d.

    a
   / \
  b   c
 /
d
```
[Solution](data/dailyCodingProblem80.cpp)

---


#### Problem No. 81

```
Given a mapping of digits to letters (as in a phone number),
and a digit string, return all possible letters the number
could represent. You can assume each valid number in the
mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …}
then “23” should return [“ad”, “ae”, “af”, “bd”, “be”,
“bf”, “cd”, “ce”, “cf"].
```
[Solution](data/dailyCodingProblem81.cpp)

---


#### Problem No. 82

```
Using a read7() method that returns 7 characters from a file,
implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”,
three read7() returns “Hello w”, “orld” and then “”.
```
[Solution](data/dailyCodingProblem82.cpp)

---


#### Problem No. 83

```
Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d
```
[Solution](data/dailyCodingProblem83.cpp)

---


#### Problem No. 84

```
Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
A 1 represents land and 0 represents water, so an island is a group of
1s that are neighboring and their perimiter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```
[Solution](data/dailyCodingProblem84.cpp)

---


#### Problem No. 85

```
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0,
using only mathematical or bit operations. You can assume b can only be 1 or 0.
```
[Solution](data/dailyCodingProblem85.cpp)

---


#### Problem No. 86

```
Given a string of parentheses, write a function to compute the minimum
number of parentheses to be removed to make the string valid
(i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1.
Given the string ")(", you should return 2,
since we must remove all of them.
```
[Solution](data/dailyCodingProblem86.cpp)

---


#### Problem No. 87

```
A rule looks like this:

A NE B

This means this means point A is located northeast of point B.

A SW C

means that point A is southwest of C.

Given a list of rules, check if the sum of the rules validate. For example:

A N B
B NE C
C N A
does not validate, since A cannot be both north and south of C.

A NW B
A N B
is considered valid.
```
[Solution](data/dailyCodingProblem87.cpp)

---


#### Problem No. 88

```
Implement division of two positive integers without using the division,
multiplication, or modulus operators. Return the quotient as an integer,
ignoring the remainder.
```
[Solution](data/dailyCodingProblem88.cpp)

---


#### Problem No. 89

```
Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right,
and satisfies the constraint that the key in the
left child must be less than or equal to the root
and the key in the right child must be greater
than or equal to the root.
```
[Solution](data/dailyCodingProblem89.cpp)

---


#### Problem No. 90

```
Given an integer n and a list of integers l,
write a function that randomly generates a
number from 0 to n-1 that isn't in l (uniform).
```
[Solution](data/dailyCodingProblem90.cpp)

---


#### Problem No. 91

```
What does the below code snippet print out?
How can we fix the anonymous functions to behave as we'd expect?

functions = []
for i in range(10):
    functions.append(lambda : i)

for f in functions:
    print(f())
```
[Solution](data/dailyCodingProblem91.py)

---


#### Problem No. 92

```
We're given a hashmap with a key courseId and value a list of courseIds,
which represents that the prerequsite of courseId is courseIds.
Return a sorted ordering of courses such that we can finish all courses.

Return null if there is no such ordering.

For example, given {'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []},
should return ['CSC100', 'CSC200', 'CSCS300'].
```
[Solution](data/dailyCodingProblem92.cpp)

---


#### Problem No. 93

```
Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.
```
[Solution](data/dailyCodingProblem93.cpp)

---


#### Problem No. 94

```
Given a binary tree of integers, find the maximum path sum between two nodes.
The path must go through at least one node, and does not need to go through the root.
```
[Solution](data/dailyCodingProblem94.cpp)

---


#### Problem No. 95

```
Given a number represented by a list of digits, find the next greater
permutation of a number, in terms of lexicographic ordering.
If there is not greater permutation possible, return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2].
The list [1,3,2] should return [2,1,3].
The list [3,2,1] should return [1,2,3].
```
[Solution](data/dailyCodingProblem95.cpp)

---


#### Problem No. 96

```
Given a number in the form of a list of digits,
return all possible permutations.

For example, given [1,2,3], return
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
```
[Solution](data/dailyCodingProblem96.cpp)

---


#### Problem No. 97

```
Write a map implementation with a get
function that lets you retrieve
the value of a key at a particular time.

It should contain the following methods:

set(key, value, time): sets key to value for t = time.
get(key, time): gets the key at t = time.
T
he map should work like this. If we set a key at a particular time,
it will maintain that value forever or until it gets set at a later
time. In other words, when we get a key at a time, it should return
the value that was set for that key set at the most recent time.

Consider the following examples:

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2
d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2
```
[Solution](data/dailyCodingProblem97.cpp)

---


#### Problem No. 98

```
Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

exists(board, "ABCCED") returns true, exists(board, "SEE")
returns true, exists(board, "ABCB") returns false.
```
[Solution](data/dailyCodingProblem98.cpp)

---


#### Problem No. 99

```
Given an unsorted array of integers, find the
length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2],
the longest consecutive element sequence
is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
```
[Solution](data/dailyCodingProblem99.cpp)

---


#### Problem No. 100

```
You are in an infinite 2D grid where you can move in any of the 8 directions:

 (x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
You are given a sequence of points and the order in which
you need to cover the points. Give the minimum number of
steps in which you can achieve it. You start from the first point.

Example:

Input: [(0, 0), (1, 1), (1, 2)]
Output: 2
It takes 1 step to move from (0, 0) to (1, 1).
It takes one more step to move from (1, 1) to (1, 2).
```
[Solution](data/dailyCodingProblem100.cpp)

---


#### Problem No. 101

```
Given an even number (greater than 2), return
two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
```
[Solution](data/dailyCodingProblem101.cpp)

---


#### Problem No. 102

```
Given a list of integers and a number K,
return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5]
and K is 9, then it should return [2, 3, 4].
```
[Solution](data/dailyCodingProblem102.cpp)

---


#### Problem No. 103

```
Given a string and a set of characters, return the shortest substring containing all the characters in the set.
For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
If there is no substring containing all the characters in the set, return null.
```
[Solution](data/dailyCodingProblem103.cpp)

---


#### Problem No. 104

```
Determine whether a doubly linked list is a palindrome.
What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns
true while 1 -> 4 returns false.
```
[Solution](data/dailyCodingProblem104.cpp)

---


#### Problem No. 106

```
Given an integer list where each number represents the number of hops you can make,
determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns true while [1, 1, 0, 1] returns false.
```
[Solution](data/dailyCodingProblem106.cpp)

---


#### Problem No. 107

```
Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.

  1
 / \
2   3
   / \
  4   5
```
[Solution](data/dailyCodingProblem107.cpp)

---


#### Problem No. 108

```
Given two strings A and B, return whether or
not A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true.
If A is abc and B is acb, return false.
```
[Solution](data/dailyCodingProblem108.cpp)

---


#### Problem No. 109

```
Given an unsigned 8-bit integer, swap its even and odd bits.
The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.

For example, 10101010 should be 01010101. 11100010 should be 11010001.

Bonus: Can you do this in one line?
```
[Solution](data/dailyCodingProblem109.cpp)

---


#### Problem No. 110

```
Given a binary tree, return all paths from the root to leaves.

For example, given the tree

   1
  / \
 2   3
    / \
   4   5

it should return [[1, 2], [1, 3, 4], [1, 3, 5]].
```
[Solution](data/dailyCodingProblem110.cpp)

---


#### Problem No. 111

```
Given a word W and a string S, find all
starting indices in S which are anagrams of W.

For example, given that W is "ab",
and S is "abxaba", return 0, 3, and 4.
```
[Solution](data/dailyCodingProblem111.cpp)

---


#### Problem No. 112

```
Given a binary tree, find the lowest common ancestor (LCA)
of two given nodes in the tree. Assume that each node
in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between
two nodes v and w as the lowest node in T that
has both v and w as descendants (where we allow
a node to be a descendant of itself).”
```
[Solution](data/dailyCodingProblem112.cpp)

---


#### Problem No. 113

```
Given a string of words delimited by spaces, reverse the words in string.
For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation,
can you perform this operation in-place?
```
[Solution](data/dailyCodingProblem113.cpp)

---


#### Problem No. 114

```
Given a string and a set of delimiters,
reverse the words in the string while
maintaining the relative order of the
delimiters.

For example, given "hello/world:here",
return "here/world:hello"

Follow-up: Does your solution work for
the following cases:
"hello/world:here/", "hello//world:here"
```
[Solution](data/dailyCodingProblem114.cpp)

---


#### Problem No. 115

```
Given two non-empty binary trees s and t, check whether tree t has exactly
the same structure and node values with a subtree of s.
A subtree of s is a tree consists of a node in s and all
of this node's descendants. The tree s could also
be considered as a subtree of itself.
```
[Solution](data/dailyCodingProblem115.cpp)

---


#### Problem No. 116

```
Generate a finite, but an arbitrarily large binary tree quickly in O(1).

That is, generate() should return a tree whose size is unbounded but finite.
```
[Solution](data/dailyCodingProblem116.cpp)

---


#### Problem No. 117

```
Given a binary tree, return the level of the tree with minimum sum.
```
[Solution](data/dailyCodingProblem117.cpp)

---


#### Problem No. 118

```
Given a sorted list of integers, square the
elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3],
return [0, 4, 4, 9, 81].
```
[Solution](data/dailyCodingProblem118.cpp)

---


#### Problem No. 119

```
Given a set of closed intervals, find the smallest set of numbers that
covers all the intervals. If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9],
one set of numbers that covers all these intervals is {3, 6}.
```
[Solution](data/dailyCodingProblem119.cpp)

---


#### Problem No. 121

```
Given a string which we can delete at most k,
return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2,
you could delete f and x to get 'waterretaw'.
```
[Solution](data/dailyCodingProblem121.cpp)

---


#### Problem No. 122

```
You are given a 2-d matrix where each cell represents number of coins in that cell.
Assuming we start at matrix[0][0], and can only move right or down,
find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1

The most we can collect is
0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
```
[Solution](data/dailyCodingProblem122.cpp)

---


#### Problem No. 123

```
Given a string, return whether it represents a number.
Here are the different kinds of numbers:

"10", a positive integer
"-10", a negative integer
"10.1", a positive real number
"-10.1", a negative real number
"1e5", a number in scientific notation

And here are examples of non-numbers:

"a"
"x 1"
"a -2"
"-"
```
[Solution](data/dailyCodingProblem123.cpp)

---


#### Problem No. 124

```
You have 100 fair coins and you flip them all at the same time.
Any that come up tails you set aside. The ones that come up heads you flip again.
How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of
rounds you'd expect to play until one coin remains.
```
[Solution](data/dailyCodingProblem124.cpp)

---


#### Problem No. 125

```
Given the root of a binary search tree, and a target K,
return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15

Return the nodes 5 and 15.
```
[Solution](data/dailyCodingProblem125.cpp)

---


#### Problem No. 126

```
Write a function that rotates a list by k elements.
For example, [1, 2, 3, 4, 5, 6] rotated by two becomes
[3, 4, 5, 6, 1, 2]. Try solving this without creating a copy of the list.
```
[Solution](data/dailyCodingProblem126.cpp)

---


#### Problem No. 127

```
Let's represent an integer in a linked list
format by having each node represent
a digit in the number. The nodes make
up the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5
is the number 54321.

Given two linked lists in this format,
return their sum in the same linked list format.

For example, given

9 -> 9
5 -> 2
return 124 (99 + 25) as:

4 -> 2 -> 1
```
[Solution](data/dailyCodingProblem127.cpp)

---


#### Problem No. 128

```
The Tower of Hanoi is a puzzle game with three rods and n disks, each a different size.

All the disks start off on the first rod in a stack. They are ordered by size,
with the largest disk on the bottom and the smallest one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:

You can only move one disk at a time.
A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.
You cannot place a larger disk on top of a smaller disk.
Write a function that prints out all the steps necessary to complete the Tower of Hanoi.
You should assume that the rods are numbered, with the first rod being 1,
the second (auxiliary) rod being 2, and the last (goal) rod being 3.

For example, with n = 3, we can do this in 7 moves:

Move 1 to 3
Move 1 to 2
Move 3 to 2
Move 1 to 3
Move 2 to 1
Move 2 to 3
Move 1 to 3
```
[Solution](data/dailyCodingProblem128.cpp)

---


#### Problem No. 129

```
Given a real number n, find the square root of n.
For example, given n = 9, return 3.
```
[Solution](data/dailyCodingProblem129.cpp)

---


#### Problem No. 130

```
Given an array of numbers representing the stock prices of a company in
chronological order and an integer k, return the maximum profit you can
make from k buys and sells. You must buy the stock before you can sell it,
and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
```
[Solution](data/dailyCodingProblem130.cpp)

---


#### Problem No. 131

```
Given the head to a singly linked list, where each node also has a “random” pointer
that points to anywhere in the linked list, deep clone the list.
```
[Solution](data/dailyCodingProblem131.cpp)

---


#### Problem No. 132

```
Design and implement a HitCounter class that keeps track of requests (or hits).
It should support the following operations:

record(timestamp): records a hit that happened at timestamp
total(): returns the total number of hits recorded
range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)

Follow-up: What if our system has limited memory?
```
[Solution](data/dailyCodingProblem132.cpp)

---


#### Problem No. 133

```
Given a node in a binary tree, return the next bigger element,
also known as the inorder successor.

For example, the inorder successor of 22 is 30.

   10
  /  \
 5    30
     /  \
   22    35

You can assume each node has a parent pointer.
```
[Solution](data/dailyCodingProblem133.cpp)

---


#### Problem No. 134

```
Use a more space-efficient data structure, SparseArray, that implements the same interface:

init(arr, size): initialize with the original large array and size.
set(i, val): updates index at i with val.
get(i): gets the value at index i
```
[Solution](data/dailyCodingProblem134.cpp)

---


#### Problem No. 135

```
For example, the minimum path in this tree is
[10, 5, 1, -1], which has sum 15.

  10
 /  \
5    5
 \     \
   2    1
       /
     -1
```
[Solution](data/dailyCodingProblem135.cpp)

---


#### Problem No. 136

```
Given an N by M matrix consisting only of 1's and 0's,
find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]

Return 4.
```
[Solution](data/dailyCodingProblem136.cpp)

---


#### Problem No. 137

```
Implement a bit array.

A bit array is a space efficient array that holds a value of 1 or 0 at each index.

init(size): initialize the array with size
set(i, val): updates index at i with val where val is either 1 or 0.
get(i): gets the value at index i.
```
[Solution](data/dailyCodingProblem137.cpp)

---


#### Problem No. 138

```
Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
```
[Solution](data/dailyCodingProblem138.cpp)

---


#### Problem No. 139

```
Given an iterator with methods next() and hasNext(), create a wrapper iterator,
PeekableInterface, which also implements peek(). peek shows the next
element that would be returned on next().

Here is the interface:

class PeekableInterface(object):
    def __init__(self, iterator):
        pass

    def peek(self):
        pass

    def next(self):
        pass

    def hasNext(self):
        pass
```
[Solution](data/dailyCodingProblem139.cpp)

---


#### Problem No. 140

```
Given an array of integers in which two elements appear exactly
once and all other elements appear exactly twice,
find the two elements that appear only once.
```
[Solution](data/dailyCodingProblem140.cpp)

---


#### Problem No. 141

```
Implement 3 stacks using a single list:

class Stack:
    def __init__(self):
        self.list = []

    def pop(self, stack_number):
        pass

    def push(self, item, stack_number):
        pass
```
[Solution](data/dailyCodingProblem141.cpp)

---


#### Problem No. 142

```
You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string.
Determine whether the parentheses are balanced.
For example, (()* and (*) are balanced. )*( is not balanced.
```
[Solution](data/dailyCodingProblem142.cpp)

---


#### Problem No. 143

```
Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10],
one partition may be [9, 3, 5, 10, 10, 12, 14].
```
[Solution](data/dailyCodingProblem143.cpp)

---


#### Problem No. 144

```
Given an array of numbers and an index i, return the index of
the nearest larger number of the number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are the equal, then return
any one of them. If the array at i doesn't have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array, can you do this in constant time?
```
[Solution](data/dailyCodingProblem144.cpp)

---


#### Problem No. 145

```
Given the head of a singly linked list, swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.
```
[Solution](data/dailyCodingProblem145.cpp)

---


#### Problem No. 146

```
Given a binary tree where all nodes are
either 0 or 1, prune the tree so that
subtrees containing all 0s are removed.

For example, given the following tree:

   0
  / \
 1   0
    / \
   1   0
  / \
 0   0

should be pruned to:

   0
  / \
 1   0
    /
   1

We do not remove the tree at the root or its left
child because it still has a 1 as a descendant.
```
[Solution](data/dailyCodingProblem146.cpp)

---


#### Problem No. 147

```
Given a list, sort it using this method: reverse(lst, i, j), which sorts lst from i to j`.
```
[Solution](data/dailyCodingProblem147.cpp)

---


#### Problem No. 148

```
Gray code is a binary code where each successive value differ in only one bit,
as well as when wrapping around. Gray code is common in hardware so
that we don't see temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
```
[Solution](data/dailyCodingProblem148.cpp)

---


#### Problem No. 149

```
Given a list of numbers L, implement a method sum(i, j) which
returns the sum from the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3)
should return sum([2, 3]), which is 5.

You can assume that you can do some pre-processing.
sum() should be optimized over the pre-processing step.
```
[Solution](data/dailyCodingProblem149.cpp)

---


#### Problem No. 150

```
Given a list of points, a central point, and an integer k,
find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)],
the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
```
[Solution](data/dailyCodingProblem150.cpp)

---


#### Problem No. 151

```
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C,
replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2),
and 'G' for green:

B B W
W W W
W W W
B B B

Becomes

B B G
G G G
G G G
B B B
```
[Solution](data/dailyCodingProblem151.cpp)

---


#### Problem No. 152

```
You are given n numbers as well as n probabilities that sum up to 1.
Write a function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities
[0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the time,
2 50% of the time, and 3 and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
```
[Solution](data/dailyCodingProblem152.cpp)

---


#### Problem No. 153

```
Find an efficient algorithm to find the smallest distance
(measured in number of words) between any two given words in a string.

For example, given words "hello", and "world" and a text
content of "dog cat hello cat dog dog hello cat world",
return 1 because there's only one word "cat" in between the two words.
```
[Solution](data/dailyCodingProblem153.cpp)

---


#### Problem No. 154

```
Implement a stack API using only a heap. A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element
(or throws an error if there is nothing on the stack)

Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
```
[Solution](data/dailyCodingProblem154.cpp)

---


#### Problem No. 155

```
Given a list of elements, find the majority element, which appears more than
half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0],
return 1.
```
[Solution](data/dailyCodingProblem155.cpp)

---


#### Problem No. 156

```
Given a positive integer n, find the smallest number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 3^2 + 2^2 = 9 + 4.

Given n = 27, return 3 since 27 = 3^2 + 3^2 + 3^2 = 9 + 9 + 9.
```
[Solution](data/dailyCodingProblem156.cpp)

---


#### Problem No. 157

```
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar,
which is a palindrome. daily should return false, since there's no rearrangement that can form a palindrome.
```
[Solution](data/dailyCodingProblem157.cpp)

---


#### Problem No. 158

```
You are given an N by M matrix of 0s and 1s. Starting from the top left corner,
how many ways are there to reach the bottom right corner?

You can only move right and down. 0 represents an empty space
while 1 represents a wall you cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]
Return two, as there are only two ways to get to the bottom right:

Right, down, down, right
Down, right, down, right

The top left corner and bottom right corner will always be 0.
```
[Solution](data/dailyCodingProblem158.cpp)

---


#### Problem No. 159

```
Given a string, return the first recurring character in it,
or null if there is no recurring character.

For example, given the string "acbbac", return "b".
Given the string "abcdef", return null.
```
[Solution](data/dailyCodingProblem159.cpp)

---


#### Problem No. 160

```
Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h

and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1,
the longest path would be c -> a -> d -> f, with a length of 17.
```
[Solution](data/dailyCodingProblem160.cpp)

---


#### Problem No. 161

```
Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000,
return 0000 1111 0000 1111 0000 1111 0000 1111.
```
[Solution](data/dailyCodingProblem161.cpp)

---


#### Problem No. 162

```
Given a list of words, return the shortest unique
prefix of each word. For example, given the list:

dog
cat
apple
apricot
fish

Return the list:

d
c
app
apr
f
```
[Solution](data/dailyCodingProblem162.cpp)

---


#### Problem No. 163

```
Given an arithmetic expression in Reverse Polish Notation,
write a program to evaluate it.

The expression is given as a list of numbers and operands.
For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-']
should return 5, since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

You can assume the given expression is always valid.
```
[Solution](data/dailyCodingProblem163.cpp)

---


#### Problem No. 164

```
You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}.
By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
```
[Solution](data/dailyCodingProblem164.cpp)

---


#### Problem No. 165

```
Given an array of integers, return a new array where each element in the new array
is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1
```
[Solution](data/dailyCodingProblem165.cpp)

---


#### Problem No. 166

```
Implement a 2D iterator class. It will be initialized with an array of arrays,
and should implement the following methods:

next(): returns the next element in the array of arrays. If there are no more elements,
raise an exception.
has_next(): returns whether or not the iterator still has elements left.
For example, given the input [[1, 2], [3], [], [4, 5, 6]],
calling next() repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays.
Some of the arrays can be empty.
```
[Solution](data/dailyCodingProblem166.cpp)

---


#### Problem No. 167

```
Given a list of words, find all pairs of unique indices such that the concatenation
of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"],
return [(0, 1), (1, 0), (2, 3)].

Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
```
[Solution](data/dailyCodingProblem167.cpp)

---


#### Problem No. 168

```
Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
you should return:

[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
Follow-up: What if you couldn't use any extra space?
```
[Solution](data/dailyCodingProblem168.cpp)

---


#### Problem No. 169

```
Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99.
```
[Solution](data/dailyCodingProblem169.cpp)

---


#### Problem No. 170

```
Given a start word, an end word, and a dictionary of valid words,
find the shortest transformation sequence from start to end such
that only one letter is changed at each step of the sequence,
and each transformed word exists in the dictionary.
If there is no possible transformation, return null.
Each word in the dictionary have the same length as
start and end and is lowercase.

For example, given start = "dog", end = "cat", and
dictionary = {"dot", "dop", "dat", "cat"}, return
["dog", "dot", "dat", "cat"].

Given start = "dog", end = "cat", and dictionary
= {"dot", "tod", "dat", "dar"}, return null as
there is no possible transformation from dog to cat.
```
[Solution](data/dailyCodingProblem170.cpp)

---


#### Problem No. 171

```
You are given a list of data entries that represent entries and exits
of groups of people into a building.

An entry looks like this:

{"timestamp": 1526579928, count: 3, "type": "enter"}
This means 3 people entered the building. An exit looks like this:

{"timestamp": 1526580382, count: 2, "type": "exit"}
This means that 2 people exited the building. timestamp is in Unix time.

Find the busiest period in the building, that is, the time with
the most people in the building. Return it as a pair of (start, end) timestamps.
You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
```
[Solution](data/dailyCodingProblem171.cpp)

---


#### Problem No. 172

```
Given a string s and a list of words words, where each word is the same length,
find all starting indices of substrings in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"],
return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return []
since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
```
[Solution](data/dailyCodingProblem172.cpp)

---


#### Problem No. 173

```
Write a function to flatten a nested dictionary.
Namespace the keys with a period.

For example, given the following dictionary:

{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}
it should become:

{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}

You can assume keys do not contain dots in them,
i.e. no clobbering will occur.
```
[Solution](data/dailyCodingProblem173.cpp)

---


#### Problem No. 175

```
You are given a starting state start, a list of transition probabilities for
a Markov chain, and a number of steps num_steps. Run the Markov chain
starting from start for num_steps and compute the number of times we visited each state.

For example, given the starting state a, number of steps 5000,
and the following transition probabilities:

[
  ('a', 'a', 0.9),
  ('a', 'b', 0.075),
  ('a', 'c', 0.025),
  ('b', 'a', 0.15),
  ('b', 'b', 0.8),
  ('b', 'c', 0.05),
  ('c', 'a', 0.25),
  ('c', 'b', 0.25),
  ('c', 'c', 0.5)
]

One instance of running this Markov chain might produce
{ 'a': 3012, 'b': 1656, 'c': 332 }.
```
[Solution](data/dailyCodingProblem175.cpp)

---


#### Problem No. 176

```
Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
```
[Solution](data/dailyCodingProblem176.cpp)

---


#### Problem No. 177

```
Given a linked list and a positive integer k, rotate the list to the right by k places.

For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.

Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2.
```
[Solution](data/dailyCodingProblem177.cpp)

---


#### Problem No. 178

```
Alice wants to join her school's Probability Student Club.
Membership dues are computed via one of two simple probabilistic games.

The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six.
Your number of rolls is the amount you pay, in dollars.

The second game: same, except that the stopping condition is a five followed by a five.

Which of the two games should Alice elect to play? Does it even matter?
Write a program to simulate the two games and calculate their expected value.
```
[Solution](data/dailyCodingProblem178.cpp)

---


#### Problem No. 179

```
Given the sequence of keys visited by a postorder traversal
of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, 
you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8
```
[Solution](data/dailyCodingProblem179.cpp)

---


#### Problem No. 180

```
Given a stack of N elements, interleave the first half of the stack with the second half
reversed using only one other queue. This should be done in-place.

Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.

For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3].
If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].

Hint: Try working backwards from the end state.
```
[Solution](data/dailyCodingProblem180.cpp)

---


#### Problem No. 181

```
Given a string, split it into as few strings as possible
such that each string is a palindrome.

For example, given the input string racecarannakayak,
return ["racecar", "anna", "kayak"].

Given the input string abc, return ["a", "b", "c"].
```
[Solution](data/dailyCodingProblem181.cpp)

---


#### Problem No. 182

```
A graph is minimally-connected if it is connected and there is no edge that can be
removed while still leaving the graph connected. For example, any binary tree is minimally-connected.

Given an undirected graph, check if the graph is minimally-connected.
You can choose to represent the graph as either an adjacency matrix or adjacency list.
```
[Solution](data/dailyCodingProblem182.cpp)

---


#### Problem No. 184

```
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
```
[Solution](data/dailyCodingProblem184.cpp)

---


#### Problem No. 185

```
Given two rectangles on a 2D graph, return the area of their intersection.
If the rectangles don't intersect, return 0.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
and

{
    "top_left": (0, 5),
    "dimensions" (4, 3) # width, height
}

return 6.
```
[Solution](data/dailyCodingProblem185.cpp)

---


#### Problem No. 186

```
Given an array of positive integers, divide the array into two subsets such that the
difference between the sum of the subsets is as small as possible.

For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20},
which has a difference of 5, which is the smallest possible difference.
```
[Solution](data/dailyCodingProblem186.cpp)

---


#### Problem No. 187

```
You are given given a list of rectangles represented by min and max x- and y-coordinates.
Compute whether or not a pair of rectangles overlap each other. If one rectangle
completely covers another, it is considered overlapping.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
return true as the first and third rectangle overlap each other.
```
[Solution](data/dailyCodingProblem187.cpp)

---


#### Problem No. 188

```
What will this code print out?

def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f()

How can we make it print out what we apparently want?
```
[Solution](data/dailyCodingProblem188.py)

---


#### Problem No. 189

```
Given an array of elements, return the length of the longest
subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1],
return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
```
[Solution](data/dailyCodingProblem189.cpp)

---


#### Problem No. 190

```
Given a circular array, compute its maximum subarray sum in O(n) time.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers
3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
```
[Solution](data/dailyCodingProblem190.cpp)

---


#### Problem No. 191

```
Given a collection of intervals, find the minimum number of intervals you
need to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they
won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8),
return 1 as the last interval can be removed and the first two won't overlap.

The intervals are not necessarily sorted in any order.
```
[Solution](data/dailyCodingProblem191.cpp)

---


#### Problem No. 192

```
You are given an array of nonnegative integers. Let's say you start
at the beginning of the array and are trying to advance to the end.
You can advance at most, the number of steps that you're currently on.
Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from
indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end,
so return false.
```
[Solution](data/dailyCodingProblem192.cpp)

---


#### Problem No. 193

```
Given a array of numbers representing the stock prices of a company in chronological order,
write a function that calculates the maximum profit you could have made from buying and selling that stock.
You're also given a number fee that represents a transaction fee for each buy and sell transaction.

You must buy before you can sell the stock, but you can make as many transactions as you like.

For example, given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9, since you could buy
the stock at 1 dollar, and sell at 8 dollars, and then buy it at 4 dollars and sell it at 10 dollars.
Since we did two transactions, there is a 4 dollar fee, so we have 7 + 6 = 13 profit minus 4 dollars of fees.
```
[Solution](data/dailyCodingProblem193.cpp)

---


#### Problem No. 194

```
Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0
and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n line segments
connecting each point pi to qi. Write an algorithm to determine how many pairs of the
line segments intersect.
```
[Solution](data/dailyCodingProblem194.cpp)

---


#### Problem No. 195

```
Given i1, j1, i2, and j2, compute the number of elements of M
smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]

And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15
numbers in the matrix smaller than 6 or greater than 23.
```
[Solution](data/dailyCodingProblem195.cpp)

---


#### Problem No. 196

```
Given the root of a binary tree, find the most frequent subtree sum.
The subtree sum of a node is the sum of all values under a node,
including the node itself.

For example, given the following tree:

  5
 / \
2  -5

Return 2 as it occurs twice: once as the left leaf,
and once as the sum of 2 + 5 - 5.
```
[Solution](data/dailyCodingProblem196.cpp)

---


#### Problem No. 197

```
Given an array and a number k that's smaller than the length of the array,
rotate the array to the right k elements in-place.
```
[Solution](data/dailyCodingProblem197.cpp)

---


#### Problem No. 198

```
Given a set of distinct positive integers, find the largest subset such that every pair
of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20].
Given [1, 3, 6, 24], return [1, 3, 6, 24].
```
[Solution](data/dailyCodingProblem198.cpp)

---


#### Problem No. 199

```
Given a string of parentheses, find the balanced string that can be produced
from it using the minimum number of insertions and deletions.
If there are multiple solutions, return any of them.

For example, given "(()", you could return "(())". Given "))()(",
you could return "()()()()".
```
[Solution](data/dailyCodingProblem199.cpp)

---


#### Problem No. 200

```
Let X be a set of n intervals on the real line.
We say that a set of points P "stabs" X if every
interval in X contains at least one point in P.
Compute the smallest set of points that stabs X.

For example, given the intervals
[(1, 4), (4, 5), (7, 9), (9, 12)],
you should return [4, 9].
```
[Solution](data/dailyCodingProblem200.cpp)

---


#### Problem No. 201

```
You are given an array of arrays of integers, where each array corresponds
to a row in a triangle of numbers. For example, [[1], [2, 3], [1, 5, 1]]
represents the triangle:

  1
 2 3
1 5 1

We define a path in the triangle to start at the top and go down one
row at a time to an adjacent value, eventually ending with an entry
on the bottom row. For example, 1 -> 3 -> 5. The weight of the path
is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
```
[Solution](data/dailyCodingProblem201.cpp)

---


#### Problem No. 202

```
Write a program that checks whether an integer is a palindrome.
For example, 121 is a palindrome, as well as 888. 678 is not a palindrome.
Do not convert the integer into a string.
```
[Solution](data/dailyCodingProblem202.cpp)

---


#### Problem No. 203

```
Suppose an array sorted in ascending order is rotated at some pivot unknown
to you beforehand. Find the minimum element in O(log N) time.
You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
```
[Solution](data/dailyCodingProblem203.cpp)

---


#### Problem No. 204

```
Given a complete binary tree, count the number of nodes in faster than O(n) time.
Recall that a complete binary tree has every level filled except the last,
and the nodes in the last level are filled starting from the left.

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
```
[Solution](data/dailyCodingProblem204.cpp)

---


#### Problem No. 205

```
Given an integer, find the next permutation of it in absolute order.
For example, given 48975, the next permutation would be 49578.
```
[Solution](data/dailyCodingProblem205.cpp)

---


#### Problem No. 206

```
A permutation can be specified by an array P, where P[i] represents
the location of the element at i in the permutation. For example,
[2, 1, 0] represents the permutation where elements at the index
0 and 2 are swapped.

Given an array and a permutation, apply the permutation to the array.
For example, given the array ["a", "b", "c"] and the permutation
[2, 1, 0], return ["c", "b", "a"].
```
[Solution](data/dailyCodingProblem206.cpp)

---


#### Problem No. 207

```
Given an undirected graph G, check whether it is bipartite.
Recall that a graph is bipartite if its vertices can be
divided into two independent sets, U and V, such that
no edge connects vertices of the same set.
```
[Solution](data/dailyCodingProblem207.cpp)

---


#### Problem No. 208

```
Given a linked list of numbers and a pivot k, partition the linked list so
that all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3,
the solution could be 1 -> 0 -> 5 -> 8 -> 3.
```
[Solution](data/dailyCodingProblem208.cpp)

---


#### Problem No. 209

```
Write a program that computes the length of the longest common subsequence of three given strings.
For example, given "epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious",
it should return 5, since the longest common subsequence is "eieio".
```
[Solution](data/dailyCodingProblem209.cpp)

---


#### Problem No. 210

```
A Collatz sequence in mathematics can be defined as follows.
Starting with any positive integer:

if n is even, the next number in the sequence is n / 2
if n is odd, the next number in the sequence is 3n + 1

It is conjectured that every such sequence eventually
reaches the number 1. Test this conjecture.

Bonus: What input n <= 1000000 gives the longest sequence?
```
[Solution](data/dailyCodingProblem210.cpp)

---


#### Problem No. 211

```
Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string.
For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].
```
[Solution](data/dailyCodingProblem211.cpp)

---


#### Problem No. 212

```
Spreadsheets often use this alphabetical encoding for its columns:
"A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id. For example,
given 1, return "A". Given 27, return "AA".
```
[Solution](data/dailyCodingProblem212.cpp)

---


#### Problem No. 213

```
Given a string of digits, generate all possible valid IP address combinations.

IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers
between 0 and 255. Zero-prefixed numbers, such as 01 and 065, are not allowed,
except for 0 itself.

For example, given "2542540123",
you should return ['254.25.40.123', '254.254.0.123'].
```
[Solution](data/dailyCodingProblem213.cpp)

---


#### Problem No. 214

```
Given an integer n, return the length of the longest
consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
```
[Solution](data/dailyCodingProblem214.cpp)

---


#### Problem No. 215

```
The horizontal distance of a binary tree node describes how far left or right the
node will be when the tree is printed out.

More rigorously, we can define it as follows:

The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.
For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8
The bottom view of a tree, then, consists of the lowest node at each
horizontal distance. If there are two nodes at the same depth and
horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
```
[Solution](data/dailyCodingProblem215.cpp)

---


#### Problem No. 216

```
Given a number in Roman numeral format, convert it to decimal.

The values of Roman numerals are as follows:

{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
In addition, note that the Roman numeral system
uses subtractive notation for numbers such as IV and XL.

For the input XIV, for instance, you should return 14.
```
[Solution](data/dailyCodingProblem216.cpp)

---


#### Problem No. 217

```
We say a number is sparse if there are no adjacent ones in its binary representation.
For example, 21 (10101) is sparse, but 22 (10110) is not. For a given input N,
find the smallest sparse number greater than or equal to N.

Do this in faster than O(N log N) time.
```
[Solution](data/dailyCodingProblem217.cpp)

---


#### Problem No. 218

```
Write an algorithm that computes the reversal of a directed graph.
For example, if a graph consists of A -> B -> C, it should become A <- B <- C.
```
[Solution](data/dailyCodingProblem218.cpp)

---


#### Problem No. 219

```
Connect 4 is a game where opponents take turns dropping
red or black discs into a 7 x 6 vertically suspended grid.
The game ends either when one player creates a line of four
consecutive discs of their color (horizontally, vertically,
or diagonally), or when there are no more spots left in the grid.

Design and implement Connect 4.
```
[Solution](data/dailyCodingProblem219.cpp)

---


#### Problem No. 220

```
In front of you is a row of N coins, with values v1, v1, ..., vn.

You are asked to play the following game. You and an opponent take
turns choosing either the first or last coin from the row, removing
it from the row, and receiving the value of the coin.

Write a program that returns the maximum amount of money you can win
with certainty, if you move first, assuming your opponent plays optimally.
```
[Solution](data/dailyCodingProblem220.cpp)

---


#### Problem No. 221

```
Let's define a "sevenish" number to be one which is either a power of 7,
or the sum of unique powers of 7. The first few sevenish numbers are
1, 7, 8, 49, and so on. Create an algorithm to find the nth sevenish number.
```
[Solution](data/dailyCodingProblem221.cpp)

---


#### Problem No. 222

```
Given an absolute pathname that may
have . or .. as part of it,
return the shortest standardized path.

For example,
given "/usr/bin/../bin/./scripts/../",
return "/usr/bin/".
```
[Solution](data/dailyCodingProblem222.cpp)

---


#### Problem No. 223

```
Typically, an implementation of in-order traversal of a binary tree has O(h)
space complexity, where h is the height of the tree. Write a program to
compute the in-order traversal of a binary tree using O(1) space.
```
[Solution](data/dailyCodingProblem223.cpp)

---


#### Problem No. 224

```
Given a sorted array, find the smallest positive integer
that is not the sum of a subset of the array.

For example, for the input [1, 2, 3, 10],
you should return 7.

Do this in O(N) time.
```
[Solution](data/dailyCodingProblem224.cpp)

---


#### Problem No. 225

```
There are N prisoners standing in a circle, waiting to be executed.
The executions are carried out starting with the kth person,
and removing every successive kth person going clockwise
until there is no one left.

Given N and k, write an algorithm to determine where a
prisoner should stand in order to be the last survivor.

For example, if N = 5 and k = 2, the order of executions
would be [2, 4, 1, 5, 3], so you should return 3.

Bonus: Find an O(log N) solution if k = 2.
```
[Solution](data/dailyCodingProblem225.cpp)

---


#### Problem No. 226

```
You come across a dictionary of sorted words in a language you've never seen before.
Write a program that returns the correct order of letters in this language.

For example, given ['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'],
you should return ['x', 'z', 'w', 'y'].
```
[Solution](data/dailyCodingProblem226.cpp)

---


#### Problem No. 227

```
Boggle is a game played on a 4 x 4 grid of letters.
The goal is to find as many words as possible that
can be formed by a sequence of adjacent letters in
the grid, using each cell at most once. Given a game
board and a dictionary of valid words, implement a Boggle solver.
```
[Solution](data/dailyCodingProblem227.cpp)

---


#### Problem No. 228

```
Given a list of numbers, create an algorithm that arranges them in order
to form the largest possible integer. For example, given [10, 7, 76, 415],
you should return 77641510.
```
[Solution](data/dailyCodingProblem228.cpp)

---


#### Problem No. 229

```
Snakes and Ladders is a game played on a 10 x 10 board, the goal of which is get
from square 1 to square 100. On each turn players will roll a six-sided die and
move forward a number of spaces equal to the result. If they land on a square
that represents a snake or ladder, they will be transported ahead or behind,
respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenience, here are the squares representing snakes and ladders, and their outcomes:

snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
```
[Solution](data/dailyCodingProblem229.cpp)

---


#### Problem No. 230

```
You are given N identical eggs and access to a building with k floors.
Your task is to find the lowest floor that will cause an egg to break,
if dropped from that floor. Once an egg breaks, it cannot be dropped again.
If an egg breaks when dropped from the xth floor, you can assume
it will also break when dropped from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops it will take,
in the worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping the egg at every floor,
beginning with the first, until we reach the fifth floor, so our solution will be 5.
```
[Solution](data/dailyCodingProblem230.cpp)

---


#### Problem No. 231

```
Given a string with repeated characters, rearrange the string so that no two adjacent
characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
```
[Solution](data/dailyCodingProblem231.cpp)

---


#### Problem No. 232

```
Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map. If the key already exists, overwrite the value.
sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.

For example, you should be able to run the following code:
mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
```
[Solution](data/dailyCodingProblem232.cpp)

---


#### Problem No. 233

```
Implement the function fib(n), which returns the nth
number in the Fibonacci sequence, using only O(1) space.
```
[Solution](data/dailyCodingProblem233.cpp)

---


#### Problem No. 234

```
Recall that the minimum spanning tree is the subset of edges of a tree that connect
all its vertices with the smallest possible total edge weight.
Given an undirected graph with weighted edges, compute the maximum weight spanning tree.
```
[Solution](data/dailyCodingProblem234.cpp)

---


#### Problem No. 235

```
Given an array of numbers of length N, find both
the minimum and maximum using less than 2 * (N - 2) comparisons.
```
[Solution](data/dailyCodingProblem235.cpp)

---


#### Problem No. 237

```
A tree is symmetric if its data and shape remain unchanged when it is
reflected about the root node. The following tree is an example:

        4
      / | \
    3   5   3
  /           \
9              9

Given a k-ary tree, determine whether it is symmetric.
```
[Solution](data/dailyCodingProblem237.cpp)

---


#### Problem No. 239

```
One way to unlock an Android phone is through a pattern of swipes across a 1-9 keypad.

For a pattern to be valid, it must satisfy the following:

All of its keys must be distinct.
It must not connect two keys by jumping over a third key, unless that key has already been used.
For example, 4 - 2 - 1 - 7 is a valid pattern, whereas 2 - 1 - 7 is not.

Find the total number of valid unlock patterns of length N, where 1 <= N <= 9.
```
[Solution](data/dailyCodingProblem239.cpp)

---


#### Problem No. 240

```
There are N couples sitting in a row of length 2 * N.
They are currently ordered randomly, but would like to rearrange
themselves so that each couple's partners can sit side by side.

What is the minimum number of swaps necessary for this to happen?
```
[Solution](data/dailyCodingProblem240.cpp)

---


#### Problem No. 241

```
In academia, the h-index is a metric used to calculate the impact
of a researcher's papers. It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each.
If there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each
paper are [4, 3, 0, 1, 5]. Then the h-index would be 3, since the
researcher has 3 papers with at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.
```
[Solution](data/dailyCodingProblem241.cpp)

---


#### Problem No. 242

```
You are given an array of length 24, where each element represents the number of new
subscribers during the corresponding hour. Implement a data structure
that efficiently supports the following:

update(hour: int, value: int): Increment the element at index hour by value.
query(start: int, end: int): Retrieve the number of subscribers that have
signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day,
and that you will not be asked for start and end values that wrap around midnight.
```
[Solution](data/dailyCodingProblem242.cpp)

---


#### Problem No. 243

```
Given an array of numbers N and an integer k, your task is to split N into
k partitions such that the maximum sum of any partition is minimized.
Return this sum.

For example, given N = [5, 1, 2, 7, 3, 4] and k = 3, you should return 8,
since the optimal partition is [5, 1, 2], [7], [3, 4].
```
[Solution](data/dailyCodingProblem243.cpp)

---


#### Problem No. 244

```
The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N.
The method is to take increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would first mark [4, 6, 8, ...]
(multiples of two), then [6, 9, 12, ...] (multiples of three), and so on.
Once we have done this for all primes less than N, the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely
(that is, without taking N as an input).
```
[Solution](data/dailyCodingProblem244.cpp)

---


#### Problem No. 245

```
You are given an array of integers, where each element represents the maximum number of
steps that can be jumped going forward from that element. Write a function to return
the minimum number of jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2,
as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
```
[Solution](data/dailyCodingProblem245.cpp)

---


#### Problem No. 246

```
Given a list of words, determine whether the words can be chained to form a circle.
A word X can be placed in front of another word Y in a circle if the last character
of X is same as the first character of Y.

For example, the words ['chair', 'height', 'racket', touch', 'tunic'] can
form the following circle: chair --> racket --> touch --> height --> tunic --> chair.
```
[Solution](data/dailyCodingProblem246.cpp)

---


#### Problem No. 247

```
Given a binary tree, determine whether or not it is height-balanced.
A height-balanced binary tree can be defined as one in which the heights
of the two subtrees of any node never differ by more than one.
```
[Solution](data/dailyCodingProblem247.cpp)

---


#### Problem No. 248

```
Find the maximum of two numbers without using any
if-else statements, branching, or direct comparisons.
```
[Solution](data/dailyCodingProblem248.cpp)

---


#### Problem No. 249

```
Given an array of integers, find the maximum XOR of any two elements.
```
[Solution](data/dailyCodingProblem249.cpp)

---


#### Problem No. 250

```
A cryptarithmetic puzzle is a mathematical game where the digits of some numbers
are represented by letters. Each letter represents a unique digit.

For example, a puzzle of the form:

  SEND
+ MORE
--------
 MONEY

may have the solution:
{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}

Given a three-word puzzle like the one above,
create an algorithm that finds a solution.
```
[Solution](data/dailyCodingProblem250.cpp)

---


#### Problem No. 252

```
The ancient Egyptians used to express fractions as a sum of several
terms where each numerator is one. For example, 4 / 13 can be
represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary
fraction a / b, where a < b,
into an Egyptian fraction.
```
[Solution](data/dailyCodingProblem252.cpp)

---


#### Problem No. 253

```
Given a string and a number of lines k, print the string in zigzag form.
In zigzag, characters are printed out diagonally from top left to bottom
right until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
```
[Solution](data/dailyCodingProblem253.cpp)

---


#### Problem No. 254

```
Recall that a full binary tree is one in which each node is either a leaf node,
or has two children. Given a binary tree,
convert it to a full one by removing nodes with only one child.

For example, given the following tree:

         0
      /     \
    1         2
  /            \
3                 4
  \             /   \
    5          6     7

You should convert it to:

     0
  /     \
5         4
        /   \
       6     7
```
[Solution](data/dailyCodingProblem254.cpp)

---


#### Problem No. 255

```
The transitive closure of a graph is a measure of which vertices are reachable
from other vertices. It can be represented as a matrix M, where M[i][j] == 1
if there is a path between vertices i and j, and otherwise 0.

For example, suppose we are given the following graph in adjacency list form:

graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]

The transitive closure of this graph would be:

[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]

Given a graph, find its transitive closure.
```
[Solution](data/dailyCodingProblem255.cpp)

---


#### Problem No. 256

```
Given a linked list, rearrange the node values such that
they appear in alternating low -> high -> low -> high ... form.
For example, given 1 -> 2 -> 3 -> 4 -> 5, you should
return 1 -> 3 -> 2 -> 5 -> 4.
```
[Solution](data/dailyCodingProblem256.cpp)

---


#### Problem No. 257

```
Given an array of integers out of order, determine the bounds of the smallest
window that must be sorted in order for the entire array to be sorted.
For example, given [3, 7, 5, 6, 9], you should return (1, 3).
```
[Solution](data/dailyCodingProblem257.cpp)

---


#### Problem No. 258

```
In Ancient Greece, it was common to write text with the first line going left to right,
the second line going right to left, and continuing to go back and forth.
This style was called "boustrophedon".

Given a binary tree, write an algorithm to print the nodes in boustrophedon order.

For example, given the following tree:

       1
    /     \
  2         3
 / \       / \
4   5     6   7

You should return [1, 3, 2, 4, 5, 6, 7].
```
[Solution](data/dailyCodingProblem258.cpp)

---


#### Problem No. 260

```
The sequence [0, 1, ..., N] has been jumbled, and the only clue you have for
its order is an array representing whether each number is larger or smaller
than the last. Given this information, reconstruct an array that is
consistent with it. For example, given [None, +, +, -, +],
you could return [1, 2, 3, 0, 4].
```
[Solution](data/dailyCodingProblem260.cpp)

---


#### Problem No. 261

```
Huffman coding is a method of encoding characters based on their frequency.
Each letter is assigned a variable-length binary string, such as 0101 or 111110,
where shorter lengths correspond to more common letters. To accomplish this,
a binary tree is built such that the path from the root to any leaf uniquely
maps to a character. When traversing the path, descending to a left child
corresponds to a 0 in the prefix, while descending right corresponds to 1.

Here is an example tree (note that only the leaf nodes have letters):

        *
      /   \
    *       *
   / \     / \
  *   a   t   *
 /             \
c               s

With this encoding, cats would be represented as 0000110111.

Given a dictionary of character frequencies, build a Huffman tree,
and use it to determine a mapping between characters and their encoded binary strings.
```
[Solution](data/dailyCodingProblem261.cpp)

---


#### Problem No. 262

```
A bridge in a connected (undirected) graph is an edge that, if removed,
causes the graph to become disconnected. Find all the bridges in a graph.
```
[Solution](data/dailyCodingProblem262.cpp)

---


#### Problem No. 264

```
Given a set of characters C and an integer k, a De Bruijn sequence is a cyclic
sequence in which every possible k-length string of characters in C occurs exactly once.

For example, suppose C = {0, 1} and k = 3. Then our sequence should
contain the substrings {'000', '001', '010', '011', '100', '101', '110', '111'},
and one possible solution would be 00010111.

Create an algorithm that finds a De Bruijn sequence.
```
[Solution](data/dailyCodingProblem264.cpp)

---


#### Problem No. 265

```
MegaCorp wants to give bonuses to its employees based on how many lines of codes
they have written. They would like to give the smallest positive amount to each
worker consistent with the constraint that if a developer has written more
lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp,
determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
```
[Solution](data/dailyCodingProblem265.cpp)

---


#### Problem No. 266

```
A step word is formed by taking a given word,
adding a letter, and anagramming the result.
For example, starting with the word "APPLE",
you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word,
create a function that returns all valid step words.
```
[Solution](data/dailyCodingProblem266.cpp)

---


#### Problem No. 267

```
You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board.
The only pieces on the board are the black king and various white pieces.
Given this matrix, determine whether the king is in check.

For details on how each piece moves, see here.

For example, given the following matrix:

...K....
........
.B......
......P.
.......R
..N.....
........
.....Q..

You should return True, since the bishop is attacking the king diagonally.
```
[Solution](data/dailyCodingProblem267.cpp)

---


#### Problem No. 268

```
Given a 32-bit positive integer N, determine whether it
is a power of four in faster than O(log N) time.
```
[Solution](data/dailyCodingProblem268.cpp)

---


#### Problem No. 269

```
You are given an string representing the initial conditions of some dominoes.

Each element can take one of three values:
L, meaning the domino has just been pushed to the left,
R, meaning the domino has just been pushed to the right, or
., meaning the domino is standing still.

Determine the orientation of each tile when the dominoes stop falling.

Note that if a domino receives a force from the left and right
side simultaneously, it will remain upright.

For example, given the string .L.R....L, you should return LL.RRRLLL.

Given the string ..R...L.L, you should return ..RR.LLLL.
```
[Solution](data/dailyCodingProblem269.cpp)

---


#### Problem No. 270

```
A network consists of nodes labeled 0 to N.
You are given a list of edges (a, b, t),
describing the time t it takes for a
message to be sent from node a to node b.
Whenever a node receives a message,
it immediately passes the message on
to a neighboring node, if possible.

Assuming all nodes are connected,
determine how long it will take for
every node to receive a message
that begins at node 0.

For example, given N = 5, and the following edges:

edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
You should return 9, because propagating
the message from 0 -> 2 -> 3 -> 4
will take that much time.
```
[Solution](data/dailyCodingProblem270.cpp)

---


#### Problem No. 271

```
Given a sorted list of integers of length N, determine if an element x
is in the list without performing any multiplication, division, or bit-shift operations.

Do this in O(log N) time.
```
[Solution](data/dailyCodingProblem271.cpp)

---


#### Problem No. 272

```
Write a function, throw_dice(N, faces, total), that determines how many ways it is possible
to throw N dice with some number of faces each to get a specific total.

For example, throw_dice(3, 6, 7) should equal 15.
```
[Solution](data/dailyCodingProblem272.cpp)

---


#### Problem No. 273

```
A fixed point in an array is an element whose value is equal to its index.
Given a sorted array of distinct elements, return a fixed point, if one exists.
Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2.
Given [1, 5, 7, 8], you should return False.
```
[Solution](data/dailyCodingProblem273.cpp)

---


#### Problem No. 275

```
The "look and say" sequence is defined as follows: beginning with the term 1,
each subsequent term visually describes the digits appearing in the previous term.
The first few terms are as follows:

1
11
21
1211
111221
As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

Given an integer N, print the Nth term of this sequence.
```
[Solution](data/dailyCodingProblem275.cpp)

---


#### Problem No. 276

```
That is, given a string of length N and a pattern of length k,
write a program that searches for the pattern in the string
with less than O(N * k) worst-case time complexity.

If the pattern is found, return the start index
of its location. If not, return False.
```
[Solution](data/dailyCodingProblem276.cpp)

---


#### Problem No. 277

```
UTF-8 is a character encoding that maps each symbol to one, two, three, or four bytes.

For example, the Euro sign, €, corresponds to
the three bytes 11100010 10000010 10101100.

The rules for mapping characters are as follows:

For a single-byte character, the first bit must be zero.
For an n-byte character, the first byte starts with n ones and a zero.
The other n - 1 bytes all start with 10.

Visually, this can be represented as follows.

 Bytes   |           Byte format
-----------------------------------------------
   1     | 0xxxxxxx
   2     | 110xxxxx 10xxxxxx
   3     | 1110xxxx 10xxxxxx 10xxxxxx
   4     | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Write a program that takes in an array of integers representing byte values,
and returns whether it is a valid UTF-8 encoding.
```
[Solution](data/dailyCodingProblem277.cpp)

---


#### Problem No. 278

```
Given an integer N, construct all possible binary search trees with N nodes.
```
[Solution](data/dailyCodingProblem278.cpp)

---


#### Problem No. 279

```
A classroom consists of N students, whose friendships
can be represented in an adjacency list.
For example, the following descibes a situation where 0 is
friends with 1 and 2, 3 is friends with 6, and so on.

{0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]} 

Each student can be placed in a friend group,
which can be defined as the transitive closure of
that student's friendship relations. In other words,
this is the smallest set such that no student in the
group has any friends outside this group.
For the example above, the friend groups
would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above,
determine the number of friend groups in the class.
```
[Solution](data/dailyCodingProblem279.cpp)

---


#### Problem No. 280

```
Given an undirected graph, determine if it contains a cycle.
```
[Solution](data/dailyCodingProblem280.cpp)

---


#### Problem No. 281

```
A wall consists of several rows of bricks of various integer lengths and uniform height.
Your goal is to find a vertical line going from the top to the bottom of the wall
that cuts through the fewest number of bricks. If the line goes through the edge
between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values in each
row represent the lengths of bricks in that row:

[[3, 5, 1, 1],
 [2, 3, 3, 2],
 [5, 5],
 [4, 4, 2],
 [1, 3, 3, 3],
 [1, 1, 6, 1, 1]]
The best we can we do here is to draw a line after the eighth brick,
which will only require cutting through the bricks in the third and fifth row.

Given an input consisting of brick lengths for each row such as the one above,
return the fewest number of bricks that must be cut to create a vertical line.
```
[Solution](data/dailyCodingProblem281.cpp)

---


#### Problem No. 282

```
Given an array of integers, determine whether it contains a Pythagorean triplet.
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.
```
[Solution](data/dailyCodingProblem282.cpp)

---


#### Problem No. 283

```
A regular number in mathematics is defined as one which evenly divides some power of 60.
Equivalently, we can say that a regular number is one whose only prime divisors are 2, 3, and 5.

These numbers have had many applications, from helping ancient
Babylonians keep time to tuning instruments according to the diatonic scale.

Given an integer N, write a program that returns, in order, the first N regular numbers.
```
[Solution](data/dailyCodingProblem283.cpp)

---


#### Problem No. 284

```
Two nodes in a binary tree can be called cousins if they are on the same
level of the tree but have different parents. For example,
in the following diagram 4 and 6 are cousins.

    1
   / \
  2   3
 / \   \
4   5   6
Given a binary tree and a particular node, find all cousins of that node.
```
[Solution](data/dailyCodingProblem284.cpp)

---


#### Problem No. 285

```
You are given an array representing the heights of neighboring buildings on a city street,
from east to west. The city assessor would like you to write an algorithm that returns
how many of these buildings have a view of the setting sun, in order to properly value the street.

For example, given the array [3, 7, 8, 3, 6, 1], you should return 3,
since the top floors of the buildings with heights 8, 6,
and 1 all have an unobstructed view to the west.

Can you do this using just one forward pass through the array?
```
[Solution](data/dailyCodingProblem285.cpp)

---


#### Problem No. 286

```
The skyline of a city is composed of several buildings of various widths and heights,
possibly overlapping one another when viewed from a distance.
We can represent the buildings using an array of (left, right, height) tuples,
which tell us where on an imaginary x-axis a building begins and ends, and how tall it is.
The skyline itself can be described by a list of (x, height) tuples,
giving the locations at which the height visible to a distant observer changes, and each new height.

Given an array of buildings as described above, create a function that returns the skyline.

For example, suppose the input consists of the buildings [(0, 15, 3), (4, 11, 5), (19, 23, 4)].
In aggregate, these buildings would create a skyline that looks like the one below.

     ______  
    |      |        ___
 ___|      |___    |   | 
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
As a result, your function should return [(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)].
```
[Solution](data/dailyCodingProblem286.cpp)

---


#### Problem No. 287

```
You are given a list of (website, user) pairs that represent users visiting websites.
Come up with a program that identifies the top k pairs of websites with the greatest similarity.

For example, suppose k = 1, and the list of tuples is:

[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5)
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e': 5), ('e', 6)]

Then a reasonable similarity metric would most likely conclude 
that a and e are the most similar, so your program should return [('a', 'e')].
```
[Solution](data/dailyCodingProblem287.cpp)

---


#### Problem No. 288

```
The number 6174 is known as Kaprekar's contant,
after the mathematician who discovered an associated property:
for all four-digit numbers with at least two distinct digits,
repeatedly applying a simple procedure eventually results in this value.

The procedure is as follows:

For a given input x, create two new numbers that consist of the digits in x in ascending and descending order.
Subtract the smaller number from the larger number.
For example, this algorithm terminates in three steps when starting from 1234:

4321 - 1234 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174

Write a function that returns how
many steps this will take for a given input N.
```
[Solution](data/dailyCodingProblem288.cpp)

---


#### Problem No. 289

```
The game of Nim is played as follows. Starting with three heaps,
each containing a variable number of items, two players take turns
removing one or more items from a single pile.
The player who eventually is forced to take the last stone loses.
For example, if the initial heap sizes are 3, 4, and 5, a game could be played as shown below:

  A  |  B  |  C
-----------------
  3  |  4  |  5
  3  |  1  |  3
  3  |  1  |  3
  0  |  1  |  3
  0  |  1  |  0
  0  |  0  |  0 
In other words, to start, the first player takes three items from pile B.
The second player responds by removing two stones from pile C.
The game continues in this way until player one takes last stone and loses.

Given a list of non-zero starting values [a, b, c], and assuming optimal play,
determine whether the first player has a forced win
```
[Solution](data/dailyCodingProblem289.cpp)

---


#### Problem No. 290

```
On a mysterious island there are creatures known as Quxes which come in
three colors: red, green, and blue. One power of the Qux is that
if two of them are standing next to each other, they can transform
into a single creature of the third color.

Given N Quxes standing in a line, determine the smallest number of
them remaining after any possible sequence of such transformations.

For example, given the input ['R', 'G', 'B', 'G', 'B'], it is
possible to end up with a single Qux through the following steps:

        Arrangement       |   Change
----------------------------------------
['R', 'G', 'B', 'G', 'B'] | (R, G) -> B
['B', 'B', 'G', 'B']      | (B, G) -> R
['B', 'R', 'B']           | (R, B) -> G
['B', 'G']                | (B, G) -> R
['R']                     |
```
[Solution](data/dailyCodingProblem290.cpp)

---


#### Problem No. 291

```
An imminent hurricane threatens the coastal town of Codeville.
If at most two people can fit in a rescue boat,
and the maximum weight limit for a given boat is k,
determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80]
and a boat limit of 200, the smallest number of boats required will be three.
```
[Solution](data/dailyCodingProblem291.cpp)

---


#### Problem No. 292

```
A teacher must divide a class of students into two teams to play dodgeball.
Unfortunately, not all the kids get along, and several
refuse to be put on the same team as that of their enemies.

Given an adjacency list of students and their enemies,
write an algorithm that finds a satisfactory pair of teams,
or returns False if none exists.

For example, given the following enemy graph
you should return the teams {0, 1, 4, 5} and {2, 3}.

students = {
    0: [3],
    1: [2],
    2: [1, 4],
    3: [0, 4, 5],
    4: [2, 3],
    5: [3]
}

On the other hand, given the input below,
you should return False.

students = {
    0: [3],
    1: [2],
    2: [1, 3, 4],
    3: [0, 2, 4, 5],
    4: [2, 3],
    5: [3]
}
```
[Solution](data/dailyCodingProblem292.cpp)

---


#### Problem No. 293

```
You have N stones in a row, and would like to create from them a pyramid.
This pyramid should be constructed such that the height of each stone
increases by one until reaching the tallest stone, after which the
heights decrease by one. In addition, the start and end stones of
the pyramid should each be one stone high.

You can change the height of any stone by paying a cost of 1 unit
to lower its height by 1, as many times as necessary. Given this
information, determine the lowest cost method to produce this pyramid.

For example, given the stones [1, 1, 3, 3, 2, 1], the optimal
solution is to pay 2 to create [0, 1, 2, 3, 2, 1].
```
[Solution](data/dailyCodingProblem293.cpp)

---


#### Problem No. 294

```
A competitive runner would like to create a route that starts and ends at his house,
with the condition that the route goes entirely uphill at first, and then entirely downhill.

Given a dictionary of places of the form {location: elevation},
and a dictionary mapping paths between some of these locations
to their corresponding distances, find the length of the shortest
route satisfying the condition above. Assume the runner's home is location 0.

For example, suppose you are given the following input:

elevations = {0: 5, 1: 25, 2: 15, 3: 20, 4: 10}
paths = {
    (0, 1): 10,
    (0, 2): 8,
    (0, 3): 15,
    (1, 3): 12,
    (2, 4): 10,
    (3, 4): 5,
    (3, 0): 17,
    (4, 0): 10
}
In this case, the shortest valid path would
be 0 -> 2 -> 4 -> 0, with a distance of 28.
```
[Solution](data/dailyCodingProblem294.cpp)

---


#### Problem No. 295

```
Pascal's triangle is a triangular array of integers constructed with the following formula:

The first row consists of the number 1.
For each subsequent row, each element is the sum of the numbers directly above it, on either side.
For example, here are the first few rows:

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
Given an input k, return the kth row of Pascal's triangle.

Bonus: Can you do this using only O(k) space?
```
[Solution](data/dailyCodingProblem295.cpp)

---


#### Problem No. 296

```
Given a sorted array, convert it into a height-balanced binary search tree.
```
[Solution](data/dailyCodingProblem296.cpp)

---


#### Problem No. 297

```
At a popular bar, each customer has a set of favorite drinks,
and will happily accept any drink among this set.
For example, in the following situation, customer 0 will
be satisfied with drinks 0, 1, 3, or 6.

preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}
A lazy bartender working at this bar is trying to reduce his
effort by limiting the drink recipes he must memorize.
Given a dictionary input such as the one above,
return the fewest number of drinks he must learn in order to satisfy all customers.

For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.
```
[Solution](data/dailyCodingProblem297.cpp)

---


#### Problem No. 298

```
A girl is walking along an apple orchard with a bag in each hand.
She likes to pick apples from each tree as she goes along,
but is meticulous about not putting different kinds of apples in the same bag.

Given an input describing the types of apples she will pass on her path,
in order, determine the length of the longest portion of
her path that consists of just two types of apple trees.

For example, given the input [2, 1, 2, 3, 3, 1, 3, 5],
the longest portion will involve types 1 and 3, with a length of four.
```
[Solution](data/dailyCodingProblem298.cpp)

---


#### Problem No. 299

```
A group of houses is connected to the main water plant by means of a set of pipes.
A house can either be connected by a set of pipes extending directly to the plant,
or indirectly by a pipe to a nearby house which is otherwise connected.

For example, here is a possible configuration, where A, B, and C are houses, and arrows represent pipes:

A <--> B <--> C <--> plant
Each pipe has an associated cost, which the utility company would like to minimize.
Given an undirected graph of pipe connections, return the lowest
cost configuration of pipes such that each house has access to water.

In the following setup, for example, we can remove all but the pipes from plant to A,
plant to B, and B to C, for a total cost of 16.

pipes = {
    'plant': {'A': 1, 'B': 5, 'C': 20},
    'A': {'C': 15},
    'B': {'C': 10},
    'C': {}
}
```
[Solution](data/dailyCodingProblem299.cpp)

---


#### Problem No. 300

```
On election day, a voting machine writes data in the form (voter_id, candidate_id) to a text file.
Write a program that reads this file as a stream and returns the top 3 candidates at any given time.
If you find a voter voting more than once, report this as fraud
```
[Solution](data/dailyCodingProblem300.cpp)

---


#### Problem No. 301

```
Implement a data structure which carries out the following operations without resizing the underlying array:

add(value): Add a value to the set of values.
check(value): Check whether a value is in the set.

The check method may return occasional false positives (in other words,
incorrectly identifying an element as part of the set),
but should always correctly identify a true element.
```
[Solution](data/dailyCodingProblem301.cpp)

---


#### Problem No. 302

```
You are given a 2-d matrix where each cell consists of either /, \, or an empty space.
Write an algorithm that determines into how many regions the slashes divide the space.

For example, suppose the input for a three-by-six grid is the following:

\    /
 \  /
  \/
Considering the edges of the matrix as boundaries,
this divides the grid into three triangles,
so you should return 3.
```
[Solution](data/dailyCodingProblem302.cpp)

---


#### Problem No. 303

```
Given a clock time in hh:mm format, determine, to the nearest degree,
the angle between the hour and the minute hands.

Bonus: When, during the course of a day, will the angle be zero?
```
[Solution](data/dailyCodingProblem303.cpp)

---


#### Problem No. 304

```
A knight is placed on a given square on an 8 x 8 chessboard.
It is then moved randomly several times, where each move is a standard knight move.
If the knight jumps off the board at any point, however, it is not allowed to jump back on.

After k moves, what is the probability that the knight remains on the board?
```
[Solution](data/dailyCodingProblem304.cpp)

---


#### Problem No. 305

```
Given a linked list, remove all consecutive nodes that sum to zero.
Print out the remaining nodes.

For example, suppose you are given the input 3 -> 4 -> -7 -> 5 -> -6 -> 6.
In this case, you should first remove 3 -> 4 -> -7, then -6 -> 6, leaving only 5.

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
```
[Solution](data/dailyCodingProblem305.cpp)

---


#### Problem No. 306

```
You are given a list of N numbers, in which each number is located
at most k places away from its sorted position. For example, if k = 1,
a given element at index 4 might end up at indices 3, 4, or 5.

Come up with an algorithm that sorts this list in O(N log k) time.
```
[Solution](data/dailyCodingProblem306.cpp)

---


#### Problem No. 307

```
Given a binary search tree, find the floor and ceiling of a given integer.
The floor is the highest element in the tree less than or equal to an integer,
while the ceiling is the lowest element in the tree greater than or equal to an integer.

If either value does not exist, return None.
```
[Solution](data/dailyCodingProblem307.cpp)

---


#### Problem No. 308

```
You are presented with an array representing a Boolean expression. The elements are of two kinds:

T and F, representing the values True and False.
&, |, and ^, representing the bitwise operators for AND, OR, and XOR.
Determine the number of ways to group the array elements using parentheses
so that the entire expression evaluates to True.

For example, suppose the input is ['F', '|', 'T', '&', 'T']. In this case,
there are two acceptable groupings: (F | T) & T and F | (T & T).
```
[Solution](data/dailyCodingProblem308.cpp)

---


#### Problem No. 309

```
There are M people sitting in a row of N seats, where M < N.
Your task is to redistribute people such that there are no
gaps between any of them, while keeping overall movement to a minimum.

For example, suppose you are faced with an input of
[0, 1, 1, 0, 1, 0, 0, 0, 1], where 0 represents an
empty seat and 1 represents a person. In this case,
one solution would be to place the person on the right
in the fourth seat. We can consider the cost of a
solution to be the sum of the absolute distance each
person must move, so that the cost here would be five.

Given an input such as the one above, return the lowest
possible cost of moving people to remove all gaps.
```
[Solution](data/dailyCodingProblem309.cpp)

---


#### Problem No. 310

```
Write an algorithm that finds the total number of set bits in all integers between 1 and N.
```
[Solution](data/dailyCodingProblem310.cpp)

---


#### Problem No. 311

```
Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both its left and right neighbors.
It is guaranteed that the first and last elements are lower than all others.
```
[Solution](data/dailyCodingProblem311.cpp)

---


#### Problem No. 312

```
You are given a 2 x N board, and instructed to completely cover the board with the following shapes:

Dominoes, or 2 x 1 rectangles.
Trominoes, or L-shapes.
For example, if N = 4, here is one possible configuration, where A is a domino, and B and C are trominoes.

A B B C
A B C C
Given an integer N, determine in how many ways this task is possible.
```
[Solution](data/dailyCodingProblem312.cpp)

---


#### Problem No. 313

```
You are given a circular lock with three wheels, each of which display the
numbers 0 through 9 in order.
Each of these wheels rotate clockwise and counterclockwise.

In addition, the lock has a certain number of "dead ends", meaning that if you turn the
wheels to one of these combinations, the lock becomes stuck in that state and cannot be opened.

Let us consider a "move" to be a rotation of a single wheel by one digit, in either direction.
Given a lock initially set to 000, a target combination, and a list of dead ends,
write a function that returns the minimum number of moves required to reach the target state,
or None if this is impossible.
```
[Solution](data/dailyCodingProblem313.cpp)

---


#### Problem No. 314

```
You are the technical director of WSPT radio, serving listeners nationwide.
For simplicity's sake we can consider each listener to live along a horizontal
line stretching from 0 (west) to 1000 (east).

Given a list of N listeners, and a list of M radio towers,
each placed at various locations along this line, determine
what the minimum broadcast range would have to be in order
for each listener's home to be covered.

For example, suppose listeners = [1, 5, 11, 20], and
towers = [4, 8, 15]. In this case the minimum range
would be 5, since that would be required for the tower
at position 15 to reach the listener at position 20.
```
[Solution](data/dailyCodingProblem314.cpp)

---


#### Problem No. 315

```
In linear algebra, a Toeplitz matrix is one in which the elements on
any given diagonal from top left to bottom right are identical.

Here is an example:

1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2

Write a program to determine whether a
given input is a Toeplitz matrix.
```
[Solution](data/dailyCodingProblem315.cpp)

---


#### Problem No. 317

```
Write a function that returns the bitwise AND of all integers between M and N, inclusive.
```
[Solution](data/dailyCodingProblem317.cpp)

---


#### Problem No. 318

```
You are going on a road trip, and would like to create a suitable music playlist.
The trip will require N songs, though you only have M songs downloaded, where M < N.
A valid playlist should select each song at least once, and guarantee a buffer of B songs between repeats.

Given N, M, and B, determine the number of valid playlists.
```
[Solution](data/dailyCodingProblem318.cpp)

---


#### Problem No. 319

```
An 8-puzzle is a game played on a 3 x 3 board of tiles,
with the ninth tile missing. The remaining tiles are
labeled 1 through 8 but shuffled randomly. Tiles may
slide horizontally or vertically into an empty space,
but may not be removed from the board.

Design a class to represent the board, and find a series
of steps to bring the board to the state
[[1, 2, 3], [4, 5, 6], [7, 8, None]].
```
[Solution](data/dailyCodingProblem319.cpp)

---


#### Problem No. 320

```
Given a string, find the length of the smallest
window that contains every distinct character.
Characters may appear more than once in the window.

For example, given "jiujitsu", you should return 5,
corresponding to the final five letters.
```
[Solution](data/dailyCodingProblem320.cpp)

---


#### Problem No. 321

```
Given a positive integer N, find the smallest number of steps it will take to reach 1.

There are two kinds of permitted steps:

You may decrement N to N - 1.
If a * b = N, you may decrement N to the larger of a and b.

For example, given 100, you can reach 1 in five steps
with the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1.
```
[Solution](data/dailyCodingProblem321.cpp)

---


#### Problem No. 322

```
Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.

On the ith jump, you may move exactly i places to the left or right.

Find a path with the fewest number of jumps required to get from 0 to N.
```
[Solution](data/dailyCodingProblem322.cpp)

---


#### Problem No. 323

```
Create an algorithm to efficiently compute the approximate median of a list of numbers.

More precisely, given an unordered list of N numbers, find an element whose rank
is between N / 4 and 3 * N / 4, with a high level of certainty, in less than O(N) time.
```
[Solution](data/dailyCodingProblem323.cpp)

---


#### Problem No. 324

```
Consider the following scenario: there are N mice and N holes placed at integer points
along a line. Given this, find a method that maps mice to holes such that the largest
number of steps any mouse takes is minimized.

Each move consists of moving one mouse one unit to the left or right,
and only one mouse can fit inside each hole.

For example, suppose the mice are positioned at [1, 4, 9, 15], and
the holes are located at [10, -5, 0, 16]. In this case,
the best pairing would require us to send the mouse at 1 to the hole at -5,
so our function should return 6.
```
[Solution](data/dailyCodingProblem324.cpp)

---


#### Problem No. 325

```
The United States uses the imperial system of weights and measures,
which means that there are many different, seemingly arbitrary units
to measure distance. There are 12 inches in a foot, 3 feet in a yard,
22 yards in a chain, and so on.

Create a data structure that can efficiently convert a certain quantity
of one unit to the correct amount of any other unit. You should also allow
for additional units to be added to the system.
```
[Solution](data/dailyCodingProblem325.cpp)

---


#### Problem No. 326

```
A Cartesian tree with sequence S is a binary tree defined by the following two properties:

It is heap-ordered, so that each parent value is strictly less than that of its children.
An in-order traversal of the tree produces nodes with values that correspond exactly to S.
For example, given the sequence [3, 2, 6, 1, 9], the resulting Cartesian tree would be:

      1
    /   \   
  2       9
 / \
3   6
Given a sequence S, construct the corresponding Cartesian tree.
```
[Solution](data/dailyCodingProblem326.cpp)

---


#### Problem No. 327

```
Write a program to merge two binary trees. Each node in the new tree should hold a
value equal to the sum of the values of the corresponding nodes of the input trees.

If only one input tree has a node in a given position, the corresponding node in
the new tree should match that input node.

Input: 
	 Tree 1            Tree 2                  
	   2                 3                             
	  / \               / \                            
	 1   4             6   1                        
	/                   \   \                      
   5                     2   7                  

Output: Merged tree:
	 5
	/ \
   7   5
  / \   \ 
 5   2   7
```
[Solution](data/dailyCodingProblem327.cpp)

---


#### Problem No. 328

```
In chess, the Elo rating system is used to calculate player strengths based on game results.

A simplified description of the Elo system is as follows.
Every player begins at the same score. For each subsequent game,
the loser transfers some points to the winner, where the amount
of points transferred depends on how unlikely the win is.
For example, a 1200-ranked player should gain much more
points for beating a 2000-ranked player than for beating a 1300-ranked player.

Implement this system.
```
[Solution](data/dailyCodingProblem328.cpp)

---


#### Problem No. 329

```
Suppose you have N men and N women, and each person has ranked their prospective
opposite-sex partners in order of preference.

For example, if N = 3, the input could be something like this:

guy_preferences = {
    'andrew': ['caroline', 'abigail', 'betty'],
    'bill': ['caroline', 'betty', 'abigail'],
    'chester': ['betty', 'caroline', 'abigail'],
}

gal_preferences = {
    'abigail': ['andrew', 'bill', 'chester'],
    'betty': ['bill', 'andrew', 'chester'],
    'caroline': ['bill', 'chester', 'andrew']
}

Write an algorithm that pairs the men and women together in such a
way that no two people of opposite sex would both rather be with each
other than with their current partners.
```
[Solution](data/dailyCodingProblem329.cpp)

---


#### Problem No. 330

```
A Boolean formula can be said to be satisfiable if there is a way to assign
truth values to each variable such that the entire formula evaluates to true.

For example, suppose we have the following formula,
where the symbol ¬ is used to denote negation:

(¬c OR b) AND (b OR c) AND (¬b OR c) AND (¬c OR ¬a)

One way to satisfy this formula would be to
let a = False, b = True, and c = True.

This type of formula, with AND statements
joining tuples containing exactly one OR,
is known as 2-CNF.

Given a 2-CNF formula, find a way to assign
truth values to satisfy it, or return False
if this is impossible.
```
[Solution](data/dailyCodingProblem330.cpp)

---


#### Problem No. 331

```
You are given a string consisting of the letters x and y, such as xyxxxyxyy.
In addition, you have an operation called flip, which changes a single x to y or vice versa.

Determine how many times you would need to apply this operation to
ensure that all x's come before all y's. In the preceding example,
it suffices to flip the second and sixth characters, so you should return 2.
```
[Solution](data/dailyCodingProblem331.cpp)

---


#### Problem No. 332

```
Given integers M and N, write a program that counts how many
positive integer pairs (a, b) satisfy the following conditions:

a + b = M
a XOR b = N
```
[Solution](data/dailyCodingProblem332.cpp)

---


#### Problem No. 333

```
At a party, there is a single person who everyone knows,
but who does not know anyone in return (the "celebrity").
To help figure out who this is, you have access to an O(1)
method called knows(a, b), which returns True
if person a knows person b, else False.

Given a list of N people and the above operation,
find a way to identify the celebrity in O(N) time.
```
[Solution](data/dailyCodingProblem333.cpp)

---


#### Problem No. 334

```
The 24 game is played as follows. You are given a list of four integers,
each between 1 and 9, 
in a fixed order. By placing the operators +, -, *, and / between the numbers,
and grouping them with parentheses, determine whether it
is possible to reach the value 24.

For example, given the input [5, 2, 7, 8], you should
return True, since (5 * 2 - 7) * 8 = 24.

Write a function that plays the 24 game.
```
[Solution](data/dailyCodingProblem334.py)

---


#### Problem No. 336

```
Write a program to determine how many distinct ways there are to create a max heap
from a list of N given integers.

For example, if N = 3, and our integers are [1, 2, 3], there are two ways, shown below.

  3      3
 / \    / \
1   2  2   1
```
[Solution](data/dailyCodingProblem336.cpp)

---


#### Problem No. 337

```
Given a linked list, uniformly shuffle the nodes.
What if we want to prioritize space over time?
```
[Solution](data/dailyCodingProblem337.cpp)

---


#### Problem No. 338

```
Given an integer n, find the next biggest integer with the same number of 1-bits on.
For example, given the number 6 (0110 in binary), return 9 (1001).
```
[Solution](data/dailyCodingProblem338.cpp)

---


#### Problem No. 339

```
Given an array of numbers and a number k, determine if there are three entries in the array which
add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49,
return true as 20 + 4 + 25 = 49.
```
[Solution](data/dailyCodingProblem339.cpp)

---


#### Problem No. 340

```
Given a set of points (x, y) on a 2D cartesian plane, find the two closest points.
For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)],
return [(-1, -1), (1, 1)].
```
[Solution](data/dailyCodingProblem340.cpp)

---


#### Problem No. 342

```
reduce (also known as fold) is a function that takes in an array, a combining function,
and an initial value and builds up a result by calling the combining function on each
element of the array, left to right. For example, we can write sum() in terms of reduce:

def add(a, b):
    return a + b

def sum(lst):
    return reduce(lst, add, 0)
This should call add on the initial value with the first element of the array,
and then the result of that with the second element of the array,
and so on until we reach the end, when we return the sum of the array.

Implement your own version of reduce.
```
[Solution](data/dailyCodingProblem342.py)

---


#### Problem No. 343

```
Given a binary search tree and a range [a, b] (inclusive),
return the sum of the elements of the binary search tree within the range.

For example, given the following tree:

    5
   / \
  3   8
 / \ / \
2  4 6  10
and the range [4, 9], return 23 (5 + 4 + 6 + 8).
```
[Solution](data/dailyCodingProblem343.cpp)

---


#### Problem No. 344

```
You are given a tree with an even number of nodes. Consider each connection between
a parent and child node to be an "edge". You would like to remove some of these edges,
such that the disconnected subtrees that remain each have an even number of nodes.

For example, suppose your input was the following tree:

   1
  / \ 
 2   3
    / \ 
   4   5
 / | \
6  7  8

In this case, removing the edge (3, 4) satisfies our requirement.

Write a function that returns the maximum number of edges
you can remove while still satisfying this requirement.
```
[Solution](data/dailyCodingProblem344.cpp)

---


#### Problem No. 345

```
You are given a set of synonyms, such as (big, large) and (eat, consume).
Using this set, determine if two sentences with the same number of words are equivalent.

For example, the following two sentences are equivalent:

"He wants to eat food."
"He wants to consume food."
Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c):
consider the case of (coach, bus) and (coach, teacher).

Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?
```
[Solution](data/dailyCodingProblem345.cpp)

---


#### Problem No. 346

```
You are given a huge list of airline ticket prices between different
cities around the world on a given day. These are all direct flights.
Each element in the list has the format (source_city, destination, price).

Consider a user who is willing to take up to k connections from their
origin city A to their destination B. Find the cheapest fare possible
for this journey and print the itinerary for that journey.

For example, our traveler wants to go from
JFK to LAX with up to 3 connections,
and our input flights are as follows:

[
    ('JFK', 'ATL', 150),
    ('ATL', 'SFO', 400),
    ('ORD', 'LAX', 200),
    ('LAX', 'DFW', 80),
    ('JFK', 'HKG', 800),
    ('ATL', 'ORD', 90),
    ('JFK', 'LAX', 500),
]

Due to some improbably low flight prices, the cheapest
itinerary would be JFK -> ATL -> ORD -> LAX, costing $440.
```
[Solution](data/dailyCodingProblem346.cpp)

---


#### Problem No. 347

```
You are given a string of length N and a parameter k.
The string can be manipulated by taking one of the
first k letters and moving it to the end.

Write a program to determine the lexicographically
smallest string that can be created after an unlimited number of moves.

For example, suppose we are given the string daily and k = 1.
The best we can create in this case is ailyd
```
[Solution](data/dailyCodingProblem347.cpp)

---


#### Problem No. 348

```
A ternary search tree is a trie-like data structure where each node
may have up to three children. Here is an example which represents
the words code, cob, be, ax, war, and we.

       c
    /  |  \
   b   o   w
 / |   |   |
a  e   d   a
|    / |   | \ 
x   b  e   r  e  

The tree is structured according to the following rules:

left child nodes link to words lexicographically earlier than the parent prefix
right child nodes link to words lexicographically later than the parent prefix
middle child nodes continue the current word

For instance, since code is the first word inserted in the tree,
and cob lexicographically precedes cod, cob is represented as a
left child extending from cod.

Implement insertion and search functions for a ternary search tree.
```
[Solution](data/dailyCodingProblem348.cpp)

---


#### Problem No. 350

```
Write a program that determines the smallest
number of perfect squares that sum up to N.

Here are a few examples:

Given N = 4, return 1 (4)
Given N = 17, return 2 (16 + 1)
Given N = 18, return 2 (9 + 9)
```
[Solution](data/dailyCodingProblem350.cpp)

---


#### Problem No. 353

```
You are given a histogram consisting of rectangles of different heights.
These heights are represented in an input list, such that [1, 3, 2, 5]
corresponds to the following diagram:

      x
      x  
  x   x
  x x x
x x x x

Determine the area of the largest rectangle that can be formed only
from the bars of the histogram. For the diagram above, for example,
this would be six, representing the 2 x 3 area at the bottom right.
```
[Solution](data/dailyCodingProblem353.cpp)

---


#### Problem No. 355

```
You are given an array X of floating-point numbers x1, x2, ... xn.
These can be rounded up or down to create a corresponding array Y of integers y1, y2, ... yn.

Write an algorithm that finds an appropriate Y array with the following properties:

The rounded sums of both arrays should be equal.
The absolute pairwise difference between elements is minimized.
In other words, |x1- y1| + |x2- y2| + ... + |xn- yn| should be as small as possible.
For example, suppose your input is [1.3, 2.3, 4.4]. In this case you cannot do better than [1, 2, 5],
which has an absolute difference of |1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1.
```
[Solution](data/dailyCodingProblem355.cpp)

---


#### Problem No. 356

```
Implement a queue using a set of fixed-length arrays.

The queue should support enqueue, dequeue, and get_size operations.
```
[Solution](data/dailyCodingProblem356.cpp)

---


#### Problem No. 357

```
You are given a binary tree in a peculiar string representation.
Each node is written in the form (lr), where l corresponds to the
left child and r corresponds to the right child.

If either l or r is null, it will be represented as a zero.
Otherwise, it will be represented by a new (lr) pair.

Here are a few examples:

A root node with no children: (00)
A root node with two children: ((00)(00))
An unbalanced tree with three consecutive left children: ((((00)0)0)0)

Given this representation, determine the depth of the tree.
```
[Solution](data/dailyCodingProblem357.cpp)

---


#### Problem No. 358

```
Create a data structure that performs all the following operations in O(1) time:

plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.
```
[Solution](data/dailyCodingProblem358.cpp)

---


#### Problem No. 359

```
You are given a string formed by concatenating several words
corresponding to the integers zero through nine and then anagramming.

For example, the input could be 'niesevehrtfeev',
which is an anagram of 'threefiveseven'.
Note that there can be multiple instances of each integer.

Given this string, return the original integers
in sorted order. In the example above, this would be 357.
```
[Solution](data/dailyCodingProblem359.cpp)

---


#### Problem No. 360

```
You have access to ranked lists of songs for various users.
Each song is represented as an integer, and more preferred
songs appear earlier in each list. For example, the list
[4, 1, 7] indicates that a user likes song 4 the best,
followed by songs 1 and 7.

Given a set of these ranked lists, interleave them to
create a playlist that satisfies everyone's priorities.

For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}.
In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
```
[Solution](data/dailyCodingProblem360.cpp)

---


#### Problem No. 361

```
Mastermind is a two-player game in which the first player attempts to guess
the secret code of the second. In this version,
the code may be any six-digit number with all distinct digits.

Each turn the first player guesses some number, and the second player
responds by saying how many digits in this number correctly matched
their location in the secret code. For example, if the secret code were 123456,
then a guess of 175286 would score two, since 1 and 6 were correctly placed.

Write an algorithm which, given a sequence of guesses and their scores,
determines whether there exists some secret code that could have produced them.

For example, for the following scores you should return True, since they correspond to the secret code 123456:
{175286: 2, 293416: 3, 654321: 0}

However, it is impossible for any key to result in the following scores, so in this case you should return False:
{123456: 4, 345678: 4, 567890: 4}
```
[Solution](data/dailyCodingProblem361.cpp)

---


#### Problem No. 362

```
A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees.
For example, 16891 is strobogrammatic.

Create a program that finds all strobogrammatic numbers with N digits.
```
[Solution](data/dailyCodingProblem362.cpp)

---


#### Problem No. 365

```
A quack is a data structure combining properties of both stacks and queues.
It can be viewed as a list of elements written left to right such that three operations are possible:

push(x): add a new item x to the left end of the list
pop(): remove and return the item on the left end of the list
pull(): remove the item on the right end of the list.

Implement a quack using three stacks and O(1) additional memory,
so that the amortized time for any push, pop, or pull operation is O(1).
```
[Solution](data/dailyCodingProblem365.cpp)

---


#### Problem No. 366

```
Given a string s, rearrange the characters so that any
two adjacent characters are not the same.
If this is not possible, return null.

For example, if s = yyz then return yzy.
If s = yyy then return null.
```
[Solution](data/dailyCodingProblem366.cpp)

---


#### Problem No. 367

```
Given two sorted iterators, merge it into one iterator.

For example, given these two iterators:

foo = iter([5, 10, 15])
bar = iter([3, 8, 9])
You should be able to do:

for num in merge_iterators(foo, bar):
    print(num)
3
5
8
9
10
15
Bonus: Make it work without pulling in the contents of the iterators in memory.
```
[Solution](data/dailyCodingProblem367.py)

---


#### Problem No. 368

```
Implement a key value store, where keys and values are integers, with the following methods:

update(key, vl): updates the value at key to val, or sets it if doesn't exist
get(key): returns the value with key, or None if no such value exists
max_key(val): returns the largest key with value val, or None if no key with that value exists

For example, if we ran the following calls:

kv.update(1, 1)
kv.update(2, 1)

And then called kv.max_key(1), it should return 2, since it's the largest key with value 1.
```
[Solution](data/dailyCodingProblem368.cpp)

---


#### Problem No. 369

```
You’re tracking stock price at a given instance of time.
Implement an API with the following functions: add(), update(), remove(),
which adds/updates/removes a datapoint for the stock price you are tracking.
The data is given as (timestamp, price), where timestamp is specified in unix epoch time.

Also, provide max(), min(), and average() functions that give the max/min/average of all values seen thus far.
```
[Solution](data/dailyCodingProblem369.cpp)

---


#### Problem No. 370

```
The “active time” of a courier is the time between
the pickup and dropoff of a delivery.
Given a set of data formatted like the following:

(delivery id, timestamp, pickup/dropoff)

Calculate the total active time in seconds.
A courier can pick up multiple orders before
dropping them off. The timestamp is in unix epoch seconds.

For example, if the input is the following:

(1, 1573280047, 'pickup')
(1, 1570320725, 'dropoff')
(2, 1570321092, 'pickup')
(3, 1570321212, 'pickup')
(3, 1570322352, 'dropoff')
(2, 1570323012, 'dropoff')

The total active time would be 1260 seconds.
```
[Solution](data/dailyCodingProblem370.cpp)

---


#### Problem No. 372

```
Write a function that takes a natural number as input and returns the number of digits the input has.

Constraint: don't use any loops.
```
[Solution](data/dailyCodingProblem372.cpp)

---


#### Problem No. 373

```
Given a list of integers L, find the maximum length of a sequence of consecutive numbers
that can be formed using elements from L.

For example, given L = [5, 2, 99, 3, 4, 1, 100], return 5 as we can build a sequence
[1, 2, 3, 4, 5] which has length 5.
```
[Solution](data/dailyCodingProblem373.cpp)

---


#### Problem No. 374

```
Given a sorted array arr of distinct integers, return the lowest index i for which arr[i] == i.
Return null if there is no such index.

For example, given the array [-5, -3, 2, 3], return 2 since arr[2] == 2.
Even though arr[3] == 3, we return 2 since it's the lowest index.
```
[Solution](data/dailyCodingProblem374.cpp)

---


#### Problem No. 375

```
The h-index is a metric used to measure the impact and productivity
of a scientist or researcher.

A scientist has index _h_ if _h_ of their _N_ papers have at least
_h_ citations each, and the other N - h papers have no more than _h_
citations each. If there are multiple possible values for _h_,
the maximum value is used.

Given an array of natural numbers, with each value representing
the number of citations of a researcher's paper, return the
h-index of that researcher.

For example, if the array was:

[4, 0, 0, 2, 3]

This means the researcher has 5 papers with 4, 1, 0, 2, and 3
citations respectively. The h-index for this researcher is 2,
since they have 2 papers with at least 2 citations and the
remaining 3 papers have no more than 2 citations.
```
[Solution](data/dailyCodingProblem375.cpp)

---


#### Problem No. 376

```
You are writing an AI for a 2D map game. You are somewhere in a 2D grid,
and there are coins strewn about over the map.

Given the position of all the coins and your current position,
find the closest coin to you in terms of Manhattan distance.
That is, you can move around up, down, left, and right, but not diagonally.
If there are multiple possible closest coins, return any of them.

For example, given the following map, where you are x, coins are o,
and empty spaces are . (top left is 0, 0):

---------------------
| . | . | x | . | o |
---------------------
| o | . | . | . | . |
---------------------
| o | . | . | . | o |
---------------------
| . | . | o | . | . |
---------------------
return (0, 4), since that coin is closest. This map would be represented in our question as:

Our position: (0, 2)
Coins: [(0, 4), (1, 0), (2, 0), (3, 2)]
```
[Solution](data/dailyCodingProblem376.cpp)

---


#### Problem No. 377

```
Given an array of numbers arr and a window of size k, print out the median
of each window of size k starting from the left and moving right by one position each time.

For example, given the following array and k = 3:

[-1, 5, 13, 8, 2, 3, 3, 1]

Your function should print out the following:

5 <- median of [-1, 5, 13]
8 <- median of [5, 13, 8]
8 <- median of [13, 8, 2]
3 <- median of [8, 2, 3]
3 <- median of [2, 3, 3]
3 <- median of [3, 3, 1]

Recall that the median of an even-sized list is the average of the two middle numbers.
```
[Solution](data/dailyCodingProblem377.cpp)

---


#### Problem No. 378

```
Write a function that takes in a number, string, list, or dictionary
and returns its JSON encoding. It should also handle nulls.

For example, given the following input:

[None, 123, ["a", "b"], {"c":"d"}]
You should return the following, as a string:

'[null, 123, ["a", "b"], {"c": "d"}]'
```
[Solution](data/dailyCodingProblem378.py)

---


#### Problem No. 379

```
Given a string, generate all possible subsequences of the string.

For example, given the string xyz, return an array or set with the following strings:

x
y
z
xy
xz
yz
xyz

Note that zx is not a valid subsequence since it is not in the order of the given string.
```
[Solution](data/dailyCodingProblem379.cpp)

---


#### Problem No. 380

```
Implement integer division without using the division operator.
Your function should return a tuple of (dividend, remainder) and
it should take two numbers, the product and divisor.

For example, calling divide(10, 3) should return (3, 1)
since the divisor is 3 and the remainder is 1.

Bonus: Can you do it in O(log n) time?
```
[Solution](data/dailyCodingProblem380.cpp)

---


#### Problem No. 381

```
Implement a function that converts a hex string to base64.

For example, the string: deadbeef
should produce: 3q2+7w==
```
[Solution](data/dailyCodingProblem381.cpp)

---


#### Problem No. 383

```
Implement the function embolden(s, lst) which takes in a string s and list of substrings lst,
and wraps all substrings in s with an HTML bold tag <b> and </b>.

If two bold tags overlap or are contiguous, they should be merged.

For example, given s = abcdefg and lst = ["bc", "ef"], return the string a<b>bc</b>d<b>ef</b>g.

Given s = abcdefg and lst = ["bcd", "def"], return the string a<b>bcdef</b>g, since they overlap.
```
[Solution](data/dailyCodingProblem383.cpp)

---


#### Problem No. 384

```
You are given an array of integers representing coin denominations and a total amount of money.
Write a function to compute the fewest number of coins needed to make up that amount.
If it is not possible to make that amount, return null.

For example, given an array of [1, 5, 10] and an amount 56, return 7 since we can use 5 dimes,
1 nickel, and 1 penny.

Given an array of [5, 8] and an amount 15, return 3 since we can use 5 5-cent coins.
```
[Solution](data/dailyCodingProblem384.cpp)

---


#### Problem No. 386

```
Given a string, sort it in decreasing order based on the frequency of characters.
If there are multiple possible solutions, return any of them.

For example, given the string tweet, return tteew. eettw would also be acceptable.
```
[Solution](data/dailyCodingProblem386.cpp)

---


#### Problem No. 391

```
We have some historical clickstream data gathered from our site anonymously using cookies.
The histories contain URLs that users have visited in chronological order.

Write a function that takes two users' browsing histories as input and returns
the longest contiguous sequence of URLs that appear in both.

For example, given the following two users' histories:

user1 = ['/home', '/register', '/login', '/user', '/one', '/two']
user2 = ['/home', '/red', '/login', '/user', '/one', '/pink']

You should return the following:

['/login', '/user', '/one']
```
[Solution](data/dailyCodingProblem391.cpp)

---


#### Problem No. 392

```
You are given a 2D matrix of 1s and 0s where 1 represents land and 0 represents water.

Grid cells are connected horizontally orvertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island
(i.e., one or more connected land cells).

An island is a group is cells connected horizontally or vertically, but not diagonally.
There is guaranteed to be exactly one island in this grid, and the island doesn't
have water inside that isn't connected to the water around the island. Each cell has a side length of 1.

Determine the perimeter of this island.

For example, given the following matrix:

[[0, 1, 1, 0],
[1, 1, 1, 0],
[0, 1, 1, 0],
[0, 0, 1, 0]]

Return 14.
```
[Solution](data/dailyCodingProblem392.cpp)

---


#### Problem No. 393

```
Given an array of integers, return the largest range, inclusive, of integers that are all included in the array.

For example, given the array [9, 6, 1, 3, 8, 10, 12, 11], return (8, 12) since 8, 9, 10, 11, and 12 are all in the array.
```
[Solution](data/dailyCodingProblem393.cpp)

---


#### Problem No. 394

```
Given a binary tree and an integer k, return whether there exists a root-to-leaf path that sums up to k.

For example, given k = 18 and the following binary tree:

    8
   / \
  4   13
 / \   \
2   6   19

Return True since the path 8 -> 4 -> 6 sums to 18.
```
[Solution](data/dailyCodingProblem394.cpp)

---


#### Problem No. 395

```
Given an array of strings, group anagrams together.

For example, given the following array:

['eat', 'ate', 'apt', 'pat', 'tea', 'now']
Return:

[['eat', 'ate', 'tea'],
 ['apt', 'pat'],
 ['now']]
```
[Solution](data/dailyCodingProblem395.cpp)

---


#### Problem No. 396

```
Given a string, return the length of the longest palindromic subsequence in the string.

For example, given the following string:

MAPTPTMTPA

Return 7, since the longest palindromic subsequence in the string is APTMTPA.
Recall that a subsequence of a string does not have to be contiguous!

Your algorithm should run in O(n^2) time and space.
```
[Solution](data/dailyCodingProblem396.cpp)

---


#### Problem No. 397

```
You are given a list of jobs to be done, where each job is represented by a start time and end time.
Two jobs are compatible if they don't overlap. Find the largest subset of compatible jobs.

For example, given the following jobs (there is no guarantee that jobs will be sorted):

[(0, 6),
(1, 4),
(3, 5),
(3, 8),
(4, 7),
(5, 9),
(6, 10),
(8, 11)]

Return:

[(1, 4),
(4, 7),
(8, 11)]
```
[Solution](data/dailyCodingProblem397.cpp)

---


#### Problem No. 398

```
Given a linked list and an integer k, remove the k-th node from the
end of the list and return the head of the list.

k is guaranteed to be smaller than the length of the list.

Do this in one pass.
```
[Solution](data/dailyCodingProblem398.cpp)

---


#### Problem No. 399

```
Given a list of strictly positive integers, partition the list into 3 contiguous partitions
which each sum up to the same value. If not possible, return null.

For example, given the following list:

[3, 5, 8, 0, 8]

Return the following 3 partitions:

[[3, 5],
[8, 0],
[8]]

Which each add up to 8.
```
[Solution](data/dailyCodingProblem399.cpp)

---


#### Problem No. 400

```
Given a list of numbers L, implement a method sum(i, j) which returns the sum from
the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.

You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step
```
[Solution](data/dailyCodingProblem400.cpp)

---


#### Problem No. 401

```
A permutation can be specified by an array P, where P[i] represents the location of the element at i
in the permutation. For example, [2, 1, 0] represents the permutation where elements at the index 0
and 2 are swapped.

Given an array and a permutation, apply the permutation to the array. For example,
given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].
```
[Solution](data/dailyCodingProblem401.cpp)

---


#### Problem No. 402

```
A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees.
For example, 16891 is strobogrammatic.

Create a program that finds all strobogrammatic numbers with N digits.
```
[Solution](data/dailyCodingProblem402.cpp)

---


#### Problem No. 403

```
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability,
implement a function rand7() that returns an integer from 1 to 7 (inclusive).
```
[Solution](data/dailyCodingProblem403.cpp)

---


#### Problem No. 404

```
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping),
find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
```
[Solution](data/dailyCodingProblem404.cpp)

---


#### Problem No. 405

```
Given a tree, find the largest tree/subtree that is a BST.
```
[Solution](data/dailyCodingProblem405.cpp)

---


#### Problem No. 406

```
You are presented with an array representing a Boolean expression. The elements are of two kinds:

T and F, representing the values True and False.
&, |, and ^, representing the bitwise operators for AND, OR, and XOR.
Determine the number of ways to group the array elements using parentheses
so that the entire expression evaluates to True.

For example, suppose the input is ['F', '|', 'T', '&', 'T']. In this case,
there are two acceptable groupings: (F | T) & T and F | (T & T).
```
[Solution](data/dailyCodingProblem406.cpp)

---


#### Problem No. 407

```
A group of houses is connected to the main water plant by means of a set of pipes.
A house can either be connected by a set of pipes extending directly to the plant,
or indirectly by a pipe to a nearby house which is otherwise connected.

For example, here is a possible configuration, where A, B, and C are houses, and arrows represent pipes:

A <--> B <--> C <--> plant
Each pipe has an associated cost, which the utility company would like to minimize.
Given an undirected graph of pipe connections, return the lowest
cost configuration of pipes such that each house has access to water.

In the following setup, for example, we can remove all but the pipes from plant to A,
plant to B, and B to C, for a total cost of 16.

pipes = {
    'plant': {'A': 1, 'B': 5, 'C': 20},
    'A': {'C': 15},
    'B': {'C': 10},
    'C': {}
}
```
[Solution](data/dailyCodingProblem407.cpp)

---


#### Problem No. 408

```
Given an array of numbers representing the stock prices of a company in chronological order and an integer k,
return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it,
and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
```
[Solution](data/dailyCodingProblem408.cpp)

---


#### Problem No. 410

```
You are given an array X of floating-point numbers x1, x2, ... xn.
These can be rounded up or down to create a corresponding array Y of integers y1, y2, ... yn.

Write an algorithm that finds an appropriate Y array with the following properties:

The rounded sums of both arrays should be equal.
The absolute pairwise difference between elements is minimized.
In other words, |x1- y1| + |x2- y2| + ... + |xn- yn| should be as small as possible.
For example, suppose your input is [1.3, 2.3, 4.4]. In this case you cannot do better than [1, 2, 5],
which has an absolute difference of |1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1.
```
[Solution](data/dailyCodingProblem410.cpp)

---


#### Problem No. 411

```
Given a string which we can delete at most k, return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.
```
[Solution](data/dailyCodingProblem411.cpp)

---


#### Problem No. 412

```
The "look and say" sequence is defined as follows: beginning with the term 1,
each subsequent term visually describes the digits appearing in the previous term.
The first few terms are as follows:

1
11
21
1211
111221
As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

Given an integer N, print the Nth term of this sequence.
```
[Solution](data/dailyCodingProblem412.cpp)

---


#### Problem No. 413

```
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time,
you could climb any number from a set of positive integers X? For example,
if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
```
[Solution](data/dailyCodingProblem413.cpp)

---


#### Problem No. 414

```
You have an N by N board. Write a function that, given N, returns the number of possible arrangements
of the board where N queens can be placed on the board without threatening each other,
i.e. no two queens share the same row, column, or diagonal.
```
[Solution](data/dailyCodingProblem414.cpp)

---


#### Problem No. 415

```
Given a array of numbers representing the stock prices of a company in chronological order,
write a function that calculates the maximum profit you could have made from buying and selling that stock.
You're also given a number fee that represents a transaction fee for each buy and sell transaction.

You must buy before you can sell the stock, but you can make as many transactions as you like.

For example, given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9, since you could buy
the stock at 1 dollar, and sell at 8 dollars, and then buy it at 4 dollars and sell it at 10 dollars.
Since we did two transactions, there is a 4 dollar fee, so we have 7 + 6 = 13 profit minus 4 dollars of fees.
```
[Solution](data/dailyCodingProblem415.cpp)

---


#### Problem No. 416

```
You are in an infinite 2D grid where you can move in any of the 8 directions:

 (x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
You are given a sequence of points and the order in which you need to cover the points.
Give the minimum number of steps in which you can achieve it. You start from the first point.

Example:

Input: [(0, 0), (1, 1), (1, 2)]
Output: 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
```
[Solution](data/dailyCodingProblem416.cpp)

---


#### Problem No. 417

```
Given a linked list, remove all consecutive
nodes that sum to zero. Print out the remaining nodes.

For example, suppose you are given the input
3 -> 4 -> -7 -> 5 -> -6 -> 6. In this case,
you should first remove 3 -> 4 -> -7,
then -6 -> 6, leaving only 5.
```
[Solution](data/dailyCodingProblem417.cpp)

---


#### Problem No. 418

```
MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written.
They would like to give the smallest positive amount to each worker consistent with the constraint
that if a developer has written more lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp, determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
```
[Solution](data/dailyCodingProblem418.cpp)

---


#### Problem No. 419

```
Given a positive integer N, find the smallest number of steps it will take to reach 1.

There are two kinds of permitted steps:

You may decrement N to N - 1.
If a * b = N, you may decrement N to the larger of a and b.
For example, given 100, you can reach 1 in five steps with the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1.
```
[Solution](data/dailyCodingProblem419.cpp)

---


#### Problem No. 420

```
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
```
[Solution](data/dailyCodingProblem420.cpp)

---


#### Problem No. 422

```
Write a program to merge two binary trees. Each node in the new tree should hold a value equal to the sum of the values of the corresponding nodes of the input trees.

If only one input tree has a node in a given position, the corresponding node in the new tree should match that input node.

     Tree 1            Tree 2                  
       2                 3                             
      / \               / \                            
     1   4             6   1                        
    /                   \   \                      
   5                     2   7                  

Output: Merged tree:
         5
        / \
       7   5
      / \   \ 
     5   2   7
```
[Solution](data/dailyCodingProblem422.cpp)

---


#### Problem No. 423

```
The transitive closure of a graph is a measure of which vertices are reachable from other vertices.
It can be represented as a matrix M, where M[i][j] == 1 if there is a path between vertices i and j,
and otherwise 0.

For example, suppose we are given the following graph in adjacency list form:

graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]
The transitive closure of this graph would be:

[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]
Given a graph, find its transitive closure.
```
[Solution](data/dailyCodingProblem423.cpp)

---


#### Problem No. 424

```
Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice,
find the two elements that appear only once.
```
[Solution](data/dailyCodingProblem424.cpp)

---


#### Problem No. 425

```
You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board.
The only pieces on the board are the black king and various white pieces. Given this matrix,
determine whether the king is in check.

For example, given the following matrix:

...K....
........
.B......
......P.
.......R
..N.....
........
.....Q..

You should return True, since the bishop is attacking the king diagonally.
```
[Solution](data/dailyCodingProblem425.cpp)

---


#### Problem No. 426

```
Given a binary tree, return the level of the tree with minimum sum.

	  4
	/   \
   2    -5
  / \    /\
-1   3 -2  6

answer = (-1 + 3 + -2 + 6) = 6
```
[Solution](data/dailyCodingProblem426.cpp)

---


#### Problem No. 427

```
A competitive runner would like to create a route that starts and ends at his house,
with the condition that the route goes entirely uphill at first, and then entirely downhill.

Given a dictionary of places of the form {location: elevation},
and a dictionary mapping paths between some of these locations
to their corresponding distances, find the length of the shortest
route satisfying the condition above. Assume the runner's home is location 0.

For example, suppose you are given the following input:

elevations = {0: 5, 1: 25, 2: 15, 3: 20, 4: 10}
paths = {
    (0, 1): 10,
    (0, 2): 8,
    (0, 3): 15,
    (1, 3): 12,
    (2, 4): 10,
    (3, 4): 5,
    (3, 0): 17,
    (4, 0): 10
}

In this case, the shortest valid
path would be 0 -> 2 -> 4 -> 0,
with a distance of 28.
```
[Solution](data/dailyCodingProblem427.cpp)

---


#### Problem No. 428

```
You have N stones in a row, and would like to create from them a pyramid.
This pyramid should be constructed such that the height of each stone
increases by one until reaching the tallest stone, after which the
heights decrease by one. In addition, the start and end stones of
the pyramid should each be one stone high.

You can change the height of any stone by paying a cost of 1 unit
to lower its height by 1, as many times as necessary. Given this
information, determine the lowest cost method to produce this pyramid.

For example, given the stones [1, 1, 3, 3, 2, 1], the optimal
solution is to pay 2 to create [0, 1, 2, 3, 2, 1].
```
[Solution](data/dailyCodingProblem428.cpp)

---


#### Problem No. 429

```
Pascal's triangle is a triangular array of integers constructed with the following formula:

The first row consists of the number 1.
For each subsequent row, each element is the sum of the numbers directly above it, on either side.
For example, here are the first few rows:

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
Given an input k, return the kth row of Pascal's triangle.

Bonus: Can you do this using only O(k) space?
```
[Solution](data/dailyCodingProblem429.cpp)

---


#### Problem No. 430

```
Given a string of parentheses, find the balanced string that can be produced from it
using the minimum number of insertions and deletions. If there are multiple solutions, return any of them.

For example, given "(()", you could return "(())". Given "))()(", you could return "()()()()".
```
[Solution](data/dailyCodingProblem430.cpp)

---


#### Problem No. 431

```
Create a basic sentence checker that takes in a stream of characters
and determines whether they form valid sentences. If a sentence is valid, the program should print it out.

We can consider a sentence valid if it conforms to the following rules:

The sentence must start with a capital letter, followed by a lowercase letter or a space.
All other characters must be lowercase letters, separators (,,;,:) or terminal marks (.,?,!,‽).
There must be a single space between each word.
The sentence must end with a terminal mark immediately following a word.
```
[Solution](data/dailyCodingProblem431.cpp)

---


#### Problem No. 433

```
Given an integer n, find the next biggest integer with the same number of 1-bits on.
For example, given the number 6 (0110 in binary), return 9 (1001).
```
[Solution](data/dailyCodingProblem433.cpp)

---


#### Problem No. 434

```
Given a binary search tree, find the floor and ceiling of a given integer.
The floor is the highest element in the tree less than or equal to an integer,
while the ceiling is the lowest element in the tree greater than or equal to an integer.

If either value does not exist, return None.

       7
    /    \
   5      10
 /  \     /  \
3    6   8   12

floor of 9 = 8
ceiling of 9 = 10

floor of 14 = 12
ceiling of 14 = does not exist
```
[Solution](data/dailyCodingProblem434.cpp)

---


#### Problem No. 435

```
Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g
```
[Solution](data/dailyCodingProblem435.cpp)

---


#### Problem No. 436

```
Implement 3 stacks using a single list:

class Stack:
    def __init__(self):
        self.list = []

    def pop(self, stack_number):
        pass

    def push(self, item, stack_number):
        pass
```
[Solution](data/dailyCodingProblem436.cpp)

---


#### Problem No. 437

```
Given a string and a set of characters, return the shortest substring containing all the characters in the set.
For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
If there is no substring containing all the characters in the set, return null.
```
[Solution](data/dailyCodingProblem437.cpp)

---


#### Problem No. 438

```
Implement a stack API using only a heap. A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element
(or throws an error if there is nothing on the stack)
Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
```
[Solution](data/dailyCodingProblem438.cpp)

---


#### Problem No. 439

```
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs,
and a starting airport, compute the person's itinerary. If no such itinerary exists, return null.
If there are multiple possible itineraries, return the lexicographically smallest one.
All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A',
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C']
is also a valid itinerary. However, the first one is lexicographically smaller.
```
[Solution](data/dailyCodingProblem439.cpp)

---


#### Problem No. 441

```
Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10],
one partition may be [9, 3, 5, 10, 10, 12, 14].
```
[Solution](data/dailyCodingProblem441.cpp)

---


#### Problem No. 442

```
A Cartesian tree with sequence S is a binary tree defined by the following two properties:

It is heap-ordered, so that each parent value is strictly less than that of its children.
An in-order traversal of the tree produces nodes with values that correspond exactly to S.
For example, given the sequence [3, 2, 6, 1, 9], the resulting Cartesian tree would be:

      1
    /   \   
  2       9
 / \
3   6

Given a sequence S, construct the corresponding Cartesian tree.
```
[Solution](data/dailyCodingProblem442.cpp)

---


#### Problem No. 443

```
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.
```
[Solution](data/dailyCodingProblem443.cpp)

---


#### Problem No. 444

```
Implement an efficient string matching algorithm.

That is, given a string of length N and a pattern of length k,
write a program that searches for the pattern in the string
with less than O(N * k) worst-case time complexity.

If the pattern is found, return the start index
of its location. If not, return False.
```
[Solution](data/dailyCodingProblem444.cpp)

---


#### Problem No. 445

```
Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed.

For example, given the following tree:

   0
  / \
 1   0
    / \
   1   0
  / \
 0   0
should be pruned to:

   0
  / \
 1   0
    /
   1
We do not remove the tree at the root or its left child because it still has a 1 as a descendant.
```
[Solution](data/dailyCodingProblem445.cpp)

---


#### Problem No. 446

```
Given a 32-bit positive integer N, determine whether it is a power of four in faster than O(log N) time.
```
[Solution](data/dailyCodingProblem446.cpp)

---


#### Problem No. 447

```
Implement integer exponentiation. That is, implement the pow(x, y) function,
where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
```
[Solution](data/dailyCodingProblem447.cpp)

---


#### Problem No. 448

```
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of
the array so that all the Rs come first, the Gs come second, and the Bs come last.
You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become
['R', 'R', 'R', 'G', 'G', 'B', 'B'].
```
[Solution](data/dailyCodingProblem448.cpp)

---


#### Problem No. 449

```
Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
```
[Solution](data/dailyCodingProblem449.cpp)

---


#### Problem No. 450

```
You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string.
Determine whether the parentheses are balanced.
For example, (()* and (*) are balanced. )*( is not balanced.
```
[Solution](data/dailyCodingProblem450.cpp)

---


#### Problem No. 451

```
Implement the function fib(n), which returns the nth number in the Fibonacci sequence, using only O(1) space.
```
[Solution](data/dailyCodingProblem451.cpp)

---


#### Problem No. 452

```
Let's represent an integer in a linked list format by having each node represent a digit in the number.
The nodes make up the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5
is the number 54321.

Given two linked lists in this format, return their sum in the same linked list format.

For example, given

9 -> 9
5 -> 2
return 124 (99 + 25) as:

4 -> 2 -> 1
```
[Solution](data/dailyCodingProblem452.cpp)

---


#### Problem No. 453

```
Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15
Return the nodes 5 and 15.
```
[Solution](data/dailyCodingProblem453.cpp)

---


#### Problem No. 454

```
Describe an algorithm to compute the longest
increasing subsequence of an array of numbers in O(n log n) time.
```
[Solution](data/dailyCodingProblem454.cpp)

---


#### Problem No. 455

```
Conway's Game of Life takes place on an infinite two-dimensional board of square cells.
Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a starting
list of live cell coordinates and the number of steps it should run for.
Once initialized, it should print out the board state at each step.
Since it's an infinite board, print out only the relevant coordinates,
i.e. from the top-leftmost live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
```
[Solution](data/dailyCodingProblem455.cpp)

---


#### Problem No. 456

```
You are given a list of data entries that represent entries and exits
of groups of people into a building.

An entry looks like this:

{"timestamp": 1526579928, count: 3, "type": "enter"}
This means 3 people entered the building. An exit looks like this:

{"timestamp": 1526580382, count: 2, "type": "exit"}
This means that 2 people exited the building. timestamp is in Unix time.

Find the busiest period in the building, that is, the time with
the most people in the building. Return it as a pair of (start, end) timestamps.
You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
```
[Solution](data/dailyCodingProblem456.cpp)

---


#### Problem No. 457

```
Given a word W and a string S, find all starting indices in S which are anagrams of W.
For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.
```
[Solution](data/dailyCodingProblem457.cpp)

---


#### Problem No. 458

```
A rule looks like this:

A NE B

This means this means point A is located northeast of point B.

A SW C

means that point A is southwest of C.

Given a list of rules, check if the sum of the rules validate. For example:

A N B
B NE C
C N A
does not validate, since A cannot be both north and south of C.

A NW B
A N B
is considered valid.
```
[Solution](data/dailyCodingProblem458.cpp)

---


#### Problem No. 459

```
Write a program that determines the smallest number of perfect squares that sum up to N.

Here are a few examples:

Given N = 4, return 1 (4)
Given N = 17, return 2 (16 + 1)
Given N = 18, return 2 (9 + 9)
```
[Solution](data/dailyCodingProblem459.cpp)

---


#### Problem No. 460

```
You are given a string consisting of the letters x and y, such as xyxxxyxyy.
In addition, you have an operation called flip, which changes a single x to y or vice versa.

Determine how many times you would need to apply this operation to ensure that
all x's come before all y's. In the preceding example, it suffices to
flip the second and sixth characters, so you should return 2
```
[Solution](data/dailyCodingProblem460.cpp)

---


#### Problem No. 461

```
There is an N by M matrix of zeroes. Given N and M,
write a function to count the number of ways of starting
at the top-left corner and getting to the bottom-right corner.
You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2,
since there are two ways to get to the bottom-right:

Right, then down
Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
```
[Solution](data/dailyCodingProblem461.cpp)

---


#### Problem No. 462

```
We say a number is sparse if there are no adjacent ones
in its binary representation.

For example, 21 (10101) is sparse, but 22 (10110) is not.
For a given input N, find the smallest sparse number
greater than or equal to N.

Do this in faster than O(N log N) time.
```
[Solution](data/dailyCodingProblem462.cpp)

---


#### Problem No. 463

```
First, recall that any integer must be either even or odd, a quality known as its parity.
Now suppose we have three integers (a, b, c), representing the number of Quxes of each color.
For any given configuration there will be four cases:

(a) These numbers are all even
(b) These numbers are all odd
(c) Two are even, and one is odd
(d) Two are odd, and one is even

The cases fall into two groups: either the parity of all the integers will be the same (a and b),
or the parity will break down into two numbers on one side, and one on the other (c and d).

Now note that for any transformation, we reduce the count of two colors by one,
and increase the value of the other by one. For example, in the change (R, G) -> B,
we decrement the number of red and green Quxes and increment the number of blue ones.
Crucially, this does not change which of the two above groups the line falls into.
In other words, a Qux line will always be alternating between cases a and b, or between c and d, but never both.

What, then, is the best possible outcome for each group? For the first group,
this will be either (2, 0, 0), (0, 2, 0), or (0, 0, 2). That is, once we reach a point
where we have two Quxes of one color and none of any other color, no new transformations are possible.
And since it is impossible to remove all Quxes from the line, these are the equal-parity formations with the lowest sum.

Analogously, the best outcome for a split-parity group will be (1, 0, 0), (0, 1, 0), or (0, 0, 1).

With some care we can show that as long as our initial line does not consist of all Quxes of the same color,
we can continually apply transformations to get to one of these base cases.
As a result, our solution will simply be the following:

If all Quxes begin as the same color, return the length of the line.
If the parities of each color are equal, return 2.
If the parities of each color are split, return 1.
```
[Solution](data/dailyCodingProblem463.cpp)

---


#### Problem No. 464

```
Given a set of distinct positive integers, find the largest subset such
that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20].
Given [1, 3, 6, 24], return [1, 3, 6, 24].
```
[Solution](data/dailyCodingProblem464.cpp)

---


#### Problem No. 465

```
Given the head of a singly linked list, reverse it in-place.
```
[Solution](data/dailyCodingProblem465.cpp)

---


#### Problem No. 466

```
4
      / | \
    3   5   3
  /           \
9              9
```
[Solution](data/dailyCodingProblem466.cpp)

---


#### Problem No. 467

```
Given a real number n, find the square root of n. For example, given n = 9, return 3.
```
[Solution](data/dailyCodingProblem467.cpp)

---


#### Problem No. 468

```
Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
you should return:

[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]

Follow-up: What if you couldn't use any extra space?
```
[Solution](data/dailyCodingProblem468.cpp)

---


#### Problem No. 469

```
Mastermind is a two-player game in which the first player attempts to guess
the secret code of the second. In this version,
the code may be any six-digit number with all distinct digits.

Each turn the first player guesses some number, and the second player
responds by saying how many digits in this number correctly matched
their location in the secret code. For example, if the secret code were 123456,
then a guess of 175286 would score two, since 1 and 6 were correctly placed.

Write an algorithm which, given a sequence of guesses and their scores,
determines whether there exists some secret code that could have produced them.

For example, for the following scores you should return True, since they correspond to the secret code 123456:
{175286: 2, 293416: 3, 654321: 0}

However, it is impossible for any key to result in the following scores, so in this case you should return False:
{123456: 4, 345678: 4, 567890: 4}
```
[Solution](data/dailyCodingProblem469.cpp)

---


#### Problem No. 470

```
Given an array of numbers and an index i, return
the index of the nearest larger number of the
number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0,
you should return 3.

If two distances to larger numbers are the equal,
then return any one of them. If the array at i doesn't
have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array,
can you do this in constant time?
```
[Solution](data/dailyCodingProblem470.cpp)

---


#### Problem No. 471

```
Total number of possible Binary Search Trees with n different keys
(countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!)
```
[Solution](data/dailyCodingProblem471.cpp)

---


#### Problem No. 472

```
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be
decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable.
For example, '001' is not allowed.
```
[Solution](data/dailyCodingProblem472.cpp)

---


#### Problem No. 473

```
Write an algorithm that computes the reversal of a directed graph.
For example, if a graph consists of A -> B -> C,
it should become A <- B <- C
```
[Solution](data/dailyCodingProblem473.cpp)

---


#### Problem No. 474

```
If V == 0, then 0 coins required.
If V > 0
minCoins(coins[0..m-1], V) 
= min {1 + minCoins(V-coin[i])} 
where i varies from 0 to m-1 
and coin[i] <= V
```
[Solution](data/dailyCodingProblem474.cpp)

---


#### Problem No. 475

```
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:
is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like.
You may assume the class is used in a single-threaded program,
so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
```
[Solution](data/dailyCodingProblem475.cpp)

---


#### Problem No. 476

```
You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}.
By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
```
[Solution](data/dailyCodingProblem476.cpp)

---


#### Problem No. 477

```
What does the below code snippet print out?
How can we fix the anonymous functions to behave as we'd expect?

functions = []
for i in range(10):
    functions.append(lambda : i)

for f in functions:
    print(f())
```
[Solution](data/dailyCodingProblem477.py)

---


#### Problem No. 479

```
Given a number in the form of a list of digits, return all possible permutations.
For example, given [1,2,3], return [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
```
[Solution](data/dailyCodingProblem479.cpp)

---


#### Problem No. 480

```
Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list. If there is more than one possible reconstruction, return any of them.
If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and
the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and
the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
```
[Solution](data/dailyCodingProblem480.cpp)

---


#### Problem No. 481

```
Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.

The expression is given as a list of numbers and operands. For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5,
since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.
```
[Solution](data/dailyCodingProblem481.cpp)

---


#### Problem No. 482

```
Given a binary search tree and a range [a, b] (inclusive),
return the sum of the elements of the binary search tree within the range.

For example, given the following tree:

    5
   / \
  3   8
 / \ / \
2  4 6  10
and the range [4, 9], return 23 (5 + 4 + 6 + 8).
```
[Solution](data/dailyCodingProblem482.cpp)

---


#### Problem No. 483

```
There are N prisoners standing in a circle, waiting to be executed.
The executions are carried out starting with the kth person,
and removing every successive kth person going clockwise until there is no one left.

Given N and k, write an algorithm to determine where a prisoner should stand in order to be the last survivor.

For example, if N = 5 and k = 2, the order of executions would be [2, 4, 1, 5, 3], so you should return 3.

Bonus: Find an O(log N) solution if k = 2.
```
[Solution](data/dailyCodingProblem483.cpp)

---


#### Problem No. 484

```
Given the root to a binary search tree, find the second largest node in the tree.
```
[Solution](data/dailyCodingProblem484.cpp)

---


#### Problem No. 485

```
Given an integer k and a string s,
find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2,
the longest substring with k distinct characters is "bcb"
```
[Solution](data/dailyCodingProblem485.cpp)

---


#### Problem No. 486

```
At a party, there is a single person who everyone knows,
but who does not know anyone in return (the "celebrity").

To help figure out who this is, you have access to an O(1) method called knows(a, b),
which returns True if person a knows person b, else False.

Given a list of N people and the above operation, find a way to identify the celebrity in O(N) time.
```
[Solution](data/dailyCodingProblem486.cpp)

---


#### Problem No. 487

```
Two nodes in a binary tree can be called cousins if they are
on the same level of the tree but have different parents.

For example, in the following diagram 4 and 6 are cousins.

    1
   / \
  2   3
 / \   \
4   5   6

Given a binary tree and a particular node, find all cousins of that node.
```
[Solution](data/dailyCodingProblem487.cpp)

---


#### Problem No. 488

```
Implement a queue using a set of fixed-length arrays.
The queue should support enqueue, dequeue, and get_size operations.
```
[Solution](data/dailyCodingProblem488.cpp)

---


#### Problem No. 489

```
Given an array of elements, return the length of the
longest subarray where all its elements are distinct

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1],
return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
```
[Solution](data/dailyCodingProblem489.cpp)

---


#### Problem No. 490

```
The horizontal distance of a binary tree node describes
how far left or right the node will be when the tree is printed out.

More rigorously, we can define it as follows:

The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.
For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8
The bottom view of a tree, then, consists of the lowest node at each horizontal distance.
If there are two nodes at the same depth and horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
```
[Solution](data/dailyCodingProblem490.cpp)

---


#### Problem No. 491

```
Write a program that checks whether an integer is a palindrome.
For example, 121 is a palindrome, as well as 888. 678 is not a palindrome.
Do not convert the integer into a string.
```
[Solution](data/dailyCodingProblem491.cpp)

---


#### Problem No. 492

```
Given an undirected graph represented as an adjacency matrix and an integer k,
write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors
```
[Solution](data/dailyCodingProblem492.cpp)

---


#### Problem No. 493

```
You are given n numbers as well as n probabilities that sum up to 1.
Write a function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2],
your function should return 1 10% of the time, 2 50% of the time, and 3 and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
```
[Solution](data/dailyCodingProblem493.cpp)

---


#### Problem No. 494

```
Given a circular array, compute its maximum subarray sum in O(n) time.
A subarray can be empty, and in this case the sum is 0.
For example, given [8, -1, 3, 4], return 15 as we choose
the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
```
[Solution](data/dailyCodingProblem494.cpp)

---


#### Problem No. 495

```
Given a stream of elements too large to store in memory,
pick a random element from the stream with uniform probability.
```
[Solution](data/dailyCodingProblem495.cpp)

---


#### Problem No. 496

```
Write an algorithm that finds the total number of set bits in all integers between 1 and N
```
[Solution](data/dailyCodingProblem496.cpp)

---


#### Problem No. 497

```
Recall that a full binary tree is one in which each node is either a leaf node, or has two children.
Given a binary tree, convert it to a full one by removing nodes with only one child.

For example, given the following tree:

         0
      /     \
    1         2
  /            \
3                 4
  \             /   \
    5          6     7

You should convert it to:

     0
  /     \
5         4
        /   \
       6     7
```
[Solution](data/dailyCodingProblem497.cpp)

---


#### Problem No. 498

```
Given an array of integers out of order, determine the bounds of the smallest window
that must be sorted in order for the entire array to be sorted.
For example, given [3, 7, 5, 6, 9], you should return (1, 3)
```
[Solution](data/dailyCodingProblem498.cpp)

---


#### Problem No. 500

```
You are given an M by N matrix consisting of booleans that represents a board.
Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate,
return the minimum number of steps required to reach the end coordinate from the start.
If there is no possible path, then return null. You can move up, left, down, and right.
You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]

and start = (3, 0) (bottom left) and end = (0, 0) (top left),
the minimum number of steps required to reach the end is 7,
since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
```
[Solution](data/dailyCodingProblem500.cpp)

---


#### Problem No. 501

```
Given a function that generates perfectly random numbers between 1 and k (inclusive),
where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
```
[Solution](data/dailyCodingProblem501.cpp)

---


#### Problem No. 502

```
Given a binary tree, determine whether or not it is height-balanced.
A height-balanced binary tree can be defined as one in which the heights
of the two subtrees of any node never differ by more than one.
```
[Solution](data/dailyCodingProblem502.cpp)

---


#### Problem No. 503

```
Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99.
```
[Solution](data/dailyCodingProblem503.cpp)

---


#### Problem No. 504

```
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
```
[Solution](data/dailyCodingProblem504.cpp)

---


#### Problem No. 505

```
Given an array and a number k that's smaller than the length of the array,
rotate the array to the right k elements in-place.
```
[Solution](data/dailyCodingProblem505.cpp)

---


#### Problem No. 506

```
Given a linked list, rearrange the node values such that they appear
in alternating low -> high -> low -> high ... form. For example,
given 1 -> 2 -> 3 -> 4 -> 5, you should return 1 -> 3 -> 2 -> 5 -> 4.
```
[Solution](data/dailyCodingProblem506.c)

---


#### Problem No. 507

```
On election day, a voting machine writes data in the form (voter_id, candidate_id) to a text file.
Write a program that reads this file as a stream and returns the top 3 candidates at any given time.
If you find a voter voting more than once, report this as fraud
```
[Solution](data/dailyCodingProblem507.cpp)

---


#### Problem No. 508

```
Create an algorithm to efficiently compute the approximate median of a list of numbers.
More precisely, given an unordered list of N numbers, find an element whose rank is between N / 4 and 3 * N / 4,
with a high level of certainty, in less than O(N) time.
```
[Solution](data/dailyCodingProblem508.cpp)

---


#### Problem No. 509

```
Given a string, find the palindrome that can be made by inserting
the fewest number of characters as possible anywhere in the word.
If there is more than one palindrome of minimum length that can
be made, return the lexicographically earliest one
(the first one alphabetically).

For example, given the string "race", you should return "ecarace",
since we can add three letters to it (which is the smallest amount
to make a palindrome). There are seven other palindromes that can
be made from "race" by adding three letters, but "ecarace" comes
first alphabetically.

As another example, given the string "google",
you should return "elgoogle".
```
[Solution](data/dailyCodingProblem509.cpp)

---


#### Problem No. 510

```
iven a list of words, find all pairs of unique indices such that
the concatenation of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)].
```
[Solution](data/dailyCodingProblem510.cpp)

---


#### Problem No. 511

```
You are given an array of integers, where each element represents the maximum
number of steps that can be jumped going forward from that element.
Write a function to return the minimum number of jumps you must take
in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2,
as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
```
[Solution](data/dailyCodingProblem511.cpp)

---


#### Problem No. 512

```
You are given an array of nonnegative integers.
Let's say you start at the beginning of the array and are trying to advance to the end.
You can advance at most, the number of steps that you're currently on.
Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1],
we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0],
we can't reach the end, so return false.
```
[Solution](data/dailyCodingProblem512.cpp)

---


#### Problem No. 513

```
Given a list of integers and a number K, return which contiguous elements of the list sum to K.
For example, if the list is [1, 2, 3, 4, 5] and K is 9,
then it should return [2, 3, 4], since 2 + 3 + 4 = 9.
```
[Solution](data/dailyCodingProblem513.cpp)

---


#### Problem No. 514

```
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element
sequence is [1, 2, 3, 4]. Return its length: 4.
```
[Solution](data/dailyCodingProblem514.cpp)

---


#### Problem No. 515

```
Given a linked list of numbers and a pivot k, partition the linked list
so that all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3,
the solution could be 1 -> 0 -> 5 -> 8 -> 3.
```
[Solution](data/dailyCodingProblem515.cpp)

---


#### Problem No. 516

```
Let's define a "sevenish" number to be one which is either a power of 7,
or the sum of unique powers of 7. The first few sevenish numbers are 1, 7, 8, 49, and so on.
Create an algorithm to find the nth sevenish number.
```
[Solution](data/dailyCodingProblem516.cpp)

---


#### Problem No. 517

```
Given two singly linked lists that intersect at some point, find the intersecting node.
The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
```
[Solution](data/dailyCodingProblem517.cpp)

---


#### Problem No. 518

```
Given an array of numbers and a number k, determine if there are three entries in the array
which add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49,
return true as 20 + 4 + 25 = 49.
```
[Solution](data/dailyCodingProblem518.cpp)

---


#### Problem No. 519

```
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0,
using only mathematical or bit operations. You can assume b can only be 1 or 0.
```
[Solution](data/dailyCodingProblem519.cpp)

---


#### Problem No. 520

```
You are given a binary tree in a peculiar string representation.
Each node is written in the form (lr), where l corresponds to the
left child and r corresponds to the right child.

If either l or r is null, it will be represented as a zero.
Otherwise, it will be represented by a new (lr) pair.

Here are a few examples:

A root node with no children: (00)
A root node with two children: ((00)(00))
An unbalanced tree with three consecutive left children: ((((00)0)0)0)

Given this representation, determine the depth of the tree.
```
[Solution](data/dailyCodingProblem520.cpp)

---


#### Problem No. 521

```
Given a string and a number of lines k, print the string in zigzag form.
In zigzag, characters are printed out diagonally from top left to bottom right
until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
```
[Solution](data/dailyCodingProblem521.cpp)

---


#### Problem No. 522

```
Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string.
For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].
```
[Solution](data/dailyCodingProblem522.cpp)

---


#### Problem No. 523

```
Given integers M and N, write a program that counts how many positive integer pairs (a, b)
satisfy the following conditions:

a + b = M
a XOR b = N
```
[Solution](data/dailyCodingProblem523.cpp)

---


#### Problem No. 524

```
For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137,
since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.
```
[Solution](data/dailyCodingProblem524.cpp)

---


#### Problem No. 525

```
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
```
[Solution](data/dailyCodingProblem525.cpp)

---


#### Problem No. 526

```
You are given a string of length N and a parameter k. The string can be manipulated by
taking one of the first k letters and moving it to the end.

Write a program to determine the lexicographically smallest string that can be created
after an unlimited number of moves.

For example, suppose we are given the string daily and k = 1.
The best we can create in this case is ailyd.
```
[Solution](data/dailyCodingProblem526.cpp)

---


#### Problem No. 527

```
Write a program to determine how many distinct ways there are to create a
max heap from a list of N given integers.

For example, if N = 3, and our integers are [1, 2, 3], there are two ways, shown below.

  3      3
 / \    / \
1   2  2   1
```
[Solution](data/dailyCodingProblem527.cpp)

---


#### Problem No. 528

```
Huffman coding is a method of encoding characters based on their frequency.
Each letter is assigned a variable-length binary string, such as 0101 or 111110,
where shorter lengths correspond to more common letters. To accomplish this,
a binary tree is built such that the path from the root to any leaf uniquely
maps to a character. When traversing the path, descending to a left child
corresponds to a 0 in the prefix, while descending right corresponds to 1.

Here is an example tree (note that only the leaf nodes have letters):

        *
      /   \
    *       *
   / \     / \
  *   a   t   *
 /             \
c               s

With this encoding, cats would be represented as 0000110111.

Given a dictionary of character frequencies, build a Huffman tree,
and use it to determine a mapping between characters and their encoded binary strings.
```
[Solution](data/dailyCodingProblem528.cpp)

---


#### Problem No. 529

```
Given a string, split it into as few strings as possible
such that each string is a palindrome.

For example, given the input string racecarannakayak,
return ["racecar", "anna", "kayak"].

Given the input string abc, return ["a", "b", "c"].
```
[Solution](data/dailyCodingProblem529.cpp)

---


#### Problem No. 530

```
The edit distance between two strings refers to the minimum number of character insertions,
deletions, and substitutions required to change one string to the other. For example,
the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”,
substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
```
[Solution](data/dailyCodingProblem530.cpp)

---


#### Problem No. 531

```
Using a read7() method that returns 7 characters from a file,
implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”,
three read7() returns “Hello w”, “orld” and then “”.
```
[Solution](data/dailyCodingProblem531.cpp)

---


#### Problem No. 532

```
On our special chessboard, two bishops attack each other if they share the same diagonal.
This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard.
Write a function to count the number of pairs of bishops that attack each other.
The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)
The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.
```
[Solution](data/dailyCodingProblem532.cpp)

---


#### Problem No. 533

```
Boggle is a game played on a 4 x 4 grid of letters.
The goal is to find as many words as possible that
can be formed by a sequence of adjacent letters in
the grid, using each cell at most once. Given a game
board and a dictionary of valid words, implement a Boggle solver.
```
[Solution](data/dailyCodingProblem533.cpp)

---


#### Problem No. 534

```
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar,
which is a palindrome. daily should return false, since there's no rearrangement that can form a palindrome.
```
[Solution](data/dailyCodingProblem534.cpp)

---


#### Problem No. 535

```
You are given N identical eggs and access to a building with k floors. Your task is to find
the lowest floor that will cause an egg to break, if dropped from that floor.
Once an egg breaks, it cannot be dropped again. If an egg breaks when dropped from
the xth floor, you can assume it will also break when dropped from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops it will take,
in the worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping the egg at every floor,
beginning with the first, until we reach the fifth floor, so our solution will be 5.
```
[Solution](data/dailyCodingProblem535.cpp)

---


#### Problem No. 536

```
Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8
```
[Solution](data/dailyCodingProblem536.cpp)

---


#### Problem No. 537

```
A Collatz sequence in mathematics can be defined as follows. Starting with any positive integer:

if n is even, the next number in the sequence is n / 2
if n is odd, the next number in the sequence is 3n + 1
It is conjectured that every such sequence eventually reaches the number 1. Test this conjecture.

Bonus: What input n <= 1000000 gives the longest sequence?
```
[Solution](data/dailyCodingProblem537.cpp)

---


#### Problem No. 538

```
Given a set of characters C and an integer k, a De Bruijn sequence is a cyclic
sequence in which every possible k-length string of characters in C occurs exactly once.

For example, suppose C = {0, 1} and k = 3. Then our sequence should contain
the substrings {'000', '001', '010', '011', '100', '101', '110', '111'},
and one possible solution would be 00010111.

Create an algorithm that finds a De Bruijn sequence.
```
[Solution](data/dailyCodingProblem538.cpp)

---


#### Problem No. 539

```
Given an undirected graph, determine if it contains a cycle.
```
[Solution](data/dailyCodingProblem539.cpp)

---


#### Problem No. 540

```
In Ancient Greece, it was common to write text with the first line going left to right, the second line going right to left, and continuing to go back and forth. This style was called "boustrophedon".

Given a binary tree, write an algorithm to print the nodes in boustrophedon order.

For example, given the following tree:

       1
    /     \
  2         3
 / \       / \
4   5     6   7
You should return [1, 3, 2, 4, 5, 6, 7].
```
[Solution](data/dailyCodingProblem540.cpp)

---


#### Problem No. 541

```
Run-length encoding is a fast and simple method of encoding strings.
The basic idea is to represent repeated successive characters as a single count and character.
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be
encoded have no digits and consists solely of alphabetic characters.
You can assume the string to be decoded is valid.
```
[Solution](data/dailyCodingProblem541.cpp)

---


#### Problem No. 542

```
Given an undirected graph G, check whether it is bipartite. Recall that a graph
is bipartite if its vertices can be divided into two independent sets, U and V,
such that no edge connects vertices of the same set.
```
[Solution](data/dailyCodingProblem542.cpp)

---


#### Problem No. 543

```
Given a singly linked list and an integer k, remove the kth last element from the list.
k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.
Do this in constant space and in one pass.
```
[Solution](data/dailyCodingProblem543.cpp)

---


#### Problem No. 544

```
Given a list of integers S and a target number k, write a function that
returns a subset of S that adds up to k. If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
```
[Solution](data/dailyCodingProblem544.cpp)

---


#### Problem No. 545

```
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
Assume that each node in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
between two nodes v and w as the lowest node in T that has both v and w as descendants
(where we allow a node to be a descendant of itself).”
```
[Solution](data/dailyCodingProblem545.cpp)

---


#### Problem No. 546

```
Given an array of integers, return a new array where each element in
the new array is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1
```
[Solution](data/dailyCodingProblem546.cpp)

---


#### Problem No. 547

```
Given an array of integers, find the maximum XOR of any two elements.
```
[Solution](data/dailyCodingProblem547.cpp)

---


#### Problem No. 548

```
Given a clock time in hh:mm format, determine, to the nearest degree,
the angle between the hour and the minute hands.

Bonus: When, during the course of a day, will the angle be zero?
```
[Solution](data/dailyCodingProblem548.cpp)

---


#### Problem No. 549

```
Given an array of integers where every integer occurs three
times except for one integer, which only occurs once,
find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1.
Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
```
[Solution](data/dailyCodingProblem549.cpp)

---


#### Problem No. 550

```
Suppose you are given a table of currency exchange rates, represented as a 2D array.
Determine whether there is a possible arbitrage: that is, whether there is some
sequence of trades you can make, starting with some amount A of any currency,
so that you can end up with some amount greater than A of that currency.

There are no transaction costs and you can trade fractional quantities.
```
[Solution](data/dailyCodingProblem550.cpp)

---


#### Problem No. 551

```
Assume you have access to a function toss_biased() which returns 0 or 1 with a
probability that's not 50-50 (but also not 0-100 or 100-0).
You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.
```
[Solution](data/dailyCodingProblem551.cpp)

---


#### Problem No. 552

```
You are given a 2 x N board, and instructed to completely cover the board with the following shapes:

Dominoes, or 2 x 1 rectangles.
Trominoes, or L-shapes.
For example, if N = 4, here is one possible configuration, where A is a domino, and B and C are trominoes.

A B B C
A B C C
Given an integer N, determine in how many ways this task is possible.
```
[Solution](data/dailyCodingProblem552.cpp)

---


#### Problem No. 553

```
You are given an N by M 2D matrix of lowercase letters.
Determine the minimum number of columns that can be
removed to ensure that each row is ordered from top
to bottom lexicographically. That is, the letter at
each column is lexicographically later as you go down
each row. It does not matter whether each row itself
is ordered lexicographically.

For example, given the following table:

cba
daf
ghi

This is not ordered because of the a in the center.
We can remove the second column to make it ordered:

ca
df
gi

So your function should return 1,
since we only needed to remove 1 column.

As another example, given the following table:

abcdef

Your function should return 0,
since the rows are already ordered (there's only one row).

As another example, given the following table:

zyx
wvu
tsr

Your function should return 3,
since we would need to remove all the columns to order it.
```
[Solution](data/dailyCodingProblem553.cpp)

---


#### Problem No. 554

```
The ancient Egyptians used to express fractions as a sum of several terms where each numerator is one.
For example, 4 / 13 can be represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary fraction a / b, where a < b, into an Egyptian fraction.
```
[Solution](data/dailyCodingProblem554.cpp)

---


#### Problem No. 555

```
An sorted array of integers was rotated an unknown number of times.
Given such an array, find the index of the element in the array in faster than linear time.
If the element doesn't exist in the array, return null.
For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).
You can assume all the integers in the array are unique.
```
[Solution](data/dailyCodingProblem555.cpp)

---


#### Problem No. 556

```
Given an array of integers, write a function to determine whether the array could
become non-decreasing by modifying at most 1 element.
For example, given the array [10, 5, 7], you should return true, since we can modify
the 10 into a 1 to make the array non-decreasing.
Given the array [10, 5, 1], you should return false, since we can't modify any one
element to get a non-decreasing array.
```
[Solution](data/dailyCodingProblem556.cpp)

---


#### Problem No. 557

```
Suppose you have a multiplication table that is N by N. That is, a 2D array where the value
at the i-th row and j-th column is (i + 1) * (j + 1) (if 0-indexed) or i * j (if 1-indexed).

Given integers N and X, write a function that returns the number of times X appears as a
value in an N by N multiplication table.

For example, given N = 6 and X = 12, you should return 4, since the multiplication table looks like this:

| 1 | 2 | 3 | 4 | 5 | 6 |

| 2 | 4 | 6 | 8 | 10 | 12 |

| 3 | 6 | 9 | 12 | 15 | 18 |

| 4 | 8 | 12 | 16 | 20 | 24 |

| 5 | 10 | 15 | 20 | 25 | 30 |

| 6 | 12 | 18 | 24 | 30 | 36 |

And there are 4 12's in the table
```
[Solution](data/dailyCodingProblem557.cpp)

---


#### Problem No. 558

```
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
```
[Solution](data/dailyCodingProblem558.cpp)

---


#### Problem No. 559

```
Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
```
[Solution](data/dailyCodingProblem559.cpp)

---


#### Problem No. 560

```
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
```
[Solution](data/dailyCodingProblem560.cpp)

---


#### Problem No. 561

```
Given a sorted array, convert it into a height-balanced binary search tree.
```
[Solution](data/dailyCodingProblem561.cpp)

---


#### Problem No. 562

```
Given an array of integers, return a new array such that each element
at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
```
[Solution](data/dailyCodingProblem562.cpp)

---


#### Problem No. 563

```
Find the maximum of two numbers without using any if-else statements, branching, or direct comparisons.
```
[Solution](data/dailyCodingProblem563.cpp)

---


#### Problem No. 564

```
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10,
since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
```
[Solution](data/dailyCodingProblem564.cpp)

---


#### Problem No. 565

```
Given an integer list where each number represents the number of hops you can make,
determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.
```
[Solution](data/dailyCodingProblem565.cpp)

---


#### Problem No. 566

```
A graph is minimally-connected if it is connected and there is no edge that can be removed while
still leaving the graph connected. For example, any binary tree is minimally-connected.

Given an undirected graph, check if the graph is minimally-connected.
You can choose to represent the graph as either an adjacency matrix or adjacency list.
```
[Solution](data/dailyCodingProblem566.cpp)

---


#### Problem No. 567

```
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns
the first and last element of that pair.
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
```
[Solution](data/dailyCodingProblem567.py)

---


#### Problem No. 568

```
Given a sorted list of integers, square the elements and give the output in sorted order.
For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
```
[Solution](data/dailyCodingProblem568.cpp)

---


#### Problem No. 569

```
Given an array of numbers of length N,
find both the minimum and maximum using less than 2 * (N - 2) comparisons.
```
[Solution](data/dailyCodingProblem569.cpp)

---


#### Problem No. 570

```
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure
and node values with a subtree of s. A subtree of s is a tree consists of a node in s
and all of this node's descendants. The tree s could also be considered as a subtree of itself.
```
[Solution](data/dailyCodingProblem570.cpp)

---


#### Problem No. 571

```
The Tower of Hanoi is a puzzle game with three rods and n disks, each a different size.

All the disks start off on the first rod in a stack. They are ordered by size,
with the largest disk on the bottom and the smallest one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:

You can only move one disk at a time.
A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.
You cannot place a larger disk on top of a smaller disk.
Write a function that prints out all the steps necessary to complete the Tower of Hanoi.
You should assume that the rods are numbered, with the first rod being 1,
the second (auxiliary) rod being 2, and the last (goal) rod being 3.

For example, with n = 3, we can do this in 7 moves:

Move 1 to 3
Move 1 to 2
Move 3 to 2
Move 1 to 3
Move 2 to 1
Move 2 to 3
Move 1 to 3
```
[Solution](data/dailyCodingProblem571.cpp)

---


#### Problem No. 572

```
Given a number represented by a list of digits, find the next greater permutation of a number,
in terms of lexicographic ordering. If there is not greater permutation possible,
return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3].
The list [3,2,1] should return [1,2,3].

Can you perform the operation without allocating extra memory (disregarding the input memory)?

Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"
```
[Solution](data/dailyCodingProblem572.cpp)

---


#### Problem No. 573

```
Given a stack of N elements, interleave the first half of the stack with the second half
reversed using only one other queue. This should be done in-place.

Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.

For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3].
If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].

Hint: Try working backwards from the end state.
```
[Solution](data/dailyCodingProblem573.cpp)

---


#### Problem No. 574

```
Implement a bit array.

A bit array is a space efficient array that holds a value of 1 or 0 at each index.

init(size): initialize the array with size
set(i, val): updates index at i with val where val is either 1 or 0.
get(i): gets the value at index i.
```
[Solution](data/dailyCodingProblem574.cpp)

---


#### Problem No. 575

```
Implement a 2D iterator class. It will be initialized with an array of arrays,
and should implement the following methods:

next(): returns the next element in the array of arrays. If there are no more elements,
raise an exception.
has_next(): returns whether or not the iterator still has elements left.
For example, given the input [[1, 2], [3], [], [4, 5, 6]],
calling next() repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays.
Some of the arrays can be empty.
```
[Solution](data/dailyCodingProblem575.cpp)

---


#### Problem No. 576

```
Write a function, throw_dice(N, faces, total), that determines how many ways
it is possible to throw N dice with some number of faces each to get a specific total.

For example, throw_dice(3, 6, 7) should equal 15.
```
[Solution](data/dailyCodingProblem576.cpp)

---


#### Problem No. 577

```
Given a list of words, determine whether the words can be chained to form a circle.
A word X can be placed in front of another word Y in a circle if the last character
of X is same as the first character of Y.

For example, the words ['chair', 'height', 'racket', touch', 'tunic'] can
form the following circle: chair --> racket --> touch --> height --> tunic --> chair.
```
[Solution](data/dailyCodingProblem577.cpp)

---


#### Problem No. 578

```
Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
```
[Solution](data/dailyCodingProblem578.cpp)

---


#### Problem No. 579

```
Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.

On the ith jump, you may move exactly i places to the left or right.

Find a path with the fewest number of jumps required to get from 0 to N.
```
[Solution](data/dailyCodingProblem579.cpp)

---


#### Problem No. 580

```
Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

  10
 /  \
5    5
 \     \
   2    1
       /
     -1
```
[Solution](data/dailyCodingProblem580.cpp)

---


#### Problem No. 581

```
Given two rectangles on a 2D graph, return the area of their intersection.
If the rectangles don't intersect, return 0.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
and

{
    "top_left": (0, 5),
    "dimensions" (4, 3) # width, height
}

return 6.
```
[Solution](data/dailyCodingProblem581.cpp)

---


#### Problem No. 582

```
Let X be a set of n intervals on the real line.
We say that a set of points P "stabs" X if every interval
in X contains at least one point in P. Compute the smallest set of points that stabs X.

For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should return [4, 9].
```
[Solution](data/dailyCodingProblem582.cpp)

---


#### Problem No. 583

```
You are given a 2-d matrix where each cell
represents number of coins in that cell.
Assuming we start at matrix[0][0], and can
only move right or down, find the maximum
number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1

The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
```
[Solution](data/dailyCodingProblem583.cpp)

---


#### Problem No. 584

```
Given a string with repeated characters,
rearrange the string so that no two adjacent
characters are the same.
If this is not possible, return None.

For example, given "aaabbc",
you could return "ababac".

Given "aaab", return None.
```
[Solution](data/dailyCodingProblem584.cpp)

---


#### Problem No. 585

```
Given an N by M matrix consisting only of 1's and 0's,
find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
Return 4.
```
[Solution](data/dailyCodingProblem585.cpp)

---


#### Problem No. 586

```
You are given a list of (website, user) pairs that represent users visiting websites.
Come up with a program that identifies the top k pairs of websites with the greatest similarity.

For example, suppose k = 1, and the list of tuples is:

[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5)
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e': 5), ('e', 6)]

Then a reasonable similarity metric would most likely conclude that a and e are the most similar,
so your program should return [('a', 'e')].
```
[Solution](data/dailyCodingProblem586.cpp)

---


#### Problem No. 587

```
Given a binary tree,
return all paths from the root to leaves.

For example, given the tree:

   1
  / \
 2   3
    / \
   4   5

Return [[1, 2], [1, 3, 4], [1, 3, 5]].
```
[Solution](data/dailyCodingProblem587.cpp)

---


#### Problem No. 588

```
You have a large array with most of the elements as zero.

Use a more space-efficient data structure, SparseArray, that implements the same interface:

init(arr, size): initialize with the original large array and size.
set(i, val): updates index at i with val.
get(i): gets the value at index i.
```
[Solution](data/dailyCodingProblem588.cpp)

---


#### Problem No. 589

```
Alice wants to join her school's Probability Student Club.
Membership dues are computed via one of two simple probabilistic games.

The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six.
Your number of rolls is the amount you pay, in dollars.

The second game: same, except that the stopping condition is a five followed by a five.

Which of the two games should Alice elect to play? Does it even matter?
Write a program to simulate the two games and calculate their expected value.
```
[Solution](data/dailyCodingProblem589.cpp)

---


#### Problem No. 590

```
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both,
which is an XOR of the next node and the previous node. Implement an XOR linked list;
it has an add(element) which adds the element to the end,
and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python),
you can assume you have access to get_pointer and dereference_pointer
functions that converts between nodes and memory addresses.
```
[Solution](data/dailyCodingProblem590.c)

---


#### Problem No. 592

```
Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
A 1 represents land and 0 represents water, so an island is a group of
1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```
[Solution](data/dailyCodingProblem592.cpp)

---


#### Problem No. 593

```
You are given an array representing the heights of neighboring buildings on a city street,
from east to west. The city assessor would like you to write an algorithm that returns
how many of these buildings have a view of the setting sun, in order to properly value the street.

For example, given the array [3, 7, 8, 3, 6, 1], you should return 3,
since the top floors of the buildings with heights 8, 6, and 1
all have an unobstructed view to the west.

Can you do this using just one forward pass through the array?
```
[Solution](data/dailyCodingProblem593.cpp)

---


#### Problem No. 595

```
The number 6174 is known as Kaprekar's contant,
after the mathematician who discovered an associated property:
for all four-digit numbers with at least two distinct digits,
repeatedly applying a simple procedure eventually results in this value.

The procedure is as follows:

For a given input x, create two new numbers that consist
of the digits in x in ascending and descending order.

Subtract the smaller number from the larger number.
For example, this algorithm terminates in three steps when starting from 1234:

4321 - 1234 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174

Write a function that returns how
many steps this will take for a given input N.
```
[Solution](data/dailyCodingProblem595.cpp)

---


#### Problem No. 596

```
Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d
```
[Solution](data/dailyCodingProblem596.cpp)

---


#### Problem No. 597

```
Given an array of integers, determine whether it contains a Pythagorean triplet.
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.
```
[Solution](data/dailyCodingProblem597.cpp)

---


#### Problem No. 598

```
You have n fair coins and you flip them all at the same time. Any that come up tails you set aside.
The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.
```
[Solution](data/dailyCodingProblem598.cpp)

---


#### Problem No. 599

```
Ghost is a two-person word game where players alternate
appending letters to a word. The first person who spells
out a word, or creates a prefix for which there is no
possible continuation, loses. Here is a sample game:

Player 1: g
Player 2: h
Player 1: o
Player 2: s
Player 1: t [loses]

Given a dictionary of words, determine the letters the
first player should start with, such that with optimal
play they cannot lose.

For example, if the dictionary is ["cat", "calf", "dog", "bear"],
the only winning start letter would be b
```
[Solution](data/dailyCodingProblem599.cpp)

---


#### Problem No. 600

```
Given a set of points (x, y) on a 2D cartesian plane, find the two closest points.
For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)],
return [(-1, -1), (1, 1)].
```
[Solution](data/dailyCodingProblem600.cpp)

---


#### Problem No. 601

```
The sequence [0, 1, ..., N] has been jumbled, and the only clue you have for its order
is an array representing whether each number is larger or smaller than the last.
Given this information, reconstruct an array that is consistent with it.
For example, given [None, +, +, -, +], you could return [1, 2, 3, 0, 4]
```
[Solution](data/dailyCodingProblem601.cpp)

---


#### Problem No. 602

```
Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0
and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n line segments
connecting each point pi to qi. Write an algorithm to determine
how many pairs of the line segments intersect.
```
[Solution](data/dailyCodingProblem602.cpp)

---


#### Problem No. 603

```
You are given an string representing the initial conditions of some dominoes.
Each element can take one of three values:

L, meaning the domino has just been pushed to the left,
R, meaning the domino has just been pushed to the right, or
., meaning the domino is standing still.

Determine the orientation of each tile when the dominoes stop falling.
Note that if a domino receives a force from the left and right side simultaneously, it will remain upright.

For example, given the string .L.R....L, you should return LL.RRRLLL.

Given the string ..R...L.L, you should return ..RR.LLLL
```
[Solution](data/dailyCodingProblem603.cpp)

---


#### Problem No. 605

```
In academia, the h-index is a metric used to calculate the impact of a researcher's papers.
It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each.
If there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each paper
are [4, 3, 0, 1, 5]. Then the h-index would be 3, since the researcher
has 3 papers with at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.
```
[Solution](data/dailyCodingProblem605.cpp)

---


#### Problem No. 606

```
A knight's tour is a sequence of moves by a knight on a
chessboard such that all squares are visited once.

Given N, write a function to return the number
of knight's tours on an N by N chessboard.
```
[Solution](data/dailyCodingProblem606.cpp)

---


#### Problem No. 607

```
There are M people sitting in a row of N seats, where M < N.
Your task is to redistribute people such that there are no
gaps between any of them, while keeping overall movement to a minimum.

For example, suppose you are faced with an input of
[0, 1, 1, 0, 1, 0, 0, 0, 1], where 0 represents an
empty seat and 1 represents a person. In this case,
one solution would be to place the person on the right
in the fourth seat. We can consider the cost of a
solution to be the sum of the absolute distance each
person must move, so that the cost here would be five.

Given an input such as the one above, return the lowest
possible cost of moving people to remove all gaps.
```
[Solution](data/dailyCodingProblem607.cpp)

---


#### Problem No. 608

```
Given a start word, an end word, and a dictionary of valid words,
find the shortest transformation sequence from start to end such
that only one letter is changed at each step of the sequence,
and each transformed word exists in the dictionary.
If there is no possible transformation, return null.
Each word in the dictionary have the same length as
start and end and is lowercase.

For example, given start = "dog", end = "cat", and
dictionary = {"dot", "dop", "dat", "cat"}, return
["dog", "dot", "dat", "cat"].

Given start = "dog", end = "cat", and dictionary
= {"dot", "tod", "dat", "dar"}, return null as
there is no possible transformation from dog to cat.
```
[Solution](data/dailyCodingProblem608.cpp)

---


#### Problem No. 609

```
Given a node in a binary search tree,
return the next bigger element,
also known as the inorder successor.

For example, the inorder successor of 22 is 30.

   10
  /  \
 5    30
     /  \
   22    35

You can assume each node has a parent pointer.
```
[Solution](data/dailyCodingProblem609.cpp)

---


#### Problem No. 610

```
Implement division of two positive integers without using the division,
multiplication, or modulus operators. Return the quotient as an integer,
ignoring the remainder.
```
[Solution](data/dailyCodingProblem610.cpp)

---


#### Problem No. 611

```
Create a data structure that performs all the following operations in O(1) time:

plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.
```
[Solution](data/dailyCodingProblem611.cpp)

---


#### Problem No. 612

```
Given a collection of intervals, find the minimum number of intervals
you need to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they
won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8),
return 1 as the last interval can be removed and the
first two won't overlap.

The intervals are not necessarily sorted in any order.
```
[Solution](data/dailyCodingProblem612.cpp)

---


#### Problem No. 613

```
Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map.
If the key already exists, overwrite the value.
sum(prefix: str): Return the sum of all values of
keys that begin with a given prefix.

For example, you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
```
[Solution](data/dailyCodingProblem613.cpp)

---


#### Problem No. 614

```
A network consists of nodes labeled 0 to N.
You are given a list of edges (a, b, t),
describing the time t it takes for a
message to be sent from node a to node b.
Whenever a node receives a message,
it immediately passes the message on
to a neighboring node, if possible.

Assuming all nodes are connected,
determine how long it will take for
every node to receive a message
that begins at node 0.

For example, given N = 5, and the following edges:

edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
You should return 9, because propagating
the message from 0 -> 2 -> 3 -> 4
will take that much time.
```
[Solution](data/dailyCodingProblem614.cpp)

---


#### Problem No. 615

```
The stable marriage problem is defined as follows:

Suppose you have N men and N women, and each person has ranked
their prospective opposite-sex partners in order of preference.

For example, if N = 3, the input could be something like this:

guy_preferences = {
    'andrew': ['caroline', 'abigail', 'betty'],
    'bill': ['caroline', 'betty', 'abigail'],
    'chester': ['betty', 'caroline', 'abigail'],
}

gal_preferences = {
    'abigail': ['andrew', 'bill', 'chester'],
    'betty': ['bill', 'andrew', 'chester'],
    'caroline': ['bill', 'chester', 'andrew']
}

Write an algorithm that pairs the men and women together in such
a way that no two people of opposite sex would both rather be
with each other than with their current partners.
```
[Solution](data/dailyCodingProblem615.cpp)

---


#### Problem No. 616

```
A cryptarithmetic puzzle is a mathematical game where the digits of some numbers
are represented by letters. Each letter represents a unique digit.

For example, a puzzle of the form:

  SEND
+ MORE
--------
 MONEY

may have the solution:
{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}

Given a three-word puzzle like the one above,
create an algorithm that finds a solution.
```
[Solution](data/dailyCodingProblem616.cpp)

---


#### Problem No. 617

```
Given a number in Roman numeral format, convert it to decimal.

The values of Roman numerals are as follows:

{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
In addition, note that the Roman numeral system uses subtractive notation for numbers such as IV and XL.

For the input XIV, for instance, you should return 14.
```
[Solution](data/dailyCodingProblem617.cpp)

---


#### Problem No. 618

```
Given a list, sort it using this method: reverse(lst, i, j),
which reverses lst from i to j.
```
[Solution](data/dailyCodingProblem618.cpp)

---


#### Problem No. 619

```
Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

exists(board, "ABCCED") returns true,
exists(board, "SEE") returns true,
exists(board, "ABCB") returns false.
```
[Solution](data/dailyCodingProblem619.cpp)

---


#### Problem No. 620

```
A wall consists of several rows of bricks of various integer lengths and uniform height.
Your goal is to find a vertical line going from the top to the bottom of the wall
that cuts through the fewest number of bricks. If the line goes through the edge
between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values in each
row represent the lengths of bricks in that row:

[[3, 5, 1, 1],
 [2, 3, 3, 2],
 [5, 5],
 [4, 4, 2],
 [1, 3, 3, 3],
 [1, 1, 6, 1, 1]]
The best we can we do here is to draw a line after the eighth brick,
which will only require cutting through the bricks in the third and fifth row.

Given an input consisting of brick lengths for each row such as the one above,
return the fewest number of bricks that must be cut to create a vertical line.
```
[Solution](data/dailyCodingProblem620.cpp)

---


#### Problem No. 621

```
Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h

and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1,
the longest path would be c -> a -> d -> f, with a length of 17.

The path does not have to pass through the root,
and each node can have any amount of children.
```
[Solution](data/dailyCodingProblem621.cpp)

---


#### Problem No. 622

```
Given the root of a binary tree, return a deepest node.
For example, in the following tree, return d.

    a
   / \
  b   c
 /
d
```
[Solution](data/dailyCodingProblem622.cpp)

---


#### Problem No. 623

```
Write an algorithm to justify text. Given a sequence of words and an integer line length k,
return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line.
There should be at least one space between each word. Pad extra spaces when
necessary so that each line has exactly length k. Spaces should be
distributed as equally as possible, with the extra spaces, if any,
distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words
["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
```
[Solution](data/dailyCodingProblem623.cpp)

---


#### Problem No. 624

```
Given a string of parentheses, write a function to compute the minimum
number of parentheses to be removed to make the string valid
(i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1.
Given the string ")(", you should return 2,
since we must remove all of them.
```
[Solution](data/dailyCodingProblem624.cpp)

---


#### Problem No. 625

```
Given an integer n, return the length of the
longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
```
[Solution](data/dailyCodingProblem625.cpp)

---


#### Problem No. 626

```
Given a list of integers, return the largest product
that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2],
we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.
```
[Solution](data/dailyCodingProblem626.cpp)

---


#### Problem No. 627

```
Given an iterator with methods next() and hasNext(),
create a wrapper iterator, PeekableInterface,
which also implements peek(). peek shows the
next element that would be returned on next().

Here is the interface:

class PeekableInterface(object):
    def __init__(self, iterator):
        pass

    def peek(self):
        pass

    def next(self):
        pass

    def hasNext(self):
        pass
```
[Solution](data/dailyCodingProblem627.py)

---


#### Problem No. 628

```
You are given a circular lock with three wheels,
each of which display the numbers 0 through 9 in order.
Each of these wheels rotate clockwise and counterclockwise.

In addition, the lock has a certain number of "dead ends",
meaning that if you turn the wheels to one of these combinations,
the lock becomes stuck in that state and cannot be opened.

Let us consider a "move" to be a rotation of a single wheel by one digit,
in either direction. Given a lock initially set to 000,
a target combination, and a list of dead ends, write a
function that returns the minimum number of moves required
to reach the target state, or None if this is impossible.
```
[Solution](data/dailyCodingProblem628.cpp)

---


#### Problem No. 629

```
Given an array of numbers N and an integer k, your task is to split N into
k partitions such that the maximum sum of any partition is minimized.
Return this sum.

For example, given N = [5, 1, 2, 7, 3, 4] and k = 3, you should return 8,
since the optimal partition is [5, 1, 2], [7], [3, 4].
```
[Solution](data/dailyCodingProblem629.cpp)

---


#### Problem No. 630

```
Implement a job scheduler which takes in a function
f and an integer n, and calls f after n milliseconds.
```
[Solution](data/dailyCodingProblem630.cpp)

---


#### Problem No. 631

```
The skyline of a city is composed of several buildings of various widths and heights,
possibly overlapping one another when viewed from a distance. We can represent the
buildings using an array of (left, right, height) tuples, which tell us where on an
imaginary x-axis a building begins and ends, and how tall it is. The skyline itself
can be described by a list of (x, height) tuples, giving the locations at which the
height visible to a distant observer changes, and each new height.

Given an array of buildings as described above, create a function that returns the skyline.

For example, suppose the input consists of the buildings [(0, 15, 3), (4, 11, 5), (19, 23, 4)].
In aggregate, these buildings would create a skyline that looks like the one below.

     ______  
    |      |        ___
 ___|      |___    |   | 
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
As a result, your function should return [(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)].
```
[Solution](data/dailyCodingProblem631.cpp)

---


#### Problem No. 633

```
You are given a list of N numbers, in which each number is located at most k
places away from its sorted position. For example, if k = 1, a given element
at index 4 might end up at indices 3, 4, or 5.

Come up with an algorithm that sorts this list in O(N log k) time.
```
[Solution](data/dailyCodingProblem633.cpp)

---


#### Problem No. 634

```
You are given a histogram consisting of rectangles of different heights.
These heights are represented in an input list, such that [1, 3, 2, 5]
corresponds to the following diagram:

      x
      x
  x   x
  x x x
x x x x

Determine the area of the largest rectangle that can be formed only
from the bars of the histogram. For the diagram above, for example,
this would be six, representing the 2 x 3 area at the bottom right.
```
[Solution](data/dailyCodingProblem634.cpp)

---


#### Problem No. 635

```
Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element

That is, implement a function that takes in a string and a valid regular
expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray",
your function should return true. The same regular expression on the
string "raymond" should return false.

Given the regular expression ".*at" and the string "chat",
your function should return true. The same regular expression
on the string "chats" should return false.
```
[Solution](data/dailyCodingProblem635.c)

---


#### Problem No. 636

```
Suppose an array sorted in ascending order is rotated at some pivot
unknown to you beforehand. Find the minimum element in O(log N) time.
You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
```
[Solution](data/dailyCodingProblem636.cpp)

---


#### Problem No. 637

```
Given a list of possibly overlapping intervals, return a new list of
intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)],
you should return [(1, 3), (4, 10), (20, 25)].
```
[Solution](data/dailyCodingProblem637.cpp)

---


#### Problem No. 638

```
Given a string of words delimited by spaces, reverse the words in string.
For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation,
can you perform this operation in-place?
```
[Solution](data/dailyCodingProblem638.cpp)

---


#### Problem No. 639

```
Given a mapping of digits to letters (as in a phone number),
and a digit string, return all possible letters the number
could represent. You can assume each valid number in the
mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …}
then “23” should return [“ad”, “ae”, “af”, “bd”, “be”,
“bf”, “cd”, “ce”, “cf"].
```
[Solution](data/dailyCodingProblem639.cpp)

---


#### Problem No. 640

```
You are given a starting state start, a list of transition probabilities for a Markov chain,
and a number of steps num_steps. Run the Markov chain starting from start for num_steps and
compute the number of times we visited each state.

For example, given the starting state a, number of steps 5000,
and the following transition probabilities:

[
  ('a', 'a', 0.9),
  ('a', 'b', 0.075),
  ('a', 'c', 0.025),
  ('b', 'a', 0.15),
  ('b', 'b', 0.8),
  ('b', 'c', 0.05),
  ('c', 'a', 0.25),
  ('c', 'b', 0.25),
  ('c', 'c', 0.5)
]

One instance of running this Markov chain might
produce { 'a': 3012, 'b': 1656, 'c': 332 }.
```
[Solution](data/dailyCodingProblem640.cpp)

---


#### Problem No. 641

```
Given a sorted array, find the smallest positive integer
that is not the sum of a subset of the array.

For example, for the input [1, 2, 3, 10],
you should return 7.

Do this in O(N) time.
```
[Solution](data/dailyCodingProblem641.cpp)

---


#### Problem No. 642

```
A step word is formed by taking a given word, adding a letter, and anagramming the result.
For example, starting with the word "APPLE", you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word,
create a function that returns all valid step words.
```
[Solution](data/dailyCodingProblem642.cpp)

---


#### Problem No. 643

```
Write a program that computes the length of the longest common subsequence
of three given strings. For example, given "epidemiologist", "refrigeration",
and "supercalifragilisticexpialodocious", it should return 5,
since the longest common subsequence is "eieio".
```
[Solution](data/dailyCodingProblem643.cpp)

---


#### Problem No. 644

```
A unival tree (which stands for "universal value") is a
tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
```
[Solution](data/dailyCodingProblem644.cpp)

---


#### Problem No. 645

```
Given a 2D matrix of characters and a target word, write a function that returns whether
the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true, since it's the leftmost column.
Similarly, given the target word 'MASS', you should return true, since it's the last row.
```
[Solution](data/dailyCodingProblem645.cpp)

---


#### Problem No. 646

```
A classroom consists of N students, whose friendships can be represented in an adjacency list.
For example, the following descibes a situation where 0 is friends with
1 and 2, 3 is friends with 6, and so on.

{0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]} 

Each student can be placed in a friend group, which can be
defined as the transitive closure of that student's friendship relations.
In other words, this is the smallest set such that no student in the group
has any friends outside this group. For the example above, the friend
groups would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above,
determine the number of friend groups in the class.
```
[Solution](data/dailyCodingProblem646.cpp)

---


#### Problem No. 647

```
Given a multiset of integers, return whether it can be partitioned
into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10},
it would return true, since we can split it up into
{15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false,
since we can't split it up into two subsets that add up to the same sum.
```
[Solution](data/dailyCodingProblem647.cpp)

---


#### Problem No. 648

```
Given the head to a singly linked list, where each node also has a “random” pointer
that points to anywhere in the linked list, deep clone the list.
```
[Solution](data/dailyCodingProblem648.cpp)

---


#### Problem No. 649

```
Given a string, return the first recurring character in it,
or null if there is no recurring character.

For example, given the string "acbbac", return "b".
Given the string "abcdef", return null.
```
[Solution](data/dailyCodingProblem649.cpp)

---


#### Problem No. 650

```
Let A be an N by M matrix in which every row and every column is sorted.

Given i1, j1, i2, and j2, compute the number of elements of M smaller
than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]

And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15 numbers
in the matrix smaller than 6 or greater than 23.
```
[Solution](data/dailyCodingProblem650.cpp)

---


#### Problem No. 651

```
Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right,
and satisfies the constraint that the key in the left child must
be less than or equal to the root and the key in the right child
must be greater than or equal to the root.
```
[Solution](data/dailyCodingProblem651.cpp)

---


#### Problem No. 652

```
You are going on a road trip, and would like to create a suitable music playlist.
The trip will require N songs, though you only have M songs downloaded, where M < N.
A valid playlist should select each song at least once, and guarantee a buffer of B songs between repeats.

Given N, M, and B, determine the number of valid playlists.
```
[Solution](data/dailyCodingProblem652.cpp)

---


#### Problem No. 653

```
You are given given a list of rectangles represented by min and max x- and y-coordinates.
Compute whether or not a pair of rectangles overlap each other.
If one rectangle completely covers another, it is considered overlapping.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
return true as the first and third rectangle overlap each other.
```
[Solution](data/dailyCodingProblem653.cpp)

---


#### Problem No. 654

```
Given a string, find the length of the smallest window
that contains every distinct character.
Characters may appear more than once in the window.

For example, given "jiujitsu", you should return 5,
corresponding to the final five letters.
```
[Solution](data/dailyCodingProblem654.cpp)

---


#### Problem No. 655

```
Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000,
return 0000 1111 0000 1111 0000 1111 0000 1111.
```
[Solution](data/dailyCodingProblem655.cpp)

---


#### Problem No. 656

```
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C,
replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

B B W
W W W
W W W
B B B
Becomes

B B G
G G G
G G G
B B B
```
[Solution](data/dailyCodingProblem656.cpp)

---


#### Problem No. 657

```
The power set of a set is the set of all its subsets.
Write a function that, given a set,
generates its power set.

For example, given the set {1, 2, 3}, it should return
{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
```
[Solution](data/dailyCodingProblem657.cpp)

---


#### Problem No. 658

```
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a
sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2.
subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1.
subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute
path to a file within our file system. For example, in the second example above,
the longest absolute path is "dir/subdir2/subsubdir2/file2.ext",
and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format,
return the length of the longest absolute path to a file in the
abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
```
[Solution](data/dailyCodingProblem658.cpp)

---


#### Problem No. 660

```
You come across a dictionary of sorted words in a language you've never seen before.
Write a program that returns the correct order of letters in this language.

For example, given ['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'],
you should return ['x', 'z', 'w', 'y'].
```
[Solution](data/dailyCodingProblem660.cpp)

---


#### Problem No. 661

```
Given a sorted list of integers of length N, determine if an element x is in the list
without performing any multiplication, division, or bit-shift operations.

Do this in O(log N) time.
```
[Solution](data/dailyCodingProblem661.cpp)

---


#### Problem No. 662

```
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
```
[Solution](data/dailyCodingProblem662.cpp)

---


#### Problem No. 663

```
Design and implement a HitCounter class that keeps track of requests (or hits).
It should support the following operations:

record(timestamp): records a hit that happened at timestamp
total(): returns the total number of hits recorded
range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)

Follow-up: What if our system has limited memory?
```
[Solution](data/dailyCodingProblem663.cpp)

---


#### Problem No. 664

```
Given a binary tree of integers, find the maximum path sum between two nodes.
The path must go through at least one node, and does not need to go through the root.
```
[Solution](data/dailyCodingProblem664.cpp)

---


#### Problem No. 665

```
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string,
such as zLg6wl.

restore(short), which expands the shortened string into the original url.
If no such shortened string exists, return null.

Hint: What if we enter the same URL twice?
```
[Solution](data/dailyCodingProblem665.cpp)

---


#### Problem No. 666

```
Given an array of positive integers, divide the array into two subsets such
that the difference between the sum of the subsets is as small as possible.

For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20},
which has a difference of 5, which is the smallest possible difference.
```
[Solution](data/dailyCodingProblem666.cpp)

---


#### Problem No. 667

```
In chess, the Elo rating system is used to calculate player strengths based on game results.

A simplified description of the Elo system is as follows.
Every player begins at the same score. For each subsequent game,
the loser transfers some points to the winner, where the amount
of points transferred depends on how unlikely the win is.
For example, a 1200-ranked player should gain much more
points for beating a 2000-ranked player than for beating a 1300-ranked player.

Implement this system.
```
[Solution](data/dailyCodingProblem667.cpp)

---


#### Problem No. 668

```
In linear algebra, a Toeplitz matrix is one in which the elements
on any given diagonal from top left to bottom right are identical.

Here is an example:

1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2

Write a program to determine whether a given input is a Toeplitz matrix.
```
[Solution](data/dailyCodingProblem668.cpp)

---


#### Problem No. 669

```
The game of Nim is played as follows. Starting with three heaps,
each containing a variable number of items, two players take turns
removing one or more items from a single pile.
The player who eventually is forced to take the last stone loses.
For example, if the initial heap sizes are 3, 4, and 5, a game could be played as shown below:

  A  |  B  |  C
-----------------
  3  |  4  |  5
  3  |  1  |  3
  3  |  1  |  3
  0  |  1  |  3
  0  |  1  |  0
  0  |  0  |  0 
In other words, to start, the first player takes three items from pile B.
The second player responds by removing two stones from pile C.
The game continues in this way until player one takes last stone and loses.

Given a list of non-zero starting values [a, b, c], and assuming optimal play,
determine whether the first player has a forced win.
```
[Solution](data/dailyCodingProblem669.cpp)

---


#### Problem No. 670

```
Given a positive integer n, find the smallest
number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.

Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.
```
[Solution](data/dailyCodingProblem670.cpp)

---


#### Problem No. 672

```
You are given an array of arrays of integers, where each array
corresponds to a row in a triangle of numbers.
For example, [[1], [2, 3], [1, 5, 1]] represents the triangle:

  1
 2 3
1 5 1

We define a path in the triangle to start at the top and go down
one row at a time to an adjacent value, eventually ending with
an entry on the bottom row.
For example, 1 -> 3 -> 5.
The weight of the path is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
```
[Solution](data/dailyCodingProblem672.cpp)

---


#### Problem No. 673

```
Given a list of points, a central point, and an integer k,
find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)],
the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
```
[Solution](data/dailyCodingProblem673.cpp)

---


#### Problem No. 674

```
A girl is walking along an apple orchard with a bag in each hand.
She likes to pick apples from each tree as she goes along,
but is meticulous about not putting different kinds of apples in the same bag.

Given an input describing the types of apples she will pass on her path,
in order, determine the length of the longest portion of
her path that consists of just two types of apple trees.

For example, given the input [2, 1, 2, 3, 3, 1, 3, 5],
the longest portion will involve types 1 and 3, with a length of four.
```
[Solution](data/dailyCodingProblem674.cpp)

---


#### Problem No. 675

```
You are given a set of synonyms, such as (big, large) and (eat, consume).
Using this set, determine if two sentences with the same number of words are equivalent.

For example, the following two sentences are equivalent:

"He wants to eat food."
"He wants to consume food."
Note that the synonyms (a, b) and (a, c)
do not necessarily imply (b, c):
consider the case of (coach, bus) and (coach, teacher).

Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?
```
[Solution](data/dailyCodingProblem675.cpp)

---


#### Problem No. 676

```
Given a string, return whether it represents a number.
Here are the different kinds of numbers:

"10", a positive integer
"-10", a negative integer
"10.1", a positive real number
"-10.1", a negative real number
"1e5", a number in scientific notation
And here are examples of non-numbers:

"a"
"x 1"
"a -2"
"-"
```
[Solution](data/dailyCodingProblem676.cpp)

---


#### Problem No. 677

```
The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N.
The method is to take increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would first mark
[4, 6, 8, ...] (multiples of two), then [6, 9, 12, ...] (multiples of three), and so on.
Once we have done this for all primes less than N,
the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely
(that is, without taking N as an input).
```
[Solution](data/dailyCodingProblem677.cpp)

---


#### Problem No. 678

```
Given an integer, find the next permutation of it in absolute order.
For example, given 48975, the next permutation would be 49578.
```
[Solution](data/dailyCodingProblem678.cpp)

---


#### Problem No. 679

```
We can determine how "out of order" an array A is by counting the number of inversions it has.
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j.
That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has.
Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions.
The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3).
The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
```
[Solution](data/dailyCodingProblem679.cpp)

---


#### Problem No. 680

```
Given a list of words,
return the shortest
unique prefix of each word.
For example, given the list:

dog
cat
apple
apricot
fish
Return the list:

d
c
app
apr
f
```
[Solution](data/dailyCodingProblem680.cpp)

---


#### Problem No. 681

```
Snakes and Ladders is a game played on a 10 x 10 board, the goal of which is get from square 1 to square 100.
On each turn players will roll a six-sided die and move forward a number of spaces equal to the result.
If they land on a square that represents a snake or ladder, they will be transported ahead or behind,
respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenience, here are the squares representing snakes and ladders, and their outcomes:

snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
```
[Solution](data/dailyCodingProblem681.cpp)

---


#### Problem No. 683

```
Given a list of elements, find the majority element,
which appears more than half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], return 1.
```
[Solution](data/dailyCodingProblem683.cpp)

---


#### Problem No. 684

```
reduce (also known as fold) is a function that takes in an array,
a combining function, and an initial value and builds up a result
by calling the combining function on each element of the array,
left to right. For example, we can write sum() in terms of reduce:

def add(a, b):
    return a + b

def sum(lst):
    return reduce(lst, add, 0)

This should call add on the initial value with the first element of the array,
and then the result of that with the second element of the array,
and so on until we reach the end, when we return the sum of the array.

Implement your own version of reduce.
```
[Solution](data/dailyCodingProblem684.cpp)

---


#### Problem No. 685

```
Given a string and a set of delimiters, reverse the words in the string while
maintaining the relative order of the delimiters.
For example, given "hello/world:here", return "here/world:hello"

Follow-up: Does your solution work for the following cases:
"hello/world:here/",
"hello//world:here"
```
[Solution](data/dailyCodingProblem685.cpp)

---


#### Problem No. 686

```
You are given a tree with an even number of nodes.
Consider each connection between a parent and child node to be an "edge".
You would like to remove some of these edges, such that
the disconnected subtrees that remain each have an even number of nodes.

For example, suppose your input was the following tree:

   1
  / \ 
 2   3
    / \ 
   4   5
 / | \
6  7  8

In this case, removing the edge (3, 4) satisfies our requirement.

Write a function that returns the maximum number of edges
you can remove while still satisfying this requirement.
```
[Solution](data/dailyCodingProblem686.cpp)

---


#### Problem No. 687

```
An 8-puzzle is a game played on a 3 x 3 board of tiles, with the ninth tile missing.
The remaining tiles are labeled 1 through 8 but shuffled randomly.
Tiles may slide horizontally or vertically into an empty space,
but may not be removed from the board.

Design a class to represent the board, and find a series of
steps to bring the board to the state [[1, 2, 3], [4, 5, 6], [7, 8, None]].
```
[Solution](data/dailyCodingProblem687.cpp)

---


#### Problem No. 688

```
A Boolean formula can be said to be satisfiable if there is a way to assign
truth values to each variable such that the entire formula evaluates to true.

For example, suppose we have the following formula,
where the symbol ¬ is used to denote negation:

(¬c OR b) AND (b OR c) AND (¬b OR c) AND (¬c OR ¬a)

One way to satisfy this formula would be to
let a = False, b = True, and c = True.

This type of formula, with AND statements
joining tuples containing exactly one OR,
is known as 2-CNF.

Given a 2-CNF formula, find a way to assign
truth values to satisfy it, or return False
if this is impossible.
```
[Solution](data/dailyCodingProblem688.cpp)

---


#### Problem No. 689

```
The United States uses the imperial system of weights and measures,
which means that there are many different, seemingly arbitrary units
to measure distance. There are 12 inches in a foot, 3 feet in a yard,
22 yards in a chain, and so on.

Create a data structure that can efficiently convert a certain quantity
of one unit to the correct amount of any other unit. You should also allow
for additional units to be added to the system.
```
[Solution](data/dailyCodingProblem689.cpp)

---


#### Problem No. 690

```
Given an array of numbers, find the length of the longest increasing subsequence in the array.
The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15],
the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
```
[Solution](data/dailyCodingProblem690.cpp)

---


#### Problem No. 691

```
Write a function that returns the bitwise AND of all integers between M and N, inclusive.
```
[Solution](data/dailyCodingProblem691.cpp)

---


#### Problem No. 692

```
Implement an autocomplete system. That is, given a query string s and
a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings
[dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
```
[Solution](data/dailyCodingProblem692.cpp)

---


#### Problem No. 693

```
Given an unsigned 8-bit integer, swap its even and odd bits.
The 1st and 2nd bit should be swapped,
the 3rd and 4th bit should be swapped, and so on.

For example, 10101010 should be 01010101.
11100010 should be 11010001.

Bonus: Can you do this in one line?
```
[Solution](data/dailyCodingProblem693.cpp)

---


#### Problem No. 694

```
Given an array of integers, find the first missing positive integer
in linear time and constant space. In other words,
find the lowest positive integer that does not exist in the array.
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2.
The input [1, 2, 0] should give 3.

You can modify the input array in-place.
```
[Solution](data/dailyCodingProblem694.cpp)

---


#### Problem No. 695

```
Given an integer n and a list of integers l,
write a function that randomly generates a
number from 0 to n-1 that isn't in l (uniform).
```
[Solution](data/dailyCodingProblem695.cpp)

---


#### Problem No. 696

```
You are given an array of length 24, where each element represents
the number of new subscribers during the corresponding hour.
Implement a data structure that efficiently supports the following:

update(hour: int, value: int): Increment the element at index hour by value.
query(start: int, end: int): Retrieve the number of subscribers that
have signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day,
and that you will not be asked for start and end values that wrap around midnight.
```
[Solution](data/dailyCodingProblem696.cpp)

---


#### Problem No. 697

```
Implement an LRU (Least Recently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

set(key, value): sets key to value. If there are already n items
in the cache and we are adding a new item, then it should also
remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
```
[Solution](data/dailyCodingProblem697.cpp)

---


#### Problem No. 698

```
You are given a 2-d matrix where each cell consists of either /, \, or an empty space.
Write an algorithm that determines into how many regions the slashes divide the space.

For example, suppose the input for a three-by-six grid is the following:

\    /
 \  /
  \/
Considering the edges of the matrix as boundaries, this divides the grid
into three triangles, so you should return 3.
```
[Solution](data/dailyCodingProblem698.cpp)

---


#### Problem No. 699

```
Given a linked list and a positive integer k,
rotate the list to the right by k places.

For example, given the linked list
7 -> 7 -> 3 -> 5 and k = 2,
it should become 3 -> 5 -> 7 -> 7.

Given the linked list
1 -> 2 -> 3 -> 4 -> 5 and k = 3,
it should become 3 -> 4 -> 5 -> 1 -> 2.
```
[Solution](data/dailyCodingProblem699.cpp)

---


#### Problem No. 700

```
You are given a huge list of airline ticket prices between different
cities around the world on a given day. These are all direct flights.
Each element in the list has the format (source_city, destination, price).

Consider a user who is willing to take up to k connections from their
origin city A to their destination B. Find the cheapest fare possible
for this journey and print the itinerary for that journey.

For example, our traveler wants to go from
JFK to LAX with up to 3 connections,
and our input flights are as follows:

[
    ('JFK', 'ATL', 150),
    ('ATL', 'SFO', 400),
    ('ORD', 'LAX', 200),
    ('LAX', 'DFW', 80),
    ('JFK', 'HKG', 800),
    ('ATL', 'ORD', 90),
    ('JFK', 'LAX', 500),
]

Due to some improbably low flight prices, the cheapest
itinerary would be JFK -> ATL -> ORD -> LAX, costing $440.
```
[Solution](data/dailyCodingProblem700.cpp)

---


#### Problem No. 701

```
At a popular bar, each customer has a set of favorite drinks,
and will happily accept any drink among this set.
For example, in the following situation, customer 0 will
be satisfied with drinks 0, 1, 3, or 6.

preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}
A lazy bartender working at this bar is trying to reduce his
effort by limiting the drink recipes he must memorize.
Given a dictionary input such as the one above,
return the fewest number of drinks he must learn in order to satisfy all customers.

For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.
```
[Solution](data/dailyCodingProblem701.cpp)

---


#### Problem No. 702

```
Given the root to a binary tree, implement serialize(root),
which serializes the tree into a string, and deserialize(s),
which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```
[Solution](data/dailyCodingProblem702.cpp)

---


#### Problem No. 703

```
A knight is placed on a given square on an 8 x 8 chessboard.
It is then moved randomly several times, where each move is
a standard knight move. If the knight jumps off the board
at any point, however, it is not allowed to jump back on.

After k moves, what is the probability that the knight remains on the board?
```
[Solution](data/dailyCodingProblem703.cpp)

---


#### Problem No. 704

```
One way to unlock an Android phone is through a pattern of swipes across a 1-9 keypad.

For a pattern to be valid, it must satisfy the following:

All of its keys must be distinct.
It must not connect two keys by jumping over a third key, unless that key has already been used.
For example, 4 - 2 - 1 - 7 is a valid pattern, whereas 2 - 1 - 7 is not.

Find the total number of valid unlock patterns of length N, where 1 <= N <= 9.
```
[Solution](data/dailyCodingProblem704.cpp)

---


#### Problem No. 705

```
You are given an array of non-negative integers that represents a two-dimensional
elevation map where each element is unit-width wall and the integer is the height.
Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index,
2 in the second, and 3 in the fourth index (we cannot hold 5 since it would
run off to the left), so we can trap 8 units of water.
```
[Solution](data/dailyCodingProblem705.cpp)

---


#### Problem No. 706

```
The 24 game is played as follows. You are given a list of four integers,
each between 1 and 9, in a fixed order. By placing the operators +, -, *, and /
between the numbers, and grouping them with parentheses, determine whether
it is possible to reach the value 24.

For example, given the input [5, 2, 7, 8], you should return True,
since (5 * 2 - 7) * 8 = 24.

Write a function that plays the 24 game.
```
[Solution](data/dailyCodingProblem706.cpp)

---


#### Problem No. 707

```
You are the technical director of WSPT radio, serving listeners nationwide.
For simplicity's sake we can consider each listener to live along a horizontal
line stretching from 0 (west) to 1000 (east).

Given a list of N listeners, and a list of M radio towers,
each placed at various locations along this line, determine
what the minimum broadcast range would have to be in order
for each listener's home to be covered.

For example, suppose listeners = [1, 5, 11, 20], and
towers = [4, 8, 15]. In this case the minimum range
would be 5, since that would be required for the tower
at position 15 to reach the listener at position 20.
```
[Solution](data/dailyCodingProblem707.cpp)

---


#### Problem No. 708

```
A fixed point in an array is an element whose value is equal to its index.
Given a sorted array of distinct elements, return a fixed point, if one exists.
Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2.
Given [1, 5, 7, 8], you should return False.
```
[Solution](data/dailyCodingProblem708.cpp)

---


#### Problem No. 709

```
You are given an N by M matrix of 0s and 1s.
Starting from the top left corner, how many
ways are there to reach the bottom right corner?

You can only move right and down. 0 represents
an empty space while 1 represents a wall you
cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]

Return two, as there are only two ways
to get to the bottom right:

Right, down, down, right
Down, right, down, right

The top left corner and bottom right
corner will always be 0.
```
[Solution](data/dailyCodingProblem709.cpp)

---


#### Problem No. 710

```
Given a string s and a list of words words, where each word is
the same length, find all starting indices of substrings in s
that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"],
return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"],
return [] since there are no substrings composed of
"dog" and "cat" in s.

The order of the indices does not matter.
```
[Solution](data/dailyCodingProblem710.cpp)

---


#### Problem No. 712

```
Given a string of round, curly, and square open and closing brackets,
return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
```
[Solution](data/dailyCodingProblem712.cpp)

---


#### Problem No. 713

```
Given an absolute pathname that may have . or .. as part of it,
return the shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
```
[Solution](data/dailyCodingProblem713.cpp)

---


#### Problem No. 714

```
Given the head of a singly linked list,
swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4,
return 2 -> 1 -> 4 -> 3.
```
[Solution](data/dailyCodingProblem714.cpp)

---


#### Problem No. 715

```
Determine whether a doubly linked list is a palindrome.
What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns True
while 1 -> 4 returns False.
```
[Solution](data/dailyCodingProblem715.cpp)

---


#### Problem No. 717

```
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to
build the nth house with kth color, return the minimum cost which achieves this goal.
```
[Solution](data/dailyCodingProblem717.cpp)

---


#### Problem No. 718

```
Gray code is a binary code where each successive value differ in only one bit,
as well as when wrapping around. Gray code is common in hardware so
that we don't see temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
```
[Solution](data/dailyCodingProblem718.cpp)

---


#### Problem No. 719

```
Spreadsheets often use this alphabetical encoding for its columns:
"A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id.
For example, given 1, return "A". Given 27, return "AA".
```
[Solution](data/dailyCodingProblem719.cpp)

---


#### Problem No. 720

```
Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits.
The objective is to fill the grid with the constraint that every row, column,
and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.

Implement an efficient sudoku solver.
```
[Solution](data/dailyCodingProblem720.cpp)

---


#### Problem No. 721

```
Recall that the minimum spanning tree is the subset of edges of a tree that
connect all its vertices with the smallest possible total edge weight.
Given an undirected graph with weighted edges, compute the maximum weight spanning tree.
```
[Solution](data/dailyCodingProblem721.cpp)

---


#### Problem No. 722

```
There are N couples sitting in a row of length 2 * N.
They are currently ordered randomly, but would like to
rearrange themselves so that each couple's partners
can sit side by side.

What is the minimum number of swaps necessary
for this to happen?
```
[Solution](data/dailyCodingProblem722.cpp)

---


#### Problem No. 723

```
Given a set of closed intervals, find the smallest set of numbers that
covers all the intervals. If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9],
one set of numbers that covers all these intervals is {3, 6}.
```
[Solution](data/dailyCodingProblem723.cpp)

---


#### Problem No. 724

```
Suppose an arithmetic expression is given as a binary tree.
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).
```
[Solution](data/dailyCodingProblem724.cpp)

---


#### Problem No. 725

```
Consider the following scenario: there are N mice and N holes
placed at integer points along a line. Given this, find a
method that maps mice to holes such that the largest number
of steps any mouse takes is minimized.

Each move consists of moving one mouse one unit to the left
or right, and only one mouse can fit inside each hole.

For example, suppose the mice are positioned at [1, 4, 9, 15],
and the holes are located at [10, -5, 0, 16]. In this case,
the best pairing would require us to send the mouse at 1 to
the hole at -5, so our function should return 6.
```
[Solution](data/dailyCodingProblem725.cpp)

---


#### Problem No. 727

```
Compute the running median of a sequence of numbers.
That is, given a stream of numbers, print out the
median of the list so far on each new element.

Recall that the median of an even-numbered
list is the average of the two middle numbers.

For example, given the sequence
[2, 1, 5, 7, 2, 0, 5],
your algorithm should print out:

2
1.5
2
3.5
2
2
2
```
[Solution](data/dailyCodingProblem727.cpp)

---


#### Problem No. 728

```
A teacher must divide a class of students into two teams to play dodgeball.
Unfortunately, not all the kids get along, and several
refuse to be put on the same team as that of their enemies.

Given an adjacency list of students and their enemies,
write an algorithm that finds a satisfactory pair of teams,
or returns False if none exists.

For example, given the following enemy graph
you should return the teams {0, 1, 4, 5} and {2, 3}.

students = {
    0: [3],
    1: [2],
    2: [1, 4],
    3: [0, 4, 5],
    4: [2, 3],
    5: [3]
}

On the other hand, given the input below,
you should return False.

students = {
    0: [3],
    1: [2],
    2: [1, 3, 4],
    3: [0, 2, 4, 5],
    4: [2, 3],
    5: [3]
}
```
[Solution](data/dailyCodingProblem728.cpp)

---


#### Problem No. 729

```
You have access to ranked lists of songs for various users.
Each song is represented as an integer, and more preferred
songs appear earlier in each list. For example, the list
[4, 1, 7] indicates that a user likes song 4 the best,
followed by songs 1 and 7.

Given a set of these ranked lists, interleave them to
create a playlist that satisfies everyone's priorities.

For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}.
In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
```
[Solution](data/dailyCodingProblem729.cpp)

---


#### Problem No. 730

```
What will this code print out?

def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f()
How can we make it print out what we apparently want?
```
[Solution](data/dailyCodingProblem730.py)

---


#### Problem No. 731

```
Given a array of numbers representing the stock prices of a
company in chronological order, write a function that
calculates the maximum profit you could have made from
buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5,
since you could buy the stock at 5 dollars and sell it at 10 dollars.
```
[Solution](data/dailyCodingProblem731.cpp)

---


#### Problem No. 732

```
An imminent hurricane threatens the coastal town of Codeville.
If at most two people can fit in a rescue boat,
and the maximum weight limit for a given boat is k,
determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80]
and a boat limit of 200, the smallest number of boats required will be three.
```
[Solution](data/dailyCodingProblem732.cpp)

---


#### Problem No. 733

```
Connect 4 is a game where opponents take turns dropping
red or black discs into a 7 x 6 vertically suspended grid.
The game ends either when one player creates a line of four
consecutive discs of their color (horizontally, vertically,
or diagonally), or when there are no more spots left in the grid.

Design and implement Connect 4.
```
[Solution](data/dailyCodingProblem733.cpp)

---


#### Problem No. 734

```
Write a map implementation with a get
function that lets you retrieve
the value of a key at a particular time.

It should contain the following methods:

set(key, value, time): sets key to value for t = time.
get(key, time): gets the key at t = time.
T
he map should work like this. If we set a key at a particular time,
it will maintain that value forever or until it gets set at a later
time. In other words, when we get a key at a time, it should return
the value that was set for that key set at the most recent time.

Consider the following examples:

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2
d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2
```
[Solution](data/dailyCodingProblem734.cpp)

---


#### Problem No. 735

```
Given an unsorted array, in which all elements are distinct,
find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both
its left and right neighbors. It is guaranteed that the
first and last elements are lower than all others.
```
[Solution](data/dailyCodingProblem735.cpp)

---


#### Problem No. 736

```
Given a complete binary tree, count the number of nodes in
faster than O(n) time. Recall that a complete binary tree
has every level filled except the last, and the nodes in
the last level are filled starting from the left.
```
[Solution](data/dailyCodingProblem736.cpp)

---


#### Problem No. 737

```
We're given a hashmap associating each courseId key with a
list of courseIds values, which represents that the prerequisites
of courseId are courseIds. Return a sorted ordering of courses
such that we can finish all courses.

Return null if there is no such ordering.

For example, given
{'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []},
should return ['CSC100', 'CSC200', 'CSCS300'].
```
[Solution](data/dailyCodingProblem737.cpp)

---


#### Problem No. 738

```
Given a string s and an integer k, break up the string into multiple texts
such that each text has a length of k or less. You must break it up so that
words don't break across lines. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that
there is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog"
and k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"].
No string in the list has a length of more than 10.
```
[Solution](data/dailyCodingProblem738.cpp)

---


#### Problem No. 739

```
A quack is a data structure combining properties of both stacks and queues.
It can be viewed as a list of elements written left to right such that three operations are possible:

push(x): add a new item x to the left end of the list
pop(): remove and return the item on the left end of the list
pull(): remove the item on the right end of the list.

Implement a quack using three stacks and O(1) additional memory,
so that the amortized time for any push, pop, or pull operation is O(1).
```
[Solution](data/dailyCodingProblem739.cpp)

---


#### Problem No. 740

```
A regular number in mathematics is defined as one which evenly divides some power of 60.
Equivalently, we can say that a regular number is one whose only prime divisors are 2, 3, and 5.

These numbers have had many applications, from helping ancient
Babylonians keep time to tuning instruments according to the diatonic scale.

Given an integer N, write a program that returns, in order, the first N regular numbers.
```
[Solution](data/dailyCodingProblem740.cpp)

---


#### Problem No. 742

```
Write a function to flatten a nested dictionary.
Namespace the keys with a period.

For example, given the following dictionary:

{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}
it should become:

{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}

You can assume keys do not contain dots in them,
i.e. no clobbering will occur.
```
[Solution](data/dailyCodingProblem742.cpp)

---


#### Problem No. 743

```
A bridge in a connected (undirected) graph is an edge that, if removed,
causes the graph to become disconnected. Find all the bridges in a graph.
```
[Solution](data/dailyCodingProblem743.cpp)

---


#### Problem No. 744

```
Implement an LFU (Least Frequently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

set(key, value): sets key to value. If there are already
n items in the cache and we are adding a new item,
then it should also remove the least frequently used item.
If there is a tie, then the least recently used key should be removed.

get(key): gets the value at key.
If no such key exists, return null.

Each operation should run in O(1) time.
```
[Solution](data/dailyCodingProblem744.cpp)

---


#### Problem No. 745

```
Implement a data structure which carries out the
following operations without resizing the underlying
array:

add(value): Add a value to the set of values.
check(value): Check whether a value is in the set.

The check method may return occasional false positives
(in other words, incorrectly identifying an element as
part of the set), but should always correctly identify
a true element.
```
[Solution](data/dailyCodingProblem745.cpp)

---


#### Problem No. 746

```
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack

pop(), which pops off and returns the topmost element of the stack.
If there are no elements in the stack, then it should throw an error or return null.

max(), which returns the maximum value in the stack currently.
If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.
```
[Solution](data/dailyCodingProblem746.cpp)

---


#### Problem No. 747

```
Given two strings A and B, return whether or not A
can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true.
If A is abc and B is acb, return false.
```
[Solution](data/dailyCodingProblem747.cpp)

---


#### Problem No. 748

```
Given the root of a binary tree, find the most frequent subtree sum.
The subtree sum of a node is the sum of all values under a node,
including the node itself.

For example, given the following tree:

  5
 / \
2  -5

Return 2 as it occurs twice: once as the left leaf,
and once as the sum of 2 + 5 - 5.
```
[Solution](data/dailyCodingProblem748.cpp)

---


#### Problem No. 749

```
Given a string, find the longest palindromic contiguous substring.
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb".
The longest palindromic substring of "bananas" is "anana".
```
[Solution](data/dailyCodingProblem749.cpp)

---


#### Problem No. 750

```
Generate a finite, but an arbitrarily large binary tree quickly in O(1).

That is, generate() should return a tree whose size is unbounded but finite.
```
[Solution](data/dailyCodingProblem750.cpp)

---


#### Problem No. 751

```
Typically, an implementation of in-order traversal of a binary
tree has O(h) space complexity, where h is the height of the tree.
Write a program to compute the in-order traversal of a binary
tree using O(1) space.
```
[Solution](data/dailyCodingProblem751.cpp)

---


#### Problem No. 752

```
Print the nodes in a binary tree level-wise.
For example, the following should print 1, 2, 3, 4, 5.

  1
 / \
2   3
   / \
  4   5
```
[Solution](data/dailyCodingProblem752.cpp)

---


#### Problem No. 753

```
A ternary search tree is a trie-like data structure where each node
may have up to three children. Here is an example which represents
the words code, cob, be, ax, war, and we.

       c
    /  |  \
   b   o   w
 / |   |   |
a  e   d   a
|    / |   | \ 
x   b  e   r  e  

The tree is structured according to the following rules:

left child nodes link to words lexicographically earlier than the parent prefix
right child nodes link to words lexicographically later than the parent prefix
middle child nodes continue the current word

For instance, since code is the first word inserted in the tree,
and cob lexicographically precedes cod, cob is represented as a
left child extending from cod.

Implement insertion and search functions for a ternary search tree.
```
[Solution](data/dailyCodingProblem753.cpp)

---


#### Problem No. 754

```
In front of you is a row of N coins, with values v1, v1, ..., vn.

You are asked to play the following game. You and an opponent take
turns choosing either the first or last coin from the row, removing
it from the row, and receiving the value of the coin.

Write a program that returns the maximum amount of money you can
win with certainty, if you move first, assuming your opponent plays optimally.
```
[Solution](data/dailyCodingProblem754.cpp)

---


#### Problem No. 755

```
In a directed graph, each node is assigned an uppercase letter.
We define a path's value as the number of most frequently-occurring
letter along that path. For example, if a path in the graph goes
through "ABACA", the value of the path is 3, since there are 3
occurrences of 'A' on the path.

Given a graph with n nodes and m directed edges, return the
largest value path of the graph. If the largest value is infinite,
then return null.

The graph is represented with a string and an edge list.
The i-th character represents the uppercase letter of
the i-th node. Each tuple in the edge list (i, j) means
there is a directed edge from the i-th node to the j-th node.
Self-edges are possible, as well as multi-edges.

For example, the following input graph:

ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]

Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).

The following input graph:

A
[(0, 0)]

Should return null, since we have an infinite loop.
```
[Solution](data/dailyCodingProblem755.cpp)

---


#### Problem No. 756

```
You are given a string formed by concatenating several words
corresponding to the integers zero through nine and then anagramming.

For example, the input could be 'niesevehrtfeev',
which is an anagram of 'threefiveseven'.
Note that there can be multiple instances of each integer.

Given this string, return the original integers
in sorted order. In the example above, this would be 357.
```
[Solution](data/dailyCodingProblem756.cpp)

---


#### Problem No. 758

```
Write a function that rotates a list by k elements.
For example, [1, 2, 3, 4, 5, 6] rotated by two becomes
[3, 4, 5, 6, 1, 2]. Try solving this without creating a copy of the list.
```
[Solution](data/dailyCodingProblem758.cpp)

---


#### Problem No. 759

```
Given a string of digits, generate all possible valid IP address combinations.

IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers
between 0 and 255. Zero-prefixed numbers, such as 01 and 065, are not allowed,
except for 0 itself.

For example, given "2542540123",
you should return ['254.25.40.123', '254.254.0.123'].
```
[Solution](data/dailyCodingProblem759.cpp)

---


#### Problem No. 760

```
Given a linked list, uniformly shuffle the nodes.
What if we want to prioritize space over time?
```
[Solution](data/dailyCodingProblem760.cpp)

---


#### Problem No. 761

```
Using a function rand7() that returns an integer from 1 to 7 (inclusive)
with uniform probability, implement a function rand5() that returns an
integer from 1 to 5 (inclusive).
```
[Solution](data/dailyCodingProblem761.cpp)

---


#### Problem No. 762

```
Find an efficient algorithm to find the smallest distance
(measured in number of words) between any two given words in a string.

For example, given words "hello", and "world" and a text
content of "dog cat hello cat dog dog hello cat world",
return 1 because there's only one word "cat" in between the two words.
```
[Solution](data/dailyCodingProblem762.cpp)

---


#### Problem No. 763

```
Given an array of integers and a number k,
where 1 <= k <= length of the array,
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3,
we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array
in-place and you do not need to store the results.

You can simply print them out as you compute them.
```
[Solution](data/dailyCodingProblem763.cpp)

---


#### Problem No. 764

```
Given a list of numbers, create an algorithm that arranges them in order
to form the largest possible integer. For example, given [10, 7, 76, 415],
you should return 77641510.
```
[Solution](data/dailyCodingProblem764.cpp)

---


#### Problem No. 765

```
Given a singly linked list and an integer k,
remove the kth last element from the list.
k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than
one pass is prohibitively expensive.

Do this in constant space and in one pass.
```
[Solution](data/dailyCodingProblem765.cpp)

---


#### Problem No. 766

```
You are given a string consisting of the letters x and y,
such as xyxxxyxyy. In addition, you have an operation called flip,
which changes a single x to y or vice versa.

Determine how many times you would need to apply this operation
to ensure that all x's come before all y's. In the preceding example,
it suffices to flip the second and sixth characters, so you should return 2.
```
[Solution](data/dailyCodingProblem766.cpp)

---


#### Problem No. 767

```
Given a word W and a string S, find
all starting indices in S which are anagrams of W.

For example, given that W is "ab",
and S is "abxaba", return 0, 3, and 4.
```
[Solution](data/dailyCodingProblem767.cpp)

---


#### Problem No. 768

```
Given an array of numbers of length N,
find both the minimum and maximum using
less than 2 * (N - 2) comparisons.
```
[Solution](data/dailyCodingProblem768.cpp)

---


#### Problem No. 769

```
Alice wants to join her school's Probability Student Club.
Membership dues are computed via one of two simple probabilistic games.

The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six.
Your number of rolls is the amount you pay, in dollars.

The second game: same, except that the stopping condition is a five followed by a five.

Which of the two games should Alice elect to play? Does it even matter?
Write a program to simulate the two games and calculate their expected value.
```
[Solution](data/dailyCodingProblem769.cpp)

---


#### Problem No. 770

```
The game of Nim is played as follows.
Starting with three heaps, each containing a
variable number of items, two players take
turns removing one or more items from a single pile.
The player who eventually is forced to take the last
stone loses. For example, if the initial heap sizes
are 3, 4, and 5, a game could be played as shown below:

  A  |  B  |  C
-----------------
  3  |  4  |  5
  3  |  1  |  3
  3  |  1  |  3
  0  |  1  |  3
  0  |  1  |  0
  0  |  0  |  0

In other words, to start, the first player
takes three items from pile B. The second
player responds by removing two stones from
pile C. The game continues in this way until
player one takes last stone and loses.

Given a list of non-zero starting values
[a, b, c], and assuming optimal play,
determine whether the first player has a forced win.
```
[Solution](data/dailyCodingProblem770.cpp)

---


#### Problem No. 771

```
Determine whether there exists a one-to-one character
mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true
since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since
the o cannot map to two characters.
```
[Solution](data/dailyCodingProblem771.cpp)

---


#### Problem No. 772

```
Boggle is a game played on a 4 x 4 grid of letters.
The goal is to find as many words as possible that
can be formed by a sequence of adjacent letters in
the grid, using each cell at most once. Given a game
board and a dictionary of valid words, implement a Boggle solver.
```
[Solution](data/dailyCodingProblem772.cpp)

---


#### Problem No. 773

```
We can determine how "out of order" an array A is
by counting the number of inversions it has.
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j.
That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has.
Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions.
The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3).
The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
```
[Solution](data/dailyCodingProblem773.cpp)

---


#### Problem No. 774

```
Using a read7() method that returns 7 characters from a file,
implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”,
three read7() returns “Hello w”, “orld” and then “”.
```
[Solution](data/dailyCodingProblem774.cpp)

---


#### Problem No. 775

```
Given an array of time intervals (start, end) for classroom
lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
```
[Solution](data/dailyCodingProblem775.cpp)

---


#### Problem No. 776

```
There are N prisoners standing in a circle, waiting to be executed.
The executions are carried out starting with the kth person,
and removing every successive kth person going clockwise
until there is no one left.

Given N and k, write an algorithm to determine where a
prisoner should stand in order to be the last survivor.

For example, if N = 5 and k = 2, the order of executions
would be [2, 4, 1, 5, 3], so you should return 3.

Bonus: Find an O(log N) solution if k = 2.
```
[Solution](data/dailyCodingProblem776.cpp)

---


#### Problem No. 777

```
A ternary search tree is a trie-like data structure where each node
may have up to three children. Here is an example which represents
the words code, cob, be, ax, war, and we.

       c
    /  |  \
   b   o   w
 / |   |   |
a  e   d   a
|    / |   | \ 
x   b  e   r  e  

The tree is structured according to the following rules:

left child nodes link to words lexicographically earlier than the parent prefix
right child nodes link to words lexicographically later than the parent prefix
middle child nodes continue the current word

For instance, since code is the first word inserted in the tree,
and cob lexicographically precedes cod, cob is represented as a
left child extending from cod.

Implement insertion and search functions for a ternary search tree.
```
[Solution](data/dailyCodingProblem777.cpp)

---


#### Problem No. 778

```
You have access to ranked lists of songs for various users.
Each song is represented as an integer, and more preferred
songs appear earlier in each list. For example, the list
[4, 1, 7] indicates that a user likes song 4 the best,
followed by songs 1 and 7.

Given a set of these ranked lists, interleave them to
create a playlist that satisfies everyone's priorities.

For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}.
In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
```
[Solution](data/dailyCodingProblem778.cpp)

---


#### Problem No. 779

```
You are given N identical eggs and access to a building with k floors.
Your task is to find the lowest floor that will cause an egg to break,
if dropped from that floor. Once an egg breaks, it cannot be dropped again.
If an egg breaks when dropped from the xth floor, you can assume
it will also break when dropped from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops
it will take, in the worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping
the egg at every floor, beginning with the first, until we reach
the fifth floor, so our solution will be 5.
```
[Solution](data/dailyCodingProblem779.cpp)

---

#### Problem No. 780

```
We're given a hashmap associating each courseId key with a
list of courseIds values, which represents that the prerequisites
of courseId are courseIds. Return a sorted ordering of courses
such that we can finish all courses.

Return null if there is no such ordering.

For example, given
{'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []},
should return ['CSC100', 'CSC200', 'CSCS300'].
```
[Solution](data/dailyCodingProblem780.cpp)

---


#### Problem No. 781

```
You are given a histogram consisting of rectangles of different heights.
These heights are represented in an input list, such that [1, 3, 2, 5]
corresponds to the following diagram:

      x
      x
  x   x
  x x x
x x x x

Determine the area of the largest rectangle that can be formed only
from the bars of the histogram. For the diagram above, for example,
this would be six, representing the 2 x 3 area at the bottom right.
```
[Solution](data/dailyCodingProblem781.cpp)

---


#### Problem No. 782

```
In academia, the h-index is a metric used to calculate the impact of a researcher's papers.
It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each.
If there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each paper
are [4, 3, 0, 1, 5]. Then the h-index would be 3, since the researcher
has 3 papers with at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.
```
[Solution](data/dailyCodingProblem782.cpp)

---


#### Problem No. 783

```
Given an array of numbers, find the length of the longest increasing
subsequence in the array. The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15],
the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
```
[Solution](data/dailyCodingProblem783.cpp)

---


#### Problem No. 784

```
Given a 2D matrix of characters and a target word, write a function that returns whether
the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true, since it's the leftmost column.
Similarly, given the target word 'MASS', you should return true, since it's the last row.
```
[Solution](data/dailyCodingProblem784.cpp)

---


#### Problem No. 785

```
Given a list of integers, return the largest product
that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2],
we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.
```
[Solution](data/dailyCodingProblem785.cpp)

---


#### Problem No. 786

```
Implement integer exponentiation. That is,
implement the pow(x, y) function,
where x and y are integers and returns x^y.

Do this faster than the naive method
of repeated multiplication.

For example, pow(2, 10) should return 1024.
```
[Solution](data/dailyCodingProblem786.cpp)

---


#### Problem No. 787

```
Given an integer n, find the next biggest integer with the same number of 1-bits on.
For example, given the number 6 (0110 in binary), return 9 (1001).
```
[Solution](data/dailyCodingProblem787.cpp)

---


#### Problem No. 788

```
Write a program that checks whether an integer is a palindrome.
For example, 121 is a palindrome, as well as 888. 678 is not a
palindrome. Do not convert the integer into a string.
```
[Solution](data/dailyCodingProblem788.cpp)

---


#### Problem No. 789

```
Given a number represented by a list of digits, find the next greater permutation of a number,
in terms of lexicographic ordering. If there is not greater permutation possible,
return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3].
The list [3,2,1] should return [1,2,3].

Can you perform the operation without allocating extra memory (disregarding the input memory)?
```
[Solution](data/dailyCodingProblem789.cpp)

---


#### Problem No. 790

```
A step word is formed by taking a given word, adding a letter,
and anagramming the result. For example, starting with the
word "APPLE", you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word, create a
function that returns all valid step words.
```
[Solution](data/dailyCodingProblem790.cpp)

---


#### Problem No. 791

```
Write a function, throw_dice(N, faces, total),
that determines how many ways it is possible to
throw N dice with some number of faces each to get a specific total.

For example, throw_dice(3, 6, 7) should equal 15.
```
[Solution](data/dailyCodingProblem791.cpp)

---


#### Problem No. 792

```
You have N stones in a row, and would like to create from them a pyramid.
This pyramid should be constructed such that the height of each stone
increases by one until reaching the tallest stone, after which the
heights decrease by one. In addition, the start and end stones of
the pyramid should each be one stone high.

You can change the height of any stone by paying a cost of 1 unit
to lower its height by 1, as many times as necessary. Given this
information, determine the lowest cost method to produce this pyramid.

For example, given the stones [1, 1, 3, 3, 2, 1], the optimal
solution is to pay 2 to create [0, 1, 2, 3, 2, 1].
```
[Solution](data/dailyCodingProblem792.cpp)

---


#### Problem No. 793

```
Recall that a full binary tree is one in which each node
is either a leaf node, or has two children. Given a binary tree,
convert it to a full one by removing nodes with only one child.

For example, given the following tree:

         0
      /     \
    1         2
  /            \
3                 4
  \             /   \
    5          6     7
You should convert it to:

     0
  /     \
5         4
        /   \
       6     7
```
[Solution](data/dailyCodingProblem793.cpp)

---


#### Problem No. 794

```
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack.
If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently.
If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.
```
[Solution](data/dailyCodingProblem794.cpp)

---


#### Problem No. 795

```
Assume you have access to a function toss_biased() which
returns 0 or 1 with a probability that's not 50-50
(but also not 0-100 or 100-0). You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.
```
[Solution](data/dailyCodingProblem795.cpp)

---


#### Problem No. 797

```
Given an even number (greater than 2), return
two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible,
return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
```
[Solution](data/dailyCodingProblem797.cpp)

---


#### Problem No. 798

```
You are given a set of synonyms, such as (big, large) and (eat, consume).
Using this set, determine if two sentences with the same number of words are equivalent.

For example, the following two sentences are equivalent:

"He wants to eat food."
"He wants to consume food."
Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c):
consider the case of (coach, bus) and (coach, teacher).

Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?
```
[Solution](data/dailyCodingProblem798.cpp)

---


#### Problem No. 799

```
Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map.
If the key already exists, overwrite the value.

sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.
For example, you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
```
[Solution](data/dailyCodingProblem799.cpp)

---


#### Problem No. 800

```
Given a linked list, rearrange the node values such
that they appear in alternating low -> high -> low -> high ... form.
For example, given 1 -> 2 -> 3 -> 4 -> 5,
you should return 1 -> 3 -> 2 -> 5 -> 4.
```
[Solution](data/dailyCodingProblem800.cpp)

---


#### Problem No. 801

```
Let's define a "sevenish" number to be one which is either a power of 7,
or the sum of unique powers of 7. The first few sevenish numbers are 1, 7, 8, 49, and so on.
Create an algorithm to find the nth sevenish number.
```
[Solution](data/dailyCodingProblem801.cpp)

---


#### Problem No. 802

```
You are given n numbers as well as n probabilities that sum up to 1.
Write a function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities
[0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the time,
2 50% of the time, and 3 and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
```
[Solution](data/dailyCodingProblem802.cpp)

---


#### Problem No. 803

```
Mastermind is a two-player game in which the first player attempts
to guess the secret code of the second. In this version, the code
may be any six-digit number with all distinct digits.

Each turn the first player guesses some number, and the second player
responds by saying how many digits in this number correctly matched
their location in the secret code. For example, if the secret code
were 123456, then a guess of 175286 would score two, since 1 and 6 were correctly placed.

Write an algorithm which, given a sequence of guesses and their scores,
determines whether there exists some secret code that could have produced them.

For example, for the following scores you should return True,
since they correspond to the secret code 123456:

{175286: 2, 293416: 3, 654321: 0}

However, it is impossible for any key to result in the following scores,
so in this case you should return False:

{123456: 4, 345678: 4, 567890: 4}
```
[Solution](data/dailyCodingProblem803.cpp)

---


#### Problem No. 804

```
You are given a huge list of airline ticket prices between different cities
around the world on a given day. These are all direct flights.
Each element in the list has the format (source_city, destination, price).

Consider a user who is willing to take up to k connections from
their origin city A to their destination B. Find the cheapest fare
possible for this journey and print the itinerary for that journey.

For example, our traveler wants to go
from JFK to LAX with up to 3 connections,
and our input flights are as follows:

[
    ('JFK', 'ATL', 150),
    ('ATL', 'SFO', 400),
    ('ORD', 'LAX', 200),
    ('LAX', 'DFW', 80),
    ('JFK', 'HKG', 800),
    ('ATL', 'ORD', 90),
    ('JFK', 'LAX', 500),
]

Due to some improbably low flight prices, the cheapest itinerary
would be JFK -> ATL -> ORD -> LAX, costing $440.
```
[Solution](data/dailyCodingProblem804.cpp)

---


#### Problem No. 805

```
Spreadsheets often use this alphabetical encoding for its columns:
"A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id.
For example, given 1, return "A". Given 27, return "AA".
```
[Solution](data/dailyCodingProblem805.cpp)

---


#### Problem No. 806

```
Let A be an N by M matrix in which every row and every column is sorted.

Given i1, j1, i2, and j2, compute the number of
elements of M smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
[2, 6, 9, 14, 22, 25],
[3, 8, 10, 15, 25, 30],
[10, 11, 12, 23, 30, 35],
[20, 25, 30, 35, 40, 45]]

And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as
there are 15 numbers in the matrix smaller than 6 or greater than 23.
```
[Solution](data/dailyCodingProblem806.cpp)

---


#### Problem No. 807

```
Given an integer k and a string s, find the length
of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest
substring with k distinct characters is "bcb".
```
[Solution](data/dailyCodingProblem807.cpp)

---


#### Problem No. 808

```
Typically, an implementation of in-order traversal
of a binary tree has O(h) space complexity, where h
is the height of the tree. Write a program to compute
the in-order traversal of a binary tree using O(1) space.
```
[Solution](data/dailyCodingProblem808.cpp)

---


#### Problem No. 809

```
Given a string of round, curly, and square open and
closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
```
[Solution](data/dailyCodingProblem809.cpp)

---


#### Problem No. 810

```
In Ancient Greece, it was common to write text with
the first line going left to right, the second line
going right to left, and continuing to go back and forth.
This style was called "boustrophedon".

Given a binary tree, write an algorithm to print
the nodes in boustrophedon order.

For example, given the following tree:

       1
    /     \
  2         3
 / \       / \
4   5     6   7

You should return [1, 3, 2, 4, 5, 6, 7].
```
[Solution](data/dailyCodingProblem810.cpp)

---


#### Problem No. 811

```
Given a list of words, return the shortest unique prefix of each word.
For example, given the list:

dog
cat
apple
apricot
fish

Return the list:

d
c
app
apr
f
```
[Solution](data/dailyCodingProblem811.cpp)

---


#### Problem No. 812

```
In chess, the Elo rating system is used to calculate player strengths based on game results.

A simplified description of the Elo system is as follows.
Every player begins at the same score. For each subsequent game,
the loser transfers some points to the winner, where the amount
of points transferred depends on how unlikely the win is.
For example, a 1200-ranked player should gain much more points
for beating a 2000-ranked player than for beating a 1300-ranked player.

Implement this system.
```
[Solution](data/dailyCodingProblem812.cpp)

---


#### Problem No. 813

```
Given an array of integers, write a function to determine whether the array could
become non-decreasing by modifying at most 1 element.
For example, given the array [10, 5, 7], you should return true, since we can modify
the 10 into a 1 to make the array non-decreasing.
Given the array [10, 5, 1], you should return false, since we can't modify any one
element to get a non-decreasing array.
```
[Solution](data/dailyCodingProblem813.cpp)

---


#### Problem No. 814

```
Let's represent an integer in a linked list format by having
each node represent a digit in the number. The nodes make up
the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5
is the number 54321.

Given two linked lists in this format, return their sum in
the same linked list format.

For example, given

9 -> 9
5 -> 2
return 124 (99 + 25) as:

4 -> 2 -> 1
```
[Solution](data/dailyCodingProblem814.cpp)

---


#### Problem No. 815

```
The area of a circle is defined as πr^2.
Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
```
[Solution](data/dailyCodingProblem815.cpp)

---


#### Problem No. 816

```
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0,
using only mathematical or bit operations. You can assume b can only be 1 or 0.
```
[Solution](data/dailyCodingProblem816.cpp)

---


#### Problem No. 817

```
Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list. If there is more than one possible
reconstruction, return any of them. If there is no possible reconstruction,
then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox',
and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond',
and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond]
or ['bedbath', 'and', 'beyond'].
```
[Solution](data/dailyCodingProblem817.cpp)

---


#### Problem No. 818

```
The Sieve of Eratosthenes is an algorithm used to generate
all prime numbers smaller than N. The method is to take
increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would
first mark [4, 6, 8, ...] (multiples of two), then [6, 9, 12, ...]
(multiples of three), and so on. Once we have done this for all
primes less than N, the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely
(that is, without taking N as an input).
```
[Solution](data/dailyCodingProblem818.cpp)

---


#### Problem No. 819

```
Given a array of numbers representing the stock prices of a company
in chronological order, write a function that calculates the maximum
profit you could have made from buying and selling that stock once.
You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5,
since you could buy the stock at 5 dollars and sell it at 10 dollars.
```
[Solution](data/dailyCodingProblem819.cpp)

---


#### Problem No. 820

```
Given an array of integers, find the first missing positive integer
in linear time and constant space. In other words,
find the lowest positive integer that does not exist in the array.
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2.
The input [1, 2, 0] should give 3.

You can modify the input array in-place.
```
[Solution](data/dailyCodingProblem820.cpp)

---


#### Problem No. 821

```
A fixed point in an array is an element whose value is equal to its index.
Given a sorted array of distinct elements, return a fixed point, if one exists.
Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2. Given [1, 5, 7, 8],
you should return False.
```
[Solution](data/dailyCodingProblem821.cpp)

---


#### Problem No. 822

```
Given a list of possibly overlapping intervals,
return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)],
you should return [(1, 3), (4, 10), (20, 25)].
```
[Solution](data/dailyCodingProblem822.cpp)

---


#### Problem No. 823

```
Implement a bit array.

A bit array is a space efficient array that holds a value of 1 or 0 at each index.

init(size): initialize the array with size
set(i, val): updates index at i with val where val is either 1 or 0.
get(i): gets the value at index i.
```
[Solution](data/dailyCodingProblem823.cpp)

---


#### Problem No. 824

```
Write a program to merge two binary trees. Each node in
the new tree should hold a value equal to the sum of the
values of the corresponding nodes of the input trees.

If only one input tree has a node in a given position,
the corresponding node in the new tree should match that input node.
```
[Solution](data/dailyCodingProblem824.cpp)

---


#### Problem No. 825

```
Given a sorted list of integers, square the
elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3],
return [0, 4, 4, 9, 81].
```
[Solution](data/dailyCodingProblem825.cpp)

---


#### Problem No. 827

```
You are the technical director of WSPT radio,
serving listeners nationwide. For simplicity's
sake we can consider each listener to live along
a horizontal line stretching from 0 (west) to 1000 (east).

Given a list of N listeners, and a list of M radio towers,
each placed at various locations along this line, determine
what the minimum broadcast range would have to be in order
for each listener's home to be covered.

For example, suppose listeners = [1, 5, 11, 20], and
towers = [4, 8, 15]. In this case the minimum range would be 5,
since that would be required for the tower at position 15 to
reach the listener at position 20.
```
[Solution](data/dailyCodingProblem827.cpp)

---


#### Problem No. 828

```
Write a program to determine how many distinct ways there are to create a
max heap from a list of N given integers.

For example, if N = 3, and our integers are [1, 2, 3], there are two ways, shown below.

  3      3
 / \    / \
1   2  2   1
```
[Solution](data/dailyCodingProblem828.cpp)

---


#### Problem No. 829

```
Create a data structure that performs all the following operations in O(1) time:

plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.
```
[Solution](data/dailyCodingProblem829.cpp)

---


#### Problem No. 830

```
Given a list of numbers, create an algorithm that arranges
them in order to form the largest possible integer.
For example, given [10, 7, 76, 415], you should return 77641510.
```
[Solution](data/dailyCodingProblem830.cpp)

---


#### Problem No. 831

```
Given a string s and a list of words words, where each word
is the same length, find all starting indices of substrings
in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"],
return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"],
return [] since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
```
[Solution](data/dailyCodingProblem831.cpp)

---


#### Problem No. 832

```
Given an array of elements, return the length of the
longest subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1],
return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
```
[Solution](data/dailyCodingProblem832.cpp)

---


#### Problem No. 833

```
At a party, there is a single person who everyone knows,
but who does not know anyone in return (the "celebrity").
To help figure out who this is, you have access to an O(1)
method called knows(a, b), which returns True if person a
knows person b, else False.

Given a list of N people and the above operation,
find a way to identify the celebrity in O(N) time.
```
[Solution](data/dailyCodingProblem833.cpp)

---


#### Problem No. 834

```
There are N couples sitting in a row of length 2 * N.
They are currently ordered randomly, but would like to
rearrange themselves so that each couple's partners
can sit side by side.

What is the minimum number of swaps necessary
for this to happen?
```
[Solution](data/dailyCodingProblem834.cpp)

---


#### Problem No. 835

```
Given a string and a set of characters, return the shortest substring containing all the characters in the set.
For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
If there is no substring containing all the characters in the set, return null.
```
[Solution](data/dailyCodingProblem835.cpp)

---


#### Problem No. 836

```
Given a function that generates perfectly random numbers between
1 and k (inclusive), where k is an input, write a function that
shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations
of the deck is equally likely.
```
[Solution](data/dailyCodingProblem836.cpp)

---


#### Problem No. 837

```
Create a basic sentence checker that takes in a stream of characters
and determines whether they form valid sentences. If a sentence is valid, the program should print it out.

We can consider a sentence valid if it conforms to the following rules:

The sentence must start with a capital letter, followed by a lowercase letter or a space.
All other characters must be lowercase letters, separators (,,;,:) or terminal marks (.,?,!,‽).
There must be a single space between each word.
The sentence must end with a terminal mark immediately following a word.
```
[Solution](data/dailyCodingProblem837.cpp)

---


#### Problem No. 838

```
You are given a 2-d matrix where each cell represents number of coins in that cell.
Assuming we start at matrix[0][0], and can only move right or down, find the maximum
number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1

The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
```
[Solution](data/dailyCodingProblem838.cpp)

---


#### Problem No. 840

```
Given a string and a number of lines k, print the string in zigzag form.
In zigzag, characters are printed out diagonally from top left to bottom right
until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
```
[Solution](data/dailyCodingProblem840.cpp)

---


#### Problem No. 841

```
Given integers M and N, write a program that counts
how many positive integer pairs (a, b)
satisfy the following conditions:

a + b = M
a XOR b = N
```
[Solution](data/dailyCodingProblem841.cpp)

---


#### Problem No. 842

```
Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d
```
[Solution](data/dailyCodingProblem842.cpp)

---


#### Problem No. 843

```
Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string.
For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].
```
[Solution](data/dailyCodingProblem843.cpp)

---


#### Problem No. 844

```
A Boolean formula can be said to be satisfiable if there is a way to assign
truth values to each variable such that the entire formula evaluates to true.

For example, suppose we have the following formula,
where the symbol ¬ is used to denote negation:

(¬c OR b) AND (b OR c) AND (¬b OR c) AND (¬c OR ¬a)

One way to satisfy this formula would be to
let a = False, b = True, and c = True.

This type of formula, with AND statements
joining tuples containing exactly one OR,
is known as 2-CNF.

Given a 2-CNF formula, find a way to assign
truth values to satisfy it, or return False
if this is impossible.
```
[Solution](data/dailyCodingProblem844.cpp)

---


#### Problem No. 845

```
Write a function that rotates a list by k elements.
For example, [1, 2, 3, 4, 5, 6] rotated by two becomes
[3, 4, 5, 6, 1, 2]. Try solving this without creating a copy of the list.
```
[Solution](data/dailyCodingProblem845.cpp)

---


#### Problem No. 846

```
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
```
[Solution](data/dailyCodingProblem846.py)

---


#### Problem No. 847

```
Given an integer list where each number represents the number of hops you can make,
determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.
```
[Solution](data/dailyCodingProblem847.cpp)

---


#### Problem No. 848

```
Implement an LRU (Least Recently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

set(key, value): sets key to value. If there are already n items
in the cache and we are adding a new item, then it should also
remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
```
[Solution](data/dailyCodingProblem848.cpp)

---


#### Problem No. 849

```
A Collatz sequence in mathematics can be defined as follows. Starting with any positive integer:

if n is even, the next number in the sequence is n / 2
if n is odd, the next number in the sequence is 3n + 1
It is conjectured that every such sequence eventually reaches the number 1. Test this conjecture.

Bonus: What input n <= 1000000 gives the longest sequence?
```
[Solution](data/dailyCodingProblem849.cpp)

---


#### Problem No. 850

```
Given a set of characters C and an integer k, a De Bruijn sequence is a cyclic
sequence in which every possible k-length string of characters in C occurs exactly once.

For example, suppose C = {0, 1} and k = 3. Then our sequence should contain
the substrings {'000', '001', '010', '011', '100', '101', '110', '111'},
and one possible solution would be 00010111.

Create an algorithm that finds a De Bruijn sequence.
```
[Solution](data/dailyCodingProblem850.cpp)

---


#### Problem No. 851

```
A graph is minimally-connected if it is connected and there is no edge that can be removed while
still leaving the graph connected. For example, any binary tree is minimally-connected.

Given an undirected graph, check if the graph is minimally-connected.
You can choose to represent the graph as either an adjacency matrix or adjacency list.
```
[Solution](data/dailyCodingProblem851.cpp)

---


#### Problem No. 852

```
Given a circular array, compute its maximum subarray sum in O(n) time.
A subarray can be empty, and in this case the sum is 0.
For example, given [8, -1, 3, 4], return 15 as we choose
the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
```
[Solution](data/dailyCodingProblem852.cpp)

---


#### Problem No. 853

```
Find an efficient algorithm to find the smallest distance
(measured in number of words) between any two given words in a string.

For example, given words "hello", and "world" and a text content of
"dog cat hello cat dog dog hello cat world", return 1 because there's
only one word "cat" in between the two words.
```
[Solution](data/dailyCodingProblem853.cpp)

---


#### Problem No. 854

```
Given a string s and an integer k, break up the string into multiple texts
such that each text has a length of k or less. You must break it up so that
words don't break across lines. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that
there is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog"
and k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"].
No string in the list has a length of more than 10.
```
[Solution](data/dailyCodingProblem854.cpp)

---


#### Problem No. 855

```
You have an N by N board. Write a function that, given N,
returns the number of possible arrangements of the board where
N queens can be placed on the board without threatening each other,
i.e. no two queens share the same row, column, or diagonal.
```
[Solution](data/dailyCodingProblem855.cpp)

---


#### Problem No. 856

```
You are given a list of (website, user) pairs that represent users visiting websites.
Come up with a program that identifies the top k pairs of websites with the greatest similarity.

For example, suppose k = 1, and the list of tuples is:

[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5)
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e': 5), ('e', 6)]

Then a reasonable similarity metric would most likely conclude that a and e are
the most similar, so your program should return [('a', 'e')].
```
[Solution](data/dailyCodingProblem856.cpp)

---


#### Problem No. 857

```
You are given a binary tree in a peculiar string representation.
Each node is written in the form (lr), where l corresponds to the
left child and r corresponds to the right child.

If either l or r is null, it will be represented as a zero.
Otherwise, it will be represented by a new (lr) pair.

Here are a few examples:

A root node with no children: (00)
A root node with two children: ((00)(00))
An unbalanced tree with three consecutive left children: ((((00)0)0)0)

Given this representation, determine the depth of the tree.
```
[Solution](data/dailyCodingProblem857.cpp)

---


#### Problem No. 858

```
Compute the running median of a sequence of numbers.
That is, given a stream of numbers, print out the median
of the list so far on each new element.

Recall that the median of an even-numbered list is the
average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5],
your algorithm should print out:

2
1.5
2
3.5
2
2
2
```
[Solution](data/dailyCodingProblem858.cpp)

---


#### Problem No. 859

```
The horizontal distance of a binary tree node describes
how far left or right the node will be when the tree is printed out.

More rigorously, we can define it as follows:

The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.
For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8

The bottom view of a tree, then, consists of the lowest node
at each horizontal distance. If there are two nodes at the
same depth and horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
```
[Solution](data/dailyCodingProblem859.cpp)

---


#### Problem No. 860

```
Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression
and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray",
your function should return true. The same regular expression on the
string "raymond" should return false.

Given the regular expression ".*at" and the string "chat",
your function should return true. The same regular expression
on the string "chats" should return false.
```
[Solution](data/dailyCodingProblem860.cpp)

---


#### Problem No. 861

```
A knight is placed on a given square on an 8 x 8 chessboard.
It is then moved randomly several times, where each move is a
standard knight move. If the knight jumps off the board at any
point, however, it is not allowed to jump back on.

After k moves, what is the probability that the knight remains on the board?
```
[Solution](data/dailyCodingProblem861.cpp)

---


#### Problem No. 862

```
A bridge in a connected (undirected) graph is an edge that,
if removed, causes the graph to become disconnected.
Find all the bridges in a graph.
```
[Solution](data/dailyCodingProblem862.cpp)

---


#### Problem No. 863

```
Generate a finite, but an arbitrarily large binary tree quickly in O(1).

That is, generate() should return a tree whose size is unbounded but finite.
```
[Solution](data/dailyCodingProblem863.cpp)

---


#### Problem No. 864

```
An imminent hurricane threatens the coastal town of Codeville.
If at most two people can fit in a rescue boat, and the maximum
weight limit for a given boat is k, determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80]
and a boat limit of 200, the smallest number of boats required will be three.
```
[Solution](data/dailyCodingProblem864.cpp)

---


#### Problem No. 865

```
A group of houses is connected to the main water plant by means of a set of pipes.
A house can either be connected by a set of pipes extending directly to the plant,
or indirectly by a pipe to a nearby house which is otherwise connected.

For example, here is a possible configuration, where A, B, and C are houses, and arrows represent pipes:

A <--> B <--> C <--> plant
Each pipe has an associated cost, which the utility company would like to minimize.
Given an undirected graph of pipe connections, return the lowest
cost configuration of pipes such that each house has access to water.

In the following setup, for example, we can remove all but the pipes from plant to A,
plant to B, and B to C, for a total cost of 16.

pipes = {
    'plant': {'A': 1, 'B': 5, 'C': 20},
    'A': {'C': 15},
    'B': {'C': 10},
    'C': {}
}
```
[Solution](data/dailyCodingProblem865.cpp)

---


#### Problem No. 866

```
Given an array of numbers representing the stock prices of a company
in chronological order and an integer k, return the maximum profit
you can make from k buys and sells. You must buy the stock before
you can sell it, and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
```
[Solution](data/dailyCodingProblem866.cpp)

---


#### Problem No. 867

```
You are given an array of arrays of integers, where each array
corresponds to a row in a triangle of numbers. For example,
[[1], [2, 3], [1, 5, 1]] represents the triangle:

  1
 2 3
1 5 1

We define a path in the triangle to start at the top and go down
one row at a time to an adjacent value, eventually ending with
an entry on the bottom row. For example, 1 -> 3 -> 5. The weight
of the path is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
```
[Solution](data/dailyCodingProblem867.cpp)

---


#### Problem No. 868

```
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to
form racecar, which is a palindrome. daily should return false, since
there's no rearrangement that can form a palindrome.
```
[Solution](data/dailyCodingProblem868.cpp)

---


#### Problem No. 869

```
Determine whether a doubly linked list is a palindrome.
What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns True
while 1 -> 4 returns False.
```
[Solution](data/dailyCodingProblem869.cpp)

---


#### Problem No. 870

```
Given an N by M matrix consisting only of 1's and 0's,
find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
Return 4.
```
[Solution](data/dailyCodingProblem870.cpp)

---


#### Problem No. 872

```
Create an algorithm to efficiently compute
the approximate median of a list of numbers.

More precisely, given an unordered list of N numbers,
find an element whose rank is between N / 4 and 3 * N / 4,
with a high level of certainty, in less than O(N) time.
```
[Solution](data/dailyCodingProblem872.cpp)

---


#### Problem No. 873

```
Given an arithmetic expression in Reverse Polish Notation,
write a program to evaluate it.

The expression is given as a list of numbers and operands.
For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-']
should return 5, since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

You can assume the given expression is always valid.
```
[Solution](data/dailyCodingProblem873.cpp)

---


#### Problem No. 874

```
Given a string, find the longest palindromic contiguous substring.
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb".
The longest palindromic substring of "bananas" is "anana".
```
[Solution](data/dailyCodingProblem874.cpp)

---


#### Problem No. 875

```
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a
sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2.
subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1.
subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute
path to a file within our file system. For example, in the second example above,
the longest absolute path is "dir/subdir2/subsubdir2/file2.ext",
and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format,
return the length of the longest absolute path to a file in the
abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
```
[Solution](data/dailyCodingProblem875.cpp)

---


#### Problem No. 876

```
You are given a list of N numbers, in which each number is located
at most k places away from its sorted position. For example, if k = 1,
a given element at index 4 might end up at indices 3, 4, or 5.

Come up with an algorithm that sorts this list in O(N log k) time.
```
[Solution](data/dailyCodingProblem876.cpp)

---


#### Problem No. 877

```
Given two non-empty binary trees s and t,
check whether tree t has exactly the same
structure and node values with a subtree of s.
A subtree of s is a tree consists of a node in
s and all of this node's descendants. The tree
s could also be considered as a subtree of itself.
```
[Solution](data/dailyCodingProblem877.cpp)

---


#### Problem No. 878

```
Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.
```
[Solution](data/dailyCodingProblem878.cpp)

---


#### Problem No. 879

```
Given a list of numbers and a number k, return whether
any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17,
return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
```
[Solution](data/dailyCodingProblem879.cpp)

---


#### Problem No. 880

```
Given a string, split it into as few strings as possible
such that each string is a palindrome.

For example, given the input string racecarannakayak,
return ["racecar", "anna", "kayak"].

Given the input string abc, return ["a", "b", "c"].
```
[Solution](data/dailyCodingProblem880.cpp)

---


#### Problem No. 881

```
Implement a 2D iterator class. It will be initialized with an array of arrays,
and should implement the following methods:

next(): returns the next element in the array of arrays. If there are no more elements,
raise an exception.
has_next(): returns whether or not the iterator still has elements left.
For example, given the input [[1, 2], [3], [], [4, 5, 6]],
calling next() repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays.
Some of the arrays can be empty.
```
[Solution](data/dailyCodingProblem881.cpp)

---


#### Problem No. 882

```
An 8-puzzle is a game played on a 3 x 3 board of tiles, with the ninth tile missing.
The remaining tiles are labeled 1 through 8 but shuffled randomly.
Tiles may slide horizontally or vertically into an empty space,
but may not be removed from the board.

Design a class to represent the board, and find a series of
steps to bring the board to the state [[1, 2, 3], [4, 5, 6], [7, 8, None]].
```
[Solution](data/dailyCodingProblem882.cpp)

---


#### Problem No. 883

```
Given a positive integer N, find the smallest number of steps it will take to reach 1.

There are two kinds of permitted steps:

You may decrement N to N - 1.

If a * b = N, you may decrement N to the larger of a and b.

For example, given 100, you can reach 1 in five steps with
the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1.
```
[Solution](data/dailyCodingProblem883.cpp)

---


#### Problem No. 884

```
Using a function rand7() that returns an integer from 1 to 7(inclusive)
with uniform probability, implement a function rand5() that returns an
integer from 1 to 5 (inclusive).
```
[Solution](data/dailyCodingProblem884.cpp)

---


#### Problem No. 885

```
Given an array of strictly the characters 'R', 'G', and 'B',
segregate the values of the array so that all the Rs come first,
the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'],
it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
```
[Solution](data/dailyCodingProblem885.cpp)

---


#### Problem No. 886

```
The edit distance between two strings refers to the minimum
number of character insertions, deletions, and substitutions
required to change one string to the other. For example, the
edit distance between “kitten” and “sitting” is three:
substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
```
[Solution](data/dailyCodingProblem886.cpp)

---


#### Problem No. 887

```
The ancient Egyptians used to express fractions as a sum of several
terms where each numerator is one. For example, 4 / 13 can be
represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary fraction a / b, where a < b,
into an Egyptian fraction.
```
[Solution](data/dailyCodingProblem887.cpp)

---


#### Problem No. 888

```
Given a list of points, a central point, and an integer k,
find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)],
the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
```
[Solution](data/dailyCodingProblem888.cpp)

---


#### Problem No. 889

```
Run-length encoding is a fast and simple method of encoding strings.
The basic idea is to represent repeated successive characters as a
single count and character. For example, the string "AAAABBBCCDAA"
would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string
to be encoded have no digits and consists solely of alphabetic characters.
You can assume the string to be decoded is valid.
```
[Solution](data/dailyCodingProblem889.cpp)

---


#### Problem No. 890

```
There is an N by M matrix of zeroes. Given N and M, write a function
to count the number of ways of starting at the top-left corner and
getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there
are two ways to get to the bottom-right:

Right, then down
Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
```
[Solution](data/dailyCodingProblem890.cpp)

---


#### Problem No. 891

```
You are given a 2-d matrix where each cell consists of either /, \, or an empty space.
Write an algorithm that determines into how many regions the slashes divide the space.

For example, suppose the input for a three-by-six grid is the following:

\    /
 \  /
  \/
Considering the edges of the matrix as boundaries, this divides the grid
into three triangles, so you should return 3.
```
[Solution](data/dailyCodingProblem891.cpp)

---


#### Problem No. 892

```
The power set of a set is the set of all its subsets.
Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return
{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
```
[Solution](data/dailyCodingProblem892.cpp)

---


#### Problem No. 893

```
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are
of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to
build the nth house with kth color, return the minimum cost which achieves this goal.
```
[Solution](data/dailyCodingProblem893.cpp)

---


#### Problem No. 894

```
Design and implement a HitCounter class that keeps track of requests (or hits).
It should support the following operations:

record(timestamp): records a hit that happened at timestamp
total(): returns the total number of hits recorded
range(lower, upper): returns the number of hits that occurred between timestamps
lower and upper (inclusive)

Follow-up: What if our system has limited memory?
```
[Solution](data/dailyCodingProblem894.cpp)

---


#### Problem No. 895

```
Given a string which we can delete at most k,
return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2,
you could delete f and x to get 'waterretaw'.
```
[Solution](data/dailyCodingProblem895.cpp)

---


#### Problem No. 896

```
Implement division of two positive integers without using the division,
multiplication, or modulus operators. Return the quotient as an integer,
ignoring the remainder.
```
[Solution](data/dailyCodingProblem896.cpp)

---


#### Problem No. 897

```
Implement a queue using two stacks.

Recall that a queue is a FIFO (first-in, first-out) data structure with
the following methods: enqueue, which inserts an element into the queue,
and dequeue, which removes it.
```
[Solution](data/dailyCodingProblem897.cpp)

---


#### Problem No. 898

```
Implement a stack API using only a heap.
A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added
element (or throws an error if there is nothing on the stack)

Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
```
[Solution](data/dailyCodingProblem898.cpp)

---


#### Problem No. 899

```
The 24 game is played as follows. You are given a list of four integers,
each between 1 and 9, in a fixed order. By placing the operators +, -, *, and /
between the numbers, and grouping them with parentheses, determine whether
it is possible to reach the value 24.

For example, given the input [5, 2, 7, 8], you should return True,
since (5 * 2 - 7) * 8 = 24.

Write a function that plays the 24 game.
```
[Solution](data/dailyCodingProblem899.cpp)

---


#### Problem No. 900

```
Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86],
the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0,
since we would not take any elements.

Do this in O(N) time.
```
[Solution](data/dailyCodingProblem900.cpp)

---


#### Problem No. 902

```
Given a collection of intervals, find the minimum number of intervals you
need to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they
won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8),
return 1 as the last interval can be removed and the first two won't overlap.

The intervals are not necessarily sorted in any order.
```
[Solution](data/dailyCodingProblem902.cpp)

---


#### Problem No. 903

```
Given an array of numbers and a number k,
determine if there are three entries in the array
which add up to the specified number k. For example,
given [20, 303, 3, 4, 25] and k = 49,
return true as 20 + 4 + 25 = 49.
```
[Solution](data/dailyCodingProblem903.cpp)

---


#### Problem No. 904

```
Given the root of a binary tree,
return a deepest node.
For example, in the following tree, return d.

    a
   / \
  b   c
 /
d
```
[Solution](data/dailyCodingProblem904.cpp)

---


#### Problem No. 905

```
Given a list of words, determine whether the words can be chained to form a circle.
A word X can be placed in front of another word Y in a circle if the last character
of X is same as the first character of Y.

For example, the words ['chair', 'height', 'racket', touch', 'tunic'] can
form the following circle: chair --> racket --> touch --> height --> tunic --> chair.
```
[Solution](data/dailyCodingProblem905.cpp)

---


#### Problem No. 906

```
Given a set of points (x, y) on a 2D cartesian plane, find the two closest points.
For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)],
return [(-1, -1), (1, 1)].
```
[Solution](data/dailyCodingProblem906.cpp)

---


#### Problem No. 907

```
Gray code is a binary code where each successive value differ
in only one bit, as well as when wrapping around.
Gray code is common in hardware so that we don't see
temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
```
[Solution](data/dailyCodingProblem907.cpp)

---


#### Problem No. 908

```
You are given an N by M 2D matrix of lowercase letters.
Determine the minimum number of columns that can be
removed to ensure that each row is ordered from top
to bottom lexicographically. That is, the letter at
each column is lexicographically later as you go down
each row. It does not matter whether each row itself
is ordered lexicographically.

For example, given the following table:

cba
daf
ghi

This is not ordered because of the a in the center.
We can remove the second column to make it ordered:

ca
df
gi

So your function should return 1,
since we only needed to remove 1 column.

As another example, given the following table:

abcdef

Your function should return 0,
since the rows are already ordered (there's only one row).

As another example, given the following table:

zyx
wvu
tsr

Your function should return 3,
since we would need to remove all the columns to order it.
```
[Solution](data/dailyCodingProblem908.cpp)

---


#### Problem No. 909

```
Given a set of closed intervals, find the smallest set of numbers that
covers all the intervals. If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9],
one set of numbers that covers all these intervals is {3, 6}.
```
[Solution](data/dailyCodingProblem909.cpp)

---


#### Problem No. 910

```
You are given an array of integers, where each element represents
the maximum number of steps that can be jumped going forward from
that element. Write a function to return the minimum number of
jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2,
as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
```
[Solution](data/dailyCodingProblem910.cpp)

---


#### Problem No. 911

```
Given a stream of elements too large to store in memory,
pick a random element from the stream with uniform probability.
```
[Solution](data/dailyCodingProblem911.cpp)

---


#### Problem No. 912

```
Two nodes in a binary tree can be called cousins if
they are on the same level of the tree but have different parents.
For example, in the following diagram 4 and 6 are cousins.

    1
   / \
  2   3
 / \   \
4   5   6

Given a binary tree and a particular node,
find all cousins of that node.
```
[Solution](data/dailyCodingProblem912.cpp)

---


#### Problem No. 913

```
Given a complete binary tree, count the number of nodes in faster than O(n) time.
Recall that a complete binary tree has every level filled except the last,
and the nodes in the last level are filled starting from the left
```
[Solution](data/dailyCodingProblem913.cpp)

---


#### Problem No. 914

```
Implement a queue using a set of fixed-length arrays.
The queue should support enqueue, dequeue, and get_size operations.
```
[Solution](data/dailyCodingProblem914.cpp)

---


#### Problem No. 915

```
You are given an array X of floating-point numbers x1, x2, ... xn.
These can be rounded up or down to create a corresponding array Y of integers y1, y2, ... yn.

Write an algorithm that finds an appropriate Y array with the following properties:

The rounded sums of both arrays should be equal.
The absolute pairwise difference between elements is minimized.
In other words, |x1- y1| + |x2- y2| + ... + |xn- yn| should be as small as possible.
For example, suppose your input is [1.3, 2.3, 4.4]. In this case you cannot do better than [1, 2, 5],
which has an absolute difference of |1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1.
```
[Solution](data/dailyCodingProblem915.cpp)

---


#### Problem No. 916

```
Given the head of a singly linked list, reverse it in-place.
```
[Solution](data/dailyCodingProblem916.cpp)

---


#### Problem No. 917

```
Given a linked list of numbers and a pivot k,
partition the linked list so that all nodes less
than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3,
the solution could be 1 -> 0 -> 5 -> 8 -> 3.
```
[Solution](data/dailyCodingProblem917.cpp)

---


#### Problem No. 919

```
A wall consists of several rows of bricks of various integer
lengths and uniform height. Your goal is to find a vertical
line going from the top to the bottom of the wall that cuts
through the fewest number of bricks. If the line goes through
the edge between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values
in each row represent the lengths of bricks in that row:

[[3, 5, 1, 1],
 [2, 3, 3, 2],
 [5, 5],
 [4, 4, 2],
 [1, 3, 3, 3],
 [1, 1, 6, 1, 1]]

The best we can we do here is to draw a line after the eighth brick,
which will only require cutting through the bricks in the third and fifth row.

Given an input consisting of brick lengths for each row such
as the one above, return the fewest number of bricks that must
be cut to create a vertical line.
```
[Solution](data/dailyCodingProblem919.cpp)

---


#### Problem No. 920

```
Implement a data structure which carries out the
following operations without resizing the underlying
array:

add(value): Add a value to the set of values.
check(value): Check whether a value is in the set.

The check method may return occasional false positives
(in other words, incorrectly identifying an element as
part of the set), but should always correctly identify
a true element.
```
[Solution](data/dailyCodingProblem920.cpp)

---


#### Problem No. 921

```
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field
named both, which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the
element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python),
you can assume you have access to get_pointer and dereference_pointer
functions that converts between nodes and memory addresses.
```
[Solution](data/dailyCodingProblem921.c)

---


#### Problem No. 922

```
Implement locking in a binary tree. A binary tree node can be
locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked

lock, which attempts to lock the node. If it cannot be locked,
then it should return false. Otherwise, it should lock it and return true.

unlock, which unlocks the node. If it cannot be unlocked, then it should return false.
Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like.
You may assume the class is used in a single-threaded program, so there is no need for
actual locks or mutexes. Each method should run in O(h),
where h is the height of the tree.
```
[Solution](data/dailyCodingProblem922.cpp)

---


#### Problem No. 923

```
Given a 32-bit positive integer N,
determine whether it is a power
of four in faster than O(log N) time.
```
[Solution](data/dailyCodingProblem923.cpp)

---


#### Problem No. 924

```
Given an array of integers out of order, determine the bounds of the smallest
window that must be sorted in order for the entire array to be sorted.
For example, given [3, 7, 5, 6, 9], you should return (1, 3)
```
[Solution](data/dailyCodingProblem924.cpp)

---


#### Problem No. 925

```
Write a function to flatten a nested dictionary.
Namespace the keys with a period.

For example, given the following dictionary:

{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}

it should become:

{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}

You can assume keys do not contain dots in them,
i.e. no clobbering will occur.
```
[Solution](data/dailyCodingProblem925.cpp)

---


#### Problem No. 926

```
Given the root of a binary tree, find the most frequent subtree sum.
The subtree sum of a node is the sum of all values under a node,
including the node itself.

For example, given the following tree:

  5
 / \
2  -5

Return 2 as it occurs twice: once as the left leaf,
and once as the sum of 2 + 5 - 5.
```
[Solution](data/dailyCodingProblem926.cpp)

---


#### Problem No. 927

```
Given a linked list and a positive integer k,
rotate the list to the right by k places.

For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2,
it should become 3 -> 5 -> 7 -> 7.

Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3,
it should become 3 -> 4 -> 5 -> 1 -> 2.
```
[Solution](data/dailyCodingProblem927.cpp)

---


#### Problem No. 928

```
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
```
[Solution](data/dailyCodingProblem928.cpp)

---


#### Problem No. 930

```
Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list
4 -> 1 -> -3 -> 99 should
become -3 -> 1 -> 4 -> 99.
```
[Solution](data/dailyCodingProblem930.cpp)

---


#### Problem No. 931

```
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
```
[Solution](data/dailyCodingProblem931.cpp)

---


#### Problem No. 933

```
The sequence [0, 1, ..., N] has been jumbled,
and the only clue you have for its order is an array
representing whether each number is larger or smaller than the last.

Given this information, reconstruct an array that is consistent with it.
For example, given [None, +, +, -, +], you could return [1, 2, 3, 0, 4].
```
[Solution](data/dailyCodingProblem933.cpp)

---


#### Problem No. 934

```
Given a string, return the first recurring character in it,
or null if there is no recurring character.

For example, given the string "acbbac", return "b".
Given the string "abcdef", return null.
```
[Solution](data/dailyCodingProblem934.cpp)

---


#### Problem No. 935

```
Given a binary tree, determine whether or not it is height-balanced.
A height-balanced binary tree can be defined as one in which the heights
of the two subtrees of any node never differ by more than one.
```
[Solution](data/dailyCodingProblem935.cpp)

---


#### Problem No. 936

```
Given a binary search tree and a range [a, b] (inclusive),
return the sum of the elements of the binary search tree within the range.

For example, given the following tree:

    5
   / \
  3   8
 / \ / \
2  4 6  10

and the range [4, 9], return 23 (5 + 4 + 6 + 8).
```
[Solution](data/dailyCodingProblem936.cpp)

---


#### Problem No. 937

```
You're given a string consisting solely of (, ), and *. *
can represent either a (, ), or an empty string.
Determine whether the parentheses are balanced.

For example, (()* and (*) are balanced. )*( is not balanced.
```
[Solution](data/dailyCodingProblem937.cpp)

---


#### Problem No. 938

```
You are given a circular lock with three wheels,
each of which display the numbers 0 through 9 in order.
Each of these wheels rotate clockwise and counterclockwise.

In addition, the lock has a certain number of "dead ends",
meaning that if you turn the wheels to one of these combinations,
the lock becomes stuck in that state and cannot be opened.

Let us consider a "move" to be a rotation of a single wheel by one digit,
in either direction. Given a lock initially set to 000,
a target combination, and a list of dead ends, write a
function that returns the minimum number of moves required
to reach the target state, or None if this is impossible.
```
[Solution](data/dailyCodingProblem938.cpp)

---


#### Problem No. 939

```
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
```
[Solution](data/dailyCodingProblem939.cpp)

---


#### Problem No. 940

```
A network consists of nodes labeled 0 to N.
You are given a list of edges (a, b, t),
describing the time t it takes for a
message to be sent from node a to node b.
Whenever a node receives a message,
it immediately passes the message on
to a neighboring node, if possible.

Assuming all nodes are connected,
determine how long it will take for
every node to receive a message
that begins at node 0.

For example, given N = 5, and the following edges:

edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
You should return 9, because propagating
the message from 0 -> 2 -> 3 -> 4
will take that much time.
```
[Solution](data/dailyCodingProblem940.cpp)

---


#### Problem No. 941

```
Suppose you are given a table of currency exchange rates, represented as a 2D array.
Determine whether there is a possible arbitrage: that is, whether there is some
sequence of trades you can make, starting with some amount A of any currency,
so that you can end up with some amount greater than A of that currency.

There are no transaction costs and you can trade fractional quantities.
```
[Solution](data/dailyCodingProblem941.cpp)

---


#### Problem No. 942

```
Given a string of parentheses, write a function to compute the minimum
number of parentheses to be removed to make the string valid
(i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1.
Given the string ")(", you should return 2,
since we must remove all of them.
```
[Solution](data/dailyCodingProblem942.cpp)

---


#### Problem No. 943

```
You are given a 2 x N board, and instructed to completely cover the board with the following shapes:

Dominoes, or 2 x 1 rectangles.
Trominoes, or L-shapes.
For example, if N = 4, here is one possible configuration, where A is a domino, and B and C are trominoes.

A B B C
A B C C
Given an integer N, determine in how many ways this task is possible.
```
[Solution](data/dailyCodingProblem943.cpp)

---


#### Problem No. 944

```
Given an integer, find the next permutation of it in absolute order.
For example, given 48975, the next permutation would be 49578.
```
[Solution](data/dailyCodingProblem944.cpp)

---


#### Problem No. 945

```
Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h

and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1,
the longest path would be c -> a -> d -> f, with a length of 17.

The path does not have to pass through the root,
and each node can have any amount of children.
```
[Solution](data/dailyCodingProblem945.cpp)

---


#### Problem No. 946

```
Pascal's triangle is a triangular array of integers constructed with the following formula:

The first row consists of the number 1.
For each subsequent row, each element is the sum of the numbers directly above it, on either side.
For example, here are the first few rows:

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
Given an input k, return the kth row of Pascal's triangle.

Bonus: Can you do this using only O(k) space?
```
[Solution](data/dailyCodingProblem946.cpp)

---


#### Problem No. 947

```
We say a number is sparse if there are no adjacent ones
in its binary representation.

For example, 21 (10101) is sparse, but 22 (10110) is not.
For a given input N, find the smallest sparse number
greater than or equal to N.

Do this in faster than O(N log N) time.
```
[Solution](data/dailyCodingProblem947.cpp)

---


#### Problem No. 948

```
The Tower of Hanoi is a puzzle game with three rods and n disks, each a different size.

All the disks start off on the first rod in a stack. They are ordered by size,
with the largest disk on the bottom and the smallest one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:

You can only move one disk at a time.
A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.
You cannot place a larger disk on top of a smaller disk.
Write a function that prints out all the steps necessary to complete the Tower of Hanoi.
You should assume that the rods are numbered, with the first rod being 1,
the second (auxiliary) rod being 2, and the last (goal) rod being 3.

For example, with n = 3, we can do this in 7 moves:

Move 1 to 3
Move 1 to 2
Move 3 to 2
Move 1 to 3
Move 2 to 1
Move 2 to 3
Move 1 to 3
```
[Solution](data/dailyCodingProblem948.cpp)

---


#### Problem No. 949

```
Implement an autocomplete system. That is, given a query string s and
a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings
[dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
```
[Solution](data/dailyCodingProblem949.cpp)

---


#### Problem No. 950

```
You are given a list of data entries that represent entries and exits
of groups of people into a building.

An entry looks like this:

{"timestamp": 1526579928, count: 3, "type": "enter"}
This means 3 people entered the building. An exit looks like this:

{"timestamp": 1526580382, count: 2, "type": "exit"}
This means that 2 people exited the building. timestamp is in Unix time.

Find the busiest period in the building, that is, the time with
the most people in the building. Return it as a pair of (start, end) timestamps.
You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
```
[Solution](data/dailyCodingProblem950.cpp)

---


#### Problem No. 951

```
Given a stack of N elements, interleave the first half of the stack with the second half
reversed using only one other queue. This should be done in-place.

Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.

For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3].
If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].

Hint: Try working backwards from the end state.
```
[Solution](data/dailyCodingProblem951.cpp)

---


#### Problem No. 952

```
You are given a string formed by concatenating several words
corresponding to the integers zero through nine and then anagramming.

For example, the input could be 'niesevehrtfeev',
which is an anagram of 'threefiveseven'.
Note that there can be multiple instances of each integer.

Given this string, return the original integers
in sorted order. In the example above, this would be 357.
```
[Solution](data/dailyCodingProblem952.cpp)

---


#### Problem No. 953

```
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10,
since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
```
[Solution](data/dailyCodingProblem953.cpp)

---


#### Problem No. 954

```
A unival tree (which stands for "universal value") is a tree where
all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
```
[Solution](data/dailyCodingProblem954.cpp)

---


#### Problem No. 955

```
Suppose an arithmetic expression is given as a binary tree.
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).
```
[Solution](data/dailyCodingProblem955.cpp)

---


#### Problem No. 956

```
Given k sorted singly linked lists, write a function to merge
all the lists into one sorted singly linked list.
```
[Solution](data/dailyCodingProblem956.cpp)

---


#### Problem No. 957

```
The skyline of a city is composed of several buildings of various widths and heights,
possibly overlapping one another when viewed from a distance. We can represent the
buildings using an array of (left, right, height) tuples, which tell us where on an
imaginary x-axis a building begins and ends, and how tall it is. The skyline itself
can be described by a list of (x, height) tuples, giving the locations at which the
height visible to a distant observer changes, and each new height.

Given an array of buildings as described above, create a function that returns the skyline.

For example, suppose the input consists of the buildings [(0, 15, 3), (4, 11, 5), (19, 23, 4)].
In aggregate, these buildings would create a skyline that looks like the one below.

     ______  
    |      |        ___
 ___|      |___    |   | 
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
As a result, your function should return [(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)].
```
[Solution](data/dailyCodingProblem957.cpp)

---


#### Problem No. 958

```
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs,
and a starting airport, compute the person's itinerary. If no such itinerary exists, return null.
If there are multiple possible itineraries, return the lexicographically smallest one.
All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A',
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C']
is also a valid itinerary. However, the first one is lexicographically smaller.
```
[Solution](data/dailyCodingProblem958.cpp)

---


#### Problem No. 959

```
Write an algorithm that finds the total number of set bits in all integers between 1 and N
```
[Solution](data/dailyCodingProblem959.cpp)

---


#### Problem No. 960

```
You are given an array of nonnegative integers.
Let's say you start at the beginning of the array and are trying to advance to the end.
You can advance at most, the number of steps that you're currently on.
Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1],
we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0],
we can't reach the end, so return false.
```
[Solution](data/dailyCodingProblem960.cpp)

---


#### Problem No. 961

```
Given an absolute pathname that may have . or .. as part of it,
return the shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
```
[Solution](data/dailyCodingProblem961.cpp)

---


#### Problem No. 962

```
A knight's tour is a sequence of moves by a knight on a
chessboard such that all squares are visited once.

Given N, write a function to return the number
of knight's tours on an N by N chessboard.
```
[Solution](data/dailyCodingProblem962.cpp)

---


#### Problem No. 963

```
Given two singly linked lists that intersect at some point, find the intersecting node.
The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
```
[Solution](data/dailyCodingProblem963.cpp)

---


#### Problem No. 964

```
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
```
[Solution](data/dailyCodingProblem964.cpp)

---


#### Problem No. 965

```
UTF-8 is a character encoding that maps each symbol to one, two, three, or four bytes.

For example, the Euro sign, €, corresponds to
the three bytes 11100010 10000010 10101100.

The rules for mapping characters are as follows:

For a single-byte character, the first bit must be zero.
For an n-byte character, the first byte starts with n ones and a zero.
The other n - 1 bytes all start with 10.

Visually, this can be represented as follows.

 Bytes   |           Byte format
-----------------------------------------------
   1     | 0xxxxxxx
   2     | 110xxxxx 10xxxxxx
   3     | 1110xxxx 10xxxxxx 10xxxxxx
   4     | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Write a program that takes in an array of integers representing byte values,
and returns whether it is a valid UTF-8 encoding.
```
[Solution](data/dailyCodingProblem965.cpp)

---


#### Problem No. 966

```
Given the head to a singly linked list, where each node also has a “random” pointer
that points to anywhere in the linked list, deep clone the list.
```
[Solution](data/dailyCodingProblem966.cpp)

---


#### Problem No. 967

```
You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}.
By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
```
[Solution](data/dailyCodingProblem967.cpp)

---


#### Problem No. 968

```
Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.

On the ith jump, you may move exactly i places to the left or right.

Find a path with the fewest number of jumps required to get from 0 to N.
```
[Solution](data/dailyCodingProblem968.cpp)

---


#### Problem No. 969

```
Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
A 1 represents land and 0 represents water, so an island is a group of
1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```
[Solution](data/dailyCodingProblem969.cpp)

---


#### Problem No. 970

```
You have a large array with most of the elements as zero.

Use a more space-efficient data structure, SparseArray, that implements the same interface:

init(arr, size): initialize with the original large array and size.
set(i, val): updates index at i with val.
get(i): gets the value at index i.
```
[Solution](data/dailyCodingProblem970.cpp)

---


#### Problem No. 971

```
Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
you should return:

[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]

Follow-up: What if you couldn't use any extra space?
```
[Solution](data/dailyCodingProblem971.cpp)

---


#### Problem No. 972

```
Given a string with repeated characters, rearrange the string so that no two adjacent
characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
```
[Solution](data/dailyCodingProblem972.cpp)

---


#### Problem No. 972

```
Given a string with repeated characters, rearrange the string so that no two adjacent
characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
```
[Solution](data/dailyCodingProblem972.cpp)

---


#### Problem No. 973

```
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be
decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable.
For example, '001' is not allowed.
```
[Solution](data/dailyCodingProblem973.cpp)

---


#### Problem No. 975

```
You are going on a road trip, and would like to create a suitable music playlist.
The trip will require N songs, though you only have M songs downloaded, where M < N.
A valid playlist should select each song at least once, and guarantee a buffer of B songs between repeats.

Given N, M, and B, determine the number of valid playlists.
```
[Solution](data/dailyCodingProblem975.cpp)

---


#### Problem No. 976

```
A cryptarithmetic puzzle is a mathematical game where the digits of some numbers
are represented by letters. Each letter represents a unique digit.

For example, a puzzle of the form:

  SEND
+ MORE
--------
 MONEY

may have the solution:
{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}

Given a three-word puzzle like the one above,
create an algorithm that finds a solution.
```
[Solution](data/dailyCodingProblem976.cpp)

---


#### Problem No. 977

```
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string,
such as zLg6wl.

restore(short), which expands the shortened string into the original url.
If no such shortened string exists, return null.

Hint: What if we enter the same URL twice?
```
[Solution](data/dailyCodingProblem977.cpp)

---


#### Problem No. 978

```
Given a string, return whether it represents a number.
Here are the different kinds of numbers:

"10", a positive integer
"-10", a negative integer
"10.1", a positive real number
"-10.1", a negative real number
"1e5", a number in scientific notation
And here are examples of non-numbers:

"a"
"x 1"
"a -2"
"-"
```
[Solution](data/dailyCodingProblem978.cpp)

---


#### Problem No. 979

```
Conway's Game of Life takes place on an infinite two-dimensional board of square cells.
Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a starting
list of live cell coordinates and the number of steps it should run for.
Once initialized, it should print out the board state at each step.
Since it's an infinite board, print out only the relevant coordinates,
i.e. from the top-leftmost live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
```
[Solution](data/dailyCodingProblem979.cpp)

---


#### Problem No. 980

```
On our special chessboard, two bishops attack each other if they share the same diagonal.
This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard.
Write a function to count the number of pairs of bishops that attack each other.
The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)
The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.
```
[Solution](data/dailyCodingProblem980.cpp)

---


#### Problem No. 981

```
Describe an algorithm to compute the longest
increasing subsequence of an array of numbers in O(n log n) time.
```
[Solution](data/dailyCodingProblem981.cpp)

---


#### Problem No. 982

```
A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees.
For example, 16891 is strobogrammatic.

Create a program that finds all strobogrammatic numbers with N digits.
```
[Solution](data/dailyCodingProblem982.cpp)

---


#### Problem No. 983

```
Given a binary tree,
return all paths from the root to leaves.

For example, given the tree:

   1
  / \
 2   3
    / \
   4   5

Return [[1, 2], [1, 3, 4], [1, 3, 5]].
```
[Solution](data/dailyCodingProblem983.cpp)

---


#### Problem No. 984

```
Given a string of parentheses, find the balanced string that can be produced from it
using the minimum number of insertions and deletions. If there are multiple solutions, return any of them.

For example, given "(()", you could return "(())". Given "))()(", you could return "()()()()".
```
[Solution](data/dailyCodingProblem984.cpp)

---


#### Problem No. 985

```
One way to unlock an Android phone is through a pattern of swipes across a 1-9 keypad.

For a pattern to be valid, it must satisfy the following:

All of its keys must be distinct.
It must not connect two keys by jumping over a third key, unless that key has already been used.
For example, 4 - 2 - 1 - 7 is a valid pattern, whereas 2 - 1 - 7 is not.

Find the total number of valid unlock patterns of length N, where 1 <= N <= 9.
```
[Solution](data/dailyCodingProblem985.cpp)

---


#### Problem No. 986

```
Given an integer n, return the length of the
longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
```
[Solution](data/dailyCodingProblem986.cpp)

---


#### Problem No. 987

```
Given an array of numbers and an index i, return the index of
the nearest larger number of the number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are the equal, then return
any one of them. If the array at i doesn't have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array, can you do this in constant time?
```
[Solution](data/dailyCodingProblem987.cpp)

---


#### Problem No. 988

```
Given a positive integer n, find the smallest
number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.

Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.
```
[Solution](data/dailyCodingProblem988.cpp)

---


#### Problem No. 990

```
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time,
you could climb any number from a set of positive integers X? For example,
if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
```
[Solution](data/dailyCodingProblem990.cpp)

---


#### Problem No. 992

```
Given the root to a binary search tree, find the second largest node in the tree.
```
[Solution](data/dailyCodingProblem992.cpp)

---


#### Problem No. 993

```
Given a list of elements, find the majority element,
which appears more than half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], return 1.
```
[Solution](data/dailyCodingProblem993.cpp)

---


#### Problem No. 994

```
Print the nodes in a binary tree level-wise.
For example, the following should print 1, 2, 3, 4, 5.

  1
 / \
2   3
   / \
  4   5
```
[Solution](data/dailyCodingProblem994.cpp)

---


#### Problem No. 995

```
Given an array of integers, return a new array such that each element
at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
```
[Solution](data/dailyCodingProblem995.cpp)

---


#### Problem No. 996

```
Recall that the minimum spanning tree is the subset of edges of a tree that
connect all its vertices with the smallest possible total edge weight.
Given an undirected graph with weighted edges, compute the maximum weight spanning tree.
```
[Solution](data/dailyCodingProblem996.cpp)

---


#### Problem No. 997

```
Given the root to a binary tree, implement serialize(root),
which serializes the tree into a string, and deserialize(s),
which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```
[Solution](data/dailyCodingProblem997.cpp)

---


#### Problem No. 998

```
Given an undirected graph represented as an adjacency matrix and an integer k,
write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors
```
[Solution](data/dailyCodingProblem998.cpp)

---


#### Problem No. 999

```
Suppose you have a multiplication table that is N by N. That is, a 2D array where the value
at the i-th row and j-th column is (i + 1) * (j + 1) (if 0-indexed) or i * j (if 1-indexed).

Given integers N and X, write a function that returns the number of times X appears as a
value in an N by N multiplication table.

For example, given N = 6 and X = 12, you should return 4, since the multiplication table looks like this:

| 1 | 2 | 3 | 4 | 5 | 6 |

| 2 | 4 | 6 | 8 | 10 | 12 |

| 3 | 6 | 9 | 12 | 15 | 18 |

| 4 | 8 | 12 | 16 | 20 | 24 |

| 5 | 10 | 15 | 20 | 25 | 30 |

| 6 | 12 | 18 | 24 | 30 | 36 |

And there are 4 12's in the table
```
[Solution](data/dailyCodingProblem999.cpp)

---


#### Problem No. 1000

```
Suppose an array sorted in ascending order is rotated at some pivot
unknown to you beforehand. Find the minimum element in O(log N) time.
You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
```
[Solution](data/dailyCodingProblem1000.cpp)

---
