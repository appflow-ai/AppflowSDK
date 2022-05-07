//
//  ViewController.swift
//  appflow
//
//  Created by Volodymyr Nazarkevych on 29.12.2021.
//

import UIKit
import AppflowSDK

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource  {
    
    @IBOutlet weak var paywallBtn: UIButton!
    @IBOutlet private weak var tableView: UITableView!
    private let dataSource: [String] = [
        "ev_first_open",
        "ev_app_start",
        "ev_scree_view",
        "ev_ads_click",
        "ev_ads_show",
        "ev_ads_request",
        "ev_in_app_purchase",
        "ev_user_engagement",
        "ev_view_paywall",
        "falal_crash"
    ]
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Choose the type of event you want to upload"
        tableView.delegate = self
        tableView.dataSource = self
        Appflow.shared.hasActiveSubscription {[weak self] _, _ in
            self?.refreshUI()
        }
//        Appflow.shared.getSubscriberData {[weak self] _, _ in
//            self?.refreshUI()
//        }
        //    NSString *str =  [IMDeviceInfoManager sharedManager].appsflyer_device_id;//[[IMDeviceInfoManager sharedManager] getCurrenttime];
        // Do any additional setup after loading the view.
        //    [IMAnalytics uploadBigDataWithEvent:@"test" params:@{@"test":@"test"}];
    }
    func refreshUI () {
        paywallBtn.isHidden = Appflow.shared.purchases.getUserIsActive()
    }
    
    @IBAction func uploadUserInfoAction(_ sender: Any) {
        let uploadUserInfo = UpLoadUserInfoViewController()
        navigationController?.pushViewController(uploadUserInfo, animated: true)
    }
    @IBAction func attributionSimulation(_ sender: Any) {
        let attrSimuVC = AttributionViewController()
        navigationController?.pushViewController(attrSimuVC, animated: true)
    }
    @IBAction func nextVCTapped(_ sender: UIButton) {
        navigationController?.pushViewController(SkuListViewController.init(), animated: true)
    }
    
    @IBAction func paywallAction(_ sender: Any) {
        Appflow.shared.loadPaywallToPurachase {[weak self] result, msg in
            guard let `self` = self else { return }
            if result == false {
                self.navigationController?.pushViewController(SkuListViewController.init(), animated: true)
            }
        }
    }
    // MARK: - UITableViewDelegate,UITableViewDataSource
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell = tableView.dequeueReusableCell(withIdentifier: "cell")
        if cell == nil {
            cell = UITableViewCell(style: .default, reuseIdentifier: "cell")
        }
        cell?.textLabel?.text = dataSource[indexPath.row]
        return cell!
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        if indexPath.row == dataSource.count - 1 {
            let vc = CrashViewController()
            navigationController?.pushViewController(vc, animated: true)
            return
        }

        let vc = ShowInfoViewController()
        vc.eventName = dataSource[indexPath.row]
        navigationController?.pushViewController(vc, animated: true)
    }
}


