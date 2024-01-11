# Language Interpreter in C++

This is a Language System (LS) for the Weird Language (WL). The LS will first a read a WL program from a file called “input.wl”. The file should contain 1 WL instruction in each line. Next, the LS will process each instruction sequentially, starting from the first line of text in the file.

This project has been implemented using the command design pattern from the pattern system of the Gang of Four.

WL programs use two kinds of data structures, namely numbers and singly-linked lists. List elements can be integers or nested lists. Objects of these types are bound to variables, which don’t need to be declared. 

The LS will keep two storage areas, a program memory that stores a WL program loaded from the input file, and a data memory holding identifiers declared in the program and the values bound to each identifier. In addition, the WL maintains a program counter (PC) storing the line number of the instruction being currently executed. Executing a WL program consists of the following two steps:   
1. Read a WL program from the input file. The program is stored in the memory starting at address (i.e., line) 0, the first line of code read from the input file.
2. Execute a command loop consisting of three commands:
o – Execute a single line of code, starting from line 0. The PC and the data memory are updated according to the instruction. The resulting values of the data memory and the PC are   
printed on the console.
a – Executes all the instructions until a halt instruction is encountered or there are no more instructions to be executed. The values of the PC and the data memory are printed.
q – Quits the command loop.

The syntax and semantics of WL instructions is given below.   
VARINT x i - This instruction assigns an integer i to a variable x. Parameter i can be an integer variable or an integer literal. Variable x is implicitly declared the first time it is used.  
VARLIST y arg1, arg2, ... - This instruction assigns a list to a variable y. Variable y is implicitly declared the first time it is used. The list will contain a variable number or arguments provided in a comma-separated sequence. Each argument arg1, arg2, etc. can be either an integer constant or a variable denoting a list or an integer.  
COMBINE list1 list2 - Argument list list1 is concatenated with list2. The resulting list is stored back into list2.   
GET x i list - The i-th element of list is assigned to variable x. Parameter i can be an integer variable or an integer literal. Variable x is implicitly declared the first time it is used.  
SET x i list - The i-th element of list is set to x. x could be an integer constant or a variable denoting either a list or an integer.  
COPY list1 list2 - The content of list2 is deep copied into list1.   
CHS x - This statement changes the sign of the integer value bound to x.   
ADD x y - This statement adds the integers bound to the two arguments and stores the result in x.   
IF x i - If x is an empty list or the number zero, jump to instruction at line i   
GOTO i - This is the unconditional jump. Transfer control to the instruction at line i.  
HLT - Terminates program execution.

