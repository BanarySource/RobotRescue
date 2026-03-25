# RobotRescue — Contexto del Proyecto

## Descripción General

Proyecto educativo de robótica autónoma para nivel medio superior.
Nombre oficial del reto: **"Operación Zona Cero"**
Inspirado en RoboCup Junior Rescue Line.

---

## Reto: Operación Zona Cero

### Secuencia completa de la misión

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

### Colores del campo

| Color | Significado | Acción del robot |
|-------|-------------|-----------------|
| Negro (línea, 2 cm) | Camino principal | Seguir |
| Verde | Entrada zona de evacuación | Entrar |
| Azul | Zona víctimas vivas (blancas) | Depositar |
| Amarillo | Zona víctimas muertas (negras) | Depositar |
| Rojo | Salida zona de evacuación | Salir (cruzar completo) |
| Morado | Meta final | Detenerse (cruzar completo) |

### Características del campo

- **Línea:** negra, ~2 cm de ancho (cinta de aislar), sobre fondo blanco mate
- **Obstáculos de navegación:** curvas, intersecciones, **GAP** (interrupción de línea), **rampa**
- **Superficie:** mate, no reflejante
- **Iluminación:** constante y controlada durante la competencia

> ⚠️ **GAP:** sección donde la línea desaparece temporalmente. El robot debe "adivinar" la trayectoria y reencontrar la línea. Requiere lógica especial.
> ⚠️ **Rampa:** el robot debe subir y descender una pendiente sin perder la línea ni desestabilizarse.

---

## Puntos de Control (Checkpoints)

| # | Ubicación | Propósito |
|---|-----------|-----------|
| CP1 | Antes de la rampa | Reinicio si falla en rampa |
| CP2 | Antes de zona de evacuación | Reinicio si falla al entrar |
| CP3 | Al salir de zona de evacuación | Reinicio si falla al retomar línea |

- Máximo **3 reinicios** por intento
- Penalización: **-5 puntos** por reinicio
- Al reiniciar: robot colocado manualmente alineado en el checkpoint, sin orientación estratégica

---

## Sistema de Evaluación

### Puntaje por criterio (máximo 100 pts)

| Criterio | Puntos |
|---------|--------|
| **Navegación** | 30 |
| — Seguimiento de línea | 15 |
| — Detección de zona verde | 5 |
| — Entrada correcta | 10 |
| **Evacuación** | 40 |
| — Detección de víctimas | 10 |
| — Control/empuje | 10 |
| — Depósito en zona correcta | 20 (máx 10 si zona incorrecta) |
| **Detección y Lógica** | 20 |
| — Detección de colores | 10 |
| — Toma de decisiones | 10 |
| **Finalización** | 10 |
| — Salida por zona roja | 5 |
| — Llegar al punto final | 5 |
| **Bonificaciones** | +10 máx |
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

### Criterios de desempate (en orden)

1. Mayor número de víctimas correctamente clasificadas
2. Menor número de reinicios
3. Menor tiempo de ejecución

### Tiempo límite

- **5 minutos** por intento
- Se evalúa el avance logrado al detenerse el tiempo

---

## Restricciones Técnicas

- Tamaño máximo: **15 cm × 15 cm** en la base (sin límite de altura)
- El robot debe caber completamente en esas dimensiones al inicio
- Sensores permitidos: IR, Color, Ultrasónico
- Sin garra, succión ni mecanismos que deformen las pelotas
- Empuje frontal recomendado
- Operación 100% autónoma — sin control remoto, sin mapas precargados

---

## Definiciones Oficiales de Validez

| Acción | Condición para considerarse válida |
|--------|----------------------------------|
| Detección de víctima | El robot modifica su comportamiento al detectarla |
| Depósito correcto | Pelota **completamente** dentro de la zona, sin contacto con el robot |
| Salida de evacuación | Robot cruza **completamente** la línea roja |
| Finalización | Robot cruza **completamente** la línea morada |

---

## Hardware

| Componente | Modelo sugerido | Cantidad |
|-----------|----------------|----------|
| Microcontrolador | Arduino Uno / Mega | 1 |
| Motores DC | Motor N20 o TT Motor | 2 |
| Driver de motores | L298N o TB6612FNG | 1 |
| Sensores IR | TCRT5000 | 3–5 |
| Sensor de color | TCS34725 o TCS3200 | 1 |
| Sensor ultrasónico | HC-SR04 | 1 |
| Batería | LiPo 7.4V o 4× AA | 1 |

### Disposición de sensores

