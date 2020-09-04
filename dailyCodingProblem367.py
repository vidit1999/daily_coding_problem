# Given two sorted iterators, merge it into one iterator.

# For example, given these two iterators:

# foo = iter([5, 10, 15])
# bar = iter([3, 8, 9])
# You should be able to do:

# for num in merge_iterators(foo, bar):
    # print(num)
# 3
# 5
# 8
# 9
# 10
# 15
# Bonus: Make it work without pulling in the contents of the iterators in memory.

def merge_iterators(foo, bar):
    try:
        item1 = next(foo)
        item2 = next(bar)
    except StopIteration:
        return
    
    while True:
        try:
            if(item1 < item2):
                yield item1
                item1 = next(foo)
            else:
                yield item2
                item2 = next(bar)

        except StopIteration:
            while True:
                try:
                    item1 = next(foo)
                    yield item1
                except StopIteration:
                    break
            while True:
                try:
                    item2 = next(bar)
                    yield item2
                except StopIteration:
                    break

for num in merge_iterators(iter([5, 10, 15]), iter([3, 8, 9])):
    print(num)