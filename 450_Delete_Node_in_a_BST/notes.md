# 450. Delete Node in a BST

## Problem
Given the root of a Binary Search Tree (BST) and an integer `key`, delete the node with the given key and return the root of the modified BST.

If the key does not exist, return the original tree.

## My Approach
Used recursion to search for the node and handle the three possible deletion cases.

1. If the root is `nullptr`, return `nullptr`.
2. If `key > root->val`, search in the right subtree recursively.
3. If `key < root->val`, search in the left subtree recursively.
4. If the key matches the current node:
   - **No right child:** Store the left child, delete the current node and return the left child.
   - **No left child:** Store the right child, delete the current node and return the right child.
   - **Two children:** Find the inorder successor (minimum node in the right subtree), copy its value into the current node, and recursively delete the successor from the right subtree.
5. Return the updated root.

## Key Logic
### 1. Searching for the node
BST property:
- Smaller values are in the left subtree.
- Larger values are in the right subtree.

This allows us to recursively locate the node.

### 2. Deleting a node with zero or one child
Connect the parent directly to the existing child, delete the current node and return the replacement subtree.

### 3. Deleting a node with two children
- Find the inorder successor using `findMin(root->right)`.
- Copy its value into the current node.
- Delete the successor from the right subtree.

The inorder successor is the smallest value in the right subtree, so the BST property remains valid.

### Helper Function
`findMin()` repeatedly moves left until it reaches the leftmost node.

## Solution

```cpp
class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        while(root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if(root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            if(root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
```

## Complexity
Let H be the height of the BST.

- **Time Complexity:** O(H) — Searching for the key and finding the inorder successor take O(H) time.
- **Space Complexity:** O(H) — Recursive calls use the call stack.

For a balanced BST, H = O(log N). In the worst case of a skewed BST, H = O(N).

## What I Learned
- How to search and delete nodes recursively in a BST.
- How to handle deletion with zero, one or two children.
- What an inorder successor is and how to find it.
- Why the inorder successor is used when deleting a node with two children.
- How to reconnect subtree pointers after deletion.
- Why returning the updated root is important.