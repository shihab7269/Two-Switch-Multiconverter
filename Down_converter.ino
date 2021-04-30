int transformer_voltage = 0;
int dummy = 0;
int number_Zero_cross = 0;

const int high_delay = 8000, low_delay = 1700;

void setup() {
  Serial.begin(250000);
  pinMode(7, INPUT_PULLUP);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
    transformer_voltage = digitalRead(7);
    //Serial.println(transformer_voltage);
    zerocross();
    Serial.println(number_Zero_cross);
    
}

void zerocross()
{
  if(transformer_voltage == 0 && dummy == 0)
    {
      //Rising     
      digitalWrite(3, HIGH);
      delayMicroseconds(high_delay);
      digitalWrite(3, LOW);
      delayMicroseconds(low_delay);
      digitalWrite(2, HIGH);
      delayMicroseconds(high_delay);
      digitalWrite(2, LOW);
      delayMicroseconds(low_delay);
      digitalWrite(3, HIGH);
      delayMicroseconds(high_delay);
      digitalWrite(3, LOW);
      delayMicroseconds(low_delay);
      
      digitalWrite(3, HIGH);
      delayMicroseconds(high_delay);
      digitalWrite(3, LOW);
      delayMicroseconds(low_delay);
      digitalWrite(2, HIGH);
      delayMicroseconds(high_delay);
      digitalWrite(2, LOW);
      delayMicroseconds(low_delay);
      digitalWrite(3, HIGH);
      delayMicroseconds(high_delay);
      digitalWrite(3, LOW);
      delayMicroseconds(low_delay);
      
      
      dummy = 1;
    }
    
    if(transformer_voltage == 1 && dummy == 1)
    {
     //Falling
      dummy = 0;
    }

}


