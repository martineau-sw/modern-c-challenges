# Challnege 11: Image Segmentation

### Specifications[^1] 

- Find an image processing library that allows loading of a grayscale image into
  a two-dimensional `unsigned char` matrix
- Perform segmentation of an image, group pixels into connected regions that are
  similar; use forest structure for partitions
- A statistic function that computes a statistic for all regions
- A merge criterion: mean values of two regions are no more than 5 apart
- Line-by-line merge strategy
- Iterate line-by-line check
- Use on different images

### Reflection

This challenge is quite a bit more than the ones preceding it, but seeing that
some of the concepts are familiar, like Union-Find from Challenge 4, that
indicates that I have a small library I've already constructed that I might be
able to utilize. If not, then I at least have a conceptual framework that is
still fresh in my mind that I can use a launch point for new ideas. 

For the image processing library, I desired something trivial and light-weight.
In my search, I stumbled across quite a robust library which improves quality of
life under those constraints. Sean Barrett and other contributers maintain an
open source, public domain modular library down to single source files to fill
in gaps such as these called stb[^2]. 

[^1]: Jens Gustedt, Modern C
[^2]: [stb repo](https://github.com/nothings/stb/tree/master)
