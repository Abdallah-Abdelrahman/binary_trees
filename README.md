# Binary trees

In computer science, a binary tree is a tree data structure in which each node has at most two children, referred to as the left child and the right child.

## Types of binary trees:

- **Full binary tree(sometimes referred to as a proper, plane, or strict binary tree)**: is a tree in which every node has either 0 or 2 children.
- **Perfect binary tree**: is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.
- **Complete binary tree**: is a binary tree in which every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
- **Balanced binary tree**: is a binary tree structure in which the left and right subtrees of every node differ in height (the number of edges from the top-most node to the farthest node in a subtree) by no more than 1 (or the skew is no greater than 1).

## Common operations:

+ **_Insertion_**:<br />
Nodes can be inserted into binary trees in between two other nodes or added after a leaf node. In binary trees, a node that is inserted is specified as to whose child it will be.
    - leaf node: To add a new node after leaf node A, A assigns the new node as one of its children and the new node assigns node A as its parent.
    - Internal nodes: Insertion on internal nodes is slightly more complex than on leaf nodes. Say that the internal node is node A and that node B is the child of A. (If the insertion is to insert a right child, then B is the right child of A, and similarly with a left child insertion.) A assigns its child to the new node and the new node assigns its parent to A. Then the new node assigns its child to B and B assigns its parent as the new node.


+ **_Deletion_**: <br />
Deletion is the process whereby a node is removed from the tree. Only certain nodes in a binary tree can be removed _unambiguously_.
    - Node with zero or one children: Suppose that the node to delete is node A. If A has no children, deletion is accomplished by setting the child of A's parent to null. If A has one child, set the parent of A's child to A's parent and set the child of A's parent to A's child.
    - Node with two children: In a binary tree, a node with two children cannot be deleted unambiguously.[32] However, in certain binary trees (including binary search trees) these nodes can be deleted, though with a rearrangement of the tree structure.

## Traversal:

+ Pre-order: In pre-order, we always visit the current node; next, we recursively traverse the current node's left subtree, and then we recursively traverse the current node's right subtree. The pre-order traversal is a topologically sorted one, because a parent node is processed before any of its child nodes is done.
+ In-order: In in-order, we always recursively traverse the current node's left subtree; next, we visit the current node, and lastly, we recursively traverse the current node's right subtree.
+ Post-order: In post-order, we always recursively traverse the current node's left subtree; next, we recursively traverse the current node's right subtree and then visit the current node. Post-order traversal can be useful to get postfix expression of a binary expression tree.
+ Depth-first order: In depth-first order, we always attempt to visit the node farthest from the root node that we can, but with the caveat that it must be a child of a node we have already visited.
+ Breadth-first order(level-order): Contrasting with depth-first order is breadth-first order, which always attempts to visit the node closest to the root that it has not already visited.
