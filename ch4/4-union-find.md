# Challenge 4: Union-Find

### Specifications[^1]

- `Find` function that for a given index finds the root of its tree
- `FindReplace` Changes all `parent` entries on a path to the root (including)
  to a specific value
- `FindCompress` Changes all `parent` entries to the root that has been found
- `Union` For two eleemnts, combines their trees into one.
  - `FindReplace` for one side and `FindCompress` for the other

### Reflection

This challenge was easy enough conceptually and to implement. Although not
having heard of this specific data structure, I was able to determine that this
section was about tree graphs, and the implementation followed nicely. 

The real challenge of this one was the specification itself. All of which was
transparent enough until arriving at `FindCompress`, in particular. I read and
reread the specification of this function for hours as I was having trouble
settling on an implementation that satisfied the strange wording. The root (hah)
of the issue for all of my interpretations is that all of them fundamentally
compromise the structure of the tree. 

The most direct interpretation of this is it changes the entire structure to
share the same root, which I asserted was not useful and thus discarded the
interpretation. The second interpretation is such that all siblings of the given
element's subtree are to be changed to the root that's found, which is to say
that it's a kind of *super* operation of `FindReplace` the difference lying in
the targeted nodes on the path to the root; granted, this is more *useful*, yet
still fundamentally alters the structure of the tree. 

I've settled on implementing the latter, but for the `Union` function, I simply
made it such that the root of the second tree is made to be that of the first
which, according to my research and bias, is in the spirit of a union operation.

# Sources

- [^1]: Jens Gustedt, Modern C
