int compare and swap(int *value, int expected, int new value){
    int temp = *value;
    if (*value == expected)
    *value = new value;
    return temp;
}

do{
  while (compare and swap(&lock, 0, 1) != 0); 
  /* do nothing */
  /* critical section */
  lock = 0;
  /* remainder section */
} while (true);
