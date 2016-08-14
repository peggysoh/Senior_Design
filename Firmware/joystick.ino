//A0(15) = green, A1(16) = yellow, A2(17) = orange, A3(18) = red
#define downPin 15
#define upPin 16
#define rightPin 17
#define leftPin 18
int X = 0;
int Y = 0;
int PrevX = X;
int PrevY = Y;
 
void setup() {
  Serial.begin(9600);
  
  //Joystick setup
  pinMode(downPin, INPUT);
  digitalWrite(downPin, HIGH);
  pinMode(upPin, INPUT);
  digitalWrite(upPin, HIGH);
  pinMode(rightPin, INPUT);
  digitalWrite(rightPin, HIGH);
  pinMode(leftPin, INPUT);
  digitalWrite(leftPin, HIGH);
}

void loop() {
  joystick( &X, &Y );
  if (X != 0 && (X != PrevX || Y != PrevY)){
    result(X,Y);
  }
  else if (Y != 0 && (X != PrevX || Y != PrevY)) {
    result(X,Y);
  }
  delay(300);
}

// [-1, 0, 1] map to [left/down, none, right/top]
void joystick(int* X, int* Y){

  //HIGH = non-trigger
  if( !digitalRead( leftPin ) ){
    *X = -1;
  }else if( !digitalRead( rightPin ) ){
    *X = 1;
  }else{
    *X = 0;
  }

  if( !digitalRead( upPin ) ){
    *Y = 1;
  }else if( !digitalRead( downPin ) ){
    *Y = -1;
  }else{
    *Y = 0;
  }

}

void result(int X, int Y ) {
    if (X == 1){
      Serial.print("Right\t");
    }
    else if (X == -1) {
      Serial.print("Left\t");   
    }
    PrevX = X;
    if (Y == 1){
      Serial.print("Up\n");
    }
    else if (Y == -1) {
      Serial.print("Down\n");
    }
    else{
      Serial.print("\n");
    }          
    PrevY = Y;
}
