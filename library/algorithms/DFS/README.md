# Depth-first search

### The Strategy

- Start at a designated root node (or any arbitrary node in a graph).
- Mark the current node as **visited** so you don't get stuck in infinite loops.
- Move to an unvisited neighboring node and repeat the process recursively.
- When you hit a dead end (a node with no unvisited neighbors), **backtrack** to the previous node and look for other unvisited neighbors.
### Time Complexity: $\mathcal{O}(V + E)$

### Space Complexity: $\mathcal{O}(V)$

### Iterative Alternative

If you ever want to avoid recursion (to prevent potential stack overflow on massive graphs), you can implement DFS manually using an explicit `std::stack`. The logic remains identical: push to stack, pop, mark visited, and push unvisited neighbors.