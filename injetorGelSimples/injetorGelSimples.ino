
int var;
//A0 = IR
int LED_R = 3;
int MOTOR = 4;
int BUZZ  = 5;

void setup() 
{
  pinMode(A0, INPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  piscaRed();
  initBuzz();
  digitalWrite(LED_R, HIGH);
    
  Serial.begin(115200);

}

void loop() 
{  
  
  injetor();  

}

void injetor()
{
  var = analogRead(A0);
  Serial.println(var);
  if(var<=1000)
  {
     //Serial.println("Detectado!"); 
     delay(500);
     digitalWrite(MOTOR, HIGH);
     delay(2500);
     digitalWrite(MOTOR, LOW);
     piscaRed();
     delay(2000);
  }
  else
  {
    //Serial.println("Não detectado...");
    digitalWrite(MOTOR, LOW);
    digitalWrite(LED_R, HIGH);
    
  }
}

void piscaRed()
{
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);  
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);  
}

void initBuzz()
{
  digitalWrite(BUZZ, HIGH);
  delay(100);
  digitalWrite(BUZZ, LOW);
  delay(100);
  digitalWrite(BUZZ, HIGH);
  delay(100);
  digitalWrite(BUZZ, LOW);
}
