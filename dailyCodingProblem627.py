# Given an iterator with methods next() and hasNext(),
# create a wrapper iterator, PeekableInterface,
# which also implements peek(). peek shows the
# next element that would be returned on next().

# Here is the interface:

# class PeekableInterface(object):
    # def __init__(self, iterator):
        # pass

    # def peek(self):
        # pass

    # def next(self):
        # pass

    # def hasNext(self):
        # pass


class PeekableInterface(object):
    def __init__(self, iterator):
        self.cache = None
        self.iterator = iterator
    
    def peek(self):
        if self.cache is None:
            self.cache = self.iterator.next()
        return self.cache
    
    def next(self):
        if self.cache is not None:
            temp = self.cache
            self.cache = None
            return temp
        return self.iterator.next()
        
    def hasNext(self):
        return (self.cache != None) or self.iterator.hasNext()

nums = [1,2,3,4,5,6]
it = PeekableInterface(iter(nums))

while it.hasNext():
    print(it.peek(), end = " ")
    print(it.next())