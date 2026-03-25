# RobotRescue — Documentación Completa: Plan de Implementación

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Crear todos los archivos del repositorio RobotRescue para que los alumnos puedan consultar en GitHub todas las características del reto "Operación Zona Cero".

**Architecture:** Estructura separada `docs/` (markdown) + `src/` (Arduino .ino). Los docs explican conceptos y las actividades; los `.ino` tienen el código base con TODO para que los alumnos completen. No hay tests automatizados — la verificación es manual (confirmar que el archivo existe y contiene todas las secciones requeridas).

**Tech Stack:** Markdown (GitHub Flavored), C++ para Arduino (.ino), Git.

**Spec:** `docs/superpowers/specs/2026-03-25-robotrescue-documentacion-design.md`

---

### Task 1: Scaffold de directorios y archivos vacíos

**Files:**
- Create: `reglamento/` (directorio)
- Create: `docs/` (directorio)
- Create: `src/04-movimiento/` (directorio)
- Create: `src/05-linea/` (directorio)
- Create: `src/06-colores/` (directorio)
- Create: `src/07-victimas/` (directorio)
- Create: `src/08-completo/` (directorio)
- Create: `hardware/diagramas/.gitkeep`
- Create: `recursos/` (directorio)

- [ ] **Paso 1: Crear directorios y el .gitkeep**

```bash
mkdir -p reglamento docs src/04-movimiento src/05-linea src/06-colores src/07-victimas src/08-completo hardware/diagramas recursos
touch hardware/diagramas/.gitkeep
```

- [ ] **Paso 2: Verificar estructura**

```bash
find . -not -path './.git/*' -not -path './docs/superpowers/*' | sort
```

Esperado: todos los directorios creados, `hardware/diagramas/.gitkeep` presente.

- [ ] **Paso 3: Commit**

```bash
git add hardware/diagramas/.gitkeep
git commit -m "chore: scaffold de directorios del proyecto"
```

---

### Task 2: README.md

**Files:**
- Create: `README.md`

- [ ] **Paso 1: Crear README.md**

```markdown
# 🤖 RobotRescue — Operación Zona Cero

Bienvenido al repositorio del reto de robótica autónoma **Operación Zona Cero**.

Tu misión: construir un robot capaz de seguir una línea, navegar obstáculos,
entrar a una zona de evacuación, clasificar víctimas (pelotas) por color y
llevarlas a la zona correcta — todo de forma completamente autónoma.

---

## ¿Por dónde empiezo?

1. Lee [`docs/00-introduccion.md`](docs/00-introduccion.md) para entender el reto completo.
2. Consulta el [Reglamento oficial](reglamento/operacion_zona_cero.md).
3. Sigue las fases en orden — cada una construye sobre la anterior.

---

## Fases del proyecto

| # | Fase | Documento | Código |
|---|------|-----------|--------|
| 0 | Introducción al reto | [📄 Ver](docs/00-introduccion.md) | — |
| 1 | Exploración y fundamentos | [📄 Ver](docs/01-exploracion.md) | — |
| 2 | Diseño y planeación | [📄 Ver](docs/02-diseno.md) | — |
| 3 | Construcción del chasis | [📄 Ver](docs/03-construccion.md) | — |
| 4 | Programación básica de movimiento | [📄 Ver](docs/04-movimiento.md) | [💾 Ver](src/04-movimiento/movimiento.ino) |
| 5 | Seguimiento de línea + GAP | [📄 Ver](docs/05-linea.md) | [💾 Ver](src/05-linea/linea.ino) |
| 6 | Detección de zonas por color | [📄 Ver](docs/06-colores.md) | [💾 Ver](src/06-colores/colores.ino) |
| 7 | Clasificación y empuje de víctimas | [📄 Ver](docs/07-victimas.md) | [💾 Ver](src/07-victimas/victimas.ino) |
| 8 | Misión completa e integración | [📄 Ver](docs/08-integracion.md) | [💾 Ver](src/08-completo/main.ino) |
| 9 | Pruebas, ajuste y competencia | [📄 Ver](docs/09-competencia.md) | — |

---

## Cómo usar este repositorio

```
leer doc de la fase → abrir código base en src/ → construir → probar → iterar
```

Cada documento de fase tiene: objetivos, conceptos, actividades, código base,
preguntas de reflexión y retos opcionales.

---

## Notas importantes

- **Calibra los sensores** en el lugar real de competencia — la iluminación afecta las lecturas.
- **Usa el Monitor Serial** desde la fase 4 como herramienta principal de depuración.
- **Haz commit en GitHub** desde la fase 4 para no perder tu código (`git commit` + `git push`).

---

## Recursos

- 📋 [Reglamento oficial](reglamento/operacion_zona_cero.md)
- 🔧 [Lista de materiales](hardware/lista_materiales.md)
- 📓 [Plantilla de bitácora](recursos/plantilla_bitacora.md)
- ✅ [Checklist de evaluación](recursos/checklist_evaluacion.md)
```

- [ ] **Paso 2: Verificar que el archivo existe y tiene todas las secciones**

Confirmar: tabla de fases con enlaces, notas operativas, sección de recursos.

- [ ] **Paso 3: Commit**

```bash
git add README.md
git commit -m "docs: agrega README principal orientado a alumnos"
```

---

### Task 3: reglamento/operacion_zona_cero.md

**Files:**
- Create: `reglamento/operacion_zona_cero.md`

- [ ] **Paso 1: Crear el reglamento**

```markdown
# Reglamento Oficial — Operación Zona Cero

> Reto de robótica autónoma inspirado en RoboCup Junior Rescue Line.

---

## Secuencia completa de la misión

```
[INICIO]
   ↓
Seguir línea negra sobre fondo blanco
(con curvas, intersecciones, GAP y rampa)
   ↓
Checkpoint 1: Antes de la rampa
   ↓
Subir y bajar rampa → retomar línea
   ↓
