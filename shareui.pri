# Srikanth Sombhatla
# Dreamcode Deviceworks
# Shareui pri for harmattan
contains(MEEGO_EDITION,harmattan) {
  HEADERS += ShareUi.h
  SOURCES += ShareUi.cpp

  INCLUDEPATH +=  $$PWD
  DEPENDPATH += $$PWD

  # share ui setup
  CONFIG += shareuiinterface-maemo-meegotouch share-ui-plugin share-ui-common mdatauri
}