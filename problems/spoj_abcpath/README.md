### ABC Path

#### Solution:

We could think of the problem as if there are some valid paths in the grid and we have to traverse every path and get its length.
A path has to start at 'A' and increase gradually by one step, such as: A -> B -> C -> D .. 
Notice that this isn't a valid path: B -> C -> D. As it doesn't start at A

So the algorithm begins by storing the start points 'roots' of what could be a path that is it stores the locations of every A's in the grid .

Then a DFS function is called upon each root.
The DFS function called upon some cell returns if:
1. The cell was visited
2. The cell doesn't make a valid path with its parent

Notes:
- Some might wonder why does it return if the cell was visited even though there are multiple roots that could form a path with this cell. Well assuming it share paths with some roots, the length of the paths will be the same, since all roots starts from points with the same value 'A'.

- A cell is marked visited if and only if it is one step higher than the parent