#include <sys/ipc.h>   // for the inter process communication 
#include <sys/shm.h>  // for allowing creating of shared memory 
#include <stdio.h>    
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 4

// struct of the segment 
// shared memory layout
struct segment {
  int recv_count;
  int send_count;
  char buff[BUFFER_SIZE];
};

int main (int argc, char* argv[]){
    
    key_t entryKey = 0; // key for shared mem
    int shMemId; // shared memory Identifier
    struct segment *shmm; //creates a segment to use
    char *buf; // pointer to buffer 

    // get key from argv 
    // ./client 500
    entryKey = (int)argv[1]; // typecasted
     
     //////// create a shared memory segment ////////////

    // shMemID is the return value of the shmget() call value 
    shMemId = shmget(entryKey, sizeof(struct segment), IPC_CREAT);

    //check if segment created 
    if (shMemId < 0){
      printf("creation of mem segment did not work\n");
    }

    ///// get a pointer to the mem segment ///////
    shmm = shmat(shMemId, NULL, 0);

  // Transfer data into shared memory from shared mem to buffer //
    buf = shmm->buff;

   // filling the buffer with input 
   printf("Enter your message\n");
   char input[1024];
   fgets(input,1024,stdin); // reads the entire string 
  
  // for loop that will break the arbitarily long message into 4 byte chunks 


    
}
 