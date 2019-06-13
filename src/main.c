#include <libRingOfBuffer.h>

#include <stdio.h>
#include <stdlib.h>

m_ringBuffer ringBuffer;

void printBuffer() {
    printf(">");
    for (int a=0; a < ringBuffer.size; a++)
    {
        printf("[");
        char sym = ringPop(&ringBuffer);
        printf("%s", &sym);
       
        printf("]");
    }
    printf("<\n");
}


void infLoop() {
    uint8_t num;
    while(1) {
        printf("Enter symbol: ");
        scanf("%s", &num); 
        
        ringPut(num, &ringBuffer);
        
        printBuffer();
    }
}

int main()
{
    int buffSize = 16;
    
    system("clear");
    printf("Enter buffer size: ");
    scanf("%d", &buffSize); 
    
    ringInit(&ringBuffer, buffSize);
    
    printf("Create buffer with size %d\n",ringBuffer.size);
    
    infLoop();
    
    return 0;
}
