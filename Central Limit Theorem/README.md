
![Logo](https://thumbs.gfycat.com/VeneratedConsiderateBovine-max-1mb.gif)


# Central limit theorem - Dice problem

The central limit theorem is a theorem that states that the normalized sums of n independent and identically
distributed random variables will show an approximately normal distribution (ie Gaussian distribution) as n goes to
infinity. In this homework, we will show by writing a C program that the probability distribution of the sums of two
dice rolled at the same time will approach a normal distribution even if n = 2.



The programming steps are summarized below:
1. Create a random dice roll simulation that simulates rolling a single dice 10000 times. Run simulation and count the frequency of the values. Plot the obtained values as a histogram graph consisting of '*' symbols as shown below. The resulting graph will be close to a uniform distribution as follows:
```
        * * * *
        * * * * * *
        * * * * * *
        * * * * * *
        * * * * * *
        * * * * * *
        1 2 3 4 5 6
```
2. 2. Now instead of one dice, create a simulation of two dice rolled at the same time 10000 times. At the end of each
roll, count the frequency of the sum of the values of the two dice. For instance, if one die reads 3, the other reads
4, the sum will be 7. Plot the obtained values (the sum of two dice will be between 2-12) as a histogram graph similar
to normal distribution (bell shaped curve) as below:
```

              *
              *
            * * *
            * * *
            * * *
          * * * * *
          * * * * *
          * * * * *
        * * * * * * *
        * * * * * * *
        * * * * * * *
      * * * * * * * * *
      * * * * * * * * *
    * * * * * * * * * * *
    * * * * * * * * * * *
   2 3 4 5 6 7 8 9 10 11 12
```

### Homework Deliverables
#### Note:  
- You need to use a proper scale factor of your own choosing so that a single '*' represents x number of dice rolls (for example, 100 rolls per '*'). You can obtain the appropriate x value by checking with different x values to make your chart look compact and neat.
- Make use of functions to modularize your code and maximize code reuse.
- Properly comment your code.
- Submit your final C source code file to Ninova, do not include binaries
#### You can get details about Homework in homework1.pdf file in this repository.


#
#
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/cavadibrahimli/)


