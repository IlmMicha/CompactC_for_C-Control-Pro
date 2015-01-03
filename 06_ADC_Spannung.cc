#define PA1     1
#define LOW     0
#define INPUT   0

char str[80];
float volt;

void main(void){
    word raw;
    float ref;

    ref= 5.0 / 1023.0;

    while(1){
        raw = GetAdc(PA1);
        volt = raw * ref;

        Str_Printf(str, "Die Spannung am PA1: %1.3f volt)\r",volt);
        Msg_WriteText(str);
        AbsDelay(1000);
    }
}

word GetAdc(byte Channel){
    ADC_Set(ADC_VREF_VCC,Channel);
    return ADC_Read();
}