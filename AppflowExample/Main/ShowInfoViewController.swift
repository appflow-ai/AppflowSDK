//
//  ShowInfoViewController.swift
//  ImplusAnalyticsSDK
//
//  Created by Volodymyr Nazarkevych on 25.12.2021.
//  Copyright © 2021 lin. All rights reserved.
//

import Foundation
import UIKit
import AppflowSDK

class ShowInfoViewController: UIViewController {
    @IBOutlet weak var textView: UITextView!
    @IBOutlet weak var threadNubers: UILabel!
    @IBOutlet weak var usedthread: UILabel!
    @IBOutlet weak var timeup: UILabel!
    @IBOutlet weak var dataNumbers: UILabel!
    @IBOutlet weak var dataUp: UITextField!
    var dict: [AnyHashable : Any]?
    var eventName: String?
    // Timer, query the request in the Fmdb database every 60s
    var timer: Timer?
    private let kTimerDuration = 60
    private let maxCurrentNum = 3

    var dataview: DataParams?

    deinit {
        timer?.invalidate()
    }
    
    @IBAction func showDataparamsView(_ sender: Any) {
        dataview = Bundle.main.loadNibNamed("DataParams", owner: nil, options: nil)?.first as? DataParams
        dataview?.frame = UIScreen.main.bounds
        dataview?.endedit = { [weak self] dict in
            if dict?.values.count ?? 0 > 0 {
                self?.dict = dict
            } else {
                self?.dict = ["test": "test"]
            }
        }
        dataview?.show()
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        updataUI(withString: "")
        //TODO: Appflow.shared instead IMAnalytics
        let analytics = Appflow.shared.analytics
        dict = ["test": "test"]
        let tMSimestamp = "\(IMDeviceInfoManager.shared.getCurrentMSimestamp())"
        let model = ParamModel()
        model.screenType = .paramScreenHome
        model.otherData = [kEngagementTimeMsec: tMSimestamp ]
        analytics.uploadBigDataWithType(eventType: .userEngagement, paramModel: model)
        //obj type is string
        analytics.uploadBigDataWithType(eventType: .userEngagement, params: [
            kEngagementTimeMsec: tMSimestamp,
            kScreenViewName: kHomepage
        ], successBlock: { obj in

        }) { obj in

        }
        analytics.uploadBigDataWithType(eventType: .adsRequest, paramModel: model, successBlock: { [weak self] obj in
            guard let self = self else { return }
            self.updataUI(withString: obj as? String)
        }) { [weak self] obj in
            guard let self = self else { return }
            self.updataUI(withString: obj as? String)
        }
        startTimer()
    }
    @IBAction func upLoad(_ sender: Any) {
        let analytics = Appflow.shared.analytics
        analytics.uploadBigDataWithEvent(eventName: eventName, params: dict, successBlock: { [weak self] obj in
            guard let self = self else { return }
            self.updataUI(withString: obj as? String)
        }) { [weak self] obj in
            self?.updataUI(withString: obj as? String)
        }
    }

    @IBAction func whileUp(_ sender: UIButton) {
        var i = 10
        while i > 0 {
            let analytics = Appflow.shared.analytics
            analytics.uploadBigDataWithEvent(eventName: eventName, params: dict, successBlock: { [weak self] obj in

                self?.updataUI(withString: obj as? String)
            }) { [weak self] obj in
                self?.updataUI(withString: obj as? String)
            }
            //        [IMAnalytics uploadBigDataWithEvent:self.eventName params:self.dataUp.text.length>0 ? @{@"test":self.dataUp.text}:@{@"test":@"test"}];
            i -= 1
        }
    }
    func updataUI(withString: String?) {
        timeup.text = "\(kTimerDuration)"
        threadNubers.text = "\(maxCurrentNum)"
        IMRequestCache.shared.allRequests(fromFmdbWihtClass: IMRequest.self) { [weak self] requestArr in
            self?.dataNumbers.text = String(format: "%ld", requestArr?.count ?? 0)
        }
        textView.text = textView.text + (withString ?? "")
        //    [self.textView scrollsTo]
    }
    //MARK: - Timer
    func startTimer() {
        DispatchQueue.main.async(execute: { [self] in
            //      dispatch_async(self.addDelQueue, ^{
            timer?.invalidate()
            timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(updateTimer), userInfo: nil, repeats: true)
        })
    }
    @objc func updateTimer() {
        IMRequestCache.shared.allRequests(fromFmdbWihtClass: IMRequest.self) { [weak self] requestArr in
            self?.dataNumbers.text = String(format: "%ld", requestArr?.count ?? 0)
        }
    }
}
