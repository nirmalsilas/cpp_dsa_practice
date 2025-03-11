1)Breadth-First Search (BFS) for Trees

Breadth-First Search (BFS) is a tree traversal method that visits nodes level by level from left to right. It is also called Level Order Traversal.
How BFS Works in a Tree
    Use a Queue (std::queue)

    Start with the root node in the queue.
    Process the front node and enqueue its left and right children.
    Repeat until the queue is empty.
    Visit nodes level by level

    First process the root.
    Then visit all nodes at depth 1, then depth 2, and so on.
/ BFS Function for Level Order Traversal
void bfs(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";  // Process node

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
BFS is useful for finding the shortest path in an unweighted tree/graph.
Great for problems involving "levels" like kth level sum, deepest node, etc.
2)Depth-First Search (DFS) for Trees

Depth-First Search (DFS) is a tree traversal algorithm that explores as deep as possible along one branch before backtracking.

DFS can be implemented in three different ways:

    a)Preorder Traversal (Root → Left → Right)
    b)Inorder Traversal (Left → Root → Right)
    c)Postorder Traversal (Left → Right → Root)
    // Preorder Traversal (Root → Left → Right)
void dfsPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";   // Visit root
    dfsPreorder(root->left);    // Recur on left subtree
    dfsPreorder(root->right);   // Recur on right subtree
}

// Inorder Traversal (Left → Root → Right)
void dfsInorder(TreeNode* root) {
    if (!root) return;
    dfsInorder(root->left);     // Recur on left subtree
    cout << root->val << " ";   // Visit root
    dfsInorder(root->right);    // Recur on right subtree
}

// Postorder Traversal (Left → Right → Root)
void dfsPostorder(TreeNode* root) {
    if (!root) return;
    dfsPostorder(root->left);   // Recur on left subtree
    dfsPostorder(root->right);  // Recur on right subtree
    cout << root->val << " ";   // Visit root
}


