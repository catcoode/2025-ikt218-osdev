section .text
    global trigger_isr32
    global trigger_isr33
    global trigger_isr14

trigger_isr32:
    ; Trigger interrupt 32 (Timer Interrupt)
    int $32
    ret

trigger_isr33:
    ; Trigger interrupt 33 (Keyboard Interrupt)
    int $33
    ret

trigger_isr14:
    ; Trigger interrupt 14 (Page Fault)
    int $14
    ret
