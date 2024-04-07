from collections import deque


def main():
    
    my_queue = deque()
    
    my_queue.appendleft(10)
    my_queue.appendleft(20)
    my_queue.appendleft(100)
    my_queue.appendleft(1000)
    my_queue.appendleft(20000)
    my_queue.extend([1,2,3,34,4,3])
    print(my_queue)
    
    my_queue.pop()
    
    print(my_queue.pop())
    print(my_queue)
    
    
    #rotate elements to the right
    my_queue.rotate(2)
    print(my_queue)
    
    #rotate elements to the left
    my_queue.rotate(-2)
    print(my_queue)
    
main()

"""### Python `deque` Documentation

#### Introduction:
`deque` (pronounced "deck") is a specialized data structure in Python that provides a double-ended queue, which supports
adding and removing elements efficiently from both ends of the queue. It is part of the Python `collections` module.

#### Features:
- **Efficient Operations**: `deque` supports efficient appending and popping of elements from both ends, making it 
suitable for implementing queues and stacks.
- **Thread Safety**: `deque` is thread-safe for appending and popping from opposite ends, making it suitable for 
multi-threaded applications.
- **Flexible Size**: Unlike fixed-size arrays, `deque` can dynamically resize itself to accommodate new elements.
- **Iterable**: `deque` supports iteration, allowing easy traversal of elements in the queue.

#### Usage:
```python
from collections import deque

# Creating a deque
my_deque = deque()

# Adding elements
my_deque.append(10)           # Append to the right end
my_deque.appendleft(20)       # Append to the left end

# Removing elements
element = my_deque.pop()      # Remove and return from the right end
element = my_deque.popleft()  # Remove and return from the left end

# Accessing elements
first_element = my_deque[0]   # Access first element
last_element = my_deque[-1]   # Access last element

# Iterating through deque
for item in my_deque:
    print(item)

# Length of deque
length = len(my_deque)
```

#### Use Cases:
- **Queue Implementation**: `deque` is commonly used to implement FIFO (First In, First Out) queues due to its efficient
appending and popping operations on both ends.
- **Stack Implementation**: `deque` can also be used to implement LIFO (Last In, First Out) stacks.
- **Sliding Window**: `deque` is useful for solving problems involving sliding window algorithms, where elements are 
added or removed from both ends efficiently.

#### Considerations:
- **Memory Overhead**: `deque` may have higher memory overhead compared to simple lists due to its additional 
functionality.
- **Performance**: While `deque` provides efficient appending and popping operations from both ends, random access 
(`my_deque[i]`) is less efficient compared to lists.

#### Conclusion:
Python `deque` is a versatile data structure that offers efficient operations for adding and removing elements from both
ends. It is a powerful tool for implementing queues, stacks, and solving various algorithmic problems efficiently.
    """