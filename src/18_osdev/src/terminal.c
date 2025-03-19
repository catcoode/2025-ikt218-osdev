#include "terminal.h"

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80

uint16_t* terminal_buffer;
uint8_t terminal_row, terminal_col;

void terminal_initialize() {
    terminal_buffer = (uint16_t*)VGA_ADDRESS;
    terminal_row = 0;
    terminal_col = 0;
}

void terminal_write(const char* str) {
    while (*str) {
        terminal_buffer[terminal_row * VGA_WIDTH + terminal_col] = (0x0F << 8) | *str;
        terminal_col++;
        str++;
    }
}

void write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = colour;
    }
}