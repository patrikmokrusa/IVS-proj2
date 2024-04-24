Struktura projektu
-----------------
- mockup (návrhy)
- profiling (graf profilingu)
- src (source kód pro ui, mathlib)
- src/linux (instalator dependencies)
- src/profiling (směrodatná odchylka pro profiling)
- src/test (TDD testy matematické knihovny)

Generované
- src/install (instalátor)
- src/doc (dokumentace

Building
-------
Projekt je napsán v C++ a QT frameworku

Jak zkompilovat:
- `cd src`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make -j`

Možnosti spuštění:
- `make run` (pro spuštění programu Hugocalc)
- `make test` (pro spuštění testů)
- `make doc` (pro vygenerování dokumentace do složku src/doc
- `make profile` (pro spuštění směrodatné odchylky)
- `make clean`
- `make pack` (zazipování projektu pro odevzdání)

Generace instalátoru:
- `cd build`
- `cmake -G "Unix Makefiles" ..`
- `cmake --build . --target package`


Autoři
------

Tým Hugo
- xmokrup00 Patrik Mokruša 
- xgeierd00 Daniel Geier
- xcernoa00 Adam Černoš 
- xjelinl00 Lukáš Jelínek

Prostředí
---------
Ubuntu 64bit

Licence
-------

Tento program je poskytovan licencí GNU GPLv3 (viz LICENSE.md)
