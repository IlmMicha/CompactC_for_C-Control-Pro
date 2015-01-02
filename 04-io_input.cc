#define LED1        0
#define LED2        16
#define SW2         26

#define OUTPUT      1
#define INPUT       0
#define HIGH        1
#define LOW         0

void main(void){
    Port_DataDirBit(SW2,INPUT);
    Port_WriteBit(SW2,HIGH);

    Port_DataDirBit(LED1,OUTPUT);
    Port_WriteBit(LED1, LOW);

    Port_DataDirBit(LED2,OUTPUT);
    Port_WriteBit(LED2, LOW);

    while(1)
    {
        if(Port_ReadBit(SW2) == LOW){
            Blink(LED1);
        } else {
            Blink(LED2);
        }
    }
}

void Blink(byte led){
        Port_WriteBit(led, HIGH);
        AbsDelay(500);
        Port_WriteBit(led, LOW);
        AbsDelay(500);
}