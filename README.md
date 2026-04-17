# 🌳 Generic Binary Search Tree (BST) System in C

An **interactive Binary Search Tree (BST) system** implemented in C, featuring dynamic data manipulation, multiple traversal methods, and graphical visualization.

---

## 🚀 Overview

This project goes beyond a basic BST implementation by providing a **menu-driven interface** that allows users to interact with the tree in real time.

Users can:

* Insert and remove elements
* Search for values
* Display the tree using multiple traversal strategies
* Visualize the tree structure graphically
* Reset the entire system

---

## 🛠️ Technologies Used

* C
* Standard libraries (`stdio.h`, `stdlib.h`)
* Modular programming with `.c` and `.h` files

---

## 🧠 Concepts Applied

* Binary Search Tree (BST) operations
* Dynamic memory allocation and pointers
* Modular architecture (separation of concerns)
* Abstract data handling via custom `Element` structure
* Tree traversal algorithms:

  * Preorder
  * Inorder
  * Postorder
  * Level-order (BFS)

---

## 🎮 Features

### 📌 Core Operations

* Insert new elements with validation
* Remove elements by value
* Search and display specific values

### 🌲 Tree Visualization

* Preorder traversal
* Inorder traversal
* Postorder traversal
* Level-order traversal (Breadth-First Search)
* Graphical tree display (structured visualization)
* Option to display all traversal methods at once

### 🔄 System Control

* Reset (erase entire tree)
* Input validation system
* Interactive CLI menu

---

## 🖥️ How It Works

The program runs a **loop-based interactive menu**, allowing the user to select operations:

```text
(1) Insert element
(2) Remove element
(3) Search element
(4) Reset tree
(5) Display options
(0) Exit
```

Display options include multiple traversal strategies and a graphical representation of the tree.

---

## 📂 Project Structure

```bash
BST.c / BST.h          -> Core BST logic
Element.c / Element.h  -> Generic element abstraction
GUI.c / GUI.h          -> Tree visualization functions
main.c                 -> Interactive system (menu + control flow)
```

---

## ▶️ How to Run

1. Clone the repository:

```bash
git clone https://github.com/GuilhermeParnaibaNunes/GenericBST.git
```

2. Compile the project:

```bash
gcc *.c -o bst
```

3. Run:

```bash
./bst
```

---

## 📈 What I Learned

* Implementing full CRUD operations on tree structures
* Managing dynamic memory safely in C
* Designing interactive CLI systems
* Applying multiple traversal algorithms in practice
* Structuring medium-sized C projects with modular design

---

## 🔮 Future Improvements

* Add tree balancing (AVL or Red-Black Tree)
* Improve graphical visualization
* Add persistence (save/load tree from file)
* Expand generic support for different data types

---

## 📌 Notes

This project was developed as part of **Data Structures studies**, focusing on both:

* Internal implementation of trees
* Practical interaction with the structure

---

## 👤 Author

Guilherme Parnaíba Nunes
🔗 https://github.com/GuilhermeParnaibaNunes
