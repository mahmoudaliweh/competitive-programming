### Kefa and Park

#### Solution:

```cpp
void dfs(int p, int v, int currentCats = 0, int maxConsecutive = 0) {
    if (hasCat[v]) {
        currentCats++;
        if (currentCats > maxConsecutive) maxConsecutive = currentCats;
    } else {
        currentCats = 0;
    }

    for (auto child : adj[v]) {  
        if (child == p) continue;  
        dfs(v, child, currentCats, maxConsecutive);  
    }  

    if (adj[v].size() == 1 && maxConsecutive <= maxCats && v != 1) {  
        paths++;  
    }  
}
```

Traverse the tree starting from the source node (root), maintain two variables; currentCats that store the current number of consecutive cats along some path, maxConsecutive that stores the maximum number of consecutive cats that has been encountered along that same path.
For each node that is being traversed, check if it has a cat, if it does increment the currentCats that stores the current number of consecutive cats along the path to this node, then check if currentCats exceeded the maximum number of cats encountered in the same path and update the maxConsecutive if needed, otherwise reset the currentCats to zero since there is no cat in the current node even though we might have encountered some cats along that path but we are only interested in the consecutive cats.
And for every edge going out this node, pass it the currentCats and maxConsecutive since that child node belongs to the same path. For every node check if it's a leaf node by checking if it has only one edge and that it's not the root node, this implies that it has only one edge which is the edge connecting it to its parent thus it's a leaf node, if it's a leaf node check if the maximum number of consecutive cats encountered from the root to that leaf node is at most the number of maxCats, if it is then increment the total number of paths that Kefa can take.
