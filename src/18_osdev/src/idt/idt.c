#include "idt.h"
#include "../isr/isr.h"  // Include ISRs
#include "libc/string.h"  // For memset (but not used now)

// Declare IDT with 256 entries
#define IDT_SIZE 256
struct idt_entry idt[IDT_SIZE];
struct idt_ptr idtp;

// External function in assembly to load IDT
extern void load_idt(uint32_t);

// Function to set an entry in the IDT
void set_idt_gate(int num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low = base & 0xFFFF;
    idt[num].selector = sel;
    idt[num].zero = 0;
    idt[num].type_attr = flags;
    idt[num].base_high = (base >> 16) & 0xFFFF;
}

// Function to initialize IDT
void init_idt() {
    idtp.limit = (sizeof(struct idt_entry) * IDT_SIZE) - 1;
    idtp.base = (uint32_t)&idt;

    // Manually clear the IDT
    for (int i = 0; i < IDT_SIZE; i++) {
        idt[i].base_low = 0;
        idt[i].base_high = 0;
        idt[i].selector = 0;
        idt[i].zero = 0;
        idt[i].type_attr = 0;
    }

    // Set three ISRs as an example
    set_idt_gate(32, (uint32_t)isr32, 0x08, 0x8E);
    set_idt_gate(33, (uint32_t)isr33, 0x08, 0x8E);
    set_idt_gate(14, (uint32_t)isr14, 0x08, 0x8E);

    // Load the IDT
    load_idt((uint32_t)&idtp);
}
