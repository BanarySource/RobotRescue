# Spec: Documentación completa RobotRescue — Operación Zona Cero

**Fecha:** 2026-03-25
**Objetivo:** Crear todos los archivos necesarios para que los alumnos puedan consultar en GitHub todas las características del reto.

---

## Estructura de archivos

```
RobotRescue/
├── README.md
├── reglamento/
│   └── operacion_zona_cero.md
├── docs/
│   ├── 00-introduccion.md
│   ├── 01-exploracion.md
│   ├── 02-diseno.md
│   ├── 03-construccion.md
│   ├── 04-movimiento.md
│   ├── 05-linea.md
│   ├── 06-colores.md
│   ├── 07-victimas.md
│   ├── 08-integracion.md
│   └── 09-competencia.md
├── src/
│   ├── 04-movimiento/
│   │   └── movimiento.ino
│   ├── 05-linea/
│   │   └── linea.ino
│   ├── 06-colores/
│   │   └── colores.ino
│   ├── 07-victimas/
│   │   └── victimas.ino
│   └── 08-completo/
│       └── main.ino
├── hardware/
│   ├── lista_materiales.md
│   └── diagramas/              ← carpeta vacía reservada para imágenes futuras
└── recursos/
    ├── plantilla_bitacora.md
    └── checklist_evaluacion.md
```

**Convención de nombres:** se omite la palabra "fase" en todos los nombres de archivos y carpetas por ser redundante. Esta convención sobreescribe la definida en CLAUDE.md.

*Las fases 1–3 no tienen código fuente porque corresponden a exploración, diseño y construcción física.*

---

## `docs/00-introduccion.md`

Archivo especial (no es una fase numerada). Contenido:
- Descripción del reto "Operación Zona Cero"
- Resumen de la misión completa (secuencia de pasos)
- Mapa visual del campo en texto/tabla (colores y zonas)
- Arquitectura de software: diagrama de la máquina de estados en texto
- Cómo navegar el repositorio: estructura de carpetas y para qué sirve cada una
- Glosario básico de términos (GAP, checkpoint, zona de evacuación, víctima)

---

## Contenido de cada doc de fase (`docs/01` a `docs/09`)

Cada archivo de fase incluye las siguientes secciones (en este orden):

1. **Objetivo** — qué aprenderá el alumno al terminar esta fase
2. **Conceptos clave** — lista con explicación breve de cada concepto nuevo
3. **Material necesario** — hardware y herramientas requeridas
4. **Actividades** — pasos concretos que el equipo debe realizar
   - Fases 1–3 (sin código): pasos físicos o de investigación/diseño
   - Fases 4–9 (con código): pasos de programación y prueba
5. **Código base** — enlace al `.ino` correspondiente en `src/` (fases 4–8); en fases 1–3 indicar "No aplica"; en fase 9 indicar que se continúa usando `src/08-completo/main.ino` con enlace directo
6. **Diagrama de flujo** — representación en texto/tabla del flujo lógico
   - Requerido en fases 5–8 (lógica de programación)
   - En fases 1–4 y 9: omitir o usar diagrama de proceso físico si aplica
7. **Preguntas de reflexión** — 3–5 preguntas para verificar comprensión
8. **Retos opcionales** — 2–3 retos adicionales para equipos que terminen antes
9. **Checklist de la fase** — lista de verificación antes de avanzar a la siguiente fase

*No se incluye "Duración estimada" en ningún documento.*

---

## Estructura de cada `.ino` (fases 4–7)

```cpp
// ============================================================
// RobotRescue — Operación Zona Cero
// Fase X: [Nombre]
// ============================================================
// INSTRUCCIONES:
// 1. Lee el doc correspondiente en docs/0X-nombre.md
// 2. Completa las secciones marcadas con TODO
// 3. Prueba cada función por separado antes de integrar
// ============================================================

// --- Constantes y pines (definidos y comentados) ---
// --- Variables globales (declaradas con descripción) ---
// --- setup() completo ---
// --- loop() con algunos TODO ---
// --- Funciones: al menos 1 completa (ejemplo) + 2 con TODO ---
```

