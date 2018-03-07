# Goindoor SDK for iOS

## Introduction

The Goindoor framework handles the communication to the server and provides easy access to the developer to the data, as well as several addition features, such as location provider, routing, statistics and asset management.
An extensive developer documentation can be found [here](http://indoor-onyourmap.github.io/iOS-SDK/).


## Preparing environment
The Base SDK version used in the project shall be iOS7. It is also required to add the `–ObjC` flag under the Linking section in the Building Settings.

The Routing bundle is required to provide a basic icons and strings for the routing.

This framework can work with most of the Maps API available. It is possible to use Google Maps by using the `OYMFloor(GoogleMaps)` category. In this case, it is required to add all the Google Maps for iOS frameworks [+info](https://developers.google.com/maps/documentation/ios/).

Starting from version 2.4.0, this SDK will also require the ZipZap framework and the libz and libc++ libraries to compile.

### CocoaPods
The Goindoor framework is also available through CocoaPods. It can be added to your existing project by adding the following line to the `Podfile`

```ruby
pod 'GoIndoor'
```

## Preparing a sample app
In order to use the indoor framework, a basic iOS app shall be created. After making all the modifications mentioned in the previous section, it is necessary to bear in mind that the application is using the Bluetooth and WiFi/Network connection; hence it is necessary to check that all this features are available.
The next step is to define a delegate class that conforms to the `OYMLocationDelegate` protocol. This delegate will be called each time a position is computed. It also provides information whether the Location provider have been started properly.

```objectivec
/**
 *  This delegate will provide feedback to the user regarding the indoor location library.
 */
@protocol OYMLocationDelegate <NSObject>

@required
/**
 *  This method is called when the indoor location service has been
 * correctly started.
 */
- (void) didStartSuccessfully;
/**
 *  This method is called when an exception is thrown when trying to
 * start the indoor location service.
 */
- (void) didFailStarting;
/**
 *  This method is called when a new position is available.
 *
 * @param location User position
 */
- (void) onLocation:(OYMLocationResult*)location;
/**
 *  This method is callen when a notification is triggered.
 *
 * @param notification Notification triggered
 */
- (void) onNotification:(OYMNotificationResult*)notification;


@optional
/**
 *  This method is called when the app has not the right authorisation for the Location Services.
 *
 * @param current Current Authorisation Permission
 */
- (void) locationAlwaysAuthorizationRequired:(CLAuthorizationStatus)current;
/**
 *  This method is called when the Location Services are disabled.
 */
- (void) locationServicesAreDisabled;
/**
 *  This method is called when the Core Blueooth Central Manager state has changed.
 *
 * @param state The new Core Blueooth Central Manager state
 */
- (void) centralManagerDidChangeState:(enum CBCentralManagerState)state;

@end
```

The `OYMLocationResult` object includes the following fields:

```objectivec
/** WGS84 Latitude */
@property (readonly) double latitude;
/** WGS84 Longitude */
@property (readonly) double longitude;
/** Number of iBeacons used */
@property (readonly) int used;
/** Position accuracy (meters) */
@property (readonly) double accuracy;
/** List including the longitude, latitude and accuracy of each iBeacon in sight */
@property (readonly) NSArray* found;
/** Floor number */
@property (readonly) int floorNumber;
/** Positioning type: kOYMIndoorLocationTypeNo, kOYMIndoorLocationTypeIbeacon, kOYMIndoorLocationTypeGps */
@property (readonly) int type;
/** Building name */
@property (readonly) NSString* buildingName;
/** Building ID */
@property (readonly) NSString* building;
/** Number of geofences */
@property (readonly) int geofences;
```

The following step is to create a new instance of the goindoor library:

```objectivec
go = [OYMGoIndoor goIndoorWithBlock:^(id<GoIndoorBuilder> builder) {
       [builder setAccount:account];
       [builder setPassword:password];
       [builder setConnectCallBack:callback];
   }];
```

In order to start the location service, it is required to provide an object that conforms the `OYMLocationDelegate` protocol to the library.

```objectivec
[go startLocate:delegate];
```

After starting the library, the delegate will be used when a new position is computed.

### Exiting the app
In order to stop properly the library, it is necessary to call the stopLocate method when the library is no longer needed and the location service should be stopped

```objectivec
[go disconnect];
```

## Creating a route
In order to create a route between two points, these points need to be encoded inside a `OYMRoutePoint` object.

```objectivec
- (OYMRoutePoint*) initWithX:(NSNumber*)newX andY:(NSNumber*)newY andFloornumber:(NSNumber*)fn andBuildingId:(NSString*)bId;
```

To get the `OYMRoute` object, it just required to use the `computeRoute()` method:

```objectivec
OYMRoute* route = [go computeRouteFrom:start to:destination];
```


### Projecting position to the route
Once a route is computed, it is possible to project the user position to the computed route by using the `getProjectionForLocation:(OYMLocationResult*)` method inside the `OYMRoute` object. This method will provide a `OYMRoutingResult` that will provide the user position on top of the route, a flag telling whether the user is too far away from the route and further useful information.


## Showing indoor maps
### MapKit integration
The Goindoor library includes a list of the buildings available for the account. In each Building object, it includes all the floors available for that building, including their tile providers. In order to show the indoor maps overlap in MapKit framework, the framework include a helper class `OYMTileOverlay` that inherits from `MKTileOverlay`. This object can be retrieved from the `OYMFloor` class and overlay it on a `MKMapView` instance.

```objectivec
tileOverlay = f.tileProvider;
[mapView addOverlay:tileOverlay level:MKOverlayLevelAboveLabels];
```

### Google Maps integration
Goindoor can also be used in Google Maps for iOS. In order to ensure the compatibility, it is required to include the `OYMFloor+GoogleMaps` category for available in this repo. This category will provide with a `tileProviderGoogle` variable of type `GMSURLTileLayer` to be integrated in the `GMSMapView`.
Assuming that the `OYMFloor` to be shown is the variable `floor` and the `map` variable has been correctly initialized, to overlay the indoor tiles in Google Maps it should be done as in the following example.

```objectivec
GMSURLTileLayer *layer = floor.tileProviderGoogle;
layer.map = map;
```

## Exiting the app
Before exiting the app it is advisable to disconnect from the server. For that, the `disconnect` method shall be called.

```objectivec
[go disconnect];
```
