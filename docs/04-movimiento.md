# 04 — Programación Básica de Movimiento

## Objetivo

Programar las funciones básicas de movimiento del robot:
avanzar, retroceder, girar a la izquierda, girar a la derecha y detenerse.

---

## Conceptos clave

- **PWM:** señal digital que simula una salida analógica variando el ancho del pulso. Controla la velocidad del motor.
- **`analogWrite(pin, valor)`:** envía una señal PWM (0–255) a un pin del Arduino.
- **`digitalWrite(pin, estado)`:** envía HIGH o LOW a un pin digital.
- **`pinMode(pin, modo)`:** configura un pin como INPUT o OUTPUT.
- **Driver L298N / TB6612FNG:** módulo que recibe señales del Arduino y entrega la corriente necesaria a los motores.
- **Monitor Serial:** herramienta del IDE de Arduino para enviar y recibir mensajes de texto mientras el robot está conectado por USB.

---

## Material necesario

- Robot ensamblado (fase 3 completada)
- Cable USB para conectar Arduino a la computadora
- Arduino IDE con el puerto COM correcto configurado
- Código base: [`src/04-movimiento/movimiento.ino`](../src/04-movimiento/movimiento.ino)

---

## Actividades

1. Abre el archivo `movimiento.ino` en el Arduino IDE.
2. Revisa la función `adelante()` ya implementada — entiende cómo usa `analogWrite`.
3. Completa las funciones `atras()`, `izquierda()`, `derecha()` siguiendo el mismo patrón.
4. Completa la función `parar()`.
5. En el `loop()`, llama a cada función con una pausa de 1 segundo entre cada una.
6. Carga el programa al Arduino y observa el movimiento.
7. Abre el Monitor Serial y verifica que los mensajes de depuración aparecen.
8. Ajusta la velocidad (`VELOCIDAD`) hasta que el robot se mueva de forma controlada.

---

## Código base

[`src/04-movimiento/movimiento.ino`](../src/04-movimiento/movimiento.ino)

---

## Preguntas de reflexión

1. ¿Qué valor de `analogWrite` detiene completamente un motor? ¿Y cuál lo pone a velocidad máxima?
2. Si el robot gira a la derecha cuando quieres que gire a la izquierda, ¿qué cambiarías en el código?
3. ¿Por qué usamos `Serial.println()` para depurar en lugar de simplemente mirar el robot?
4. ¿Qué diferencia hay entre `delay(1000)` y no tener delay? ¿Cuándo es un problema usar delay?
5. Si un motor va más rápido que el otro, ¿cómo lo compensarías en el código?

---

## Retos opcionales

1. Implementa una función `girarGrados(int grados)` que haga girar al robot aproximadamente esa cantidad de grados usando tiempo.
2. Implementa una función `avanzarCm(int cm)` que avance aproximadamente esa distancia usando tiempo.
3. Crea una secuencia de movimientos que dibuje un cuadrado en el suelo.

---

## Checklist de la fase

- [ ] Funciones `adelante()`, `atras()`, `izquierda()`, `derecha()`, `parar()` implementadas
- [ ] Robot se mueve en las 4 direcciones correctamente
- [ ] Monitor Serial muestra mensajes de depuración
- [ ] Velocidad ajustada para movimiento controlado
- [ ] Código guardado con `git commit`
- [ ] Preguntas de reflexión respondidas en la bitácora
