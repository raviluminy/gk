
ajouter ces lignes dans le .pro

LIBS += -L$$PWD/annuaire/lib/ -lldapsdk

win32: INCLUDEPATH += $$PWD/annuaire/include/windows
else:unix:!macx:!symbian: INCLUDEPATH += $$PWD/annuaire/include/linux

win32: DEPENDPATH += $$PWD/annuaire/include/windows
else:unix:!macx:!symbian: DEPENDPATH += $$PWD/annuaire/include/linux

ca fonctionne pour windows et linux
