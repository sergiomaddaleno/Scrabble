﻿@REM Compilación y Enlace con librería gráfica.
@cls
@echo ---------------------------------------------------
@echo  ESAT Curso 2022-2023 Asignatura PRG Primero
@echo ---------------------------------------------------
@echo  Proceso por lotes iniciado.
@echo ---------------------------------------------------
@echo off

cl /nologo /Zi /GR- /EHs /MD Scrabble_main.cc -I ".\Lib_Graph\ESAT_rev225\include" ".\Lib_Graph\ESAT_rev225\bin\ESAT.lib"   opengl32.lib user32.lib gdi32.lib shell32.lib Ws2_32.lib

@echo ---------------------------------------------------
@echo  Proceso por lotes finalizado.
@echo ---------------------------------------------------
