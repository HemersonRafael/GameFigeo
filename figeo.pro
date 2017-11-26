TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circulo.cpp \
    reta.cpp \
    retangulo.cpp \
    screen.cpp \
    triangulo.cpp \
    game.cpp \
    data.cpp

HEADERS += \
    circulo.h \
    figurageometrica.h \
    reta.h \
    retangulo.h \
    screen.h \
    triangulo.h \
    game.h \
    data.h
