#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#include "LED_POV.h"

// 데이터 인식 함수 정의
void MBI_A_5026(unsigned int i){
	int k;

	for(k=0;k<16;k++){
		if(i & (0x0001<<k))SDI_A_ON;// 데이터 인식
		else SDI_A_OFF;
		CLK_A_ON; _delay_us(CLKTi); CLK_A_OFF; // 클럭
	}

}

// LED ON/OFF 함수 정의
void RP(unsigned int i){

	OE_A_OFF;// 데이터를 보내는 동안 OFF
	
	MBI_A_5026(i);// 데이터 전송	

	LE_A_ON; // 출력 래치
	_delay_us(CLKTi);
	LE_A_OFF;
	

	OE_A_ON;// 데이터를 다 보낸 후ON	
	
}
/*
void act_0(){
	long x;
	for(x=0;x<1;x++){
		
		RP(0xffff);
		_delay_us(0.4);
		RP(0x0000);
		_delay_us(0.85);		
	}
}

void act_1(){
	long x;
	for(x=0;x<1;x++){
		
		RP(0xffff);
		_delay_us(0.8);
		RP(0x0000);
		_delay_us(0.45);
	}
}

void act_r(){
	long x;
	for(x=0;x<1;x++){
		
		RP(0x0000);
		_delay_us(50);
	}
}
*/

void act_0(){
	long x;
	for(x=0;x<1;x++){
		
		PORTA=0xff;
		_delay_us(0.4);
		PORTA=0x00;
		_delay_us(0.85);
	}
}

void act_1(){
	long x;
	for(x=0;x<1;x++){
		
		PORTA=0xff;
		_delay_us(0.8);
		PORTA=0x00;
		_delay_us(0.45);
	}
}

void act_r(){
	long x;
	for(x=0;x<1;x++){
		
		PORTA=0x00;
		_delay_us(50);
	}
}

void act(){
	long x;
	for(x=0;x<1;x++){
		
		RP(0xffff);
		_delay_ms(500);
		RP(0);
		_delay_ms(500);
	}
}

int main(){

	DDRA=0xFF;
	
	while(1){
		act();					

	}
	
	return 0;
}