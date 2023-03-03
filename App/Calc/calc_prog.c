/*
* calc_prog.c
*
* Created: 2/22/2023 8:41:26 PM
*  Author: amrba
*/
#include "../../HAL/Keypad/Keypad_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "calc_interface.h"

f64 Calc_PerformOP(f64 Operand1,f64 Operand2,u8 OP){
	if (OP=='+')
	{
		return Operand1+Operand2;
	}
	else if(OP=='-')
	{
		return Operand1-Operand2;
	}
	else if(OP=='*')
	{
		return Operand1*Operand2;
	}
	else if(OP=='/')
	{
		return Operand1/Operand2;
	}
	return 0;
}
u8 Calc_GetOpPrecedence(u8 op){
	if (op=='+'||op=='-')
	{
		return 1;
	}
	else if(op=='*'||op=='/')
	{
		return 2;
	}
	else if (op=='(')
	{
		return 0;
	}
	return 0;
}

u8  Calc_OpPrecedenceCMP(u8 op1,u8 op2){
	u8 op1_Prec=Calc_GetOpPrecedence(op1);
	u8 op2_Prec=Calc_GetOpPrecedence(op2);
	return (op1_Prec < op2_Prec);
}

f64 Calc_GetOP(u8 * Copy_u8ptrStr){
	u8 OperatorStack[20],OperatorStackInd=0;static u8 OperandStackInd=0;
	static f64 OperandStack[50];
	f64 TempOperand=0;
	f64 TempRes;
	u8 TempChar;
	for (;*Copy_u8ptrStr;Copy_u8ptrStr++){
		TempChar=*Copy_u8ptrStr;

		if (TempChar>='0'&&TempChar<='9')
		{
			/*detect operand*/
			TempChar-='0';
			if (TempOperand==0)
			{
				TempOperand=TempChar;
			}
			else{
				TempOperand=TempOperand*10+(TempChar);
			}
		}
		else{
			/* add operand to stack */
			if (TempOperand!=0)
			{
				OperandStack[OperandStackInd++]=TempOperand;
				TempOperand=0;
			}
			
			if (TempChar==')' )
			{
				//perform MatOP till reaching  '('
				while (TempChar!='('){
					/* Pop 2 operands from stack and pop operartor from stack then perform MathOP */
					TempRes=Calc_PerformOP(OperandStack[OperandStackInd-2],OperandStack[OperandStackInd-1],OperatorStack[OperatorStackInd-1]);
					OperatorStackInd--;
					OperandStackInd-=2;
					OperandStack[OperandStackInd++]=TempRes;
					TempChar=OperatorStack[OperatorStackInd-1];
				}
				/* pop '(' from the stack */
				OperatorStackInd--;
			}
			/* if empty Operator stack or next operator precedence higher than top of stack add to stack*/
			else if(TempChar=='('||OperatorStackInd==0||Calc_OpPrecedenceCMP(OperatorStack[OperatorStackInd-1],TempChar)){
				OperatorStack[OperatorStackInd++]=TempChar;
			}
			else
			{
				//perform MatOP
				TempRes=Calc_PerformOP(OperandStack[OperandStackInd-2],OperandStack[OperandStackInd-1],OperatorStack[OperatorStackInd-1]);
				OperatorStackInd--;
				OperandStackInd-=2;
				OperandStack[OperandStackInd++]=TempRes;
				OperatorStack[OperatorStackInd++]=TempChar;
			}
		}
	}
	/* add operand to stack */
	if (TempOperand!=0)
	{
		OperandStack[OperandStackInd++]=TempOperand;
		TempOperand=0;
	}
	//perform MatOP till Operator stack is empty
	while (OperatorStackInd!=0){
		TempRes=Calc_PerformOP(OperandStack[OperandStackInd-2],OperandStack[OperandStackInd-1],OperatorStack[OperatorStackInd-1]);
		OperatorStackInd--;
		OperandStackInd-=2;
		OperandStack[OperandStackInd++]=TempRes;
	}

	return OperandStack[OperandStackInd-1];
}

void Calc_Start(){
	u8 CalcInputStr[100]={0};
	u8 Calc_StrPtr=0;
	f64 Calc_Result=0;
	u8 Keypad_Num=0;
	while(1){
		Keypad_Num=Keypad_GetKey();
		if (Keypad_Num!=0)
		{
			if(Keypad_Num=='='){
				Calc_Result=Calc_GetOP(CalcInputStr);
				//LCD_ClearDisplay();
				LCD_SendData('=');
				LCD_WriteFLOAT(Calc_Result,2);
			}
			else{
				CalcInputStr[Calc_StrPtr++]=Keypad_Num;
				LCD_SendData(Keypad_Num);
			}
		Keypad_Num=0;	
		}
	}
}