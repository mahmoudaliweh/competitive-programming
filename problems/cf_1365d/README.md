### Solve the maze

#### Solution:
The algorithm begins to iterate over the cells of the grid and for every cell with a bad guy, a function called block is called upon that cell, this function checks for every valid neighbor of the cell if it can be replaced with a wall, since that's a way to guarantee blocking that "bad guy" cell from reaching to the destination, There are some things to keep in mind, if one of the neighbor cells is:
1. A "good guy" cell or a "bad guy" cell, in that case it ignores it
2. An empty cell and it that case it replaces it with a wall.

There is only one case where this function fails on blocking a bad cell and that is when one of its neighbors is a good guy cell and in that case there is no solution.
One might argue that replacing an empty neighbor cell of a bad cell might block a good guy cell from reaching to the destination, well it doesn't matter, because either way there will be no solution, Because if I didn't block it, the bad cell will take the same path that leads it to the destination and if I block it, the good cell won't be able to reach the destination cell so it doesn't matter.

That's the first part of the algorithm which is blocking all the bad cells if can.
Keep in mind that if there are no good guys and this is checked at the beginning of the program then there is a solution no matter what.

After blocking all the bad cells, we want to check if all the good guys can reach the destination and also if no bad guys aren't reachable from the destination and we can do this simply by storing the number of all the good guys, and running the DFS algorithm starting from the destination node, and every time we encounter a good guy, we increment a counter storing the number of good guys encountered so far and at the end we check if the counter equals to the number of good guys exist, well if the DFS encounters a bad guy then it will set the variable storing the number of good guys to -1 thus guaranteeing that the comparison will yield false.

