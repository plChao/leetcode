
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

copyed_Node = {}
def copy_Node(ptr):
    if ptr == None:
        return None
    try:
        return copyed_Node[ptr]
    except:
        newNode = Node(ptr.val)
        copyed_Node[ptr] = newNode
        newNode.next = copy_Node(ptr.next)
        newNode.random = copy_Node(ptr.random)
        return newNode

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        return copy_Node(head)

        
def print_list(head):
    cur = head
    while(cur != None):
        print(cur.val, end=" ")
        cur = cur.next
    print()

num = 10
head = Node(48)
while(num):
    cur = Node(num, head)
    head = cur
    num-=1
print_list(head)
s = Solution()
head = s.copyRandomList(head)
print_list(head)