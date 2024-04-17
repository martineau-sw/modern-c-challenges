# Challenge 1: Quick Sort and Merge Sort

### Specifications[^1]

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

##### 17 April 2024

In challenge 10, I was able to do some refactoring and resolve the trace trap
bug. Most refactoring decisions were motivated to find the source of the trace
trap bug during run time. To be precise, it signaled during `quick-sort-strings`
which exclusively uses the `swap_strings` function. Previously `swap_strings`
looked something like:

```C
void swap_strings(size_t i, size_t j, size_t strlen, char A[][strlen]) {
    char temp[strlen];
    strcpy(temp, A[i]);
    strcpy(A[i], A[j]);
    strcpy(A[j], temp);
}
```

Care has been taken so that strings within `A` are the same length and `0`
terminated. The temp `char` array has equal length, so that the source string
would fit, including its terminator, so for my intent, this was appropriate
usage of `strcpy` within context. With that I moved on to refactor the rest of
my code. 

Despite idiomatic assertions made by Gustedt, I changed array parameters to
pointer parameters since I've since learned array parameters decay into pointer
types. I did this for a couple of reasons, first this isn't production level
code, its for my educational benefit and given the *tone* of the exercise
mentioned previously, some experimental license can be afforded here. Second, I
wanted to play around with pointers and memory allocations; in the spirit of the 
exercise, I took it upon myself to find a little more information than what is 
presented. And finally, I had a strong feeling that it would improve legibility 
and make it easier to use without sacrificing much in the way of portability or 
safety considering I am not accepting user input.

All of those reasons have been realized in the refactor and after a little
digging, the source of the trace trap bug has been found. For a little context
I'm working on a 2021 M1 MacBook Air and it's my only machine. I use `clang` for
my compiler and I haven't learned how to use a debugger yet. Trace trap goes by
another name, `SIGTRAP` and is normally signalled when interruption occurs in
the same way debugger interrupts at breakpoints. In this case, my platform
interrupted the process because some instructions are simply disallowed[^2].
As you can imagine, it was the infamous `strcpy` that was the culprit. After all
of the detective work and refactoring I rewrote `swap_strings` to be something like: 

```C
void swap_strings(size_t i, size_j, char** S) {
    for (size_t len = 0; S[i][len] != 0; ++len);
    char* temp = (char*)malloc(len * sizeof(char));

    memcpy(temp, S[i], len);
    memcpy(S[i], S[j], len);
    memcpy(S[j], temp, len);
}
```

And it finally runs.

One final thing I'd like to do for this source is generalize the sorts to be
type agnostic. I was reading up on approaches and it seems that the best way to
go about doing it is having a compare function parameter for each of the types, but even
with that generalization, providing a size for generic void pointers. But all of
this is for another day. 

[^1]: Jens Gustedt, Modern C
[^2]: [SIGTRAP, Apple](https://developer.apple.com/documentation/xcode/sigtrap_sigill)
