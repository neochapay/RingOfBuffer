#include "libRingOfBuffer.h"

#include <stdlib.h>

void ringInit(m_ringBuffer *buf, uint16_t size){
    buf->size = size;
    buf->buffer = (char*) malloc(size);
    ringClear(buf);
}

void ringClear(m_ringBuffer* buf){
    buf->idxIn = 0;
    buf->idxOut = 0;
}

void ringPut(char symbol, m_ringBuffer* buf){
    buf->buffer[buf->idxIn++] = symbol;
    
    if (buf->idxIn >= buf->size){
        buf->idxIn = 0;
    }
}

char ringPop(m_ringBuffer *buf){
    char retval;

    retval = buf->buffer[buf->idxOut++];
    
    if (buf->idxOut >= buf->size){
        buf->idxOut = 0;
    }
    
    return retval;
}

uint16_t ringGetCount(m_ringBuffer *buf){
    uint16_t retval = 0;
    if (buf->idxIn < buf->idxOut){
        retval = buf->size + buf->idxIn - buf->idxOut;
    }
    else
    {
        retval = buf->idxIn - buf->idxOut;
    }
    return retval;
}

int32_t ringShowSymbol(uint16_t symbolNumber ,m_ringBuffer *buf){
    
    uint32_t pointer = buf->idxOut + symbolNumber;
    int32_t  retval = -1;
    
    if (symbolNumber < ringGetCount(buf))
    {
        if (pointer > buf->size)
        {
            pointer -= buf->size;
        }
        retval = buf->buffer[pointer] ;
    }
    return retval;
}
