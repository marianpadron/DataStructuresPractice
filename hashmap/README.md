## Hashmap

**Completed March 2023**

Homework assignment in which I implemented a hashmap using a **DJB2** hashing function. It is a simple implementation of the data structure, and its methods were tested using simple unit tests. These were completed based on a rubric, and it is important to note that while the majority of the code is mine, I did receive collaboration and help from TAs and the professor.

## Questions

1. Add a markdown table demonstrating the in practice time for Hashmaps. 

| Time Complexity | Insertion | Deletion | Lookup |
|-----------------|-----------|----------|--------|
| Average Case    | O(1)      | O(1)     | O(1)   |
| Worst Case      | O(n)      | O(n)     | O(n)   |

The worst case in hashmaps occurs when there are collisions, in this case the time complexity is O(n) becuase all elents in the linked list have to be examined sequentially.

2. What is the worst case time for a hashmap, even if rare, can you come up with a condition that always generates worst case?

  The worst case scenario for a hashmap is if there are a lot of collisions created from the hash method. If there are many collisions the time complexity of searching,       inserting, and deleting can go up significantly. An worst case example would be a bandly implemented hash, where all elements in the table hash to a single index. The       hashmap will essentially become a linked list and will have the corresponding worst case time complexity of O(n).

3. Looking back at the Lab09, how often did you see collisions from the various data sizes? (go ahead and copy/paste the output from the lab)

movie_ids_us_1000.txt...
Collisions: 999, Highest: 81, Average Length > 1: 38.42, Filled Spots: 27, Load: 0.00001
Collisions: 507, Highest: 3, Average Length > 1: 2.08, Filled Spots: 737, Load: 0.00037
Collisions: 0, Highest: 0, Average Length > 1: -nan, Filled Spots: 1000, Load: 0.00050
Collisions: 0, Highest: 0, Average Length > 1: -nan, Filled Spots: 1000, Load: 0.00050

movie_titles_us_1000.txt...
Collisions: 645, Highest: 5, Average Length > 1: 2.42, Filled Spots: 622, Load: 0.00031
Collisions: 402, Highest: 5, Average Length > 1: 2.21, Filled Spots: 780, Load: 0.00039
Collisions: 22, Highest: 2, Average Length > 1: 2.00, Filled Spots: 989, Load: 0.00049
Collisions: 24, Highest: 2, Average Length > 1: 2.00, Filled Spots: 988, Load: 0.00049

movie_ids_us_10000.txt...
Collisions: 9999, Highest: 697, Average Length > 1: 285.69, Filled Spots: 36, Load: 0.00002
Collisions: 10000, Highest: 15, Average Length > 1: 10.00, Filled Spots: 1000, Load: 0.00050
Collisions: 110, Highest: 2, Average Length > 1: 2.00, Filled Spots: 9945, Load: 0.00497
Collisions: 62, Highest: 2, Average Length > 1: 2.00, Filled Spots: 9969, Load: 0.00498

movie_titles_us_10000.txt...
Collisions: 9998, Highest: 26, Average Length > 1: 10.02, Filled Spots: 1000, Load: 0.00050
Collisions: 9928, Highest: 17, Average Length > 1: 5.21, Filled Spots: 1978, Load: 0.00099
Collisions: 838, Highest: 4, Average Length > 1: 2.12, Filled Spots: 9557, Load: 0.00478
Collisions: 814, Highest: 4, Average Length > 1: 2.13, Filled Spots: 9568, Load: 0.00478

movie_ids_us_100000.txt...
Collisions: 99999, Highest: 6029, Average Length > 1: 2222.20, Filled Spots: 46, Load: 0.00002
Collisions: 99636, Highest: 120, Average Length > 1: 69.38, Filled Spots: 1800, Load: 0.00090
Collisions: 4200, Highest: 3, Average Length > 1: 2.01, Filled Spots: 97889, Load: 0.04894
Collisions: 4742, Highest: 3, Average Length > 1: 2.02, Filled Spots: 97608, Load: 0.04880

movie_titles_us_100000.txt...
Collisions: 100000, Highest: 195, Average Length > 1: 100.00, Filled Spots: 1000, Load: 0.00050
Collisions: 100000, Highest: 96, Average Length > 1: 50.03, Filled Spots: 1999, Load: 0.00100
Collisions: 21811, Highest: 17, Average Length > 1: 2.46, Filled Spots: 87056, Load: 0.04353
Collisions: 21886, Highest: 17, Average Length > 1: 2.46, Filled Spots: 87023, Load: 0.04351

movie_ids_us_unique.txt...
Collisions: 924735, Highest: 38290, Average Length > 1: 8723.92, Filled Spots: 107, Load: 0.00005
Collisions: 924736, Highest: 976, Average Length > 1: 462.60, Filled Spots: 1999, Load: 0.00100
Collisions: 339502, Highest: 6, Average Length > 1: 2.16, Filled Spots: 742110, Load: 0.37106
Collisions: 342185, Highest: 7, Average Length > 1: 2.17, Filled Spots: 740572, Load: 0.37029

movie_titles_us_unique.txt...
Collisions: 925175, Highest: 1579, Average Length > 1: 925.17, Filled Spots: 1000, Load: 0.00050
Collisions: 925175, Highest: 978, Average Length > 1: 462.82, Filled Spots: 1999, Load: 0.00100
Collisions: 461694, Highest: 200, Average Length > 1: 3.11, Filled Spots: 611734, Load: 0.30587
Collisions: 461793, Highest: 200, Average Length > 1: 3.11, Filled Spots: 611832, Load: 0.30592

4. To make this hashmap fully usable - what are some functions missing that should be implemented? (props if you implement them!)
   * if you are stuck, think about how would someone get all the names of the food items, if they are doing inventory?
   - a count method to count all items in the hashmap
   - a get keys method that returns all possible keys in the hashmap
   
5. How can hashmaps help you with dynamic programming? Are they effective mechanisms for caches? 

Hashmaps can help with dynamic programming by being an effective storage method used to retreive data as an algorithm is called recursively. When using dynamic programming we are breaking down a problem into smaller problems, which then get solved and their results stored to be used by the larger problem. Using hashmaps is an effective method of keeping a faster runtime because of their retreival time complexity of O(1). They can also be effective machanisms for caches depending on the size of the cache and the access pattern for the data. With caches we store frequently used data in fast memory location, which makes a hashmap more effective than using other more time consuming memory allocations such as a database. 

Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource
- DBJ2 hash: https://gist.github.com/MohamedTaha98/ccdf734f13299efb73ff0b12f7ce429f
- calloc: https://www.educative.io/answers/what-is-calloc-in-c
- calloc vs malloc : https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/
- time complexity of hashmaps: https://linuxhint.com/hashmap-time-complexity-cpp/
