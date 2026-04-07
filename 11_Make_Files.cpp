// Notes Sources,

// Makefile Tutorial: 
// https://courses.grainger.illinois.edu/cs225/fa2017/resources/maketutorial/#linking-generating-the-final-executable

// Practical Examples:
// https://www.yisu.com/ask/38197163.html

// Official Documentation:
// https://www.gnu.org/software/make/manual/


// (Make Tutorial):

// A seperate hello_world.cpp file is created (Name must be same on path directory) in downloads 
// or any other folder you want and after creating this file 

// I will set a path to make it executeable like this:
// cd "/home/nomangull/Downloads/maketutorial/hello/" && g++ hello_world.cpp -o hello_world && "/home/nomangull/Downloads/maketutorial/hello/"hello_world

// here cd is for control directory to access the path given for the file, 
// In, g++ hello_world.cpp -o hello_world , 
// The -o flag tells the compiler to give the executable an alternative name. 
// Otherwise, the default name is a.out

// "/home/nomangull/Downloads/maketutorial/hello/"hello_world
// the above line will confirm which file is to be executed after compilation

// Now if i run this ./hello command on the terminal,
// Here The ./ simply tells your shell to search the current directory for the executable, rather than its normal executable paths.
// If all goes well, you should see Hello, world! printed as output.

// You can get rid of the executable you made by typing: rm hello

// And an, ls , should verify its disappearance. 

// Run the following command:
// g++ -save-temps hello_world.cpp -o hello

// The flag -save-temps tells the compiler to retain the temporary files it makes 
// when we compile our program… so we can look at them! 
// Listing the contents of your current directory should yield four new files: 
// naturally the executable hello, but also hello_world.ii, hello_world.s, 
// and hello_world.o, the temporary files we asked the compiler to save, 
// and our guides into the slightly more technical aspects of basic compilation.

// Running the macro preprocessor: What is hello_world.ii?:

// Run the following line: 
// g++ -E hello_world.cpp -o preprocessed.ii
// Then:
// cat preprocessed.ii 
// All it really did for this program was replace our "include" directive 
// (#include <iostream>) with the actual text of the library we included (and, of course, strip the comment out).

// What does that actually mean? Well, if you were capable of compiling this program 
// at all, somewhere on the machine (be it virtual, remote, or physically present) that 
// compiled it, there exists a file called iostream, which contains the C++ code that implements the i/o streams library.
// If you were using gcc, it’s in the directory where libstdc++ (libstdcxx) is installed. 
// Don’t worry about the specific libraries, it doesn’t really matter, but if you were so inclined, 
// you would be able to find the code on your own machine.

// Back to the preprocessed code. In this case, the only included library was iostream, 
// but it would do exactly the same thing for any other included library. If you had a million include directives, 
// it would go through those millions of lines, find each file you referenced, and tack it to your program, 
// so that when you referenced a function or class defined in one of those standard library files, 
// it would make sense to the compiler—like std::cout in this case, 
// which is a function defined in iostream, that you wouldn’t have been able to use without including the code. 
// Of course the preprocessor has plenty of other jobs as well, but we won’t cover them now.

// Question: Why did we enclose the library name, iostream, in angle brackets?
// Using angle brackets specifies that the preprocessor should look in the standard compiler 
// include paths, and quotes tell it to search the current directory first, and via the standard 
// paths only if that fails. Note that the true standard definition is a little more complicated 
// than this: technically, both behave in an “implementation-defined manner”

// Now you can run:
// cat hello-hello_world.ii (can check the name of the file using ls and run accordingly)
// That’s the output file the preprocessor dumped, and it is identical to the output you saw 
// when you ran the preprocessor yourself. This is the file that the compiler really compiles—not your plain, 
// unpreprocessed source file.

// If you want to be sure, try running:
// diff hello_world.ii preprocessed.ii
// diff returns no output if the files it’s comparing are identical. 
// Make sure that both hello_world.ii and preprocessed.ii were produced by the same compiler, though!

