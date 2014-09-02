/* 
* These additional helpers below come from:
* http://web.media.mit.edu/~stefanm/yano/picc_Math32.html
* 
* dec_int32() 		- Decrement a 32bit value by 1
* lt_int32() 		- Is a < b
* lte_int32() 		- Is a <= b
* ge_int32() 		- Is a > b
* gte_int32() 		- Is a >= b
* 
////////////////////////////////////////////////////////////////////////////
//                                                                        
// This code is based on code by Vadim Gerasimov (vadim@media.mit.edu),   
// and extended skillfully by Mark Newman (newman@media.mit.edu) for the  
// Robotic F.A.C.E. project                                               
//                                                                        
// Copyright (C) 2001-2004 MIT Media Laboratory                           
//                                                                        
////////////////////////////////////////////////////////////////////////////
* 	
*/

#if 0
dec_int32(int32_result)
char*	int32_result;
{
	/* Decrement (in-place) a 32bit number */
	if (int32_result[3]--==0) if(int32_result[2]--==0) if (int32_result[1]--==0) --int32_result[0];
}
#else
#asm
    .proc _dec_int32
        ldy    #3
        stx    <__ptr
        sta    <__ptr+1
        
        sec
        lda    [__ptr], y
        sbc    #$01
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        sbc    #$00
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        sbc    #$00
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        sbc    #$00
        sta    [__ptr], y
    
    rts
    .endp
#endasm
#endif

#if 0
inc_int32(int32_result)
char*	int32_result;
{
	/* Increment (in-place) a 32bit number */
	 if (int32_result[3]++==0) if(int32_result[2]++==0) if (int32_result[1]++==0) ++int32_result[0]; 
}
#else 
#asm
    .proc _inc_int32
        ldy    #3
        stx    <__ptr
        sta    <__ptr+1
        
        clc
        lda    [__ptr], y
        adc    #$01
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        adc    #$00
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        adc    #$00
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        adc    #$00
        sta    [__ptr], y    
    rts
    .endp
#endasm
#endif

lt_int32(int32_a, int32_b)
char*	int32_a;
char*	int32_b;
{
	/* Boolean - Less Than (a < b) */
	int i;
	for (i = 3; i >= 0; i--) {
		if (int32_a[i] > int32_b[i])
			return 0;
		if (int32_a[i] < int32_b[i])
			return 1;
	}
	return 0;
}

lte_int32(int32_a, int32_b)
char*	int32_a;
char*	int32_b;
{
	/* Boolean - Less Than or Equal To (a <= b) */
	int i;
	for (i = 3; i >= 0; i--) {
		if (int32_a[i] < int32_b[i]) {
			return 1;
		}
		if (int32_a[i] > int32_b[i]) {
			return 0;
		}
	}
	return 1;
}

gt_int32(int32_a, int32_b)
char*	int32_a;
char*	int32_b;
{
	/* Boolean - Greater Than (a > b) */
	int i;
	for (i = 3; i >= 0; i--) {
		if (int32_a[i] < int32_b[i]) {
			return 0;
		}
		if (int32_a[i] > int32_b[i]) {
			return 1;
		}
	}
	return 0;
}

gte_int32(int32_a, int32_b)
char*	int32_a;
char*	int32_b;
{
	/* Boolean - Greater Than or Equal To (a >= b) */
	int i;
	for (i = 3; i >= 0; i--) {
		if (int32_a[i] > int32_b[i]) {
			return 1;
		}
		if (int32_a[i] < int32_b[i]) {
			return 0;
		}
	}
	return 1;
}

#if 0
shift_int32(int32_result)
char*	int32_result;
{
	/* Bitshifts a 32bit number */
	
	char i, in, out;
	in = 0;
	for (i = 0; i < 4; i++) {
		out = int32_result[i] >> 7;
		int32_result[i] = in + (int32_result[i] << 1);
		in = out;
	}
}
#else
#asm
    .proc _shift_int32
        ldy    #3
        stx    <__ptr
        sta    <__ptr+1
        
        lda    [__ptr], y
        asl    A
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        rol    A
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        rol    A
        sta    [__ptr], y
        
        dey
        lda    [__ptr], y
        rol    A
        sta    [__ptr], y
    rts
    .endp
#endasm
#endif
