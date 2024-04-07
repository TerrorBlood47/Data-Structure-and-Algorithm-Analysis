class sllNode:
    data = None
    next = None
    def __init__(self, data=None, next = None):
        self.data = data
        self.next = next
        

class SinglyLinkedList:
    
    def __init__(self) -> None:
        self.root = None
        
    def insert_at_beginning(self, data):
        
        if self.root == None:
            self.root = sllNode(data, None)
            return
        
        new_root = sllNode(data,self.root)
        self.root = new_root 
        
    
    def insert_at_end(self, data):
        
        if self.root == None:
            self.root = sllNode(data, None)
            return
        
        node = self.root
        while node.next != None:
            node = node.next
        node.next = sllNode(data, None)
    
    def __print__(self):
        
        if self.root == None:
            print("the linked list is empty")
            return 
        
        node = self.root
        ll_str = ''
        
        while node != None:
            ll_str += str(node.data) + "->"
            node = node.next
        
        ll_str += "/"
        
        print(ll_str)
        
    def get_len(self)->int:
        count = 0
        node = self.root
        while node != None:
            node = node.next
            count = count + 1
        
        return count
            
    def remove_at(self, index):
        
        if index<0 or index>=self.get_len():
            raise Exception("Invalid Index")
            
        if index == 0:
            prev_root = self.root
            self.root = prev_root.next
            return
        
        elif index == self.get_len() - 1:
            node = self.root
            while node.next.next!= None:
                node = node.next
            node.next = None # just asserting node = None does not delete it
            return
        else:
            prev_node = self.root
            node = self.root.next
            next_node = self.root.next.next
            i = 1
            while i != index:
                prev_node = node
                node = node.next
                next_node = node.next
                i = i + 1
            
            prev_node.next = next_node
            return
            
            
if __name__ == "__main__":
    
    ll = SinglyLinkedList()
    
    ll.insert_at_beginning(10)
    ll.insert_at_beginning(20)
    ll.insert_at_beginning(30)
    
    ll.__print__()
    
    ll.insert_at_end(100)
    
    ll.__print__()
    
    ll.remove_at(3)
    
    ll.__print__()
    