// Now let’s take a look at the next temporary file. 
// Print the contents of hello_world.s:
// cat hello_world.s
// For those of you who have seen assembly code before, the output should be recognisable. 
// If you haven’t, assembly is the low-level intermediate between normal, higher-level programming 
// languages like C++, and the machine code that your computer actually executes. 

// In this case, the compiler (this is the step of compilation that’s actually called compilation) has translated 
// the preprocessed source code from C++ to assembly, and dumped the output as hello_world.s.

// Let’s ask our compiler to directly compile the code that we preprocessed into assembly code:
// g++ -S preprocessed.ii -o compiled.s

// Use diff to verify that the files are the same 
// (again, remember to make sure that both hello_world.s and compiled.s were produced by the same compiler):

// diff hello_world.s compiled.s

// If you used gcc, there shouldn’t be any differences. With clang which is another compiler sources may show the difference in first line of the file. 

// Assembly: What is hello_world.o?
// Just means translating the assembly code from hello_world.s into machine-readable code. 
// That’s known as object code, and the standard suffix for object code is .o—and unlike .s
// Now Run to see machine code:
// cat hello_world.o

// To assemble your assembly code, you can do this:
// g++ -c compiled.s -o assembled.o

// Linking: Generating the final executable:
// Linking is the final step, and arguably the most important and relevant to you. 
// It’s the part you’ll interact with most, and besides perhaps flat out failure to compile at all.

// Note that: 
// Undefined reference errors are pretty much always linking errors, and you will probably have them.

// All a linker does is take all the object files tossed out by the assembling step, 
// and join them together into a single executable—in this case, the file hello which you ran earlier. 
// We only have one object file in our Hello, world program.

// Run the following, to have our compiler link our object file and output our final executable, hello_manual:
// g++ assembled.o -o hello_manual

// Feel free to verify that it does exactly the same thing as our original executable, hello:

// ./hello_manual
// ./hello

// Dealing with multiple object files:
// In files: 
// cd /home/nomangull/Downloads/maketutorial/animals

// The files you’ll see listed are dog.hpp, dog.cpp, and main.cpp. 
// Feel free to check out the source code. dog.hpp is a C++ header file, what we’d call the definition of the 
// Dog class, and dog.cpp is a source file, the implementation for said class. 

// You’ll become more familiar with the details of that relationship as the class moves on, 
// but right now, just know that together, they make the Dog class. main.cpp might look more familiar to you. 

// It’s a lot like hello_world.cpp from the last exercise, in that it has some includes 
// and it has an executable main function. In that main function, it calls a constructor for the class Dog, 
// and asks the object it creates to do a number of things. But including the Dog header file doesn’t 
// actually make the source code available. 

// First, compile the main object file:
// g++ -c main.cpp -o main.o

// Then, try compiling dog_program:

// g++ main.o -o dog_program

// That’s what we did before for our Hello, world program, so what happened this time? 
// You got a bunch of “undefined reference” errors, and if you remember what we said a few paragraphs up, 
// “undefined reference” errors are pretty much always linking errors. 

// The compiler’s telling us that it doesn’t know what the function Dog::bark() 
// (or any Dog function) does, because it doesn’t have that information in main.cpp. 

// The solution is to compile a separate object file for the Dog class. 
// In general, you’ll have one object file per .cpp source file, compiled together with its header file (.h or .hpp) 
// and other necessary dependencies.
// So let’s compile an object file for the Dog class.
// g++ -c dog.cpp

// and then check files with:
// ls

// You’ll see that it added a new file called dog.o, the object file for the Dog class 
// (if you include the header in the compilation, you’ll also see a .h.gch or .hpp.gch file. 

// The .gch file is a precompiled header; all that happens with that is in the future, for fulfilling an 
// #include "dog.hpp" directive, the precompiled header is preferentially used). 

// So now if we wanted to compile these together, we would do this:
// g++ dog.o main.o -o dog_program
// And that should complete just fine. 

// Try running it like so:
// ./dog_program

