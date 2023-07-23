int led1=4;
int led2=3;
int led3=2;
int INP3=10;
int INP4=9;
int ENB=6;
int x=0;
int y=1;
int SW_pin=2;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(INP3,OUTPUT);
  pinMode(INP4,OUTPUT);
  pinMode(SW_pin,INPUT);
  pinMode(ENB,OUTPUT);
  digitalWrite(SW_pin,HIGH);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(led3,HIGH);
      digitalWrite(led1,HIGH);
       digitalWrite(led2,LOW);
       
      delay(2000);
       digitalWrite(led1,LOW);
       digitalWrite(led3,LOW);
      digitalWrite(led2,LOW);
      delay(500);
        digitalWrite(led3,LOW);
      digitalWrite(led2,HIGH);
      digitalWrite(led1,HIGH);
      motor_control();
      delay(2500);
    
}
void motor_control(){
  if(digitalRead(led2)==1){
    Serial.print(analogRead(y));
   if(analogRead(y)>700){


        digitalWrite(INP3,HIGH);
        digitalWrite(INP4,LOW);
        analogWrite(ENB,analogRead(y)/4);
       delay(200);
      }  
      if(analogRead(y)<250){

        digitalWrite(INP3,LOW);
        digitalWrite(INP4,HIGH);

    analogWrite(ENB,250-(analogRead(y)/3));
      delay(200);
      }
    }
     else  digitalWrite(ENB,LOW);
}
