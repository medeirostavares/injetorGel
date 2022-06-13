
int var;
int ligado = 150;
int desligado = 255;

unsigned long millisAtual;
long millisAnterior;
long millisIntervalo = 800;

int lerPresenca;

int PIR   = 2;
int LED_R = 3;
int LED_G = 4;
int LED_B = 5;
int PWM   = 6;
int BUZZ  = 7;

void setup() 
{
  analogWrite(PWM,desligado);
  pinMode(A0, INPUT);
  pinMode(PIR, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(PWM,OUTPUT);
  pinMode(BUZZ, OUTPUT);
  piscaRed();
  initBuzz();
    
  Serial.begin(115200);

}

void loop() 
{
  millisAtual = millis();
  if (millisAtual - millisAnterior > millisIntervalo) 
  {  
    presenca();
    millisAnterior = millisAtual;
  }  
  
  injetor();  

}

void presenca()
{
  lerPresenca = digitalRead(PIR);

   if (lerPresenca == LOW) 
   {
     digitalWrite(BUZZ, LOW);
   }
   
   else 
   {
      alarme();
   }
}

void injetor()
{
  var = analogRead(A0);
  //Serial.println(var);
  if(var<700)
  {
     Serial.println("Detectado!"); 
     digitalWrite(LED_B, LOW);
     digitalWrite(LED_G, HIGH);
     analogWrite(PWM,ligado);
     delay(340);
     analogWrite(PWM,desligado); 
     delay(2000);
  }
  else
  {
    Serial.println("Não detectado...");
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_G, LOW);
    analogWrite(PWM,desligado);
  }
  delay(500);  
}

void piscaRed()
{
  digitalWrite(LED_R, HIGH);
  delay(1000);
  digitalWrite(LED_R, LOW);
  delay(1000);
  digitalWrite(LED_R, HIGH);
  delay(1000);
  digitalWrite(LED_R, LOW);
  delay(1000);  
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

void alarme()
{
  digitalWrite(BUZZ, HIGH);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(BUZZ, LOW);
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(BUZZ, HIGH);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(BUZZ, LOW);
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(BUZZ, HIGH);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(BUZZ, LOW);
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(BUZZ, HIGH);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(BUZZ, LOW);
  digitalWrite(LED_R, LOW);
}