// But what happens if we change something? If we just change something in main.cpp, 
// like the Dog’s name, we just have to run that final linking command again, and that’s easy. 
// But if we change something in the Dog class itself, like adding a new function, or changing an implementation, 
// we have to recompile the Dog object file, and then link it back to the main object file. 
// That may not seem like a big deal now, but it gets annoying extremely fast 
// when you have more than a single tiny class.

// Introducing the program make:
// Those of you with some experience in compilation are probably aware of a common Unix utility called make. 
// It’s a program extremely widely used on Unix based systems (Microsoft also has a Visual Studio spinoff called nmake), 
// generally to build executable program files from source files.

// The best instruction is by example, so let’s build a basic Makefile for our dog_program. 
// Open a file called Makefile (make sure it’s titlecase—make will recognise the lowercase makefile as well, 
// but our autograder won’t, so it’s good to get into the habit now) with your preferred text editor 
// (mine is emacs, yours may not be, so replace “emacs” with your editor of choice if you disagree (nano in my case)):
// Now run this to makefile: 
// nano Makefile
// now to save file use ctrl + o to save and ctrl + x to exit 

// To check what is inside Makefile use the command:
// cat Makefile

// Here are the few steps to understand make program further: 

// Step 1: Understanding a Makefile Rule:

// This is the general structure:

// target : dependencies
//      command

// target → What you want to create
// dependencies → Files needed to create it
// command → The instruction to build it

// if our target is dog.o, the dependencies (the files needed to make the target) are dog.cpp and dog.hpp 
// And the command is the same as the one we used to compile the object file to begin with. 

// Step 2: Your First Rule:

// dog.o : dog.cpp dog.hpp
// 	  g++ -c dog.cpp

// What this means:
// You want to create → dog.o
// It depends on → dog.cpp and dog.hpp

// To build it → run: g++ -c dog.cpp
// This creates an object file (dog.o)

// Step 3: Second Rule
// main.o : main.cpp
//     g++ -c main.cpp 

// It means:
// Target → main.o
// Depends on → main.cpp
// To compile it → run: g++ -c main.cpp 

// IMPORTANT RULE (Very Common Mistake)
// That space before the command is NOT spaces — it's a TAB
// Wrong:
//     g++ -c main.cpp   (spaces)
// Correct:
// [TAB]g++ -c main.cpp

// If wrong → you get:
// *** missing separator. Stop.

// Copy these first and second rule into your new Makefile, and save it.

// Now run the command:
// rm dog.o dog_program

// then run:
// make

// If you ls now, you’ll see that it’s built the target dog.o 

// Examples of make file priority for rules:

// An aside about the order in which make interprets makefiles:

// When called, make will search the current directory for a file called Makefile or makefile 
// If it finds one, it will execute the first rule in the file, and if one of the dependencies 
// of the first target does not yet exist, it will search for a rule that creates it. 
// So for example, if I have a makefile like so:

// animal_assembly : moose goose cat
// 	command
// moose : antlers hooves fur
// 	command
// goose : beak wings webbed_feet interest_in_bread
// 	command
// cat : whiskers evil_personality
// 	command
 
// then make, when called with no arguments, will attempt to build the target animal_assembly. 
// Assuming the dependencies moose, goose, and cat are already available in the directory, 
// it will completely ignore the rules for them, and build animal_assembly from what’s present. 
// If moose and cat are available, but goose is not, it will note that moose is present, 
// see that goose is not present, look for a rule to build goose, find the rule, build goose, 
// and then note that cat is present and build animal_assembly. 
// If none of moose, goose, cat are present, it will have to build all of them using the rules available.

// But what if you put the target for moose first?

// moose : antlers hooves fur
// 	command
// animal_assembly : moose goose cat
// 	command
// goose : beak wings webbed_feet interest_in_bread
// 	command
// cat : whiskers evil_personality
// 	command

// Well, then if make is called with no arguments, it will make the target moose and stop. 
// If you wanted it to make animal_assembly, you would then have to call it like so:

// make animal_assembly

