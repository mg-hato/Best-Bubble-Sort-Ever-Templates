# But why does it have to be ascending order

Using templates once again, we give up on the specific ordering and introduce a generic one, labelled as `Compare`.

The `Compare` has `operator()` that takes two items of type `T`, say `x` (left) and `y` (right),
and returns true if and only if `(x,y)` is in the relation defined by `Compare`.

## Relations primer

From mathematics point of view, a relation `A^2` (cartesian product of `A` with itself) is a set of pairs `(x,y)` for all `x` and `y` from the set `A`.
A relation `R` over the set `A` is just a subset of `A^2`. There are many kind of relations depending on whether they satisfy certain properties.

E.g. An operator `<` can be viewed also as a relation. If it is over integers (like `std::less<int>`), then it defines relation `R` over the set of all integers, such that
a pair of `(x,y)`, with both `x` and `y` being of type `int`, is a member of the relation `R` if and only if `x < y`.
In other words, `(x,y)` is a member of `R` if and only if `std::less<int>()(x, y)` returns true.

Hence, we shall proceed to create relations and orderings to our own taste, by defining the `operator()` which we can view as a membership query, rather than physically creating a relation-set `R`.

Furthermore, since we are interested in sorting, it makes sense for such a relation to have the following properties:

- `R` is not reflexive

- `R` is transitive

- `R` is not symmetric

Observe line 9 and the condition within the `if` statement: `Compare()(a[j], a[j-1])`

If that condition is true, we perform swap-operation. We write `<'` for short and use it infixed, so that the condition becomes `a[j] <' a[j-1]`.

If `a[j]` and `a[j-1]` are the same value, we can leave them as it is, without swapping them with one another. Hence, it makes sense for `<'` to not be reflexive.

If `x <' y` and `y <' z`, it would make sense that `x <' z` as well. Assume that is not the case. Then for an array `[z, x, y]`, since it is not the case that `x <' z`. They will not be swapped. And this might be even the sorted array, with `z` being at index 0, despite `y <' z`.

Lastly, symmtetry. If `x <' y` and `y <' x`, the sort would swap `x` with `y` always, regarding of who is left and who is right. Hence it makes sense for `<'` to be not symmetric.

## Other orders

At this point, we implement few more relations by defining `operator()`. We can define such a method within a `class` or within a `struct`.

On lines 41-58 we define a class `decimalDigitOrdering` that implements `operator()`. This class 'defines' a relation of integer pairs `(x,y)` such that number of digits in `x` is smaller than in `y`. E.g. `(12, 100)` is in this relation, as `12` is written with two digits and `100` with three. `(41, 49)` is not in this relation, as both have two digits in them. On line 80 we pass the class to be used within our sort.

On lines 63-67 we define a `stuct` called `stringSizeOrdering` which defines a relation between strings with respect to the size (length). On line 88, we pass the `struct` to be used within our sort. 