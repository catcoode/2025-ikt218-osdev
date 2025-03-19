#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include <multiboot2.h>
#include "gdt/gdt.h"         // Include GDT header
#include "terminal.h"        // Include terminal header
#include "idt/idt.h" 

struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};


int main(uint32_t magic, struct multiboot_info* mb_info_addr) {
    // Initialize the Global Descriptor Table
    load_gdt();

    // Initialize the Interrupt Descriptor Table
    init_idt();

    // Print "Hello World" to the terminal
    //terminal_write("Hello World");
    write_string(15,"Hello world");

    while(1);
    return 0;
}

