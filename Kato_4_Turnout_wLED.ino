int led_turn1=12; //switch 1 turn LED
int led_str1=13; //switch 1 str LED
int led_turn2=10; //switch 2 turn LED
int led_str2=11; //switch 2 str LED
int led_turn3=A0; //switch 1 turn LED
int led_str3=A1; //switch 1 str LED
int led_turn4=A2; //switch 2 turn LED
int led_str4=A3; //switch 2 str LED
// first set of switches
const int switch1pin1=2;//set up digital pin 2 for controlling switch 1
const int switch1pin2=3;//set up digital pin 3 for controlling switch 1
const int switch2pin1=4;//set up digital pin 4 for controlling switch 2
const int switch2pin2=5;//set up digital pin 5 for controlling switch 2
const int button1=A7;//set up analog pin A0 for reading button 1
const int button2=A6;//set up analog pin A1 for reading button 2
// second set of swtiches
const int switch3pin1=6;//set up digital pin 6 for controlling switch 3
const int switch3pin2=7;//set up digital pin 7 for controlling switch 3
const int switch4pin1=8;//set up digital pin 8 for controlling switch 4
const int switch4pin2=9;//set up digital pin 9 for controlling switch 4
const int button3=A5;//set up analog pin A2 for reading button 3
const int button4=A4;//set up analog pin A3 for reading button 4
int State1=0;//Sets our value for the state of switch 1
int State2=0;//Sets our value for the state of swtich 2
int State3=0;//Sets our value for the state of switch 3
int State4=0;//Sets our value for the state of swtich 4

void setup() {
  Serial.begin(9600);//sets up our readings in the serial monitor and the baud rate of 9600
  pinMode(switch1pin1,OUTPUT);
  pinMode(switch1pin2,OUTPUT);
  pinMode(switch2pin1,OUTPUT);
  pinMode(switch2pin2,OUTPUT);
  pinMode(switch3pin1,OUTPUT);
  pinMode(switch3pin2,OUTPUT);
  pinMode(switch4pin1,OUTPUT);
  pinMode(switch4pin2,OUTPUT);
  //
  pinMode(led_turn1, OUTPUT);
  pinMode(led_str1, OUTPUT); 
  pinMode(led_turn2, OUTPUT);
  pinMode(led_str2, OUTPUT);
  pinMode(led_turn3, OUTPUT);
  pinMode(led_str3, OUTPUT);
  pinMode(led_turn4, OUTPUT);
  pinMode(led_str4, OUTPUT);
  //This sets up our digital pins as outputs
}
enum SWITCHSTATES
{
  ST_OFF,
  ST_STRAIGHT1,
  ST_TURN1,
  ST_STRAIGHT2,
  ST_TURN2,
  ST_STRAIGHT3,
  ST_TURN3,
  ST_STRAIGHT4,
  ST_TURN4,
};//Sets up states that arduino can hop between

SWITCHSTATES switchState=ST_OFF;


