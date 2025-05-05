#include <iostream>
using namespace std;

class BTree{
    private :
        struct node {
            char data;
            struct node * left,*right;
        };
    public:
        struct node * root;
        BTree(){
            root=NULL;
        }
        node* Insert();
        void Preorder(node * root);
        void Inorder(node * root);
        void Postorder(node * root);
        void Search(node * root,char);
};

int main(){
    BTree btree;
    char cha;
    int choice;
    do
    {
        cout<<"\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice){
            case 1:
               btree.root=btree.Insert();
                break;
            case 2:
                cout<<"\nPreorder:";
                btree.Preorder(btree.root);
                cout<<"\n";
                break;
            case 3:
                cout<<"\nInorder:";
                btree.Inorder(btree.root);
                cout<<"\n";
                break;
            case 4:
                cout<<"\nPostorder:";
                btree.Postorder(btree.root);
                cout<<"\n";
                break;
            case 5:
                cout<<"Enter the character to be searched:";
                cin>>cha;
                btree.Search(btree.root,cha);
                break;
            case 6:
                printf("Exiting the program");
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
                break;
        }
    }while(choice!=6);
}


BTree::node* BTree::Insert(){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    char ch;
    cout<<"Enter the character to be inserted(N for exit):";
    cin>>ch;
    if (ch=='N'){
        return NULL;
    }
    newnode->data=ch;
    cout<<"\nEnter Left child of "<<ch<<":\n";
    newnode->left=Insert();
    cout<<"\nEnter Right child of "<<ch<<":\n";
    newnode->right=Insert();
    return newnode;
}


void BTree::Preorder(node* root){
    if (root!=NULL){
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
    else{
        return;
    }
}


void BTree::Postorder(node * root){
    if (root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }
    else{
        return;
    }
}


void BTree::Inorder(node *root){
    if (root!=NULL){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
    else{
        return;
    }
}

void BTree::Search(node * root,char cha){
    if (root!=NULL){
        if (root->data == cha){
            cout<<"\nElement Found\n";
            return;
        }
        Search(root->left,cha);
        Search(root->right,cha); 
    }
}
