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
