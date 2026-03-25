# Lista de Materiales — RobotRescue

## Componentes principales

| Componente | Modelo sugerido | Cantidad | Notas |
|-----------|----------------|----------|-------|
| Microcontrolador | Arduino Nano | 1 | Incluye cable USB (mini o micro según modelo). Instalar driver CH340 si la PC no lo reconoce |
| Motores DC | Motor TT (motores amarillos) | 2 | Fáciles de montar, compatibles con el chasis 3D del proyecto |
| Driver de motores | TB6612FNG | 1 | Más eficiente y compacto que el L298N. Requiere conectar STBY a 5V |
| Sensores IR línea | TCRT5000 | 2–3 | 2 sensores mínimo; 3 recomendado. Montar a 3–8 mm del suelo |
| Sensor IR frontal | TCRT5000 o similar | 1 | Montado al frente horizontal; detecta pelotas y clasifica por color (blanco/negro) |
| Sensor de color | TCS34725 | 1 | Montado al frente apuntando al suelo; detecta zonas del campo (verde, rojo, azul, etc.) |
| Batería | LiPo 2S (7.4V) | 1 | Incluir cargador balanceado 2S. No descargar por debajo de 6V |
| Chasis | Impresión 3D (diseño del proyecto) | 1 | Máximo 15×15 cm. Incluye guía frontal tipo embudo y soportes para sensores |
| Ruedas | Compatibles con motor TT | 2 + 1 loca | La rueda loca va en la parte trasera para equilibrio |
| Cables dupont | Macho-hembra y macho-macho | 40+ | Varios colores para identificar conexiones |

## Componentes opcionales / recomendados

| Componente | Modelo sugerido | Cantidad | Notas |
|-----------|----------------|----------|-------|
| Módulo regulador | LM2596 step-down | 1 | Regula la LiPo 2S (7.4V) a 5V para el Arduino. Calibrar con multímetro antes de conectar |
| Interruptor | Switch SPDT o DPDT | 1 | Instalar en el cable (+) entre la batería y el regulador |
| Conector de batería | JST, XT30 o similar | 1 | Debe coincidir con el conector de la LiPo elegida |
| LED indicador | LED 5mm + resistencia 220Ω | 2–3 | Útiles para depuración visual (estado del robot) |
| Resistencias | 220Ω y 1kΩ | 5 c/u | Para LEDs y protección de entradas digitales |
| Zumbador | Pasivo 5V | 1 | Opcional; indica cambios de estado con sonido |
| Soporte PCB | Separadores de nylon M3 | 8+ | Para montar el Arduino y el driver de forma segura |

## Disposición de sensores

### Sensores IR (TCRT5000)
- **Altura del suelo:** 3–8 mm. Si están muy lejos, pierden sensibilidad; si están muy cerca, pueden rozar el suelo.
- **Separación entre sensores:** el sensor central debe estar sobre la línea. Los demás se distribuyen simétricamente.
- **Para el GAP:** los sensores extremos (izq_ext y der_ext) deben estar más separados que los demás — ayudan a detectar la línea cuando el robot se desvía al cruzar el GAP.

### Sensor de color (TCS34725) — detección de zonas del campo
- Montar apuntando **perpendicular al suelo**, en la parte delantera del robot.
- Distancia al suelo: **10–20 mm** para una lectura estable.
- Conectar por I2C: SDA → A4, SCL → A5 del Arduino Nano.
- Evitar luz directa de lámparas (puede saturar el sensor).
- Calibrar **en el lugar real de competencia** con la iluminación del día.

### Sensor IR frontal (TCRT5000) — detección y clasificación de víctimas
- Montar **horizontal** al frente, centrado, a la **altura de las pelotas** (~3–5 cm del suelo).
- Si el chasis incluye guía tipo embudo, el sensor va al centro del embudo.
- Detecta presencia de pelota por reflexión IR.
- También clasifica color: pelota blanca refleja mucho (valor alto), negra refleja poco (valor bajo).

## Diagramas de conexión

Los diagramas de conexión electrónica se agregarán en `hardware/diagramas/`.