**Regla:** mínimo 1 función completa como referencia y mínimo 2 funciones con TODO por archivo.

---

## `src/08-completo/main.ino`

Este archivo es especial: integra la máquina de estados completa. Su scaffold debe:
- Definir todos los estados como constantes (`SEGUIR_LINEA`, `ENTRAR_EVACUACION`, etc.)
- Incluir la variable `estadoActual` y el `switch` principal en `loop()`
- Proveer las firmas de todas las funciones principales definidas en CLAUDE.md
- Dejar con TODO las transiciones entre estados y el cuerpo de las funciones de evacuación
- Incluir al menos 2 funciones completamente implementadas (p. ej. `adelante()`, `parar()`) como referencia

---

## `README.md`

Orientado a alumnos. Incluye:
- Bienvenida y nombre oficial del reto
- Resumen de la misión en 3–4 líneas
- Tabla de las 9 fases con enlace a cada doc
- Guía de uso del repositorio (leer doc → abrir código → construir → probar)
- Notas operativas clave: calibrar sensores en el lugar real, usar Monitor Serial desde la fase 4, hacer commit en GitHub desde la fase 4
- Enlace al reglamento completo

---

## `reglamento/operacion_zona_cero.md`

Contenido extraído de CLAUDE.md (documento completo para consulta de alumnos):
- Secuencia completa de la misión
- Tabla de colores del campo y acciones del robot
- Características del campo (GAP, rampa, superficie)
- Checkpoints: ubicación, propósito, máximo de reinicios, penalización
- Sistema de evaluación: tabla de puntaje por criterio
- Penalizaciones
- Escala de desempeño
- **Tiempo límite** (5 minutos por intento; se evalúa el avance logrado)
- **Criterios de desempate** (en orden: víctimas clasificadas, reinicios, tiempo)
- Restricciones técnicas (tamaño, sensores permitidos, autonomía)
- Definiciones oficiales de validez

---

## `hardware/lista_materiales.md`

Tabla de componentes con columnas: Componente | Modelo sugerido | Cantidad | Notas.
La columna "Notas" incluye información de montaje y disposición de sensores:
- Sensores IR: altura del suelo, separación recomendada, nota sobre GAP
- Sensor de color: orientación al suelo
- Sensor ultrasónico: orientación horizontal

La carpeta `hardware/diagramas/` incluye un archivo `.gitkeep` para que sea visible en GitHub; las imágenes se agregarán posteriormente.

---

## `recursos/plantilla_bitacora.md`

Plantilla semanal con campos: fecha, objetivo de la sesión, actividades realizadas, problemas encontrados, soluciones aplicadas, aprendizajes, próximos pasos.

---

## `recursos/checklist_evaluacion.md`

Lista de verificación para autoevaluación de equipos antes de competir. Estructura espeja la tabla de puntaje del reglamento por categorías:
- Navegación (30 pts): seguimiento de línea, detección zona verde, entrada correcta
- Evacuación (40 pts): detección de víctimas, control/empuje, depósito en zona correcta
- Detección y Lógica (20 pts): detección de colores, toma de decisiones
- Finalización (10 pts): salida por zona roja, llegada al punto final
- Bonificaciones (+10 máx): clasificación correcta, prioridad víctimas blancas
- Penalizaciones: tabla con los valores específicos (reinicio desde checkpoint: -5 pts; salirse de la pista: -5 pts)

Cada ítem tiene: [ ] descripción — (X pts)

---

## Decisiones de diseño

| Decisión | Razón |
|----------|-------|
| Docs y código separados (Opción A) | Estructura estándar en GitHub; permite descargar `.ino` directamente |
| Código con TODO, no funcional completo | Los alumnos deben completar el código como ejercicio de aprendizaje |
| Sin "Duración estimada" en docs | Decisión explícita del autor del proyecto |
| Solo diagramas de flujo en texto | Imágenes/diagramas visuales se agregarán posteriormente |
| Nombres sin la palabra "fase" | Redundante; sobreescribe convención de CLAUDE.md |
| Idioma: español | Proyecto para alumnos de nivel medio superior en español |