Checkpoint 2: Antes de entrar a zona de evacuación
   ↓
Detectar zona VERDE → Entrar
   ↓
Buscar víctimas (pelotas ~5 cm)
  • Pelota blanca (viva)  → empujar completamente a zona AZUL
  • Pelota negra  (muerta)→ empujar completamente a zona AMARILLA
  • Priorizar víctimas blancas (+5 pts bonus)
   ↓
Detectar línea ROJA → Salir completamente
   ↓
Checkpoint 3: Al salir de zona de evacuación
   ↓
Retomar línea negra
   ↓
Cruzar línea MORADA completamente → [FIN]
```

---

## Colores del campo

| Color | Significado | Acción del robot |
|-------|-------------|-----------------|
| Negro (línea, ~2 cm) | Camino principal | Seguir |
| Verde | Entrada zona de evacuación | Entrar |
| Azul | Zona víctimas vivas | Depositar víctimas blancas |
| Amarillo | Zona víctimas muertas | Depositar víctimas negras |
| Rojo | Salida zona de evacuación | Salir (cruzar completo) |
| Morado | Meta final | Detenerse (cruzar completo) |

---

## Características del campo

- **Línea:** negra, ~2 cm de ancho (cinta de aislar), sobre fondo blanco mate.
- **GAP:** sección donde la línea desaparece temporalmente. El robot debe inferir la trayectoria y reencontrar la línea.
- **Rampa:** el robot debe subir y descender una pendiente sin perder la línea ni desestabilizarse.
- **Superficie:** mate, no reflejante.
- **Iluminación:** constante y controlada durante la competencia.

---

## Puntos de Control (Checkpoints)

| # | Ubicación | Propósito |
|---|-----------|-----------|
| CP1 | Antes de la rampa | Reinicio si falla en rampa |
| CP2 | Antes de zona de evacuación | Reinicio si falla al entrar |
| CP3 | Al salir de zona de evacuación | Reinicio si falla al retomar línea |

- Máximo **3 reinicios** por intento.
- Al reiniciar: robot colocado manualmente alineado en el checkpoint.

---

## Sistema de Evaluación

### Puntaje por criterio (máximo 100 pts)

| Criterio | Puntos |
|---------|--------|
| **Navegación** | **30** |
| — Seguimiento de línea | 15 |
| — Detección de zona verde | 5 |
| — Entrada correcta | 10 |
| **Evacuación** | **40** |
| — Detección de víctimas | 10 |
| — Control/empuje | 10 |
| — Depósito en zona correcta | 20 (máx 10 si zona incorrecta) |
| **Detección y Lógica** | **20** |
| — Detección de colores | 10 |
| — Toma de decisiones | 10 |
| **Finalización** | **10** |
| — Salida por zona roja | 5 |
| — Llegar al punto final | 5 |
| **Bonificaciones** | **+10 máx** |
| — Clasificar todas las víctimas correctamente | +5 |
| — Priorizar víctimas blancas | +5 |

### Penalizaciones

| Situación | Penalización |
|-----------|-------------|
| Reinicio desde checkpoint | -5 pts c/u |
| Salirse de la pista | -5 pts |
| No completar una etapa | Se pierde puntaje de esa etapa |

### Escala de desempeño

| Puntaje | Nivel |
|---------|-------|
| 90–100 | Excelente |
| 80–89 | Muy Bueno |
| 70–79 | Aceptable |
| < 70 | Insuficiente |

---

## Tiempo límite

- **5 minutos** por intento.
- Se evalúa el avance logrado al detenerse el tiempo.

---

## Criterios de desempate

En caso de empate, se aplican estos criterios en orden:

1. Mayor número de víctimas correctamente clasificadas.
2. Menor número de reinicios.
3. Menor tiempo de ejecución.

---

## Restricciones Técnicas

- Tamaño máximo: **15 cm × 15 cm** en la base (sin límite de altura).
- El robot debe caber completamente en esas dimensiones al inicio.
- Sensores permitidos: IR, Color, Ultrasónico.
- Sin garra, succión ni mecanismos que deformen las pelotas.
- Empuje frontal recomendado.
- Operación **100% autónoma** — sin control remoto, sin mapas precargados.

---

## Definiciones Oficiales de Validez

| Acción | Condición para considerarse válida |
|--------|----------------------------------|
| Detección de víctima | El robot modifica su comportamiento al detectarla |
| Depósito correcto | Pelota **completamente** dentro de la zona, sin contacto con el robot |
| Salida de evacuación | Robot cruza **completamente** la línea roja |
| Finalización | Robot cruza **completamente** la línea morada |
```

- [ ] **Paso 2: Verificar secciones presentes**

Confirmar que el archivo contiene: secuencia de misión, colores, GAP/rampa, checkpoints, puntaje, penalizaciones, escala, tiempo límite, desempate, restricciones, validez.

- [ ] **Paso 3: Commit**

```bash
git add reglamento/operacion_zona_cero.md
git commit -m "docs: agrega reglamento oficial completo"
```

---

### Task 4: docs/00-introduccion.md

**Files:**
- Create: `docs/00-introduccion.md`

- [ ] **Paso 1: Crear el archivo**

```markdown
# Introducción — Operación Zona Cero

## ¿Qué es este reto?

**Operación Zona Cero** es un reto de robótica autónoma donde construirás
un robot capaz de navegar un circuito, detectar zonas por color, clasificar
víctimas y completar una misión de rescate — todo sin intervención humana.

El reto está inspirado en **RoboCup Junior Rescue Line**, una competencia
internacional de robótica educativa.

---

## La misión completa

```
[INICIO]
   ↓
Seguir línea negra sobre fondo blanco
(con curvas, intersecciones, GAP y rampa)
   ↓
Subir y bajar rampa → retomar línea
   ↓
Detectar zona VERDE → Entrar a zona de evacuación
   ↓
