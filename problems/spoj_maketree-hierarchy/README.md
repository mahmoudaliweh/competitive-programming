### Thinking Process

#### Attempt 1:
So for every node 'x' that wants to be a superior for some node 'y', there are 3 cases:

1. y already have x as its superior.
2. y has a different main boss or doesn't have any bosses.
3. y has the same main boss as x.

For case 1: Don't do anything
For case 2: we simply make x superior of y's main boss or y if no main boss exist.
For case 3: If they have the same main boss, then it's either case 1 or they can't be in the same branch, in that case we take y's next boss after the main boss and set its parent to x.

So when some node x wants to be a superior of some node y, we will ask y about its main boss and ask x about its main boss, if they have different bosses we will set y's main boss' parent to x, otherwise we will set y's next boss after the main boss parent to x.

Time limit exceeded.
I will try to think of an optimization, the thing is I use a recursive function to find the main boss.

I looked up the solution, it's a problem related to topological sorting. The solution I looked up is much more efficient than mine because It had to visit each node at most once

It simply DFS every node if it's not visited, and every node DFS the nodes it wants to be superior of, and after the for loop DFS, the node is pushed onto a stack, so simply nodes with no wishes get to be pushed first into the stack, and the nodes who got their wishes nodes pushed into the stack are pushed next and so on. So the stack basically resembles some ordering of the nodes where the node on the top is the main boss.