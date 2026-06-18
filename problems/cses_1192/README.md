### Counting Rooms

#### Solution:

For every non-visited floor cell in the grid, Increase the number of rooms and call the dfs function to mark all the floor cells connected either directly or indirectly to this cell as visited since they all belong to the same room.
