[app]
title = Space Engine 120
package.name = spaceengine
package.domain = org.test
source.dir = .
source.include_exts = cpp,h,otf,ttf
version = 1.0

# hostpython3 нужен для работы инструментов сборки внутри сервера
requirements = sdl2,sdl2_ttf,hostpython3

orientation = landscape
fullscreen = 1

# Стабильные версии инструментов
android.api = 33
android.minapi = 21
android.sdk = 33
android.build_tools_version = 33.0.2
android.ndk = 25b
android.archs = arm64-v8a

# Отключаем Python-специфичные штуки для чистого C++
p4a.setup_py = false
p4a.bootstrap = sdl2

[buildozer]
log_level = 2
warn_on_root = 1
