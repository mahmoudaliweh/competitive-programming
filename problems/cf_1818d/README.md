### Fish Graph

#### Attempt 1:

Get all possible cycles of the graph, and for each cycle check for every node if it's a special node in terms of that cycle.

This solution got time limit exceeded at first, then I realized that I misunderstood something in the problem so I adjusted my solution and got memory limit exceeded, and so I had another idea in mind where we check for every node that has degree greater than or equal 4 if it is a part of a cycle where two of its edges aren't included in that cycle, I didn't implement this idea because I thought it would have the same time complexity as the previous solution and it probably does but it's better in terms of memory. At this point, I decided to look up for hints or a solution and surprisingly the second idea that I didn't implement was a solution, I was confused why as the time complexity would be O((n + m) * n * t) and would result in O(10^9) based on the constraints of the problem leading to time limit exceeded. But turned out to be that my worst-cases analysis was wrong since the phrase was "Furthermore, it is guaranteed that the sum of n and the sum of m over all test cases both do not exceed 2000.".

#### Solution:

Two necessary conditions for a node to be a special node:

1. The node should have degree greater than or equal to 4.
2. It should be part of a cycle (It could be any cycle).

You can prove that yourself, it is easy to observe that.

So the thing is that you will notice if you found any cycle for a node with degree greater than or equal to 4, what if that cycle includes all the adjacent nodes to the original node? this can't be a fish graph as we need the node to have at least extra two edges that aren't part of the cycle.

So the other thing you will notice is, if some node is part of a cycle that includes all its adjacent nodes, this implies that there is one or more shorter cycles where only two of any of the adjacent nodes are part of.
Note: The two or more adjacent nodes that you will pick have to be in the same subsequence as the big cycle nodes order.

So now we can implement an algorithm:

For every node in the graph, if the node has a degree greater than or equal to 4, DFS that node searching for a cycle where the end point of the cycle is the same node.
If a cycle is found, then a solution exists, where the special node is the original node where you started the DFS so break from the loop, otherwise repeat for other nodes.

If you found a cycle, we aren't sure if it doesn't include at least two adjacent nodes of the special node, If this is true, we do another DFS on the special node with the change that we mark the nodes that we don't want it to be part of the cycle visited, so the DFS will result in another cycle where only the only unmarked adjacent nodes could be part of it, this guarantees having at least 2 extra edges that aren't part of the cycle.
