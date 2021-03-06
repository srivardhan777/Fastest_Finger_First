#define user1 A1 //the number of the button 1
#define user2 A2 //button2
#define user3 A3 //button3
#define user4 A4 //button4
#define reset A5 //button5(Reset Button)
// #define buzzerPin 10 //the buzzer attach to
//LEDs defined for seven segment display
#define ledA 2
#define ledB 3
#define ledC 4
#define ledD 5
#define ledE 6
#define ledF 8
#define ledG 9
//#define LEDreset 7 //LED attach to(Showing reset functioning)

char flag = 0; //used to indicate the state of button5(i.e. reset button)
char b1State,b2State,b3State,b4State,b5State = 0;

void setup()
{
  //initialize buzzer,LED1, LED2, LED3 and LED4 as output
  //pinMode(buzzerPin, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  //pinMode(LEDreset,OUTPUT);
  //initialize button1,button2,button3,button as input,combined with pullup
  pinMode(user1, INPUT_PULLUP);
  pinMode(user2, INPUT_PULLUP);
  pinMode(user3, INPUT_PULLUP);
  pinMode(user4,INPUT_PULLUP);
  pinMode(reset, INPUT_PULLUP);
  //turn all the led off
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, LOW);
  //digitalWrite(LEDreset,LOW);
  Serial.begin(9600);
} 
void loop()
{
  //turn all the led off
  digitalWrite(ledA, LOW);
  digitalWrite(ledB,LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD,LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, HIGH);
  //digitalWrite(LEDreset,LOW);
  //read the state of the button5 (reset button)
  b5State = digitalRead(reset);
  if(b5State == 0)
  {
    if(b5State == 0) //confirm that the button5(reset button pressed) is pressed
    {
      flag = 1; //if so,flag is 1
      // digitalWrite(LEDreset, HIGH); //turn the host LED on
      Serial.print("0");
      delay(200);
    }
  }
  if(1 == flag)
  {
    //read the state of the button of buttons
    b1State = digitalRead(user1);
    b2State = digitalRead(user2);
    b3State = digitalRead(user3);
    b4State = digitalRead(user4);
    //If the button1 press the first
    if(b1State == 0)
    {
      Serial.println(" User 1 is the Winner !!!");
      flag = 0;
      digitalWrite(ledA, HIGH);
      Alarm(); //buzzer sound
      digitalWrite(ledB,LOW);
      digitalWrite(ledC,LOW);
      digitalWrite(ledD,HIGH);
      digitalWrite(ledE,HIGH);
      digitalWrite(ledF,HIGH);
      digitalWrite(ledG,HIGH);
      while(digitalRead(reset)); //detect the button4,if pressed,out of the while loop
    }
    //If the button2 press the first
    if(b2State == 0)
    {
      Serial.println(" User 2 is the Winner !!!");
      flag = 0;
      digitalWrite(ledA, LOW);
      Alarm(); //buzzer sound
      digitalWrite(ledB,LOW);
      digitalWrite(ledC,HIGH);
      digitalWrite(ledD,LOW);
      digitalWrite(ledE,LOW);
      digitalWrite(ledF,HIGH);
      digitalWrite(ledG,LOW);
      while(digitalRead(reset));
    }
    //If the button3 press the first
    if(b3State == 0)
    {
      Serial.println("User 3 is the Winner !!!");
      flag = 0;
      digitalWrite(ledA, LOW);
      Alarm(); //buzzer sound
      digitalWrite(ledB,LOW);
      digitalWrite(ledC,LOW);
      digitalWrite(ledD,LOW);
      digitalWrite(ledE,HIGH);
      digitalWrite(ledF,HIGH);
      digitalWrite(ledG,LOW);
      while(digitalRead(reset));
    }
    if(b4State == 0)
    {
      Serial.println("User 4 is the Winner !!!");
      flag = 0;
      digitalWrite(ledA, HIGH);
      Alarm(); //buzzer sound
      digitalWrite(ledB,LOW);
      digitalWrite(ledC,LOW);
      digitalWrite(ledD,HIGH);
      digitalWrite(ledE,HIGH);
      digitalWrite(ledF,LOW);
      digitalWrite(ledG,LOW);
      while(digitalRead(reset));
    }
  }
}
//buzzer sound
void Alarm()
{
  for(int i=0;i<100;i++)
  {
    // digitalWrite(buzzerPin,HIGH); //the buzzer sound
    delay(2);
    // digitalWrite(buzzerPin,LOW); //without sound
    delay(2); //when delay time changed,the frequency changed
  }
}
