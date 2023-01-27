int IN4 = 2;
int IN3 = 3;
int IN2 = 4;
int IN1 = 5;
int speedA = 9;
int speedB = 10;

int midIR = 7;
int leftIR = 6;
int rightIR = 8;
int rightmidIR = 11;
int leftmidIR = 12;
int goti = 70;


void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(speedA,OUTPUT);
  pinMode(speedB,OUTPUT);
  pinMode(midIR,INPUT);
  pinMode(rightIR,INPUT);
  pinMode(leftIR,INPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  while(digitalRead(midIR)){
    forward();
    while(digitalRead(leftmidIR)){
      bitleft();
      while(digitalRead(leftIR)){
        bitmoreleft(); 
      }
    }
    while(digitalRead(rightmidIR)){
      bitright();
      while(digitalRead(rightIR)){
        bitmoreright();
      }
    }
  }
  while(digitalRead(leftmidIR)){
      bitleft();
      while(digitalRead(leftIR)){
        bitmoreleft(); 
      }
  }
  while(digitalRead(rightmidIR)){
      bitright();
      while(digitalRead(rightIR)){
        bitmoreright();
      }
  }
  while(digitalRead(leftIR)){
    bitmoreleft(); 
  }
  while(digitalRead(rightIR)){
    bitmoreright();
  }
} 

void forward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(speedA,goti);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(speedB,goti);
}
void backward(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(speedA,goti);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(speedB,goti);
}
void bitmoreright(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(speedA,goti);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(speedB,120);
}
void bitmoreleft(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(speedA,120);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(speedB,goti);
}
void stopp(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void bitleft(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(speedA,90);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(speedB,goti);
}
void bitright(){
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
  analogWrite(speedA,goti);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(speedB,90);
}
