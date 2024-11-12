// #include <iostream>
// #include <vector>
// using namespace std;

// bool red = 1;
// bool black = 0;

// struct RBNode
// {
//     int key;
//     RBNode* left = nullptr;
//     RBNode* right = nullptr;
//     RBNode* parent = nullptr;
//     bool color = red;
//     RBNode(int value) : key(value){}
// };

// class RedBlackTree{
//     RBNode* root;
//     RBNode* TNULL;

//     private :
    
//     void rightRotation(RBNode* node){
//         if (node == nullptr || node->left == nullptr){
//             return;
//         }

//         RBNode* leftNode = node->left;
//         node->left = leftNode->right;
//         if(leftNode->right != nullptr){
//             leftNode->right->parent = node;
//         }
        
//         leftNode->parent = node->parent;
//         if(node->parent == nullptr){
//             root = leftNode;  
//         }
        
//         else if(node->parent->left == node){
//             node->parent->left = leftNode;
//         }

//         else{
//             node->parent->right = leftNode;
//         }
//         leftNode->right = node;
//         node->parent = leftNode;

//     }

//     void leftRotation(RBNode* node){
//         if(node == nullptr){
//             return;
//         }

//         RBNode* rightNode = node->right;
//         node->right = rightNode->left;
//         if(rightNode->left != nullptr){
//             rightNode->left->parent = node;
//         }
//         rightNode->parent = node->parent;
//         if(node->parent == nullptr){
//             root = rightNode;
//         }
//         else if(node->parent->left == node){
//             node->parent->left = rightNode;
//         } 
//         else{node->parent->right = rightNode;}

//         node->parent = rightNode;
//         rightNode->left = node;
//     }

//     RBNode* findNode (int value){
//         RBNode* node = root;
//         while(node != nullptr){
//             if (value == node->key){return node;}
//             else if (value > node->key){
//                 node = node->right;
//             }
//             else{
//                 node = node->left;
//             }
//         }
//         if (node==nullptr){cout<<"This element is not present in the RB."<<endl;}
//         return node;
//         }

//     void fixInsertImbalances(RBNode* node){
//         while(node != root && node->parent->color == red){
//             if(node->parent->parent->left == node->parent){
//                 RBNode* uncle = node->parent->parent->right;
//                 if(uncle != nullptr && uncle->color == red){
//                     node->parent->color = black;
//                     node->parent->parent->color = red;
//                     uncle->color = black;
//                     node = node->parent->parent;
//                 }
//                 else{
//                     if(node->parent->right == node){
//                         node = node->parent;
//                         leftRotation(node);
//                     }
//                     node->parent->parent->color = red;
//                     node->parent->color = black;
//                     rightRotation(node->parent->parent);
//                 }
//             }
//             else{
//                 RBNode* uncle = node->parent->parent->left;
//                 if(uncle != nullptr && uncle->color == red){
//                     node->parent->color = black;
//                     node->parent->parent->color = red;
//                     uncle->color = black;
//                     node = node->parent->parent;
//                 }
//                 else{
//                     if(node->parent->left == node){
//                         node = node->parent;
//                         rightRotation(node);
//                     }
//                     node->parent->parent->color = red;
//                     node->parent->color = black;
//                     leftRotation(node->parent->parent);
//                 }
//             }
//         }
//         root->color = black;
//     }

//     void transplant(RBNode* u, RBNode* v) {
//         if (u->parent == nullptr)
//             root = v;
//         else if (u == u->parent->left)
//             u->parent->left = v;
//         else
//             u->parent->right = v;
//         if (v != nullptr)
//             v->parent = u->parent;
//     }

//     RBNode* minimum(RBNode* node) {
//         while (node->left != nullptr)
//             node = node->left;
//         return node;
//     }

//     void delete_key_main(RBNode* node){
//         RBNode* succ_right;

//         if (node == nullptr){
//             cout<<"Eantered key not found"<<endl;
//         }

//         RBNode* nodeCopy = node;
//         bool nodeColor = node->color;

//         //Case 1 
//         if (node->left == nullptr){
//             transplant(node, node->right);
//         }

//         //Case 2
//         else if (node->right == nullptr){
//             transplant(node, node->left);
//         }

//         //Case 3
//         else{
//             RBNode* succ = minimum(node->right);
//             bool color_succ = succ->color;
//             RBNode* succ_right = succ->right;

