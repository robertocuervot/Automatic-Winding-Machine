# Kiubs Winding Machine (KWM)

## Descripción del Proyecto

El **Kiubs Winding Machine (KWM)** es una máquina de embobinado automático diseñada para facilitar la construcción de transformadores y bobinas para proyectos de pequeña y mediana escala. Este sistema permite al usuario configurar parámetros clave, como calibre del alambre, número de vueltas, y tipo de bobina, proporcionando un proceso más eficiente, preciso y menos propenso a errores.

---

## Contexto y Motivación

La fabricación manual de bobinas es un proceso complejo y lento, especialmente para calibres pequeños. La falta de precisión y los materiales desperdiciados son desafíos comunes. Este proyecto busca resolver estos problemas mediante una solución automatizada accesible, ideal para estudiantes e investigadores.

---

## Características Principales

- **Compatibilidad con distintos tipos de bobinas:** Diseñada para bobinas circulares y cuadradas.
- **Control de tensión avanzado:** Mantiene una tensión constante para prevenir rupturas o sobrelapsos.
- **Configuración flexible:** El usuario puede especificar parámetros como número de vueltas, calibre del cable y velocidad de embobinado.
- **Interfaz de usuario:** Control sencillo mediante comandos seriales y una máquina de estados finitos.
- **Diseño modular:** Componentes impresos en 3D, perfiles de aluminio y sistemas de poleas ajustables.

---

## Especificaciones Técnicas

- **Rango de calibres soportados:** Alambres desde AWG 25 hasta AWG 36.
- **Dimensiones de las bobinas:** 
  - Máximo: Longitud 59 mm, Ancho 59.1 mm.
  - Mínimo: Longitud 2.5 mm, Ancho 18.7 mm.
- **Componentes clave:**
  - Motores NEMA 17 y motor DC con reductor.
  - Microcontrolador PIC18F46K42.
  - Sensores como celda de carga con módulo HX711.
- **Materiales:** Estructura de aluminio tipo V-slot 2020, piezas en PLA impresas en 3D.

---

## Cómo Usar la Máquina

1. **Configurar los parámetros:** 
   - Introducir longitud, calibre del cable y número de capas.
   - Especificar si se necesita aislamiento entre capas.
2. **Preparar la bobina:** Asegurarla en la máquina y pasar el cable a través de las guías.
3. **Iniciar el proceso:** Utilizar la interfaz serial para enviar el comando de inicio.
4. **Monitorear el proceso:** La máquina ajustará automáticamente la tensión y velocidad según los parámetros.
5. **Finalizar:** Retirar la bobina cuando el sistema indique la conclusión.

---

## Galería de Imágenes

### Diseño CAD del Sistema
![Diseño CAD](path/to/cad_image.png)

### Ensamble Final
![Ensamble Final](path/to/final_assembly_image.png)

### Diagrama de Flujo del Proceso
![Diagrama de Flujo](path/to/flowchart_image.png)

Asegúrate de reemplazar `path/to/image.png` con la ruta a tus imágenes en el repositorio.

---

## Videos del Proyecto

- **Video de funcionamiento completo:**  
[![Video de Funcionamiento](path/to/thumbnail.png)](link/to/video)
- **Pruebas con bobinas circulares y cuadradas:**  
[![Video de Pruebas](path/to/thumbnail.png)](link/to/video)

Sustituye `path/to/thumbnail.png` con las miniaturas y `link/to/video` con los enlaces a los videos.

---

## Estructura del Repositorio

- **`/code`:** Código fuente del firmware implementado en el microcontrolador.
- **`/designs`:** Modelos CAD de la máquina y diagramas de circuito.
- **`/docs`:** Documentación técnica, incluyendo reportes y manuales.
- **`/tests`:** Resultados de las pruebas realizadas y scripts de validación.

---

## Limitaciones

- No apta para alambres con calibres inferiores a AWG 9.
- Requiere cierta experiencia para el manejo inicial.
- Disminución de precisión a altas velocidades (más de 500 rpm).
- Dimensiones y peso considerables, dificultando el transporte.

---

## Créditos

Este proyecto fue desarrollado por:

- **María Alejandra Amaya Mejía** (amaya_maria@javeriana.edu.co)  
- **Roberto Andrés Cuervo Torres** (ra.cuervo@javeriana.edu.co)  
- **Karen Vanessa Wilches Beltrán** (karenv-wilchesb@javeriana.edu.co)

---

## Licencia

Este proyecto se encuentra bajo la licencia [MIT](LICENSE), lo que permite su uso, modificación y distribución para fines académicos y comerciales. 
