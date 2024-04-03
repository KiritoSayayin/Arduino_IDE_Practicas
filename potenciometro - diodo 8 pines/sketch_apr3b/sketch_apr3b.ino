const int potPin = A0; // Pin de datos conectado al potenciómetro
const int LED_PINS[] = {0, 1, 2, 3, 4, 5, 6, 7}; // Esto es un arreglo de numeros enteros para pines conectados a los LEDs
const int NUM_LEDS = sizeof(LED_PINS) / sizeof(LED_PINS[0]); // Número de LEDs

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT); // Configura los pines de los LEDs como salida
  }
}

void loop() {
  double potValue = analogRead(potPin); // Lee el valor del potenciómetro (0-1023)
  double brightness = map(potValue, 0.0, 1023.0, 0.0, 255.0); // Mapea el valor a un rango de brillo (0-255)
  
  // Enciende cada LED gradualmente con un retraso escalonado
  for (int i = 0; i < NUM_LEDS; i++) {
    analogWrite(LED_PINS[i], brightness);
    delay(100); // Ajusta el tiempo de espera entre cada LED
  }
}
