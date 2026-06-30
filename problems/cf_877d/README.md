#### Solution Explanation:

Okay so we can BFS normally on the source node while keep tracking of the number of levels for some set of nodes currently in the frontier and we check for every node that we are about to expand if it's the destination node, if it is then return the number of levels, if the frontier gets empty return -1 indicating that the destination is unreachable.

The problem with this approach is that it will exceed the time limit since we don't keep track of the visited nodes, so one way to solve this is to create a visited 2D array to keep track of visited nodes and don't revisit it again or pushing it in the frontier if it has already been visited.

Now this solution still doesn't work and might get wrong answer, let's assume that you avoid revisiting the same node by breaking out of the loop once you encounter a visited node in some direction, if there are unvisited nodes in the same direction then you missed them and they could possibly be included in the wrong set of nodes of some level.

To solve this problem, you could continue instead of breaking from the loop if you encounter a visited node, but still this takes O(k) time, yes you succeeded at not pushing the already visited nodes in the frontier but you still access them.

To transform this into a better solution, you could store the distances for each node instead of storing whether each node is visited or not, and then while you are getting the neighbors of some cell you ask if the node has a distance smaller than the distance you gonna set it to, if so then break otherwise you either continue if they are equal or set it to the new distance and push it to the frontier otherwise.

And this solution got accepted.

I still believe there is a better solution since this solution still continues the loop if the distances are equal which in the worst case is O(k) time.
So instead we could store extra information about what are the unvisited nodes for each row and each column, and then instead of accessing nodes blindly we can just look up the set for the first unvisited node and then we could decide what to do and of course this is much faster than the previous solution except that there is something we missed which is that there could be a wall between the unvisited node and us and so we will also need to store the walls location for each row and column.
I haven't implemented that last solution but I believe it will work better and get accepted.