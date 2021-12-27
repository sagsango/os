https://www.geeksforgeeks.org/semaphores-in-process-synchronization/
wait (S){
  while(S <= 0); // no-op
  S--;
}

signal (S){
  S++;
}

/**
*Causes spin lock / busy waiting
*just waiting in whole time quantum
*to remove it we have to modify
**/


P(Semaphore s){     //lock
	s = s - 1; 
	if (s < 0) {     //means there are less no of resources than required
    // add process to queue 
		block(); 
	} 
} 

V(Semaphore s){    //signal
	s = s + 1; 
	if (s <= 0) {    //means 1 source is definetly become  free so if some process is still waiting ( s<= 0 ) we have to dispatch
   // remove process p from queue 
		wakeup(p); 
	} 
} 


//library
sem_wait(s);
sem_post(s);
