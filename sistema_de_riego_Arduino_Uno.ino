#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  
int bomba = 9;

void setup() {
  lcd.init();                // Inicializa la pantalla LCD
  lcd.backlight();           
  Serial.begin(9600);
  pinMode(bomba, OUTPUT);
  digitalWrite(bomba, HIGH); // Bomba apagada al inicio
}

void loop() {
  int lectura = analogRead(A0);
  int humedad = map(lectura, 800, 300, 0, 100);  

 
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println("%");

  // Mostrar en LCD
  lcd.setCursor(0, 0);
  lcd.print("Humedad:      ");  
  lcd.setCursor(9, 0);
  lcd.print(humedad);
  lcd.print("% ");

  // Control de la bomba
  if (humedad <= 30) {
    digitalWrite(bomba, LOW);   // Enciende la bomba
  } else {
    digitalWrite(bomba, HIGH);  // Apaga la bomba
  }

  delay(1000);  
}
