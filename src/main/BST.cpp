#include<iostream>
using namespace std;
struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) {
                data = val;
                left = right = NULL;
        }
};
void insertLeft(Node* root, int val) {
 if (root->left == nullptr)
      root->left = new Node(val);
 else
     insertLeft(root->left, val);
}
void insertRight(Node* root, int val) {
        if(!root->right)
                root->right = new Node(val);
        else
             insertRight(root->right, val);
}
bool search(Node* root, int key) {
        if(root == NULL) {
                return false;
        }
        if(root->data == key) {
                return true;
        }
        return search(root->left,key) || search(root->right, key);
}
void deleteTree(Node* root) {
        if(root == NULL) {
                return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
}
void inorder(Node* root) {
            if (root == nullptr) return;
                inorder(root->left);
                cout << root->data << " ";
                inorder(root->right);
}

 void preorder(Node* root) {
     if (root == nullptr) return;
         cout << root->data << " ";
         preorder(root->left);
          preorder(root->right);
 }
 void postorder(Node* root) {
      if (root == nullptr) return;
      postorder(root->left);
      postorder(root->right);
      cout << root->data << " ";
 }
int main() {
        Node* root = new Node(1);

        insertLeft(root,2);
        insertRight(root,3);
        insertLeft(root->left,4);
        insertRight(root->right,5);

        cout << "\nPre-Order Traversal: ";
        preorder(root);
        cout << "\nIn-Order Traversal: ";
        inorder(root);
        cout << "\nPost-Order Traversal: ";
        postorder(root);

        int key = 5;
        cout << (search(root,key) ? "Found" : "Not Found ") << endl;
        deleteTree(root);
        return 0;
        }

