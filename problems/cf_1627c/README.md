### Thinking Process

#### Attempt 1:
Something I noticed is that you can't have more than two prime numbers such that the summation of any pair is a prime number and that's because any number is either even or odd, and for two prime numbers to be summed and result in another prime number, they can't be of the same type, like they both can't be even or odd, as two odd numbers will result in an even number, and two prime numbers will result in an even number which makes the result divisible by 2. By the way 2 is the only even prime number.

So for every node in the tree, if it has more than two edges then it can't be a prime tree.
This problem kind of reminds of bipartite graph.

Otherwise I can choose two prime numbers such as 2 and 5 and assign them to the edges in turns, starting from some node.

Accepted.