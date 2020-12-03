# Starting with bubble sort

We start with the magnificent bubble sort algorithm described in lines 4-14. The algorithm will be sorting a `vector` of `int` and it uses operator `<` to sort it in non-decreasing order.

Two helping functions are provided for printing purposes, the first being `printVector` (lines 16-21) that just prints the contents, the second being `printSortPrint` (lines 23-29)well-described by its name.

A makefile is provided offering three simple rules:
- `prog.o` - to compile the main file into the object file
- `run` - to run the object file
- `clean` - to delete the object file

The makefiles and these 3 function names will not change in the further enhancements.

The bubble sort works, all is swell and well. But say we want to also sort strings with it.

Easy: copy-paste and change the argument's type.