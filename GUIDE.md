# OYM Indoor SDK for iOS

## Introduction

This framework includes three different submodules to interact with our SDK:
- Indoor SDK
- Indoor Location SDK
- Indoor Routing SDK

In order to use this framework, it is required to include also the `links.framework` and the `Routing.bundle` in the project and add the `-ObjC` flag in the `Other Linker Flags`.


## Indoor SDK
This package is the base of the indoor library, where the connection and interaction with the server is performed. In this package, the main objects to handle buildings, floors and iBeacons are introduced as well as the OYMIndoor object that will handle all the communication and requests to the server.

### OYMFloor class
This class includes all the information regarding the floor items stored in the server. As well, it includes a tile provider to be used to overlap the indoor maps in the Google Map.

Parameter | Type | Description
--------- | ---- | -----------
uuid | NSString* | Unique ID
building | NSString* | Building ID
floor | NSNumber* | Floor number
type | NSString* | String defining the floor type
tileProvider | OYMTileProvider* | Tile provider for indoor tiles

> **Note:** This class can also offer the tiles using the Google Maps GMSURLTileLayer*. In order to be able to retrieve it from the OYMFloor object it is required to define the macro `INDOOR_HASGOOGLEMAP` before including the framework and include all the Google Maps for iOS frameworks [+info](https://developers.google.com/maps/documentation/ios/).

### OYMBuilding class
This class includes all the information regarding the Building shapes stored in the server. As well, it includes the floors related with the building.

Parameter | Type | Description
--------- | ---- | -----------
uuid | NSString* | Unique ID
name | NSString* | Building name
geometry | Geometry* | Building bounding box
type | NSString* | String identifying building type
floors | NSMutableDictionary* | Dictionary including the floors available in the building

### OYMIbeacon class

This class includes all the information regarding the iBeacon items stored in the server.

Parameter | Type | Description
--------- | ---- | -----------
uuid | NSString* | Unique ID
x | NSNumber* | WGS84 Longitude
y | NSNumber* | WGS84 Latitude
major | NSNumber* | iBeacon major
minor | NSNumber* | iBeacon minor
txPower | NSNumber* | Transmission power at 1m
uuidIbeacon | NSString* | iBeacon UUID
building | NSString* | Building ID
floor | NSString* | Floor ID
floornumber | NSNumber* | Floor number
type | NSString* | String defining the OYMIbeacon type
scanDate | NSString* | Scan date in ISO8601 format
status | int | Variable defining the iBeacon status

### OYMIndoor class and OYMIndoorDelegate
The OYMIndoor class is the basic object to perform any communication with the server and retrieve all the required information. It is provided with three constructors according to the user needs. The object is able to handle the reconnection to the server when it is lost due to timeout (30 min without activity).

Related to this class there is the OYMIndoorDelegate, that will handle all the responses from the indoor object.

Parameter | Type | Description
--------- | ---- | -----------
url | NSString* | URL to the server
user | NSString* | Username (user@indoor.test)
pwd | NSString* | Password
deleg | id&lt;OYMIndoorDelegate&gt; | Indoor delegate to handle the output of the SDK
*ac* | *BOOL* | *Flag to enable the autoconnect with the default number (3) of retries*
*attemps* | *int* | *Enables the autoconnect feature with the defined number of retries*

To initialize an OYMIndoor object we have three different constructors to be used according to the purpose:
- Constructor without autoconnect 

```objective-c
- (instancetype) initWithUrl:(NSString*)url andUser:(NSString*)user andPassword:(NSString*)pwd andDelegate:(id&lt;OYMIndoorDelegate&gt;)deleg
```
- Constructor with a fixed number (3) of reconnections

```objective-c
- (instancetype) initWithUrl:(NSString*)url andUser:(NSString*)user andPassword:(NSString*)pwd andDelegate:(id&lt;OYMIndoorDelegate&gt;)deleg withAutoconnect:(BOOL)ac
```
- Constructor with an user-defined number of reconnections

```objective-c
- (instancetype) initWithUrl:(NSString*)url andUser:(NSString*)user andPassword:(NSString*)pwd andDelegate:(id&lt;OYMIndoorDelegate&gt;)deleg withAutoconnectAttempts:(int)attempts
```

Once the OYMIndoor object is initialized, the delegate will be called.

If the connection to the server is successful, the *didLoginSucceed* delegate method will be called. In case that the process fails, the *didLoginFailedWithError:(NSString*)msg* will be called, with further information of the error. This two delegate methods are required.

The delegate also provides feedback with respect the autoconnect feature. When the session is expired the *didAutoconnectDisconnected* method is called while the library tries to reconnect to the server. When the reconnection is successful, the *didAutoconnectSucceed* callback is called. If the reconnection is not possible, the *didAutoconnectFailed* is called an the library will no longer be useful.

##### Example
If the user `user@indoor.test` with password `password` wants to connect to the server located at `https://indoor.onyourmap.com`, with a OYMIndoorDelegate defined called `delegate` and without autoconnection, the user shall use:
```objective-c
OYMIndoor* indoor = [[OYMIndoor alloc] initWithUrl:@"https://indoor.onyourmap.com" andUser:@"user@indoor.test" andPassword:@"password" andDelegate:delegate];
```

#### Get buildings
Once the user is correctly logged in to the server, the user can start retrieving information from the server. In order to retrieve the buildings available, there are several functions to match the user requirements for each case. It can be specified a list of IDs to be retrieved, a bounding box to limit the search and pagination.

Below the different methods to retrieve the buildings:

```objective-c
getBuildings
```

```objective-c
getBuildingsWithArray:(NSArray*)buildingIdList
```

```objective-c
getBuildingsWithBoundingBox:(NSString*)boundingBox
```

```objective-c
getBuildingsWithArray:(NSArray *)buildingIdList andBoundingBox:(NSString*)boundingBox
```

```objective-c
getBuildingsWithArray:(NSArray*)buildingIdList andBoundingBox:(NSString*)boundingBox andOffset:(int)offset andBucketSize:(int)bucketSize
```

Parameter | Type | Description
--------- | ---- | -----------
*buildingIdList* | *NSArray** | *List of the building ID that needs to be retrieved*
*boundingBox* | *NSString** | *Bounding box to limit the search*
*offset* | *int* | *List offset to be retrieved*
*bucketSize* | *int* | *Number of elements to be retrieved*

The delegate will provide the response to the request in its _didGetBuildings:(NSArray*)buildings succeeded:(BOOL)succeed_ method, where `buildings` is an array containing the requested buildings or `nil` if no buildings, and `succeed` a flag indicating if the process was successful.

##### Example
All the buildings available in the server need to be retrieved. The user shall use:
```objective-c
[indoor getBuildings];
```

#### Get iBeacons

In order to retrieve the iBeacons, it can be done by specifying the id(s) of the building or floor in which the iBeacons are located.

Below the different methods to retrieve the buildings:

```objective-c
getIbeaconsForUuid:(NSString*)uuid
```

```objective-c
getIbeaconsForArray:(NSArray*)ids
```

Parameter | Type | Description
--------- | ---- | -----------
*uuid* | *NSString** | *Building or floor ID whose iBeacons are requested*
*ids* | *NSArray** | *Building or floor ID list whose iBeacons are requested*

The delegate will provide the response to the request in its _didGetIbeacons:(NSArray*)ibeacons succeeded:(BOOL)succeed_ method, where `ibeacons` is an array containing the requested iBeacons or `nil` if no iBeacons, and `succeed` a flag indicating if the process was successful.


## Indoor Location SDK

This module is the base of the location library, where the indoor position using iBeacons is computed. This module provides a location provider that provides an indoor position based on iBeacons when the user is inside a building, and a GPS position when the user is outside.

The indoor location provider is able to define geofences per each building. A geofence can be seen as a circular When the user is entering in one of these, the provider will start retrieving the list of iBeacon for the building the user have entered and listening for iBeacons nearby to compute the position.

In order to compute the indoor position it is required an iPhone 4S or higher with iOS7 or higher. 

### OYMIndoorLocation class

This class includes all the fields necessary to get the user position, the location provider used and further useful information.

Parameter | Type | Description
--------- | ---- | -----------
latitude | double | WGS84 Latitude
longitude | double | WGS84 Longitude
used | int | Number of iBeacons used
accuracy | double | Position accuracy in meters
found | NSArray* | Array including the longitude, latitude and accuracy for each iBeacon in sight
floornumber | int | Floor number
type | int | Positioning type: `kOYMIndoorLocationTypeNo`, `kOYMIndoorLocationTypeIbeacon`, `kOYMIndoorLocationTypeGps`
bName | NSString* | Building name
buildingId | NSString* | Building ID
geofences | int | Number of geofences crossed

### OYMIndoorLocationLib

This class is the enter point for the indoor location provider. It offers the capability to start and stop the indoor location provider. It offers two types of indoor location:
- Based on the weighted average of the iBeacons in range (`kOYMIndoorLocationLibTypeAverage`)
- Based on the more powerful iBeacon in range (`kOYMIndoorLocationLibTypeClosest`)

Where if not defined, the weighted average type will be selected by default. It comes with different constructors according to the user needs:
- Constructor using the average type by default

```objective-c
- (instancetype) initWithUrl:(NSString*)webServiceUrl andUser:(NSString*)user andPassword:(NSString*)pwd withDelegate:(id&lt;OYMIndoorLocationDelegate&gt;)deleg
```
- Constructor using the user-defined type

```objective-c
- (instancetype) initWithUrl:(NSString*)webServiceUrl andUser:(NSString*)user andPassword:(NSString*)pwd withType:(int)posType andDelegate:(id&lt;OYMIndoorLocationDelegate&gt;)deleg
```

Parameter | Type | Description
--------- | ---- | -----------
webServiceUrl | NSString* | Server URL
user | NSString* | Username (user@foo.bar)
pwd | NSString* | Password
delegate | id&lt;OYMIndoorLocationDelegate&gt; | Indoor location delegate to handle the output of the SDK
*type* | *int* | *Indoor location type*

The delegate also provides feedback with respect the autoconnect feature. When the session is expired the *didAutoconnectDisconnected* method is called while the library tries to reconnect to the server. When the reconnection is successful, the *didAutoconnectSucceed* callback is called. If the reconnection is not possible, the *didAutoconnectFailed* is called an the library will no longer be useful.

#### startLocate

Once the object is created the indoor location provider can be started. In order to work it is required that the user grants the app with location services (`kCLAuthorizationStatusAuthorizedAlways`). The user can also define a desired update rate for the position.

The delegate will provide feedback with respect the start process. Then *didStartSuccessfully* method is called when the location provider is started correctly. If a problem appears while starting the provider, the *didFailStarting* methol will be called. The position updated will be provided in the _onPositionUpdate:(OYMIndoorLocation*)location_. These methods are required.

If the developer tries to start the library with the Location Services, the *locationServicesAreDisabled* method will be called, and if the user does not grant the right permission to the app and the developer tries to start the location provider, the *locationAlwaysAuthorizationRequired:(CLAuthorizationStatus)current* method will be called, providing to the developer the current authorization granted.

##### Example
If the user `user@indoor.test`, with password `pass` wants to connect to the server located at `https://indoor.onyourmap.com`, with an already OYMIndoorLocationDelegate defined called `delegate`, the user shall use:
```objective-c
OYMIndoorLocationLib* lib = [[OYMIndoorLocationLib alloc] initWithUrl:@"https://indoor.onyourmap.com" andUser:@"user@indoor.demo" andPassword:@"pass" withDelegate:delegate];
```

#### stopLocate
Once the indoor location provider is no longer used, the user shall stop it properly using the *stopLocate* method.


## Indoor Routing SDK

This module is the base of the routing library, which is an extension of the indoor SDK module that includes routing features. This module also handles the interaction with the server, and includes the OYMIndoorRouting object that will provide advanced routing methods.

### OYMArea class

This class includes all the information regarding POI and places stored in the server.

Parameter | Type | Description
--------- | ---- | -----------
uuid | NSString* | Unique ID
x | NSNumber* | WGS84 Longitude
y | NSNumber* | WGS84 Latitude
name | NSString* | Area name
building | NSString* | Buinding ID
floor | NSString* | Floor ID
floornumber | NSNumber* | Floor number
geometry | NSString* | Area boundix box
type | NSString* | String defining the Area type

### InstructionType enumeration

This enumeration includes all the possible instructions supported for the routing algorithm.

Value | Description
----- | -----------
TURNLEFT | Turn left
TURNRIGHT | Turn right
DOWNSTAIRS | Walk downstairs
UPSTAIRS | Walk upstairs
DOWNELEVATOR | Go downstairs with a lift
UPELEVATOR | Go upstairs with a lift
ARRIVAL | Arrive to your destination
STRAIGHT | Go straight ahead

### OYMInstruction class

This class defines an instruction being used in the routing algorithm.

Parameter | Type | Description
--------- | ---- | -----------
distance | double | Distance from the starting point
instruction | InstructionType | Instruction to apply at that distance
props | NSDictionary* | Dictionary including extra values to complete the instruction

### OYMRoutePoint class

This class helps to define a point with information of the floor and building to which is targeting.

Parameter | Type | Description
--------- | ---- | -----------
x | NSNumber* | WGS84 Longitude
y | NSNumber* | WGS84 Latitude
floornumber | NSNumber* | Floor number
buildingId | NSString* | Building ID

### OYMRouteProjectedPoint class

This class extends the OYMRoutePoint class by adding further useful information to describe points projected in the user route. The projected point will always lay on the route.

Parameter | Type | Description
--------- | ---- | -----------
x | NSNumber* | WGS84 Longitude
y | NSNumber* | WGS84 Latitude
floornumber | NSNumber* | Floor number
buildingId | NSString* | Building ID
distanceFromStart | NSNumber* | Distance in meters from the starting point
distanceToShape | NSNumber* | Distance between the user and the shape
bearing | NSNumber* | Orientation of the route segment in which the user is, counted clockwise from the north

### OYMRoutingResult class

This class helps the developer to project the current position into a route. As well provides information whether the user is too far away from the route and the route should be recomputed.

Parameter | Type | Description
--------- | ---- | -----------
projectedPoint | OYMRouteProjectedPoint* | User position to the route
isRecomputeRequired | BOOL | Flag indication whether the user should recompute its route

### OYMIndoorRouting class

The IndoorRouting class inheritates from the OYMIndoor class, hence it will handle all the communication with the server. In addition of all the features OYMIndoor class provides, this class allows the user to retrieve the list of places/POI from the server. It has the same three constructors described for the OYMIndoor class.

#### Get Area

Once the user is correctly logged in to the server as explained in the OYMIndoor class, the user can start retrieving information from the server. In order to retrieve the places/POI available, there are several functions to match the user requirements for each case. It can be specified a single ID or a list of IDs to be retrieved.


Below the different methods to retrieve the areas:

```objective-c
getAreasForUuid:(NSString*)uuid
```

```objective-c
getAreasForArray:(NSArray*)ids
```

The delegate will provide the response to the request in its _didGetAreas:(NSArray*)areas succeeded:(BOOL)succeed_ method, where `areas` is an array containing the requested areas or `nil` if no areas, and `succeed` a flag indicating if the process was successful.

### OYMRouting class

This class handles the Routing algorithm interface to the developer. It is required when the user wants to create a route from A to B. in order to initialize the object, the building ID where the routing is required, an initialized and logged in IndoorRouting object and a OYMIndoorRoutingDelegate shall be provided.

Parameter | Type | Description
--------- | ---- | -----------
ind | OYMIndoorRouting* | Initialized and logged in OYMIndoorRouting object
bId | NSString* | Building ID whose routing needs to be started
del | id&lt;OYMIndorDelegate&gt; | Indoor Routing delegate to handle the process

#### initRouting

Once the object has been properly created it needs to be initialized. If the object is not correctly initialized the user will not be able to compute routes.

In order to handle the process the *didRoutingSucceed:(BOOL)succeed* method in the delegate will be used. The `succeed` flag will notify whether the object has been initialized properly and if routes can be computed.

##### Example
The OYMRouting object needs to be created and initialized for the building with ID defined in `buildingId` and the OYMIndoorRouting object `indoor` is initialized and logged in. The OYMIndoorRoutingDelegate is already defined under `delegate`.
```objective-c
OYMRouting* routing = [[OYMRouting alloc] initWithIndoor:indoor andBuilding:buildingId andDelegate:delegate];
[routing initRouting];
```

#### Compute Route

This method is used to compute a route from one point to another. In order to work it requires a OYMRoutePoint to identify the start point and another OYMRoutePoint to identify the destination.

##### Example
It is required to compute a route from the defined OYMRoutePoint `start` to the defined destination OYMRoutePoint `destination` using the OYMRouting object `routing` already defined and initialized.
```objective-c
OYMRoute* route = [routing computeRouteFrom:start to:destination];
```

### OYMRoute class

This object defines the route to be followed. It includes information regarding the points, instructions to be shown, distance in meters and an estimation of the route time.

Parameter | Type | Description
--------- | ---- | -----------
route | NSArray* | Array of OYMRoutePoint containing the route
instructions | NSArray* | List of OYMInstruction to follow
distance | NSNumber* | Route distance in meters
time | NSNumber* | Route time in seconds








