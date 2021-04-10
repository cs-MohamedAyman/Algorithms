import heapq

class node:
    def __init__(self, freq, symbol, left=None, right=None, huff=''):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = huff
    def __lt__(self, x):
        return x.freq > self.freq

def print_nodes(node, val = ''):
    new_val = val + str(node.huff)
    if (node.left):
        print_nodes(node.left, new_val)
    if (node.right):
        print_nodes(node.right, new_val)
    if (not node.left and not node.right):
        print(node.symbol, "->", new_val)
 
chars = ['a', 'b', 'c', 'd', 'e', 'f']
freq  = [ 5,   9,   12,  13,  16, 45 ]
nodes = []
for i in range(len(chars)):
    nodes.append(node(freq[i], chars[i]))
heapq.heapify(nodes)
while len(nodes) > 1:
    left = heapq.heappop(nodes)
    right = heapq.heappop(nodes)
    left.huff = 0
    right.huff = 1
    new_node = node(left.freq+right.freq, left.symbol+right.symbol, left, right)
    heapq.heappush(nodes, new_node)
print_nodes(heapq.heappop(nodes))
