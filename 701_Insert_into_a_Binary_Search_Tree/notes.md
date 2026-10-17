## Problem

You are given the root node of a binary search tree (BST) and a value `val` to insert.

Insert the value into the BST and return the root node after insertion.

The new value is guaranteed not to exist in the original BST.

## My Approach

I use recursion to find the correct position for the new value while preserving the BST property.

First, I check whether `root == NULL`. If the current position is empty, I create and return a new node containing `val`.

Otherwise, I compare `val` with `root->val`.

- If `val > root->val`, I recursively insert into the right subtree.
- Otherwise, I recursively insert into the left subtree.

I assign the returned subtree root to the corresponding child pointer.

Finally, I return `root` so the original tree structure is preserved.

## Key Logic

**Base case:** Create a new node when an empty position is found.

```cpp
if(root == NULL) {
    return new TreeNode(val);
}
```

**Insert into the right subtree:**

```cpp
if(val > root->val) {
    root->right = insertIntoBST(root->right, val);
}
```

**Insert into the left subtree:**

```cpp
else {
    root->left = insertIntoBST(root->left, val);
}
```

Return the current root:

```cpp
return root;
```

**Example:**

```text
Input:
root = [4,2,7,1,3]
val = 5

Search path:
5 > 4 → move right
5 < 7 → move left
Left child of 7 is NULL → insert 5

Result:
[4,2,7,1,3,5]
```

## Solution

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }

        if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        else {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};
```

## Complexity

Let `h` be the height of the BST.

- **Time:** `O(h)` because each recursive call moves down one level.
- **Space:** `O(h)` for the recursion stack.

For a balanced BST, both are `O(log n)`; for a completely skewed BST, both can be `O(n)`.

## What I Learned

- A BST stores smaller values in the left subtree and larger values in the right subtree.
- Recursion helps find the correct insertion position.
- The base case creates a node when an empty child is reached.
- Assigning the recursive result to `root->left` or `root->right` connects the new node to the tree.
- Returning `root` preserves the original root of the BST.
- BST operations depend on tree height, which varies with the tree's shape.