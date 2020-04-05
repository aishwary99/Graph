# Graph
Codes &amp; Logics behind graph ds

Complexities ->

#Matrix - (Good if the graphs are dense)
Space: O(v^2)
Time: O(v^2)

#List - 
Space : O(v+e)
Time: O(1)
---------------------------------

About ->

{Depth First Search}
Just Like -> Preorder traversal !

DFS algorithm works in a manner similar to traversal of trees. Like preorder traversal , internally this algorithm also uses Stack.
The idea of DFS is just going forward (in depth) while there is any possibility, if not then backtrack. 
Backtrack -> It is a dead end , from where we move backward and choose a new path..

#Applications ->
1. Topological Sorting
2. Finding connected components
3. Solving puzzles such as mazes
4. Finding articulation points (cut vertices) of a graph


