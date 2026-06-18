### Link Cut Centroids

#### Solution:

So when I thought about an algorithm, I came up with this:

1. I get the centroids
2. If there is one unique centroid, then problem is already solved.
3. If there are two centroids, you DFS one of the two centroids and assume its parent is the other centroid to avoid traversing the other centroid graph, then get an edge that connects between a leaf and its parent, separate this edge from its parent and connect it to the other centroid.

For some reason this worked but I'm not sure why, but I think this works because when you do that leaf node separation and connect it to the other centroid, basically what happens is that the centroid's value decreases and the other centroid's value increases and maybe this results in a graph with a unique centroid.

In the code, I begin by calculating the number of nodes in each subtree starting from some root node, I chose the root node to be 1, then I try to get the centroids by assuming each node is the centroid and calculate its value which is the maximum between the subtree child with the maximum number of nodes and the total number of nodes minus the number of the current subtree. That basically assumes if some node was the centroid by assuming it got separated and then getting the maximum number of nodes between the resulted graphs.
That's the hardest part in the algorithm which is getting the centroids, the last step is to separate a leaf edge from some centroid and connect it to the other centroid.