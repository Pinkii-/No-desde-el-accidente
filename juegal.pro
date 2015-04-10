TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    Game.cpp \
    Resources.cpp \
    utils.cpp \
    Scene.cpp

HEADERS += \
    Game.hpp \
    Resources.hpp \
    utils.hpp \
    Scene.hpp

