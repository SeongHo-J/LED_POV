
// SDI는 PORTA.0 CLK는 PORTA.2 LE는 PORTA.4 OE는 PORTA.6
#define SDI_A_ON  PORTA|=1
#define SDI_A_OFF PORTA&=~1

#define CLK_A_ON  PORTA|=4
#define CLK_A_OFF PORTA&=~4

#define LE_A_ON  PORTA|=0x10
#define LE_A_OFF PORTA&=~0x10

#define OE_A_ON  PORTA&=~0x40
#define OE_A_OFF PORTA|=0x40


// 딜레이 시간 정의
#define Ti 300       //LED ON Time
#define CLKTi 20     //CLK time