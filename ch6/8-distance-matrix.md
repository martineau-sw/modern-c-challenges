# Challenge 8: Distance Matrix

### Specifications

- Construct a distance matrix where `SIZE_MAX` represents unreachable vertices
- Find the shortest path between two vertices

### Reflection

This challenge is an extension from the previous one. To kick it off, I copied
the source from the previous one since the functions will be useful here.
The plan is to define a new matrix type based on `size_t` values and implement
Dijkstra's algorithm since breadth-first search is quite similar.

In order to adapt the breadth-first search to Dijkstra's we need a way of
assigning values to the verticies, to get a minimum value, and output the path.
The `explored` array can be rewritten as a `size_t` array initialized to
`SIZE_MAX` to represent values of visited vertices. A minimum function is
necessary to find vertex values in the case that two edges arrive at the same
vertex; for this, we can pass in the row of the vertex to get all adjacent
vertices and use `explored` to determine if a vertex has a value to be
considered for a minimum function. Finally, to output the intended path, we
simply `print` the vertex that's selected as the minimum since that's when an
edge is "finalized." 
# Sources

- Jens Gustedt, Modern C
