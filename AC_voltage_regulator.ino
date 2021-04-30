int transformer_voltage = 0;
int dummy = 0;

const int high_delay = 6000, low_delay = 1150;
const int T1 = 2, T2 = 3, T3 = 4, T4 = 5;

void setup() {
  Serial.begin(250000);
  pinMode(7, INPUT_PULLUP);
  
  //pinMode(T1, OUTPUT);
  pinMode(T2, OUTPUT);
  pinMode(T3, OUTPUT);
  //pinMode(T4, OUTPUT);
}

void loop() {
    transformer_voltage = digitalRead(7);
    //Serial.println(transformer_voltage);
    zerocross(); 
}

void zerocross()
{
  if(transformer_voltage == 0 && dummy == 0)
    {
      //Rising Edge......
      delayMicroseconds(3000);
      digitalWrite(T2, HIGH);
      delayMicroseconds(5000);
      digitalWrite(T2, LOW);
      delayMicroseconds(1500);


      delayMicroseconds(3500);
      digitalWrite(T3, HIGH);
      delayMicroseconds(5000);
      digitalWrite(T3, LOW);
      delayMicroseconds(1500);
      
      dummy = 1;
    }
    
    if(transformer_voltage == 1 && dummy == 1)
    {
     //Falling Edge......
      dummy = 0;
    }
}

