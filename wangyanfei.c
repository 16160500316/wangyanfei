#include"LPC11XX.H"
unsigned int status;
/*******************************************************
*FunctionName :LedInit()
*Description :初始化LED引脚
*EntryParameter :None
*RE+eturnValue : None
*********************************************************/
void  LedInit(void)
{
LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);
LPC_IOCON->PIO2_0 	&=~0x07;
LPC_IOCON->PIO2_0   |=0x00;
LPC_IOCON->PIO2_1   &=~0x07;
LPC_IOCON->PIO2_1   |=0x00;
LPC_SYSCON ->SYSAHBCLKCTRL &=~(1<<16);	
LPC_SYSCON ->SYSAHBCLKCTRL |=(1<<6);
LPC_GPIO2->DIR|=(1<<0);	
LPC_GPIO2->DATA |=(1<<0);	
LPC_GPIO2->DIR|=(1<<1);	
LPC_GPIO2->DATA |=(1<<1);
}
/******************************************************
*FunctionName :SysTickInit()
*Description :初始化系统节拍计时器
*EntryParameter :None
*RE+eturnValue : None
*********************************************************/
void SysTickInit(void )
{
SysTick ->CTRL &=~(1<<2);
SysTick->LOAD=12499999;
SysTick->VAL =0;
SysTick->CTRL |=((1<<1)|(1<<0));	
NVIC_EnableIRQ(SysTick_IRQn)	;
}
/*******************************************************
*FunctionName :SysTick_Handler()
*Description :系统节拍定时器中断服务函数
*EntryParameter :None
*RE+eturnValue : None
********************************************************/
void SysTick_Handler(void)
{
	status =LPC_GPIO2->DATA ;
	LPC_GPIO2->DATA=~status ;
}
/*******************************************************
*FunctionName :main()
*Description : 主函数
*EntryParameter :None
*RE+eturnValue : None
********************************************************/
int main(void)
{
 LedInit();
 SysTickInit();
 while(1)
 {
;
}
}