

#ifndef   __CONFIG_H__
#define   __CONFIG_H__

#define  PTA_EN  SIM_SCGC5_PORTA_MASK
#define  PTB_EN  SIM_SCGC5_PORTA_MASK
#define  PTC_EN  SIM_SCGC5_PORTA_MASK
#define  PTD_EN  SIM_SCGC5_PORTA_MASK
#define  PTE_EN  SIM_SCGC5_PORTA_MASK

//ѡ��Ҫʹ����Щ�˿ڵ�ʱ�ӣ������õģ�               ����ѡ��
#define  PORT_CLK_EN    (PTA_EN | PTB_EN | PTC_EN | PTD_EN | PTE_EN)





#endif