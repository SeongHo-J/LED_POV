static void delay_int_count(volatile unsigned int nTime){
  for(;nTime>0;nTime--);
}

int main(void){
    (*(volatile unsigned*)0x40023830)|=0x000001ff;
    
    (*(volatile unsigned*)0x40021C00)|=0x55555555; //H   
    (*(volatile unsigned*)0x40022000)|=0x55555555;
    
  
  while(1){
    (*(volatile unsigned*)0x40021C18)|=0xC;  //H
    (*(volatile unsigned*)0x40022018)|=0x500;   
   delay_int_count(60000); 
   (*(volatile unsigned*)0x40021C18)|=0xC0000;  //H
    (*(volatile unsigned*)0x40022018)|=0x5000000;   
   delay_int_count(60000); 
  }
}