Buscar víctimas (pelotas ~5 cm)
  • Blanca (viva)  → empujar a zona AZUL
  • Negra  (muerta)→ empujar a zona AMARILLA
   ↓
Detectar línea ROJA → Salir de zona de evacuación
   ↓
Retomar línea negra
   ↓
Cruzar línea MORADA completamente → [FIN]
```

---

## Mapa del campo

| Zona / Elemento | Color | Qué hace el robot |
|----------------|-------|-------------------|
| Línea de navegación | Negro (~2 cm) | La sigue |
| GAP | Sin línea | Avanza recto y busca la línea |
| Rampa | — | Sube y baja ajustando velocidad |
| Zona de evacuación | Verde (entrada) | Entra al detectarlo |
| Depósito vivas | Azul | Empuja víctimas blancas aquí |
| Depósito muertas | Amarillo | Empuja víctimas negras aquí |
| Salida evacuación | Rojo | Sale al cruzarlo completamente |
| Meta final | Morado | Se detiene al cruzarlo |

---

## Arquitectura de software: Máquina de estados

El robot decide qué hacer según su **estado actual**:

```
SEGUIR_LINEA
    ↓ (detecta verde)
ENTRAR_EVACUACION
    ↓
BUSCAR_VICTIMAS  ←──────────────┐
    ↓ (detecta pelota)          │
CLASIFICAR_VICTIMA              │
    ↓ (empuja)                  │
VOLVER_A_BUSCAR ────────────────┘
    ↓ (detecta rojo)
SALIR_EVACUACION
    ↓
SEGUIR_LINEA (hasta morado)
    ↓
MISION_COMPLETADA
```

En cada ciclo del `loop()`, el robot lee sus sensores y actúa según el estado en que se encuentre.

---

## Cómo navegar este repositorio

| Carpeta | Contenido |
|---------|-----------|
| `docs/` | Documentación de cada fase (léela primero) |
| `src/` | Código base Arduino por fase (ábrelo después) |
| `reglamento/` | Reglas oficiales del reto |
| `hardware/` | Lista de materiales y diagramas |
| `recursos/` | Bitácora y checklist de evaluación |

**Flujo de trabajo recomendado:**
1. Lee el doc de la fase.
2. Abre el código base en `src/`.
3. Completa los `TODO`.
4. Prueba en el robot.
5. Haz `git commit` para guardar tu progreso.

---

## Glosario

| Término | Significado |
|---------|-------------|
| **GAP** | Interrupción temporal de la línea negra; el robot debe inferir la dirección |
| **Checkpoint** | Punto de reinicio si el robot falla; hay 3 en el circuito |
| **Zona de evacuación** | Área delimitada donde se encuentran y clasifican las víctimas |
| **Víctima** | Pelota de ~5 cm; blanca = viva, negra = muerta |
| **Máquina de estados** | Lógica de control donde el robot tiene un "estado actual" y reglas para cambiar de estado |
| **Monitor Serial** | Herramienta del IDE de Arduino para ver mensajes de depuración en tiempo real |
```

- [ ] **Paso 2: Verificar secciones**

Confirmar: descripción, secuencia de misión, mapa del campo, máquina de estados, navegación del repo, glosario.

- [ ] **Paso 3: Commit**

```bash
git add docs/00-introduccion.md
git commit -m "docs: agrega introducción al reto y guía del repositorio"
```

---

### Task 5: docs/01-exploracion.md, docs/02-diseno.md, docs/03-construccion.md

**Files:**
- Create: `docs/01-exploracion.md`
- Create: `docs/02-diseno.md`
- Create: `docs/03-construccion.md`

- [ ] **Paso 1: Crear docs/01-exploracion.md**

```markdown
# 01 — Exploración y Fundamentos

## Objetivo

Comprender el reto completo, investigar los componentes del robot y
establecer el equipo de trabajo.

---

## Conceptos clave

- **Robótica autónoma:** sistema que toma decisiones sin intervención humana.
- **Sensor:** dispositivo que detecta información del entorno (luz, distancia, color).
- **Actuador:** dispositivo que produce movimiento o acción (motor, servo).
- **Microcontrolador:** "cerebro" del robot; ejecuta el programa (Arduino Uno/Mega).
- **Bucle de control:** ciclo continuo de leer sensores → decidir → actuar.

---

## Material necesario

- Computadora con acceso a internet
- Cuenta en GitHub (crear si no tienen)
- Arduino IDE instalado
- Componentes del kit (para inspección visual, no se arma aún)

---

## Actividades

1. Lee el [reglamento oficial](../reglamento/operacion_zona_cero.md) completo.
2. Identifica cada componente de tu kit: ¿qué es? ¿para qué sirve?
3. Investiga: ¿cómo funciona un sensor IR TCRT5000?
4. Investiga: ¿cómo funciona un sensor de color TCS34725?
5. Dibuja (en papel) cómo imaginas el robot terminado.
6. Define los roles del equipo: programador, ensamblador, documentador.
7. Crea el repositorio en GitHub y clona en tu computadora.

---

## Código base

No aplica — esta fase es de investigación y planeación.

---

## Preguntas de reflexión

1. ¿Cuál es la diferencia entre un sensor IR y un sensor de color? ¿Cuándo usarías cada uno?
2. ¿Por qué el robot no puede usar control remoto durante la competencia?
3. ¿Qué pasaría si el robot no tiene ningún sensor? ¿Podría completar la misión?
4. ¿Cuál crees que será la parte más difícil del reto? ¿Por qué?
5. ¿Qué información necesita el robot para saber en qué "estado" de la misión se encuentra?

---

## Retos opcionales

1. Busca un video de RoboCup Junior Rescue Line y anota 3 estrategias que observes en los robots ganadores.
2. Investiga qué es un controlador PID y explica con tus palabras para qué podría servir en este reto.
3. Diseña en papel el diagrama de flujo completo de la misión (antes de ver la solución en `docs/00-introduccion.md`).

---

## Checklist de la fase

- [ ] Reglamento leído y comprendido
- [ ] Todos los componentes del kit identificados
- [ ] Sensores IR y de color investigados
- [ ] Boceto del robot dibujado
- [ ] Roles del equipo definidos
- [ ] Repositorio de GitHub creado y clonado
- [ ] Preguntas de reflexión respondidas en la bitácora
```

