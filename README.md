<a id="readme-top"></a>

# Máquina de Embobinado Automático

## Tabla de Contenidos

- [Descripción del Proyecto](#descripción-del-proyecto)
- [Contexto y Motivación](#contexto-y-motivación)
- [Características Principales](#características-principales)
- [Especificaciones Técnicas](#especificaciones-técnicas)
- [Cómo Usar la Máquina](#cómo-usar-la-máquina)
- [Galería de Imágenes](#galería-de-imágenes)
- [Video en funcionamiento](#video-en-funcionamiento)
- [Estructura del Repositorio](#estructura-del-repositorio)
- [Limitaciones](#limitaciones)
- [Créditos](#créditos)
- [Licencia](#Licencia)

## Descripción del Proyecto

**Kiubs Winding Machine (KWM)** es una máquina de embobinado automático diseñada para facilitar la construcción de transformadores y bobinas para proyectos de pequeña y mediana escala. Este sistema permite al usuario configurar parámetros clave, como calibre del alambre, número de vueltas, y tipo de bobina, proporcionando un proceso más eficiente, preciso y menos propenso a errores.

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Contexto y Motivación

La fabricación manual de bobinas es un proceso complejo y lento, especialmente para calibres pequeños. La falta de precisión y los materiales desperdiciados son desafíos comunes. Este proyecto busca resolver estos problemas mediante una solución automatizada accesible, ideal para estudiantes e investigadores.

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Características Principales

- **Compatibilidad con distintos tipos de bobinas:** Diseñada para bobinas circulares y cuadradas.
- **Control de tensión avanzado:** Mantiene una tensión constante para prevenir rupturas o sobrelapsos.
- **Configuración flexible:** El usuario puede especificar parámetros como número de vueltas, calibre del cable y velocidad de embobinado.
- **Interfaz de usuario:** Control sencillo mediante comandos seriales y una máquina de estados finitos.
- **Diseño modular:** Componentes impresos en 3D, perfiles de aluminio y sistemas de poleas ajustables.

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Especificaciones Técnicas

- **Rango de calibres soportados:** Alambres desde AWG 25 hasta AWG 36.
- **Componentes clave:**
  - Motores NEMA 17 y motor DC con reductor.
  - Microcontrolador PIC18F46K42 (Se utilizó el software MPLAB para su programación).
  - Sensores como celda de carga con módulo HX711.
- **Materiales:** Estructura de aluminio tipo V-slot 2020, piezas en PLA impresas en 3D.

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Cómo Usar la Máquina

1. **Configurar los parámetros:** 
   - Introducir longitud, calibre del cable y número de capas.
   - Especificar si se necesita aislamiento entre capas.
2. **Preparar la bobina:** Asegurarla en la máquina y pasar el cable a través de las guías.
3. **Iniciar el proceso:** Utilizar la interfaz serial para enviar el comando de inicio.
4. **Monitorear el proceso:** La máquina ajustará automáticamente la tensión y velocidad según los parámetros.
5. **Finalizar:** Retirar la bobina cuando el sistema indique la conclusión.

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Galería de Imágenes

### Diseño CAD del Sistema
![Diseño CAD](Imagenes/Modelo.png)

### Ensamble Final
![Ensamble Final](Imagenes/Montaje.png)

### Montaje electrónico realizado
![Esquematico](Imagenes/Esquemático.png)

### Diagramas del Proceso
Comportamiento del sistema en lazo cerrado:

![Diagrama Control](Imagenes/FuncionamientoGeneral.png)

Diagrama de flujo de los pasos que sigue el sistema:

![Diagrama de Flujo](Imagenes/FlujoSistema.png)

### Resultados de embobinado
![Diseño CAD](Imagenes/Resultados.jpg)

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Video en funcionamiento
[![Video de Funcionamiento](path/to/thumbnail.png)](link/to/video)

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Estructura del Repositorio

- **`Proyecto_MPLAB/Emobinadora_Control.X`:** Proyecto MPLAB que contiene la programación del microcontrolador.
- **`/Imagenes`:** Modelos CAD de la máquina, diagramas e imagenes del proyecto.

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Limitaciones

- No apta para alambres con calibres inferiores a AWG 9.
- Requiere cierta experiencia para el manejo inicial.
- Disminución de precisión a altas velocidades (más de 500 rpm).
- Dimensiones y peso considerables, dificultando el transporte.

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Créditos

Este proyecto fue desarrollado por:

- **María Alejandra Amaya Mejía** (amaya_maria@javeriana.edu.co)   
- **Karen Vanessa Wilches Beltrán** (karenv-wilchesb@javeriana.edu.co)
- **Roberto Andrés Cuervo Torres** (ra.cuervo@javeriana.edu.co) 

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>

---

## Licencia

Este proyecto se encuentra bajo la licencia [GNU General Public License v3.0](LICENSE).

<p align="right">(<a href="#readme-top">Volver arriba</a>)</p>
