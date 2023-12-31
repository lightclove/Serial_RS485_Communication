# Serial_RS485_Communication
Communication between Serial port and RS-485 on Arduino
The library of Arduinors485 https://github.com/arduino-libraries/arduinors485 is used for more visible examples than are given there

RS485 is a standard for serial communication in industrial environments. It's commonly used for communication between industrial control systems, sensors, and other devices
Serial (UART): This is a standard sequential port that is used to exchange data between Arduino and other devices, including computers. The Serial library is used to work with UART.

RS-485 (Recommended Standard 485) - это стандарт для последовательной двунаправленной передачи данных, используемый в промышленных и коммерческих приложениях. Вот некоторые из его особенностей:
    Дифференциальная передача данных: RS-485 использует дифференциальную передачу данных, что означает, что данные отправляются на двух проводах: один с положительным сигналом (A) и другой с отрицательным сигналом (B). Это делает интерфейс более устойчивым к помехам.
    Балансирование: RS-485 - симметричный интерфейс, который позволяет балансировать линию и уменьшать влияние смещения напряжения и помех. Это особенно важно для длинных кабелей и сред с высоким уровнем электромагнитных помех.
    Множество устройств: RS-485 поддерживает подключение множества устройств к одной линии. Это делает его подходящим для систем, в которых несколько устройств должны обмениваться данными.
    Поддержка полудуплексной и полнодуплексной передачи: RS-485 может работать как в полудуплексном, так и в полнодуплексном режимах. В полудуплексном режиме устройства могут либо передавать, либо принимать данные в определенный момент времени, в то время как в полнодуплексном режиме они могут одновременно передавать и принимать данные.
    Дальность передачи: RS-485 позволяет передавать данные на длинные расстояния, обычно до нескольких километров, в зависимости от скорости передачи данных и качества линии связи.
    Скорость передачи данных: RS-485 поддерживает различные скорости передачи данных, начиная от низких (несколько бит в секунду) и заканчивая высокими (десятки мегабит в секунду).
    Множественные топологии: RS-485 может использоваться в различных физических топологиях, включая линейную, звездную и шинную топологии.
    Поддержка множества протоколов: RS-485 является физическим уровнем и не предписывает специфический протокол передачи данных. Это означает, что вы можете использовать различные протоколы (например, Modbus, Profibus) поверх RS-485 в зависимости от ваших потребностей.
    Электрические параметры: RS-485 работает с напряжением в диапазоне от -7 В до +12 В. Это обеспечивает высокий уровень сигнала и помогает в уменьшении ошибок передачи данных.
    Half-Duplex vs. Full-Duplex: RS-485 может работать как в режиме полудуплекса (передача и прием чередуются) или полнодуплекса (передача и прием одновременны). Выбор зависит от конкретных требований системы.
Общие требования к RS-485 устройствам и линиям могут быть описаны в стандартах, таких как EIA/TIA-485, который содержит технические характеристики и рекомендации по применению.

Serial (UART): Это стандартный последовательный порт, который используется для обмена данными между Arduino и другими устройствами, включая компьютеры. Используется библиотека Serial для работы с UART.

