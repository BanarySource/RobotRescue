# 03 — Construcción del Chasis

## Objetivo

Ensamblar el robot físicamente: instalar motores, ruedas, sensores y
electrónica siguiendo el diseño de la fase anterior.

---

## Conceptos clave

- **Driver de motores:** módulo que permite al Arduino controlar motores DC de mayor voltaje/corriente (L298N o TB6612FNG).
- **PWM (Pulse Width Modulation):** señal que controla la velocidad del motor variando el ciclo de trabajo.
- **Pull-up / Pull-down:** resistencias que definen el estado lógico de una señal cuando no hay entrada activa.
- **Conexión en serie vs paralelo:** cómo afecta el voltaje y la corriente en circuitos de alimentación.
- **Masa común (GND):** todos los componentes deben compartir la misma referencia de tierra.

---

## Material necesario

- Todos los componentes de [`hardware/lista_materiales.md`](../hardware/lista_materiales.md)
- Desarmadores, pinzas, cautín (si se suelda)
- Cables dupont macho-hembra y macho-macho
- Multímetro (para verificar conexiones)

---

## Actividades

1. Monta los motores y ruedas en el chasis.
2. Instala el driver de motores (L298N o TB6612FNG) y conéctalo a los motores.
3. Fija los sensores IR en la posición definida en el diseño (3–8 mm del suelo).
4. Instala el sensor de color apuntando al suelo al frente del robot.
5. Instala el sensor ultrasónico al frente, horizontal.
6. Conecta todos los componentes al Arduino según el diagrama de pines.
7. Conecta la batería (sin encender aún).
8. Verifica cada conexión con el multímetro antes de encender.
9. Enciende el robot y verifica con el Monitor Serial que el Arduino responde.

---

## Código base

No aplica — esta fase es de ensamblaje físico.
En la siguiente fase (04-movimiento) comenzarás a programar.

---

## Preguntas de reflexión

1. ¿Qué pasaría si conectaras los motores directamente al Arduino sin el driver? ¿Por qué es peligroso?
2. ¿Por qué todos los componentes deben compartir el mismo GND (masa común)?
3. Si un sensor IR da lecturas erráticas, ¿qué verificarías primero: la conexión eléctrica o el código?
4. ¿Cómo verificarías sin código que el driver de motores está funcionando?
5. ¿Qué ajuste harías si el robot no cabe en los 15×15 cm una vez ensamblado?

---

## Retos opcionales

1. Diseña un soporte impreso en 3D o cortado en acrílico para fijar los sensores IR a la distancia exacta del suelo.
2. Agrega un LED indicador (conectado a un pin digital del Arduino) que se encienda cuando el robot está encendido. Pruébalo con `digitalWrite`.
3. Mide con el multímetro el voltaje real que llega a cada motor bajo carga y compáralo con el voltaje nominal de la batería.

---

## Checklist de la fase

- [ ] Motores y ruedas montados y fijos
- [ ] Driver de motores conectado correctamente a motores y Arduino
- [ ] Sensores IR montados a 3–8 mm del suelo
- [ ] Sensor de color apuntando al suelo
- [ ] Sensor ultrasónico apuntando al frente horizontal
- [ ] Todas las conexiones verificadas con multímetro
- [ ] Robot enciende sin humo ni calor inusual
- [ ] Arduino responde en Monitor Serial al encender
- [ ] Robot cabe dentro de 15×15 cm
- [ ] Preguntas de reflexión respondidas en la bitácora
