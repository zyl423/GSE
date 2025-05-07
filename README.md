# 中英文切换的Hello World桌面应用

这是一个简单的Windows桌面小程序，展示了如何创建一个有中英文切换功能的窗口应用。

## 功能介绍

- 在窗口中央显示"Hello, World!"文本
- 点击底部按钮可以在中文和英文之间切换
- 切换语言时，窗口标题和显示内容都会改变

## 运行方法

### 方法一：直接运行（最简单）

1. 双击`build\Release\HelloWorldApp.exe`文件
2. 程序会自动启动并显示窗口

### 方法二：从命令行运行

1. 按`Win+R`打开"运行"窗口
2. 输入`cmd`并回车打开命令提示符
3. 输入以下命令（将路径改为您的实际路径）：
   ```
   D:\project_c\GSE\build\Release\HelloWorldApp.exe
   ```

## 如何重新构建程序

如果您修改了代码，可以通过以下方式重新构建程序：

1. 双击运行`cmake_and_build.bat`批处理文件
2. 等待构建完成
3. 运行`build\Release\HelloWorldApp.exe`查看结果

## 项目文件说明

- `main.cpp` - 程序的主要源代码，包含窗口创建和语言切换逻辑
- `CMakeLists.txt` - 项目配置文件，告诉电脑如何编译这个程序
- `cmake_and_build.bat` - 自动构建脚本，一键完成构建过程

## 不懂编程也没关系

即使您完全不懂编程，也可以通过以下简单修改来自定义程序：

1. 修改窗口标题：打开`main.cpp`，找到`L"Hello World Application"`和`L"\u4F60\u597D\u4E16\u754C\u5E94\u7528"`，换成您想要的文字
2. 修改显示文本：找到`L"Hello, World!"`和`L"\u4F60\u597D\uFF0C\u4E16\u754C\uFF01"`，换成您想要的文字
3. 修改按钮文本：找到`L"Switch to Chinese"`和`L"\u5207\u6362\u82F1\u6587"`，换成您想要的文字

记得修改后要重新构建程序（运行`cmake_and_build.bat`）！

## 常见问题

1. **中文显示乱码？**
   程序使用Unicode编码确保正确显示中文，如果还有问题可能是文件编码问题。

2. **按钮不工作？**
   请确保您没有修改按钮的ID（`ID_BUTTON_SWITCH`）。

3. **无法构建？**
   请确保您的电脑上安装了Visual Studio和CMake。 