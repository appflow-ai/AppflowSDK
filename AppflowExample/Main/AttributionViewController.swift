//
//  AttributionViewController.swift
//  appflow
//
//  Created by implus on 2022/3/29.
//

import UIKit
import AppflowSDK
import FBSDKCoreKit
import AdServices
import AppsFlyerLib
import Adjust

class AttributionViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        
    }
    func getcurrentDate()->String {
        let dateTime = 1648387320.916192
        let date = Date(timeIntervalSince1970: dateTime)
        let dateFormat = DateFormatter()
        dateFormat.dateFormat = "YYYY-MM-dd HH:mm:ss"
        return dateFormat.string(from: date)
    }

    @IBAction func appsfyerSimulation(_ sender: Any) {
        let attibution = ["af_message":"organic install",
                          "af_status":"Organic",
                          "install_time":getcurrentDate(),
                          "is_first_launch":"0",
        ]
        Appflow.shared.updateAttribution(attibution, source: .appsflyer, networkUserId: AppsFlyerLib.shared().getAppsFlyerUID())
    }
    
    
    @IBAction func adjustSimulation(_ sender: Any) {
        let attibution = ["adid":"32c3e0cedee1fce1ed4a27af4bbe5e8e98",
                          "network":"Organic",
                          "trackerName":"Organic",
                          "trackerToken":"0pfx3d3o",
        ]
        Appflow.shared.updateAttribution(attibution, source: .adjust, networkUserId: Adjust.adid())
    }
    
    @IBAction func branchSimulation(_ sender: Any) {
        let attibution = ["branch":"32c3e0cedee1fce1ed4ssa27af4bbe5e8e98",
                          "network":"Organic",]
        Appflow.shared.updateAttribution(attibution, source: .branch, networkUserId: Appflow.shared.getAppUserId())
    }
    
    @IBAction func facebookSimulation(_ sender: Any) {
        Appflow.shared.updateAttribution([:], source: .facebook,networkUserId:FBSDKCoreKit.AppEvents.shared.anonymousID)
    }
    
    //reference: https://dev.to/pauladozsa/how-to-add-apple-search-ads-attribution-to-your-ios-app-4p2g
    //Pass the 'token' data, the backend requests and processes
    @IBAction func appleSearchAdsHander(_ sender: Any){
        if #available(iOS 14.3, *) {
            if let attributionToken = try? AAAttribution.attributionToken() {
                let param = ["attributionToken": attributionToken]
                Appflow.shared.updateAttribution(param, source: .appleSearchAds)
            }
        }
    }
    
    func updateAppleSearchAdsAttribution(_ attribution:[String:Any]) {
        Appflow.shared.updateAttribution(attribution, source: .appleSearchAds)
    }
    @IBAction func customSimulation(_ sender: Any) {
        let attribution = [
            "status" : "non_organic",
            "channel" : "Google Ads",
            "campaign" : "Christmas Sale"
        ]
        Appflow.shared.updateAttribution(attribution, source: .custom)
    }
    
}

