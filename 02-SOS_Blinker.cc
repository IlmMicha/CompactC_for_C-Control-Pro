#define LED1    0

void main(void){
 int i;
 for(i=0;i<5;i++){
  Msg_WriteInt(1);
  Flashing(3,200);
  AbsDelay(200);
  Msg_WriteInt(2);
  Flashing(3,200);
  AbsDelay(200);
  Msg_WriteInt(3);
  Flashing(3,200);
  AbsDelay(1000);
 }
}

void Flashing(int val, int time){
 int cnt;

 Port_DataDirBit(LED1,1);
 Port_WriteBit(LED1,0);
 for(cnt=1;cnt<val;cnt++){
  Port_WriteBit(LED1,1);
  AbsDelay(time);
  Port_WriteBit(LED1,0);
  AbsDelay(time);
 }
}