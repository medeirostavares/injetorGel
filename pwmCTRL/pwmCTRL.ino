int PWM = 6;
int velocidade = 190;


void setup()
{
  pinMode(PWM,OUTPUT);
}
 
void loop()
{

    
    analogWrite(PWM,velocidade);
    //Serial.println("TESTE...");  
 
}
