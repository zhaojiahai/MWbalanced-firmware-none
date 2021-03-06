/********************************************************************
作者：Songyimiao
建立日期: 20151129
版本：V2.0
喵呜实验室版权所有
/********************************************************************/
#ifndef _CARSTAND_H_
#define _CARSTAND_H_

/******角度控制相关宏定义******/
#define	CAR_ANGLE_SET	      0					//角度预设值
#define CAR_ANGULARSPEED_SET  0					//角速度预设值
#define GRAVITY_OFFSET   (2000)      			//加速度零点偏移值 
#define GYRO_OFFSET      0      				//陀螺仪零点偏移值 
#define	GYROSCOPE_ANGLE_RATIO 30.5		        //陀螺仪比例因子
/******速度控制相关宏定义******/
#define CAR_POSITION_SET  0						//路程预设值
#define CAR_SPEED_SET     g_iCarSpeedSet	    //速度期望值
#define MOTOR_LEFT_SPEED_POSITIVE  ((int)g_fLeftMotorOut >0)   //左轮速度方向判断
#define MOTOR_RIGHT_SPEED_POSITIVE ((int)g_fRightMotorOut>0)   //右轮速度方向判断
#define SPEED_CONTROL_OUT_MAX	MOTOR_OUT_MAX 	
#define SPEED_CONTROL_OUT_MIN	MOTOR_OUT_MIN

/******电机控制相关宏定义******/
#define MOTOR_OUT_DEAD_VAL       0	   //死区值
#define MOTOR_OUT_MAX           1000   //占空比正最大值
#define MOTOR_OUT_MIN         (-1000)  //占空比负最大值	
#define UART2_DATA	   	  32

/* Used to make commands more readable */

enum Command {
  stop,
  forward,
  backward,
  left,
  right,
  imu,
  joystick,
} ; // This is used set a new targetPosition
														   
extern unsigned char xdata g_ucIRFlag;
extern unsigned int xdata g_uiStartCount;
extern unsigned char xdata g_ucLEDCount;
extern int g_iLeftMotorPulse;
extern int g_iRightMotorPulse;
extern float g_fCarAngle;
extern float g_fGravityAngle;
extern float g_fGyroAngleSpeed ;
extern int g_iAccelInputVoltage_X_Axis;
extern int g_iGyroInputVoltage_Y_Axis ;
extern unsigned char g_ucSpeedControlCount ;
extern float g_fSpeedControlOut;
extern float g_fCarSpeed;
extern float g_fCarPosition;
extern float g_fGyroscopeAngleIntegral;
extern int g_iGyroOffset;
extern int g_iLeftMotorPulseSigma  ;
extern float g_fAngleControlOut;
extern float g_fLeftMotorOut;
extern float g_fPower;
extern unsigned char xdata g_ucRxd2;
extern unsigned char xdata g_ucUart2Flag;
extern unsigned char xdata g_ucUltraDis;
extern char xdata g_cUart2Buffer[UART2_DATA];
extern unsigned char xdata g_ucUart2MoveIndex;
extern unsigned char g_ucUart2Count;


void setValues(char *dataInput);
void DirectionControl(void);
void EliminateDirectionDeviation(void);
void DriversInit(void);
void SampleInputVoltage(void);
void CarStandInit(void);
void SpeedControl(void);
void AngleControl(void);
void BluetoothControl(void);	
void GetMotorPulse(void);
void GetGyroRevise(void);
void MotorOutput(void);
void BatteryChecker();
void UltraFollow();
int DataSynthesis(unsigned char REG_Address);

#endif