// So a good rule of thumb is to put the final and most important command at the top.


// Now Back to the dog file example: 

// dog_program : dog.o main.o
// 	clang++ dog.o main.o -o dog_program

// Put that at the top of your makefile, save it, and run make again.

// make
// ls

// Now you should see the executable dog_program, 
// which should behave as it has in all previous post-compilation incarnations.

// Now let’s do one final thing—in general, you should do this when writing your own Makefiles, 
// but it’s especially useful for instructive purposes: we’ll write a clean rule.

// clean :
// 	rm dog_program *.o
// Add that to the bottom of your Makefile (as long as it’s not the top, it doesn’t really matter, 
// but in long Makefiles, you want to separate the clean targets from real compilation-relevant 
// targets for clarity), save it, and run make again, passing clean as an argument to invoke the clean rule:

// make clean
// ls

// We’ve deleted all of the executables and compilation byproducts that we created, to clean up the directory. 
// But the most notable thing about this rule compared to the others we’ve seen is that it:
// a.) lacks dependencies and 
// b.) doesn’t perform anything compilation-related in its command. 

// Let’s talk about those two things a bit.

// The dependency list:
// The dependency list you write for a target exists so that make knows 
// what other targets to ensure you have before you run the command, but if the targets are 
// guaranteed to be present and make isn’t responsible for updating them, 
// make technically doesn’t need to check for anything. 
// Try deleting the dependency list of the target dog.o, and then running:

// make clean
// make dog.o

// Since dog.cpp and dog.hpp are present in the directory, 
// and make doesn’t have to rebuild them individually when they change (as it does for dog.o), 
// make will have never have errors when compiling that line. But if you deleted the dependency 
// list for the target dog_program and ran:

// make clean
// make

// make will output an error that the recipe for target 'dog_program' failed, 
// because dog.o was not in the dependency list, 
// and make therefore did not check to make sure it existed. 
// As such, it didn’t bother to build it. 
// As for including dependencies that make will never have to build 
// (such as .h/.hpp and .cpp files), well, 
// it’s simply good practice to document the dependencies of each target thoroughly. 
// It’s cleaner for other people to read, 
// and it’s a good way for you to confirm that you’re doing what you wanted to do. 

// Remember: 
// Make will run anything you ask it to, because it’s not as smart as you think it is:

// Run this in your terminal:
// cd /home/nomangull/Downloads/maketutorial/file_meddling

// then
// make 

// and check with:
// ls

// And now there’s a new file in the directory. The command

// cat silly_file

// will yield the somewhat accurate phrase “Hello, there is nothing important here”—
// make is simply executing the command you gave it, and it does so blindly, 
// and without any particular personal interest in the results. 

// Execute the following now:

// make move_file
// ls

// Now, when make executes the rule for the target move_file, 
// it simply renames the file silly_file.

// Now run the command:

// make delete_file
// ls

// removes the file altogether. 

// make clean
// ls

// In this Makefile, 
// we are using the clean target to populate our directory with junk. 
// And clean does what we wanted it to do so according to code.

// Note that there are now five empty junk files (the directory is not cleaner), 
// and feel free to remove them:

// make really_clean
// ls

// The first rule you hit is the rule for the target all. 
// all is a phony target, placed at the top of a Makefile, which, in its typical use case, 
// will list all relevant targets which produce executables as dependencies. 
// This ensures that make will compile all of the executables for which there are rules listed.

// When you read the rule for all, you see the dependency listed is fill_file_with_nonsense. 
// Obviously fill_file_with_nonsense doesn’t actually exist in the directory, 
// so we skip down to the rule for fill_file_with_nonsense. 
// The dependency listed is create_file, which also isn’t a real file, 
// so we skip to the rule for create_file, which tells us it has no dependencies, 
// and to touch silly_file. touch is a standard Unix program that can create, 
// as we have done here, an empty file.

// Once that’s done, we can finish up the rule to “build” fill_file_with_nonsense, 
// which pipes the string “Hello, there is nothing important here” into the newly 
// created file silly_file.