- [ ] **Paso 2: Crear docs/02-diseno.md**

```markdown
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
```

- [ ] **Paso 3: Crear docs/03-construccion.md**

```markdown
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
```

- [ ] **Paso 4: Verificar las 3 secciones**

Confirmar que cada archivo tiene las 9 secciones definidas en el spec (sin "Duración estimada").

- [ ] **Paso 5: Commit**

```bash
git add docs/01-exploracion.md docs/02-diseno.md docs/03-construccion.md
git commit -m "docs: agrega documentación de fases 1-3 (exploración, diseño, construcción)"
```

---

### Task 6: docs/04-movimiento.md + src/04-movimiento/movimiento.ino

**Files:**
- Create: `docs/04-movimiento.md`
- Create: `src/04-movimiento/movimiento.ino`

- [ ] **Paso 1: Crear docs/04-movimiento.md**

```markdown
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
```

- [ ] **Paso 2: Crear src/04-movimiento/movimiento.ino**

```cpp
// ============================================================
// RobotRescue — Operación Zona Cero
// 04: Programación Básica de Movimiento
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc en docs/04-movimiento.md
// 2. Completa las secciones marcadas con TODO
// 3. Prueba cada función por separado antes de continuar
// ============================================================

// --- Pines del driver de motores ---
// Motor izquierdo
const int PIN_MOT_IZQ_EN  = 5;   // Enable (PWM velocidad)
const int PIN_MOT_IZQ_IN1 = 4;   // Dirección 1
const int PIN_MOT_IZQ_IN2 = 3;   // Dirección 2

// Motor derecho
const int PIN_MOT_DER_EN  = 6;   // Enable (PWM velocidad)
const int PIN_MOT_DER_IN1 = 7;   // Dirección 1
const int PIN_MOT_DER_IN2 = 8;   // Dirección 2

// --- Configuración de velocidad ---
const int VELOCIDAD = 180;        // 0–255; ajusta hasta que el movimiento sea controlado

// ============================================================
void setup() {
  Serial.begin(9600);
  Serial.println("RobotRescue - Fase 4: Movimiento iniciado");

  pinMode(PIN_MOT_IZQ_EN,  OUTPUT);
  pinMode(PIN_MOT_IZQ_IN1, OUTPUT);
  pinMode(PIN_MOT_IZQ_IN2, OUTPUT);
  pinMode(PIN_MOT_DER_EN,  OUTPUT);
  pinMode(PIN_MOT_DER_IN1, OUTPUT);
  pinMode(PIN_MOT_DER_IN2, OUTPUT);
}

// ============================================================
void loop() {
  Serial.println("Avanzando...");
  adelante();
  delay(1000);

  Serial.println("Parando...");
  parar();
  delay(500);

  // TODO: Llama a las demás funciones de movimiento aquí
  // (atras, izquierda, derecha) con delay entre cada una
  // para probarlas una por una.
}

// ============================================================
// FUNCIÓN COMPLETA (úsala como referencia para las demás)
// ============================================================

// Hace avanzar el robot hacia adelante
void adelante() {
  analogWrite(PIN_MOT_IZQ_EN, VELOCIDAD);
  digitalWrite(PIN_MOT_IZQ_IN1, HIGH);
  digitalWrite(PIN_MOT_IZQ_IN2, LOW);

  analogWrite(PIN_MOT_DER_EN, VELOCIDAD);
  digitalWrite(PIN_MOT_DER_IN1, HIGH);
  digitalWrite(PIN_MOT_DER_IN2, LOW);
}

// ============================================================
// FUNCIONES CON TODO — COMPLETA EL CUERPO
// ============================================================

// Hace retroceder el robot
// Pista: invierte las señales IN1 e IN2 respecto a adelante()
void atras() {
  // TODO: implementa esta función
}

// Gira el robot a la izquierda (motor izq atrás, motor der adelante)
void izquierda() {
  // TODO: implementa esta función
}

// Gira el robot a la derecha (motor izq adelante, motor der atrás)
void derecha() {
  // TODO: implementa esta función
}

// Detiene ambos motores
// Pista: analogWrite con valor 0 detiene el motor
void parar() {
  // TODO: implementa esta función
}
```

- [ ] **Paso 3: Verificar archivos**

Confirmar: doc tiene 9 secciones, `.ino` tiene 1 función completa y 4 con TODO.

- [ ] **Paso 4: Commit**

```bash
git add docs/04-movimiento.md src/04-movimiento/movimiento.ino
git commit -m "docs: agrega fase 4 — movimiento básico (doc + código base)"
```

---

### Task 7: docs/05-linea.md + src/05-linea/linea.ino

**Files:**
- Create: `docs/05-linea.md`
- Create: `src/05-linea/linea.ino`

- [ ] **Paso 1: Crear docs/05-linea.md**

```markdown
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
```

- [ ] **Paso 2: Crear src/05-linea/linea.ino**

```cpp
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
```

- [ ] **Paso 3: Verificar archivos**

Confirmar: doc tiene diagrama de flujo, `.ino` tiene 1 función completa + 2 con TODO.

- [ ] **Paso 4: Commit**

```bash
git add docs/05-linea.md src/05-linea/linea.ino
git commit -m "docs: agrega fase 5 — seguimiento de línea y GAP (doc + código base)"
```

---

### Task 8: docs/06-colores.md + src/06-colores/colores.ino

**Files:**
- Create: `docs/06-colores.md`
- Create: `src/06-colores/colores.ino`

- [ ] **Paso 1: Crear docs/06-colores.md**

```markdown
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
```

