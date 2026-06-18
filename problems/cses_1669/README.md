### Round Trip

#### Solution:

When we call DFS upon some node, we don't DFS back towards the parent of this node, therefore while we are traversing the nodes, if a node was visited this means we are at the end of a cycle, that's the solution to this problem, the only problem we have now is storing the nodes that makes up the cycle, To solve this we could set up a boolean called found for example that is set to true when a cycle is found, The node where the cycle is found is supposed to be the start and the end of the cycle, so after a cycle has been detected at some node, we store that node in some output vector and we also set a variable called stop to the value of the node, that will tell us where to stop storing nodes while we are backtracking since we might backtrack beyond the node where the cycle has been detected. So for each node we check the boolean found variable and the stop value and if:
1. found is false, nothing happens, node calls DFS upon its children as usual.
2. found is true and stop equals to -1 (Sentinel value that tells us not to store this node), we just return to the parent node.
3. found is true and stop equals some value other than -1 (Node where to stop value), we store that node and we ask it if it's the node that we should stop at, if it is then we set stop to -1 indicating the end of the cycle so other parent nodes beyond this node don't get stored, and if it's not then we do nothing. We return to parent node in both cases
And that's it, if found is true, just print the output vector after DFS is done.

Note: There could be multiple disconnected graphs, so to ensure that you considered all the graphs, loop over the nodes and call DFS upon them if they weren't visited.