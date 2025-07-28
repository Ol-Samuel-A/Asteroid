@echo off
set carpD=%DATE:~0,2%_%DATE:~3,2%
set clokt=%TIME:~1,1%_%TIME:~3,2%_%TIME:~6,2%
IF NOT EXIST %carpD%\ md %carpD% 
cd %carpD%
md %clokt%
cd ..
del recursos\imag\*.png
del recursos\font\*.TTF
copy imag recursos\imag
copy font recursos\font
xcopy /e recursos %carpD%\%clokt%
gcc Asteroid.cpp -o Asteroid.exe -lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_primitives
Asteroid.exe
copy Asteroid.cpp %carpD%\%clokt%\Asteroid%clokt%.cpp
copy Asteroid.exe %carpD%\%clokt%\Asteroid%clokt%.exe
set clokt=
set carpD=