- [ ] **Paso 2: Crear src/06-colores/colores.ino**

```cpp
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
```

- [ ] **Paso 3: Verificar archivos**

Confirmar: doc tiene diagrama de flujo, `.ino` tiene 1 función completa + mínimo 2 con TODO.

- [ ] **Paso 4: Commit**

```bash
git add docs/06-colores.md src/06-colores/colores.ino
git commit -m "docs: agrega fase 6 — detección de zonas por color (doc + código base)"
```

---

### Task 9: docs/07-victimas.md + src/07-victimas/victimas.ino

**Files:**
- Create: `docs/07-victimas.md`
- Create: `src/07-victimas/victimas.ino`

- [ ] **Paso 1: Crear docs/07-victimas.md**

```markdown
# 07 — Clasificación y Empuje de Víctimas

## Objetivo

Programar el robot para detectar víctimas (pelotas ~5 cm) con el sensor
ultrasónico, clasificarlas por color y empujarlas a la zona correcta.

---

## Conceptos clave

- **Sensor HC-SR04:** emite un pulso ultrasónico y mide el tiempo de retorno para calcular distancia. Fórmula: `distancia (cm) = duracion / 58`.
- **`pulseIn(pin, HIGH)`:** mide la duración de un pulso en microsegundos.
- **Estrategia de empuje:** el robot avanza hacia la pelota hasta empujarla completamente dentro de la zona objetivo. La pelota no debe quedar en contacto con el robot al terminar.
- **Zona azul:** destino de víctimas blancas (vivas). Zona amarilla: destino de víctimas negras (muertas).

---

## Material necesario

- Robot con sensor ultrasónico y sensor de color instalados
- Pelotas blancas y negras de ~5 cm
- Zona de evacuación de prueba (cartulinas de colores)
- Código base: [`src/07-victimas/victimas.ino`](../src/07-victimas/victimas.ino)

---

## Actividades

1. Abre `victimas.ino` y revisa la función `medirDistancia()` ya implementada.
2. Prueba en el Monitor Serial: ¿a qué distancia detecta el robot una pelota?
3. Define la constante `DIST_VICTIMA`: la distancia a la que se considera que hay una víctima.
4. Completa la función `detectarColorPelota()` para distinguir blanca/negra.
5. Completa la función `empujarAZonaAzul()` para víctimas blancas.
6. Completa la función `empujarAZonaAmarilla()` para víctimas negras.
7. Prueba el ciclo completo: detectar → clasificar → empujar → regresar a buscar.

---

## Código base

[`src/07-victimas/victimas.ino`](../src/07-victimas/victimas.ino)

---

## Diagrama de flujo — Búsqueda y clasificación de víctimas

```
BUSCAR_VICTIMAS
  │
  ▼
medirDistancia()
  │
  ▼
¿distancia < DIST_VICTIMA?
  │
  ├─ NO  ──► girar buscando (continuar loop)
  │
  └─ SÍ  ──► detectarColorPelota()
                  │
                  ├─ "BLANCO" ──► empujarAZonaAzul()    → volver a BUSCAR
                  └─ "NEGRO"  ──► empujarAZonaAmarilla() → volver a BUSCAR
```

---

## Preguntas de reflexión

1. ¿Por qué el sensor ultrasónico puede dar lecturas erróneas con superficies muy inclinadas o muy pequeñas?
2. ¿Qué pasaría si el robot empuja la pelota pero no sale completamente de la zona? ¿Se cuenta el punto?
3. ¿Cómo decides cuándo el robot ha "terminado" de empujar? ¿Usas tiempo, distancia o detección de color de zona?
4. Si hay 2 pelotas en la zona de evacuación, ¿en qué orden las atendería tu robot? ¿Importa el orden?
5. ¿Cómo priorizarías víctimas blancas sobre negras sin desperdiciar tiempo?

---

## Retos opcionales

1. Implementa una estrategia de búsqueda sistemática (en espiral o en zigzag) en lugar de giro aleatorio.
2. Lleva un conteo de víctimas depositadas y muéstralo en el Monitor Serial.
3. Implementa la prioridad de víctimas blancas: si el robot detecta una negra y hay indicios de una blanca cerca, pospone la negra.

---

## Checklist de la fase

- [ ] `medirDistancia()` probada y DIST_VICTIMA definida
- [ ] `detectarColorPelota()` implementada (distingue blanca/negra)
- [ ] `empujarAZonaAzul()` implementada y probada
- [ ] `empujarAZonaAmarilla()` implementada y probada
- [ ] Ciclo completo probado con ambos tipos de víctimas
- [ ] Pelota queda completamente dentro de la zona al terminar
- [ ] Código guardado con `git commit`
- [ ] Preguntas de reflexión respondidas en la bitácora
```

- [ ] **Paso 2: Crear src/07-victimas/victimas.ino**