//             if(succ->parent != node){
//                 transplant(succ, succ_right);
//                 succ->right = node->right;
//                 succ->right->parent = succ;
//             }

//             transplant(node, succ);
//             succ->left = node->left;
//             succ->left->parent = succ;
//             succ->color = node->color;
//         }

//         if (nodeColor == black){
//             fixDelete(succ_right);
//         }
//     }

//     void fixDelete(RBNode* node){
//         while (node != root && node->color == black){
//             if (node == node->parent->left){
//                 RBNode* sibling = node->parent->right;
//                 //type 1
//                 if(sibling->color == red){
//                     sibling->color = black;
//                     node->parent->color = red;
//                     leftRotation(node->parent);
//                     sibling = node->parent->right;
//                 }
//                 //type 2
//                 if(sibling->left->color == black && sibling->right->color == black){
//                     sibling->color = red;
//                     node = node->parent;
//                 }
//                 else{
//                     //type 3
//                     if(sibling->right->color == black){
//                         sibling->left->color = black;
//                         sibling->color = red;
//                         rightRotation(sibling);
//                         sibling = node->parent->right;
//                     }
//                     //type 4
//                     sibling->color = node->parent->color;
//                     node->parent->color = black;
//                     sibling->right->color = black;
//                     leftRotation(node->parent);
//                     node = root;
//                 }
//             }
//             else{
//                 RBNode* sibling = node->parent->left;
//                 //type 1
//                 if (sibling->color == red){
//                     sibling->color = black;
//                     node->parent->color = red;
//                     rightRotation(node->parent);
//                     sibling = node->parent->left;
//                 }
//                 //type 2
//                 if(sibling->right->color == black && sibling->left->color == black){
//                     sibling->color = red;
//                     node = node->parent;
//                 }
//                 else{
//                     //type 3
//                     if(sibling->left->color == black){
//                         sibling->right->color = black;
//                         sibling->color = red;
//                         leftRotation(sibling);
//                         sibling = node->parent->left;
//                     }
//                 //type 4
//                 sibling->color = node->parent->color;
//                 node->parent->color = black;
//                 sibling->left->color = black;
//                 rightRotation(node->parent);
//                 node = root;
//                 }
//             }
//         }
//         node->color = black;
//     }


//     public:
//     RedBlackTree() {
//         TNULL = new RBNode(0);
//         TNULL->color = black;
//         root = TNULL;
//     }

//     void insert(int key) {
//         RBNode* node = new RBNode(key);
//         node->parent = nullptr;
//         node->key = key;
//         node->left = TNULL;
//         node->right = TNULL;
//         node->color = red;

//         RBNode* y = nullptr;
//         RBNode* x = root;

//         while (x != TNULL) {
//             y = x;
//             if (node->key < x->key) {
//                 x = x->left;
//             } else {
//                 x = x->right;
//             }
//         }

//         node->parent = y;
//         if (y == nullptr) {
//             root = node;
//         } else if (node->key < y->key) {
//             y->left = node;
//         } else {
//             y->right = node;
//         }

//         if (node->parent == nullptr) {
//             node->color = black;
//             return;
//         }

//         if (node->parent->parent == nullptr) {
//             return;
//         }

//         fixInsertImbalances(node);
//     }


//     void delete_key(int value){
//         RBNode* node = findNode(value);
//         delete_key_main(node);
//     }

// };

#include <iostream>
#include <vector>
using namespace std;

// Define colors for nodes
bool red = 1;
bool black = 0;

// Structure representing a Red-Black Tree Node
struct RBNode {
    int key;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    bool color;

    RBNode(int value) : key(value), left(nullptr), right(nullptr), parent(nullptr), color(red) {}
};

class RedBlackTree {
private:
    RBNode* root;     // Pointer to the root node of the Red-Black Tree
    RBNode* TNULL;    // Sentinel node representing null leaves (used for leaf nodes)

    // Right rotation around a given node
    void rightRotation(RBNode* node) {
        RBNode* leftNode = node->left;         // Temporary pointer to hold node's left child
        node->left = leftNode->right;          // Move leftNode's right child to be node's left child

        // Update the parent reference if leftNode's right child is not TNULL
        if (leftNode->right != TNULL) {
            leftNode->right->parent = node;
        }

        // Update the parent of leftNode to node's parent
        leftNode->parent = node->parent;

        // If node is the root, update root pointer to leftNode
        if (node->parent == nullptr) {
            root = leftNode;
        } 
        // Otherwise, update the left or right child of node's parent to leftNode
        else if (node == node->parent->left) {
            node->parent->left = leftNode;
        } else {
            node->parent->right = leftNode;
        }

        // Make node the right child of leftNode and update node's parent
        leftNode->right = node;
        node->parent = leftNode;
    }

