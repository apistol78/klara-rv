
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

void _start()
{
    volatile uint32_t* mem = (uint32_t*)0x10000000;
    volatile uint32_t* io = (uint32_t*)0x20000000;
    for (;;)
    {
        (*mem)++;
        *io = *mem;
    }
}
