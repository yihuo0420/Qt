######################################################################
# Automatically generated by qmake (3.1) Mon Aug 6 20:48:18 2018
######################################################################

TEMPLATE = app
TARGET = imsclient
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += imsdefine.h \
           imsimageaccount.h \
           imsimagelabel.h \
           imsimagelineedit.h \
           imsresoursce.h \
           resource.h \
           uiapplicationmanager.h \
           uiimsbasedialog.h \
           uiinterfacemanager.h \
           uiloginscreen.h \
           uitabwidget.h \
           uiweatherinfo.h \
           workstation.h
FORMS += uiapplicationmanager.ui \
         uiinterfacemanager.ui \
         uiloginscreen.ui \
         uiweatherinfo.ui \
         workstation.ui
SOURCES += imsimageaccount.cpp \
           imsimagelabel.cpp \
           imsimagelineedit.cpp \
           imsresoursce.cpp \
           main.cpp \
           uiapplicationmanager.cpp \
           uiimsbasedialog.cpp \
           uiinterfacemanager.cpp \
           uiloginscreen.cpp \
           uitabwidget.cpp \
           uiweatherinfo.cpp \
           workstation.cpp
RESOURCES += workstation.qrc