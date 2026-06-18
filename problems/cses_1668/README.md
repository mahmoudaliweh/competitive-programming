### Building Teams

#### Solution:

The problem is basically asking if the graph is a bipartite graph, if there are more than one then check if all are bipartite.
So the solution starts by calling DFS upon unvisited nodes, and giving them a color of two colors, doesn't matter which color it gives, then for every node it asks itself if it has a color, if it does it asks itself if that color is the same as the color one of its neighbors expects it to be for it to be a bipartite graph, if it's not then it's not a bipartite graph. If it is, then the node is good and it just returns since having a color indicates that it has been visited.
If it doesn't have a color it takes the color passed to it and then calls DFS with the opposite color upon its neighbors/children.

That's it, at the end we check if the noSol variable is true or false, true indicates that it's not a bipartite graph, otherwise iterate over the nodes and print their colors.