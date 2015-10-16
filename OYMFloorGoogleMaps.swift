//
//  OYMFloorGoogleMaps.swift
//  Goindoor
//
//  Created by Joan Comellas on 15/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

import Foundation
import GoogleMaps

extension OYMFloor {
    
    public var tile:GMSURLTileLayer {
        get {
            return GMSURLTileLayer { (x, y, zoom) -> NSURL! in
                let power = UInt(pow(Double(2), Double(zoom)))
                let y2 = power-y-1
                
                let url = NSString(format: "https://indoor.onyourmap.com/indoor/getTiles.php?l=%@&x=%d&y=%d&z=%d", self.uuid, x, y2, zoom) as String
                return NSURL(string: url)
            }
        }
    }
    
}