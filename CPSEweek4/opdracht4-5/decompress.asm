  .cpu cortex-m0
  .align 4
  .text
  .global decompress
  
decompress:
  push { r4-r7,lr }
  ldr r5, =compressed 
  b print
  
print:
  ldrb r0, [r5]   
  cmp r0, #0      
  beq done    
  
  cmp r0, #'@'    
  beq decode      
  bl bufferp 
  b toprint
  
  
bufferp:
  push { lr }
  ldr r2, =counter
  ldr r3, [r2]
  ldr r2, =buffer 
  add r3, r3, r2
  strb r0, [r3]
  ldr r2, =counter
  ldr r3, [r2]
  add r3, r3, #1
  str r3, [r2]
  
  bl uart_put_char
  pop { pc }
  
toprint:
  add r5, r5, #1 
  b print
  
decode:          
  add r5, r5, #1 
  ldrb r0, [r5]  
  sub r0, r0, #'0'
  mov r6, r0
  
  add r5, r5, #1 
  ldrb r0, [r5] 
  sub r0, r0, #'0'
  mov r7, r0
  
  ldr r2, =counter
  ldr r3, [r2]
  ldr r2, =buffer
  sub r2, r2, #1
  add r2, r2, r3
  sub r4, r2, r6
  bl plus
  b toprint 
  
plus:
  ldrb r0, [r4]
  cmp r7, #0
  beq toprint 
  bl bufferp
  add r4, r4, #1
  sub r7, r7, #1
  b plus
  
done:
  pop { r4-r7, pc }
  
.bss
buffer:
  .skip 4100

counter:
  .skip 4