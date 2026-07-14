#### Solution:

First we do some precomputing, For every node we calculate the shortest path to every node.
This takes O(n^2lgn) and n is up to 10^3 so that's fine.
Then we just do brute force, for every edge we calculate the the shortest path, for all of the routes, we can calculate the shortest path in O(1) since we did precomputing and stored them in a 2D array, we accumulate the total cost for every edge removed, and minimize on that.

I looked up the solution, I kind of needed to calculate the shortest path for every route if certain edge is removed for all edges, and I really didn't notice I could compute that in that brute force way, so I had the idea but didn't know how.