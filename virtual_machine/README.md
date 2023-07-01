# Emulated CPU, RAM, and Assembly Compiler
This program emulates a CPU, RAM, and an assembly compiler. It takes a command-line argument, which is the name of a file with the format .jm. The program opens the file and if it doesn't exist, it throws an exception. In such cases, the compiler is executed to compile the Jassembly program. The compiler includes a preprocessor, syntax analyzer, and generates binary code. The Loader then loads the compiled result into the RAM. The CPU is connected to the RAM and executes the program.

## Program Execution
To run the program, ensure you have Java 20.0.1 or a compatible version installed on your system.

java Main <filename.jm>

Replace <filename.jm> with the name of the Jassembly program file you want to execute.

# Program Components

## Compiler
The compiler is responsible for converting the Jassembly program into binary code that can be executed by the CPU. It includes the following stages:

Preprocessor: Performs preprocessing tasks.
Syntax Analyzer: Checks the syntax of the Jassembly program and ensures it adheres to the defined grammar rules.
Code Generation: Translates the validated Jassembly code into binary instructions that the CPU can understand.

## Loader
The Loader component loads the compiled binary code into the RAM so that the CPU can access and execute the program.

## CPU
The CPU emulates a simple processor with the following registers:

ayb (accumulator register): Stores the result of the last executed instruction.
ben: General-purpose register.
gim: General-purpose register.
da: General-purpose register.
ech: General-purpose register.
za (flag register): Stores the result of comparison operations.
gh: Stores the address of the next instruction.
The CPU supports the following instructions:

mov: Move a value into a register or memory location.
add: Add a value to the accumulator register.
sub: Subtract a value from the accumulator register.
div: Divide the accumulator register by a value.
mul: Multiply the accumulator register by a value.
and: Perform a logical AND operation.
or: Perform a logical OR operation.
not: Perform a logical NOT operation.
cmp: Compare two values and set the flag register accordingly.
jmp: Unconditionally jump to a specified instruction.
jg: Jump if the last comparison was greater.
jl: Jump if the last comparison was less.
je: Jump if the last comparison was equal.
Jassembly Program Format
The Jassembly program is written in a file with the .jm extension. Each line of the file represents an instruction or a comment. Comments start with the # symbol and are ignored during compilation.

Requirements
Java 20.0.1 or a compatible version is required to run this program.