```cpp
// ============================================================
// RobotRescue — Operación Zona Cero
// 07: Clasificación y Empuje de Víctimas
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc en docs/07-victimas.md
// 2. Completa las secciones marcadas con TODO
// 3. Prueba medirDistancia() primero antes de integrar todo
// ============================================================

#include <Wire.h>
#include <Adafruit_TCS34725.h>

// --- Pines sensor ultrasónico HC-SR04 ---
const int PIN_TRIG = 9;
const int PIN_ECHO = 10;

// --- Pines motores (igual que fases anteriores) ---
const int PIN_MOT_IZQ_EN  = 5;
const int PIN_MOT_IZQ_IN1 = 4;
const int PIN_MOT_IZQ_IN2 = 3;
const int PIN_MOT_DER_EN  = 6;
const int PIN_MOT_DER_IN1 = 7;
const int PIN_MOT_DER_IN2 = 8;

// --- Sensor de color ---
Adafruit_TCS34725 sensorColor = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X
);

// --- Configuración ---
const int VELOCIDAD     = 150;
const int DIST_VICTIMA  = 10;  // cm — ajusta según tus pruebas

// ============================================================
void setup() {
  Serial.begin(9600);
  Serial.println("RobotRescue - Fase 7: Clasificación de víctimas iniciada");

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(PIN_MOT_IZQ_EN,  OUTPUT);
  pinMode(PIN_MOT_IZQ_IN1, OUTPUT);
  pinMode(PIN_MOT_IZQ_IN2, OUTPUT);
  pinMode(PIN_MOT_DER_EN,  OUTPUT);
  pinMode(PIN_MOT_DER_IN1, OUTPUT);
  pinMode(PIN_MOT_DER_IN2, OUTPUT);

  sensorColor.begin();
}

// ============================================================
void loop() {
  float dist = medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist < DIST_VICTIMA) {
    String tipoPelota = detectarColorPelota();
    Serial.print("Víctima detectada: ");
    Serial.println(tipoPelota);

    // TODO: según el tipo de pelota, llama a la función de empuje correspondiente
  }

  delay(100);
}

// ============================================================
// FUNCIÓN COMPLETA (úsala como referencia)
// ============================================================

// Mide la distancia en cm usando el sensor ultrasónico HC-SR04
float medirDistancia() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long duracion = pulseIn(PIN_ECHO, HIGH);
  float distancia = duracion / 58.0;
  return distancia;
}

// ============================================================
// FUNCIONES CON TODO — COMPLETA EL CUERPO
// ============================================================

// Devuelve "BLANCO" si la pelota es blanca (viva) o "NEGRO" si es negra (muerta)
// Pista: usa el sensor de color — una pelota blanca refleja mucho en todos los canales,
//        una pelota negra absorbe la luz (valores bajos en todos los canales)
String detectarColorPelota() {
  // TODO: implementa esta función
  return "DESCONOCIDO";
}

// Empuja la víctima blanca completamente hacia la zona AZUL
// La pelota debe quedar dentro de la zona sin contacto con el robot al terminar
void empujarAZonaAzul() {
  Serial.println("Empujando víctima blanca a zona AZUL...");
  // TODO: implementa la secuencia de movimiento para llevar la pelota a la zona azul
}

// Empuja la víctima negra completamente hacia la zona AMARILLA
void empujarAZonaAmarilla() {
  Serial.println("Empujando víctima negra a zona AMARILLA...");
  // TODO: implementa la secuencia de movimiento para llevar la pelota a la zona amarilla
}
```

- [ ] **Paso 3: Verificar archivos**

Confirmar: doc tiene diagrama de flujo, `.ino` tiene 1 función completa + 3 con TODO.

- [ ] **Paso 4: Commit**

```bash
git add docs/07-victimas.md src/07-victimas/victimas.ino
git commit -m "docs: agrega fase 7 — clasificación y empuje de víctimas (doc + código base)"
```

---

### Task 10: docs/08-integracion.md + src/08-completo/main.ino

**Files:**
- Create: `docs/08-integracion.md`
- Create: `src/08-completo/main.ino`

- [ ] **Paso 1: Crear docs/08-integracion.md**

```markdown
# 08 — Misión Completa e Integración

## Objetivo

Integrar todas las fases anteriores en un único programa que ejecute
la misión completa de forma autónoma usando una máquina de estados.

---

## Conceptos clave

- **Integración:** proceso de combinar módulos independientes en un sistema funcional.
- **Máquina de estados finita (FSM):** modelo de control con estados definidos, transiciones y acciones. Cada estado tiene una condición de entrada y una condición de salida.
- **Variable de estado:** almacena el estado actual del robot (`estadoActual`).
- **Depuración de integración:** los errores más comunes al integrar son variables con el mismo nombre, pines en conflicto y lógica de transición incorrecta.

---

## Material necesario

- Robot completamente ensamblado y probado por fases
- Pista de prueba completa (con línea, GAP, rampa y zona de evacuación)
- Código base: [`src/08-completo/main.ino`](../src/08-completo/main.ino)

---

## Actividades

1. Abre `main.ino` y estudia la estructura de la máquina de estados ya definida.
2. Copia las funciones ya implementadas de las fases anteriores al archivo.
3. Completa las transiciones entre estados en el `switch` de `loop()`.
4. Completa las funciones de evacuación que tienen TODO.
5. Prueba cada transición por separado: empieza en el estado que quieras probar.
6. Prueba la misión completa de inicio a fin.
7. Ajusta los parámetros hasta completar la misión de forma consistente.

---

## Código base

[`src/08-completo/main.ino`](../src/08-completo/main.ino)

---

## Diagrama de flujo — Máquina de estados completa

```
[INICIO] → estadoActual = SEGUIR_LINEA
  │
  ▼
SEGUIR_LINEA
  │ detectarColor() == "VERDE"
  ▼
ENTRAR_EVACUACION
  │ robot dentro de la zona
  ▼
BUSCAR_VICTIMAS ←──────────────────────┐
  │ medirDistancia() < DIST_VICTIMA    │
  ▼                                    │
CLASIFICAR_VICTIMA                     │
  │ detectarColorPelota()              │
  ├─ BLANCO → empujarAZonaAzul()      │
  └─ NEGRO  → empujarAZonaAmarilla()  │
  │ empuje completado                  │
  └───────────────────────────────────┘
  │ detectarColor() == "ROJO"
  ▼
SALIR_EVACUACION
  │ robot fuera completamente
  ▼
SEGUIR_LINEA
  │ detectarColor() == "MORADO"
  ▼
