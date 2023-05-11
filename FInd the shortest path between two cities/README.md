# I will upload the all source codes to this repository after end of the deadline. 

# DEADLINE : 08.05.2023

## Homework 2 description:

Write a “C” program using the graph below to find and print the path between the two cities using the depth-first
search algorithm in a specific order (always choose the city with the shortest distance). The graph will be
automatically imported from the given text file. Thus, it is possible to define any graph in your code with the given
text file. Your code should generate the desired output file.

![Logo](https://github.com/cavadibrahimli1/ITU-homeworks./blob/main/FInd%20the%20shortest%20path%20between%20two%20cities/assets./map.png)


### For this graph, the given input text file contains:
- 7 11
- Prague Helsinki 1845
- Prague London 122264
- Beijing London 8132
- Beijing Tokyo 1303
- Beijing NewYork 11550
- Helsinki Tokyo 7815
- Tokyo Jakarta 5782
- Tokyo NewYork 10838
- Jakarta Beijing 4616
- NewYork London 5567
- London Tokyo 9566
- Prague London
- London London
- London Prague

where in the first line, the number of nodes and the number of edges are given. In the following 11 lines, edges
are given in the format of {SOURCE_NODE, DESTINATION_NODE, LENGTH}. The last three lines represent the
questioned paths.

The output file format is given below:
```txt
Path (Prague London) : Prague -> Helsinki -> Tokyo -> New York -> London
Distance: 26065 km
Path (London London): London -> Tokyo -> New York -> London
Distance: 25971 km
Path (London Prague): Path not found
Distance: Path not found
```
The distance is the length of this path. Your code should run on the terminal when typing

```txt
./hw2 -i input.txt -o output.txt
```

and should generate the desired output file. Here input.txt and output.txt are optional parameters that can be
replaced with any input/output file path.
Important: Your code will be compiled with gcc or g++ and your grade will be automatically given. So, the text
in the output file should be correctly typed (Not even extra spaces allowed. It is type-strict as the language:).
Your code should be properly commented. Uncommented code will get partial credit.
Your code should input the graph and queries from the given text file. Otherwise, your code will get partial
credit. You need to do your assignment alone. Code sharing among students or using code from any other source is
not allowed.
