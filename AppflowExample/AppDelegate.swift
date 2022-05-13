//
//  AppDelegate.swift
//  appflow
//
//  Created by Volodymyr Nazarkevych on 29.12.2021.
//

import UIKit
import AppflowSDK
import UserNotifications
import AppsFlyerLib
import Adjust
import Branch
@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        //AppflowSDK initialization
        Appflow.shared.configure()
        //Whether to enable in-app purchase related logs, the default is not
        Appflow.shared.setPurchasesLogs(enabled: true)
        //Whether to enable the log related to the buried point, the default is not
        Appflow.shared.setAnalyticsLogs(enabled: true)
        //Notification related initialization
        requestPushNotificationsPermissions()
        //load welocome page
        loadLaunchScreenView()
        return true
    }
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

//    MARK: appsflyerInit
    func appsflyerInit() {
        AppsFlyerLib.shared().appsFlyerDevKey = ""
        AppsFlyerLib.shared().appleAppID = ""
        AppsFlyerLib.shared().delegate = self
        /* Set isDebug to true to see AppsFlyer debug logs */
        AppsFlyerLib.shared().isDebug = true
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(sendLaunch),
                                               // For Swift version < 4.2 replace name argument with the commented out code
                                               name: UIApplication.didBecomeActiveNotification, //.UIApplicationDidBecomeActive for Swift < 4.2
                object: nil)
        
    }
    @objc func sendLaunch(app:Any) {
        AppsFlyerLib.shared().start()
    }
    
    //    MARK: adjust init
    func adjustInit() {
        let yourAppToken = "{YourAppToken}"
        let environment = ADJEnvironmentSandbox
        let adjustConfig = ADJConfig(
            appToken: yourAppToken,
            environment: environment)
        adjustConfig?.delegate = self
        Adjust.appDidLaunch(adjustConfig)

    }
    //    MARK: branch init
    func branchInit(launchOptions: [UIApplication.LaunchOptionsKey: Any]?) {
        Branch.getInstance().setIdentity("YOUR_USER_ID")
        Branch.getInstance().initSession(launchOptions: launchOptions) { (data, error) in
            if let data = data {
                Appflow.shared.updateAttribution(data, source: .branch)
            }
        }

    }
    //    MARK: facebook
    func facebookInit(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) {
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        let deviceToken = deviceToken.reduce("", { $0 + String(format: "%02X", $1) })
        Appflow.shared.uploadDeviceInfo(deviceToken: deviceToken) { _, _ in
        }
    }

    func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: Error) {
        print("Failed to register: \(error)")
    }
    
    private func requestPushNotificationsPermissions() {
        let userNotificationCenter = UNUserNotificationCenter.current()
        userNotificationCenter.requestAuthorization(options: [.alert, .sound, .badge]) { [weak self] granted, error in
            print("Permission granted: \(granted)")
            if granted {
                self?.getNotificationSettings()
            }
        }
    }

    private func getNotificationSettings() {
        UNUserNotificationCenter.current().getNotificationSettings { settings in
            print("Notification settings: \(settings)")
            guard settings.authorizationStatus == .authorized else { return }
            DispatchQueue.main.async {
                UIApplication.shared.registerForRemoteNotifications()
            }
        }
    }
}

extension AppDelegate: AppsFlyerLibDelegate {
    func onConversionDataFail(_ error: Error) {
        //appsflyer is fail
    }
    
    func onConversionDataSuccess(_ installData: [AnyHashable : Any]) {
        // It's important to include the network user ID
        Appflow.shared.updateAttribution(installData, source: .appsflyer, networkUserId: AppsFlyerLib.shared().getAppsFlyerUID())
        
    }
}

extension AppDelegate: AdjustDelegate {
    //Callback for the first app installation
    func adjustAttributionChanged(_ attribution: ADJAttribution?) {
        // Just pass Adjust attribution to Adapty SDK
        if let attribution = attribution?.dictionary() {
            Appflow.shared.updateAttribution(attribution, source: .adjust)
        }
    }
    
}

