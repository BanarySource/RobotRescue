# Guía de Componentes — RobotRescue

> Esta guía está pensada para alumnos sin experiencia previa en electrónica.
> Aquí encontrarás qué necesitas, para qué sirve cada cosa y cómo empezar a armar tu robot.

---

## ¿Cómo funciona el robot por dentro?

Antes de ver los componentes uno por uno, es útil entender cómo se conectan entre sí:

```
BATERÍA (LiPo 2S)
   │
   ▼
REGULADOR (LM2596) → entrega 5V estable
   │
   ├──► ARDUINO NANO (cerebro — recibe sensores, controla todo)
   │         │
   │    ┌────┴────┐
   │    ▼         ▼
   │  SENSORES   DRIVER TB6612FNG
   │  (IR línea,      │
   │  IR frontal,     ▼
   │  color)      MOTORES DC (mueven el robot)
   │
   └──► DRIVER TB6612FNG (también recibe energía directa de la batería)
```

El Arduino es el cerebro: lee los sensores y decide qué hacer. Los motores son los músculos. El driver es el intermediario que les da a los motores la potencia que el Arduino no puede dar solo.

---

## 1. Controlador — Arduino Nano

**Nivel de dificultad:** Básico

### ¿Para qué sirve?
Es el "cerebro" del robot. Ejecuta tu programa, lee los sensores y envía señales al driver de motores. Todo el código que escribes corre aquí.

### Características importantes
- Alimentación: 5V (por USB) o 7–12V (por pin VIN)
- 8 pines analógicos (A0–A7) para sensores IR
- Pines digitales con PWM (~) para controlar velocidad de motores
- Comunicación por USB con el IDE de Arduino

### ¿Cómo interactúa con los demás?
Recibe datos de los sensores IR y del sensor de color. Envía señales al driver TB6612FNG para mover los motores. Se programa desde la computadora por cable USB.

### Consejos de armado
- Monta el Arduino sobre separadores (standoffs) para que no toque el chasis metálico ni otros componentes.
- Deja el puerto USB accesible — lo necesitarás para cargar programas durante todo el proyecto.
- Usa el pin **5V** del Arduino para alimentar sensores (no el VIN).

### Errores comunes
| Error | Consecuencia | Solución |
|-------|-------------|----------|
| Conectar motores directo al Arduino | Quema el Arduino | Siempre usa el driver TB6612FNG |
| Alimentar con menos de 5V | El programa falla o se reinicia | Verifica el regulador step-down |
| No instalar drivers USB | La computadora no reconoce el Arduino | Instala driver CH340 (para clones Nano) |

---

## 2. Sistema de Movimiento — Motores TT y Ruedas

**Nivel de dificultad:** Básico

### ¿Para qué sirven?
Los **motores DC tipo TT** (los motores amarillos) convierten energía eléctrica en movimiento rotatorio. Las ruedas van acopladas directamente al eje del motor.

### ¿Cómo funciona el movimiento?
Con **2 motores independientes** (uno izquierdo, uno derecho), el robot gira cambiando la velocidad o dirección de cada motor:

| Motor izquierdo | Motor derecho | Resultado |
|-----------------|---------------|-----------|
| Adelante | Adelante | Avanza recto |
| Atrás | Atrás | Retrocede |
| Adelante | Atrás | Gira a la derecha |
| Atrás | Adelante | Gira a la izquierda |
| Rápido | Lento | Curva suave |

### La rueda loca (caster)
Va en la parte trasera o delantera del robot y sirve de tercer punto de apoyo. No tiene motor — solo rueda libremente para que el robot no se caiga.

### Consejos de armado
- Fija los motores con tornillos M3 — si se mueven, el robot no irá recto.
- Las ruedas deben quedar a la **misma altura** del suelo; si una está más alta, el robot jala hacia un lado.
- La rueda loca debe tocar el suelo con la misma presión que las ruedas motrices.

### Errores comunes
| Error | Consecuencia | Solución |
|-------|-------------|----------|
| Motores flojos o mal fijados | El robot no va recto | Asegura con tornillos y tuercas M3 |
| Rueda loca muy apretada contra el suelo | El robot frena solo | Ajusta la altura del caster |
| Ruedas desalineadas | Giros imprecisos | Verifica que ambas ruedas queden paralelas |

---

## 3. Driver de Motores — TB6612FNG

**Nivel de dificultad:** Intermedio

