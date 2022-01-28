# LineScanner
An Arduino that drives a Parallax line-scan camera module [TSL1401-DB (#28317)](https://eu.mouser.com/ProductDetail/Parallax/28317?qs=%2Fha2pyFaduiCRhuOAXMuCmQIeG1Q3R01m6Y1EH%252BmN80%3D) in continuous acquisition mode.

- Arduino UNO (default serial buffer size 64) ~ 20 fps.
- Arduino UNO (serial buffer size 512) ~ 43 fps.- 
- Arduino Due (TBA).

## Circuit diagram

![circuit_dark](https://user-images.githubusercontent.com/89871015/135935393-ee9d5ee6-431d-4c14-a326-cdcd8c534669.png)

## Commands

The acquired frames are sent continuously via serial port as an array of 260 bytes (130 pixels) with the first and last values set to zero for alignment purposes.

## Software 

The LineScanner is part of the [microEye](https://github.com/samhitech/microEye) microscopy control system and is used to track the peak position of a totally internally reflected IR beam to achieve automatic focus stabilization.

![control_module](https://user-images.githubusercontent.com/89871015/141841883-d37c4979-c8aa-4e1f-b1b9-84bdd819c828.png)


## Authors

Mohammad Nour Alsamsam

[![Twitter URL](https://img.shields.io/twitter/url/https/twitter.com/samhightech.svg?style=social&label=Follow%20%40samhightech)](https://twitter.com/samhightech)
    
