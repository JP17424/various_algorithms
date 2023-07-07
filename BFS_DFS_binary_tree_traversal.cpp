#include <iostream>
#include <queue> // for BFS 
#include <stack> // for DFS 


// -----
// (1) create tree node
//
// here, we create a basic tree node structure,
// each node needs a value and a left and right pointer which
// points to the left and right child nodes respectively
struct tree_node {

        int value;
        tree_node * left;
        tree_node * right;

        // optional constructor
        tree_node(int input_data){
                value = input_data;
                left = nullptr;
                right = nullptr;
        }

};


// -----
// (2) function for DFS recursive algorithm
//
// This is a depth first search (DFS) algorithm
// There are 3 examples in which a binary tree
// can be traversed, pre-order, in-order, post-order,
// all these are examples of DFS,
// here we use pre-order, however for in-order or post order,
// simply...
// 1) go left, 2) get data, 3) go right,
// or...
// 1) go left, 2) go right, 3) get data, respectively
void print_tree_DFS(tree_node * input_node){

        if(input_node==nullptr) {
                return;
        }

        // pre-order -> 1) get data, 2) go left, 3) go right
        std::cout << " node value : " << input_node->value << '\n';

        print_tree_DFS(input_node->left);
        print_tree_DFS(input_node->right);

} // DFS


// -----
// (3) function for DFS stack algorithm
//
// see (2) for further details 
void print_tree_stack_DFS(tree_node * input_node){


        // first create a stack for the tree nodes and push root node onto stack
        std::stack<tree_node*> my_node_stack;

        my_node_stack.push(input_node);

        // while there are elements in the stack, we iterate
        while(!my_node_stack.empty()) {

                // get element from top of stack
                tree_node * node = my_node_stack.top();

                // need to pop current element here as this is a stack, not a queue
                my_node_stack.pop();

                // get data
                std::cout << " node value : " << node->value << '\n';

                // go to left child node, put element in stack
                if(node->left) {
                        my_node_stack.push(node->left);
                }

                // go to right child node, put element in stack
                if(node->right) {
                        my_node_stack.push(node->right);
                }

        } // while

} // stack DFS


// -----
// (4) function for BFS queue algorithm 
//
// To perform a breath first search (BFS) in which we traverse
// the tree layer-by-layer, we need to use a queue as a queue
// operates on a first-in-first-out basis, and we use this to
// remember the layers of the tree. 
// So, put root node in the queue,
// check left child node, put in queue, check right child node
// and put in queue, pop root and iterate
void print_tree_BFS(tree_node * input_node){

        // first create a queue data structure, and push root onto queue
        std::queue<tree_node*> my_node_queue;

        my_node_queue.push(input_node);

        // while there are elements in the queue
        while(!my_node_queue.empty()) {

                // get element from front of queue
                tree_node * node = my_node_queue.front();

                // get data
                std::cout << "node value : "  << node->value << '\n';

                // if left child exists - push left node in queue
                if(node->left) {
                        my_node_queue.push(node->left);
                }

                // if right child exists - push right node in queue
                if(node->right) {
                        my_node_queue.push(node->right);
                }

                // we can now pop the first element in the queue
                my_node_queue.pop();

        } // while

} // BFS



// main
int main(){


        // ----- ----- -----
        //
        // READ ME
        //
        // ----- ----- -----
        // notes on methods:
        //
        // This C++ script contains functions to traverse a binary tree using DFS and BFS methods.
        // Two DFS methods are included, the first traverses the tree via recursion,
        // and the second traverses the tree with the use of a stack function from the C++ STL.
        // One BFS method is included which utilises a queue, also from C++ STL.
        // A recursion method using BFS has not been included here as recursive BFS traversal
        // can use significant amounts of memory when large trees are traversed and can potentially
        // cause a stack memory overflow.
        //
        // ----- ----- -----
        // notes on code:
        //
        // Firstly, a basic tree structure is created as an example and its values are printed manually
        // such that the tree structure is shown, the DFS and BFS algorithms are then called on the tree,
        // and the results are printed to the terminal, the results demonstrate the different methods
        // of binary tree traversal.
        //
        // Additional notes on the code can be found above in which:
        // (1) info on creating a basic binary tree node
        // (2) info on DFS recursive algorithm
        // (3) info on DFS stack algorithm
        // (4) info on BFS queue algorithm
        //
        //
        // ----- ----- -----
        // first we create the binary tree, as below...


        // create the root node
        tree_node * root = new tree_node(10);

        // create the left and right branches
        root->left = new tree_node(5);
        root->right = new tree_node(15);

        // add a 3rd layer on left hand side
        root->left->left = new tree_node(3);
        root->left->right = new tree_node(7);

        // add a 3rd layer on the right hand side
        root->right->left = new tree_node(12);
        root->right->right = new tree_node(17);


        // ----- ----- -----
        // next, we manually print the tree to the terminal,
        // this allows us to see the exact tree structure
        //
        std::cout << "--- manually prinitng the tree structure ---" << '\n';
        std::cout << " root : " << root->value << '\n';
        std::cout << " root->left : " << root->left->value << '\n';
        std::cout << " root->right : " << root->right->value << '\n';
        std::cout << " root->left->left : " << root->left->left->value << '\n';
        std::cout << " root->left->right : " << root->left->right->value << '\n';
        std::cout << " root->right->left : " << root->right->left->value << '\n';
        std::cout << " root->right->right : " << root->right->right->value << '\n';


        // ----- ----- -----
        // finally, we  call the DFS and BFS functions,
        // hence we can compare the order of traversal
        //


        // DFS recursion
        std::cout << "\n" << "--- using DFS recursion algorithm ---" << '\n';
        print_tree_DFS(root);

        // DFS stack
        std::cout << "\n" << "--- using DFS stack algorithm ---" << '\n';
        print_tree_stack_DFS(root);

        // BFS queue
        std::cout << "\n" << "--- using BFS queue algorithm ---" << '\n';
        print_tree_BFS(root);

        // 
        // release memory as we were using raw pointers
        // note: much better to use smart pointers as you do not have to deallocate memory manually
        delete root->right->left; 
        delete root->right->right;
        delete root->left->left;
        delete root->left->right;
        delete root->left; 
        delete root->right;
        delete root; 

        std::cout << "done." << '\n';
        return 0;
}
