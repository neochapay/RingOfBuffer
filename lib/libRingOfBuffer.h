#ifndef RINGOFBUFFER_H
#define RINGOFBUFFER_H

#include <stdint.h>

typedef struct{
    char *buffer;
    uint16_t idxIn;
    uint16_t idxOut;
    uint16_t size;
} m_ringBuffer;

void ringInit(m_ringBuffer *buf, uint16_t size);
void ringClear(m_ringBuffer* buf);

void ringPut(char symbol, m_ringBuffer* buf);
char ringPop(m_ringBuffer *buf);

uint16_t ringGetCount(m_ringBuffer *buf);
int32_t ringShowSymbol(uint16_t symbolNumber ,m_ringBuffer *buf);


#endif
