# midi-controller

This project is a implementation of firmware for a midi controller using Arduino Mega.

## Requirements

### Arch Linux

```
$ pacman -S arduino-cli
```
or
```
$ yay -S arduino-cli
```

## Install dependencies

In your terminal:

```
$ arduino-cli lib uninstall LiquidCrystal@1.0.7
```

## How to compile

Adjust the compile.sh to your needs and:

```
$ ./compile.sh
```

## How to upload

Adjust the upload.sh to your needs then:

```
$ ./upload.sh
```