// Then we can finish up “building” the target all, for which the command is to 
// print the string “I have mostly created a lot of junk today!” to standard out. 
// And so it does. Take note that, of course, it “builds” none of the targets 
// that are not present in its direct control flow, so the unmentioned targets 
// have to be explicitly passes as arguments to make in order for it to build them.

// Now run:

// make open_file

// and the gedit text editor will open another_silly_file. 
// Feel free to make a little change and run make open_file again. 
// It will open the same file. 
// we can delete it with

// make delete_file


// Marvelous macros ($):

// Makefile syntax allows for a certain kind of variable called a macro. 
// Macros are useful in a standard makefile essentially for the same reason that 
// variables are useful in a normal program—they allow you to quickly define parts of 
// your program which will appear repeatedly, and if you later to decide to change that 
// part of the program, well, it’s a single change, rather than the countlessly many 
// that are possible in large makefiles. In this class, you will never actually need 
// macros to write an effective and mostly unrepetitive makefile, but it’s not a bad 
// habit to get into. 

// let’s see an example.

// cd ../macro_intro/

// chek file:
// ls

// Open up the Makefile:
// nano Makefile

// First, we’ve defined a macro called CXX. Unfortunately, this is a special macro, 
// so we’re going to ignore it briefly and jump to FLAGS. FLAGS is a macro we defined 
// to refer to the flags we’re passing our compiler; in this case, the flag is -O, an 
// optimisation option that turns on a series of other flags which it’s not important 
// for you to know right now.

// FLAGS of course isn’t restricted in value to valid flags (You can learn about it in g++ instructions)

// Now let’s talk about CXX. Not all macro names in the Makefile language are completely 
// without meaning—there is a certain set of names which do have a default meaning. 
// In this case, we’ve defined CXX = clang++. The CXX macro’s default value is usually 
// g++ on Linux systems, so if we never defined the macro CXX, when we used it in the 
// command to compile the executable, it would have probably used g++ instead. 
// Try running make:

// make

// will gives the output:
// clang++ -O hello_world.cpp -o hello
// by creating executeable hello file.

// But if you delete the line that says CXX = clang++, what happens?
// After deleting line:

// Try run:
// make

// output will be same:
// g++ -O hello_world.cpp -o hello


// When you call a macro, enclose it like so: $(MACRO). That’s simply makefile language 
// syntax. (You may have noticed that my example macro’s name was all uppercase—as in 
// fact, all of my macros thus far have been. This is not syntactically required, but it 
// is conventional.)

// So that explains most of what’s going on in this file, but the strange symbols $? and 
// $@ remain, perhaps, mysteries. As you might guess, those are also macros—they’re 
// special predefined macros in the makefile language, with the respective meanings 
// “names of the dependencies (newer than the target)” and “name of the target”, so in 
// this case, $? refers to hello_world.cpp (provided that you make clean before you 
// make), and $@ refers to hello, incidentally (purposefully) the name of the executable 
// created as well. Using shorthand like this is a good motivation to name targets after 
// the file the rule creates (this is, of course, also conventional, and increases the 
// readability of your Makefiles drastically).

// Compiler and linker flags:
// We are going to have a very standard set of flags to pass during compilation and linking. 
// We are going to define these as macros. 
// Here is an example of what those look like:

// # This defines our compiler and linker, as we've seen before.
// CXX = clang++
// LD = clang++ 

// # These are the options we pass to the compiler. 
// # -std=c++1y means we want to use the C++14 standard (called 1y in this version of Clang). 
// # -stdlib=libc++ specifies that we want to use the standard library implementation called libc++
// # -c specifies making an object file, as you saw before
// # -g specifies that we want to include "debugging symbols" which allows us to use a debugging program.
// # -O0 specifies to do no optimizations on our code.
// # -Wall, -Wextra, and -pedantic tells the compiler to look out for common problems with our code. -Werror makes it so that these warnings stop compilation.
// CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic 

