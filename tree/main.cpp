#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};

// Function to insert a node in level order
void insert(Node* &root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = new Node(val);
            return;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = new Node(val);
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}



Node* findLCA(Node* root, Node* p,Node* q)
{
   if(!root || root ==p || root == q)
    return root;

   Node* leftLca = findLCA(root->left,p,q);
   Node* rightLca = findLCA(root->right,p,q);

   if(leftLca && rightLca) return root; 
   return (leftLca != nullptr) ? leftLca : rightLca;

}

int main() {
    Node* root = nullptr;
    int keys[] = {3, 5, 1, 6, 2, 0, 8,0, 0, 7, 4};

    for (int key : keys) {
        insert(root, key);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;


    Node* res = findLCA(root, root->left->right->right,root->left->right->left);


    return 0;
}