### ¿Para qué sirve?
Es el intermediario entre el Arduino y los motores. El Arduino **no puede dar suficiente corriente** para mover motores directamente — intentarlo quemaría el Arduino. El TB6612FNG toma la señal de control del Arduino y entrega a los motores la potencia que necesitan desde la batería.

### Pines importantes

| Pin del TB6612FNG | Conectar a | Función |
|-------------------|-----------|---------|
| VCC | 5V del Arduino | Alimenta la lógica interna |
| VM | Batería (+) | Alimenta los motores |
| GND | GND común | Tierra |
| AIN1, AIN2 | Pines digitales Arduino | Dirección motor A |
| PWMA | Pin PWM del Arduino (~) | Velocidad motor A |
| BIN1, BIN2 | Pines digitales Arduino | Dirección motor B |
| PWMB | Pin PWM del Arduino (~) | Velocidad motor B |
| STBY | 5V (o pin digital) | Habilita el driver (debe estar en HIGH) |
| AO1, AO2 | Motor izquierdo | Salida al motor |
| BO1, BO2 | Motor derecho | Salida al motor |

### Consejos de armado
- El pin **STBY** (standby) debe estar conectado a 5V o a un pin HIGH del Arduino. Si está en LOW, los motores no se mueven aunque todo lo demás esté bien.
- Verifica la polaridad de los motores — si el motor gira al revés, intercambia los cables de salida (AO1↔AO2).

### Errores comunes
| Error | Consecuencia | Solución |
|-------|-------------|----------|
| STBY no conectado | Motores no giran | Conecta STBY a 5V |
| VM conectado a 5V en lugar de batería | Motores sin fuerza | VM va a la batería directamente |
| GND de Arduino y batería no compartidos | Comportamiento errático | Conecta todos los GND juntos |

---

## 4. Alimentación — Batería, Regulador y Switch

**Nivel de dificultad:** Intermedio

### Batería LiPo 2S (7.4V)

**¿Para qué sirve?** Es la fuente de energía de todo el robot. "2S" significa que tiene 2 celdas en serie, lo que da ~7.4V nominales (8.4V cargada).

> ⚠️ **Las baterías LiPo requieren cuidado especial:**
> - Nunca las descargues por debajo de 3V por celda (6V total para 2S).
> - Nunca las cargues sin supervisión ni con cargador incorrecto.
> - Si se hinchan, no las uses — son peligrosas.
> - Siempre usa el **cargador balanceado** incluido en el kit.

### Regulador Step-Down LM2596

**¿Para qué sirve?** La batería da 7.4V, pero el Arduino y los sensores necesitan 5V. El regulador "baja" el voltaje de forma segura y eficiente.

**Ajuste del regulador:**
1. Conecta la batería al regulador (sin conectar el Arduino todavía).
2. Mide el voltaje de salida con un multímetro.
3. Gira el potenciómetro (tornillo pequeño) hasta leer **5.0V exactos**.
4. ¡Importante! Hacer este ajuste **antes** de conectar el Arduino.

### Interruptor (Switch)

**¿Para qué sirve?** Permite encender y apagar el robot sin desconectar la batería. Instálalo en el cable positivo (+) entre la batería y el regulador.

### Diagrama de conexión de alimentación

```
Batería (+) ──► Switch ──► Regulador (entrada) ──► Regulador salida 5V ──► Arduino VIN o 5V
                     │
                     └──────────────────────────────────────────────────► TB6612FNG (VM)

Batería (−) ──────────────────────────────────────────────────────────► GND común
```

### Errores comunes
| Error | Consecuencia | Solución |
|-------|-------------|----------|
| Regulador sin ajustar | Puede entregar 7.4V y quemar el Arduino | Siempre calibra a 5V antes de conectar |
| Invertir polaridad de la batería | Daño permanente en componentes | Verifica rojo (+) y negro (−) |
| Cargar con cargador incorrecto | Batería dañada o incendio | Solo usar cargador balanceado 2S |

---

## 5. Sensores

### 5a. Sensores IR para seguimiento de línea (TCRT5000)

**Nivel de dificultad:** Básico

**¿Para qué sirven?**
Detectan si el robot está sobre la línea negra o sobre el fondo blanco. Emiten luz infrarroja hacia el suelo y miden cuánta luz regresa: el blanco refleja mucho (valor bajo), el negro absorbe casi todo (valor alto).

**Configuración recomendada:**
- **2 sensores:** detección básica (izquierda y derecha de la línea).
- **3 sensores:** más preciso (izquierda, centro, derecha) — recomendado para el GAP.

