#define LED1    0
#define LED2    16

#thread 0, 0, 10
#thread 1, 128, 10
#thread 2, 256, 10

void main(void)
{
    Port_DataDirBit(LED1,1);
    Port_DataDirBit(LED2,1);

    Port_WriteBit(LED1,0);
    Port_WriteBit(LED2,0);

    Thread_Start(1,thread1);
    Thread_Start(2,thread2);

    while(1);
}

void thread1(void)
{
    while(1)
    {
      Port_ToggleBit(LED1);
      Thread_Delay(25);
      Port_ToggleBit(LED2);
      Thread_Delay(25);
    }
}

void thread2(void)
{
    int i;
    while(1)
    {
      i = i + 1;
      Msg_WriteInt(i);
      Msg_WriteText(".: Ausgabe Thread 2 \r");
      Thread_Delay(100);
    }
}