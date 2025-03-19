#ifndef IDT_H
#define IDT_H

#include "libc/stdint.h"  // Standard integer types

// Each IDT entry (Interrupt Descriptor)
struct idt_entry {
    uint16_t base_low;  // Lower 16 bits of the ISR address
    uint16_t selector;  // Code segment selector in GDT
    uint8_t  zero;      // Always zero
    uint8_t  type_attr; // Type and attributes (present, DPL, etc.)
    uint16_t base_high; // Upper 16 bits of the ISR address
} __attribute__((packed));

// IDT pointer structure
struct idt_ptr {
    uint16_t limit; // Size of IDT in bytes - 1
    uint32_t base;  // Address of the first element in the IDT
} __attribute__((packed));

// Function to initialize the IDT
void init_idt();

#endif
