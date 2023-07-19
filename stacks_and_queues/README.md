## Stacks and Queues

 **Completed January 2023**

Homework assignment in which I wrote my own queue and stack libraries to better understand how they are implemented and work. They are simple implementations of both data structures, and their methods were tested using simple unit tests. These were completed based on a rubric, and it is important to note that while the majority of the code is mine, I did collaborate with the TAs and the professor.

### Further Thinking Questions

1. Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and answer this question specifically: Why is a ring buffer useful and/or when should it be used? 

Ring buffers (circular buffers) are implemented using a fixed sized array and FIFO (first-in-first-out) odering. The buffer holds the array which contains the data, the location of the next available slot to insert an element, the front or "head" of the buffer, the size of the buffer, and its total capacity. Circular buffers use the mod operator to create a wrapped sequence and it has the capacity to write (queue) data, read (dequeue) data, and overwrite data if necessary.

Because of its construction and use of FIFO data access, ring buffers allow for efficient memory access with a best runtime complexity of O(1). This makes it efficient and useful for running simple and fast programs. The simple data structure of a ring buffer makes it useful for collecting and processing data streams and can be applied to things such as: buffering data streams, computer controlled trafficking signal systems, memory management, and CPU scheduling. Its fixed size also means that the buffer does not need to move/reorganize data. Additionally, because it doesn't implement dynamic memory, it reduces the chances of a memory leak.

Some disadvantages of using the ring or circular buffer include its fixed size. Although a work around this would be to include dynamic sizing, the moving and allocating of the data in order to achieve this defeats the purpose of the circular buffer's O(1) access time. For this reason buffers should be used for the collecting and processing of simple data streams with a fixed size.

Citations:

Srivastava, Priyank. “Implementing a Ring Buffer in Java.” Baeldung, 24 Nov. 2022, https://www.baeldung.com/java-ring-buffer#:~:text=Advantages%20and%20Disadvantages,require%20a%20shifting%20of%20elements. 

Ward, Brian. “Circular Queue or Ring Buffer.” Medium, Towards Data Science, 1 May 2020, https://towardsdatascience.com/circular-queue-or-ring-buffer-92c7b0193326. 


2. We are going to talk about stacks quite a lot in this course, so it will be important to understand them. Do a little outside research, and edit this section of the readme answering specifically: Why is a stack useful and/or when should it be used?

Stacks are a linear data structures that operate by using a LIFO (last-in-first-out) method of managing data. They can be implemented using linked lists or arrays. When using a linked list, stacks hold the current size of items in the stack, its maximum capacity, and the location of the last item added to the stack. Keeping track of this allows the data structure to implement its most common push() and pop() methods. 

Similar to circular buffers, stacks have a runtime complexity of O(1) when popping a value. When pushing an object into the stack, the best case scenario would allow for a runtime complexity of O(1), and a worst case scenario of O(n). This makes this type of data structure very efficient and allows for multiple applications. Stacks are used in a variety of programming languages such as Python and Java, and its structure is often implemented when preforming tasks such as: evaluating expressions with operands and opeations, matching tags with HTML and XML, backtracking, conversion of arithmetic notations, and systematic memory management. Stacks are used to implement functions within programs, and are useful for processing nested structures and for recursion.

Besides their fast runtime, some advantages of stacks are that they are not easily corrupted and have very good control of memory allocation and deallocation. Disadvantages include their limited memory size and inability of random access within the stack. Additionally, if not implemented correctly, running a stack could lead to issues such as a stack overflow.

Citations:

“Applications, Advantages and Disadvantages of Stack.” GeeksforGeeks, GeeksforGeeks, 13 June 2022, https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-stack/. 

“Defining a Stack as an Abstract Data Type.” Stacks, https://www.cse.unr.edu/~sushil/class/cs202/notes/stacks/stacks.html.

### Other Resources

* [Data Structure Visualizations](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)
* [Queue High Level Description](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
* [Stack High Level Description](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
* [Example Single File C Libraries](https://github.com/nothings/single_file_libs)
* [Are header only libraries more efficient?](https://softwareengineering.stackexchange.com/questions/305618/are-header-only-libraries-more-efficient)
* [Header Files from GCC](https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html)
* [Circular Buffer](https://en.wikipedia.org/wiki/Circular_buffer)


