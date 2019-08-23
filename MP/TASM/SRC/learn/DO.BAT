doskey
cls
echo off
tasm %1.ASM /l/n
if errorlevel 1 goto end
tlink %1.OBJ
%1.EXE
