
I looked up the solution because I spent so much time trying to figure it out and I was overcomplicating it and never thought of the 3D BFS, 3 States for each node.
### Gemini:

Because the doors can switch between being open and closed depending on whether Harry has stepped on an 'O' or 'C' button, a standard Breadth-First Search (BFS) on just the grid coordinates $(x, y)$ isn't enough. You need to include the **state of the doors** in your search space.

## The Solution: 3D Breadth-First Search (BFS)

To find the minimum number of steps, we use a BFS where each state in our queue and visited array is tracking three variables:

1. **$x$**: The current row.
    
2. **$y$**: The current column.
    
3. **$door\_state$**: A boolean or integer representing whether the doors are currently **Open (1)** or **Closed (0)**.
    

### State Transitions and Rules

When Harry moves to an adjacent cell, the state updates based on the cell type:

- **Empty cell (`.`) or Harry's start (`H`)**: Doors remain in their current state.
    
- **Opening Button (`O`)**: Doors become **Open (1)**, regardless of their previous state.
    
- **Closing Button (`C`)**: Doors become **Closed (0)**, regardless of their previous state.
    
- **Wall (`W`)**: Harry cannot move here.
    
- **Door (`D`)**: Harry can only move here if the current state is **Open (1)**. The doors remain open.