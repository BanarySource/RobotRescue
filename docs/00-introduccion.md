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
