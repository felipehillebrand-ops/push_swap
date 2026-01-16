*This project has been created as part of the 42 curriculum by &lt;fhose-hi&gt;.*


# Description:
Push_swap is a 42 School algorithm project. The goal is to sort data on a stack, with a limited set of instructions with the minimum number of movements possible.

**Here the operations used in the project:**

*sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none.  

*sb (swap b) : Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none.   

*ss : sa and sb at the same time. 
*pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty.   

*pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty.   

*ra (rotate a): Shifts all the elements ofREADM the stack a up by one position. The first element becomes the last.   

*rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one.   

*rr : ra and rb at the same time.   

*rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first.   

*rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first.   

*rrr : rra and rrb at the same time.

## Parsing:
This project can be executed in two forms: ./push_swap "0 1 2 5 42"   or ./push_swap 0 1 2 5 42. Don't accept non-number, duplicates numbers, nunbers bigger or smaller than INT_MAX or  INT_MIN or multiples -0 +000 in the same argument.

## List Size:
**Depending on the size of the list, one or more different algorithms were used:**
For 2 disorganized values, did a unique "sa".
For 3 disorganized values, have a specific function (sort_3);
For 4 or 5 disorganized values, have a specific function (sort_4_or_5 and his auxiliary function lowest_to_b);
For 6 or more disorganized values, it was done a chunk sort algorithm (called too to butterfly sort). This sort divide stack a in many chunks for pass the stack a values to stack b, then return this values after to stack a sorted.



# Instructions:
## How to compile: 
make - for compile the main part of the project;
make bonus - for compile the bonus;

## Execution commands:
./push_swap "values" - For the main executable return the moves realized with a list of values. In "values" you put the args that you want;
ARG="values"; ./push_swap $ARG | ./checker_linux $ARG - For check if the sort return OK or return KO conform the 42 school checker;
ARG="values; ./push_swap $ARG | wc -l - For check the number of moves realized;
ARG="values"; ./push_swap $ARG > out; cat out | ./checker_linux $ARG; wc -l out - Return OK or KO and the number of moves realized;

**For 100 random moves:**
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG - For check if the sort return OK or KO with 100 random values;
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l - For check the number of moves realized with 100 random values;
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG - For check the moves realized with 100 random values;

**For 500 random moves:**
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG - For check if the sort return OK or KO with 500 random values;
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l - For check the number of moves realized with 500 random values;
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG - For check the moves realized with 500 random values;

**Bonus commands:**
./checker "values" - For run the checker of bonus. In "values" you put the args that you want and the checker will return OK or KO;
ARG="values; ./push_swap $ARG | ./checker $ARG - For compare if my checker program hit with my push_swap program;



# Resources:
## References:
**Subject:** The official 42 School project pdf.
**Sort algorithms:** Articles, push_swap visualizer tools, GitHub, 42 colleagues and AI.

## AI usage:
**Debugging & Compilation:** AI was used to discover some buggs in my code and problems when I tried to compile some times my program.
**Terminal commands:** AI help me to discover some commands in the terminal like "ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG" or "ARG="values"; ./push_swap $ARG > out; cat out | ./checker_linux $ARG; wc -l out ".
