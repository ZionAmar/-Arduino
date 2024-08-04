#define pinLed_R D1
#define pinLed_G D3
#define pinLed_B D4

void game_setup() {
  pinMode(pinLed_R, OUTPUT);
  pinMode(pinLed_G, OUTPUT);
  pinMode(pinLed_B, OUTPUT);
}

void game_loop() {
  LightLed(0x5DE2E7);
  delay(3000);
  LightLed(0xFE9900);
  delay(3000);
}

void LightLed(long HexaColor) {
  // HexaColor - RRGGBB
  int red = (HexaColor >> 16) & 0xFF;
  int green = (HexaColor >> 8) & 0xFF;
  int blue = HexaColor & 0xFF;
  
  analogWrite(pinLed_R, red);
  analogWrite(pinLed_G, green);
  analogWrite(pinLed_B, blue);
}