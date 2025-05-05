#include <iostream>
#include <stack>
using namespace std;

// Node structure for Expression Tree
struct Node {
    char data;
    Node *left, *right;
    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

class ExpressionTree {
public:
    Node* constructTree(string postfix);
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
};

// Construct Expression Tree from Postfix Expression
Node* ExpressionTree::constructTree(string postfix) {
    stack<Node*> st;
    for (char ch : postfix) {
        Node* newNode = new Node(ch);
        
        if (isalpha(ch) || isdigit(ch)) { // Operand
            st.push(newNode);
        } else { // Operator
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            st.push(newNode);
        }
    }
    return st.top();
}

// Inorder Traversal (Left - Root - Right)
void ExpressionTree::inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root - Left - Right)
void ExpressionTree::preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left - Right - Root)
void ExpressionTree::postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    ExpressionTree et;
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    
    Node* root = et.constructTree(postfix);
    
    cout << "\nInorder traversal: ";
    et.inorder(root);
    
    cout << "\nPreorder traversal: ";
    et.preorder(root);
    
    cout << "\nPostorder traversal: ";
    et.postorder(root);
    
    return 0;
}
