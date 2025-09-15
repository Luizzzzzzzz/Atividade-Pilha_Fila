# Data Structures Project – Queue and Stack in C

## 📌 Overview
This project was developed for my **Data Structures** course.  
It implements two fundamental data structures in C: **Queue (FIFO)** and **Stack (LIFO)**, with dynamic memory allocation using `malloc` from the `malloc.h` library.


## 🔹 Queue Implementation
The queue supports the following functionalities:
- **Insertion**: Add an element to the queue.
- **Dynamic allocation**: Using `malloc` to manage memory.
- **Removal**: Remove an element from the queue.
- **Display**: Show all elements and their respective positions.
- **Check if full**: Verify if the queue is at maximum capacity.
- **Search element**: Locate an element in the queue:  
  - Returns `-1` if the element is not found.  
  - Returns the element's position if found.  

## 🔹 Stack Implementation
The stack includes the following operations:
- **Insertion (Push)**: Add an element on top of the stack.
- **Dynamic allocation**: Memory management with `malloc`.
- **Removal (Pop)**: Remove the top element from the stack.
- **Peek**: Show the top element **without removing it**.
- **Check empty/full**: Verify if the stack is empty or full.


## ⚙️ Technical Details
- **Language:** C  
- **Memory management:** Dynamic allocation with `malloc` (`malloc.h`)  
- **Structures covered:** Queue (FIFO), Stack (LIFO)  


## 🚀 Future Improvements
- Add error handling for edge cases (e.g., underflow/overflow).  
- Implement interactive menu for testing both structures.  
- Expand functionality (e.g., clear queue/stack, resize dynamically). 
