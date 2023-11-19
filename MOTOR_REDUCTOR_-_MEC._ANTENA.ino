const int MOTOR_PIN = 3;  // Pin PWM válido para Arduino Uno
const int BUTTON_PIN = 2; // Pin al que conectas el botón

int velocidad = 80;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Habilita la resistencia de pull-up interna para el botón
  Serial.begin(9600);
}

void loop() {
  // Verificar si el botón NO está presionado
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Botón no presionado, encender el motor con velocidad inicial durante el primer segundo
    analogWrite(MOTOR_PIN, 190);
    delay(1000); // Mantener velocidad inicial durante el primer segundo

    // Mantener velocidad normal mientras el botón NO esté presionado
    while (digitalRead(BUTTON_PIN) == HIGH) {
      analogWrite(MOTOR_PIN, velocidad);
    }

    // Botón presionado, detener el motor y esperar a que se suelte completamente el botón
    detenerMotor();
  }
}

void detenerMotor() {
  analogWrite(MOTOR_PIN, 0);  // Detener el motor
  Serial.println("Motor detenido");
  while (digitalRead(BUTTON_PIN) == HIGH) {
    // Esperar hasta que se suelte el botón
    delay(50);
  }
  Serial.println("Botón suelto");
}


