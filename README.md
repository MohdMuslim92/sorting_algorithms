**0x1B. C - Sorting algorithms & Big O

This project includes implementations of various sorting algorithms in the C programming language. The sorting algorithms covered in this project are Bubble Sort, Insertion Sort, Selection Sort, and Quick Sort. Additionally, the project contains two files: print_array.c and print_list.c, which include the print_array and print_list functions respectively. These functions are used to print the elements of an array or a linked list.

**Compilation
To compile the project and generate the executable files, you can use the following command:

gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-bubble_sort.c 0-main.c print_array.c -o bubble
This command will compile the source files 0-bubble_sort.c, 0-main.c, and print_array.c, and generate the executable file bubble, and so on for the rest of the functions.

**Sorting Algorithms
* Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The algorithm continues iterating through the list until no more swaps are needed, indicating that the list is sorted.

The implementation of Bubble Sort can be found in the file 0-bubble_sort.c.

* Insertion Sort
Insertion Sort is a comparison-based sorting algorithm that builds the final sorted array one item at a time. It takes one element from the input data and places it in the correct position within the sorted portion of the array.

The implementation of Insertion Sort can be found in the file 1-insertion_sort_list.c.

* Selection Sort
Selection Sort is an in-place comparison sorting algorithm. It sorts an array by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning.

The implementation of Selection Sort can be found in the file 2-selection_sort.c.

* Quick Sort
Quick Sort is a highly efficient sorting algorithm that uses a divide-and-conquer strategy to sort elements. It picks an element as a pivot and partitions the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

The implementation of Quick Sort can be found in the file 3-quick_sort.c.

**Function Usage
After compiling the project and generating the bubble executable, you can run it using the following command:

./bubble
The program will execute the sorting algorithm and provide the output accordingly.

**Contributing
If you would like to contribute to this project, feel free to fork the repository and submit a pull request. Contributions are always welcome!
