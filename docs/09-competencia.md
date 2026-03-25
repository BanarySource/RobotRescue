# 09 — Pruebas, Ajuste y Competencia

## Objetivo

Afinar el robot para obtener el máximo puntaje en la competencia,
desarrollar una estrategia de ajuste sistemático y prepararse para competir.

---

## Conceptos clave

- **Depuración sistemática:** proceso de identificar y corregir fallos de forma ordenada, un problema a la vez.
- **Repetibilidad:** capacidad del robot de completar la misión de forma consistente. Un robot que lo logra 8 de 10 veces es más confiable que uno que lo logra 1 vez perfecto.
- **Parámetros ajustables:** valores en el código que afectan el comportamiento (velocidad, umbral IR, umbral de color, distancia de detección).
- **Estrategia de competencia:** decisiones sobre qué arriesgar y qué asegurar según la tabla de puntos.

---

## Material necesario

- Robot completamente integrado (`src/08-completo/main.ino`)
- Pista de competencia (o réplica lo más fiel posible)
- Cronómetro
- Bitácora de ajustes

---

## Actividades

1. Ejecuta la misión completa 5 veces y registra el puntaje de cada intento.
2. Identifica el paso donde falla con más frecuencia.
3. Ajusta el parámetro relacionado (velocidad, umbral, etc.) y repite.
4. Practica reinicios desde cada checkpoint — debes poder hacerlo en menos de 10 segundos.
5. Mide el tiempo de misión completa; si supera los 4 minutos, optimiza la búsqueda de víctimas.
6. Realiza al menos 10 intentos completos y documenta los resultados en la bitácora.
7. Define la estrategia del día de competencia: ¿priorizar víctimas blancas? ¿cuántos reinicios arriesgar?

---

## Código base

Continúa usando [`src/08-completo/main.ino`](../src/08-completo/main.ino).
No se introduce código nuevo en esta fase — solo ajuste de parámetros existentes.

---

## Preguntas de reflexión

1. ¿Cuál fue el fallo más frecuente en tus pruebas? ¿Lo resolviste completamente o lo mitigaste?
2. ¿Vale más intentar hacer la misión completa perfecta o asegurar los primeros 60 puntos de forma consistente?
3. ¿Cómo afecta el nerviosismo a los operadores el día de competencia? ¿Qué procedimientos ayudan a reducirlo?
4. Si el robot falla en el GAP el día de la competencia y ya usaste 2 reinicios, ¿qué decides?
5. ¿Qué aprendiste en este proyecto que no esperabas aprender?

---

## Retos opcionales

1. Graba un video de una misión completa exitosa y analiza frame a frame las transiciones de estado.
2. Compara tu estrategia de seguimiento de línea con la de otro equipo — ¿cuáles son las diferencias clave?
3. Escribe un documento de "lecciones aprendidas" con los 5 errores más importantes que cometió tu equipo y cómo los resolvieron.

---

## Checklist de la fase

- [ ] Al menos 10 intentos completos documentados con puntaje
- [ ] Fallo más frecuente identificado y abordado
- [ ] Tiempo de misión < 4 minutos en condiciones normales
- [ ] Reinicios desde cada checkpoint practicados
- [ ] Estrategia de competencia definida y documentada
- [ ] Video de al menos una misión completa exitosa grabado
- [ ] Presentación de 5 minutos preparada
- [ ] Preguntas de reflexión respondidas en la bitácora