    // Left rotation around a given node
    void leftRotation(RBNode* node) {
        RBNode* rightNode = node->right;       // Temporary pointer to hold node's right child
        node->right = rightNode->left;         // Move rightNode's left child to be node's right child

        // Update the parent reference if rightNode's left child is not TNULL
        if (rightNode->left != TNULL) {
            rightNode->left->parent = node;
        }

        // Update the parent of rightNode to node's parent
        rightNode->parent = node->parent;

        // If node is the root, update root pointer to rightNode
        if (node->parent == nullptr) {
            root = rightNode;
        } 
        // Otherwise, update the left or right child of node's parent to rightNode
        else if (node == node->parent->left) {
            node->parent->left = rightNode;
        } else {
            node->parent->right = rightNode;
        }

        // Make node the left child of rightNode and update node's parent
        rightNode->left = node;
        node->parent = rightNode;
    }

    // Fix imbalances after insertion to maintain Red-Black Tree properties
    void fixInsertImbalances(RBNode* node) {
        // Loop until the root is reached or node's parent is black (no imbalance)
        while (node != root && node->parent->color == red) {
            // Case where node's parent is the left child of node's grandparent
            if (node->parent == node->parent->parent->left) {
                RBNode* uncle = node->parent->parent->right;  // Get the "uncle" (right child of grandparent)

                if (uncle->color == red) {                    // Case 1: Uncle is red (recoloring case)
                    node->parent->color = black;              // Recolor parent to black
                    uncle->color = black;                     // Recolor uncle to black
                    node->parent->parent->color = red;        // Recolor grandparent to red
                    node = node->parent->parent;              // Move up the tree to check grandparent
                } else {
                    if (node == node->parent->right) {        // Case 2: Node is right child (left rotation case)
                        node = node->parent;                  // Move node up to its parent
                        leftRotation(node);                   // Rotate left around parent
                    }
                    // Case 3: Node is left child (right rotation case)
                    node->parent->color = black;              // Recolor parent to black
                    node->parent->parent->color = red;        // Recolor grandparent to red
                    rightRotation(node->parent->parent);      // Rotate right around grandparent
                }
            } else {
                // Symmetric logic for the right subtree (mirror cases)
                RBNode* uncle = node->parent->parent->left;   // Get the "uncle" (left child of grandparent)

                if (uncle->color == red) {                    // Case 1: Uncle is red (recoloring case)
                    node->parent->color = black;              // Recolor parent to black
                    uncle->color = black;                     // Recolor uncle to black
                    node->parent->parent->color = red;        // Recolor grandparent to red
                    node = node->parent->parent;              // Move up the tree to check grandparent
                } else {
                    if (node == node->parent->left) {         // Case 2: Node is left child (right rotation case)
                        node = node->parent;                  // Move node up to its parent
                        rightRotation(node);                  // Rotate right around parent
                    }
                    // Case 3: Node is right child (left rotation case)
                    node->parent->color = black;              // Recolor parent to black
                    node->parent->parent->color = red;        // Recolor grandparent to red
                    leftRotation(node->parent->parent);       // Rotate left around grandparent
                }
            }
        }

        // Ensure the root node is always black to satisfy Red-Black Tree properties
        root->color = black;
    }

        // Find the node with the minimum key in a given subtree
    RBNode* minimum(RBNode* node) {
        // Traverse left subtree until reaching the leftmost node
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;  // Return the node with the minimum key
    }

    // Transplant node u with node v in the tree (replace u with v)
    void transplant(RBNode* u, RBNode* v) {
        if (u->parent == nullptr) {
            root = v;  // If u is the root, set v as the new root
        } else if (u == u->parent->left) {
            u->parent->left = v;  // If u is the left child, update parent's left child to v
        } else {
            u->parent->right = v;  // If u is the right child, update parent's right child to v
        }
        v->parent = u->parent;  // Set v's parent to u's parent
    }

