#include <iostream>
using namespace std;

// For creation of Node
// NODE :: START >>>>>>>>>>>>>>>>>>

template<class dynamic>
class Node {
    public:
    
    dynamic element;
    Node<dynamic> *right;
    Node<dynamic> *left;
    
    static Node<dynamic> *addnode(dynamic);
};

template<class dynamic>
Node<dynamic>* Node<dynamic>::addnode(dynamic element) {
    Node<dynamic>* temp = new Node<dynamic>;
    temp->element = element;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// NODE :: END <<<<<<<<<<<<<<<<<<<<

// For set using Binary search tree
// SET :: START >>>>>>>>>>>>>>>>>>

template<class dynamic>
class Set {
    Node<dynamic> *root;
    public:

    Set();
    bool insert(dynamic);
    bool remove(dynamic);
    int size();
    bool ispresent(dynamic);
    Set<dynamic> *begin();  // Use of iterator should be rethinked
    Set<dynamic> *end();
    Set<dynamic> __intersection(Set<dynamic>);
    Set<dynamic> __union(Set<dynamic>);
    Set<dynamic> __difference(Set<dynamic>);

};

template<class dynamic>
Set<dynamic>::Set() {
    root = NULL;        // Initialisation
}

template<class dynamic>
bool Set<dynamic>::ispresent(dynamic element) {
    for (Node<dynamic> temp = this->root; temp !=NULL; /*updation provided in block*/) {
        if( element == temp->element)       // if element is in set return 1;
            return 1;
        else if (element > temp->element) {
            temp = temp->right;
        }
        else if (element < temp->element) {
            temp = temp->left;
        }   
    }
    return 0;       //element not found
    
}

template<class dynamic>
bool Set<dynamic>::remove(dynamic element) {
    for (Node<dynamic> temp = this->root; temp !=NULL; /*updation provided in block*/) {
        if( element == temp->element) {       // if element is in set return 1;
            
            return 1;
        }
        else if (element > temp->element) {
            temp = temp->right;
        }
        else if (element < temp->element) {
            temp = temp->left;
        }   
    }
    return 0;       //element not found
    
}


template<class dynamic>
bool Set<dynamic>::insert(dynamic element) {
    for (Node<dynamic> temp = this->root; temp !=NULL; /*updation provided in block*/) {
        if( element == temp->element)       // if element is already in set return 0;
            return 0;
        else if (element > temp->element) {
            if (temp->right == NULL) {       // if element is not present ie. NULL add the given element
                temp->right = Node<int>::addnode(element);
                return 1;
            }
            temp = temp->right;
        }
        else if (element < temp->element) {
             if (temp->left == NULL) {
                temp->left = Node<int>::addnode(element);
                return 1;
            }
            temp = temp->left;
        }   
    }
}
// SET :: END <<<<<<<<<<<<<<<<<<

// Driver Function
// MAIN :: START >>>>>>>>>>>>>>>>
int main(int argc, char const *argv[]) {
    
    return 0;
}

