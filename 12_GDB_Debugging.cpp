// GDB_Tutorial Source: https://icgrp.github.io/ese532_handouts/hw1/gdb_tutorial.html
// Official GDB manual: https://sourceware.org/gdb/current/onlinedocs/gdb.html/

// GDB (GNU Debugger) is a tool that lets you stop your program in the middle of running, 
// look at what’s happening inside, and find bugs. 
// It’s like an X-ray machine for your code.


// Create a file named program.cpp:

// #include <iostream>
// using namespace std;

// void log_msg(const char* message) {
//     cout << message;
// }

// void my_broken_function() {
//     int a = 10;
//     int* p = nullptr;          // p points to nothing (null pointer)
//     cout << "Value of a is " << a << endl;
//     *p = 1;                    // CRASH! Trying to write to address 0
// }

// int main() {
//     log_msg("Welcome to the wonderful world of segfaults!\n");
//     log_msg("Brace for impact! We are about to crash!\n");
//     my_broken_function();
//     return 0;
// }

// In my case it is saved in home/Downloads/gdb_practice/program.cpp

// Step 1: Compile with Debug Info:

// Compile and run:

// g++ -g program.cpp -o program 

// ./program

// you will see: Segmentation fault (core dumped)  error msg

// Step 2: Start GDB:

// Now run:

// gdb ./program

// Step 3: Run the Program Inside GDB:

// At the (gdb) prompt:

// (gdb) run

// GDB will start your program, and when it crashes, it will stop and show you where:

// Program received signal SIGSEGV, Segmentation fault.
// 0x0000000000400556 in my_broken_function () at program.cpp:12
// 12      *p = 1;

// Now you know line 13 is where the crash happens.

// Step 4: Restart from the Beginning:
// To debug properly, we want to start from the very first line of main(). Use the start command:

// (gdb) start

// GDB will set a temporary breakpoint at main and run until there. You’ll see:

// Temporary breakpoint 1, main () at program.cpp:16
// 16      log_msg("Welcome to the wonderful world of segfaults!\n");

// Now you’re paused at line 16, before anything runs.

// Step 5: Step Into a Function (step):

// The command step goes inside a function call. Try it:

// (gdb) step

// log_msg (message=0x400630 "Welcome to the wonderful world of segfaults!\n") at program.cpp:5
// 5       cout << message;
// Now you’re inside log_msg. To see where you are, use list:

// (gdb) list

// E.g:
// 1       #include <iostream>
// 2       using namespace std;
// 3
// 4       void log_msg(const char* message) { // here you are
// 5           cout << message;
// 6       }
// 7
// 8       void my_broken_function() {
// 9           int a = 10;
// 10          int* p = nullptr;

// Step 6: Finish the Current Function (finish):

// To run the rest of log_msg and return to main, use finish:

// (gdb) finish

// Run till exit from #0  log_msg (message=0x400630 "Welcome to the wonderful world of segfaults!\n")
//     at program.cpp:5
// Welcome to the wonderful world of segfaults!
// main () at program.cpp:17
// 17      log_msg("Brace for impact! We are about to crash!\n");

// Now you’re back in main, at line 18.

// Step 7: Step Over a Function (next):

// If you want to run a function without stepping into it, use next:

// (gdb) next

// Brace for impact! We are about to crash!
// 19      my_broken_function();

// Now you’re at line 19, just about to call the broken function.

// Step 8: Set a Breakpoint Inside the Suspect Function:

// Instead of stepping into it right away, let’s set a breakpoint at line 12 
// (inside my_broken_function). First, we need to know line numbers. 
// Use list around the function:

// (gdb) list my_broken_function

// 8       void my_broken_function() {
// 9           int a = 10;
// 10          int* p = nullptr;
// 11          cout << "Value of a is " << a << endl;
// 12          *p = 1;
// 13      }

// Now set a breakpoint at line 12 (the crash line):

// (gdb) break program.cpp:12

// Breakpoint 2 at 0x40053e: file program.cpp, line 12.

// Now continue running until that breakpoint:

// (gdb) continue
// Continuing.

// Breakpoint 2, my_broken_function () at program.cpp:12
// 12          *p = 1;

// The program paused before executing the crash line.

// Step 9: Inspect Local Variables:

// Use info locals to see all local variables and their current values:

// (gdb) info locals

// a = 10
// p = 0x0
// p is 0x0 (null). That’s the problem!

// You can also print a single variable:

// (gdb) print a

// $1 = 10

// (gdb) print p
// $2 = (int *) 0x0

// Step 10: See the Call Stack (backtrace):
// If you want to know how you got here, use backtrace (or bt):

// (gdb) backtrace

// #0  my_broken_function () at program.cpp:12
// #1  0x0000000000400581 in main () at program.cpp:18

// This shows: the crash happened in my_broken_function, which was called from main at line 18.

// Step 11: Continue to the Crash:

// Now you can continue to see the crash happen:

// (gdb) continue
// Continuing.

// Program received signal SIGSEGV, Segmentation fault.
// 0x0000000000400556 in my_broken_function () at program.cpp:12
// 12          *p = 1;

// Exactly as expected.

// Extras:
// Step 12: Using a Core Dump (Optional):
// Sometimes you can’t reproduce the crash on your machine, but you have a core dump – 
// a snapshot of memory at the time of crash. You can try to debug it on another computer 
// because of snapshot of memory.

// To enable core dumps on your personal Linux machine:
// Run command on terminal:
// bash
// Then run:
// ulimit -c unlimited
// Then run the program – it will create a file named core or core.1234. 
// Load it with GDB:
// gdb ./program core
// GDB will show you exactly where the crash happened, 
// without having to rerun the program.


// Important GDB Commands:

// Command                 Shortcut    What it does


// --- Running and Starting ---
// run                     r           Start the program
// start                   –           Start program and stop at main
// restart                 r           Restart program


// --- Breakpoints ---
// break file.cpp:line     b           Set a breakpoint at specific file and line
// break func_name         b           Set breakpoint at a function
// delete                  d           Delete all breakpoints
// info breakpoints        i b         List all breakpoints
// watch var               –           Break when variable value changes
// rwatch var              –           Break when variable is read
// awatch var              –           Break on read/write of variable


// --- Execution Control ---
// continue                c           Resume execution until next breakpoint or crash
// step                    s           Step into function (go line by line)
// next                    n           Execute next line, skip function calls
// stepi                   si          Execute one machine instruction (assembly level)
// nexti                   ni          Next instruction (assembly level)
// finish                  –           Run until current function returns


// --- Inspecting Variables ---
// print var               p           Show value of a variable
// print *ptr              p           Dereference pointer
// print &var              p           Show address of variable
// print var@N             p           Print N elements (arrays)
// set var x=10            –           Change variable value during debugging
// info locals             –           Show all local variables
// info args               –           Show function arguments
// display var             –           Automatically print variable every step
// undisplay               –           Remove automatic display


// --- Stack and Frames ---
// backtrace               bt          Show the call stack
// where                   bt          Same as backtrace
// frame n                 f           Switch to stack frame n
// up                      –           Move up in call stack
// down                    –           Move down in call stack


// --- Source Code ---
// list                    l           Show source code around current line
// list func_name           l           Show source code of a function
// list file.cpp:line       l           Show code at specific line
// info source             –           Show current source file info


// --- Registers & Low-Level ---
// info registers          i r         Show CPU registers (advanced debugging)


// --- Misc ---
// shell command           –           Run shell command inside gdb
// help command            –           Get help about a command