#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int led =13;
int btn=7;
static int led_state,prev_btn_data;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);

}

void loop() {
  int btn_data=digitalRead(btn);
  if(btn_data==LOW &&btn_data!=prev_btn_data)
  {
    led_state=!led_state;
  }
  digitalWrite(led,led_state);
  lcd.setCursor(0,0);
  lcd.print("LED STATE: ");
  lcd.print(led_state);
  prev_btn_data=btn_data;

}
