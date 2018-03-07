# Changelog

## 2.4.0 (2018-03-06)
#### Added features
- Introducing indicators
- Introducing combinations
- Introducing multi-building routing
#### Bugs fixed
- Improving closest POI logic
- Improving instruction creation, end route and wrong direction detection
- Improving beacon handling
- Fixing string typos


## 2.3.2 (2017-04-27)
#### Added features
- Adding CocoaPods support


## 2.3.1 (2017-03-24)
#### Bugs fixed
- Correcting issue that might lead to consider the start edge as both direction under some circumstances


## 2.3.0 (2016-11-23)
#### Added features
- Using the new www.goindoor.co servers

#### Bugs fixed
- Improving instruction creation


## 2.2.4 (2016-07-27)
#### Added features
- Projection is done in edges that fulfill the properties
- Adding possibility to set CBCentralManager options
- Adding centralManagerDidChangeState in OYMLocationProtocol

#### Bugs fixed
- Correcting beacon maintenance in multiple floors


## 2.2.3 (2016-06-15)
#### Bugs fixed
- Improving SDK performance


## 2.2.2 (2016-06-06)
#### Bugs fixed
- Fixing issue that might prevent in some cases the SDK to be updated without connection
- Correcting how indoor location computation is triggered when GPS signal is unreliable


## 2.2.1 (2016-05-26)
#### Bugs fixed
- Fixing issue that might prevent the SDK to be updated without wifi connection
- Improving SDK performance


## 2.2.0 (2016-05-12)
#### Added features
- Introducing Offline tiles

#### Bugs fixed
- Correcting position log
- Correcting a bug that might not decode some edge properly under some circumstances
- Improving data sync
- Adding WebService UTF-8 support


## 2.1.1 (2016-03-10)
#### Bugs fixed
- Correcting a bug that might not update to the most updated data when starting the SDK


## 2.1.0 (2016-03-07)
#### Added features
- Adding offline mode
- Introducing proxibeacons
- Removing Links framework

#### Bugs fixed
- Correcting how location update is provided

#### :warning: Deprecated methods
- x and y variables have been deprecated in favor of longitude and latitude
- Introducing new Geometry class


## 2.0.7 (2016-01-22)
#### Bugs fixed
- Improving switching floors experience


## 2.0.6 (2016-01-14)
#### Bugs fixed
- Correcting bug that might prevent to get places
- Removing log statements


## 2.0.5 (2015-12-14)
#### Bugs fixed
- Correcting how floor ID is computed in OYMLocationResult


## 2.0.4 (2015-11-17)
#### Added features
- Location algorithm can be changed after GoIndoor initialization

#### Bugs fixed
- Correcting support for stairs, lifts and escalators


## 2.0.3 (2015-10-15)
#### Bugs fixed
- Google Maps support is now done through OYMFloor(GoogleMaps) category
- Removing dSYM warnings
- Correcting notification filtering for empty strings


## 2.0.2 (2015-10-05)
#### Added features
- Enabling bitcode

#### Bugs fixed
- Correcting floor change delay
- Introducing LOCATION_TYPE_PROJECT
- Correcting notification filtering for number values


## 2.0.0 (2015-09-18)
#### Added features
- Introducing new GoIndoor class
- Multimodal navigation
- Asset finder
- Automatic maintenance


## 1.4.0 (2015-06-17)
#### Added features
- Adding Eddystone support

#### Bugs fixed
-Correcting how nearby notifications are triggered


## 1.2.2 (2015-06-16)
#### Bugs fixed

- Notification properties decoding
- Correcting notifications triggering system

## 1.2.1 (2015-06-04)
#### Bugs fixed
- iOS7 devices might crash when the indoor location library was initialized
- Correcting how routes are computed
- Updating appledoc


## 1.2.0 (2015-05-28)
#### Added features
- Notification support


## 1.0.0 (2015-05-01)
- Initial commit
