# Changelog

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
