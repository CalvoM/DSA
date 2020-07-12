class Stack:
    """ Class Stack

    Implements the Stack Data structure
    """

    def __init__(self):
        self._data = []

    
    def top(self):
        return self._data[-1]
    
    def push(self, el):
        self._data.append(el)

    def pop(self):
        return self._data.pop()

    def isEmpty(self):
        return len(self._data)==0
    
    def clear(self):
        self._data.clear()
