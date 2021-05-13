# 0x19. C - Stacks, Queues - LIFO, FIFO
 Foundations - Low-level programming & Algorithm ― Data structures and Algorithms
 
## Compilation & Output

* Your code will be compiled this way:
> gcc -Wall -Werror -Wextra -pedantic *.c -o monty
* Any output must be printed on stdout
* Any error message must be printed on stderr
 + Here is a link to a GitHub repository "https://github.com/sickill/stderred" that could help you making sure your errors are printed on stderr 

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
 
### The monty program

* Usage: [  monty file  ]
 + where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message [ USAGE: monty file ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
* If, for any reason, it’s not possible to open the file, print the error message [ Error: Can't open file <file> ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
 + where <file> is the name of the file
* If the file contains an invalid instruction, print the error message [ L<line_number>: unknown instruction <opcode> ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
 + where is the line number where the instruction appears. 
 + Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
 + it executed properly every line of the file
 + it finds an error in the file
 + an error occured
* If you can’t malloc anymore, print the error message [ Error: malloc failed ], followed by a new line, and exit with status [ EXIT_FAILURE ].
* You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

## Tasks
### 0. push, pall  < Implement the push and pall opcodes >
#### The push opcode
The opcode push pushes an element to the stack.

* Usage: [ push <int> ]
 + where <int> is an integer
* if <int> is not an integer or if there is no argument given to push, print the error message [ L<line_number>: usage: push integer ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
 + where is the line number in the file
* You won’t have to deal with overflows. Use the atoi function

#### The pall opcode
The opcode pall prints all the values on the stack, starting from the top of the stack.
* Usage pall
* Format: see example
* If the stack is empty, don’t print anything
> cat -e bytecodes/00.m
> ./monty bytecodes/00.m

### 1. pint  < Implement the pint opcode. >
#### The pint opcode
The opcode pint prints the value at the top of the stack, followed by a new line.
* Usage: [ pint ]
* If the stack is empty, print the error message [ L<line_number> : can't pint , stack empty ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
> cat bytecodes/06.m 
> ./monty bytecodes/06.m

### 2. pop  < Implement the pop opcode >
#### The pop opcode
The opcode pop removes the top element of the stack.
* Usage: [ pop ]
* If the stack is empty, print the error message [ L<line_number>: can't pop an empty stack ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
> cat bytecodes/07.m
> ./monty bytecodes/07.m

### 3. swap  < Implement the swap opcode. >
#### The swap opcode
The opcode swap swaps the top two elements of the stack.
* Usage: [ swap ]
* If the stack contains less than two elements, print the error message [ L<line_number>: can't swap, stack too short ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
> cat bytecodes/09.m
> ./monty bytecodes/09.m

### 4. add  < Implement the add opcode. >
#### The add opcode
The opcode add adds the top two elements of the stack.
* Usage: [ add ]
* If the stack contains less than two elements, print the error message [ L<line_number>: can't add, stack too short ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  + The top element of the stack contains the result
  + The stack is one element shorter
> cat bytecodes/12.m
> ./monty bytecodes/12.m  

### 5. nop  < Implement the nop opcode. >
#### The nop opcode
The opcode nop doesn’t do anything.
* Usage: [ nop ]

### 6. sub < Implement the sub opcode. >
#### The sub opcode
The opcode sub subtracts the top element of the stack from the second top element of the stack.
* Usage: [ sub ]
* If the stack contains less than two elements, print the error message [ L<line_number>: can't sub, stack too short ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  + The top element of the stack contains the result
  + The stack is one element shorter
> cat bytecodes/19.m
> ./monty bytecodes/19.m

### 6. sub < Implement the sub opcode. >
#### The sub opcode
The opcode sub subtracts the top element of the stack from the second top element of the stack.
* Usage: [ sub ]
* If the stack contains less than two elements, print the error message [ L<line_number>: can't sub, stack too short ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  + The top element of the stack contains the result
  + The stack is one element shorter
> cat bytecodes/19.m
> ./monty bytecodes/19.m

### 7. div < Implement the div opcode. >
#### The div opcode
The opcode div divides the second top element of the stack by the top element of the stack.
* Usage: [ div ]
* If the stack contains less than two elements, print the error message [ L<line_number>: can't div, stack too short ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  + The top element of the stack contains the result
  + The stack is one element shorter
* If the top element of the stack is 0, print the error message [ L<line_number>: division by zero ], followed by a new line, and exit with the status [ EXIT_FAILURE ]


### 8. mul < Implement the mul opcode. >
#### The mul opcode
The opcode div divides the second top element of the stack by the top element of the stack.
* Usage: [ mul ]
* If the stack contains less than two elements, print the error message [ L<line_number>: can't mul, stack too short ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  + The top element of the stack contains the result
  + The stack is one element shorter

### 9. mod < Implement the mod opcode. >
#### The mod opcode
The opcode div divides the second top element of the stack by the top element of the stack.
* Usage: [ mod ]
* If the stack contains less than two elements, print the error message [ L<line_number>: can't mod, stack too short ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  + The top element of the stack contains the result
  + The stack is one element shorter
* If the top element of the stack is 0, print the error message [ L<line_number>: division by zero ], followed by a new line, and exit with the status [ EXIT_FAILURE ]

### 10. comments
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

### 11. pchar < Implement the pchar opcode. >
#### The pchar opcode
The opcode pchar prints the char at the top of the stack, followed by a new line.
* Usage: [ pchar ]
* The integer stored at the top of the stack is treated as the ascii value of the character to be printed
* If the value is not in the ascii table (man ascii) print the error message [ L<line_number>: can't pchar ], value out of range, followed by a new line, and exit with the status [ EXIT_FAILURE ]
* If the stack is empty, print the error message [ L<line_number>: can't pchar, stack empty ], followed by a new line, and exit with the status [ EXIT_FAILURE ]
> cat bytecodes/28.m
> ./monty bytecodes/28.m

### 12. pstr < Implement the pstr opcode. >
#### The pstr opcode
The opcode pstr prints the string starting at the top of the stack, followed by a new line.
* Usage: [ pstr ]
* The integer stored in each element of the stack is treated as the ascii value of the character to be printed
* The string stops when either:
  + the stack is over
  + the value of the element is 0
  + the value of the element is not in the ascii table
* If the stack is empty, print only a new line
> cat bytecodes/31.m
> ./monty bytecodes/31.m

### 13. rotl < Implement the rotl opcode. >
#### The rotl opcode
The opcode rotl rotates the stack to the top.
* Usage: [ rotl ]
* The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
* rotl never fails
> cat bytecodes/35.m
> ./monty bytecodes/35.m

### 14. rotr < Implement the rotr opcode. >
#### The rotr opcode
The opcode rotr rotates the stack to the bottom.
* Usage: [ rotr ]
* The last element of the stack becomes the top element of the stack
* rotr never fails
   
### 15. stack, queue < Implement the stack and queue opcodes. >
#### The stack opcode
The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.
* Usage: [ stack ]
+ The queue opcode
+ The opcode queue sets the format of the data to a queue (FIFO).
* Usage: [ queue ]
+ When switching mode:
* The top of the stack becomes the front of the queue
* The front of the queue becomes the top of the stack
> cat bytecodes/47.m
> ./monty bytecodes/47.m

### 16. Holberton <1000-holberton.bf>
Write a Brainf*ck script that prints Holberton, followed by a new line.
* All your Brainf*ck files should be stored inside the bf sub directory
* You can install the bf interpreter to test your code: sudo apt-get install bf
* Read: Brainf*ck "https://alx-intranet.hbtn.io/rltoken/x0I37o6PVmnT0M1RF0XXjg"
> bf 1000-holberton.bf

### 17. Add two digits <1001-add.bf>
Add two digits given by the user.
* Read the two digits from stdin, add them, and print the result
* The total of the two digits with be one digit-long (<10)
> bf 1001-add.bf

### 18. Multiplication <1002-mul.bf>
Multiply two digits given by the user.
* Read the two digits from stdin, multiply them, and print the result
* The result of the multiplication will be one digit-long (<10)
> bf ./1002-mul.bf

### 19. Multiplication level up <1003-mul.bf>
Multiply two digits given by the user.
* Read the two digits from stdin, multiply them, and print the result, followed by a new line
> bf 1003-mul.bf


------------------------------------------------------------------------------------------------------------------------------------------------------------------
                      Notes ....
------------------------------------------------------------------------------------------------------------------------------------------------------------------
<monty.c>
+ => create a stack : ? a global accessible datatype
+ => initilize a stack
+ => validate input ? { argc != 2}, {argv[2] not type int}   Instruction
+ => call instruction over stack
+ => exit
<execute_file.c>
+ => check file exists!
+ => open read file getline(&line, &len, fptr); read line by line while loop
+ => strtok escape \n \t " "
+ => if instruction found call the method
+ =>end
<instruction_PUSH()>
+ => check valid args
