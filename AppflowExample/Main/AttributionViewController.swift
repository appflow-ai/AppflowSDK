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
import iAd
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
        Appflow.shared.updateAttribution(attibution, source: .appsflyer, networkUserId: "appsflyer_id")
    }
    
    
    @IBAction func adjustSimulation(_ sender: Any) {
        let attibution = ["adid":"32c3e0cedee1fce1ed4a27af4bbe5e8e98",
                          "network":"Organic",
                          "trackerName":"Organic",
                          "trackerToken":"0pfx3d3o",
        ]
        Appflow.shared.updateAttribution(attibution, source: .adjust)
    }
    
    @IBAction func branchSimulation(_ sender: Any) {
        let attibution = ["branch":"32c3e0cedee1fce1ed4ssa27af4bbe5e8e98",
                          "network":"Organic",]
        Appflow.shared.updateAttribution(attibution, source: .branch)
    }
    
    @IBAction func facebookSimulation(_ sender: Any) {
        Appflow.shared.updateAttribution([:], source: .facebook,networkUserId:FBSDKCoreKit.AppEvents.shared.anonymousID)
    }
    
    //reference: https://dev.to/pauladozsa/how-to-add-apple-search-ads-attribution-to-your-ios-app-4p2g
    @IBAction func appleSearchAdsAction(_ sender: Any) {
        if #available(iOS 14.3, *) {
            if let attributionToken = try? AAAttribution.attributionToken() {
                let request = NSMutableURLRequest(url: URL(string:"https://api-adservices.apple.com/api/v1/")!)
                request.httpMethod = "POST"
                request.setValue("text/plain", forHTTPHeaderField: "Content-Type")
                request.httpBody = Data(attributionToken.utf8)
                let task = URLSession.shared.dataTask(with: request as URLRequest) {[weak self] (data, _, error) in
                    guard let `self` = self else { return }
                    if let error = error {
                        print(error)
                        return
                    }
                    do {
                       let result = try JSONSerialization.jsonObject(with: data!, options: .allowFragments) as! [String:Any]
                        print("Search Ads attribution info:", result)
                        //*** this upload apple search datas ***
                        self.updateAppleSearchAdsAttribution(result)
                        if let campaignId = result["campaignId"] as? Int {
                        // Only send data to Amplitude if it is not mock data, in which case the campaign id would be the integer below
                            if campaignId != 1234567890 {
                                // Send data to your tracking tool, we use Amplitude, with the line of code below.
                                // Amplitude.instance().logEvent("open_app_from_apple_search_ad, with EventProperties: result)
                            }
                        }
                    } catch {
                       print(error)
                    }
                }
            task.resume()
            }
        }else {
            ADClient.shared().requestAttributionDetails({ (attributionDetails, error) in
                guard let attributionDetails = attributionDetails else {
                    print("Search Ads error: \(error?.localizedDescription ?? "")")
                    return
                }
                for (version, adDictionary) in attributionDetails {
                    print("Search Ads version:", version)
                        if var attributionInfo = adDictionary as? Dictionary<String, Any> {
                            //*** this upload apple search datas ***
                            print("Search Ads attribution info:", attributionInfo)
                            self.updateAppleSearchAdsAttribution(attributionInfo)
                            if let campaignId = attributionInfo["iad-campaign-id"] as? String {

                            // Only send data to Amplitude if it is not mock data, in which case the campaign id would be the string of numbers below
                            if campaignId != "1234567890" {
                                // Add campaignID attribute in order to have consistent property which which to segment users on all iOS versions
                                attributionInfo["campaignId"] = campaignId
                                // Send data to your tracking tool, we use Amplitude, with the line of code below.
                                // Amplitude.instance().logEvent("open_app_from_apple_search_ad, with EventProperties: attributionInfo)
                            }
                        }
                    }
                }
            })
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

