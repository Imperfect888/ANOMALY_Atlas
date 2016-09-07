#include <SPI.h>
#include <RF24.h>


RF24 radio(9, 10); // можно использовать любые
const uint32_t pipe = 123456789; // адрес

struct Player
{
  short int Anomaly = 10;
};

struct Player Player;

void setup()
{

  
  Serial.begin(9600);
  radio.begin();
  delay(2);
  radio.setChannel(9);
  radio.setDataRate(RF24_1MBPS); // скорость обмена данными RF24_1MBPS или RF24_2MBPS
  radio.setPALevel(RF24_PA_MIN);
  radio.openWritingPipe(pipe); // открыть канал на отправку
}


void loop()   
{
  radio.write(&Player.Anomaly,1);


  
  /*int data=analogRead(0);

  radio.write(&data,sizeof(data));
*/

  
}