MISION_COMPLETADA → parar()
```

---

## Preguntas de reflexión

1. ¿Qué pasa si el robot se queda atascado en un estado? ¿Cómo lo detectarías y lo resolverías?
2. ¿Por qué es importante probar cada transición por separado antes de probar la misión completa?
3. ¿Qué harías si el robot detecta "VERDE" mientras está en el estado `SALIR_EVACUACION`? ¿Es un error o debe manejarse?
4. ¿Cómo usarías el Monitor Serial para saber en qué estado está el robot en cada momento?
5. ¿Qué criterios usarías para decidir si el robot está listo para competir?

---

## Retos opcionales

1. Agrega un estado `MANEJAR_RAMPA` que ajuste la velocidad al detectar un cambio en la inclinación del robot.
2. Implementa un temporizador de seguridad: si el robot pasa más de 30 segundos en el estado `BUSCAR_VICTIMAS` sin encontrar nada, transiciona a `SALIR_EVACUACION`.
3. Agrega una rutina de inicio: el robot espera 3 segundos antes de iniciar para que el juez pueda retirarse.

---

## Checklist de la fase

- [ ] Todas las funciones de fases anteriores integradas en `main.ino`
- [ ] Todos los estados de la máquina implementados
- [ ] Todas las transiciones probadas individualmente
- [ ] Misión completa ejecutada de inicio a fin al menos 3 veces
- [ ] Monitor Serial muestra el estado actual en cada cambio
- [ ] Código guardado con `git commit`
- [ ] Preguntas de reflexión respondidas en la bitácora
```

- [ ] **Paso 2: Crear src/08-completo/main.ino**

```cpp
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
```

- [ ] **Paso 3: Verificar archivos**

Confirmar: doc tiene el diagrama de estados completo, `main.ino` tiene todos los estados definidos, 2 funciones completas y el resto con TODO.

- [ ] **Paso 4: Commit**

```bash
git add docs/08-integracion.md src/08-completo/main.ino
git commit -m "docs: agrega fase 8 — misión completa con máquina de estados (doc + código base)"
```

---

### Task 11: docs/09-competencia.md

**Files:**
- Create: `docs/09-competencia.md`

- [ ] **Paso 1: Crear docs/09-competencia.md**

```markdown
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
```

- [ ] **Paso 2: Verificar archivo**

Confirmar que el archivo tiene las 9 secciones y que "Código base" apunta a `src/08-completo/main.ino`.

- [ ] **Paso 3: Commit**

```bash
git add docs/09-competencia.md
git commit -m "docs: agrega fase 9 — pruebas, ajuste y competencia"
```

---

### Task 12: hardware/lista_materiales.md + hardware/diagramas/.gitkeep

**Files:**
- Create: `hardware/lista_materiales.md`
- Verify: `hardware/diagramas/.gitkeep` (creado en Task 1)

- [ ] **Paso 1: Crear hardware/lista_materiales.md**

```markdown
# Lista de Materiales — RobotRescue

## Componentes principales

| Componente | Modelo sugerido | Cantidad | Notas |
|-----------|----------------|----------|-------|
| Microcontrolador | Arduino Uno o Mega | 1 | El Mega tiene más pines y memoria; recomendado si se agregan sensores extra |
| Motores DC | Motor N20 (150–300 RPM) o TT Motor | 2 | Los N20 son más pequeños y precisos; los TT son más baratos y fáciles de montar |
| Driver de motores | L298N o TB6612FNG | 1 | El TB6612FNG es más eficiente y compacto; el L298N es más común y barato |
| Sensores IR | TCRT5000 | 5 | Mínimo 3; con 5 se maneja mejor el GAP. Montar a 3–8 mm del suelo |
| Sensor de color | TCS34725 o TCS3200 | 1 | El TCS34725 usa I2C y es más preciso. Montar apuntando al suelo al frente |
| Sensor ultrasónico | HC-SR04 | 1 | Montar horizontal al frente, centrado, a la altura aproximada de las pelotas |
| Batería | LiPo 7.4V 1000mAh o 4× AA | 1 | El LiPo da más autonomía; las AA son más seguras para principiantes |
| Chasis | Acrílico cortado o impreso en 3D | 1 | Máximo 15×15 cm de base. Diseñar en la fase 2 |
| Ruedas | Compatible con motores elegidos | 2 + 1 loca | La rueda loca va en la parte trasera para equilibrio |
| Cables dupont | Macho-hembra y macho-macho | 40+ | Varios colores para identificar conexiones |

## Componentes opcionales / recomendados

| Componente | Modelo sugerido | Cantidad | Notas |
|-----------|----------------|----------|-------|
| Módulo regulador | LM2596 o MT3608 | 1 | Para estabilizar el voltaje a los sensores si se usa LiPo |
| LED indicador | LED 5mm (cualquier color) + resistencia 220Ω | 1 | Para indicar estado encendido/apagado |
| Interruptor | Switch SPDT o DPDT | 1 | Para encender/apagar sin desconectar la batería |
| Soporte PCB | Separadores de nylon M3 | 8+ | Para montar el Arduino y el driver de forma segura |

## Disposición de sensores

### Sensores IR (TCRT5000)
- **Altura del suelo:** 3–8 mm. Si están muy lejos, pierden sensibilidad; si están muy cerca, pueden rozar el suelo.
- **Separación entre sensores:** el sensor central debe estar sobre la línea. Los demás se distribuyen simétricamente.
- **Para el GAP:** los sensores extremos (izq_ext y der_ext) deben estar más separados que los demás — ayudan a detectar la línea cuando el robot se desvía al cruzar el GAP.

### Sensor de color (TCS34725)
- Montar apuntando **perpendicular al suelo**, al frente del robot.
- Distancia al suelo: **10–20 mm** para una lectura estable.
- Evitar que reciba luz directa de lámparas u otras fuentes (puede causar saturación).

### Sensor ultrasónico (HC-SR04)
- Montar **horizontal**, centrado al frente.
- Altura: a la **altura de las pelotas** (~5 cm del suelo).
- El cono de detección es de ~15°; objetos fuera de ese ángulo no serán detectados.

## Diagramas de conexión

Los diagramas de conexión electrónica se agregarán en `hardware/diagramas/`.
```

- [ ] **Paso 2: Verificar que `.gitkeep` existe**

