


class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None
        self.prev = None


class DLL:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next

    def createDLL(self, value):
        newnode = Node(value)

        newnode.next = None
        newnode.prev = None
        self.head = newnode
        self.tail = newnode
        return "created"

    def insert(self, value, location):


        if self.head == None:
            print( "node does not exist")
        

        else:
            newnode = Node(value)
            if location == 0:

                newnode.prev = None
                newnode.next = self.head
                self.head.prev = newnode
                self.head = newnode

            elif location == -1:

                newnode.next = None
                newnode.prev = self.tail
                self.tail.next = newnode
                self.tail = newnode

            else:
                tempnode = self.head
                index = 0
                while index < location-1:
                    tempnode = tempnode.next
                    index += 1



                

                nextnode = tempnode.next
                newnode.prev = tempnode
                newnode.next = nextnode
                tempnode.next = newnode
                nextnode.prev = newnode

              




           


createdDDL = DLL()
createdDDL.createDLL(3)



print([i.value for i in createdDDL])
createdDDL.insert(1, 0)
createdDDL.insert(2, -1)
createdDDL.insert(2, 1)

print([i.value for i in createdDDL])
