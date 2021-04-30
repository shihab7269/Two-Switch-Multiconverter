int transformer_voltage = 0;
int dummy = 0;

const int T1 = 2, T2 = 3, T3 = 4, T4 = 5;

void setup() {
  Serial.begin(250000);
  pinMode(7, INPUT_PULLUP);
  
  pinMode(T1, OUTPUT);
  pinMode(T2, OUTPUT);

}

void loop() {
    transformer_voltage = digitalRead(7);
    zerocross(); 
}

void zerocross()
{
  if(transformer_voltage == 0 && dummy == 0)
    {
      //Rising Edge......
      digitalWrite(T1, HIGH);
      delayMicroseconds(5000);
      digitalWrite(T1, LOW);
      delayMicroseconds(100);
      digitalWrite(T2, HIGH);
      delayMicroseconds(4700);
      digitalWrite(T2, LOW);
      delayMicroseconds(100);

      
      dummy = 1;
    }
    
    if(transformer_voltage == 1 && dummy == 1)
    {
     //Falling Edge......
     digitalWrite(T1, HIGH);
      delayMicroseconds(4800);
      digitalWrite(T1, LOW);
      delayMicroseconds(100);
      digitalWrite(T2, HIGH);
      delayMicroseconds(4700);
      digitalWrite(T2, LOW);
      delayMicroseconds(100);
      dummy = 0;
    }
}



