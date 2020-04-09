# StacksQueuesBasic
The 5 queries are denoted by S, Q, I, E, and P and these query type identifiers
correspond to -
 performing Stack operations,
 performing Queue operations,
 converting Infix expression to equivalent postfix expression,
 Evaluating infix expression value and
 computing stack Permutation, respectively.

The first line of the input contains an integer T and Z where T denotes the number of
queries and Z denotes the size for the stack and queue (wherever that size limit is
applicable).
Then there follows T lines, each line correspond to a query and query type is identified with
the first character in that line which could be either S, Q, I, E or P.
Query type identifier is then followed by parameters specific to that query as discussed
below. These parameters would be single-space separated.

Query S:
Positive Integer: Push that positive integer value in the stack. Don’t print
anything
0: Is_Stack_Empty. Print E if yes, else NE
-1: Pop. Print the integer value popped out.
-2: Is_Stack_Full. Print F if yes, else NF
-3: Print the number of elements currently in stack.
anyOtherInteger: Denotes end of the query. Ignore any symbol after this in that
sequence

Query Q:
Positive Integer: Insert/Enqueue that value in the queue. Don’t print anything
0: Is_Queue_Empty. Print E if yes, else NE
-1: Dequeue. Print the value you dequeued
-2: Is_Queue_Full
-3: Print the Number of elements currently in queue
anyOtherInteger: Denotes end of the query. Ignore any symbol after this in that
sequence

Query I: integer operator
Max 20 operators.
/# used to mark the end of query. Ignore any symbol after #
Integers range : 0 to 1000
No brackets etc. No operators other than what mentioned below would be considered valid.
Operands and Operators are single-space separated. Some operators may consist of two characters e.g. >>
Query Response would be: Postfix expression where operands and operator are single
space separated. No space before first operand. If expression is invalid, mention ONLY “Error” without
Quotes

Query E: integer operator
Max 20 operators.
OPERATORS , Their associativity in the code
/# used to mark the end of query. Ignore any symbol after #
Integers range : 0 to 1000
No brackets etc. No operators other than what mentioned below would be considered valid.

Query P: parameters N k:
kth sequence (in lexicographic ordering) in stack permutations. possible using N numbers observed in the order as follows: 1,2,3,…,N. Query Response:
Total number of stack permutations possible with these N different numbers, and then the kth stack permutation


Stack for integers to be implemented using linked list. Stack for non integer elements to
be implemented using array.
Queue (if to be implemented) can be implemented using either array or linked-list.
Print Error if query type identifier is other than what’s discussed above.
Print Error if parameters are not specific to the query type under consideration or
parameters are not in proper format as mentioned above.
