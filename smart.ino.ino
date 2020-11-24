//핀번호 설정한다.
int echoPin = 12;
int trigPin = 13;
int echoPin2 = 7;
int trigPin2 = 8;
int vibe = 3;
int touch = 2;
int previous = LOW; 

void setup() {

  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
  pinMode(vibe, OUTPUT);
  pinMode(touch, INPUT);
}

void loop() {
  float duration, distance, duration2, distance2;
  int tvalue = digitalRead(touch);

  if (tvalue == LOW){ //터치 센서가 on인 상태
   
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH);

  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  distance = ((float)(340 * duration) / 10000) / 2;  
  distance2 = ((float)(340 * duration2) / 10000) / 2;
  
  Serial.print(distance);
  Serial.println("cm#1");
  Serial.print(distance2);
  Serial.println("cm#2");
  // 수정한 값을 출력
  delay(500);
  

  if (distance < 25) {
  analogWrite(3, 255); //진동세기 임의의 값
  delay(500);
  analogWrite(3, 0);
  
  }

  if (distance2 < 5) {
  analogWrite(3, 255); //
  delay(500);
  analogWrite(3, 0);
 
  
 
}
  
  }
else{
  digitalWrite(trigPin, HIGH);
  Serial.println("터치 안됨");
  delay(1000);
}
}