    // Fix violations after deletion to maintain Red-Black Tree properties
    void fixDelete(RBNode* node) {
        while (node != root && node->color == black) {  // Continue until node is root or red
            if (node == node->parent->left) {  // Node is the left child
                RBNode* sibling = node->parent->right;  // Get the sibling (right child of parent)
                
                if (sibling->color == red) {  // Case 1: Sibling is red
                    sibling->color = black;  // Recolor sibling to black
                    node->parent->color = red;  // Recolor parent to red
                    leftRotation(node->parent);  // Left rotate around parent
                    sibling = node->parent->right;  // Update sibling after rotation
                }

                if (sibling->left->color == black && sibling->right->color == black) {
                    // Case 2: Both of sibling's children are black
                    sibling->color = red;  // Recolor sibling to red
                    node = node->parent;  // Move node up the tree
                } else {
                    if (sibling->right->color == black) {
                        // Case 3: Sibling's right child is black
                        sibling->left->color = black;  // Recolor left child of sibling to black
                        sibling->color = red;  // Recolor sibling to red
                        rightRotation(sibling);  // Right rotate around sibling
                        sibling = node->parent->right;  // Update sibling after rotation
                    }

                    // Case 4: Sibling's right child is red
                    sibling->color = node->parent->color;  // Match sibling's color to parent's color
                    node->parent->color = black;  // Recolor parent to black
                    sibling->right->color = black;  // Recolor sibling's right child to black
                    leftRotation(node->parent);  // Left rotate around parent
                    node = root;  // Set node to root to end the loop
                }
            } else {  // Symmetric case: Node is the right child
                RBNode* sibling = node->parent->left;

                if (sibling->color == red) {  // Case 1: Sibling is red
                    sibling->color = black;
                    node->parent->color = red;
                    rightRotation(node->parent);
                    sibling = node->parent->left;
                }

                if (sibling->left->color == black && sibling->right->color == black) {
                    sibling->color = red;
                    node = node->parent;
                } else {
                    if (sibling->left->color == black) {
                        sibling->right->color = black;
                        sibling->color = red;
                        leftRotation(sibling);
                        sibling = node->parent->left;
                    }

                    sibling->color = node->parent->color;
                    node->parent->color = black;
                    sibling->left->color = black;
                    rightRotation(node->parent);
                    node = root;
                }
            }
        }
        node->color = black;  // Ensure node is black at the end
    }

    // Main function for deleting a node by key
    void delete_key_main(RBNode* node) {
        RBNode* y = node;  // Temporary pointer for node to be deleted
        RBNode* x;         // Pointer to child that will replace y
        bool y_original_color = y->color;  // Save original color of y

        if (node->left == TNULL) {  // Case: Node has only a right child
            x = node->right;  // Set x to right child
            transplant(node, node->right);  // Transplant node with its right child
        } else if (node->right == TNULL) {  // Case: Node has only a left child
            x = node->left;  // Set x to left child
            transplant(node, node->left);  // Transplant node with its left child
        } else {  // Node has two children
            y = minimum(node->right);  // Find minimum in node's right subtree
            y_original_color = y->color;  // Save color of y
            x = y->right;  // Set x to y's right child
            if (y->parent == node) {  // If y is the direct child of node
                x->parent = y;  // Set x's parent to y
            } else {
                transplant(y, y->right);  // Transplant y with its right child
                y->right = node->right;  // Set y's right child to node's right child
                y->right->parent = y;  // Update parent of node's right child
            }
            transplant(node, y);  // Replace node with y
            y->left = node->left;  // Set y's left child to node's left child
            y->left->parent = y;  // Update parent of node's left child
            y->color = node->color;  // Preserve original color of node
        }
        delete node;  // Delete the original node
        if (y_original_color == black) {  // If y was black, fix delete imbalances
            fixDelete(x);
        }
    }


        // Recursive function to print the tree structure
    void printMain(RBNode* root, string indent, bool last) {
        if (root != TNULL) { // Continue if the node is not the sentinel node
            cout << indent;
            if (last) {
                cout << "R----";      // Print "R----" for right child nodes
                indent += "   ";      // Add indentation for visual structure
            } else {
                cout << "L----";      // Print "L----" for left child nodes
                indent += "|  ";      // Add indentation for visual structure
            }

            string sColor = root->color ? "RED" : "BLACK";  // Determine color of node
            cout << root->key << "(" << sColor << ")" << endl; // Print node key and color
            printMain(root->left, indent, false);  // Recursively print left subtree
            printMain(root->right, indent, true);  // Recursively print right subtree
        }
    }

