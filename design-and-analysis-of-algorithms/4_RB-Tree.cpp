#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <iomanip>

#define INF std::numeric_limits<int>::max()

/* Red Black Tree implementation
 * This implementation uses the concept of a NIL node which is used as a sentinel (as described in CLRS)
 */

enum Color {
    RED, BLACK
};

struct Node {
    int key;
    Color color;
    Node *left, *right, *parent;
    Node(const int& key) {
        this->key = key;
        left = right = parent = nullptr;
    }
};

class RBTree {
public:
    Node* NIL;
    Node* root;
    RBTree() {
        NIL = new Node(INF);
        NIL->color = BLACK;
        // initially, root is simply a pointer to the NIL node, which has been allocated memory
        root = NIL; // tree only consists of the NIL node
    }

    void levelorder(Node* root) {
        if (root == NIL) return;

        int level = 0;

        // Use a queue for breadth-first traversal of the tree.  The pair is
        // to keep track of the depth of each node.  (Depth of root node is 1.)

        typedef std::pair<Node*,int> node_level;
        std::queue<node_level> q;
        q.push(node_level(root, 1));

        while (!q.empty()) {
            node_level nl = q.front();
            q.pop();

            if (NIL != (root = nl.first)) {
                if (level != nl.second) {
                    std::cout << "\n";
                    std::cout << "Level " << nl.second << ": ";
                    level = nl.second;
                }
                std::cout << root->key << "(";

                if(root->color == BLACK) std::cout << "B";
                else std::cout << "R";

                std::cout << ") ";

                q.push(node_level(root->left,  1 + level));
                q.push(node_level(root->right, 1 + level));
            }
        }
        std::cout << std::endl;
    }

    void inorder(Node* root) {
        if(root == NIL) return;
        inorder(root->left);

        std::cout << root->key << "(";

        if(root->color == BLACK) std::cout << "B";
        else std::cout << "R";

        std::cout << ") ";
        inorder(root->right);
    }

    void print_tree() {
        std::cout << "\nINORDER: ";
        inorder(root);
        std::cout << "\n";
        std::cout << "\nLEVEL ORDER:";
        levelorder(root);
        std::cout << "\n\n";
    }

    void print_node(Node* node) {
        std::cout << "\nNode: " << node->key << "\n";
        std::cout << "Color: ";
        if(node->color == BLACK) std::cout << "BLACK\n";
        else std::cout << "RED\n";

        std::cout << "Left child: ";
        if(node->left != nullptr) {
            if(node->left == NIL) std::cout << "NIL\n";
            else std::cout << node->left->key << "\n";
        } else std::cout << "NULL\n";

        std::cout << "Right child: ";
        if(node->right != nullptr) {
            if(node->right == NIL) std::cout << "NIL\n";
            else std::cout << node->right->key << "\n";
        } else std::cout << "NULL\n";

        std::cout << "Parent: ";
        if(node->parent != nullptr) {
            if(node->parent == NIL) std::cout << "NIL\n";
            else std::cout << node->parent->key << "\n";
        } else std::cout << "NULL\n\n";
    }

    void print_all_nodes(Node* root) {
        if(root == NIL) return;
        else {
            print_node(root);
            print_all_nodes(root->left);
            print_all_nodes(root->right);
        }
    }