**Montaje:**
- Altura del suelo: **3 a 8 mm**. Muy lejos → no detecta bien. Muy cerca → puede rozar.
- Los sensores deben estar simétricos respecto al centro del robot.
- Apuntar **perpendicular al suelo** (no inclinados).

**Pines de conexión:**

| Pin TCRT5000 | Conectar a |
|-------------|-----------|
| VCC | 5V del Arduino |
| GND | GND |
| A0 (analógico) | Pin analógico del Arduino (A0, A1, A2...) |

**Calibración (obligatoria antes de programar):**
1. Abre el Monitor Serial en el Arduino IDE.
2. Pon el sensor sobre blanco y anota el valor.
3. Pon el sensor sobre negro y anota el valor.
4. El **umbral** va a la mitad entre ambos valores.

---

### 5b. Sensor IR frontal — Detección de víctimas (TCRT5000 o similar)

**Nivel de dificultad:** Básico

**¿Para qué sirve?**
Montado al frente del robot, detecta la **presencia de un objeto** (la pelota) midiendo la distancia por reflexión infrarroja. Cuando hay una pelota enfrente, el valor del sensor cambia notablemente.

**Montaje:**
- Posición: frente del robot, a la **altura de las pelotas** (~3–5 cm del suelo).
- Apuntando **horizontalmente** hacia adelante, no al suelo.
- Si usas una guía frontal tipo embudo (recomendado), el sensor va al centro del embudo.

> **Nota:** Este mismo sensor también puede detectar el color de las pelotas (blanca vs negra) cuando el robot la tiene enfrente: la pelota blanca refleja mucho, la negra casi nada.

---

### 5c. Sensor de color en el piso (parte delantera)

**Nivel de dificultad:** Intermedio

**¿Para qué sirve?**
Montado apuntando al suelo en la parte frontal del robot, detecta los **colores del campo**: verde (entrada a zona de evacuación), rojo (salida), azul, amarillo y morado (meta).

**Montaje:**
- Apuntar **perpendicular al suelo**.
- Distancia al suelo: **10 a 20 mm** para lectura estable.
- Evitar que reciba luz directa de lámparas — puede saturar el sensor y dar lecturas incorrectas.
- Conectar por I2C al Arduino: pin A4 (SDA) y A5 (SCL) en el Arduino Nano.

**Calibración (crítica):**
> ⚠️ Calibra siempre en el **lugar real de competencia** con la iluminación del día. Los colores cambian según la luz ambiental.

1. Instala la librería `Adafruit_TCS34725` en el Arduino IDE.
2. Abre el Monitor Serial y coloca el robot sobre cada color.
3. Anota los valores R, G, B para cada color.
4. Define rangos (no valores exactos) para tolerar variaciones.

---

## 6. Estructura — Chasis 3D

**Nivel de dificultad:** Básico

### ¿Para qué sirve?
Es el esqueleto del robot. Todo se monta sobre él: motores, Arduino, sensores, batería. Está diseñado a medida para que todo quepa dentro de los **15 × 15 cm** máximos del reglamento.

### Características del diseño
- **Guía frontal tipo embudo:** ayuda a centrar la pelota frente al sensor IR y facilita el empuje hacia las zonas de depósito.
- **Soportes para sensores IR de línea:** mantienen los sensores a la altura correcta del suelo sin tener que usar cinta.
- **Soporte para sensor IR frontal:** posiciona el sensor a la altura de las pelotas.

### Consejos de armado
- Usa tornillos **M3** con tuercas o insertos de calor para fijar componentes — el chasis impreso aguanta bien M3.
- Usa **separadores (standoffs)** de 5–10 mm para el Arduino, así el aire circula y no hay cortocircuitos.
- Pega los cables con cinchos o cinta doble cara para que no queden sueltos — los cables sueltos son la causa número uno de fallas durante la competencia.

---

## 7. Conexiones — Cables Dupont y Protoboard

**Nivel de dificultad:** Básico

### Tipos de cables Dupont
| Tipo | Uso |
|------|-----|
| Macho-Macho (M-M) | Conectar dos filas de la protoboard |
| Macho-Hembra (M-H) | Conectar protoboard a módulo (sensor, driver) |
| Hembra-Hembra (H-H) | Conectar dos módulos directamente |

