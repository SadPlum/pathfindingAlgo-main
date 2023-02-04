# Pathfinding Algorithm written in C.

## How it was built.
I wanted to challenge myself and learn about how lower-level concepts such as pointers, arrays and memory works. I decided I wanted to build a pathfinding algorithm. I established that I wanted to program to know where the starting point was, but was unaware of the end. The grid is a 10x10 array, using numbers to dictate whats the end, wall, etc.

Each of the files shows the evolution of how it started, to where it is. Search3 is the working version.

```
0 = searchable area
1 = start
2 = searched area
3 = walls
4 = end
5 = path from start to end
```
The algorithm grows out and tries to find the end, then uses recursion to find the shortest path.

## How it works
The grid is currently hardcoded and can be changed by moving 3's arround on the grid array. At the start of the main function the start, in this case grid[0][5] and the end[0][0] is established. While the are on the grid, the algorithm is not notified where the end is.

*Here is the grid with the start, end and walls established*

![alt text](https://i.imgur.com/TuU3Rvh.png)

*Here is the grid with the area searched until it found the end*

![alt text](https://i.imgur.com/Tv1Ol6h.png)

*Here is the grid with the path found*

![alt text](https://i.imgur.com/mDg2H20.png)
