[app]
title = Space Engine 120
package.name = spaceengine
package.domain = org.test
source.dir = .
source.include_exts = cpp,h,otf,ttf
version = 1.0

# ОСТАВЛЯЕМ ТОЛЬКО ЭТО (никаких hostpython3 и ffi!)
requirements = sdl2,sdl2_ttf

orientation = landscape
fullscreen = 1

# Стабильные версии инструментов для Redmi Pad
android.api = 33
android.minapi = 21
android.sdk = 33
android.build_tools_version = 33.0.2
android.ndk = 25b
android.archs = arm64-v8a

# Отключаем Python-логику, включаем SDL2-старт
p4a.setup_py = false
p4a.bootstrap = sdl2

[buildozer]
log_level = 2
warn_on_root = 1 
