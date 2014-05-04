CMPS 111 - Spring 2014
Programming Project #2

Authors: 
	Ryan Gliever -- rgliever@ucsc.edu
	Leland Miller
	Craig Collins
	Mat Fukano

About:
This program changes the minix scheduler to either a dynamic or static lottery scheduler.
In the static lottery scheduler, the number of tickets does not change.
In the dynamic lottery scheduler, the number of tickets is decreased each time
a process runs out of a fixed quantum of time before finishing its task.
To switch between dynamic and static, edit the macro "DYNAMIC" at the top of schedule.c
in path /usr/src/servers/sched :
	change DYNAMIC to 1 to enable dynamic lottery scheduling
	change DYNAMIC to 0 to enable static lottery scheduling

Compiling:
Copy all included files to the correct minix directories.
Run "make install" from path /usr/src/tools.
Once done compiling and installing, use "shutdown" to turn off the virtual machine, and
re-launch minix.
Choose option 2 when booting, as this will be the custom minix in which the changes will
take place.
	
Testing:
To compile and run the testing files, run "make run" in the directory of the testing
files. This will run the tests and redirect the output to a file called
"test_results.md".  
