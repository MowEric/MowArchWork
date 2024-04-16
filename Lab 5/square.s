#Eric Mow
start: LDI IN
    LD X1, X0 #X0 is the decrement, X1 is the counter, X2 is the reference
    LD X2, X0
    LDI -1
adding: ADD X3, X2 #Loop this until X1 is 0
    ADD X1, X0
    BZ exit
    BRA adding  # This is a branch instruction
exit:
LDI OUT
ST X3 X0
HLT
IN: 2
OUT: 0