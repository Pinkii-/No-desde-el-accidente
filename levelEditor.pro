TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    ../utils.cpp \
    ../Resources.cpp \
    ../Obstacle.cpp \
    ../Goal.cpp \
    ../Chameleon.cpp \
    Editor.cpp \
    ../Player.cpp \
    ../readlevels.cpp \
    ../Background.cpp

HEADERS += \
    ../utils.hpp \
    ../Resources.hpp \
    ../Obstacle.hpp \
    ../Goal.hpp \
    ../Chameleon.hpp \
    Editor.hpp \
    ../Player.hpp \
    ../readlevels.hpp \
    ../Background.hpp

