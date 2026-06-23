### Thinking Process

#### Attempt 1:

I think it's a simple problem, all we have to do is traverse the tree starting from the root node in some kind of way while storing the path we are taking, So we will traverse the tree using DFS but we will modify it a little bit, there will be some kind of id parameter that will tell us if the current node is a start of a new path or a part of an old path, and depending on that we will either create a new path with a special id which will be the number of that node, or we will append the current node to the old path with the passed id.
All the paths are stored in a universal variable.
After that the node will run DFS for all its children with the special ID parameter = -1 indicating that each of them has to create their own path except one child, it will pass to it its ID indicating that this child will be part of the same path.

Accepted

#### Simpler Solution:

Let's find a set of leaves of a given tree. From each leaf we will climb up the tree until we meet a vertex already visited. Having met such a vertex, start a new path from the next leaf.

The sequence of vertices in the found paths must be deduced in reverse order, because the paths must go from bottom to top. It also follows from this solution that the number of paths will always be equal to the number of leaves in the tree.

