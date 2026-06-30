### Thinking Process

#### Attempt 1:
I think a naive solution would be to DFS each house need to be visited to know how far it is from current position of Vlad, then go to the nearest one and update Vlad's position and DFS the remaining houses again, and that would result in a path, I'm not sure yet if it's the shortest path or not, but I will implement this idea and see if it works.

#### Attempt 2:
Lol I'm back after 2 days, that old idea got wrong answer on some test after it was implemented.
At that same day I spent some long amount of time thinking about how could I solve this problem, and while I'm drawing and imagining some test case graphs, I noticed something and that is if Vlad at some node x and there are some house that need to be visited and the node where he should return to is at some node y then for Vlad to not do unnecessary wasted moves he should consider visiting the houses that are not in the direction of y and then after he visits these houses and return to his start point, now he should take one step forward towards y and then repeat the process on the neighbor branches except the branch he came from and the branch that gets him close to y.
Since there is only one path that leads him to y, then after he visits the houses that aren't on that path, he must get back to that path.

Well now the question is how are we going to compute the minimum amount number of steps needed to visit the houses on some branches starting from some node y and return back to y?

Well turns out that it's not that hard, with a simple DFS function that returns a bool and stores the steps needed for each node to visit the houses on its outgoing branches except the parent that called it in some global array.

So the algorithm works as follows:
1. find the path from x to y and store it (x and y included).
2. Then start visiting the houses on the current node in the path excluding the next node in the path, calculate the distance and add it to the total distance.
3. Then move to the next node to that path and add 1 to the total distance since you took one step towards y.
4. Now repeat while popping the node you already visited from the path until the path is empty but this time you will block two nodes which are the last node you already calculated its distance and the next node on the path that we want to block from traversing until later, minus 1 from the total distance at the end.
That's it.

