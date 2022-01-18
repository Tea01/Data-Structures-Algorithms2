# Data-Structures-Algorithms-Project-2
By using Linked List, Priority Queue and AVL Tree the code reads numbers row by row from a txt file. Every number is a coordinate. 
First I found the distance (x,y,z) of one point from origin and the result is saved into the queue. 
Then i found the distance between each point in a row. Then I find the total distance between points for every row. 
This data is added to the queue. Then by using AVL tree and Post Order I place the total distance of each row there. 
After the data is ordered in the tree the output has to be the origin distance of each point.
So for each row there has to be a queue and in each queue is saved the origin distance and the total distance. The origin distances are saved into a Linked List. 
In the AVL tree I put every queue. And the Post Order is done by using the total distance data. Before I output I organize the queue to output in order from the greatest to the lowest number.
