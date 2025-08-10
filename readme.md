# City Map Navigation using Graphs (C++)

A simple navigation system that finds the shortest path between a source city and all other cities using **Dijkstra's Algorithm** — one of the most efficient algorithms for computing shortest paths in a weighted graph.

---

## Features
- Stores cities and roads as a **graph** using an adjacency matrix.  
- Implements **Dijkstra’s Algorithm** to calculate shortest distances and paths.  
- Interactive menu for displaying the adjacency matrix or computing shortest paths.  
- Supports custom city names and distances between them.

---

## Data Structures Used

**Graph (Adjacency Matrix)**  
- Represents the city map as a 2D array.  
- `adjMatrix[i][j]` holds the distance between city `i` and city `j`.  
- No direct road ⇒ stored as `INF`.

**Arrays**  
- `dist[]`: Minimum distances from the source city.  
- `visited[]`: Tracks visited cities in shortest path computation.  
- `prev[]`: Stores the previous city for path reconstruction.

---

## Workflow

1. **City and Road Input**  
   - Enter number of cities and their names.  
   - Enter number of roads and distances between city pairs.

2. **Menu Options**
   - **Option 1:** Display adjacency matrix of city-to-city distances.  
   - **Option 2:** Select a source city to compute shortest paths to all others.  
   - **Option 3:** Exit the program.

---

