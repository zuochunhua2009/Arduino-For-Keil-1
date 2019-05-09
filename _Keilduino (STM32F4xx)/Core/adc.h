#ifndef __ADC_H
#define	__ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mcu_type.h"

// 转换通道个数
#define ADC_CHANNEL_NUM 8
extern uint16_t ADC_ConvertedValue[ADC_CHANNEL_NUM];//ADC DMA Buffer


/**************************函数声明********************************/
void ADCx_DMA_Init(void);
void ADCx_Init(ADC_TypeDef* ADCx);

uint16_t Get_DMA_ADC(uint8_t Channel);
uint16_t Get_ADC(ADC_TypeDef* ADCx, uint8_t ADC_Channel);

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H */
