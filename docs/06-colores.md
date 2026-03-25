# 06 — Detección de Zonas por Color

## Objetivo

Programar el robot para detectar los colores del campo (verde, rojo, azul,
amarillo, morado) usando el sensor TCS34725 o TCS3200 y tomar decisiones
basadas en el color detectado.

---

## Conceptos clave

- **Sensor TCS34725:** mide la intensidad de luz en canales rojo, verde, azul y claro (RGBC). Devuelve valores de 0–65535 por canal.
- **Calibración de color:** proceso de determinar los rangos de valores R, G, B que corresponden a cada color del campo.
- **Lógica de umbral por canal:** en lugar de comparar colores exactos, se comparan rangos para tolerar variaciones de iluminación.
- **`Wire.h`:** librería de Arduino para comunicación I2C, necesaria para el TCS34725.

---

## Material necesario

- Robot con sensor de color instalado (apuntando al suelo)
- Muestras de cada color del campo (cartulinas o el campo real)
- Código base: [`src/06-colores/colores.ino`](../src/06-colores/colores.ino)
- Librería `Adafruit_TCS34725` instalada en el Arduino IDE

---

## Actividades

1. Instala la librería `Adafruit_TCS34725` desde el Gestor de Librerías del Arduino IDE.
2. Abre `colores.ino` y revisa la función `leerColor()` ya implementada.
3. Coloca el robot sobre cada color y anota los valores R, G, B en el Monitor Serial.
4. Define los rangos de cada color en las constantes del código.
5. Completa la función `detectarColor()` para que devuelva el nombre del color.
6. Prueba detectando cada color del campo al menos 5 veces y verifica la tasa de aciertos.
7. Ajusta los rangos si la detección no es confiable.

---

## Código base

[`src/06-colores/colores.ino`](../src/06-colores/colores.ino)

---

## Diagrama de flujo — Detección de color

```
detectarColor()
  │
  ▼
leerColor() → obtiene R, G, B
  │
  ▼
¿R alto, G alto, B bajo? → "AMARILLO"
  │ no
  ▼
¿G alto, R bajo, B bajo? → "VERDE"
  │ no
  ▼
¿B alto, R bajo, G bajo? → "AZUL"
  │ no
  ▼
¿R alto, G bajo, B bajo? → "ROJO"
  │ no
  ▼
¿R medio, G bajo, B medio? → "MORADO"
  │ no
  ▼
"NINGUNO"
```

---

## Preguntas de reflexión

1. ¿Por qué los valores R, G, B del mismo color pueden variar entre distintas lecturas?
2. ¿Qué pasaría si calibras el sensor en el salón y luego compites en el lugar real con diferente iluminación?
3. ¿Por qué es mejor definir **rangos** de color en lugar de valores exactos?
4. ¿Cómo afecta la altura del sensor al suelo a las lecturas de color?
5. ¿Qué harías si el sensor detecta "VERDE" cuando el robot está sobre la línea negra?

---

## Retos opcionales

1. Implementa una función `calibrarColor(String nombreColor)` que lea 10 muestras y calcule el promedio automáticamente.
2. Agrega detección de la pelota blanca y negra con el mismo sensor de color (para la fase siguiente).
3. Crea una animación en el Monitor Serial que muestre el color detectado de forma gráfica (con caracteres ASCII).

---

## Checklist de la fase

- [ ] Librería del sensor de color instalada
- [ ] Valores R, G, B de cada color del campo registrados en la bitácora
- [ ] Rangos de color definidos en el código
- [ ] `detectarColor()` implementada y probada
- [ ] Tasa de aciertos ≥ 90% para cada color
- [ ] Código guardado con `git commit`
- [ ] Preguntas de reflexión respondidas en la bitácora