### Protoboard (mini)
Permite conectar componentes sin soldar. Ideal para pruebas. Para el robot final, se recomienda soldar las conexiones permanentes o usar borneras para mayor seguridad mecánica.

### Buenas prácticas de cableado
- Usa **colores consistentes**: rojo para (+), negro para (−), otros colores para señales.
- Mantén los cables **lo más cortos posible** — los cables largos se enganchan y fallan.
- Agrupa los cables con cinchos cada 5–10 cm.
- Etiqueta los cables si tienes muchos — un trozo de cinta con marcador funciona.

---

## 8. Componentes de Apoyo

**Nivel de dificultad:** Básico

| Componente | Uso |
|-----------|-----|
| **LEDs + resistencias 220Ω** | Indicadores visuales: enciende uno cuando el robot detecta la línea, otro cuando detecta un color. Muy útiles para depurar sin abrir el Monitor Serial. |
| **Resistencias 1kΩ** | Protección en entradas digitales o divisores de voltaje. |
| **Zumbador (opcional)** | Emite un bip cuando el robot cambia de estado — ayuda a saber qué está haciendo sin ver la pantalla. |

> **Tip:** Conecta un LED al pin 13 del Arduino (que tiene LED integrado también) para confirmar que el programa inició correctamente.

---

## 9. Herramientas

**Nivel de dificultad:** Básico–Intermedio

| Herramienta | Para qué se usa | Consejo |
|------------|----------------|---------|
| **Cautín (soldador)** | Soldar cables a borneras, motores o conectores | Calienta 3–5 min antes de usar. La punta debe brillar, no estar negra. |
| **Estaño** | El material que "pega" las soldaduras | Usa poco — una gota del tamaño de un grano de arroz es suficiente. |
| **Esponja húmeda** | Limpiar la punta del cautín | Limpia la punta cada 3–4 soldaduras para que no acumule residuos. |
| **Pinzas** | Sostener cables mientras se suelda | Nunca sostengas cables con los dedos cerca del cautín. |
| **Desarmadores** | Tornillos M3 del chasis | Ten uno Phillips y uno de punta plana. |
| **Multímetro** | Medir voltajes, verificar conexiones | Aprende a medir voltaje DC — te salvará de muchos problemas. |

> ⚠️ **Seguridad con el cautín:**
> - Siempre en la base cuando no lo uses.
> - Nunca lo dejes desatendido encendido.
> - No toques la punta — quema a 350–450°C.
> - Trabaja en un lugar ventilado — el humo de la soldadura irrita.

---

## 10. Elementos Mecánicos

| Elemento | Uso |
|---------|-----|
| **Tornillos M3** | Fijar motores, Arduino, sensores al chasis |
| **Tuercas M3** | Asegurar tornillos desde el otro lado |
| **Separadores (standoffs)** | Elevar el Arduino y el driver para evitar cortocircuitos |
| **Cinta doble cara** | Fijar la batería y la protoboard temporalmente |
| **Cinchos (cable ties)** | Organizar y asegurar los cables |

---

## Guía de Armado Paso a Paso

Sigue este orden para evitar tener que desarmar y rearmar:

### Paso 1 — Prepara el chasis
- [ ] Verifica que el chasis impreso no tenga deformaciones.
- [ ] Instala los insertos de calor (si el diseño los usa) con el cautín a baja temperatura.

### Paso 2 — Instala los motores y la rueda loca
- [ ] Fija los 2 motores TT con tornillos M3.
- [ ] Instala la rueda loca en la posición correcta.
- [ ] Monta las ruedas en los ejes de los motores.
- [ ] Verifica que el robot queda nivelado al ponerlo en el suelo.

### Paso 3 — Monta el Arduino y el driver
- [ ] Coloca separadores de 5–10 mm bajo el Arduino.
- [ ] Fija el Arduino con tornillos M3.
- [ ] Coloca el TB6612FNG cerca del Arduino (reducir longitud de cables de señal).

### Paso 4 — Instala los sensores
- [ ] Fija los sensores IR de línea en sus soportes (3–8 mm del suelo).
- [ ] Fija el sensor IR frontal a la altura de las pelotas.
- [ ] Fija el sensor de color apuntando al suelo (10–20 mm de altura).
- [ ] Verifica que ningún sensor roce el suelo al mover el robot a mano.

### Paso 5 — Sistema de alimentación
- [ ] Instala el regulador LM2596.
- [ ] **Ajusta la salida a 5.0V con el multímetro antes de conectar el Arduino.**
- [ ] Instala el interruptor en el cable positivo de la batería.
- [ ] Fija la batería con cinta doble cara en el lugar más bajo y centrado posible (baja el centro de gravedad).

