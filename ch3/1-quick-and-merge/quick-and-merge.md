# Challenge 1

### Specifications

- Recursive merge sort
  - `double`
    - Test routine
  - `char[]`
    - Test routine
- Recursive quick sort
  - `double`
    - Test routine
  - `char[]`
    - Test routine

### Reflection

This exercise sets a tone for the rest: use what you can and do your best. It
surely took me by surprise. Having plenty of introductory level exposure to
sorting algorithms, I felt confident going into implementing some sorting
algorithms; that confidence swiftly vanished upon opening my editor. Looking
back at the text revealed that I had been duped: strings are creeping from the
shadows for which don't get a type definition, functions are yet to be covered
until chapter 7, and pointers are black magic. I'm a babe in the woods!

Yet all the tools have been given at the outset. In this text, the reader has
much in common with a prospector, who only needs a shovel (and maybe a sifting
pan). While the returns may not compare to those more experienced, nor hands as
clean, we do walk away with nuggets of value. Therein lies the excitement, the
experience of problem solving in ignorance. 

All this to say, the solution I provided in this first challenge is not good,
safe, or pretty-- it's quite messy and doesn't compare to future challenges thus
far (at the time of writing: up to 6), but it is evidence of learning the hard
way. 

I come back to revise these as more progress is made. This one in particular
serves as a lighthouse of the start. Whenever something new is learned, it
glimmers such that I can safely touch base and do some housekeeping while I'm at
it.

In the initial implementation, I was able to move on once the sorts have been
implmented to varying degrees of success. Both sorts worked according to
textbook definition on doubles, but I fell into the trap of segmentation faults
using string operations. It wasn't until chapter 6 that I was able to solve
these problems with enough precision to avoid them again. 

Currently, quick sort on strings is giving me a trace trap error which I don't
know how to deal with at this time, but I'm keeping my eye open and will return
here once the lighthouse sparks my periphery again.
