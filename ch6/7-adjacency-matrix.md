# Challenge 7: Adjacency Matrix

### Specifications

- Adjacency matrix of an unweighted graph
- Breadth-First Search algorithm
- Find connected verticies
- Find a spanning tree

### Reflection

##### First Impressions

The standout lesson from all of these challenges is that I desperately need to
brush up on my math. Thankfully, plenty of resources are available to hone in
on specific topics, but at times it feels that I'm getting such a small piece
of the picture. There is a level of intuition that can be utilized in all of
these problems but they're designed in such a way where intuition falls short
for me. Hats off to you, Gustedt. Now I *have* to learn something.

I did some research on breadth-first search (BFS) once the adjacency matrix of
an unweighted graph had been implemented. BFS has much in common with
depth-first search (DFS), the key difference being BFS enqueues next targets
whereas DFS stacks them. With what I know currently, and some things I don't, I
was able to implement a queue struct that wraps an array that is arbitrarily
large and tracks the first and last indicies of the window in which the queue
contains its elements. From there, I introduced queue functions. Knowing that
`struct`s are passed by value unlike arrays, I decided to utilize parameterized
pointers, despite not covering their use in the text yet. 

Much like challenge 2, I felt this to be a potent yet reasonable introduction
to pointers as parameters and its applications. It was a simple enough case
that the growing pains are reasonably justifiable for the end result.

# Sources
- Modern C, Jens Gustedt
- [BFS algorithm (trees)](https://en.wikipedia.org/wiki/Breadth-first_search)
- [BFS on
  graphs](https://web.archive.org/web/20150326055019/http://www.graph500.org/specifications#sec-6)
