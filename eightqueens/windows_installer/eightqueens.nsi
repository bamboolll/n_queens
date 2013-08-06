; -------------- Headers ------------
!include MUI2.nsh

; --------------- General --------------

Name "Eight Queens Installer"
BrandingText /TRIMLEFT "Eight Queens Installer 0.3.4"
outFile "eightqueens_installer-0.3.3.exe"
installDir $PROGRAMFILES
RequestExecutionLevel admin

; ----------- Icon and Bitmap ---------

!define MUI_ICON install.ico
!define MUI_UNICON uninstall.ico

; -------------------------------------

!define MUI_ABORTWARNING

;------------- Language Selection Dialog Settings --------------

!define MUI_LANGDLL_REGISTRY_ROOT "HKCU" 
!define MUI_LANGDLL_REGISTRY_KEY "Software\Eight Queens" 
!define MUI_LANGDLL_REGISTRY_VALUENAME "Installer Language"

;-------------- Pages -------------

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "..\COPYING"
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

    # These indented statements modify settings for MUI_PAGE_FINISH
    !define MUI_FINISHPAGE_NOAUTOCLOSE
    !define MUI_FINISHPAGE_RUN "$INSTDIR\Eight Queens\eightqueens.exe"
    !define MUI_FINISHPAGE_RUN_CHECKED
    !define MUI_FINISHPAGE_RUN_TEXT "Launch Eight Queens"
    !define MUI_FINISHPAGE_SHOWREADME_CHECKED
    !define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\Eight Queens\readme.txt"
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

;--------------- Languages ---------------

!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "French"
!insertmacro MUI_LANGUAGE "German"
!insertmacro MUI_LANGUAGE "Spanish"
!insertmacro MUI_LANGUAGE "SpanishInternational"
!insertmacro MUI_LANGUAGE "SimpChinese"
!insertmacro MUI_LANGUAGE "TradChinese"
!insertmacro MUI_LANGUAGE "Japanese"
!insertmacro MUI_LANGUAGE "Korean"
!insertmacro MUI_LANGUAGE "Italian"
!insertmacro MUI_LANGUAGE "Dutch"
!insertmacro MUI_LANGUAGE "Danish"
!insertmacro MUI_LANGUAGE "Swedish"
!insertmacro MUI_LANGUAGE "Norwegian"
!insertmacro MUI_LANGUAGE "NorwegianNynorsk"
!insertmacro MUI_LANGUAGE "Finnish"
!insertmacro MUI_LANGUAGE "Greek"
!insertmacro MUI_LANGUAGE "Russian"
!insertmacro MUI_LANGUAGE "Portuguese"
!insertmacro MUI_LANGUAGE "PortugueseBR"
!insertmacro MUI_LANGUAGE "Polish"
!insertmacro MUI_LANGUAGE "Ukrainian"
!insertmacro MUI_LANGUAGE "Czech"
!insertmacro MUI_LANGUAGE "Slovak"
!insertmacro MUI_LANGUAGE "Croatian"
!insertmacro MUI_LANGUAGE "Bulgarian"
!insertmacro MUI_LANGUAGE "Hungarian"
!insertmacro MUI_LANGUAGE "Thai"
!insertmacro MUI_LANGUAGE "Romanian"
!insertmacro MUI_LANGUAGE "Latvian"
!insertmacro MUI_LANGUAGE "Macedonian"
!insertmacro MUI_LANGUAGE "Estonian"
!insertmacro MUI_LANGUAGE "Turkish"
!insertmacro MUI_LANGUAGE "Lithuanian"
!insertmacro MUI_LANGUAGE "Slovenian"
!insertmacro MUI_LANGUAGE "Serbian"
!insertmacro MUI_LANGUAGE "SerbianLatin"
!insertmacro MUI_LANGUAGE "Arabic"
!insertmacro MUI_LANGUAGE "Farsi"
!insertmacro MUI_LANGUAGE "Hebrew"
!insertmacro MUI_LANGUAGE "Indonesian"
!insertmacro MUI_LANGUAGE "Mongolian"
!insertmacro MUI_LANGUAGE "Luxembourgish"
!insertmacro MUI_LANGUAGE "Albanian"
!insertmacro MUI_LANGUAGE "Breton"
!insertmacro MUI_LANGUAGE "Belarusian"
!insertmacro MUI_LANGUAGE "Icelandic"
!insertmacro MUI_LANGUAGE "Malay"
!insertmacro MUI_LANGUAGE "Bosnian"
!insertmacro MUI_LANGUAGE "Kurdish"
!insertmacro MUI_LANGUAGE "Irish"
!insertmacro MUI_LANGUAGE "Uzbek"
!insertmacro MUI_LANGUAGE "Galician"
!insertmacro MUI_LANGUAGE "Afrikaans"
!insertmacro MUI_LANGUAGE "Catalan"
!insertmacro MUI_LANGUAGE "Esperanto"

; ------------ Reserve Files ------------

!insertmacro MUI_RESERVEFILE_LANGDLL

; ------------- Installer Functions ----------

Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

;-------------- Uninstaller Functions ------------

Function un.onInit
  !insertmacro MUI_UNGETLANGUAGE
FunctionEnd

;------------ Installer -------------

section
  setOutPath "$INSTDIR\Eight Queens"
  writeUninstaller "$INSTDIR\Eight Queens\uninstall.exe"

  createDirectory "$SMPROGRAMS\Eight Queens"
  createShortCut "$SMPROGRAMS\Eight Queens\Eight Queens.lnk" "$INSTDIR\Eight Queens\eightqueens.exe"
  createShortCut "$SMPROGRAMS\Eight Queens\Uninstall.lnk" "$INSTDIR\Eight Queens\uninstall.exe"

  file ..\release\eightqueens.exe
  file ..\COPYING
  file ..\readme.txt
  file QtGui4.dll
  file QtCore4.dll
  file libgcc_s_dw2-1.dll
  file mingwm10.dll
  file QtSvg4.dll
sectionEnd

;------------ Uninstaller -------------

section "uninstall"
  delete "$INSTDIR\uninstall.exe"
  delete "$INSTDIR\eightqueens.exe"
  delete "$INSTDIR\COPYING"
  delete "$INSTDIR\readme.txt"
  delete "$INSTDIR\QtGui4.dll"
  delete "$INSTDIR\QtCore4.dll"
  delete "$INSTDIR\libgcc_s_dw2-1.dll"
  delete "$INSTDIR\mingwm10.dll"
  delete "$INSTDIR\QtSvg4.dll"
  rmDir  "$INSTDIR"

  delete "$SMPROGRAMS\Eight Queens\uninstall.lnk"
  delete "$SMPROGRAMS\Eight Queens\Eight Queens.lnk"
  rmDir  "$SMPROGRAMS\Eight Queens"
sectionEnd
