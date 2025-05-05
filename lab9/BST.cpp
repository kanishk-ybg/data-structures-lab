#include<iostream>
using namespace std;

class BST{
    struct TreeNode{
        TreeNode* left;
        TreeNode* right;
        int val;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };
    
    public:
       TreeNode* root;
       BST();
       TreeNode* insert(TreeNode*, int);
       void insert(int);
       void inorder(TreeNode*);
       void preorder(TreeNode*);
       void postorder(TreeNode*);
       bool search(TreeNode*, int);
       void inorder();
       void preorder();
       void postorder();
       bool search(int);
};

BST::BST(){
    root = nullptr;
}

BST::TreeNode* BST::insert(BST::TreeNode* root, int ele){
    if(!root) return new TreeNode(ele);
    if(ele < root->val) root->left = insert(root->left, ele);
    else root->right = insert(root->right, ele);
    return root;
}

void BST::insert(int ele){
    root = insert(root, ele);
}

void BST::inorder(BST::TreeNode* root){
    if(root){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void BST::preorder(BST::TreeNode* root){
    if(root){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::postorder(BST::TreeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

bool BST::search(BST::TreeNode* root, int ele){
    if(!root) return false;
    if(root->val == ele) return true;
    if(ele < root->val) return search(root->left, ele);
    return search(root->right, ele);
}

void BST::inorder(){ inorder(root); }
void BST::preorder(){ preorder(root); }
void BST::postorder(){ postorder(root); }
bool BST::search(int ele){ return search(root, ele); }

int main(){
    int ch, ele;
    BST bst;
    while(true){
        cout << "\nMENU\n";
        cout << "1.Insert\n";
        cout << "2.Postorder\n";
        cout << "3.Inorder\n";
        cout << "4.Preorder\n";
        cout << "5.Search\n";
        cout << "6.Exit\n";
        cout << "Enter your choice(1-6):";
        cin  >> ch;

        if(ch == 6){
            cout << "\nExiting Program..";
            break;
        }

        switch(ch){
            case 1:
                cout << "Enter element to insert: ";
                cin >> ele;
                bst.insert(ele);
                break;
            case 2:
                bst.postorder();
                cout << "\n";
                break;
            case 3:
                bst.inorder();
                cout << "\n";
                break;
            case 4:
                bst.preorder();
                cout << "\n";
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> ele;
                cout << (bst.search(ele) ? "Found\n" : "Not Found\n");
                break;
        }
    }
}

