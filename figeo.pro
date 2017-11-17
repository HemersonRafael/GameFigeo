TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circulo.cpp \
    extras.cpp \
    reta.cpp \
    retangulo.cpp \
    screen.cpp \
    triangulo.cpp \
    game.cpp

HEADERS += \
    circulo.h \
    extras.h \
    figurageometrica.h \
    reta.h \
    retangulo.h \
    screen.h \
    triangulo.h \
    game.h
