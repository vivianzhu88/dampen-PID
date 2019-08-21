#include <Servo.h>
#include <unistd.h>
using namespace std;

Servo servo;

//private variables
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 1000;  //the value is a number of milliseconds, ie 1 second
int m_highV = 90;
int m_lowV = 10;
int m_period = 400;

//servo setup
void setup() 
{
  servo.attach(10);
}

//gives servo value based on position in function
int highOrLow(int val)
{
  if ((val < m_period) || (val > m_period*3))
  {
    return (val % m_period)/m_period * m_lowV;
  }
  else
  {
    return (val % m_period)/m_period * m_highV;
  }
}

void loop() 
{
  int position = 0;
  int value = 0;
  startMillis = millis();
  int timeElapsed;
  char newKey;
  
  while(true)
  {
    currentMillis = millis();
    timeElapsed = currentMillis - startMillis;
    position = timeElapsed % (m_period*4);
    value = highOrLow(position);
    servo.write(value);
  }
}
