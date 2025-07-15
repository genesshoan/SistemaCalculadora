# 🧮 Sistema de Ecuaciones por Consola

**Autores:** Valdo Castiglia, Gonzalo Giusiano, Shoan Genes  
**Profesor:** José Clavijo  
**Fecha de entrega:** 17 de febrero de 2025

---

## 📌 Descripción

Este sistema permite al usuario crear, visualizar, resolver, sumar, guardar y recuperar **ecuaciones de primer y segundo grado** mediante una interfaz por línea de comandos. Fue desarrollado como parte del Taller 1, aplicando técnicas de estructuras de datos, TADs y persistencia en archivos.

---

## 🧠 Funcionalidades

El sistema reconoce y ejecuta los siguientes comandos:

- `crear <id> <a> <b> [c]` → Crea una ecuación (de 1er o 2do grado)
- `mostrar` → Muestra todas las ecuaciones cargadas en memoria
- `resolver <id>` → Resuelve la ecuación con ese identificador
- `sumar <id1> <id2> <idResultado>` → Suma dos ecuaciones y guarda el resultado
- `guardar <id>` → Guarda una ecuación en disco (`.dat`)
- `recuperar <id>` → Recupera una ecuación desde disco
- `salir` → Libera memoria y finaliza la ejecución

> 🧪 Se utiliza una lista lineal para los comandos y un árbol binario de búsqueda (ABB) para almacenar ecuaciones.

---

## 🔧 Tecnologías y estructuras usadas

- Lenguaje: **C++**
- Paradigma: **Estructurado**, con uso intensivo de **TADs**
- Estructuras:
  - Árbol binario de búsqueda (ABB)
  - Lista de strings para comandos
  - `union` para distinguir ecuaciones de 1er o 2do grado
  - Archivo binario para respaldo (`.dat`)
- Modularización: diseño por encabezados (`.h`) y definición separada de TADs

---

## 💻 Ejemplo de uso

```txt
crear eq1 2 3
crear eq2 1 4 5
sumar eq1 eq2 eq3
resolver eq3
guardar eq3
salir
