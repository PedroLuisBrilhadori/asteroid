# Requisitos para o Windows

Para que o projeto seja compilado e executado com sucesso é necessário ter instalado os seguintes requisitos:

- [MSY2 MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)

- [SFML 2.6.2](https://www.sfml-dev.org/download/sfml/2.6.2/)

# Como rodar

O projeto pode ser compilado e executado de diferentes formas, partircularmente estou utilizando o próprio VSCODE.

```json
// .vscode/launch.json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug SFML",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/build/main.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "Build SFML Project"
    }
  ]
}
```

```json
// .vscode/tasks.json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build SFML Project",
      "type": "shell",
      "command": "g++",
      "args": [
        "-g",
        "./src/main.cpp",
        "-o",
        "./build/main.exe",
        "-IC:/SFML/include",
        "-LC:/SFML/lib",
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"]
    }
  ]
}
```

> Para o executavel gerado executar é necessário que as ddls da lib SFML sejam colocada na pasta `build` que fica na raiz do projeto

> "-lsfml-graphics", "-lsfml-window", "-lsfml-system"; São as ddls utilizadas inicialmente
