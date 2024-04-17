# Challenge 3: Pi Approximation

### Specifications[^1]

- Compute the N first decimal places of pi

### Reflection

I'll be honest, this went completely over my head on a computational level. The
prompt is simple enough to understand but the constraints of the phrasing creeps
in ways I didn't expect. 

My immediate intuition was to simply implement an infinite sum that approximates
pi. But how is this done such that a parameter n determines the precision of pi?
And how can I garauntee that those decimal places are correct without doing too
much or too little computation? Not to mention, how do I truncate a
transcendental number to N digits that's a sum total of however many floating
point terms it takes to get to the point? All of these I'm underqualified to
answer. Thankfully, John Zelle answered all of these questions with Leibniz
approximation via Python[^2]. 

Prior to arriving at that solution, I was down a rabbit hole of spigot
algorithms for pi, one of which seemed to fit the bill nicely known as
Bailey-Borwein-Plouffe formula (BBP)[^3] which can effectively extract sections
of pi without calculating previous terms. It's effectively O(N) complexity, the
catch is that the digits are base-16. Bummer. But compare that to Leibniz, where
I can only compute 46 terms before floating point precision becomes an issue,
which I must say is awful efficiency-- but hey, Leibniz (and John Zelle)
answered this one for me (and John Zelle) so I (we) owe him one.

[^1]: Jens Gustedt, Modern C
[^2]: [Spigot Algorithms for pi](https://www.gavalas.dev/blog/spigot-algorithms-for-pi-in-python/) 
[^3]: [BBP Formula](https://en.wikipedia.org/wiki/Bailey-Borwein-Plouffe_formula) 

