# 蜂鸣器报警+LED灯光实验
## 内容说明：
使用超声波测距模块、有源蜂鸣器、led灯等，与 UNO 实验套装组成一个感应距离触发报警的小工具。因 led 灯需要的电流很小，所以要每个 led 都要串联一个限流电阻，以达到降低电流的作用。

> 限流电阻计算公式：
>  </br>
>  R=（E－U）/ I
>  </br>
> 式中E为电源电压，U为LED的正向降压，I为LED的一般工作电流，红色发光二极管的工作电压一般为1.5V～2.0V，其工作电流一般为10mA～20mA，所以在5v的数字逻辑电路中，一般使用220Ω电阻作为限流电阻。

### 实验元件：

>  - UNO 实验套装（UNO R3控制板、USB数据线、面包板、跳线）
>  - 有源蜂鸣器（MH-FMD 低电平触发）
>  - 超声波测距模块（HC-SR04）
>  - 6 个 led 灯
>  - 电阻（220 欧，6 个）
## 元件介绍：
##### 有源蜂鸣器：

有源蜂鸣器是一种一体化结构的电子讯响器，采用直流电压供电，广泛应用于计算机、打印机、复印机、报警器、电子玩具、汽车电子设备、电话机、定时器等电子产品中作发声器件。蜂鸣器主要分为压电式蜂鸣器和电磁式蜂鸣器两种类型。蜂鸣器在电路中用字母 “H” 或 “HA”（旧标准用 “FM”、“LB”、“JD” 等）表示。 超声波

#### 超声波测距模块
超声波测距模块是用来测量距离的一种产品，通过发送和收超声波，利用时间差和声音传播速度，计算出模块到前方障碍物的距离。

## 电路图
（手残原因，无法画出平面电路图，请见谅。）
 <img src="https://img-blog.csdnimg.cn/2019061421364540.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzMTUzNDE4" width="50%">
 

 1. LED灯对应的引脚分别为：8、9、10、11、12，每个led灯的负极（短边）串联一个电阻后连接到面包板的负极区，然后连接到GNC口。正极（长边）则连接到相应的引脚处。
    
 2. 超声波测距模块必须连接到 5V，若连接到 3V会运作不正常。TrigPin 引脚为 A2，EchoPin 引脚为 A3。

 3. 蜂鸣器引脚为 6。

## 控制板代码

    int i;                            //定义变量i
    int tonepin=6;                    //定义蜂鸣器引脚
    
    /*
      定义led灯引脚
     */
    int LED1=8;
    int LED2=9;
    int LED3=10;
    int LED4=11;
    int LED5=12;
    int n;
    
    /*
      定义超声波引脚
     */
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
      //判断超声波检测到的距离是否小于10cm。
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

## 实验结果视频
[Arduino—超声波测距、有源蜂鸣器和led灯的搭配使用](https://v.youku.com/v_show/id_XNDIyODMyMjI2MA==.html?spm=a2h3j.8428770.3416059.1)

> 元件介绍来自于百度百科（若想了解详情，请点击下方连接）：
> 蜂鸣器：https://baike.baidu.com/item/%E6%9C%89%E6%BA%90%E8%9C%82%E9%B8%A3%E5%99%A8/10017869?fr=aladdin
> 超声波测距模块：https://baike.baidu.com/item/%E8%B6%85%E5%A3%B0%E6%B3%A2%E6%B5%8B%E8%B7%9D%E6%A8%A1%E5%9D%97/1118715?fr=aladdin

> 本文内容为本人学习操作 Arduino 开发板时的总结，若有错误之处，请多多包涵。
