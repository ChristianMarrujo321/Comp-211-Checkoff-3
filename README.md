# Compiler Optimizations: Dead Code Elimination & Loop Optimizations
COMP 211 Checkoff 3, Christian Marrujo

## Overview
Compiler Optimization is the part of the comipiling process for a program from source code into machine code. Code is efficienized to reduce the time it takes to run a program whilst still printing the same output for every possible input AS-IF the code was not changed at all.

## What I Explored
- What compiling is and where optimization happens in the pipeline
- GCC optimization levels (-O0, -O1, -O2) and how to see what each enables
- Dead code elimination
- Loop-invariant code motion

## Key Discoveries
### 1. The compiler deleted my entire loop
I discovered that when I created a simple for-loop program that didn't return anything, the compiler at level 1 would delete the actions inside the for loop drastically reducing the time to run the program, and then at level 2 it deleted the for loop and main function entirley make the program run instantaneously.

### 2. One printf made it ~100× slower
I discovered that when I added a printf statement to expirement 1's code, it slowed level 1 and level 2 optimization times to .4, however it kept level 0 the same. This is because level 1 and 2 now had to run the loop, but had the arithmetic inside the loop body slightly optimized to run the full loop faster.

### 3. Moving strlen out of a loop changed O(n²) to O(n)
I discovered, that when the condition of a loop has a calculation that produces the same anaswer everytime, the compiler will actually only calculate it once and re-use that number in the codition.


## How to Run
  gcc -O0 prog.c -o prog_O0
  gcc -O2 prog.c -o prog_O2
  time ./prog_O0
  time ./prog_O2

To see the assembly: paste the code into https://godbolt.org (set language to C).
To list optimizations per level: 'gcc -Q --help=optimizers -O2'

## Presentation
[Compiler Optimization.pdf](https://github.com/user-attachments/files/34987470/Compiler.Optimization.pdf)

## Resources
- Compiler Explorer: https://godbolt.org
-  AI conversation: https://claude.ai/share/26b82b75-623f-4e14-80af-9849254fe92a
