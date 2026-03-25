// ============================================================
// RobotRescue — Operación Zona Cero
// 04: Programación Básica de Movimiento
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc en docs/04-movimiento.md
// 2. Completa las secciones marcadas con TODO
// 3. Prueba cada función por separado antes de continuar
// ============================================================

// --- Pines del driver de motores ---
// Motor izquierdo
const int PIN_MOT_IZQ_EN  = 5;   // Enable (PWM velocidad)
const int PIN_MOT_IZQ_IN1 = 4;   // Dirección 1
const int PIN_MOT_IZQ_IN2 = 3;   // Dirección 2

// Motor derecho
const int PIN_MOT_DER_EN  = 6;   // Enable (PWM velocidad)
const int PIN_MOT_DER_IN1 = 7;   // Dirección 1
const int PIN_MOT_DER_IN2 = 8;   // Dirección 2

// --- Configuración de velocidad ---
const int VELOCIDAD = 180;        // 0–255; ajusta hasta que el movimiento sea controlado

// ============================================================
void setup() {
  Serial.begin(9600);
  Serial.println("RobotRescue - Fase 4: Movimiento iniciado");

  pinMode(PIN_MOT_IZQ_EN,  OUTPUT);
  pinMode(PIN_MOT_IZQ_IN1, OUTPUT);
  pinMode(PIN_MOT_IZQ_IN2, OUTPUT);
  pinMode(PIN_MOT_DER_EN,  OUTPUT);
  pinMode(PIN_MOT_DER_IN1, OUTPUT);
  pinMode(PIN_MOT_DER_IN2, OUTPUT);
}

// ============================================================
void loop() {
  Serial.println("Avanzando...");
  adelante();
  delay(1000);

  Serial.println("Parando...");
  parar();
  delay(500);

  // TODO: Llama a las demás funciones de movimiento aquí
  // (atras, izquierda, derecha) con delay entre cada una
  // para probarlas una por una.
}

// ============================================================
// FUNCIÓN COMPLETA (úsala como referencia para las demás)
// ============================================================

// Hace avanzar el robot hacia adelante
void adelante() {
  analogWrite(PIN_MOT_IZQ_EN, VELOCIDAD);
  digitalWrite(PIN_MOT_IZQ_IN1, HIGH);
  digitalWrite(PIN_MOT_IZQ_IN2, LOW);

  analogWrite(PIN_MOT_DER_EN, VELOCIDAD);
  digitalWrite(PIN_MOT_DER_IN1, HIGH);
  digitalWrite(PIN_MOT_DER_IN2, LOW);
}

// ============================================================
// FUNCIONES CON TODO — COMPLETA EL CUERPO
// ============================================================

// Hace retroceder el robot
// Pista: invierte las señales IN1 e IN2 respecto a adelante()
void atras() {
  // TODO: implementa esta función
}

// Gira el robot a la izquierda (motor izq atrás, motor der adelante)
void izquierda() {
  // TODO: implementa esta función
}

// Gira el robot a la derecha (motor izq adelante, motor der atrás)
void derecha() {
  // TODO: implementa esta función
}

// Detiene ambos motores
// Pista: analogWrite con valor 0 detiene el motor
void parar() {
  // TODO: implementa esta función
}