- **IR (3–5):** parte frontal inferior, 3–8 mm del suelo — seguimiento de línea
- **Sensor de color (1):** apuntando al suelo al frente — detección de zonas de color
- **Ultrasónico (1):** frente del robot, horizontal — detección de víctimas

> Para el GAP se recomienda al menos 5 sensores IR (extremos más separados) o lógica de memoria de última dirección conocida.

---

## Software — Arquitectura

El programa usa una **máquina de estados**:

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

### Funciones principales

```
// Movimiento
adelante() / atras() / izquierda() / derecha() / parar()

// Navegación
seguirLinea()
manejarGAP()           ← nueva — avanzar recto hasta reencontrar línea
manejarRampa()         ← nueva — ajustar velocidad en pendiente

// Sensores
detectarColor()        → "VERDE" | "ROJO" | "AZUL" | "AMARILLO" | "MORADO" | "NINGUNO"
medirDistancia()       → distancia en cm (HC-SR04)
detectarColorPelota()  → "BLANCO" | "NEGRO"

// Evacuación
empujarAZonaAzul()
empujarAZonaAmarilla()
```

---

## Perfil de los Estudiantes

- Nivel medio superior
- Conocimientos básicos de programación (condicionales, funciones)
- Mayoría sin experiencia previa en electrónica
- Se espera que aprendan: máquinas de estados, toma de decisiones, depuración

---

## Plan de Desarrollo — 9 Fases

| # | Fase | Semanas | Nivel |
|---|------|---------|-------|
| 1 | Exploración y fundamentos | 2 | Básico |
| 2 | Diseño y planeación | 2 | Básico |
| 3 | Construcción del chasis | 2 | Básico |
| 4 | Programación básica de movimiento | 3 | Básico |
| 5 | Seguimiento de línea (IR) + GAP | 3 | Básico–Intermedio |
| 6 | Detección de zonas (color) | 2 | Intermedio |
| 7 | Clasificación y empuje de víctimas | 3 | Intermedio |
| 8 | Misión completa e integración | 2 | Intermedio–Avanzado |
| 9 | Pruebas, ajuste y competencia | 1 | Avanzado |

**Duración total estimada:** 16–20 semanas (semestre completo)

---

## Estructura del Repositorio

```
RobotRescue/
├── README.md                    ← Página principal pública para alumnos
├── CLAUDE.md                    ← Contexto interno del proyecto
│
├── reglamento/
│   └── operacion_zona_cero.md   ← Reglamento oficial completo
│
├── docs/
│   ├── 00-introduccion.md
│   ├── 01-fase-exploracion.md
│   ├── 02-fase-diseno.md
│   ├── 03-fase-construccion.md
│   ├── 04-fase-movimiento.md
│   ├── 05-fase-linea.md         ← incluye GAP y rampa
│   ├── 06-fase-colores.md
│   ├── 07-fase-victimas.md
│   ├── 08-fase-integracion.md
│   └── 09-fase-competencia.md
│
├── src/
│   ├── fase_04_movimiento/
│   ├── fase_05_linea/
│   ├── fase_06_colores/
│   ├── fase_07_victimas/
│   └── fase_08_completo/
│       └── main.ino
│
├── hardware/
│   ├── lista_materiales.md
│   └── diagramas/
│
└── recursos/
    ├── plantilla_bitacora.md
    └── checklist_evaluacion.md
```

---

## Convenciones de Código

- Lenguaje: **C++ para Arduino** (archivos `.ino`)
- Cada función máximo **15 líneas**; si es mayor, dividir
- Comentarios en **español**
- Variables y funciones en **camelCase** (`seguirLinea`, `detectarColor`)
- Estados de la máquina en **MAYÚSCULAS**
- Siempre usar Monitor Serial para depuración (`Serial.println()`)

---

## Entregables Finales por Equipo

- [ ] Robot físico funcional (≤15×15 cm)
- [ ] Código final comentado (`main.ino`)
- [ ] Bitácora de proyecto completa
- [ ] Video del robot completando la misión
- [ ] Presentación de 5 minutos explicando lógica y decisiones de diseño

---

## Notas Pedagógicas

- Normalizar el fallo: cada error es aprendizaje
- Calibrar sensores **en el lugar real de uso** (iluminación afecta lecturas)
- Usar Monitor Serial desde fase 4 como herramienta principal de depuración
- GitHub básico desde fase 4 (`commit` + `push`) para no perder código
- Checkpoints semanales de 5 min entre equipos fomentan aprendizaje entre pares
- El **GAP** y la **rampa** son los puntos de mayor dificultad — planear tiempo extra para fase 5
- Período de pruebas previo a competencia: sin acceso al diseño final del circuito (evita sobreoptimización)
