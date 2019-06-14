
int i;                            //定义变量i
int tonepin=6;                    //定义蜂鸣器引脚

//定义led灯引脚
int LED1=8;
int LED2=9;
int LED3=10;
int LED4=11;
int LED5=12;
int n;

//定义超声波引脚
const int TrigPin = A2; 
const int EchoPin = A3; 
float cm = 1000; 


void setup()
{
  //设置各个引脚的初始状态 
  for(n=8;n<=12;n++)
  {
    pinMode(n, OUTPUT);  
  }
  //设置超声波初始状态
  Serial.begin(9600); 
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT); 
  //设置蜂鸣器引脚
  pinMode(tonepin,OUTPUT);
}

void loop(){
  if (cm < 10) {
    for (i = 200; i <= 800; i++)        //将频率从200HZ 增加到800HZ
    {
      tone(tonepin,i);               //输出频率
      if(i <= 260) { digitalWrite(LED1, HIGH); }
      else if(i <= 320) { digitalWrite(LED2, HIGH); }
      else if(i <= 380) { digitalWrite(LED3, HIGH); }
      else if(i <= 440) { digitalWrite(LED4, HIGH); }
      else if(i <= 500) { digitalWrite(LED5, HIGH); }
      else if(i <= 560) { digitalWrite(LED5, HIGH); }
      else if(i <= 620) { digitalWrite(LED4, HIGH); }
      else if(i <= 680) { digitalWrite(LED3, HIGH); }
      else if(i <= 740) { digitalWrite(LED2, HIGH); }
      else { digitalWrite(LED1, HIGH); }
      delay(5);                     //该频率维持5毫秒   
      if(i <= 260) { digitalWrite(LED1, LOW); }
      else if(i <= 320) { digitalWrite(LED2, LOW); }
      else if(i <= 380) { digitalWrite(LED3, LOW); }
      else if(i <= 440) { digitalWrite(LED4, LOW); }
      else if(i <= 500) { digitalWrite(LED5, LOW); }
      else if(i <= 560) { digitalWrite(LED5, LOW); }
      else if(i <= 620) { digitalWrite(LED4, LOW); }
      else if(i <= 680) { digitalWrite(LED3, LOW); }
      else if(i <= 740) { digitalWrite(LED2, LOW); }
      else { digitalWrite(LED1, LOW); }
    }
    
    for (i = 400; i <= 2000; i += 400) {
      for (int k = 0; k < 4; k++) {
        for (int j = 8; j <= 12; j++) {
          digitalWrite(j, HIGH);
        }
        delay(40);
        for (int j = 8; j <= 12; j++) {
          digitalWrite(j, LOW);
        }
        delay(60);
      }
    }
    
    for (i = 800; i >= 200; i--)        //将频率从800HZ 减小到200HZ
    {       
      tone(tonepin,i);               //输出频率
      //根据频率亮不同的灯
      if(i <= 260) { digitalWrite(LED1, HIGH); }
      else if(i <= 320) { digitalWrite(LED2, HIGH); }
      else if(i <= 380) { digitalWrite(LED3, HIGH); }
      else if(i <= 440) { digitalWrite(LED4, HIGH); }
      else if(i <= 500) { digitalWrite(LED5, HIGH); }
      else if(i <= 560) { digitalWrite(LED5, HIGH); }
      else if(i <= 620) { digitalWrite(LED4, HIGH); }
      else if(i <= 680) { digitalWrite(LED3, HIGH); }
      else if(i <= 740) { digitalWrite(LED2, HIGH); }
      else { digitalWrite(LED1, HIGH); }
      delay(10);                    //该频率维持10毫秒 
      //根据频率关闭不同的灯
      if(i <= 260) { digitalWrite(LED1, LOW); }
      else if(i <= 320) { digitalWrite(LED2, LOW); }
      else if(i <= 380) { digitalWrite(LED3, LOW); }
      else if(i <= 440) { digitalWrite(LED4, LOW); }
      else if(i <= 500) { digitalWrite(LED5, LOW); }
      else if(i <= 560) { digitalWrite(LED5, LOW); }
      else if(i <= 620) { digitalWrite(LED4, LOW); }
      else if(i <= 680) { digitalWrite(LED3, LOW); }
      else if(i <= 740) { digitalWrite(LED2, LOW); }
      else { digitalWrite(LED1, LOW); }
    }
    noTone(tonepin);
  }
  
  //低高低电平发一个短时间脉冲去TrigPin 
  digitalWrite(TrigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW); 
  
  cm = pulseIn(EchoPin, !(LOW)) / 58.0; //将回波时间换算成cm 
  cm = (int(cm * 100.0)) / 100.0; //保留两位小数 
  
  delay(1000); 
}
