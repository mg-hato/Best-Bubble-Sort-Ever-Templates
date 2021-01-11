# Why the operator()?

No particular reason. It is chosen because of the consistency with other comparators of similiar nature.

For example, both priority queue and (ordered) set use such comparators.
And comparators providing `<`-operator for type `T` are identified as `std::less<T>`, which also implement `operator()`.

As such, on line 39 we use `decimalDigitOrdering` discussed previously and pass it as the comparator for native C++ priority queue.

As such, the simple journey of C++ templates ends here. 