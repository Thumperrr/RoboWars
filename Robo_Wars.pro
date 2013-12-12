TEMPLATE = app
CONFIG -= console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

LIBS += -LC:/SFML-2.1-QT/lib
INCLUDEPATH += C:/SFML-2.1-QT/include
DEPENDPATH += C:/SFML-2.1-QT/include

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

SOURCES += main.cpp \
    Game/Application.cpp \
    Game/States/State.cpp \
    Game/States/StateStack.cpp \
    Game/States/TestingState.cpp

HEADERS += \
    Game/Application.hpp \
    Game/States/State.hpp \
    Game/Context.hpp \
    Game/States/StateIdentifiers.hpp \
    Game/States/StateStack.hpp \
    Game/States/TestingState.hpp

