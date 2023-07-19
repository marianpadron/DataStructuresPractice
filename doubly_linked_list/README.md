# Homework 04: Doubly Linked List

Name: Marian Padron

Github Account name: mpadron-neu

How many hours did it take you to complete this assignment (estimate)? 3-4hrs

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  

- Time complexities of different data structures : https://www.geeksforgeeks.org/time-complexities-of-different-data-structures/


(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## Understanding Time Complexity

1. Using a markdown table and markdown/latex math, show the BigO for Arrays, Singly Linked Lists, Doubly Linked Lists (so total of 3). For the columns, you will look at the Average Case Time Complexity for Access, Search/Find,	Insertion, and Deletion. 

| Big O Table         | Access | Search / Find |  Insertion   |  Deletion   | 
|---------------------------------------------------------------------------|
| Arrays              |  O(1)  |     O(n)      |     O(n)     |     O(n)    | 
| Singly Linked Lists |  O(n)  |     O(n)      | O(n) or O(1) | O(n) or O(1)| <- when inserting or deleting at the
| Doubly Linked Lists |  O(n)  |     O(n)      | O(n) or O(1) | O(n) or O(1)| head or tail of list, runtime = O(1);
                                                                            when going through the list to insert at a specific location, runtime = O(n) + O(1) = O(n)

2. Usually for singly and doubly linked lists, we reference both the head and tail for speed considerations. What would be the cost if you only had your head referenced, and you wanted to push to the tail of either?  $O(?)$

For both, only having the head referenced would mean a runtime of O(n) because you would have to iterate through every item in the linked list to get to the final (n) value.

3. Name an example where an array is better than a linked list, and an example where a linked list is better than an array. Make sure to reference the big O as part of your reasoning. 

Linked lists are very time efficient when it comes to changing the location of data, and inserting or deleting at the end or front of the list (O(1)). Because linked lists use nodes with pointers to the location of data, they don't require the same rearraging of data as an array which has a set memory location. This makes using linked lists in situations where things may need to be added or changed very efficient. An example of this could be a digital phone book, where everytime you add the phone number of a person, you would need to rearange the data to fit the alphabetical order of people's names. On the other hand, arrays are very efficient at fetching or accessing data from a given location (O(1)). Arrays are a good structure to use when working with set data that is very unlikely to grow or change, and that requires quick access. An example of this would be to hold student grades in a fixed sized classroom, where you can access a student's grade depending on its location in the array and quickly update it.

Note: Make sure look at your finished markdown in the browser hosted on github or via a markdown preview extension. To confirm the notation is showing up properly. 

## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

