https://en.wikipedia.org/wiki/Test-and-set
test_and_lock() is atomic function preset in linux/spinlock.h


#define LOCKED 1
#define UNLOCKED 0
int lock = 0;

int TestAndSet(int* lockPtr) {
    int oldValue;
     
    // -- Start of atomic segment --
    // This should be interpreted as pseudocode for illustrative purposes only.
    // Traditional compilation of this code will not guarantee atomicity, the
    // use of shared memory (i.e., non-cached values), protection from compiler
    // optimizations, or other required properties.
    oldValue = *lockPtr;
    *lockPtr = LOCKED;
    // -- End of atomic segment --
    return oldValue;
}

function threadFunction()
{
     while (TestAndSet(&lock) == 1);
     critical section // only one process can be in this section at a time
     lock = UNLOCKED // release lock when finished with the critical section
}





/**
* Library 
**/

spinlick_init(lock){
    lock =free; \\ 0 = free; 1 = busy   //atomic
}
    
spinlock_lock(lock){
    while(test_ans_set(lock) == busy );  //atomic
}

spinlock_unlock(lock){
    lock = free;                         //atomic
}
 
