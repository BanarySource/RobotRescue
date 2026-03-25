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
