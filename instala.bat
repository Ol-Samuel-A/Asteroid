set origen=%CD%\InstalaAstro
echo En que subcarpeta dentro de tu perfil de usuario quieres instalar el program?
echo Ejemplo  desktop\Astroid o documents\Astroid
set /p Subdir=subcarpeta:
set "Destino=%UserProfile%\%Subdir%"
if not exist "%Destino%" md "%Destino%"
xcopy /e %origen% %Destino%
set Subdir=
set Destino=
set origen=