# 02 — Diseño y Planeación

## Objetivo

Diseñar el chasis del robot, planear la distribución de componentes y
definir la arquitectura del software antes de construir.

---

## Conceptos clave

- **Chasis:** estructura física que sostiene todos los componentes del robot.
- **Centro de gravedad:** punto de equilibrio del robot; afecta la estabilidad en la rampa.
- **Distribución de sensores:** posición estratégica de cada sensor para maximizar su efectividad.
- **Diagrama de conexiones:** mapa de cómo se conectan los componentes al Arduino.
- **Máquina de estados:** modelo de software donde el robot tiene estados definidos y reglas de transición.

---

## Material necesario

- Papel cuadriculado o herramienta de diseño (opcional)
- Lista de materiales: [`hardware/lista_materiales.md`](../hardware/lista_materiales.md)
- Regla y lápiz

---

## Actividades

1. Revisa la restricción de tamaño: máximo **15 cm × 15 cm** de base.
2. Dibuja a escala la planta (vista superior) del chasis con los componentes.
3. Define la posición de cada sensor IR (mínimo 3, recomendado 5).
4. Define la posición del sensor de color (al frente, apuntando al suelo).
5. Define la posición del sensor ultrasónico (al frente, horizontal).
6. Verifica que el robot cabe en 15×15 cm con todos sus componentes.
7. Dibuja el diagrama de la máquina de estados de tu robot (basado en `docs/00-introduccion.md`).
8. Anota qué pines del Arduino usarás para cada componente.

---

## Código base

No aplica — esta fase es de diseño.

---

## Preguntas de reflexión

1. ¿Por qué es importante diseñar antes de construir? ¿Qué problemas evita?
2. Si pones los sensores IR muy juntos, ¿qué problema podría surgir al seguir la línea?
3. ¿Dónde colocarías la batería para que el robot sea más estable en la rampa?
4. ¿Qué información necesita el robot para decidir si está en el estado `BUSCAR_VICTIMAS` o en `CLASIFICAR_VICTIMA`?
5. ¿Cuántos estados tiene la máquina de estados de tu diseño?

---

## Retos opcionales

1. Investiga la diferencia entre una transmisión de ruedas directa y con engranajes. ¿Cuál conviene para este reto?
2. Calcula la corriente total que consumirán tus componentes y verifica que la batería elegida es suficiente.
3. Diseña un estado adicional `MANEJAR_GAP` y define sus transiciones de entrada y salida.

---

## Checklist de la fase

- [ ] Diseño del chasis dibujado a escala (dentro de 15×15 cm)
- [ ] Posición de todos los sensores definida y justificada
- [ ] Diagrama de pines del Arduino completado
- [ ] Máquina de estados dibujada con todos los estados y transiciones
- [ ] Lista de materiales revisada y componentes confirmados
- [ ] Preguntas de reflexión respondidas en la bitácora
