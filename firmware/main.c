/**
* @file main.c
* @author Lea Calot
* @date 2023/12/05
* @brief Main program body.
* SPDX-License-Identifier: CERN-OHL-W-2.0+

/*
 *@Note
 *Example routine to emulate a simulate USB-CDC Device, USE USART2(PA2/PA3);
 *Please note: This code uses the default serial port 1 for debugging,
 *if you need to modify the debugging serial port, please do not use USART2
*/

#include "ch32v20x_usbfs_device.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
	Delay_Init( );
	USART_Printf_Init( 115200 );
	printf("SystemClk:%ld\r\n",SystemCoreClock);
	RCC_Configuration( );

	/* Tim2 init */
    TIM2_Init( );

	/* Usart1 init */
    UART2_Init( 1, DEF_UARTx_BAUDRATE, DEF_UARTx_STOPBIT, DEF_UARTx_PARITY );

    /* USB20 device init */
    USBFS_RCC_Init( );
    USBFS_Device_Init( ENABLE );

    printf( "main\r\n" );

	for(;;)
	{
        UART2_DataRx_Deal( );
        UART2_DataTx_Deal( );
	}
}
