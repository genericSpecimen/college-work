#include <iostream>
#include <queue>

template<class T>
class Queue : public std::queue<T> {
public:
    T dequeue() {
        T tmp = std::queue<T>::front();
        std::queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el) {
        this->push(el);
    }
};

template <class T>
class BSTNode {
public:
    T element;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode() {
        left = right = 0;
    }
    BSTNode(const T& element, BSTNode<T>* left = 0, BSTNode<T>* right = 0) {
        this->element = element;
        this->left = left;
        this->right = right;
    }
};

template<class T>
class BST {
protected:
    BSTNode<T>* root;
    void preorder(BSTNode<T>* p) {
        if(p != 0) {
            visit(p);
            preorder(p->left);
            preorder(p->right);
        }
    }
    void inorder(BSTNode<T>* p) {
        if(p != 0) {
            inorder(p->left);
            visit(p);
            inorder(p->right);
        }
    }
    void postorder(BSTNode<T>* p) {
        if(p != 0) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
        }
    }
    T* search(BSTNode<T>* p, const T& el) const {
        while(p != 0) {
        if(el == p->element) return &p->element;
        else if(el < p->element) p = p->left;
        else p = p->right;
        }
        return NULL;
    };
    void visit(BSTNode<T>* p) {
        std::cout << p->element << ' ';
    }
    int height(BSTNode<T>* p) {
        if(p == NULL) return 0;
        int left_tree_height = height(p->left);
        int right_tree_height = height(p->right);
        return left_tree_height > right_tree_height ? left_tree_height+1 : right_tree_height+1;
    }
    int num_leaves(BSTNode<T>* p) {
        if(p == NULL) return 0;
        else if(p->left == NULL && p->right == NULL) return 1;
        else return num_leaves(p->left)+num_leaves(p->right);
    }
    int num_non_leaves(BSTNode<T>* p) {
        if(p == NULL || p->left == NULL && p->right == NULL) return 0;
        else return 1 + num_non_leaves(p->left) + num_non_leaves(p->right);
    }
    void mirror(BSTNode<T>* p) {
        if(p != NULL) {
            mirror(p->left);
            mirror(p->right);
            BSTNode<T>* temp = p->left;
            p->left = p->right;
            p->right = temp;
        }
    }
    void clear(BSTNode<T>* p) {
        if(p != NULL) {
            clear(p->left);
            clear(p->right);
            delete p;
        }
    }
public:
    BST() {
        root = 0;
    }
    ~BST() {
        clear(root); root = NULL;
    }
    bool isEmpty() const {
        return root == 0;
    }
    void preorder() {
        preorder(root);
    }
    void inorder() {
        inorder(root);
    }
    void postorder() {
        postorder(root);
    }
    T* search(const T& el) const {
        return search(root, el);
    }
    void breadthFirst() {
        Queue<BSTNode<T>*> queue;
        BSTNode<T>* p = root;
        if(p != 0) {
            queue.enqueue(p);
            while(!queue.empty()) {
                p = queue.dequeue();
                visit(p);
                if(p->left != 0) queue.enqueue(p->left);
                if(p->right != 0) queue.enqueue(p->right);
            }
        }
    }

    void insert(const T& el) {
        BSTNode<T>* p = root;
        BSTNode<T>* prev = 0;
        while(p != 0) {
            prev = p;
            if(el < p->element) p = p->left;
            else p = p->right;
        }
        if(root == 0) root = new BSTNode<T>(el);
        else if(el < prev->element) prev->left = new BSTNode<T>(el);
        else prev->right = new BSTNode<T>(el);
    }
    void deleteByMerging(BSTNode<T>*& node) {
        BSTNode<T>* temp = node;
        if(node != 0) {
            if(node->right == 0) node = node->left;
            else if(node->left == 0) node = node->right;
            else {
                //merge subtrees
                temp = node->left; //move left
                while(temp->right != 0) temp = temp->right; //go right as far as possible
                temp->right = node->right;

                temp = node;
                node = node->left;
            }
            delete temp;
        }
    }
    void findAndDeleteByMerging(const T& el) {
        BSTNode<T>* node = root;
        BSTNode<T>* prev = 0;
        while(node != 0) {
            if(node->element == el) break;
            prev = node;
            if(el < node->element) node = node->left;
            else node = node->right;
        }
        if(node != 0 && node->element == el) {
            if(node == root) deleteByMerging(root);
            else if(prev->left == node) deleteByMerging(prev->left);
            else deleteByMerging(prev->right);
        }
        else if(root != 0) std::cout << "Element " << el << " is not in the tree\n";
        else std::cout << "The tree is emoty\n";
    }
    void deleteByCopying(BSTNode<T>*& node) {
        BSTNode<T>* prev;
        BSTNode<T>* temp = node;
        if(node->right == 0) node = node->left;
        else if(node->left == 0) node = node->right;
        else {
            temp = node->left;
            prev = node;
            while(temp->right != 0) {
                prev = temp;
                temp = temp->right;
            }
            node->element = temp->element;
            if(prev == node) prev->left = temp->left;
            else prev->right == temp->left;
        }
        delete temp;
    }
    void findAndDeleteByCopying(const T& el) {
        BSTNode<T>* node = root;
        BSTNode<T>* prev = 0;
        while(node != 0) {
            if(node->element == el) break;
            prev = node;
            if(el < node->element) node = node->left;
            else node = node->right;
        }
        if(node != 0 && node->element == el) {
            if(node == root) deleteByCopying(root);
            else if(prev->left == node) deleteByCopying(prev->left);
            else deleteByCopying(prev->right);
        }
        else if(root != 0) std::cout << "Element " << el << " is not in the tree\n";
        else std::cout << "The tree is emoty\n";
    }

    int height() {
        return height(root);
    }

    int num_leaves() {
        return num_leaves(root);
    }

    int num_non_leaves() {
        return num_non_leaves(root);
    }

    void mirror() {
        mirror(root);
    }
};

