#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include <multiboot2.h>
#include "gdt/gdt.h"         // Include GDT header
#include "terminal.h"        // Include terminal header

struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

void write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = colour;
    }
}
int main(uint32_t magic, struct multiboot_info* mb_info_addr) {
    // Initialize the Global Descriptor Table
    load_gdt();

    // Print "Hello World" to the terminal
    //terminal_write("Hello World");
    write_string(15,"Hello world");
    return 0;
}

