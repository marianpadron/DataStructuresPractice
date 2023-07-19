## Binary Search Trees (BST)

Name: Marian Padron

Homework assignment in which I implemented Binary Search Tree, as well as some utility functions. 
It is a simple implementation of the data structure, and its methods were tested using simple unit tests. 
These were completed based on a rubric, and it is important to note that while the majority of the code is mine, 
I did receive collaboration and help from TAs and the professor.

### BST Questions

1. Given a *balanced* and *full* Binary Search Tree, what is the Big O for finding a value in the tree?

   Given a balanced and full binary tree we know that the Big O of finding a value would be the same as the Big O of searching using a binary search, Big O of O(log n). This is because if the tree is full we know that each node has exactly zero or two children; and if the tree is balanced the left and right heights are proportional. This allows the search within the tree to be split in half everytime we search within a node, similar to when when conducting a binary search.

2. Define balanced in relation to BSTs. Remember to relate it to height. 

   A balanced binary tree is one in which the left height and the right height of the tree are equal. Meaning all nodes have either two children or no children. This minimizes the height of the tree by keeping the tree from skewing in one direction. By doing this the height of the BST is approximately log of n, with n being the nodes in the tree.

3. What is the Worst Case Big O for searching or adding to a BST?
   * What type of BST would this be? (how would it look)

   The worst case Big O time complexity of searching or adding to a BST would be of O(n), with n being the number of nodes in the tree. This could occur given an unbalanced tree, where if all nodes are towards one side of the tree it would essentially become a linear structure, having to iterate through n times until it finds the nth value in the tree. Having a balanced tree minimizes the height and therefore search/insertion time for the tree.

4. What are some of the advantages of a BST over a linked list?

   In terms of search and insertion BSTs are better than a linked list due to its Big O time complexity of O(log n). BST also adds data in an ordered manner unlike a linked list, which also allows for its fast search time complexity. Depending on where you are inserting or deleting in a linked list, its Big O time complexity can vary between O(1) (if inserting/deleting at the beginning of the list) or Big O(n). In general, searching in a linked list could also take O(n).

5. What are some cases / examples of when you would use a BST?

   Binary trees are very efficient for searching and sorting data, this makes it efficient for things such as database indexing where the indices of a given record are stored within the tree to be accessed easily later. Another use for binary trees, would be instances where linked lists are used, such as for handling collisions whithin a hashmap. Using a binary tree would make the search time of finding a key within a hashmap with several collisions faster than using a linked list.

### Resources
* [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
* [Visual Go](https://visualgo.net/en/bst)
* [Geeks for Geeks Binary Search Tree](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)
* [Program Wiz BST](https://www.programiz.com/dsa/binary-search-tree)


