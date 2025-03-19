#include "gdt.h"

struct GDTEntry gdt[3];
struct GDTPtr gdt_ptr;

void set_gdt_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    gdt[index].base_low = (base & 0xFFFF);
    gdt[index].base_middle = (base >> 16) & 0xFF;
    gdt[index].base_high = (base >> 24) & 0xFF;
    gdt[index].limit_low = (limit & 0xFFFF);
    gdt[index].granularity = (limit >> 16) & 0x0F;
    gdt[index].granularity |= (gran & 0xF0);
    gdt[index].access = access;
}

void load_gdt() {
    gdt_ptr.limit = (sizeof(struct GDTEntry) * 3) - 1;
    gdt_ptr.base = (uint32_t)&gdt;

    set_gdt_entry(0, 0, 0, 0, 0);                // NULL descriptor
    set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment

    asm volatile("lgdt %0" : : "m" (gdt_ptr));  // Load GDT
}