// # These are the options we pass to the linker.
// # The first two are the same as the compiler flags.
// # -l<something> tells the linker to go look in the system for pre-installed object files to link with.
// # Here we want to link with the object files from libpng (since we use it in our code) and libc++. Remember libc++ is the standard library implementation. 
// LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread


// the makefile language is actually a complete functional programming language. 
// Will you ever need to write a Fibonacci number generator in the makefile language? Probably not, but you certainly can.

// cd ../functional_fun/

// run:
// make
// This will, of course, get quite slow as n
// gets large (the naive solution takes exponential time), 
// so I suggest you stop the process with a well timed Ctrl-C as it begins to lag.





// (Practical Example): 

// In Linux, Makefiles can help you automate the compilation of C++ projects. 
// Below is a simple example demonstrating how to write a basic Makefile.

// Suppose your project contains the following source files:

// main.cpp
// foo.cpp
// bar.cpp
// And you need to link an external library, such as pthread.

// First, create a file named Makefile and add the following content to it:

// # Compiler
// CXX = g++

// # Compilation options
// CXXFLAGS = -Wall -std=c++11

// # Linking options
// LDFLAGS = -lpthread

// # Target executable file
// TARGET = my_program

// # Source files
// SRCS = main.cpp foo.cpp bar.cpp

// # Object files
// OBJS = $(SRCS:.cpp=.o)

// # Default rule
// all: $(TARGET)

// # Link object files to generate the executable
// $(TARGET): $(OBJS)
// 	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

// # Compile source files to generate object files
// %.o: %.cpp
// 	$(CXX) $(CXXFLAGS) -c $< -o $@

// # Clean generated files
// clean:
// 	rm -f $(TARGET) $(OBJS)



// This Makefile defines the following rules:

// 1. Use the g++ compiler to compile C++ source files.
// 2. Use ` -Wall---` and -std=c++11`---` as compilation options.
// 3. Use -lpthreadas a link option.
// 4. Define the target executable file as follows my_program.
// 5. Define the list of source files SRCS.
// 6. Use the list of source files to generate a list of object files OBJS.
// 7. Define default rules allfor building the target executable.
// 8. Define linking rules to link object files into an executable file.
// 9. Define compilation rules to compile source files into object files.
// 10. Define cleanup rules cleanto delete generated executable files and object files.


// // To build the project, run makethe command in the terminal. To clean up the generated project files, run make cleanthe command.


// Summary Using Chatgpt:
// 🧠 1. BASIC COMPILATION (Single File)
// 🔹 Compile and Run
// g++ hello_world.cpp -o hello
// ./hello

// 👉 Explanation:

// g++ → C++ compiler
// -o hello → output executable name
// ./hello → run program from current directory
// 🔹 Delete Executable
// rm hello

// 👉 Removes compiled program

// ⚙️ 2. COMPILATION PIPELINE (VERY IMPORTANT)
// g++ -save-temps hello_world.cpp -o hello (To generate all at once)
// 👉 Full process:
// .cpp → .ii → .s → .o → executable 
// 🔸 Step 1: Preprocessing
// g++ -E hello_world.cpp -o preprocessed.ii (To execute one by one)
// cat preprocessed.ii

// 👉 What happens:

// Expands #include
// Removes comments
// 🔸 Step 2: Assembly Code
// g++ -S hello_world.cpp -o hello_world.s (To execute one by one)
// cat hello_world.s

// 👉 Converts C++ → Assembly

// 🔸 Step 3: Object File
// g++ -c hello_world.cpp -o hello_world.o (To execute one by one)

// 👉 Creates binary object file (not human-readable)

// 🔸 Step 4: Linking
// g++ hello_world.o -o hello (To execute one by one)
// ./hello

// 👉 Combines object file → executable

// 🐶 3. MULTIPLE FILE COMPILATION
// 🔹 Compile separately
// g++ -c main.cpp -o main.o
// g++ -c dog.cpp -o dog.o
// 🔹 Link together
// g++ main.o dog.o -o dog_program
// ./dog_program

