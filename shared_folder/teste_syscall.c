#include<stdio.h>
#include<unistd.h>

#define sys_faisca_sleep 468

int main() {
    
    unsigned int low = 1000, high = 5000;
    unsigned int decided;    
    printf("Dormindo por algum periodo de %u ate %u milissegundos\n", low, high);

    int ret = syscall(sys_faisca_sleep, low, high, &decided);
    
    if (ret == -1) {
        perror("syscall failed");
        return 1;
    }

    printf("Tudo certo! Processo dormiu por %u milissegundos\n", decided);
    return 0;

    
}
