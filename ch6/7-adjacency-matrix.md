# Challenge 7: Adjacency Matrix

### Specifications[^1]

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

I did some research on breadth-first search (BFS)[^2][^3] once the adjacency matrix of
an unweighted graph had been implemented. BFS has much in common with
depth-first search (DFS), the key difference being BFS enqueues next targets
whereas DFS stacks them. With what I know currently, and some things I don't, I
was able to implement a queue struct that wraps an array that is arbitrarily
large and tracks the first and last indicies of the window in which the queue
contains its elements. From there, I introduced queue functions. Knowing that
`struct`s are passed by value unlike arrays, I decided to utilize parameterized
pointers, despite not covering their use in the text yet.

After translating the pseudocode from wikipedia[^2], I asked a friend to check my
work thus far to ensure I'm not making any catastrophic mistakes. This they did
no problem, additionally, they also advised that I instead use a circular
structure for the array queue so I don't have to worry much about boundary
checking. This was excellent insight as the queue is still functionally
identical and I needn't worry about checking the boundaries of the array. 

The standout constraint of an array based dynamic structure like a queue is the
array is of fixed size which limits the size of the matrix that can be
inputted. By exactly how much I am not sure, but it lies beyond the scope of
the problem. The solution requires heap allocation to allow for dynamic array
resizing which also lies beyond the scope of what I currently know. I will
return with this solution once it has been made available by the text.  

As far as I understand, there are several ways to find or construct a spanning
tree from a given graph. It was difficult to decide on an approach as I'm
attempting to balance the semantics of the prompt *"Find a spanning tree"* as
well as my own objectives in a self-paced exercise with reasonable velocity. I
went with a solution that determines if a spanning tree exists satisfying that
there are at least two adjacent verticies such that they don't form an
undirected cycle.

Playing around with the adjacency matrix on paper, I found that for a square
adjacency matrix of side length N, one can sum the columnar elements above the
diagonal (to disregard self cycles), and if the columnar sum is equal to one,
then that vertex does not form a cyclical graph. A sum of zero implies an
orphaned vertex. For columnar sum greater than one in graphs with verteces less than
or equal to 4 we can stop the operation since a cycle of minimum length of three
will cause the entire undirected graph to be cyclical disqualifying it.

Much like challenge 2, I felt this to be a potent yet reasonable introduction
to pointers as parameters and its applications. It was a simple enough case
that the growing pains are reasonably justifiable for the end result.

# Sources
- [^1]: Modern C, Jens Gustedt
- [^2]: [BFS algorithm (trees)](https://en.wikipedia.org/wiki/Breadth-first_search)
- [^3]: [BFS on graphs](https://web.archive.org/web/20150326055019/http://www.graph500.org/specifications#sec-6)
