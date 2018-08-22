#ifndef __DATA_PACK_H
#define __DATA_PACK_H

#include "stm32f10x.h"
/* c 标准库 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>


/**
  ******************************************************************
													   宏定义
  ******************************************************************
  */ 
	
/**
* @name Log print macro definition
* @{
*/
#define DEBUG_LOG_ENABLE	1

#if  DEBUG_LOG_ENABLE 
#define DEBUG_LOG 	printf                 ///<Run log print

#ifndef DEBUG_LOG_NOFORMAT
#define DEBUG_LOG_NOFORMAT 	printf
#endif

#endif

/**@} */
	
//针对不同的编译器调用不同的stdint.h文件
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
#endif

//断言
#define AssertCalled(char,int) 	printf("Error:%s,%d\r\n",char,int)
#define ASSERT(x) if((x)==0) 		AssertCalled(__FILE__,__LINE__)
typedef enum {ASSERT_ERR = 0, ASSERT_SUCCESS = !ERROR} Assert_ErrorStatus;

	
	
#define USE_DATA_CRC  1
	

#define NAME_HEAD1   'x'
#define NAME_HEAD2   'c'
#define NAME_HEAD3   'a'
#define NAME_HEAD4   'i'

#define NAME_TAIL1   'x'
#define NAME_TAIL2   'j'
#define NAME_TAIL3   'i'
#define NAME_TAIL4   'e'

#define DATA_HEAD   Get_Data_Head()
#define DATA_TAIL   Get_Data_Tail()





/**
  ******************************************************************
													   变量声明
  ******************************************************************
  */ 
typedef struct datapack
{
	uint16_t data_length; // 数据长度
	uint16_t data_crc; // 数据长度
	uint32_t data_head; //数据头
//	char data_type; 			//数据类型
	void* data; 		//数据
	uint32_t data_tail; //数据尾
}DataPack;




/**
  ******************************************************************
														函数声明
  ******************************************************************
  */ 

int32_t Create_Pack(void *buff,uint16_t len);
int32_t Usart_Write(uint8_t *buf, uint32_t len);
uint32_t Get_Data_Head(void);
uint32_t Get_Data_Tail(void);





#endif /* __DATA_PACK_H */
