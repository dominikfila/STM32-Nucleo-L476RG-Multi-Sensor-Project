/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "8-seg_disp.h"
#include "ds18b20.h"

#include "lps25hb.h"
//#include <math.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int i = 0;
int num=0;
int num1=0;
int num2=0;
int num3=0;
int num4=0;

int a_s1=0;
int s1_deboucing [4];
int s1_state;

int a_s2=0;
int s2_deboucing [4];
int s2_state;

int mode = 0;

int temp1 = 0;
float temp = 0;
int temp_busy = 0;

float p0 = 0;
float p = 0;
float h = 0;
int h1 = 0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int __io_putchar(int ch)
{
  if (ch == '\n') {
    __io_putchar('\r');
  }

  HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, HAL_MAX_DELAY);

  return 1;
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_I2C2_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */

  if (ds18b20_init() != HAL_OK) {
    Error_Handler();
  }

  uint8_t ds1[DS18B20_ROM_CODE_SIZE];

  if (ds18b20_read_address(ds1) != HAL_OK) {
    Error_Handler();
  }
  // 0x28, 0x61, 0x64, 0x8, 0xa7, 0x8a, 0x1, 0xe2

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  printf("hello world \n");


  printf("Searching...\n");
  if (lps25hb_init() == HAL_OK) {
	  printf("OK: LPS25HB\n");
  } else {
	  printf("Error: LPS25HB not found\n");
	  Error_Handler();
  }
  HAL_Delay(100);

  printf("T = %.1f*C\n", lps25hb_read_temp());
  printf("p = %.1f hPa\n", lps25hb_read_pressure());

  float p0 = lps25hb_read_pressure();
  float temp = lps25hb_read_temp() + 273.15;
  float p = lps25hb_read_pressure();
  float h = -29.271769 * temp * log(p / p0);

  printf("h = %.2f m\n", h);

  HAL_Delay(1000);


  HAL_ADC_Start(&hadc1);
  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

  uint32_t value = HAL_ADC_GetValue(&hadc1);
  float voltage = 3.3f * value / 4096.0f;
  int voltage_int = 0;

  printf("ADC = %lu (%.3f V)\n", value, voltage);
  HAL_Delay(250);

  /*
  printf("Searching...\n");
  if (lps25hb_init() == HAL_OK) {
  	printf("OK: LPS25HB\n");
  } else {
  	printf("Error: LPS25HB not found\n");
  	Error_Handler();
  }
  HAL_Delay(5000);

  lps25hb_set_calib(-60);
  */



  HAL_TIM_Base_Start_IT(&htim7);
  HAL_TIM_Base_Start_IT(&htim4); // debouncng

  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
  HAL_Delay(500);

  int s1_rising = 0;
  int s2_rising = 0;
  int b1_rising = 0;
  int stoper = 0;

  while (1)
  {


	  if (s2_state == 1 && s2_rising == 1)
	  {
		  s2_rising = 0;
		  mode++;
		  num1 = 0; //cleaning
		  num2 = 0;
		  num3 = 0;
		  num4 = 0;
		  if (mode>4) mode = 0;
	  }
	  else if(s2_state == 0)
	  {
		  s2_rising = 1;
	  }

	  if (s1_state == 1 && s1_rising == 1)
	  {
		  s1_rising = 0;
		  mode--;
		  num1 = 0; //cleaning
		  num2 = 0;
		  num3 = 0;
		  num4 = 0;
		  if (mode<0) mode = 4;
	  }
	  else if(s1_state == 0)
	  {
		  s1_rising = 1;
	  }


	  switch (mode) // 0-stoper, 1-temp_DS18b20, 2-hight_from_presure_LPS25HB, 3-LPS25HB_temp
	  {

	  	  case 0:  // stoper
	  		num1=num%10;
	  		num2=((num%100)-num1)/10;
	  		num3=((num%1000)-num2-num1)/100;
	  		num4=((num%10000)-num3-num2-num1)/1000;
	  		  if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 1 && b1_rising == 1)
	  		  {
	  			  b1_rising = 0;
	  			  if (stoper == 0)
	  			  {
	  				  stoper = 1;
		  			  num = 0;
	  			  }
	  			  else if (stoper == 1) stoper = 0;

	  		  }
	  		  else if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0)
	  		  {
	  			  b1_rising = 1;

	  		  }

	  		  if (stoper == 1)
	  		  {
	  			  num++;
	  			  num1=num%10;
	  			  num2=((num%100)-num1)/10;
	  			  num3=((num%1000)-num2-num1)/100;
	  			  num4=((num%10000)-num3-num2-num1)/1000;
	  			  HAL_Delay(100);
	  		  }
	  		  break;

	  	  case 1: // temp DS18B20

	  		  //HAL_Delay(750);
	  		  //
	  		  if (temp_busy == 0)
	  		  {
	  			  temp_busy = 1;
	  			  ds18b20_start_measure(NULL);
	  			  HAL_TIM_Base_Start_IT(&htim5); // wait 750 to

	  		  }
	  		  break;

	  	  case 2:

	  		  //printf("p = %.1f hPa\n", lps25hb_read_pressure());
	  		  if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0)
	  		  {
	  			  p0 = lps25hb_read_pressure(); //set reference
	  		  }

	  		  temp = lps25hb_read_temp() + 273.15;
	  		  p = lps25hb_read_pressure();
	  		  h = -29.271769 * temp * log(p / p0);
	  		  h1 = (int)(h*100);
	  		  num2 = abs(((h1%100))/10);
	  		  num3 = abs(((h1%1000)-num2-num3)/100);

	  		  printf("h = %.2f m\n", h);
	  		  HAL_Delay(100);

	  		  break;

	  	  case 3: //LPS25HB_temp
	  		  printf("T2 = %.1f*C\n", lps25hb_read_temp());
	  		  temp = lps25hb_read_temp();
	  		  temp1= (int)(temp*10);
	  		  num2 = temp1%10;
	  		  num3 = ((temp1%100)-num2)/10;
	  		  num4 = ((temp1%1000)-num2-num3)/100;
	  		  HAL_Delay(100);

	  		  break;
	  	  case 4:

	  		  HAL_ADC_Start(&hadc1);
	  		  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

	  		  value = HAL_ADC_GetValue(&hadc1);
	  		  voltage = 3.3f * value / 4096.0f;

	  		  printf("ADC = %lu (%.3f V)\n", value, voltage);
	  		  voltage_int = (int)(voltage * 100);
	  		  num2 = voltage_int%10;
	  		  num3 = ((voltage_int%100)-num2)/10;
	  		  num4 = ((voltage_int%1000)-num2-num3)/100;

	  		  HAL_Delay(250);

	  		  break;


	  }



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim == &htim5)
	{
		temp = ds18b20_get_temp(NULL);
		if (temp >= 80.0f)
			printf("Sensor error...\n");
		else
		{
			printf("T1 = %.1f*C\n", temp);

			temp1= (int)(temp*10);
			num2 = temp1%10;
			num3 = ((temp1%100)-num2)/10;
			num4 = ((temp1%1000)-num2-num3)/100;
		}
		temp_busy = 0;
		HAL_TIM_Base_Stop_IT(&htim5);


	}
	if (htim == &htim7)
	{


		if (i==1)
		{
			disp(1, num1);
			if (mode == 1 || mode == 3)
			{
				disp_letter(1, 'C');
			}else if (mode == 2)
			{
				disp_letter(1, 'n');
			}else if(mode == 4)
			{
				disp_letter(1, 'V');
			}
		}
		if (i==2)
		{
			disp(2, num2);
			if (mode == 0) HAL_GPIO_WritePin(LED_DP_GPIO_Port, LED_DP_Pin, 1);
		}
		if (i==3)
		{
			disp(3, num3);
			if (mode == 1 || mode == 2 || mode == 3) HAL_GPIO_WritePin(LED_DP_GPIO_Port, LED_DP_Pin, 1);
		}

		if (i==4)
		{
			disp(4, num4);
			if (mode == 4) HAL_GPIO_WritePin(LED_DP_GPIO_Port, LED_DP_Pin, 1);
			if (mode == 2 && h1 < 0)
			{
				disp_letter(4, '-');
			}
			else if (mode == 2 && h1 >= 0)
			{
				disp_letter(4, 'null');
			}
		}

		i++;
		if (i==5) i=1;
	}
	if (htim == &htim4) //deboucing
	{


		// debouncing s1
		if (HAL_GPIO_ReadPin(S1_button_GPIO_Port, S1_button_Pin)==1)
		{
			s1_deboucing[a_s1] = 1;
			a_s1++;
			if (a_s1>3) a_s1 = 0;

			if (s1_deboucing[0] == 1 && s1_deboucing[1] == 1 && s1_deboucing[2] == 1 && s1_deboucing[3] == 1)
			{
				//HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
				s1_state = 0;
			}

		}else if (HAL_GPIO_ReadPin(S1_button_GPIO_Port, S1_button_Pin) == 0)
		{
			s1_deboucing[a_s1] = 0;
			a_s1++;
			if (a_s1>3) a_s1 = 0;

			if (s1_deboucing[0] == 0 && s1_deboucing[1] == 0 && s1_deboucing[2] == 0 && s1_deboucing[3] == 0)
			{
				//HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
				s1_state = 1;
			}
		}
		// debouncing s2
		if (HAL_GPIO_ReadPin(S2_button_GPIO_Port, S2_button_Pin)==1)
		{
			s2_deboucing[a_s2] = 1;
			a_s2++;
			if (a_s2>3) a_s2 = 0;

			if (s2_deboucing[0] == 1 && s2_deboucing[1] == 1 && s2_deboucing[2] == 1 && s2_deboucing[3] == 1)
			{
				//HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
				s2_state = 0;
			}

		}else if (HAL_GPIO_ReadPin(S2_button_GPIO_Port, S2_button_Pin) == 0)
		{
			s2_deboucing[a_s2] = 0;
			a_s2++;
			if (a_s2>3) a_s2 = 0;

			if (s2_deboucing[0] == 0 && s2_deboucing[1] == 0 && s2_deboucing[2] == 0 && s2_deboucing[3] == 0)
			{
				//HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
				s2_state = 1;
			}
		}

	}

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
