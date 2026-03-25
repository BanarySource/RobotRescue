# 05 — Seguimiento de Línea + GAP

## Objetivo

Programar el robot para seguir una línea negra sobre fondo blanco,
manejar intersecciones y detectar y cruzar un GAP (interrupción de la línea).

---

## Conceptos clave

- **Sensor IR TCRT5000:** emite luz infrarroja y mide la reflexión. La línea negra absorbe luz (valor alto), el fondo blanco la refleja (valor bajo).
- **`analogRead(pin)`:** lee el valor analógico de un sensor (0–1023 en Arduino Uno).
- **Umbral (threshold):** valor que define si el sensor está "sobre la línea" o "fuera de la línea". Se calibra experimentalmente.
- **Control proporcional:** ajusta la corrección de dirección en proporción al error detectado.
- **GAP:** tramo donde la línea desaparece; el robot debe avanzar recto (recordando su última dirección) hasta reencontrarla.

---

## Material necesario

- Robot ensamblado con sensores IR montados
- Pista de prueba con línea negra y un GAP de ~10 cm
- Código base: [`src/05-linea/linea.ino`](../src/05-linea/linea.ino)

---

## Actividades

1. Abre `linea.ino` y revisa la función `leerSensores()` ya implementada.
2. Abre el Monitor Serial y calibra los valores de tus sensores: pon el robot sobre la línea y sobre el blanco y anota los valores.
3. Ajusta la constante `UMBRAL` en el código con el valor que mejor separa línea/fondo.
4. Completa la función `seguirLinea()` para que el robot siga la línea.
5. Prueba el seguimiento de línea en una pista recta primero, luego con curvas.
6. Completa la función `manejarGAP()`: el robot debe avanzar recto al perder la línea y volver a `seguirLinea()` al reencontrarla.
7. Prueba con el GAP en la pista.

---

## Código base

[`src/05-linea/linea.ino`](../src/05-linea/linea.ino)

---

## Diagrama de flujo — Seguimiento de línea + GAP

```
loop()
  │
  ▼
leerSensores()
  │
  ▼
¿Algún sensor detecta línea?
  │
  ├─ SÍ ──► ¿GAP activo?
  │              │
  │              ├─ SÍ  ──► GAP resuelto, desactivar flag → seguirLinea()
  │              └─ NO  ──► seguirLinea()
  │
  └─ NO ──► ¿GAP activo?
                 │
                 ├─ SÍ  ──► manejarGAP() (avanzar recto)
                 └─ NO  ──► Activar flag GAP → manejarGAP()
```

---

## Preguntas de reflexión

1. ¿Por qué el umbral no es el mismo en todos los robots, aunque usen el mismo sensor?
2. Si el robot "vibra" al seguir la línea (corrige demasiado), ¿qué ajustarías?
3. ¿Qué información "recuerda" el robot para manejar el GAP? ¿Cómo la almacena?
4. ¿Qué pasaría si el robot llegara a un GAP mientras está girando? ¿Habría que manejar ese caso?
5. ¿Por qué se recomienda usar al menos 5 sensores IR para manejar el GAP mejor?

---

## Retos opcionales

1. Implementa un control proporcional (P) para suavizar el seguimiento de línea: la corrección debe ser mayor cuanto más alejado esté el robot de la línea.
2. Agrega lógica para detectar y ignorar intersecciones (cuando todos los sensores detectan negro al mismo tiempo).
3. Mide y registra cuántos milisegundos tarda tu robot en cruzar el GAP. ¿Hay un tiempo máximo antes de perder la línea?

---

## Checklist de la fase

- [ ] Sensores IR calibrados (umbral definido y documentado)
- [ ] `seguirLinea()` implementada y probada en pista recta
- [ ] `seguirLinea()` probada con curvas
- [ ] `manejarGAP()` implementada
- [ ] GAP cruzado exitosamente al menos 3 veces
- [ ] Código guardado con `git commit`
- [ ] Preguntas de reflexión respondidas en la bitácora
