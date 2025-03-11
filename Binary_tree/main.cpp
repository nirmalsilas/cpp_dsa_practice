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

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(Node* root) {
    if (root) {
        cout << root->val << " ";
        preorderTraversal(root->left);
        
        preorderTraversal(root->right);
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

// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        
        
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
}


void findmin(Node* root ,int& min)
{

    if(!root)return;
    findmin(root->left,min);
    if(root->val <min )min =root->val;

    findmin(root->right,min);
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

void flatten(Node* root) {

if(!root)return;
flatten(root->left);
flatten(root->right);

Node* tmp = root->right;
root->right =root->left;
root->left =nullptr;
Node* curr = root;

while(curr->right)
{
    curr =curr->right;
}

curr->right = tmp;
return ;
        
}

vector<double> averageOfLevels(Node* root) {

        std::vector<double> v{};
        if (!root) return v;
        std::queue<Node*> Q;
        Q.push(root);


        while(!Q.empty())
        {
            int sum=0;
            int size = Q.size();
            for(int i= 0;i<size;i++)
            {
                Node* tmp =Q.front();
                Q.pop();
                sum+= tmp->val;
                if (tmp->left) Q.push(tmp->left);
                if (tmp->right)Q.push(tmp->right);

            }
           

            v.push_back(sum/size);



        }
        return v;
}

int main() {
    Node* root = nullptr;
    int keys[] = {3, 5, 1, 6, 2, 0, 8, 7, 4};

    for (int key : keys) {
        insert(root, key);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;


    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;


    //Node* res = findLCA(root, root->left->right->right,root->left->right->left);

   // flatten(root);
    //averageOfLevels(root);
    int min = 5000;
    findmin(root,min);
    return 0;
}
