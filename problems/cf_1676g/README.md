### Thinking Process

#### Attempt 1:

We could recursively starting from the root node, to ask about the net sum of each vertex children and add it to a local value sum that starts with 1 if the color of the vertex is white and -1 if it's black.

After we get the net sum of the children, we add to it the value of the current vertex. If the result is 0 then it's balanced otherwise it's not.
For each vertex we return the sum to the parent if exists.

Accepted.