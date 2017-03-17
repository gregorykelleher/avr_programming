PROJECT_DIR = /Users/admin/Documents/avr_programming

ARDMK_DIR = /usr/local/opt/arduino-mk/

ARDUINO_DIR = /Applications/Arduino.app/Contents/Java

BOARD_TAG = mega
BOARD_SUB = atmega2560

MONITOR_BAUDRATE  = 9600

AVR_TOOLS_DIR     = /usr/local

CFLAGS_STD        = -std=gnu11
CXXFLAGS_STD      = -std=gnu++11
CXXFLAGS         += -pedantic -Wall -Wextra

MONITOR_PORT      = /dev/tty.usbserial-AL00A3CE

CURRENT_DIR       = $(shell basename $(CURDIR))

OBJDIR            = $(PROJECT_DIR)/bin/$(BOARD_TAG)/

include $(ARDMK_DIR)/Arduino.mk

