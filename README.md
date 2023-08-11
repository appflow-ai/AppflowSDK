# AppflowSDK
Platform：iOS
Version：v1.0.9

## 1. SDK integration
##### AppflowSDK provides one integration methods for iOS developers to choose:
- Pass through CocoaPods integrated
### Pass through CocoaPods integrated

```
target 'MyApp' do
    use_frameworks!
    pod 'AppflowSDK', '~> 1.0.9'
end
```
Save and execute pod install, then open the project with a file suffixed with .xcworkspace.
```
pod install
```
> Notice:
> Execute pod search AppflowSDK under the command line. If the displayed version of **AppflowSDK** is not the latest, execute the pod repo update operation to update the content of the local repo
> For more information on CocoaPods please see [ CocoaPods](https://cocoapods.org/)。

## 2. Initialize SDK

### Add configuration file

> Download the **appflow-app-token.json** file, Add to targets to the project. 
> Select Copy Items if needed.
> Create groups.
> Add to targets.

### import header file
Import the header file in the project's AppDelegate file
```
import AppflowSDK
```
## Setup
```
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        //AppflowSDK initialization
        Appflow.shared.configure()
        return true
}
```
### Enable SDK log (optional)
#### You can enable SDK log output before initializing the SDK

```
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    // Override point for customization after application launch.
    
    //AppflowSDK initialization
    Appflow.shared.configure()
    //Whether to enable in-app purchase related logs, the default is not
    Appflow.shared.setPurchasesLogs(enabled: true)
    //Whether to enable the log related to the buried point, the default is not
    Appflow.shared.setAnalyticsLogs(enabled: true)
    return true
}
```


## 3. Purchases
> Ready to work
> a. Configure product information in apple store
> 
> b. Add product information in appflow platform

### Get product id of in-app purchase

```
 Appflow.shared.getPurchaseProductIds { productIdArray, error in 
 
 }
```
**API Reference**
| getPurchaseProductIds                             |                  |
| ----------------------------------------- | ---------------- |
| error = nil    | Success callback |
| error != nil   | Failure callback |

| error: Error   |                  |
| -------------- | ---------------- |
| code           | error code       |
| message        | error message    |

| Parameter returned: data type             | Tnstructions     |
| ----------------------------------------- | ------------------------------------------------------------ |
| productIdArray: [string]                  | Returns the Appflow platform configuration ProductID  |


### Get the sku information of in-app purchases
Displaying Products
To fetch the products sku information, you have to call method:

According to the interface `getSkuDetails`, you need to pass in the Set <product_Ids> of in-app purchases, the return value is a dictionary, `product_id` is key, value: `SKProduct` object
```
Appflow.shared.getSkuDetails(productIds: Set(productIDs)) { skuDetailInfo, error in
    
};
```
**API Reference**
| getSkuDetails                             |                  |
| ----------------------------------------- | ---------------- |
| error = nil    | Success callback |
| error != nil   | Failure callback |

| error: Error   |                  |
| -------------- | ---------------- |
| code           | error code       |
| message        | error message    |

| Request parameter: data type              | Tnstructions      |
| ----------------------------------------- | ------------------------------------------------------------------ |
| productIds: Set<String>                   | The parameter is the product ID configured in the Apple background |

| Returned parameter: data type             | Tnstructions                                                 |
| ----------------------------------------- | ------------------------------------------------------------ |
| skuDetailInfo: [String:SKProduct]         | key - value, Return SKProduct                                |

After obtaining `SKProduct`, you can obtain information related to in-app purchases, and developers can save them in their own projects. Subsequent payment needs to be used.
> SKProduct, please refer to the official documentation of Apple[:](https://developer.apple.com/documentation/storekit/skproduct)

### Check if payment available
```
 let canMakePurchases = Appflow.shared.canMakePayment()
```
> This interface returns data of type 'bool'. True: indicates that payment can be pulled up. False: indicates that payment cannot be pulled up

### Making purchase
To start the purchase process call function purchaseProduct it will take `SKProduct` object as a parameter.

> NOTE: After the in-app purchase is completed, uploadUserInfo must be reported, which is mainly used for user data attribution.
>
> 1. If the developer has integrated the purchase method of AppflowSDK (Appflow.shared.purchaseSKProduct). There will be no need to process and report user information after subscription, this step has been completed automatically, (versions after V1.0.7 will be automatically reported, and versions before V1.0.7 need to be manually reported by developers)
> 2. If the developer does not integrate the method of purchasing goods in AppflowSDK, the developer will need to manually handle it. After the user completes the purchase, use this method uploadUserInfo to report the user information, where UserId is not a mandatory parameter

```
// After V1.0.7, it will be automatically reported after subscription
Appflow.shared.purchaseSKProduct(skProduct) { transaction, subscriber, error, canceled in
    if canceled || error != nil {
        print("Canceled")
    } else {
        print("Completed")
    }
}

// Before V1.0.7, the subscription must be reported manually, otherwise it will lead to data loss
Appflow.shared.purchaseSKProduct(skProduct) { transaction, subscriber, error, canceled in
    if canceled || error != nil {
        print("Canceled")
    } else {
        // Manually report user information after subscription is complete
        Appflow.shared.uploadUserInfo()
    }
}
```
> Closure will return `SKPaymentTransaction`, entitlement dictionary, error if it occurred and bool to indicate if a user canceled the purchase process.

```
 Users can use **IMSubscriber.isActive** to determine the subscription status. true: subscribed\purchased; false: unsubscribed\unpurchased
 IMSubscriber.expireAt, Return the expiration time of the current subscription. You can compare `expireAt` with the current time and process the subscription status
```


**API Reference**
| purchaseSKProduct                         |                  |
| ----------------------------------------- | ---------------- |
| error = nil    | Success callback |
| error != nil   | Failure callback, **Note**: A user's subscription status cannot be determined by ERROR.Please use:`isActive` or `expireAt` |

| error: Error   |                  |
| -------------- | ---------------- |
| code           | error code       |
| message        | error message|

| Request parameter: data type  | Tnstructions        |
| ----------------------------- | ------------------- |
| product: SKProduct            | Product information |

| Returned parameter: data type       | Tnstructions                                                 |
| ----------------------------------- | ------------------------------------------------------------ |
| transaction: SKPaymentTransaction   | An object in the payment queue. [SKPaymentTransaction|](https://developer.apple.com/documentation/storekit/skpaymenttransaction) |
| isCanceled: Bool                    | Cancel the payment  |

| entitlement: IMSubscriber           | Tnstructions                                                 |
| ----------------------------------- | ------------------------------------------------------------ |
| productId: String                   | product id |
| expireAt: Int64                     | Expiration time of the subscription (millisecond) |
| isActive: Bool                      | product subscription\purchase status, true: subscribed\purchased; false: unsubscribed\unpurchased |
| imEntitlement: [IMEntitlement]      | check entitlement for current status |
| imSubscription: [IMSubscription]    | subscription details by product_id |

| IMEntitlement                       | Tnstructions                                                 |
| ----------------------------------- | ------------------------------------------------------------ |
| id: String                          | product group id      |
| expireAt: Int64                     | Expiration time of the subscription (millisecond) |
| isActive: Bool                      | product subscription\purchase status, true: subscribed\purchased; false: unsubscribed\unpurchased |
| productId: String                   | product id |

| IMSubscription                      | product Id                                                 |
| ----------------------------------- | ------------------------------------------------------------ |
| status: IMSubscriberStatus          | SubscriptionState_State |
| expireAt: Int64                     | Expiration time of the subscription (millisecond) |
| cancelAt: Int64                     | Time to unsubscribe (millisecond) |
| willRenewTo: String                 | The next subscription ID to switch: Product ID |
| originalTransactions: [IMSubscriptionOriginalTransaction]  | Original transactions |

| IMSubscription                      | product Id                                                 |
| ----------------------------------- | ------------------------------------------------------------ |
| originalTxid: String                | Original order note |
| expireAt: Int64                     | Expiration time of the subscription (millisecond) |
| startAt: Int64                      | Time to start the subscription (millisecond) |


### Checking user status
To check if user have any active subscriber call function `hasActiveSubscription`
```
Appflow.shared.hasActiveSubscription({ [weak self] subscriber, error in
    guard let `self` = self else { return }
    var status = "pro not active"
    if error == nil {
        if subscriber.isActive {
            status = "pro active"
        }
        self.statusLabel.text = "Subcription status: \(status)"
    }
})

```
```
 Users can use **IMSubscriber.isActive** to determine the subscription status. true: subscribed\purchased; false: unsubscribed\unpurchased
 IMSubscriber.expireAt, Return the expiration time of the current subscription. You can compare `expireAt` with the current time and process the subscription status
```

### Restoring purchases
To restore user purchases call restorePurchases function.

```
Appflow.shared.restorePurchases { (subscriber, error) in
    if error == nil {
        if subscriber.isActive {
            // Purchase restored and have active entitlment
        }else {
            // Purchase restore finished but user don't have active entitlment
        }
    }
}
```
```
 Users can use **IMSubscriber.isActive** to determine the subscription status. true: subscribed\purchased; false: unsubscribed\unpurchased
 IMSubscriber.expireAt, Return the expiration time of the current subscription. You can compare `expireAt` with the current time and process the subscription status
```

### UploadUserInfo

Introduction: If you need to associate the userId in your application with the Appflow platform, then the developer needs to choose an appropriate time to report **userId** to the Appflow platform, for example, when your application logs in. Where **useId** is the unique identifier defined in the App.

`Appflow.shared.uploadUserInfo(userId: "xxx") { _, _ in   }`

#### expand
##### Add a json string field in the UploadUserInfo API to support developers uploading map<string, string> type data. It supports fixed fields: username, email, phone, gender, age.
> - Field:
> - All key , value length limit is 128 , calculated according to toString characters
> - The fixed fields are username, email, phone, gender, age, please refer to the table below, gender is a number, and the meaning is shown in the table
> - There are no restrictions on the type of additional fields added by the user, both numbers and strings can be used
> - If you need to report user-related data, report it through the following methods

field | type |
---|---
username | string
email | string
phone | string
gender | number(FEMALE = 1, MALE = 2, OTHER = 3)
age | number



```
//uploadUserInfo to extraAttribute
Appflow.shared.uploadUserInfo(userId: "app_user_idxxxxx", extraAttribute: extraAttribute) {[weak self] _, _ in
}
```


## 4. Event tracking
You can send statistics events to Appflow backend in the following ways

```Swift
//Send an event with params, If you have no arguments you can just pass 'nil'
uploadBigDataWithType(eventName: String, params: [AnyHashable : Any]?)
```

**Example**

```Swift
//Send an event with no parameters
Appflow.shared.uploadBigDataWithType(eventName: "test_event", params: nil)
//Send an event with parameters
var params:[AnyHashable : Any] = [AnyHashable : Any]()
params["name"] = "abc"
arams["age"] = 18
Appflow.shared.uploadBigDataWithType(eventName: "test_event", params: params)

```

> If you want to check whether an event was reported successfully, you can open AnalyticsLogs with the following code:
>> Appflow.shared.setAnalyticsLogs(enabled: true)



## 5. Push notification
### a. Capabilities
Please enable the Capabilities->Push Notifications option of Application Target
### b. Request PushNotifications Permissions in AppDelegate

```
private func requestPushNotificationsPermissions() {
    let userNotificationCenter = UNUserNotificationCenter.current()
    userNotificationCenter.requestAuthorization(options: [.alert, .sound, .badge]) { [weak self] granted, error in
        print("Permission granted: \(granted)")
        if granted {
            self?.getNotificationSettings()
        }
    }
}
```
### c. Permission request completed, get notification settings

```
private func getNotificationSettings() {
    UNUserNotificationCenter.current().getNotificationSettings { settings in
        print("Notification settings: \(settings)")
        guard settings.authorizationStatus == .authorized else { return }
        DispatchQueue.main.async {
            UIApplication.shared.registerForRemoteNotifications()
        }
    }
}
```
### d. Successfully register APNs and report DeviceToken
```
func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
    let deviceToken = deviceToken.reduce("", { $0 + String(format: "%02X", $1) })
    Appflow.shared.purchases.uploadDeviceInfo(deviceToken: deviceToken) { _, _ in
    }
}
```

## 6. Paywall
The SDK provides a shortcut for displaying paid products. After setting the style in Appflow plaltform, you can display it by call method:

```
Appflow.shared.loadPaywallToPurachase {[weak self] result, msg in
    guard let `self` = self else { return }
    if result == false {
        //if false , Developers can jump to the native payment page
    }
}
```



## 7. Attribution
Appflow supports Appsflyer, Adjust, Branch, Apple search ads, FacebookAds and custom attribution data upload，you have to call method:
### Appsflyer
To upload Appsflyer attribution data, the developer accesses the appsflyer SDK and reports the data in the AppsFlyerLibDelegate method, refer to the example below,which **networkUserId **cannot be empty

```
extension AppDelegate: AppsFlyerLibDelegate {
    func onConversionDataFail(_ error: Error) {
        //appsflyer is fail
    }
    
    func onConversionDataSuccess(_ installData: [AnyHashable : Any]) {
        // It's important to include the network user ID
        Appflow.shared.updateAttribution(installData, source: .appsflyer, networkUserId: AppsFlyerLib.shared().getAppsFlyerUID())
        
    }
}
```
### Adjust
To upload Adjust attribution data, the developer accesses the Adjust SDK and reports the data in the AdjustDelegate method, refer to the example below

```
extension AppDelegate: AdjustDelegate {
    //Callback for the first app installation
    func adjustAttributionChanged(_ attribution: ADJAttribution?) {
        // Just pass Adjust attribution to Adapty SDK
        if let attribution = attribution?.dictionary() {
            //networkUserId:Adjust.adid()
            Appflow.shared.updateAttribution(attribution, source: .adjust, networkUserId: Adjust.adid())
        }
    }
    
}
```

### Branch
To upload Adjust attribution data, the developer accesses the Adjust SDK and reports the data in the andRegisterDeepLinkHandler block, refer to the example below

```
//  MARK: branch init
func branchInit(launchOptions: [UIApplication.LaunchOptionsKey: Any]?) {
    Branch.getInstance().initSession(launchOptions: launchOptions) { (data, error) in
        if let data = data {
            Appflow.shared.updateAttribution(data, source: .branch,networkUserId: Appflow.shared.getAppUserId())
            //When Branch reports data, setIdentity must be set for data association.
            Branch.getInstance().setIdentity(Appflow.shared.getAppUserId())
        }
    }

}
```
### FacebookAds
To upload FacebookAds attribution data, refer to the following example, which **networkUserId **cannot be empty

```
Appflow.shared.updateAttribution([:], source: .facebook,networkUserId:FBSDKCoreKit.AppEvents.shared.anonymousID)
```


### Apple Search ads
To upload Apple Search ads attribution data, refer to the following example,

For the AdServices Framework

```
if let attributionToken = try? AAAttribution.attributionToken() {
    let attributionDetails = ["attributionToken": attributionToken]
    Appflow.shared.updateAttribution(attributionDetails, source: .appleSearchAds)
}
```

For the iAd Framework

```
ADClient.shared().requestAttributionDetails({ (attributionDetails, error) in
    guard let attributionDetails = attributionDetails else {
        return
    }
    Appflow.shared.updateAttribution(attributionDetails, source: .appleSearchAds)
})
```

### Custom
attribution_source = *custom* ，Update attribution data, There are 2 ways.

Way 1:   The developer must pass it in according to the format set by this parameter, otherwise an error will be reported

```
/// The developer must pass it in according to the format set by this parameter, otherwise an error will be reported
/// - Parameter Description
/// - channel: Corresponding to `channel` on the Appflow dashboard
/// - campaign: Corresponding to `campaign` on the Appflow dashboard
/// - ad_group: Corresponding to `ad group` on the Appflow dashboard
/// - creative: Corresponding to `creative` on the Appflow dashboard
/// - click_id: Currently just saving data
/// - attributed: The app needs to pass this value explicitly. If it is false, it will be processed according to the natural amount. If it is true, the attribution information will be written according to the value of other fields,
/// If using custom for attribution processing, attributed = True will be used by default
let attribution: [String: Any] = [
    "channel": "channel name",
    "campaign": "campaign",
    "ad_group": "ad_group",
    "creative": "creative",
    "click_id": "click_id",
    "attributed": true
]
Appflow.shared.updateAttribution(attribution, source: .custom) { getAttributionResponse, error in
    if error == nil {
        print("Attribution data reported successfully")
    } else {
        print("Attribution data reported Failed")
    }
}
```

Way2: If the developer does not want to deal with the data conversion problem by himself, he can use the following method to quickly set parameters, which will be automatically processed internally

    Appflow.shared.updateCustomAttribution(channel: "channel name", campaign: "campaign name", adGroup: "adGroup name", creative: "creative name", clickID: "clickID") { getAttributionResponse, error in
        if error == nil {
            print("Attribution data reported successfully")
        } else {
            print("Attribution data reported Failed")
        }
    }

## 8. WelcomPage

The SDK adds the View of AppflowWelcomePage. If the user needs to start the welcome page, the configuration of the page needs to be configured on the Appflow platform. The welcomePage loading method can be referred to as follows:

```
// loading WelcomPage
func loadLaunchScreenView() {
    // customized launch screen
    if let window = self.window {
        window.backgroundColor = .white
        let welcomPageView = AppflowWelcomePage(frame: window.bounds)
        welcomPageView.waitingTime = 6
        self.window?.makeKeyAndVisible()
        self.window?.addSubview(welcomPageView)
        self.window?.bringSubviewToFront(welcomPageView)
    }
}

```
> It may take time to load welcome page for the first time. The default loading waiting time is 30s. Users can set **waitingTime** according to their needs.



## 9. In App Message

> In App message has a, b two ways to load, divided into automatic and manual,

### a.  Automatically set the pop-up In App Message

> If the user accesses the push function and wants to automatically manage and display the In App Message when it is received, you can call the following method to enable this function. The In App Message function is disabled by default. **Example:** 

```
 //In App Message
 //true: automatically displayed;
 //false: not automatically displayed
 Appflow.shared.setInAppMesssageAutoShow(isAuto: true)
```

If you set 'setInAppMesssageAutoShow = True', developers can set the delay time of In App Mesesage as needed, the default delay time is 1.5s

> Explanation： When the App is in the background, click on the content of the push message to enter the App. The In App Message cannot be displayed immediately. It needs to wait for the App to start up before displaying the content. In this setting process, there needs to be a delay time for loading buffers. The default loading buffer delay time is 1.5s, which can be set according to the effect of your own project. **Example:** 
>

```
 //Set the delay time for message display
 Appflow.shared.setFromBackgroudPointToDelayTime(delayTime: 2)
```

> **Note**: Method ‘a’ ：is not applicable to projects that have access to message push or need to process message content. If the message push function has been connected, you can use method 'b' to access 'In App message'

### b.  Manually set the pop-up In App Message

If the project itself is connected to the message push function, if you want to use the In App Message function, you can call the sendUserNotificationCenterMessage(userInfo:[AnyHashable:Any]) method after receiving the message, package the message and send it to the SDK, and the SDK will automatically parse the message content to judge Whether it is 'In App Message', if it is, it will be displayed automatically and return true, if it is not 'In App Message', it will not be displayed and return false. **example:**

```
//UserInfo: Apps can set the userInfo for locally scheduled notification requests. The contents of the push payload will be set as the userInfo for remote notifications.
//The custom data to associate with the notification.
//userInfo ：notification.request.content.userInfo
Appflow.shared.sendUserNotificationCenterMessage(userInfo: userInfo)
```

