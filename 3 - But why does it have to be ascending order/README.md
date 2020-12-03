# But why does it have to be ascending order

Using templates once again, we give up on the specific ordering and introduce a generic one, labelled as `Compare`.

The `Compare` has `operator()` that takes two items of type `T`, say `x` (left) and `y` (right),
and returns true if and only if `(x,y)` is in the relation defined by `Compare`.

From mathematics point of view, a relation `R` over a set `A`, is a subset of `A` cartesian-product with `A`.
And less-than (`<`) is also a relation, where set `A` is all the integers that `int` type covers; and pair (3, 10) is in `<` while (10, 3) isn't.

For type `T` we can also define a relation in such a way, just by defining the `test` function.

