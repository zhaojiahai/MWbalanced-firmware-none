
#include <uart.h>   

/***************************************************************
** ��������: Uart1Init
** ��������: UART1��ʼ������
** �䡡��:   
** �䡡��:   
** ȫ�ֱ���: 
** ������:   ����ʵ����
** ��  ����  Http://miaowlabs.taobao.com
** �ա���:   2014��08��01��
***************************************************************/
void Uart1Init(void)		//115200bps@33.000MHz//9600bps@33.000MHz
{
    SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
	T2L = 0xA5;		//�趨��ʱ��ֵ
	T2H = 0xFC;		//�趨��ʱ��ֵ
	//T2L = 0xB8;		//�趨��ʱ��ֵ
	//T2H = 0xFF;		//�趨��ʱ��ֵ
	AUXR |= 0x01;		//����1ѡ��ʱ��2Ϊ�����ʷ�����
	AUXR |= 0x10;		//������ʱ��2
    //EA = 1;
	TI = 1;

}

/***************************************************************
** ��������: Uart2Init
** ��������: UART1��ʼ������
** �䡡��:   
** �䡡��:   
** ȫ�ֱ���: 
** ������:   ����ʵ����
** ��  ����  Http://miaowlabs.taobao.com
** �ա���:   2014��08��01��
***************************************************************/
void Uart2Init(void)		//115200bps@33.000MHz
{
	S2CON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
	//T2L = 0xA5;		//�趨��ʱ��ֵ
	//T2H = 0xFC;		//�趨��ʱ��ֵ
	T2L = 0xB8;		//�趨��ʱ��ֵ
	T2H = 0xFF;		//�趨��ʱ��ֵ
	AUXR |= 0x10;		//������ʱ��2
}

/***************************************************************
** ��������: UART1ReceiveByte
** ��������: UART1���պ���
** �䡡��:   
** �䡡��:   
** ȫ�ֱ���: 
** ������:   ����ʵ����
** ��  ����  Http://miaowlabs.taobao.com
** �ա���:   2014��08��01��
***************************************************************/
unsigned char UART1ReceiveByte(void)
{
    unsigned char xdata ucRxd1; 
    /*if(RI == 1)					     
    {
      RI = 0;
      ucRxd1 = SBUF;
      return(ucRxd1);		 
    }
    //return 0;	  */
	while(RI==0);
	RI = 0;
	ucRxd1 = SBUF;
	return(ucRxd1);
}

/***************************************************************
** ��������: UART2ReceiveByte
** ��������: UART2���պ���
** �䡡��:   
** �䡡��:   
** ȫ�ֱ���: 
** ������:   ����ʵ����
** ��  ����  Http://miaowlabs.taobao.com
** �ա���:   2014��08��01��
***************************************************************/
unsigned char UART2ReceiveByte(void)
{
    unsigned char xdata ucRxd2; /*
	if ((S2CON & 0x01) == 1)  
    {  
      S2CON &= 0xFE;  
      ucRxd2 = S2BUF;
	  return(ucRxd2);  
    }     		 	   */
	while((S2CON & 0x01) == 0);
	S2CON &= 0xFE;
	ucRxd2 = S2BUF;
	return(ucRxd2);
}

/***************************************************************
** ��������: UART1SendByte
** ��������: UART1���ͺ���
** �䡡��:   
** �䡡��:   
** ȫ�ֱ���: 
** ������:   ����ʵ����
** ��  ����  Http://miaowlabs.taobao.com
** �ա���:   2014��08��01��
***************************************************************/
void UART1SendByte(unsigned char TxD1)  
{   
    SBUF=TxD1;  
    while(TI == 0);//�ȴ�������� 
    //while(!TI);//�ȴ�������� 
    TI=0;   
}  

/***************************************************************
** ��������: UART2SendByte
** ��������: UART2���ͺ���
** �䡡��:   
** �䡡��:   
** ȫ�ֱ���: 
** ������:   ����ʵ����
** ��  ����  Http://miaowlabs.taobao.com
** �ա���:   2014��08��01��
***************************************************************/
void UART2SendByte(unsigned char TxD2)  
{   
    S2BUF=TxD2;  
    while ((S2CON & 0x02) == 0); //�ȴ�������� 
    S2CON &= 0xFD;    
}   