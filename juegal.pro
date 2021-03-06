TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    Game.cpp \
    Resources.cpp \
    utils.cpp \
    Scene.cpp \
    Player.cpp \
    Tongue.cpp \
    Chameleon.cpp \
    Portada.cpp \
    Goal.cpp \
    IngameMenu.cpp \
    Menu.cpp \
    Button.cpp \
    readlevels.cpp \
    frases.cpp \
    Background.cpp \
    Obstacle.cpp \
    Editor.cpp

HEADERS += \
    Game.hpp \
    Resources.hpp \
    utils.hpp \
    Scene.hpp \
    Player.hpp \
    Tongue.hpp \
    Chameleon.hpp \
    Portada.hpp \
    Goal.hpp \
    IngameMenu.hpp \
    Menu.hpp \
    Button.hpp \
    readlevels.hpp \
    frases.hpp \
    Background.hpp \
    Obstacle.hpp \
    Editor.hpp
