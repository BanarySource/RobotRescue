// ============================================================
// RobotRescue — Operación Zona Cero
// 06: Detección de Zonas por Color
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc en docs/06-colores.md
// 2. Instala la librería Adafruit_TCS34725 en el Arduino IDE
// 3. Calibra los rangos de color ANTES de completar detectarColor()
// ============================================================

#include <Wire.h>
#include <Adafruit_TCS34725.h>

// --- Sensor de color ---
Adafruit_TCS34725 sensorColor = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS,
  TCS34725_GAIN_4X
);

// --- Rangos de color (ajusta con los valores de tu calibración) ---
// Formato: {R_min, R_max, G_min, G_max, B_min, B_max}
// IMPORTANTE: calibra sobre el campo real con la iluminación de competencia

const int RANGO_VERDE[6]   = {  0, 100, 150, 400,   0, 100 };  // TODO: ajusta
const int RANGO_ROJO[6]    = {150, 400,   0, 100,   0, 100 };  // TODO: ajusta
const int RANGO_AZUL[6]    = {  0, 100,   0, 100, 150, 400 };  // TODO: ajusta
const int RANGO_AMARILLO[6]= {150, 400, 150, 400,   0, 100 };  // TODO: ajusta
const int RANGO_MORADO[6]  = { 80, 200,   0, 100,  80, 200 };  // TODO: ajusta

// --- Variables globales ---
uint16_t r, g, b, c;  // Valores de los canales del sensor

// ============================================================
void setup() {
  Serial.begin(9600);
  Serial.println("RobotRescue - Fase 6: Detección de color iniciada");

  if (!sensorColor.begin()) {
    Serial.println("ERROR: Sensor de color no encontrado. Verifica conexiones I2C.");
    while (1);
  }
  Serial.println("Sensor de color listo.");
}

// ============================================================
void loop() {
  leerColor();
  String color = detectarColor();

  Serial.print("Color detectado: ");
  Serial.println(color);

  delay(200);
}

// ============================================================
// FUNCIÓN COMPLETA (úsala como referencia)
// ============================================================

// Lee los valores RGBC del sensor y los guarda en las variables globales r, g, b, c
void leerColor() {
  sensorColor.getRawData(&r, &g, &b, &c);

  Serial.print("R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" C: "); Serial.println(c);
}

// ============================================================
// FUNCIONES CON TODO — COMPLETA EL CUERPO
// ============================================================

// Devuelve el nombre del color detectado según los rangos calibrados
// Posibles valores de retorno: "VERDE", "ROJO", "AZUL", "AMARILLO", "MORADO", "NINGUNO"
String detectarColor() {
  // TODO: implementa esta función
  // Pista: compara los valores r, g, b con cada rango usando condicionales
  // Ejemplo:
  // if (r >= RANGO_VERDE[0] && r <= RANGO_VERDE[1] &&
  //     g >= RANGO_VERDE[2] && g <= RANGO_VERDE[3] &&
  //     b >= RANGO_VERDE[4] && b <= RANGO_VERDE[5]) {
  //   return "VERDE";
  // }
  return "NINGUNO";
}

// Devuelve "BLANCO" si la pelota es una víctima viva, "NEGRO" si es muerta
// Pista: una pelota blanca refleja mucho luz en todos los canales (r, g, b altos)
//        una pelota negra absorbe la luz (r, g, b bajos)
// Esta función se usará en la fase 7; impleméntala aquí como práctica
String detectarColorPelota() {
  // TODO: implementa esta función
  return "DESCONOCIDO";
}
