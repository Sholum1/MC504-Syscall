#include<stdio.h>
#include<unistd.h>

#define sys_sleep_proc 468

int main() {
    
    long ret;
    unsigned int seconds = 5000;

    printf("Sleeping for %u seconds...\n", seconds);
    
    // Call the syscall to sleep for a specified number of seconds
    ret = syscall(sys_sleep_proc, seconds);

    // Check if the syscall was successful
    if (ret == -1) {
        perror("syscall failed");
        return 1;
    }

    printf("Slept for %u seconds\n", seconds);
    return 0;

    
}