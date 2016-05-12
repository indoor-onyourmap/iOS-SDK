//
//  OYMFloorGoogleMaps.swift
//  Goindoor
//
//  Created by Joan Comellas on 23/03/16.
//  Copyright © 2016 OnYourMap. All rights reserved.
//

import Foundation
import GoogleMaps


private let kOYMTileOverlayBundleName = "goindoorTiles"
private let tilesBundle: NSBundle? =  {
    if let path = NSBundle.mainBundle().pathForResource(kOYMTileOverlayBundleName, ofType: "bundle") {
        return NSBundle(path: path)
    }
    return nil
}()

/**
   This extension will provided an initialized GMSURLTileLayer to be used in Google Maps.
 */
extension OYMFloor {
    
    /**
      Computed property that will return a GMSURLTileLayer for the current floor.
     */
    public var tile: GMSURLTileLayer {
        get {
            return GMSURLTileLayer { (x, y, zoom) -> NSURL! in
                let power = UInt(pow(Double(2), Double(zoom)))
                let y2 = power-y-1
                
                if let bundle = tilesBundle where bundle.pathsForResourcesOfType(nil, inDirectory: self.uuid).count > 0 {
                    return bundle.URLForResource(String(y2), withExtension: "png", subdirectory: String(format: "%@/%ld/%ld", self.uuid, zoom, x))
                } else {
                    let url = String(format: "https://indoor.onyourmap.com/indoor/getTiles.php?l=%@&x=%d&y=%d&z=%d", self.uuid, x, y2, zoom)
                    return NSURL(string: url)
                }
            }
        }
    }
    
}