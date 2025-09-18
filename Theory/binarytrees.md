# Chapter: Binary Trees (C++)

> *This chapter explains binary trees in detail — theory, diagrams, common operations, C++ implementations (idiomatic, modern), analyses, and advanced topics. It's written as a book chapter: read from top to bottom or jump to sections you need.*

---

## Table of Contents

- [Chapter: Binary Trees (C++)](#chapter-binary-trees-c)
  - [Table of Contents](#table-of-contents)
  - [Introduction \& definition](#introduction--definition)
  - [Terminology \& properties](#terminology--properties)
  - [Kinds of binary trees](#kinds-of-binary-trees)
  - [Representations in memory](#representations-in-memory)
  - [Basic operations \& algorithms](#basic-operations--algorithms)
  - [Tree traversals (with C++)](#tree-traversals-with-c)
    - [Node definition (C++)](#node-definition-c)
    - [Preorder (root, left, right)](#preorder-root-left-right)
    - [Inorder (left, root, right)](#inorder-left-root-right)
    - [Postorder (left, right, root)](#postorder-left-right-root)
    - [Level-order (BFS)](#level-order-bfs)
  - [Common utility functions (C++)](#common-utility-functions-c)
    - [Height (recursive)](#height-recursive)
    - [Size (number of nodes)](#size-number-of-nodes)
    - [Check if two trees are identical](#check-if-two-trees-are-identical)
    - [Mirror / invert tree](#mirror--invert-tree)
    - [Check balanced (optimized, O(n))](#check-balanced-optimized-on)
    - [Lowest Common Ancestor (LCA) — simple binary tree O(n)](#lowest-common-ancestor-lca--simple-binary-tree-on)
  - [Binary Search Tree (BST): brief and code](#binary-search-tree-bst-brief-and-code)
  - [Balanced BSTs: AVL \& Red-Black (overview)](#balanced-bsts-avl--red-black-overview)
  - [Serialization / Deserialization](#serialization--deserialization)
  - [Memory, performance, and tradeoffs](#memory-performance-and-tradeoffs)
  - [Compact ASCII diagrams (kept narrow)](#compact-ascii-diagrams-kept-narrow)
  - [Problems \& exercises](#problems--exercises)
  - [Worked example: diameter (O(n))](#worked-example-diameter-on)
  - [Best practices \& tips](#best-practices--tips)
  - [References \& further reading](#references--further-reading)

---

## Introduction & definition

A **binary tree** is a hierarchical data structure composed of nodes. Each node contains a value and *up to two* child pointers (commonly named *left* and *right*). The topmost node is the **root**. Nodes with no children are **leaves**.

Binary trees are one of the most fundamental data structures in computer science, used to build search trees, expression trees, heaps, tries (in variants), segment trees, and many algorithmic solutions.

## Terminology & properties

* **Node**: single element holding a value (and possibly metadata).
* **Root**: the top node (no parent).
* **Parent / Child**: obvious relation.
* **Left / Right subtree**: the tree rooted at the left / right child.
* **Leaf**: node with no children.
* **Internal node**: node with at least one child.
* **Depth (of node)**: number of edges from root to the node.
* **Height (of node)**: number of edges on the longest path from the node down to a leaf. Convention: height of an empty tree = -1 or sometimes 0; pick one consistently.
* **Size**: number of nodes in the tree.
* **Level**: nodes with same depth are on same level.

Properties to remember:

* Maximum number of nodes at level `d` is `2^d` (root at level 0).
* Maximum number of nodes in a binary tree of height `h` is `2^{h+1}-1`.

Compact formulas and reminders:

* If a tree is perfect (all levels full) and height `h`, size = `2^{h+1}-1`.
* Balanced trees aim to keep height `O(log n)`.

## Kinds of binary trees

* **Full binary tree**: every node has `0` or `2` children.
* **Perfect binary tree**: full and all leaves at same level.
* **Complete binary tree**: all levels filled except possibly last; last level filled left-to-right.
* **Balanced binary tree**: left/right subtree heights differ by at most some constant (commonly 1).
* **Degenerate (pathological)**: every node has exactly one child — behaves like a linked list.

## Representations in memory

Two common ways to represent binary trees:

1. **Node-and-pointer (linked) representation** — dynamic allocation of nodes with `left` and `right` pointers. Great for sparse trees, easiest to express recursion.
2. **Array (implicit) representation** — used for binary heaps / complete trees. Root at index `1` (or `0`), left child `2*i`, right child `2*i+1` (or `2*i+1`, `2*i+2` for 0-indexed). Memory-friendly for complete trees.

Use pointer nodes for general trees; use arrays for complete trees like heaps.

## Basic operations & algorithms

Common operations and their high-level algorithmic ideas:

* **Search / Find (general binary tree)**: traverse (BFS/DFS) to locate value — `O(n)`.
* **Insert (general)**: depends on constraint; to keep complete property use level-order insert; for BST insert at correct position using comparisons `O(height)`.
* **Delete (general)**: find node, then adjust children; for BST deletion there are classical cases (leaf, one child, two children — replace with inorder successor or predecessor).
* **Traversals**: preorder, inorder, postorder, level-order (BFS).
* **Height / Depth**: compute recursively or iteratively via BFS.
* **LCA (Lowest Common Ancestor)**: multiple algorithms — binary lifting for static trees, Euler-tour + RMQ, or simple recursive method for binary trees `O(n)`.
* **Mirror / invert**: swap left/right recursively or iteratively.
* **Check balanced**: compute heights bottom-up to detect imbalance in `O(n)`.

## Tree traversals (with C++)

Below are canonical implementations and explanations. Wherever helpful I show both recursive and iterative forms.

> **Coding style**: C++ snippets use modern idioms while keeping things explicit. Comments are informal and human-like per your preference.

### Node definition (C++)

```cpp
// simple binary tree node
struct Node {
    int val;            // stored value
    Node* left;         // left child (nullptr if absent)
    Node* right;        // right child (nullptr if absent)
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

### Preorder (root, left, right)

Recursive:

```cpp
void preorder(Node* root) {
    if (!root) return;            // base case
    cout << root->val << ' ';     // visit root
    preorder(root->left);         // visit left subtree
    preorder(root->right);        // visit right subtree
}
```

Iterative (using stack):

```cpp
void preorder_iter(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* cur = st.top(); st.pop();
        cout << cur->val << ' ';
        // push right first so left is processed first
        if (cur->right) st.push(cur->right);
        if (cur->left) st.push(cur->left);
    }
}
```

### Inorder (left, root, right)

Recursive:

```cpp
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}
```

Iterative (stack-based):

```cpp
void inorder_iter(Node* root) {
    stack<Node*> st;
    Node* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        cout << cur->val << ' ';
        cur = cur->right;
    }
}
```

### Postorder (left, right, root)

Recursive:

```cpp
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}
```

Iterative (two stacks / modified preorder):

```cpp
// method: push root, pop to output stack, push left/right, then output stack reversed
void postorder_iter(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* cur = s1.top(); s1.pop();
        s2.push(cur);
        if (cur->left) s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
    }
    while (!s2.empty()) { cout << s2.top()->val << ' '; s2.pop(); }
}
```

Another single-stack approach exists using a visited flag or tracking previously visited node.

### Level-order (BFS)

```cpp
void level_order(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << ' ';
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
```

To print level-by-level, track queue size at each iteration.

## Common utility functions (C++)

Below are implementations often used in algorithm problems.

### Height (recursive)

```cpp
int height(Node* root) {
    if (!root) return -1; // or return 0 if you define leaf height = 1
    int hl = height(root->left);
    int hr = height(root->right);
    return 1 + max(hl, hr);
}
```

### Size (number of nodes)

```cpp
int size(Node* root) {
    if (!root) return 0;
    return 1 + size(root->left) + size(root->right);
}
```

### Check if two trees are identical

```cpp
bool identical(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val && identical(a->left,b->left) && identical(a->right,b->right);
}
```

### Mirror / invert tree

```cpp
Node* invert(Node* root) {
    if (!root) return nullptr;
    swap(root->left, root->right);
    invert(root->left);
    invert(root->right);
    return root;
}
```

### Check balanced (optimized, O(n))

We compute height and detect imbalance with a sentinel `-inf` return.

```cpp
int checkHeight(Node* root) {
    if (!root) return 0;
    int lh = checkHeight(root->left);
    if (lh == -1) return -1; // left subtree unbalanced
    int rh = checkHeight(root->right);
    if (rh == -1) return -1; // right subtree unbalanced
    if (abs(lh-rh) > 1) return -1; // current node unbalanced
    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}
```

### Lowest Common Ancestor (LCA) — simple binary tree O(n)

This recursive method returns a node pointer if it finds either p or q in the subtree. If both sides return non-null, current node is LCA.

```cpp
Node* lca(Node* root, Node* p, Node* q) {
    if (!root) return nullptr;
    if (root == p || root == q) return root;
    Node* L = lca(root->left, p, q);
    Node* R = lca(root->right, p, q);
    if (L && R) return root;     // p and q found in different subtrees
    return L ? L : R;            // either one side found or none
}
```

## Binary Search Tree (BST): brief and code

A **BST** is a binary tree with the ordering property: for any node `x`, every node in `x->left` has value `<= x->val` (or `<` depending on convention) and every node in `x->right` has value `>= x->val`.

This allows **search, insert, delete** to be done in `O(h)` time where `h` is tree height. In balanced BSTs `h = O(log n)`; in worst-case degenerate BST `h = O(n)`.

Basic operations in C++:

```cpp
// insert into BST (iterative)
Node* bst_insert(Node* root, int x) {
    if (!root) return new Node(x);
    Node* cur = root;
    Node* parent = nullptr;
    while (cur) {
        parent = cur;
        if (x < cur->val) cur = cur->left;
        else cur = cur->right;
    }
    if (x < parent->val) parent->left = new Node(x);
    else parent->right = new Node(x);
    return root;
}

// find minimum in subtree
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// delete node with value x from BST
Node* bst_delete(Node* root, int x) {
    if (!root) return nullptr;
    if (x < root->val) root->left = bst_delete(root->left, x);
    else if (x > root->val) root->right = bst_delete(root->right, x);
    else {
        // found node
        if (!root->left) {
            Node* r = root->right; delete root; return r;
        }
        else if (!root->right) {
            Node* l = root->left; delete root; return l;
        }
        else {
            // two children: replace with inorder successor
            Node* succ = findMin(root->right);
            root->val = succ->val;
            root->right = bst_delete(root->right, succ->val);
        }
    }
    return root;
}
```

## Balanced BSTs: AVL & Red-Black (overview)

Balanced trees ensure `O(log n)` operations. Two popular choices:

* **AVL trees**: strictly balanced; maintain height difference (`balance factor`) in `{-1,0,1}` via rotations. Faster lookups, more rotations on inserts/deletes.
* **Red-Black trees**: looser balance but fewer rotations. Many STL implementations (e.g., `std::map`, `std::set`) use red-black trees.

Detailed implementations are long; the ideas revolve around rotations (left/right), recoloring (for RB), and maintaining invariants.

## Serialization / Deserialization

A common task is serializing a tree to store or transmit and deserializing it back. Two standard techniques:

1. **Preorder with null markers** — write node values in preorder and use a special token (eg `#`) for `nullptr`. On deserialization, read tokens and reconstruct recursively.
2. **Level-order (BFS) with null markers** — useful for preserving structure for complete-ish trees.

Example (preorder with markers):

```cpp
// serialize to string using preorder; values separated by commas; use '#'
void serialize(Node* root, ostringstream &out) {
    if (!root) { out << "#,"; return; }
    out << root->val << ',';
    serialize(root->left, out);
    serialize(root->right, out);
}

Node* deserialize_helper(istringstream &in) {
    string token;
    if (!getline(in, token, ',')) return nullptr;
    if (token == "#") return nullptr;
    Node* node = new Node(stoi(token));
    node->left = deserialize_helper(in);
    node->right = deserialize_helper(in);
    return node;
}

string serialize_tree(Node* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
}

Node* deserialize_tree(const string &s) {
    istringstream in(s);
    return deserialize_helper(in);
}
```

Notes: `serialize` size is `O(n)` and round-trips exact structure.

## Memory, performance, and tradeoffs

* **Pointer-based nodes**: allocate `Node` objects separately; memory overhead per node includes pointers and allocation metadata. Good for sparse trees.
* **Array-based (vector)**: contiguous storage. Excellent cache locality for complete trees (heaps), but wasteful for sparse trees.
* **Smart pointers**: consider `unique_ptr<Node>` for RAII ownership; careful with raw pointer algorithms that assume raw `Node*`.
* **Recursion depth**: naive recursion may overflow for skewed trees with depth \~ `10^5`. Use iterative algorithms or increase stack if necessary.

Complexities (typical):

* Traversals: `O(n)` time, `O(h)` recursion stack or `O(n)` worst-case.
* Height/size computations: `O(n)`.
* Insert/delete/search for arbitrary binary tree: `O(n)`; for BST `O(h)`.

## Compact ASCII diagrams (kept narrow)

Perfect binary tree (height 2):

```
   [A]
  /   \
 [B]  [C]
 / \  / \
[D][E][F][G]
```

Complete but not perfect:

```
   [1]
  /   \
 [2]  [3]
 / \  /
[4][5][6]
```

Skewed (degenerate):

```
[10]
  \
  [20]
    \
    [30]
```

## Problems & exercises

1. **Implement** recursive and iterative preorder/inorder/postorder for a tree.
2. **Compute diameter** of a binary tree (longest path between two nodes). Aim for `O(n)`.
3. **Serialize & deserialize** a binary tree and verify round-trip equality.
4. **Find LCA** (Lowest Common Ancestor) for two nodes in `O(n)` and then explore faster methods for many queries.
5. **Transform** a tree into its mirror and verify symmetric property.
6. **Given inorder and preorder (or postorder) traversals**, reconstruct the tree.
7. **Check if a binary tree is a BST**.
8. **Convert BST to sorted doubly linked list** in-place.

## Worked example: diameter (O(n))

We compute longest path that may pass through root or entirely inside left/right subtree. Use postorder to compute height and diameter simultaneously.

```cpp
// returns pair {height, diameter}
pair<int,int> height_diameter(Node* root) {
    if (!root) return {0, 0};
    auto L = height_diameter(root->left);
    auto R = height_diameter(root->right);
    int h = 1 + max(L.first, R.first);
    int through_root = L.first + R.first; // edges count; adjust if you prefer nodes count
    int diam = max({L.second, R.second, through_root});
    return {h, diam};
}

int diameter(Node* root) {
    return height_diameter(root).second;
}
```

Comment: a small variant counts nodes instead of edges. Pick consistently.

## Best practices & tips

* Choose array representation if tree is complete or almost complete (heaps, tournament trees).
* Use smart pointers (`unique_ptr`) for ownership when building trees in modern C++ — avoids leaks.
* For competitive programming, raw pointers and manual `new/delete` are common — but free memory if reusing across test cases.
* When recursion depth could be large, convert to iterative or tail-recursive style if possible.
* Always be consistent about whether height is measured in nodes or edges; document your choice.

## References & further reading

1. CLRS (Cormen et al.) — chapter on trees and balanced trees.
2. Sedgewick & Wayne — Algorithms, sections on BSTs and balanced trees.
3. Online problem sets: LeetCode, CSES, Kattis for binary-tree practice problems.

---

*End of chapter.*
