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