int main() {
    BST<double> bst;

    std::cout << "*** BINARY SEARCH TREE ***\n";
    std::cout << "\nWhat do you want to do?";
    std::cout << "\n1.  Insertion";
    std::cout << "\n2.  Deletion by copying";
    std::cout << "\n3.  Deletion by merging";
    std::cout << "\n4.  Search for a number";
    std::cout << "\n5.  Display its preorder, postorder and inorder traversals";
    std::cout << "\n6.  Display its level by level traversals";
    std::cout << "\n7.  Count the non-leaf nodes and leaf nodes";
    std::cout << "\n8.  Display height of tree";
    std::cout << "\n9.  Create a mirror image of tree";
    int option;
    char ans = 'y';
    do {
        std::cout << "\nEnter your option: ";
        std::cin >> option;
        switch(option) {
            case 1: {
                int element;
                std::cout << "Enter element to insert: ";
                std::cin >> element;
                bst.insert(element);
                break;
            }
            case 2: {
                int element;
                std::cout << "Enter element to delete: ";
                std::cin >> element;
                bst.findAndDeleteByCopying(element);
                break;
            }
            case 3: {
                int element;
                std::cout << "Enter element to delete: ";
                std::cin >> element;
                bst.findAndDeleteByMerging(element);
                break;
            }
            case 4: {
                int element;
                std::cout << "Enter element to search: ";
                std::cin >> element;
                if(bst.search(element) != NULL) {
                    std::cout << "Element" << *bst.search(element) << " found!" << std::endl;
                } else std::cout << "Element not found!\n";
                break;
            }
            case 5: {
                std::cout << "Preorder traversal: ";
                bst.preorder();
                std::cout << std::endl;
                std::cout << "Postorder traversal: ";
                bst.postorder();
                std::cout << std::endl;
                std::cout << "Inorder traversal: ";
                bst.inorder();
                std::cout << std::endl;
                break;
            }
            case 6: {
                std::cout << "Breadth first traversal: ";
                bst.breadthFirst();
                std::cout << std::endl;
                break;
            }
            case 7: {
                std::cout << "Number of leaves: " << bst.num_leaves() << std::endl;
                std::cout << "Number of non leaves: " << bst.num_non_leaves() << std::endl;
                break;
            }
            case 8: {
                std::cout << "Height of tree is: " << bst.height() << std::endl;
                break;
            }
            case 9: {
                std::cout << "Mirroring tree... \n";
                bst.mirror();
                std::cout << "Done!\n";
                break;
            }
        }
        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> ans;
    } while(ans == 'y' || ans == 'Y');
}
