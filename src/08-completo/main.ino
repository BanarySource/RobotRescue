// ============================================================
// RobotRescue — Operación Zona Cero
// 08: Misión Completa — Máquina de Estados
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc en docs/08-integracion.md
// 2. Copia las funciones ya implementadas de fases anteriores
// 3. Completa las transiciones marcadas con TODO
// ============================================================

#include <Wire.h>
#include <Adafruit_TCS34725.h>

// ============================================================
// ESTADOS DE LA MISIÓN
// ============================================================
const int SEGUIR_LINEA        = 0;
const int ENTRAR_EVACUACION   = 1;
const int BUSCAR_VICTIMAS     = 2;
const int CLASIFICAR_VICTIMA  = 3;
const int VOLVER_A_BUSCAR     = 4;
const int SALIR_EVACUACION    = 5;
const int MISION_COMPLETADA   = 6;

// --- Variable de estado ---
int estadoActual = SEGUIR_LINEA;

// ============================================================
// PINES
// ============================================================
// Motores
const int PIN_MOT_IZQ_EN  = 5;
const int PIN_MOT_IZQ_IN1 = 4;
const int PIN_MOT_IZQ_IN2 = 3;
const int PIN_MOT_DER_EN  = 6;
const int PIN_MOT_DER_IN1 = 7;
const int PIN_MOT_DER_IN2 = 8;

// Sensores IR
const int PIN_IR_IZQ_EXT = A0;
const int PIN_IR_IZQ     = A1;
const int PIN_IR_CENTRO  = A2;
const int PIN_IR_DER     = A3;
const int PIN_IR_DER_EXT = A4;

// Ultrasónico
const int PIN_TRIG = 9;
const int PIN_ECHO = 10;

// ============================================================
// CONSTANTES DE CONFIGURACIÓN
// ============================================================
const int VELOCIDAD      = 150;
const int UMBRAL_IR      = 500;
const int DIST_VICTIMA   = 10;   // cm

// Sensor de color
Adafruit_TCS34725 sensorColor = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X
);

// ============================================================
void setup() {
  Serial.begin(9600);
  Serial.println("RobotRescue - Mision Completa iniciada");

  pinMode(PIN_MOT_IZQ_EN,  OUTPUT);
  pinMode(PIN_MOT_IZQ_IN1, OUTPUT);
  pinMode(PIN_MOT_IZQ_IN2, OUTPUT);
  pinMode(PIN_MOT_DER_EN,  OUTPUT);
  pinMode(PIN_MOT_DER_IN1, OUTPUT);
  pinMode(PIN_MOT_DER_IN2, OUTPUT);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  sensorColor.begin();
}

// ============================================================
// LOOP PRINCIPAL — MÁQUINA DE ESTADOS
// ============================================================
void loop() {
  Serial.print("Estado: ");
  Serial.println(estadoActual);

  switch (estadoActual) {

    case SEGUIR_LINEA:
      seguirLinea();
      // TODO: si detectarColor() == "VERDE", cambiar a ENTRAR_EVACUACION
      break;

    case ENTRAR_EVACUACION:
      // TODO: avanzar hacia la zona de evacuación
      // TODO: cuando el robot esté dentro, cambiar a BUSCAR_VICTIMAS
      break;

    case BUSCAR_VICTIMAS:
      // TODO: girar buscando víctimas
      // TODO: si medirDistancia() < DIST_VICTIMA, cambiar a CLASIFICAR_VICTIMA
      // TODO: si detectarColor() == "ROJO", cambiar a SALIR_EVACUACION
      break;

    case CLASIFICAR_VICTIMA:
      // TODO: detectar color de la pelota
      // TODO: si es BLANCA → empujarAZonaAzul() → cambiar a VOLVER_A_BUSCAR
      // TODO: si es NEGRA  → empujarAZonaAmarilla() → cambiar a VOLVER_A_BUSCAR
      break;

    case VOLVER_A_BUSCAR:
      // TODO: regresar a posición de búsqueda → cambiar a BUSCAR_VICTIMAS
      break;

    case SALIR_EVACUACION:
      // TODO: avanzar hasta cruzar completamente la línea roja
      // TODO: cuando haya salido, cambiar a SEGUIR_LINEA
      break;

    case MISION_COMPLETADA:
      parar();
      Serial.println("¡Misión completada!");
      // No hacer nada más — misión terminada
      break;
  }
}

// ============================================================
// FUNCIONES COMPLETAS (referencia y utilidades básicas)
// ============================================================

void adelante() {
  analogWrite(PIN_MOT_IZQ_EN, VELOCIDAD);
  digitalWrite(PIN_MOT_IZQ_IN1, HIGH);
  digitalWrite(PIN_MOT_IZQ_IN2, LOW);
  analogWrite(PIN_MOT_DER_EN, VELOCIDAD);
  digitalWrite(PIN_MOT_DER_IN1, HIGH);
  digitalWrite(PIN_MOT_DER_IN2, LOW);
}

void parar() {
  analogWrite(PIN_MOT_IZQ_EN, 0);
  analogWrite(PIN_MOT_DER_EN, 0);
}

float medirDistancia() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  long duracion = pulseIn(PIN_ECHO, HIGH);
  return duracion / 58.0;
}

// ============================================================
// FUNCIONES CON TODO — COPIA E INTEGRA DESDE FASES ANTERIORES
// ============================================================

// Copia tu implementación de fase 4
void atras()     { /* TODO */ }
void izquierda() { /* TODO */ }
void derecha()   { /* TODO */ }

// Copia tu implementación de fase 5
void seguirLinea() { /* TODO */ }
void manejarGAP()  { /* TODO */ }

// Copia tu implementación de fase 6
String detectarColor() { /* TODO */ return "NINGUNO"; }

// Copia tu implementación de fase 7
String detectarColorPelota()   { /* TODO */ return "DESCONOCIDO"; }
void empujarAZonaAzul()        { /* TODO */ }
void empujarAZonaAmarilla()    { /* TODO */ }
