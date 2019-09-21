.model small
.stack 100h

.data

num dw ?    
str   db 6         ;MAX NUMBER OF CHARACTERS ALLOWED (4).
      db ?         ;NUMBER OF CHARACTERS ENTERED BY USER.
      db 6 dup (?) ;CHARACTERS ENTERED BY USER. 

.code       

;------------------------------------------
;FILLS VARIABLE STR WITH '$'.
;USED BEFORE CONVERT NUMBERS TO STRING, BECAUSE
;THE STRING WILL BE DISPLAYED.

dollars proc                 
  mov  si, offset str
  mov  cx, 6
six_dollars:      
  mov  bl, '$'
  mov  [ si ], bl
  inc  si
  loop six_dollars

  ret
dollars endp

;------------------------------------------
;NUMBER TO CONVERT MUST ENTER IN AX.
;ALGORITHM : EXTRACT DIGITS ONE BY ONE, STORE
;THEM IN STACK, THEN EXTRACT THEM IN REVERSE
;ORDER TO CONSTRUCT STRING (STR).

number2string proc
  mov  bx, 10 ;DIGITS ARE EXTRACTED DIVIDING BY 10.
  mov  cx, 0 ;COUNTER FOR EXTRACTED DIGITS.
cycle1:       
  mov  dx, 0 ;NECESSARY TO DIVIDE BY BX.
  div  bx ;DX:AX / 10 = AX:QUOTIENT DX:REMAINDER.
  push dx ;PRESERVE DIGIT EXTRACTED FOR LATER.
  inc  cx ;INCREASE COUNTER FOR EVERY DIGIT EXTRACTED.
  cmp  ax, 0  ;IF NUMBER IS
  jne  cycle1 ;NOT ZERO, LOOP. 
;NOW RETRIEVE PUSHED DIGITS.
  mov  si, offset str
cycle2:  
  pop  dx        
  add  dl, 48 ;CONVERT DIGIT TO CHARACTER.
  mov  [ si ], dl
  inc  si
  loop cycle2  

  ret
number2string endp     

string2number proc
;MAKE SI TO POINT TO THE LEAST SIGNIFICANT DIGIT.
  inc  si ;POINTS TO THE NUMBER OF CHARACTERS ENTERED.
  mov  cl, [ si ] ;NUMBER OF CHARACTERS ENTERED.                                         
  mov  ch, 0 ;CLEAR CH, NOW CX==CL.
  add  si, cx ;NOW SI POINTS TO LEAST SIGNIFICANT DIGIT.
;CONVERT STRING.
  mov  bx, 0
  mov  bp, 1 ;MULTIPLE OF 10 TO MULTIPLY EVERY DIGIT.
repeat:         
;CONVERT CHARACTER.                    
  mov  al, [ si ] ;CHARACTER TO PROCESS.
  sub  al, 48 ;CONVERT ASCII CHARACTER TO DIGIT.
  mov  ah, 0 ;CLEAR AH, NOW AX==AL.
  mul  bp ;AX*BP = DX:AX.
  add  bx,ax ;ADD RESULT TO BX. 
;INCREASE MULTIPLE OF 10 (1, 10, 100...).
  mov  ax, bp
  mov  bp, 10
  mul  bp ;AX*10 = DX:AX.
  mov  bp, ax ;NEW MULTIPLE OF 10.  
;CHECK IF WE HAVE FINISHED.
  dec  si ;NEXT DIGIT TO PROCESS.
  loop repeat ;COUNTER CX-1, IF NOT ZERO, REPEAT.

  ret 
string2number endp  


main proc
;INITIALIZE DATA SEGMENT.
  mov  ax, @data
  mov  ds, ax

;CAPTURE NUMBER AS STRING.
  mov  ah, 0Ah
  mov  dx, offset str
  int  21h

;CONVERT CAPTURED NUMBER FROM STRING TO NUMERIC.
  mov  si, offset str ;PARAMETER FOR STRING2NUMBER.
  call string2number
  mov  num, bx      ;RETURNED VALUE.
 
  call dollars        ;FILL "STR" WITH '$'. NEEDED TO DISPLAY.
  mov  ax, num
  call number2string  ;PARAMETER = AX. RETURNS IN VARIABLE "STR".

;DISPLAY NUMBER CONVERTED TO STRING.
  mov  ah, 9
  mov  dx, offset str
  int  21h


;------------------------------------------
;CONVERT STRING TO NUMBER IN BX.
;SI MUST ENTER POINTING TO THE STRING.

  



;FINISH PROGRAM.
  mov  ax, 4c00h
  int  21h    
main endp
end main
