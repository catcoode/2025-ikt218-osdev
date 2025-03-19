#include "isr.h"
#include "../terminal.h"  // Move up one level before accessing terminal.h

// Basic ISR handlers
void isr32() { write_string(15, "ISR 32: Timer Interrupt\n"); }
void isr33() { write_string(15, "ISR 33: Keyboard Interrupt\n"); }
void isr14() { write_string(15, "ISR 14: Page Fault\n"); }
