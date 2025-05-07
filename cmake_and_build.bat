@echo off
echo 开始CMake配置...

cd build
D:\Visual_Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe ..
if errorlevel 1 (
    echo CMake配置失败！
    pause
    exit /b 1
)

echo CMake配置成功！
echo 开始构建...

D:\Visual_Studio\2022\Enterprise\MSBuild\Current\Bin\MSBuild.exe HelloWorldApp.sln /p:Configuration=Release
if errorlevel 1 (
    echo 构建失败！
    pause
    exit /b 1
) else (
    echo 构建成功！
    echo 你可以运行：Release\HelloWorldApp.exe
    pause
) 