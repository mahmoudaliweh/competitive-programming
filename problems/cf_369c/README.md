#### Attempt 1:
Do a normal BFS on the root to set the distances for every node from the root and store them on a priority queue where the priority is the larger distance, and also store the parent for every node .

For every node in the priority queue, if it's a problem then then add it to the answer, and traverse upwards from this node until you meet the root while possibly resolving other problems on your way up, repeat as long as there are problems that aren't resolved.

This solution got time limit exceeded because of the second part of it, so I did a slight modification and created a visited array to use it for the second part to stop revisiting nodes that has been already visited which makes the second part worst case time O(n + m), and it got accepted.