// 👉 Fixes undefined reference errors

// ⚠️ KEY RULE

// 👉 One .cpp file → one .o file

// 🤖 4. INTRODUCTION TO MAKE
// 🔹 Run make
// make

// 👉 Reads Makefile and builds project automatically

// 🧩 5. BASIC MAKEFILE RULE
// target : dependencies
// 	 command

// 👉 Meaning:

// target → file to create
// dependencies → required files
// command → build instruction
// ⚠️ IMPORTANT

// 👉 Command must start with a TAB (not spaces)

// 🧩 6. SIMPLE MAKEFILE (DOG PROJECT)
// dog_program : dog.o main.o
// 	g++ dog.o main.o -o dog_program

// main.o : main.cpp
// 	g++ -c main.cpp -o main.o

// dog.o : dog.cpp dog.hpp
// 	g++ -c dog.cpp -o dog.o
// 🔹 Build project
// make

// 👉 Builds:

// dog.o
// main.o
// dog_program
// 🧹 7. CLEAN RULE (BEST PRACTICE)
// .PHONY: clean
// clean:
// 	rm -f dog_program *.o
// 🔹 Run clean
// make clean

// 👉 Deletes:

// Executable
// Object files
// 🧠 8. HOW MAKE WORKS

// 👉 make:

// Reads Makefile
// Builds first target (default goal)
// Checks dependencies
// Uses timestamps:
// If source changed → rebuild
// Otherwise → skip
// 🧩 9. TARGET PRIORITY

// 👉 Default:

// make

// → builds first target

// 👉 Specific:

// make dog_program
// 🧪 10. MAKE CAN RUN ANY COMMAND
// create_file:
// 	touch file.txt
// make create_file

// 👉 make is not limited to compilation

// 📦 11. MACROS (VARIABLES)
// 🔹 Define macros
// CXX = g++
// CXXFLAGS = -Wall -std=c++11
// 🔹 Use macros
// $(CXX) $(CXXFLAGS)
// 🔥 12. AUTOMATIC VARIABLES (VERY IMPORTANT)
// Variable	Meaning
// $@	Target name
// $^	All dependencies
// $<	First dependency
// $?	Only dependencies newer than target
// 🔹 Example
// $(TARGET): $(OBJS)
// 	$(CXX) $(CXXFLAGS) -o $@ $^

// 👉 Expands to:

// g++ -Wall -std=c++11 -o my_program main.o foo.o bar.o
// 🧱 13. PROFESSIONAL MAKEFILE
// # Compiler
// CXX = g++

// # Compilation flags
// CXXFLAGS = -Wall -std=c++11

// # Linking flags
// LDFLAGS = -lpthread

// # Output file
// TARGET = my_program

// # Source files
// SRCS = main.cpp foo.cpp bar.cpp

// # Object files
// OBJS = $(SRCS:.cpp=.o)

// # Default target
// all: $(TARGET)

// # Linking
// $(TARGET): $(OBJS)
// 	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

// # Compilation
// %.o: %.cpp
// 	$(CXX) $(CXXFLAGS) -c $< -o $@

// # Clean
// .PHONY: clean
// clean:
// 	rm -f $(TARGET) $(OBJS)
// 🚀 14. IMPORTANT COMMANDS (REVISION TABLE)
// Command	Purpose
// g++ file.cpp -o prog	Compile
// ./prog	Run
// g++ -c file.cpp	Create object file
// g++ file.o -o prog	Link
// make	Build project
// make clean	Remove build files
// rm file	Delete file
// ls	List files
// cat file	View content
// diff file1 file2	Compare files
// 🎯 FINAL UNDERSTANDING

// 👉 Compilation flow:

// Source → Object → Executable

// 👉 make:

// Automates builds
// Saves time
// Rebuilds only what changed
// 🧪 PRACTICE (DO THIS)
// rm -f *.o my_program
// make

// Then:

// Modify one .cpp file
// Run make again

// 👉 Observe:

// Only that file recompiles
