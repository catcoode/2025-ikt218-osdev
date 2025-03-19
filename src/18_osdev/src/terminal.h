#ifndef TERMINAL_H
#define TERMINAL_H

#include "libc/stddef.h"
#include "libc/stdint.h"

void terminal_initialize();
void terminal_write(const char* str);
void write_string( int colour, const char *string );
#endif
