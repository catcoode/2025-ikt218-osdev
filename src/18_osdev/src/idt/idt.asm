global load_idt
load_idt:
    lidt [esp + 4]  ; Load IDT from memory
    ret
