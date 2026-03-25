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
