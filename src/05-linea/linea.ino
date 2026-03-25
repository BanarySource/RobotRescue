// ============================================================
// RobotRescue — Operación Zona Cero
// 05: Seguimiento de Línea + GAP
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc en docs/05-linea.md
// 2. Calibra el UMBRAL con el Monitor Serial antes de completar
// 3. Completa las secciones marcadas con TODO
// ============================================================

// --- Pines sensores IR (ajusta según tu montaje) ---
const int PIN_IR_IZQ_EXT = A0;  // Sensor izquierdo extremo
const int PIN_IR_IZQ     = A1;  // Sensor izquierdo
const int PIN_IR_CENTRO  = A2;  // Sensor central
const int PIN_IR_DER     = A3;  // Sensor derecho
const int PIN_IR_DER_EXT = A4;  // Sensor derecho extremo

// --- Pines motores (igual que fase 4) ---
const int PIN_MOT_IZQ_EN  = 5;
const int PIN_MOT_IZQ_IN1 = 4;
const int PIN_MOT_IZQ_IN2 = 3;
const int PIN_MOT_DER_EN  = 6;
const int PIN_MOT_DER_IN1 = 7;
const int PIN_MOT_DER_IN2 = 8;

// --- Configuración ---
const int VELOCIDAD_BASE = 150;
const int UMBRAL = 500;  // Ajusta con el Monitor Serial: sobre línea negra > UMBRAL

// --- Variables globales ---
bool enGAP = false;              // true cuando el robot está cruzando un GAP
int lecturas[5];                 // Valores de los 5 sensores IR

// ============================================================
void setup() {
  Serial.begin(9600);
  Serial.println("RobotRescue - Fase 5: Seguimiento de línea iniciado");

  pinMode(PIN_MOT_IZQ_EN,  OUTPUT);
  pinMode(PIN_MOT_IZQ_IN1, OUTPUT);
  pinMode(PIN_MOT_IZQ_IN2, OUTPUT);
  pinMode(PIN_MOT_DER_EN,  OUTPUT);
  pinMode(PIN_MOT_DER_IN1, OUTPUT);
  pinMode(PIN_MOT_DER_IN2, OUTPUT);
}

// ============================================================
void loop() {
  leerSensores();

  bool hayLinea = (lecturas[0] > UMBRAL || lecturas[1] > UMBRAL ||
                   lecturas[2] > UMBRAL || lecturas[3] > UMBRAL ||
                   lecturas[4] > UMBRAL);

  // TODO: Implementa la lógica de decisión:
  // - Si hay línea y enGAP es true  → GAP resuelto, enGAP = false, llamar seguirLinea()
  // - Si hay línea y enGAP es false → llamar seguirLinea()
  // - Si no hay línea               → enGAP = true, llamar manejarGAP()
}

// ============================================================
// FUNCIÓN COMPLETA (úsala como referencia)
// ============================================================

// Lee los 5 sensores IR y guarda los valores en el arreglo 'lecturas'
void leerSensores() {
  lecturas[0] = analogRead(PIN_IR_IZQ_EXT);
  lecturas[1] = analogRead(PIN_IR_IZQ);
  lecturas[2] = analogRead(PIN_IR_CENTRO);
  lecturas[3] = analogRead(PIN_IR_DER);
  lecturas[4] = analogRead(PIN_IR_DER_EXT);

  Serial.print("IR: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(lecturas[i]);
    Serial.print(" ");
  }
  Serial.println();
}

// ============================================================
// FUNCIONES CON TODO — COMPLETA EL CUERPO
// ============================================================

// Sigue la línea negra ajustando velocidades de los motores
// Pista: si el sensor izquierdo detecta línea → gira levemente a la izquierda
//        si el sensor derecho detecta línea   → gira levemente a la derecha
//        si solo el centro detecta línea      → avanza recto
void seguirLinea() {
  // TODO: implementa esta función
}

// Maneja el GAP: avanza recto mientras no haya línea
// El robot saldrá de esta función cuando vuelva a detectar la línea en loop()
void manejarGAP() {
  // TODO: implementa esta función
  // Pista: simplemente llama a adelante() — loop() se encargará de detectar
  //        cuando la línea reaparezca
}
