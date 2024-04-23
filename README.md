# ZPID
Сборка : Visual Studio 2017
Компилятор : MSVC141

Использованные средства и методы при написании программы : таблица корректных хэшей. Хэши хранятся в формате чистого MD5 (без соли). Все данные записываются в буфер, после чего посимвольно каждый символ преобразовывается в HEX-представление. Из шестнадцатеричных кодов символов формируется строка, от которой берётся хэш. Все валидные хэши хранятся в векторе. Шестнадцатеричное представление позволяет обезопасить себя от брутфорса, т.к. с крайне малой вероятностью в готовых базах данных хэшей будут найдены хэши этого hex-представления. Затем полученный хэш логина ищется в векторе. В случае успеха - та же самая операция проделывается для пароля. В противном случае - программа завершает своё выполнение.

Коды ошибок :
-100 - обнаружен системный отладчик
-101 - логин/пароль неверен

Файлы :
zpid.cpp - файл с основным кодом
h.h - реализация MD5 хэша
