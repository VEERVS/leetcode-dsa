## Problem

Given the root of a Binary Search Tree (BST) and an integer `val`, find the node whose value equals `val` and return the subtree rooted at that node.

If the value does not exist, return `NULL`.

## My Approach

I used the BST property to decide which side of the tree to search.

- If `root == NULL`, the value does not exist → return `NULL`.
- If `val == root->val`, we found the node → return `root`.
- If `val > root->val`, search the right subtree.
- Otherwise, search the left subtree.

I used recursion to continue searching down the appropriate side.

## Key Logic

The important property of a BST is:

```text
val < root->val  →  go LEFT
val > root->val  →  go RIGHT
val == root->val →  FOUND
```

Since we return `TreeNode*`, when we find the value we return the actual node:

```cpp
return root;
```

If the search reaches a `NULL` node:

```cpp
return NULL;
```

## Solution

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
        else if(val == root->val){
            return root;
        }
        else if(val > root->val){
            return searchBST(root->right, val);
        }
        else{
            return searchBST(root->left, val);
        }
    }
};
```

## Complexity

- **Time:** `O(h)` where `h` is the height of the BST.
- **Space:** `O(h)` due to the recursive call stack.

For a balanced BST, `h = log n`, so the time and space are `O(log n)`.

For a skewed BST, `h = n`, so they can become `O(n)`.

## What I Learned

- A BST lets us eliminate half of the search space at every node in a balanced tree.
- `root->val` accesses the value stored in the current node.
- Since the function returns `TreeNode*`, we return `root`, not `1`.
- `NULL` means no matching node was found.
- Recursion follows the same BST decision rule at every node.