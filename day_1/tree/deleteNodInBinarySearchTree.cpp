#include <iostream>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* findRightMost(TreeNode* root) {
    if (root == nullptr) return root;
    if (root->right == nullptr) return root;
    return findRightMost(root->right); 
}


TreeNode* helper(TreeNode* root) {
    if (root->left == nullptr) return root->right; 
    if (root->right == nullptr) return root->left;
    
    TreeNode* rightChild = root->right;
    TreeNode* leftTree = findRightMost(root->left); 
    leftTree->right = rightChild; 
    return root->left; 
}



TreeNode* deleteNode(TreeNode* root, int target) {
    if (root == nullptr) return nullptr;
    if (root->val == target) return helper(root); 
    
    TreeNode* dummy = root;
    
    while (root) {
        if (root->val > target) {
            if (root->left && root->left->val == target) {
                root->left = helper(root->left); 
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right && root->right->val == target) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    
    return dummy; 
}


void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Insert nodes to build a binary search tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    std::cout << "In-order traversal before deletion:\n";
    inorder(root);
    std::cout << "\n";

    // Delete node with value 20
    root = deleteNode(root, 20);
    std::cout << "In-order traversal after deleting 20:\n";
    inorder(root);
    std::cout << "\n";

    // Delete node with value 30
    root = deleteNode(root, 30);
    std::cout << "In-order traversal after deleting 30:\n";
    inorder(root);
    std::cout << "\n";

    // Delete node with value 50
    root = deleteNode(root, 50);
    std::cout << "In-order traversal after deleting 50:\n";
    inorder(root);
    std::cout << "\n";

    return 0;
}
