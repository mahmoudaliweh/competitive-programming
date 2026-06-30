Not a bad problem, what I learnt from these kind of problems is that if you have to minimize the number of moves to visit all the nodes starting from some node x, then you have to postpone the longest path until the end.

You are meant to visit every edge twice except the edges of the last path since you don't need to get back to the root by then, so by knowing the max_depth of the tree with some root, we can calculate the number of moves as follows:

2 x (n - 1) - max_depth.

(n - 1) is the number of edges, since you will visit all the edges twice except the edges of the longest path, you multiply the number of edges of the whole tree by 2 then subtract the max_depth from it as a way of saying the longest path's edges will be visited once.

I solved the problem but had a stupid bug on a utility function, and Gemini told me about it, after that my solution got accepted.