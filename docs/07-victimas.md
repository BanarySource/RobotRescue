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
