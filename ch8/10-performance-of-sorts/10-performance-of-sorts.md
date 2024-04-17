# Challenge 10: Performance of Sorts

### Specifications[^1]

- Use `time.h` to measure performance of merge and quick sort from challenge 1

### Reflection

##### 17 April 2024

This challenge was an exercise in using existing libraries provided by the C
language. My first thought was to use `difftime` but after exercising some
reading comprehension I saw my mistake that `time_t`'s granularity is limited to
whole seconds, so I had to resort to `timespec_t`. This is a wrapper for
`time_t` which includes a property for nanoseconds, which is the type of
precision we need. 

Now that we had to formally reapproach challenge 1, it's time that I refactored
so that it mostly functions without issue. The main issue I was experiencing in
its original implementation was a trace trap which was a result of my platform
refusing to use `strcpy`. Switching `strcpy` out with `memcpy` resolved this.
Now the code is running as it should with the primary drawback being
segmentation faults which interrupt during large string array allocations and
operations but works with smaller collections in whose elements demand less
space. I'm attributing this to be a problem with limited runtime memory. 

To read more about the refactor and trace trap (SIGTRAP) issue, I go into detail
in 1-quick-and-merge.md

The time measurements were simple to grasp: take note of the time before and
after the operation, then take the difference of those two times. Due to being
constrained to small sets, these times don't amount to much.

# Sources

- [^1]: Jens Gustedt, Modern C
