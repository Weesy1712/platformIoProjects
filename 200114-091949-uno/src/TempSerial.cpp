#define led1 2 
#define led2 3
#define led3 4
#define tmp37 A0
float tmp; 
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
void setup() {
pinMode(led1, OUTPUT); 
pinMode(led2,OUTPUT); 
pinMode(led3,OUTPUT); 
pinMode(tmp37,INPUT); 
Serial.begin(9600);
 inputString.reserve(200); 
}

void loop() {
  tmp = (analogRead(tmp37) /4.1); 
   if (stringComplete) {
    Serial.println(inputString);
    if( inputString == "rt\n"){
      Serial.println("kek");
    Serial.println(tmp); 
    }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  
 
/* Serial.println("Temp:"); 
 Serial.print(tmp); 
 Serial.print(" C°");
 */
 if(tmp>=24.00){
  digitalWrite(led1, HIGH); 
 }else{
  digitalWrite(led1, LOW
  );
 }
 if(tmp>25.00 ){
  digitalWrite(led1, HIGH); 
   digitalWrite(led2, HIGH); 
 }else{
  digitalWrite(led2, LOW); 
 }
 if(tmp>26.00 ){
  digitalWrite(led1, HIGH); 
   digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
 }else{
   digitalWrite(led3, LOW);
 }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
