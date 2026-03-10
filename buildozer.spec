[app]
# Название твоего приложения в меню
title = Space Engine 120

# Имя пакета (должно быть уникальным, без пробелов)
package.name = spaceengine

# Домен (просто для идентификации)
package.domain = org.imba

# Где лежат исходники (. означает текущую папку)
source.dir = .

# Какие типы файлов включать в APK (добавь свои, если есть другие)
source.include_exts = cpp,h,otf,ttf

# Версия приложения
version = 1.0

# БИБЛИОТЕКИ (Самое важное для SDL2)
# Мы указываем sdl2 и sdl2_ttf, чтобы сборщик их скачал и настроил
requirements = sdl2,sdl2_ttf

# Ориентация экрана (landscape - альбомная, portrait - портретная)
orientation = landscape

# Работать во весь экран? (1 - да)
fullscreen = 1

# --- Android специфичные настройки ---

# Архитектура процессора (arm64-v8a подходит для большинства новых планшетов)
android.archs = arm64-v8a

# Минимальная версия Android (21 - это Android 5.0)
android.api = 31
android.minapi = 21

# (Опционально) Иконка приложения
# android.presplash_color = #000000

# Разрешения (если вдруг захочешь добавить интернет или память)
android.permissions = INTERNET

# Указываем Buildozer, что это C++ проект
p4a.setup_py = false

[buildozer]
# Уровень логирования (2 - выводить всё, чтобы видеть ошибки)
log_level = 2

# Предупреждать перед запуском от рута
warn_on_root = 1
