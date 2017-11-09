QT += qml quick

CONFIG += c++11

HEADERS += \
        *.h \
# ecs framework
        ecs/framework/entity.h \
        ecs/framework/id_engine.h \
        ecs/framework/world.h \
        ecs/framework/details/polymorph.h \
# game ecs stuff
        ecs/components.h \
        ecs/events.h \
        ecs/systems.h \

SOURCES += \
        main.cpp \
# ecs framework
        ecs/framework/entity.cpp \
        ecs/framework/id_engine.cpp \
        ecs/framework/world.cpp \
        ecs/framework/details/polymorph.cpp \
        ecs/framework/details/polymorph.impl \
# game ecs stuff
        ecs/components.cpp \
        ecs/events.cpp \
        ecs/systems.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
