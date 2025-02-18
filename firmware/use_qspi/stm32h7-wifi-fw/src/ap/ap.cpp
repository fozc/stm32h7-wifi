#include "ap.h"
#include "wifi/wifi.h" 




void apInit(void)
{ 
  cliOpen(_DEF_UART1, 115200);
  wifiInit();  
}

void apUpdate(void)
{
  powerUpdate();
  sdUpdate();
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }
    cliMain();    

    apUpdate();
  }
}

