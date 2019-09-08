#include <dos.h> 
#include <stdio.h> 

int main(void) 
{ 
   int i; 

   for (i=1; i<5; i++) 
   { 
      printf("Sleeping for %d seconds\n", i); 
      sleep(i); 
   } 
   return 0; 
} 
  
  

