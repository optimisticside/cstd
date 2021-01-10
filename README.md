# C-std
C-Std is a very lightweight library written in ANSI C that implements some classes you would find in the C++ standard library, such as a dynamic-array, linked-list, stack, and queue. It's published under the Unlicense, meaning you can do whatever you want with it without any restrictions.

It currently contains the following modules:
 - dynarray - An implementation of a dynamic array, comparable to C++'s vector
 - list - An implementation of a singly linked list, comparable to C++'s list (although it's doubly linked)
 - queue - An implementation of a queue (FIFO), comparable to C++'s queue
 - stack - An implementation of a stack (LIFO), comparable to C++'s stack
 - deque - An implemeentation of a double-ended queue data-structure (has the ability to perform operations on the front and back), comparable to C++'s deque
 - map - An implementation of a hashmap, comparable to C++'s map
 - bitmap - An implementation of an array of booleans/bits with the ability to store eight in one byte with masking, comparable to C++'s bitset