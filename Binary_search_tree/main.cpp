#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert a node into BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    
    if (key < root->val) 
        root->left = insert(root->left, key);
    else 
        root->right = insert(root->right, key);
    
    return root;
}

// Search a key in BST
bool search(TreeNode* root, int key) {
    if (!root) return false;
    
    if (root->val == key) return true;
    if (key < root->val) return search(root->left, key);
    
    return search(root->right, key);
}

// Inorder Traversal (Prints BST in sorted order)
void inorder(TreeNode* root) {
    if (!root) return;
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Find the minimum value node
TreeNode* findMin(TreeNode* root) {
    while (root->left) root = root->left;
    return root;
}

// Delete a node from BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    if (key < root->val) 
        root->left = deleteNode(root->left, key);
    else if (key > root->val) 
        root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        // Node with two children: Get inorder successor (smallest in right subtree)
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void check(TreeNode* root,int& k,int& result)
{
    if(k ==0 || !root)return;

    check(root->left,k,result);
    k--;
    if(k==0 ){
        result =root->val;
        return;
    }

    check(root->right,k,result);
}


int kthSmallest(TreeNode* root, int k) {
    int result =-1;
    check(root,k,result);
    return result;

}

bool isvalid(TreeNode* root,int min,int max)
{
    if(!root) return true;
    if(min>= root->val || root->val >= max) return false;
    
    return isvalid(root->left,min,root->val) && isvalid(root->right,root->val,max);
   
}
int main() {
    TreeNode* root = nullptr;

    // Insert nodes
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search key
    int key = 4;
    cout << "Search " << key << ": " << (search(root, key) ? "Found" : "Not Found") << endl;

    // Delete node
    root = deleteNode(root, 3);
    cout << "After Deletion (3): ";
    inorder(root);
    cout << endl;


    kthSmallest(root,3);

    return 0;
}
