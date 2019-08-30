echo off
set file=%1
tasm %file%.asm
if errorlevel 1 goto End
tlink %file%.obj
%file%.exe
echo.
del *.map
del *.obj
del *.exe

:End

