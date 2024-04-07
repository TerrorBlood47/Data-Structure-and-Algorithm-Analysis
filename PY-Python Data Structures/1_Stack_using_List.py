
class Stack():
    
    def __init__(self):
        self.stack = list()
    
    def push(self, value):
        self.stack.append(value)
    
    def pop(self):
        if len(self.stack):
            self.stack.pop()
        else:
            print("empty stack")
            
    def peek(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        else:
            return "empty stack"
    
    def __str__(self) -> str:
        return str(self.stack)

def  main():
    
    #basic way
    
    my_stack = list()
    
    my_stack.append(10)
    my_stack.append(20)
    my_stack.append(30)
    
    print(my_stack)
    
    my_stack.pop()
    
    print(my_stack)
    
    
    ##classy way
    
    stack = Stack()
    
    stack.push(10)
    stack.push(20)
    stack.push(30)
    
    print(stack)
    
    stack.pop()
    stack.pop()
    
    print(stack)
    print(stack.peek())
    
    
    
main()