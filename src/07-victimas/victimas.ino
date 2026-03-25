// ============================================================
// RobotRescue — Operación Zona Cero
// 07: Clasificación y Empuje de Víctimas
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc en docs/07-victimas.md
// 2. Completa las secciones marcadas con TODO
// 3. Prueba medirDistancia() primero antes de integrar todo
// ============================================================

#include <Wire.h>
#include <Adafruit_TCS34725.h>

// --- Pines sensor ultrasónico HC-SR04 ---
const int PIN_TRIG = 9;
const int PIN_ECHO = 10;

// --- Pines motores (igual que fases anteriores) ---
const int PIN_MOT_IZQ_EN  = 5;
const int PIN_MOT_IZQ_IN1 = 4;
const int PIN_MOT_IZQ_IN2 = 3;
const int PIN_MOT_DER_EN  = 6;
const int PIN_MOT_DER_IN1 = 7;
const int PIN_MOT_DER_IN2 = 8;

// --- Sensor de color ---
Adafruit_TCS34725 sensorColor = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X
);

// --- Configuración ---
const int VELOCIDAD     = 150;
const int DIST_VICTIMA  = 10;  // cm — ajusta según tus pruebas

// ============================================================
void setup() {
  Serial.begin(9600);
  Serial.println("RobotRescue - Fase 7: Clasificación de víctimas iniciada");

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(PIN_MOT_IZQ_EN,  OUTPUT);
  pinMode(PIN_MOT_IZQ_IN1, OUTPUT);
  pinMode(PIN_MOT_IZQ_IN2, OUTPUT);
  pinMode(PIN_MOT_DER_EN,  OUTPUT);
  pinMode(PIN_MOT_DER_IN1, OUTPUT);
  pinMode(PIN_MOT_DER_IN2, OUTPUT);

  sensorColor.begin();
}

// ============================================================
void loop() {
  float dist = medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist < DIST_VICTIMA) {
    String tipoPelota = detectarColorPelota();
    Serial.print("Víctima detectada: ");
    Serial.println(tipoPelota);

    // TODO: según el tipo de pelota, llama a la función de empuje correspondiente
  }

  delay(100);
}

// ============================================================
// FUNCIÓN COMPLETA (úsala como referencia)
// ============================================================

// Mide la distancia en cm usando el sensor ultrasónico HC-SR04
float medirDistancia() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long duracion = pulseIn(PIN_ECHO, HIGH);
  float distancia = duracion / 58.0;
  return distancia;
}

// ============================================================
// FUNCIONES CON TODO — COMPLETA EL CUERPO
// ============================================================

// Devuelve "BLANCO" si la pelota es blanca (viva) o "NEGRO" si es negra (muerta)
// Pista: usa el sensor de color — una pelota blanca refleja mucho en todos los canales,
//        una pelota negra absorbe la luz (valores bajos en todos los canales)
String detectarColorPelota() {
  // TODO: implementa esta función
  return "DESCONOCIDO";
}

// Empuja la víctima blanca completamente hacia la zona AZUL
// La pelota debe quedar dentro de la zona sin contacto con el robot al terminar
void empujarAZonaAzul() {
  Serial.println("Empujando víctima blanca a zona AZUL...");
  // TODO: implementa la secuencia de movimiento para llevar la pelota a la zona azul
}

// Empuja la víctima negra completamente hacia la zona AMARILLA
void empujarAZonaAmarilla() {
  Serial.println("Empujando víctima negra a zona AMARILLA...");
  // TODO: implementa la secuencia de movimiento para llevar la pelota a la zona amarilla
}