    // Search function to find a value in the Red-Black Tree
    bool searchMain(RBNode* node, int value) {
        if (node == nullptr) {   // If node is null, return false (value not found)
            return false;
        } else if (value == node->key) {  // If node key matches value, return true
            return true;
        } else if (value < node->key) {   // If value is smaller, search left subtree
            return searchMain(node->left, value);
        } else {                          // If value is larger, search right subtree
            return searchMain(node->right, value);
        }
    }

    // Function to find the node with the minimum key in a subtree
    RBNode* find_minimum_main(RBNode* node) {
        if (node == TNULL) {  // If node is TNULL, no data is present
            cout << "No data in the RB" << endl;
            return nullptr;   // Return nullptr as indicator
        }
        if (node->left == TNULL) { // If node has no left child, it is the minimum node
            return node;
        }
        return find_minimum_main(node->left);  // Recursively traverse left subtree
    }

    // Function to find the node with the maximum key in a subtree
    RBNode* find_maximum_main(RBNode* node) {
        if (node == TNULL) {  // If node is TNULL, no data is present
            cout << "No data in the RB" << endl;
            return nullptr;   // Return nullptr as indicator
        }
        if (node->right == TNULL) { // If node has no right child, it is the maximum node
            return node;
        }
        return find_maximum_main(node->right);  // Recursively traverse right subtree
    }

    // Recursive in-order traversal to fill a vector with node keys
    void inorder_main(vector<int>& inorder_vector, RBNode* node) {
        if (node != TNULL) {  // If node is not TNULL, continue traversal
            inorder_main(inorder_vector, node->left);    // Traverse left subtree
            inorder_vector.push_back(node->key);         // Add node's key to vector
            inorder_main(inorder_vector, node->right);   // Traverse right subtree
        }
    }

    // Function to find the successor of a given node
    RBNode* find_successor_main(RBNode* node) {
        if (node->right != TNULL) {  // If right child exists, find minimum in right subtree
            return find_minimum_main(node->right);
        } else {
            // Traverse up the tree until we find a node that is the left child of its parent
            while (node->parent != TNULL && node->parent->left != node) {
                node = node->parent;  // Move up to the parent
            }
        }
        return node;  // Return the successor node
    }

    // Function to find the predecessor of a given node
    RBNode* find_predecessor_main(RBNode* node) {
        if (node->left != TNULL) {  // If left child exists, find maximum in left subtree
            return find_maximum_main(node->left);
        } else {
            // Traverse up the tree until we find a node that is the right child of its parent
            while (node->parent != TNULL && node->parent->right != node) {
                node = node->parent;  // Move up to the parent
            }
        }
        return node;  // Return the predecessor node
    }


public:
    // Constructor for initializing the Red-Black Tree
    RedBlackTree() {
        TNULL = new RBNode(0);     // Create the sentinel (TNULL) node
        TNULL->color = black;      // Set sentinel node color to black
        root = TNULL;              // Initialize root to TNULL
    }

    // Function to insert a new key into the Red-Black Tree
    void insert(int key) {
        RBNode* node = new RBNode(key);  // Create a new node with the given key
        node->parent = nullptr;
        node->left = TNULL;              // Set left and right children to TNULL
        node->right = TNULL;

        RBNode* y = nullptr;             // Temporary pointer to hold the parent node
        RBNode* x = root;                // Start from the root node

        // Traverse the tree to find the insertion point
        while (x != TNULL) {
            y = x;
            if (node->key < x->key) {
                x = x->left;             // Move left if the new key is smaller
            } else {
                x = x->right;            // Move right if the new key is larger
            }
        }

        // Set the parent of the new node to y
        node->parent = y;
        if (y == nullptr) {              // If y is null, the tree was empty
            root = node;                 // Set new node as the root
        } else if (node->key < y->key) {
            y->left = node;              // Insert as left child if key is smaller
        } else {
            y->right = node;             // Insert as right child if key is larger
        }

        // If the new node is root, set its color to black and return
        if (node->parent == nullptr) {
            node->color = black;
            return;
        }

        // Fix Red-Black Tree property violations caused by the insertion
        fixInsertImbalances(node);
    }

    // Function to search for a key in the Red-Black Tree
    bool search(int key) {
        return searchMain(root, key);    // Call helper function starting from root
    }

    // Function to find the minimum key in the tree
    int find_minimum() {
        RBNode* minNode = find_minimum_main(root); // Find minimum node starting from root
        return minNode->key;                       // Return the key of the minimum node
    }

