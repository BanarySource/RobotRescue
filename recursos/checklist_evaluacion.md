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
