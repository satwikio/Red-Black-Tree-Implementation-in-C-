# Red-Black Tree Implementation in C++

This repository contains a C++ implementation of a **Red-Black Tree**, a type of balanced binary search tree. Red-Black Trees ensure efficient insertions, deletions, and lookups with $O(\log n)$ time complexity for each operation.

## Features

- **Insertion**: Adds a new node while maintaining tree balance.
- **Deletion**: Removes a node and ensures the tree remains balanced.
- **Search**: Finds a node with a specific key.
- **Minimum/Maximum**: Retrieves the minimum and maximum keys.
- **Predecessor/Successor**: Finds adjacent keys for a given node.
- **Traversal**: In-order traversal for retrieving all keys in sorted order.
- **Rank and Select**: Supports order statistics.

## Project Structure

- **RedBlackTree Class**: Core class implementing the Red-Black Tree and its operations.
- **Key Methods**:
  - `insert(int key)`: Inserts a node with the given key.
  - `delete_key(int key)`: Deletes a node with the given key.
  - `search(int key)`: Searches for a node with the specified key.
  - `find_minimum()` and `find_maximum()`: Retrieves the minimum and maximum keys.
  - `find_predecessor(int value)` and `find_successor(int value)`: Finds predecessor and successor.
  - `inorder_traversal()`: Returns keys in sorted order.
  - `rank(int value)` and `select(int ind)`: Finds the rank and selects the k-th smallest element.

## Red-Black Tree Properties

A Red-Black Tree follows these rules:

1. Every node is either red or black.
2. The root is always black.
3. All leaves (sentinel nodes) are black.
4. Red nodes cannot have red children (no two red nodes in a row).
5. Every path from a node to its descendant leaves has the same number of black nodes.

These properties ensure the tree is balanced and maintains $O(\log n)$ height.

## Example Usage

Below is a sample code snippet that demonstrates how to use the Red-Black Tree implementation.

```cpp
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

    return 0;
}
```




## Mathematical Complexity

Red-Black Trees have a height of $O(\log n)$, which guarantees efficient operations. This ensures the time complexity for **search**, **insertion**, and **deletion** is $O(\log n)$ in the worst case.

## How to Run

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/Red-Black-Tree-Implementation-in-Cpp.git
   ```
Navigate into the project directory:

```bash
cd Red-Black-Tree-Implementation-in-Cpp
```

Compile and run the code:
```bash
g++ main.cpp -o RedBlackTree
./RedBlackTree
```
This will execute the sample code in main.cpp, demonstrating the Red-Black Tree operations.