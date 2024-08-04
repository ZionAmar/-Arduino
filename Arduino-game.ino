#define Switch_pin D2

bool IamServer;

void setup() {
  pinMode(Switch_pin, INPUT_PULLUP);
  IamServer = (digitalRead(Switch_pin) == LOW) ? true : false;
  if (IamServer)
    performance_setup();
  else
    game_setup();
}

void loop(){
    if (IamServer)
    performance_loop();
  else
    game_loop();
}

