.DEFAULT_GOAL := all
.PHONY: deps build upload all

deps:
	arduino-cli core install arduino:avr
	arduino-cli lib install LiquidCrystal@1.0.7

build:
	arduino-cli compile --fqbn arduino:avr:mega .

upload:
	arduino-cli upload --fqbn arduino:avr:mega -p /dev/ttyUSB0 .

all: deps build upload