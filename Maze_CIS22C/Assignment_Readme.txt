Write a program that solves a maze.

The maze
The maze is a 2D array of characters, such as:

       . . . X X
      X X . . .
      . . . X .
      X . X . .
      X . X . .

where  . . . . represents a possible path, and X X X X is a wall

The 2D array used in the lab is an 8 x 8 matrix of characters. The entrance to the maze is at (0,0), and the exit is at (7,7).
To move along a path, movement is restricted to the 4 directions: up, down, left, right. There is no diagonal move.

Solving the maze
The program starts at the entrance (0,0) and moves along a path until it reaches the exit at (7,7), or it determines that there is no possible solution.
When done, the program either prints “no solution” or it prints the maze with all paths that it tried, along with a list of all decision points that it needed to make.
The paths that the program tried is marked with ‘+’

For example, with the maze above, the program will print the following solved maze (with no highlight):

      + + + X X
      X X + + +
      + + + X +
      X + X . +
      X + X . +

and it prints the decision points, in the order that it reached them: (1, 2) (2, 1) (3, 4)   [highlighted in yellow]

The program solves the maze by systematically doing an exhaustive search at each decision point.
In the example above, here are the steps:
- From (0, 0), as long as there is only one way to go, the program went down the only path to the right
- The first decision point is (1, 2), and the program made a wrong decision to go down at (1,2)
- Then at the second decision point (2, 1), it made another wrong decision to go down, and it got stuck at (4, 1)
- When stuck, the program went back to the decision point at (2, 1) and went to the only path still available, which was to go left, where it got stuck at (2, 0)
- Being stuck, the program went back to the decision point at (2, 1) and found that there was no path left to try. 
  It had exhausted all paths at decision point (2, 1), so it went back to the previous decision point (1, 2)
- Back at (1, 2), it went with the only path that had not been tried, which was to go right
- At (3, 4) was another decision point, where the program decided to go down and reached the exit at (4,4)

As the step by step description shows, solving a maze requires trying to go down one path and then possibly having to go back and trying a different path. 
Going back to a decision point to make different decision is called backtracking, and it’s easiest to use a stack for this. 
With every decision point, the location of the decision point is pushed on the stack.When backtracking is necessary, we pop from the stack the most recent decision point (LIFO order) and go back to that location

Algorithm to solve the maze
The following is an algorithm that describes the solution above

algorithm solveMaze
1  create stack s
2  noSolution = false
3  (r,c) = (0,0)  // start at maze entrance
4  loop while ( (r,c) != (7,7)   AND   noSolution == false )
    1  (r,c) = '+'     // mark path
    2  pathCount = countAvailablePaths()
    3  if  (pathCount > 1)      // more than 1 path available: decision point
         1  s.push( (r,c) )
    4 if (pathCount >= 1)       // at least one path available
         1  if (go_down == true)
              1  change (r,c) to go down on path
         2  else if (go_right == true)
              1  change (r,c) to go right on path
         3  else if (go_left == true)
              1 change (r,c) to go left on path
         4  else
              1 change (r,c) to go up on path
     5  else                        // stuck, no path available
          1  if  (!s.empty())
               1 (r, c) = s.pop()   // go back to decision point
          2  else
               1 noSolution = true  // no more decision point: no solution
5 end loop

Coding
The code for lab 2 is partially provided for you, at lab2.zip:
- lab2.cpp has main, which instantiates a maze and calls the member functions of the maze to print and solve the maze.
- The input text file is maze.txt. This file has lines of characters that make up the maze. 
  This makes it easy for you to modify the maze and create a new one for testing.
- Maze.h and Maze.cpp is partially written. Maze.cpp has the function to read from the file and create the maze, and the function to print the maze

Your task to continue lab2 includes:
- Add member data and member functions to the Maze class as you see fit
- The member function of the Maze class to solve the maze should use the algorithm given above
- Use a queue to store all decision points and print them at the end
- You will need to create a simple class that stores the location (r,c) so that you can use the stack and queue with it. This class should be simple, just like the Node class.
- For the stack, use the ArrayStack.h file and for the queue, use the LinkedQueue.h file.
- Make sure you change the peek() function of the stack ADT and the peekFront() function of the queue ADT so they are safe.

Test
- In addition to the given maze.txt, copy and modify maze.txt to create different mazes to test your program. 
Make sure you only create an 8 x 8 maze, and use the same symbols for path (.) and wall (X)
- Don’t forget to test for the no solution case

Turn in
All files that you use in your program, except maze.txt, ArrayInterface.h, and QueueInterface.h.
I will use my own maze.txt, and I will use the ArrayInterface.h and QueueInteface.h that we changed in the class exercise

Sample program output

Maze:
 . . . . X X X X
 X X X . . . . X
 . . . . X X . .
 X X X X X . . X
 X X . . . . X X
 X . . X X . X X
 . . . . X X . .
 X . . . . . . .

Solved mazed:
 + + + + X X X X
 X X X + + + + X
 + + + + X X + .
 X X X X X + + X
 X X + + + + X X
 X . + X X + X X
 . . + . X X . .
 X . + + + + + +

Decision points:
(1,3) (2,6) (4,5) (5,2) (6,2) (7,2) (7,3) (7,6)

 

Honors Requirement
- When printing the solved maze, only print the path that is successful in reaching the exit of the maze

Solved maze:

 * * * * X X X X
 X X X * * * * X
 . . . . X X * .
 X X X X X * * X
 X X * * * * X X
 X . * X X . X X
 . . * . X X . .
 X . * * * * * *

You can develop an additional algorithm or modify the existing solveMaze algorithm to do the requirement. However, your solution must not involve copying the maze multiple times, or walking the entire maze (all rows and all columns) too many times.