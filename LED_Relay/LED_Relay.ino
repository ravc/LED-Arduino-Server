int Red = 4;
int Blue = 5;
int Green = 6;
int Power = 7;
int incomingByte = 0;

void On_Off(){
  digitalWrite(Power, !digitalRead(Power));
}
void Red_LED(){
  digitalWrite(Red, !digitalRead(Red));
}
void Blue_LED(){
  digitalWrite(Blue, !digitalRead(Blue));
}
void Green_LED(){
  digitalWrite(Green, !digitalRead(Green));
}

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Power, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    
    if(incomingByte == 'R'){
      Red_LED();
    }else if(incomingByte == 'B'){
      Blue_LED();
    }else if(incomingByte == 'G'){
      Green_LED();
    }else if(incomingByte == 'O'){
      On_Off();
    }else if(incomingByte == 'S'){
      Serial.println(digitalRead(Power));
      Serial.println(digitalRead(Red));
      Serial.println(digitalRead(Blue));
      Serial.println(digitalRead(Green));
      Serial.println("end");
    }
  }

}