    void LeftRotate(Node* x) {
        // assumes x->right != NIL
        if(x->right != NIL) {
            Node* y = x->right; // set y

            x->right = y->left; // turn y's left subtree into x's right subtree

            if(y->left != NIL) {
                y->left->parent = x;
            }

            y->parent = x->parent; // link x's parent to y

            if(x->parent == NIL) {
                root = y;
            }
            else if(x == x->parent->left) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }

            y->left = x;
            x->parent = y;
        }

    }

    void RightRotate(Node* y) {
        // assumes y->left != NIL

        if(y->left != NIL) {
            Node* x = y->left; // set y

            y->left = x->right; // turn x's right subtree into y's left subtree
            if(x->right != NIL) x->right->parent = y;
            x->parent = y->parent; // link y's parent to x

            if(y->parent == NIL) root = x;
            else if(y == y->parent->left) y->parent->left = x;
            else y->parent->right = x;

            x->right = y;
            y->parent = x;
        }

    }

    void BSTInsert(Node* z) {
        //std::cout << "(BSTInsert): Received a pointer to node " << z->key << ", pointer address: " << &z << "\n";

        Node* y = NIL;
        Node* x = root;

        //std::cout << "--Inserting " << key << "... root = " << x << " NIL = " << y << "\n";
        while(x != NIL) {
            y = x;
            if(z->key < x->key) x = x->left;
            else x = x->right;
        }

        z->parent = y;
        if(y == NIL) {
            root = z;
        }
        else if(z->key < y->key) y->left = z;
        else y->right = z;

        z->left = NIL;
        z->right = NIL;
        z->color = RED;
    }

    void RBInsertFixup(Node* z) {
        //std::cout << "(RBInsertFixup): Received a pointer to node " << z->key << ", pointer address: " << &z << "\n";

        /* possible violations when inserting a node colored RED
         * property 2 (root must be black), this is handled by simply setting the root to black
         * property 4 (red parent-black children)
        */

        Node* y = NIL;
        while (z != root && z->parent->color == RED) {
            // property 4 violation

            if(z->parent == z->parent->parent->left) {
                // parent of z is the left child of its parent

                y = z->parent->parent->right; // uncle

                if(y->color == RED) {
                    // CASE 1: UNCLE IS RED
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    // UNCLE IS BLACK

                    if(z == z->parent->right) {
                        // CASE 2: UNCLE IS BLACK, z is right child
                        z = z->parent;
                        LeftRotate(z);
                    }

                    // CASE 3: UNCLE IS BLACK, z is left child
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RightRotate(z->parent->parent);
                }
            }

            else {
                // parent of z is the right child of its parent

                y = z->parent->parent->left; // uncle

                if(y->color == RED) {
                    // CASE 1: UNCLE IS RED
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    // UNCLE IS BLACK

                    if(z == z->parent->left) {
                        // CASE 2: UNCLE IS BLACK, z is left child
                        z = z->parent;
                        RightRotate(z);
                    }

                    // CASE 3: UNCLE IS BLACK, z is right child
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    LeftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void RBInsert(const int& key) {
        Node* temp = new Node(key);
        //std::cout << "(RBInsert): Inserting node " << key << ", address of pointer: " << &temp << "\n";
        BSTInsert(temp);
        RBInsertFixup(temp);
    }

    Node* RBSearch(const int& key) {
        Node* temp = root;
        while(temp != NIL) {
            if(temp->key == key) return temp;
            else if(key < temp->key) temp = temp->left;
            else temp = temp->right;
        }
        return temp;
    }

    Node* TreeMinimum(Node* start) {
        Node* temp = start;
        while(temp->left != NIL) {
            temp = temp->left;
        }
        return temp;
    }

    Node* TreeMaximum(Node* start) {
        Node* temp = start;
        while(temp->right != NIL) {
            temp = temp->right;
        }
        return temp;
    }

    void RBTransplant(Node* u, Node* v) {
        if(u->parent == NIL) root = v;
        else if(u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;

    }

    void RBDeleteFixup(Node* x) {
        Node* w = NIL;

        while(x != root && x->color == BLACK) {

            if(x == x->parent->left) {
                // x is the left child
                w = x->parent->right; // sibling

                if(w->color == RED) {
                    // case 1: x's SIBLING w IS RED
                    // convert to case 2, 3, or 4 (sibling w is BLACK)
                    w->color = BLACK;
                    x->parent->color = RED;
                    LeftRotate(x->parent);
                    w = x->parent->right;
                }

                // x's sibling w is BLACK for cases 2, 3, 4

                if(w->left->color == BLACK && w->right->color == BLACK) {
                    // case 2: x's sibling w is black, both children of sibling are black
                    w->color = RED;
                    x = x->parent;
                }
                else if(w->right->color == BLACK) {
                    // case 3: x's sibling w is black, left child of w is red, right child of w is black
                    // convert to case 4: right child of w is red
                    w->left->color = BLACK;
                    w->color = RED;
                    RightRotate(w);
                    w = x->parent->right;
                }

                // case 4: x's sibling w is black, right child of w is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                LeftRotate(x->parent);
                x = root;
            }

            else {
                // x is the right child
                w = x->parent->left; // sibling

                if(w->color == RED) {
                    // case 1: x's SIBLING w IS RED
                    // convert to case 2, 3, or 4 (sibling w is BLACK)
                    w->color = BLACK;
                    x->parent->color = RED;
                    RightRotate(x->parent);
                    w = x->parent->left;
                }

                // x's sibling w is BLACK for cases 2, 3, 4

                if(w->right->color == BLACK && w->left->color == BLACK) {
                    // case 2: x's sibling w is black, both children of sibling are black
                    w->color = RED;
                    x = x->parent;
                }
                else {
                    if(w->left->color == BLACK) {
                        // case 3: x's sibling w is black, right child of w is red, left child of w is black
                        // convert to case 4: left child of w is red
                        w->right->color = BLACK;
                        w->color = RED;
                        LeftRotate(w);
                        w = x->parent->left;
                    }

                    // case 4: x's sibling w is black, left child of w is red
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    RightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void RBDelete(Node* z) {

        Node* y = z;
        Node* x = NIL;
        Color y_original_color = y->color;

        if(z->left == NIL) {
            x = z->right;
            RBTransplant(z, z->right);
        } else if(z->right == NIL) {
            x = z->left;
            RBTransplant(z, z->left);
        } else {
            y = TreeMinimum(z->right);
            y_original_color = y->color;
            x = y->right;

            if(y->parent == z) x->parent = y;
            else {
                RBTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            RBTransplant(z,y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        if(y_original_color == BLACK) RBDeleteFixup(x);
    }

    void delete_BST(Node* root) {
        if(root == NIL) return;
        else {
            delete_BST(root->left);
            delete_BST(root->right);
            //std::cout << "Deleted " << root->key << "\n";
            delete root;
        }
    }

    void delete_BST_helper() {
        Node* temp = root;
        delete_BST(temp);
        root = NIL;
    }

    ~RBTree() {
        delete_BST_helper();
        delete NIL;
    }
};

int main() {
    RBTree rb;

    // 11 2 14 1 7 15 5 8 4
    std::cout << "Red-Black Tree\n";
    std::cout << "1. Insert an element.\n";
    std::cout << "2. Delete an element.\n";
    std::cout << "3. Search for an element.\n";
    std::cout << "4. Print tree's inorder and levelorder traversal.\n";
    std::cout << "5. Delete the entire tree.\n";
    std::cout << "6. Exit.\n";
    int choice;
    char ans = 'y';
    while(true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                    std::cout << "(Insertion mode) Enter number of elements to insert: ";
                    int num1, element1;
                    std::cin >> num1;
                    std::cout << "Enter " << num1 << " elements to insert: ";
                    while(num1--) {
                        std::cin >> element1;
                        rb.RBInsert(element1);
                    }

                    std::cout << "Inorder and levelorder traversals of updated tree:\n";
                    rb.print_tree();
                    break;
            }
            case 2: {
                    std::cout << "(Deletion mode) Enter element to delete: ";
                    int element2;
                    std::cin >> element2;
                    Node* search_result2 = rb.RBSearch(element2);
                    if(search_result2 != rb.NIL) {
                        rb.RBDelete(search_result2);
                        delete search_result2; // delete the actual node
                    } else std::cout << "No such element exists!\n";
                    std::cout << "Inorder and levelorder traversals of updated tree:\n";
                    rb.print_tree();
                    break;
            }
            case 3: {
                    std::cout << "(Searching mode) Enter an element to search: ";
                    int element3;
                    std::cin >> element3;
                    Node* search_result = rb.RBSearch(element3);
                    if(search_result != rb.NIL) {
                        std::cout << "Element found!\n";
                        rb.print_node(search_result);
                    } else std::cout << "No such element exists!\n";
                    break;
            }
            case 4: rb.print_tree(); break;
            case 5: rb.delete_BST_helper();
                    std::cout << "Inorder and levelorder traversals of updated tree:\n";
                    rb.print_tree(); break;
            case 6: return 0;
            default: std::cout << "Invalid option!\n";
        }
    }
}