void loop(){
  Serial.println("State 1");
  Serial.println(State1);//display in serial monitor what the State of State 1 is with the text "State 1" in front.
  Serial.println("State 2");
  Serial.println(State2);//display in serial monitor what the State of State 2 is with the text "State 2" in front.

int Button1Read=analogRead(button1);//Stores value for button1
int Button2Read=analogRead(button2);//Stores value for button2
int Button3Read=analogRead(button3);//Stores value for button3
int Button4Read=analogRead(button4);//Stores value for button4
  Serial.println("Button 1");
  Serial.println(Button1Read);//display in serial monitor what the State of Button 1 is with the text "Button 1" in front.
  Serial.println("Button 2");
  Serial.println(Button2Read);//display in serial monitor what the State of Button 2 is with the text "Button 2" in front.
  Serial.println("Button 3");
  Serial.println(Button3Read);//display in serial monitor what the State of Button 3 is with the text "Button 3" in front.
  Serial.println("Button 4");
  Serial.println(Button4Read);//display in serial monitor what the State of Button 4 is with the text "Button 4" in front.
  delay(200);// 0.2 second pause between readings
  switch(switchState)
  {
    case ST_OFF:
    switchoff(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_STRAIGHT1:
    switchstraight1(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_TURN1:
    switchturn1(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_STRAIGHT2:
    switchstraight2(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_TURN2:
    switchturn2(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_STRAIGHT3:
    switchstraight3(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_TURN3:
    switchturn3(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_STRAIGHT4:
    switchstraight4(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
    case ST_TURN4:
    switchturn4(Button1Read, Button2Read, Button3Read, Button4Read);
    break;
  }
}

void switchoff(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,LOW);//keeps all of our turnouts powered off

  if ((Button1Read>500) && (State1==1)){
    switchState=ST_STRAIGHT1;//sends to straight 1 with button press
  }
  if ((Button1Read>500) && (State1==0)){
    switchState=ST_TURN1;//sends to turn 1 with button press
  }
  if ((Button2Read>500) && (State2==1)){
    switchState=ST_STRAIGHT2;//sends to straight 2 with button press
  }
  if ((Button2Read>500) && (State2==0)){
    switchState=ST_TURN2;//sends to turn 2 with button press
  }
    if ((Button3Read>500) && (State3==1)){
    switchState=ST_STRAIGHT3;//sends to straight 3 with button press
  }
  if ((Button3Read>500) && (State3==0)){
    switchState=ST_TURN3;//sends to turn 3 with button press
  }
    if ((Button4Read>500) && (State4==1)){
    switchState=ST_STRAIGHT4;//sends to straight 4 with button press
  }
  if ((Button4Read>500) && (State4==0)){
    switchState=ST_TURN4;//sends to turn 4 with button press
  }
}

void switchstraight1(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,HIGH);//powers on turnout
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,LOW);
  digitalWrite(led_turn1, LOW);//Turn off led 1
  digitalWrite(led_str1, HIGH);//Turn on led 1
  delay(500);//keep power to the turnout for 0.5 seconds
  State1=0;//sets value to 0
  switchState=ST_OFF;//sends program back to off
}

void switchturn1(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,HIGH);//powers on turnout
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,LOW);
  digitalWrite(led_turn1, HIGH);//Turn on led 1
  digitalWrite(led_str1, LOW);//Turn off led 1
  delay(500);//keep power to the turnout for 0.5 seconds
  State1=1;//sets value to 1
  switchState=ST_OFF;//sends program back to off
}

void switchstraight2(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,HIGH);//powers on turnout
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,LOW);
  digitalWrite(led_turn2, LOW);//Turn off led 2
  digitalWrite(led_str2, HIGH);//Turn on led 2
  delay(500);//keep power to the turnout for 0.5 seconds
  State2=0;//sets value to 0
  switchState=ST_OFF;//sends program back to off
}

void switchturn2(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,HIGH);//powers on turnout
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,LOW);
  digitalWrite(led_turn2, HIGH);//Turn on led 2
  digitalWrite(led_str2, LOW);//Turn off led 2
  delay(500);//keep power to the turnout for 0.5 seconds
  State2=1;//sets value to 1
  switchState=ST_OFF;//sends program back to off
}

void switchstraight3(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,HIGH);//powers on turnout
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,LOW);
  digitalWrite(led_turn3, LOW);//Turn off led 3
  digitalWrite(led_str3, HIGH);//Turn on led 3
  delay(500);//keep power to the turnout for 0.5 seconds
  State3=0;//sets value to 0
  switchState=ST_OFF;//sends program back to off
}

void switchturn3(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,HIGH);//powers on turnout
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,LOW);
  digitalWrite(led_turn3, HIGH);//Turn on led 3
  digitalWrite(led_str3, LOW);//Turn off led 3
  delay(500);//keep power to the turnout for 0.5 seconds
  State3=1;//sets value to 1
  switchState=ST_OFF;//sends program back to off
}
void switchstraight4(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,HIGH);//powers on turnout
  digitalWrite(switch4pin2,LOW);
  digitalWrite(led_turn4, LOW);//Turn off led 4
  digitalWrite(led_str4, HIGH);//Turn on led 4
  delay(500);//keep power to the turnout for 0.5 seconds
  State4=0;//sets value to 0
  switchState=ST_OFF;//sends program back to off
}

void switchturn4(int Button1Read, int Button2Read, int Button3Read, int Button4Read){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
  digitalWrite(switch2pin1,LOW);
  digitalWrite(switch2pin2,LOW);
  digitalWrite(switch3pin1,LOW);
  digitalWrite(switch3pin2,LOW);
  digitalWrite(switch4pin1,LOW);
  digitalWrite(switch4pin2,HIGH);//powers on turnout  
  digitalWrite(led_turn4, HIGH);//Turn on led 4
  digitalWrite(led_str4, LOW);//Turn off led 4
  delay(500);//keep power to the turnout for 0.5 seconds
  State4=1;//sets value to 1
  switchState=ST_OFF;//sends program back to off
}
