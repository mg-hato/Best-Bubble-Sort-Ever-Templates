# First template

Perhaps, copy-pasting and editing bits and pieces is not the best solution (certainly it works).
This is quite a fitting time for templates.

We use `template` keyword and change the `vector` type, and propagate the change in all 3 functions.
Now the same bubble sort is used to sort both `vec` (`vector<int>`) and `svec` (`vector<string>`) in the main's code.

Note that on line 37 we call `printSortPrint` without specifying that the `T` type is `int`, whereas we do specify the `T` type on line 40.
Lesson to take: it goes well with specifying, it goes well without it.

But say we want to also have a sort that produces non-increasing order; or some custom order. What then?

Easy: Copy-paste and change the `if` condition bit of the bubble sort code.