[app]
title = Space Engine 120
package.name = spaceengine
package.domain = org.test
source.dir = .
source.include_exts = cpp,h,otf,ttf
version = 1.0

# Только SDL2 библиотеки, никакого Python
requirements = sdl2,sdl2_ttf

# Настройки экрана
orientation = landscape
fullscreen = 1

# Версии Android (Фикс для твоей ошибки)
android.api = 33
android.minapi = 21
android.sdk = 33
android.build_tools_version = 33.0.2
android.ndk = 25b
android.archs = arm64-v8a

# Разрешения
android.permissions = INTERNET, WRITE_EXTERNAL_STORAGE

# Указываем, что проект на C++, а не на Python
p4a.setup_py = false

[buildozer]
log_level = 2
warn_on_root = 1
