/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_cdc_if.c
  * @version        : v1.0_Cube
  * @brief          : Usb device for Virtual Com Port.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "usbd_cdc_if.h"

/* USER CODE BEGIN INCLUDE */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encoder_control.h"
#include "mecanum.h"
/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device library.
  * @{
  */

/** @addtogroup USBD_CDC_IF
  * @{
  */

/** @defgroup USBD_CDC_IF_Private_TypesDefinitions USBD_CDC_IF_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CDC_IF_Private_Defines USBD_CDC_IF_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */
/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CDC_IF_Private_Macros USBD_CDC_IF_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CDC_IF_Private_Variables USBD_CDC_IF_Private_Variables
  * @brief Private variables.
  * @{
  */
/* Create buffer for reception and transmission           */
/* It's up to user to redefine and/or remove those define */
/** Received data over USB are stored in this buffer      */
uint8_t UserRxBufferFS[APP_RX_DATA_SIZE];

/** Data to send over USB CDC are stored in this buffer   */
uint8_t UserTxBufferFS[APP_TX_DATA_SIZE];

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CDC_IF_Exported_Variables USBD_CDC_IF_Exported_Variables
  * @brief Public variables.
  * @{
  */

extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */
extern Wheel wheelRB,wheelLB,wheelRF,wheelLF;
extern float CarSpeedTarget[3];
/* USER CODE END EXPORTED_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CDC_IF_Private_FunctionPrototypes USBD_CDC_IF_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CDC_Init_FS(void);
static int8_t CDC_DeInit_FS(void);
static int8_t CDC_Control_FS(uint8_t cmd, uint8_t* pbuf, uint16_t length);
static int8_t CDC_Receive_FS(uint8_t* pbuf, uint32_t *Len);
static int8_t CDC_TransmitCplt_FS(uint8_t *pbuf, uint32_t *Len, uint8_t epnum);

/* USER CODE BEGIN PRIVATE_FUNCTIONS_DECLARATION */

/* USER CODE END PRIVATE_FUNCTIONS_DECLARATION */

/**
  * @}
  */

USBD_CDC_ItfTypeDef USBD_Interface_fops_FS =
{
  CDC_Init_FS,
  CDC_DeInit_FS,
  CDC_Control_FS,
  CDC_Receive_FS,
  CDC_TransmitCplt_FS
};

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Initializes the CDC media low layer over the FS USB IP
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Init_FS(void)
{
  /* USER CODE BEGIN 3 */
  /* Set Application Buffers */
  USBD_CDC_SetTxBuffer(&hUsbDeviceFS, UserTxBufferFS, 0);
  USBD_CDC_SetRxBuffer(&hUsbDeviceFS, UserRxBufferFS);
  return (USBD_OK);
  /* USER CODE END 3 */
}

/**
  * @brief  DeInitializes the CDC media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_DeInit_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  Manage the CDC class requests
  * @param  cmd: Command code
  * @param  pbuf: Buffer containing command data (request parameters)
  * @param  length: Number of data to be sent (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Control_FS(uint8_t cmd, uint8_t* pbuf, uint16_t length)
{
  /* USER CODE BEGIN 5 */
  switch(cmd)
  {
    case CDC_SEND_ENCAPSULATED_COMMAND:

    break;

    case CDC_GET_ENCAPSULATED_RESPONSE:

    break;

    case CDC_SET_COMM_FEATURE:

    break;

    case CDC_GET_COMM_FEATURE:

    break;

    case CDC_CLEAR_COMM_FEATURE:

    break;

  /*******************************************************************************/
  /* Line Coding Structure                                                       */
  /*-----------------------------------------------------------------------------*/
  /* Offset | Field       | Size | Value  | Description                          */
  /* 0      | dwDTERate   |   4  | Number |Data terminal rate, in bits per second*/
  /* 4      | bCharFormat |   1  | Number | Stop bits                            */
  /*                                        0 - 1 Stop bit                       */
  /*                                        1 - 1.5 Stop bits                    */
  /*                                        2 - 2 Stop bits                      */
  /* 5      | bParityType |  1   | Number | Parity                               */
  /*                                        0 - None                             */
  /*                                        1 - Odd                              */
  /*                                        2 - Even                             */
  /*                                        3 - Mark                             */
  /*                                        4 - Space                            */
  /* 6      | bDataBits  |   1   | Number Data bits (5, 6, 7, 8 or 16).          */
  /*******************************************************************************/
    case CDC_SET_LINE_CODING:

    break;

    case CDC_GET_LINE_CODING:

    break;

    case CDC_SET_CONTROL_LINE_STATE:

    break;

    case CDC_SEND_BREAK:

    break;

  default:
    break;
  }

  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Data received over USB OUT endpoint are sent over CDC interface
  *         through this function.
  *
  *         @note
  *         This function will issue a NAK packet on any OUT packet received on
  *         USB endpoint until exiting this function. If you exit this function
  *         before transfer is complete on CDC interface (ie. using DMA controller)
  *         it will result in receiving more data while previous ones are still
  *         not sent.
  *
  * @param  Buf: Buffer of data to be received
  * @param  Len: Number of data received (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_Receive_FS(uint8_t* Buf, uint32_t *Len)
{
  /* USER CODE BEGIN 6 */
	USBVcomParser(Buf);
	memset(UserRxBufferFS,0,sizeof(UserRxBufferFS));//
  USBD_CDC_SetRxBuffer(&hUsbDeviceFS, &Buf[0]);
  USBD_CDC_ReceivePacket(&hUsbDeviceFS);
  return (USBD_OK);
  /* USER CODE END 6 */
}

/**
  * @brief  CDC_Transmit_FS
  *         Data to send over USB IN endpoint are sent over CDC interface
  *         through this function.
  *         @note
  *
  *
  * @param  Buf: Buffer of data to be sent
  * @param  Len: Number of data to be sent (in bytes)
  * @retval USBD_OK if all operations are OK else USBD_FAIL or USBD_BUSY
  */
uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len)
{
  uint8_t result = USBD_OK;
  /* USER CODE BEGIN 7 */
  USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;
  if (hcdc->TxState != 0){
    return USBD_BUSY;
  }
  USBD_CDC_SetTxBuffer(&hUsbDeviceFS, Buf, Len);
  result = USBD_CDC_TransmitPacket(&hUsbDeviceFS);
  /* USER CODE END 7 */
  return result;
}

/**
  * @brief  CDC_TransmitCplt_FS
  *         Data transmitted callback
  *
  *         @note
  *         This function is IN transfer complete callback used to inform user that
  *         the submitted Data is successfully sent over USB.
  *
  * @param  Buf: Buffer of data to be received
  * @param  Len: Number of data received (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CDC_TransmitCplt_FS(uint8_t *Buf, uint32_t *Len, uint8_t epnum)
{
  uint8_t result = USBD_OK;
  /* USER CODE BEGIN 13 */
  UNUSED(Buf);
  UNUSED(Len);
  UNUSED(epnum);
  /* USER CODE END 13 */
  return result;
}

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */
void USBVcom_printf(const char *format,...)//我感觉这个函数有问题，好像连续两次输出就会丢字符,所以一个函数只能用一次它。另外就是
{
	unsigned char usbtemp[256];//这里的256其实是限制了输出字符的长短，如果长度超过这个数值则会乱码，所以可以设定的大一些
	uint32_t len;
	va_list args;//创建一个va_list类型变量
	va_start(args,format);//初始化可变参数列表，初始化完之后就可以用va_arg(args,int)来当做列表一样来访问每一个参数
	len = vsnprintf((char*)usbtemp,sizeof(usbtemp)+1,(char*)format,args);
	va_end(args);//这句必须有用来释放内存
	
	CDC_Transmit_FS(usbtemp,len);
}

void USBVcomParser(uint8_t* Buf)
{
	
	if (Buf[0]==0x76)//Buf是指向UserRxBufferFS的，也可以用UserRxBufferFS替代。0x76是v的意思,表示速度,注意v需要时小写
	{
		char ch_speed[64];//用来复制字符串,并且保证结束符可以被复制
		float speed;
		
		if(Buf[1]==0x4c && Buf[2]==0x42)//如果第二三位是LB,区分大小写
		{
			strncpy(ch_speed,Buf+5,strlen(Buf+5)+1);//从第六位开始读取数字一直读到末尾，因为第四位和第五位是:和空格
		  speed = atof(ch_speed);//把字符串ch_speed转成float赋给speed
			wheelLB.fSpeedTarget = speed;
			USBVcom_printf("左后轮收到目标速度为%f\n",wheelLB.fSpeedTarget);
		}else if(Buf[1]==0x52 && Buf[2]==0x42)//如果第二三位是RB,区分大小写
		{
			strncpy(ch_speed,Buf+5,strlen(Buf+5)+1);
		  speed = atof(ch_speed);
			wheelRB.fSpeedTarget = speed;
			USBVcom_printf("右后轮收到目标速度为%f\n",speed);
		}else if(Buf[1]==0x4c && Buf[2]==0x46)//如果第二三位是LF
		{
			strncpy(ch_speed,Buf+5,strlen(Buf+5)+1);
		  speed = atof(ch_speed);
			wheelLF.fSpeedTarget = speed;
			USBVcom_printf("左前轮收到目标速度为%f\n",wheelLF.fSpeedTarget);
		}else if(Buf[1]==0x52 && Buf[2]==0x46)//如果第二三位是RF
		{
			strncpy(ch_speed,Buf+5,strlen(Buf+5)+1);
		  speed = atof(ch_speed);
			wheelRF.fSpeedTarget = speed;
			USBVcom_printf("右前轮收到目标速度为%f\n",wheelRF.fSpeedTarget);
		}
	}
	else if(Buf[0]==0x56)//如果给出的速度是大写的V
	{
		
		char ch[32];
		int i=0;
		strcpy(ch,Buf+3);//从buf的第三位起给字符串复制
		char *p = strtok(ch," ");//字符串分割函数，分割符为空格
		while (p != NULL) 
		{
    CarSpeedTarget[i++] = atof(p);     // 将子字符串转换为整数并存储到数组中
    p = strtok(NULL, " ");
    }
    Speed2Wheels(CarSpeedTarget[0],CarSpeedTarget[1],CarSpeedTarget[2]);
		//USBVcom_printf("车身收到目标速度为[%f, %f, %f]\n",CarSpeedTarget[0],CarSpeedTarget[1],CarSpeedTarget[2]);
	}
	/*
	else if (Buf[0]==0x6b && Buf[1]==0x69)
	{
		char ch_ki[64];
		float ki;
		strncpy(ch_ki,Buf+4,strlen(Buf+4)+1);//从第三位开始读取数字一直读到末尾
		ki = atof(ch_ki);
		fKi=ki;
		USBVcom_printf("收到积分参数Ki为%f\n",ki);}
	else if (Buf[0]==0x6b && Buf[1]==0x70)
	{
		char ch_kp[64];
		float kp;
		strncpy(ch_kp,Buf+4,strlen(Buf+4)+1);//从第三位开始读取数字一直读到末尾
		kp = atof(ch_kp);
		fKp=kp;
		USBVcom_printf("收到比例参数Kp为%f\n",kp);
	}
	*/
}
/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */

/**
  * @}
  */

/**
  * @}
  */
