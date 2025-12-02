
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

void _start()
{
    //volatile uint8_t* sdram = (uint8_t*)0x10001000;
    volatile uint32_t* uart = (uint32_t*)0x20000000;
    for (;;)
    {
        //*sdram = ((*sdram + 1) & 15) + 'A';

        *uart = 'H';
        *uart = 'E';
        *uart = 'L';
        *uart = 'L';
        *uart = 'O';
        //*uart = *sdram;
        
        *uart = '\n';
        *uart = '\r';
    }
}
