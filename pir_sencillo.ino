
int sensor = 2;
int led = 13;
int next = 5;
 
  
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(next, OUTPUT);
  Serial.begin(9600);  
}
  
void loop()
{
  bool lectura = digitalRead(sensor);
  if (lectura == HIGH)
    {
      Serial.println(lectura);
      digitalWrite (led, HIGH);
    digitalWrite (next, LOW);
    Serial.println(led);
    Serial.println(next);
    delay (50);
    digitalWrite (next, HIGH);
    Serial.println(next);
    }
  else
    {
      Serial.println("FIN");
      digitalWrite (led, LOW);
      digitalWrite (next, HIGH);}
      Serial.println(led);
      Serial.println(next);
}
