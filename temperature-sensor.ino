int sensorTemp = A0;
int ledHot = 13;
int ledCold = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledHot, OUTPUT);
  pinMode(ledCold, OUTPUT);
}

void loop() {
  float temp = currentTemp();

  if(temp >= 35)
  {
    Serial.println("TOO HOT");
    ledRun(ledHot, 50);
  } else if(temp >= 27 && temp < 35)
  {
    Serial.println("HOT");
    ledRun(ledHot, 500);
  } else if(temp >= 22 && temp < 27)
  {
    Serial.println("AVERAGE");
    ledRunParallel(ledHot, ledCold, 500);
    
  } else if(temp >= 10 && temp < 22)
  {
    Serial.println("COLD");
    ledRun(ledCold, 500);
  } else
  {
    Serial.println("TOO COLD");
    ledRun(ledCold, 50);
  }

  Serial.println(temp);
  
}

float currentTemp() {
  int reading = analogRead(sensorTemp);
  float voltage = reading*5.0/1024.0;
  return voltage*100.0;
}

void ledRun(int pin, int number)
{
  digitalWrite(pin, HIGH);
  delay(number);
  digitalWrite(pin, LOW);
  delay(number);
}

void ledRunParallel(int pin1, int pin2, int number){
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  delay(number);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  delay(number);
}

