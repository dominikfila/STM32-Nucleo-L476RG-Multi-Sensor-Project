/*
 * 8-seg_disp.c
 *
 *  Created on: Aug 14, 2024
 *      Author: Dominik Fila
 */
#include "8-seg_disp.h"
#include "gpio.h"



void disp(int seg, int num)
{

	HAL_GPIO_WritePin(DISP_COM1_GPIO_Port, DISP_COM1_Pin, 1);
	HAL_GPIO_WritePin(DISP_COM2_GPIO_Port, DISP_COM2_Pin, 1);
	HAL_GPIO_WritePin(DISP_COM3_GPIO_Port, DISP_COM3_Pin, 1);
	HAL_GPIO_WritePin(DISP_COM4_GPIO_Port, DISP_COM4_Pin, 1);
	HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
	HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 0);
	HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
	HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
	HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
	HAL_GPIO_WritePin(LED_DP_GPIO_Port, LED_DP_Pin, 0);


	switch (num)
	{
		case 0:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
			break;
		case 1:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 0);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			break;
		case 3:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			break;
		case 4:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			break;
		case 5:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			break;
		case 6:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			break;
		case 7:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
			break;
		case 8:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			break;
		case 9:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
			break;

		default:
	}
	switch (seg)
	{
		case 1:
			HAL_GPIO_WritePin(DISP_COM4_GPIO_Port, DISP_COM4_Pin, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(DISP_COM3_GPIO_Port, DISP_COM3_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(DISP_COM2_GPIO_Port, DISP_COM2_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(DISP_COM1_GPIO_Port, DISP_COM1_Pin, 0);
			break;
	}
}


void disp_letter(int seg, char letter)
{
	HAL_GPIO_WritePin(DISP_COM1_GPIO_Port, DISP_COM1_Pin, 1);
	HAL_GPIO_WritePin(DISP_COM2_GPIO_Port, DISP_COM2_Pin, 1);
	HAL_GPIO_WritePin(DISP_COM3_GPIO_Port, DISP_COM3_Pin, 1);
	HAL_GPIO_WritePin(DISP_COM4_GPIO_Port, DISP_COM4_Pin, 1);
	HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
	HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 0);
	HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
	HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
	HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);

	switch (seg)
	{
		case 1:
			HAL_GPIO_WritePin(DISP_COM4_GPIO_Port, DISP_COM4_Pin, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(DISP_COM3_GPIO_Port, DISP_COM3_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(DISP_COM2_GPIO_Port, DISP_COM2_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(DISP_COM1_GPIO_Port, DISP_COM1_Pin, 0);
			break;
	}

	switch (letter)//C, c, n
	{
	case 'C':
		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 1);
		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 0);
		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
		break;
	case 'c':
		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 0);
		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
		break;
	case 'n':
		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
		break;
	case 'V':
		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 1);
		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 1);
		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 1);
		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 1);
		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
		break;
	case '-':
		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 0);
		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
		break;
	case 'null':
		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, 0);
		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);
		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, 0);
		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, 0);
		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, 0);
		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, 0);
		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
		break;

	}

}





