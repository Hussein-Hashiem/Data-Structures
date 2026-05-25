# Data Structures

A personal study repository containing from-scratch implementations of core data structures in **C++**, built while learning Data Structures as a college course. Everything here is implemented manually — no STL containers used for the actual structures (only where explicitly noted).

---

## Contents

### 🔗 Lists

| File | Description |
|---|---|
| `Linked List.cpp` | Singly linked list — generic (`template`), supports insert at front/back/position, delete, reverse, search, and print |
| `Doubly Linked List.cpp` | Doubly linked list — generic (`template`), bidirectional traversal, insert at front/back, delete |
| `Array Based List Implementation.cpp` | Dynamic array-backed list with insert, update, delete at position, and boundary checking |

---

### 📚 Stacks

| File | Description |
|---|---|
| `Stack Implementation.cpp` | Array-based stack — generic (`template`), push, pop (with and without return), peek, print |
| `Stack Using Linked List Implementation.cpp` | Linked-list-based stack — generic (`template`), dynamic memory, push, pop, peek |

---

### 🔁 Queues

| File | Description |
|---|---|
| `Queue Implementation Using Circular Array.cpp` | Circular array queue — generic (`template`), enqueue, dequeue, get front/rear, search, print |
| `Queue Implementation Using Linked List.cpp` | Linked-list queue — generic (`template`), enqueue, dequeue, peek front |
| `Queue Using Two Stacks.cpp` | Queue built on top of two STL stacks — demonstrates how to simulate FIFO using LIFO |

---

### 🌳 Trees

| File | Description |
|---|---|
| `Binary Tree.cpp` | Binary tree with full DFS traversals (Preorder, Inorder, Postorder) and BFS Level-order traversal; includes tree deletion |
| `Binary Search Tree.cpp` | BST with insert, search, delete (with proper successor handling), and Level-order traversal |

---

### ⚙️ Stack Applications

| File | Description |
|---|---|
| `Infix expression to Postfix expression.cpp` | Converts an infix expression to postfix using a stack; handles operator precedence and parentheses |
| `Expression Evaluation.cpp` | Evaluates a postfix expression using a stack; supports multi-digit numbers |

---

## Key Concepts Covered

- Pointer manipulation and dynamic memory allocation (`new` / `delete`)
- Template classes for generic data structures
- Recursive vs iterative tree traversal
- Circular indexing for array-based queues
- Operator precedence and associativity in expression parsing
- Soft boundaries and edge-case handling (empty/full checks)

---

## Notes

- All implementations are written from scratch as learning exercises — clarity and correctness are the priority over performance optimization.
- Templates (`template<class t>`) are used in most structures to make them generic.
- The tree files use a function-based approach (free functions + struct) instead of a class, reflecting how trees are commonly introduced in DS courses.

---

## Author

**Hussein Hashiem** 
