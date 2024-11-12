Red-Black Tree Implementation in C++
This project provides an implementation of a Red-Black Tree in C++. A Red-Black Tree is a balanced binary search tree with additional properties that ensure the tree remains balanced during insertions and deletions. This structure allows for efficient searching, insertion, and deletion operations.

Overview
A Red-Black Tree is a binary search tree with the following properties:

Every node is either red or black.
The root is always black.
All leaves (sentinels) are black.
If a node is red, then both of its children are black (no two red nodes can be adjacent).
Every path from a node to its descendant leaves has the same number of black nodes.
This implementation includes core operations of the Red-Black Tree: insertion, deletion, searching, minimum, maximum, predecessor, and successor.

Code Structure
RedBlackTree Class
The main data structure is encapsulated in the RedBlackTree class, which contains methods for managing the tree and its properties. The tree uses a sentinel node (TNULL) to represent leaf nodes, which helps simplify the implementation.

Key Functions
1. RedBlackTree()
The constructor initializes the sentinel node (TNULL) and sets the root to this sentinel node.

2. insert(int key)
Inserts a new node with the specified key into the Red-Black Tree. This method uses a helper function fixInsertImbalances() to handle any Red-Black Tree property violations after insertion.

3. fixInsertImbalances(RBNode* node)
After each insertion, this function is called to maintain Red-Black Tree properties. It performs rotations and recoloring to ensure the tree remains balanced.

4. delete_key(int key)
Deletes a node with the specified key from the Red-Black Tree. If the node exists, it uses delete_key_main(RBNode* node) to perform the deletion. Any imbalances created by the deletion are corrected by the fixDelete(RBNode* node) function.

5. delete_key_main(RBNode* node)
Handles the core deletion logic, ensuring that the deleted node is replaced in a way that maintains Red-Black Tree properties. It performs the actual transplant of nodes and calls fixDelete() to resolve any imbalances.

6. fixDelete(RBNode* node)
Corrects any property violations after deletion by performing rotations and recoloring. This function ensures that all Red-Black Tree properties are satisfied after a node is removed.

7. search(int key)
Searches the tree for a node with the specified key. This function calls a helper, searchMain(RBNode* node, int value), which recursively traverses the tree.

8. find_minimum()
Returns the minimum key in the tree by traversing to the leftmost node. This function uses a helper, find_minimum_main(RBNode* node).

9. find_maximum()
Returns the maximum key in the tree by traversing to the rightmost node. It calls the helper function find_maximum_main(RBNode* node).

10. find_predecessor(int value)
Finds and returns the predecessor of a node with the given value. This function uses find_predecessor_main(RBNode* node) to perform the traversal.

11. find_successor(int value)
Finds and returns the successor of a node with the given value. This function calls find_successor_main(RBNode* node).

12. select(int ind)
Returns the ind-th smallest element in the tree by performing an in-order traversal. It calls inorder_traversal() to get a sorted list of keys.

13. rank(int value)
Returns the rank (position in in-order traversal) of the specified value in the tree. This function performs a binary search on the sorted list obtained from inorder_traversal().

14. inorder_traversal()
Returns a vector containing an in-order traversal of the tree, which is a sorted sequence of keys. This function calls inorder_main() to populate the vector.

15. printTree()
A debugging utility that prints the structure of the tree in a visual format. It calls printMain(RBNode* root, string indent, bool last) to recursively print each node and its color (RED or BLACK).

Helper Functions
minimum(RBNode* node): Finds the minimum node in a subtree.
maximum(RBNode* node): Finds the maximum node in a subtree.
transplant(RBNode* u, RBNode* v): Replaces node u with node v in the tree.
printMain(RBNode* root, string indent, bool last): Helper for printTree() to print nodes with indentation.
binary_search(int num, vector<int> inorder_array): Binary search on a sorted vector to find the index of num.
Usage
To use the Red-Black Tree implementation, compile the code with a C++ compiler and run the main function provided in main.cpp. The main function demonstrates how to:

Insert nodes into the Red-Black Tree
Delete nodes
Print the tree structure
Find the minimum, maximum, predecessor, and successor of nodes
Perform in-order traversal
Retrieve the rank and select the k-th smallest element in the tree


int main() {
    RedBlackTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(2);
    tree.printTree();

    tree.delete_key(20);
    cout << "\nTree after deleting 20:\n";
    tree.printTree();

    cout << "In-order Traversal: ";
    vector<int> inorder = tree.inorder_traversal();
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Minimum: " << tree.find_minimum() << endl;
    cout << "Maximum: " << tree.find_maximum() << endl;
    cout << "Select (2nd smallest): " << tree.select(2) << endl;
    cout << "Rank (of 10): " << tree.rank(10) << endl;
    cout << "Predecessor of 10: " << tree.find_predecessor(10) << endl;
    cout << "Successor of 10: " << tree.find_successor(10) << endl;

    tree.delete_key(10);
    cout << "In-order Traversal after deletion: ";
    inorder = tree.inorder_traversal();
    for (int val : inorder) {
        cout << val << " ";
    }
    return 0;
}

This example demonstrates the main functions of the Red-Black Tree, showing how nodes are added, deleted, and queried for their properties.