#define pinLed_R D1
#define pinLed_G D3
#define pinLed_B D4
#define pinBtn D7

int lastVal;
unsigned long lastPress;
unsigned long duration;
unsigned long lastDuration;
#define pinBtn D7

int lastVal;
unsigned long lastPress;
unsigned long duration;
unsigned long lastDuration;

void game_setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(pinLed_R, OUTPUT);
  pinMode(pinLed_G, OUTPUT);
  pinMode(pinLed_B, OUTPUT);
  pinMode(pinBtn, INPUT_PULLUP);
  LedOFF();
  lastVal = HIGH;
  lastPress = millis();
  pinMode(pinBtn, INPUT_PULLUP);
  LedOFF();
  lastVal = HIGH;
  lastPress = millis();
}

void game_loop() {
  lastDuration = GetData();
  if(lastDuration <= 0) SendData(6000000);//במידה והשרת ריק
  
  if (digitalRead(pinBtn) == LOW && lastVal == HIGH && (millis() - lastPress > 50)) {
    lastPress = millis();
    lastVal = LOW;
    Serial.println("start press");
  }
  if (digitalRead(pinBtn) == HIGH && lastVal == LOW) {
    lastVal = HIGH;
    duration = millis() - lastPress;
    Serial.println("end press");
    Serial.print("Duration: ");
    Serial.println(duration);

    if (duration < lastDuration) {
      SendData(duration);
      LightLed(0x5DE2E7);
    } else {
      LightLed(0xFE9900);
    }
  }
}

void LightLed(long HexaColor) {
  int red = (HexaColor >> 16) & 0xFF;
  int green = (HexaColor >> 8) & 0xFF;
  int blue = HexaColor & 0xFF;


  analogWrite(pinLed_R, red);
  analogWrite(pinLed_G, green);
  analogWrite(pinLed_B, blue);
}

void LedOFF() {
  analogWrite(pinLed_R, 0);
  analogWrite(pinLed_G, 0);
  analogWrite(pinLed_B, 0);
}
