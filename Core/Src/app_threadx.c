/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "app_threadx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
TX_THREAD threadG_handle;
TX_THREAD threadB_handle;

uint8_t tracex_buffer[TRACEX_BUFFER_SIZE] __attribute__ ((section(".trace")));

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;

  /* USER CODE BEGIN App_ThreadX_MEM_POOL */
  (void)byte_pool;
  /* USER CODE END App_ThreadX_MEM_POOL */

  /* USER CODE BEGIN App_ThreadX_Init */

  CHAR *pointer;

  tx_trace_enable(&tracex_buffer, TRACEX_BUFFER_SIZE, 30);

    /* Allocate the stack for ThreadG.  */
    if ((ret = tx_byte_allocate(byte_pool, (VOID **) &pointer,
                         APP_STACK_SIZE, TX_NO_WAIT)) != TX_SUCCESS)
    {
    	Error_Handler();
    }

    /* Create ThreadG.  */
    if ((ret = tx_thread_create(&threadG_handle, "ThreadG", threadG_entry, 0,
                         pointer, APP_STACK_SIZE,
                         THREADG_PRIO, THREADG_PREEMPTION_THRESHOLD,
                         TX_NO_TIME_SLICE, TX_AUTO_START)) != TX_SUCCESS)
    {
    	Error_Handler();
    }

    /* Allocate the stack for ThreadB.  */
    if ((ret = tx_byte_allocate(byte_pool, (VOID **) &pointer,
                             APP_STACK_SIZE, TX_NO_WAIT)) != TX_SUCCESS)
    {
        Error_Handler();
    }
    /* Create ThreadB.  */
    if ((ret = tx_thread_create(&threadB_handle, "ThreadB", threadB_entry, 0,
                         pointer, APP_STACK_SIZE,
                         THREADB_PRIO, THREADB_PREEMPTION_THRESHOLD,
                         TX_NO_TIME_SLICE, TX_AUTO_START)) != TX_SUCCESS)
    {
    	Error_Handler();
    }


  /* USER CODE END App_ThreadX_Init */

  return ret;
}

/**
  * @brief  MX_ThreadX_Init
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */

  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
