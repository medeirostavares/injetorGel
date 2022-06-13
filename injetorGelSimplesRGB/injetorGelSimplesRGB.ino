
int var;
//A0 = IR
int LED_R = 2;
int LED_G = 3;
int LED_B = 4;
int MOTOR = 6;
int BUZZ  = 7;

void setup() 
{
  pinMode(A0, INPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  piscaRed();
  initBuzz();
  digitalWrite(LED_B, HIGH);
    
  Serial.begin(115200);

}

void loop() 
{  
  
  injetor();  

}

void injetor()
{
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, HIGH);
  var = analogRead(A0);
  Serial.println(var);
  if(var<=1000)
  {
     //Serial.println("Detectado!"); 
     digitalWrite(LED_G, HIGH);
     digitalWrite(MOTOR, HIGH);
     delay(1000);
     digitalWrite(MOTOR, LOW);
     piscaGreen();
     digitalWrite(LED_G, LOW);
     //delay(2000);
  }
  else
  {
    //Serial.println("Não detectado...");
    digitalWrite(MOTOR, LOW);
    //digitalWrite(LED_R, HIGH);
    
  }
  delay(500);  
}

void piscaRed()
{
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
  
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

void piscaGreen()
{
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_B, LOW);
  
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_G, LOW);
  delay(100);
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_G, LOW);
  delay(100);  
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_G, LOW);
  delay(100);
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_G, LOW);
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