### Paso 6 — Conexiones eléctricas
- [ ] Conecta GND de batería, Arduino y TB6612FNG al mismo punto (GND común).
- [ ] Conecta la salida 5V del regulador al Arduino.
- [ ] Conecta la batería directamente al pin VM del TB6612FNG.
- [ ] Conecta los motores al TB6612FNG (AO1/AO2 y BO1/BO2).
- [ ] Conecta los pines de control del TB6612FNG al Arduino.
- [ ] Conecta los sensores IR al Arduino (VCC→5V, GND→GND, A0→pin analógico).
- [ ] Conecta el sensor de color por I2C (SDA→A4, SCL→A5).

### Paso 7 — Verificación antes de encender
- [ ] Revisa que ningún cable esté suelto o cruzado.
- [ ] Verifica polaridad de la batería.
- [ ] Comprueba que el regulador está en 5V.
- [ ] Verifica que el pin STBY del TB6612FNG está conectado a 5V.

### Paso 8 — Primera prueba
- [ ] Carga el programa básico (fase 4) desde el Arduino IDE.
- [ ] Enciende el robot y verifica el Monitor Serial.
- [ ] Prueba cada función de movimiento.
- [ ] Si algo no funciona, apaga inmediatamente y revisa conexiones.

---

## Resumen: Nivel de Dificultad por Componente

| Componente | Nivel | ¿Por qué? |
|-----------|-------|-----------|
| Arduino Nano | Básico | Fácil de programar, bien documentado |
| Motores TT + ruedas | Básico | Solo atornillar correctamente |
| Rueda loca | Básico | Solo ajustar altura |
| TB6612FNG | Intermedio | Varios pines, fácil confundir STBY y VM |
| Batería LiPo | Intermedio | Requiere precaución — puede ser peligrosa si se usa mal |
| Regulador LM2596 | Intermedio | Hay que calibrarlo con multímetro |
| Sensores IR (línea) | Básico | Montaje simple, calibración fácil |
| Sensor IR (frontal) | Básico | Igual que los de línea |
| Sensor de color | Intermedio | Requiere librería I2C y calibración cuidadosa |
| Chasis 3D | Básico | Solo ensamblaje mecánico |
| Soldadura | Intermedio | Requiere práctica previa |

---

## Los 10 Errores Más Comunes (y cómo evitarlos)

1. **Conectar motores directo al Arduino** → Quema el Arduino. Siempre usa el driver TB6612FNG.
2. **No calibrar el regulador antes de conectar** → Puede enviar 7.4V al Arduino. Mide con multímetro primero.
3. **GND no compartido entre todos los componentes** → Comportamiento errático. Conecta todos los GND juntos.
4. **STBY del TB6612FNG no conectado** → Motores no giran aunque todo esté bien. Conecta STBY a 5V.
5. **Sensores demasiado lejos del suelo** → No detectan la línea. Mantén 3–8 mm para IR de línea.
6. **Calibrar sensores de color en el salón, no en el campo real** → Falla en competencia. Calibra siempre donde vas a competir.
7. **Cables sueltos** → Fallas intermitentes difíciles de diagnosticar. Asegura todo con cinchos.
8. **Batería LiPo descargada por debajo de 6V** → Daño permanente a la batería. Monitorea el voltaje.
9. **Polaridad invertida en algún componente** → Daño inmediato. Siempre verifica rojo(+) y negro(−).
10. **No probar cada función por separado antes de integrar** → Cuando algo falla, no sabes qué es. Prueba parte por parte.

---

## Kit Mínimo Funcional

Si vas a empezar desde cero, este es el kit mínimo que necesitas para tener un robot que funcione:

| Componente | Cantidad |
|-----------|----------|
| Arduino Nano + cable USB | 1 |
| TB6612FNG | 1 |
| Motores TT + ruedas | 2 |
| Rueda loca | 1 |
| Sensores IR TCRT5000 | 3 (2 línea + 1 frontal) |
| Sensor de color | 1 |
| Batería LiPo 2S + cargador | 1 |
| Regulador LM2596 | 1 |
| Interruptor | 1 |
| Chasis 3D | 1 |
| Cables Dupont y protoboard | Varios |
| Tornillos M3 + tuercas + separadores | 20–30 pcs |
