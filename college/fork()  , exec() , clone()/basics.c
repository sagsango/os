https://www.geeksforgeeks.org/fork-system-call/
https://ece.uwaterloo.ca/~dwharder/icsrts/Tutorials/fork_exec/
http://www-h.eng.cam.ac.uk/help/tpl/unix/fork.html
http://www.yolinux.com/TUTORIALS/ForkExecProcesses.html
https://github.com/angrave/SystemProgramming/wiki
https://stackoverflow.com/questions/19099663/how-to-correctly-use-fork-exec-wait


#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	// make two process which run same 
	// program after this instruction 
	fork(); 
	printf("Hello world!\n"); 
	return 0; 
} 



#include <stdio.h> 
#include <sys/types.h> 
int main() 
{ 
	fork(); 
	fork(); 
	fork(); 
	printf("hello\n"); 
	return 0; 
} 



#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkexample() 
{ 
	// child process because return value zero 
	if (fork() == 0) 
		printf("Hello from Child!\n"); 

	// parent process because return value non-zero. 
	else
		printf("Hello from Parent!\n"); 
} 
int main() 
{ 
	forkexample(); 
	return 0; 
} 




#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkexample() 
{ 
	int x = 1; 

	if (fork() == 0) 
		printf("Child has x = %d\n", ++x); 
	else
		printf("Parent has x = %d\n", --x); 
} 
int main() 
{ 
	forkexample(); 
	return 0; 
} 



#include <stdio.h> 
#include <unistd.h> 
int main() 
{ 
	fork(); 
	fork() && fork() || fork(); 
	fork(); 
	printf("forked\n"); 
	return 0; 
} 