```bash
ls hardware/diagramas/
```

- [ ] **Paso 3: Commit**

```bash
git add hardware/lista_materiales.md
git commit -m "docs: agrega lista de materiales con notas de disposición de sensores"
```

---

### Task 13: recursos/plantilla_bitacora.md + recursos/checklist_evaluacion.md

**Files:**
- Create: `recursos/plantilla_bitacora.md`
- Create: `recursos/checklist_evaluacion.md`

- [ ] **Paso 1: Crear recursos/plantilla_bitacora.md**

```markdown
# Plantilla de Bitácora — RobotRescue

> Copia esta plantilla para cada sesión de trabajo. Una bitácora bien llevada
> es evidencia de tu proceso de aprendizaje y te ayudará en la presentación final.

---

## Sesión #___

**Fecha:** ____________________
**Fase del proyecto:** ____________________
**Integrantes presentes:** ____________________

---

### Objetivo de la sesión

¿Qué querían lograr hoy?

> _Escribe aquí_

---

### Actividades realizadas

¿Qué hicieron paso a paso?

1.
2.
3.

---

### Problemas encontrados

¿Qué no funcionó como esperaban? (Sin problema es sospechoso — el aprendizaje viene del error)

| Problema | Síntoma observado |
|----------|-------------------|
|  |  |
|  |  |

---

### Soluciones aplicadas

¿Cómo resolvieron cada problema?

| Problema | Solución intentada | ¿Funcionó? |
|----------|-------------------|------------|
|  |  | Sí / No / Parcialmente |
|  |  | Sí / No / Parcialmente |

---

### Aprendizajes

¿Qué aprendieron hoy que no sabían antes?

-
-

---

### Próximos pasos

¿Qué harán en la siguiente sesión?

- [ ]
- [ ]
- [ ]

---

### Commits realizados

| Descripción del commit | Hash (últimos 7 caracteres) |
|------------------------|---------------------------|
|  |  |
|  |  |
```

- [ ] **Paso 2: Crear recursos/checklist_evaluacion.md**

```markdown
# Checklist de Evaluación — Operación Zona Cero

> Usa esta lista antes de competir para estimar tu puntaje y detectar áreas de mejora.
> Marca con ✅ lo que ya funciona de forma **consistente** (al menos 8 de 10 intentos).

---

## Navegación — 30 pts

| # | Criterio | Pts | Estado |
|---|----------|-----|--------|
| 1 | El robot sigue la línea negra sin salirse en rectas | 5 | ☐ |
| 2 | El robot sigue la línea negra en curvas | 5 | ☐ |
| 3 | El robot cruza el GAP y retoma la línea | 5 | ☐ |
| 4 | El robot detecta la zona verde | 5 | ☐ |
| 5 | El robot entra correctamente a la zona de evacuación | 10 | ☐ |

**Subtotal estimado: ___ / 30**

---

## Evacuación — 40 pts

| # | Criterio | Pts | Estado |
|---|----------|-----|--------|
| 6 | El robot detecta una víctima (modifica su comportamiento) | 10 | ☐ |
| 7 | El robot empuja la víctima sin aplastarla | 10 | ☐ |
| 8 | La pelota queda **completamente** dentro de la zona correcta | 20 | ☐ |
| 8b | (Alternativa: zona incorrecta, pero completamente dentro) | 10 | ☐ |

**Subtotal estimado: ___ / 40**

---

## Detección y Lógica — 20 pts

| # | Criterio | Pts | Estado |
|---|----------|-----|--------|
| 9 | El robot detecta correctamente todos los colores del campo | 10 | ☐ |
| 10 | El robot toma decisiones correctas según el color detectado | 10 | ☐ |

**Subtotal estimado: ___ / 20**

---

## Finalización — 10 pts

| # | Criterio | Pts | Estado |
|---|----------|-----|--------|
| 11 | El robot sale de la zona de evacuación cruzando la línea roja | 5 | ☐ |
| 12 | El robot cruza completamente la línea morada (meta) | 5 | ☐ |

**Subtotal estimado: ___ / 10**

---

## Bonificaciones — hasta +10 pts

| # | Criterio | Pts | Estado |
|---|----------|-----|--------|
| B1 | Todas las víctimas clasificadas correctamente | +5 | ☐ |
| B2 | Víctimas blancas priorizadas sobre negras | +5 | ☐ |

**Bonificación estimada: +___ / 10**

---

## Penalizaciones — recordatorio

| Situación | Penalización |
|-----------|-------------|
| Reinicio desde checkpoint | **-5 pts** por reinicio (máx 3 reinicios) |
| Salirse de la pista | **-5 pts** |

**Penalización estimada: -___**

---

## Puntaje total estimado

```
Navegación:          ___ / 30
Evacuación:          ___ / 40
Detección y Lógica:  ___ / 20
Finalización:        ___ / 10
Bonificaciones:     + ___
Penalizaciones:     - ___
─────────────────────────
TOTAL:               ___ / 100
```

## Escala de desempeño

| Puntaje | Nivel |
|---------|-------|
| 90–100 | Excelente |
| 80–89 | Muy Bueno |
| 70–79 | Aceptable |
| < 70 | Insuficiente |
```

- [ ] **Paso 3: Verificar archivos**

Confirmar: plantilla tiene todos los campos, checklist tiene todas las categorías con puntos específicos.

- [ ] **Paso 4: Commit final**

```bash
git add recursos/plantilla_bitacora.md recursos/checklist_evaluacion.md
git commit -m "docs: agrega plantilla de bitácora y checklist de evaluación"
```

---

## Verificación final

- [ ] Ejecutar `find . -not -path './.git/*' -not -path './docs/superpowers/*' | sort` y confirmar que todos los archivos están presentes.
- [ ] Verificar en GitHub que todos los archivos se renderizan correctamente en Markdown.
- [ ] Confirmar que los enlaces entre docs y src funcionan (relativos con `../src/`).