    // Function to find the maximum key in the tree
    int find_maximum() {
        RBNode* maxNode = find_maximum_main(root); // Find maximum node starting from root
        return maxNode->key;                       // Return the key of the maximum node
    }

    // Function to find a node with a specific key
    RBNode* findNode(int value) {
        RBNode* current = root;           // Start searching from the root
        while (current != TNULL) {        // Continue until TNULL is reached
            if (current->key == value) return current;  // Return node if key is found
            current = (value < current->key) ? current->left : current->right; // Traverse
        }
        return TNULL;                     // Return TNULL if key is not found
    }

    // Function to delete a node with a given key
    void delete_key(int key) {
        RBNode* node = findNode(key);    // Find node with the specified key
        if (node != TNULL)
            delete_key_main(node);       // Call main deletion function if found
        else
            cout << "Key not found in the tree\n";  // Print message if key not found
    }

    // Function to find the predecessor of a node with a given key
    int find_predecessor(int value) {
        RBNode* node = findNode(value);             // Find node with the specified key
        return find_predecessor_main(node)->key;    // Return predecessor node's key
    }

    // Function to find the successor of a node with a given key
    int find_successor(int value) {
        RBNode* node = findNode(value);             // Find node with the specified key
        return find_successor_main(node)->key;      // Return successor node's key
    }
    
    // Function to select the k-th smallest element in the tree
    int select(int ind) {
        vector<int> inorder_array = inorder_traversal();  // Get in-order traversal vector
        return inorder_array[ind];                        // Return the k-th element
    }

    // Binary search on the in-order traversal array
    int binary_search(int num, vector<int> inorder_array) {
        int left = 0;
        int right = inorder_array.size() - 1;

        // Standard binary search implementation
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (num == inorder_array[mid]) {
                return mid;                   // Return index if found
            } else if (num > inorder_array[mid]) {
                left = mid + 1;               // Move right if num is greater
            } else {
                right = mid - 1;              // Move left if num is smaller
            }
        }
        return -1;  // Return -1 if not found
    }

    // Function to find the rank of a value in the tree
    int rank(int value) {
        vector<int> inorder_array = inorder_traversal(); // Get in-order traversal vector
        return binary_search(value, inorder_array);      // Return index of value in traversal
    }

    // In-order traversal to return a sorted vector of keys
    vector<int> inorder_traversal() {
        vector<int> inorder_vector;                // Vector to store the keys
        inorder_main(inorder_vector, root);        // Populate vector with in-order traversal
        return inorder_vector;                     // Return the sorted vector
    }

    // Helper function to print the tree structure for debugging
    void printTree() {
        if (root != TNULL) {                       // If tree is not empty
            printMain(root, "", true);             // Print the tree structure
        }
    }
    
};


int main() {
    RedBlackTree tree;               // Initialize a Red-Black Tree instance
    
    // Insert nodes into the Red-Black Tree
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(2);
    
    // Print the tree structure after initial insertions
    tree.printTree();

    // Delete the node with key 20 from the tree
    tree.delete_key(20);

    // Print the tree structure after deletion of key 20
    cout << "\nTree after deleting 20:\n";
    tree.printTree();

    // Perform in-order traversal and display the result
    cout << "In-order Traversal: ";
    vector<int> inorder = tree.inorder_traversal();
    for (int val : inorder) {
        cout << val << " ";         // Print each element in the in-order traversal
    }
    cout << endl;

    // Find and display the minimum key in the tree
    cout << "Minimum: " << tree.find_minimum() << endl;

    // Find and display the maximum key in the tree
    cout << "Maximum: " << tree.find_maximum() << endl;

    // Select and display the 2nd smallest element in the tree
    cout << "Select (2nd smallest): " << tree.select(2) << endl;

    // Find and display the rank of the key 10 in the tree
    cout << "Rank (of 10): " << tree.rank(10) << endl;

    // Find and display the predecessor of the key 10
    cout << "Predecessor of 10: " << tree.find_predecessor(10) << endl;

    // Find and display the successor of the key 10
    cout << "Successor of 10: " << tree.find_successor(10) << endl;

    // Delete the node with key 10 from the tree
    tree.delete_key(10);

    // Perform in-order traversal after deletion and display the result
    cout << "In-order Traversal after deletion: ";
    inorder = tree.inorder_traversal();
    for (int val : inorder) {
        cout << val << " ";         // Print each element in the updated in-order traversal
    }
    return 0;                       // Exit the program
}
