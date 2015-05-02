TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    Editor.cpp \
    ../utils.cpp \
    ../Resources.cpp \
    ../Obstacle.cpp \
    ../Goal.cpp \
    ../Chameleon.cpp \
    ../Player.cpp \
    ../readlevels.cpp \
    ../Background.cpp \
    ../Tongue.cpp

HEADERS += \
    Editor.hpp \
    ../utils.hpp \
    ../Resources.hpp \
    ../Obstacle.hpp \
    ../Goal.hpp \
    ../Chameleon.hpp \
    ../Player.hpp \
    ../readlevels.hpp \
    ../Background.hpp \
    ../Tongue.hpp

