class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        if self.search(new_val):
            return
        if  not self.root:
            self.root = Node(new_val)
            return
        nextNode = self.root
        while  nextNode!= None:
            currentNode = nextNode
            if new_val<nextNode.value:
                nextNode = nextNode.left
            elif new_val>nextNode.value:
                nextNode = nextNode.right
        if new_val<currentNode.value:
            currentNode.left = Node(new_val)
        if new_val>currentNode.value:
            currentNode.right = Node(new_val)

    def search(self, find_val):
        return self.searchVal(self.root,find_val)

    def searchVal(self,root,find_val):
        if root == None:
            return False
        if root.value == find_val:
            return True
        if root.value>find_val:
            return self.searchVal(root.left,find_val)
        if root.value<find_val:
            return self.searchVal(root.right,find_val)

# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print tree.search(4)
# Should be False
print tree.search(6)
