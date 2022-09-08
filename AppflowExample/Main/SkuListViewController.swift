//
//  SkuListViewController.swift
//  appflow
//
//  Created by implus on 2022/4/6.
//

import UIKit
import AppflowSDK
import StoreKit

class SkuListViewController: UIViewController {
    @IBOutlet weak var statusLabel: UILabel!
    @IBOutlet weak var activityView: UIActivityIndicatorView!
    @IBOutlet weak var tbView: UITableView!
    var productIDs:[String] = [];
    var skuDetailInfo:[String:SKProduct]?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        getProductIds()
        setUpUI()
        checkStatus()
        
        
    }
    func getProductIds() {
        Appflow.shared.getPurchaseProductIds {[weak self] productIdArray, error in
            guard let `self` = self else { return }
            if error == nil {
                if let array = productIdArray {
                    self.productIDs = array
                    self.loadSkuDetail()
                }
            }
        }
    }
    func setUpUI() {
        tbView.register(UITableViewCell.self, forCellReuseIdentifier: "SkuListViewControllerCellID")
    }
    
    func loadSkuDetail() {
        self.showActivity()
        Appflow.shared.getSkuDetails(productIds: Set(productIDs)) {[weak self] skuDetailInfo, error in
            guard let `self` = self else { return }
            self.hiddenActivity()
            self.skuDetailInfo = skuDetailInfo
            self.tbView.reloadData()
        };
    }
    func showActivity() {
        self.activityView.startAnimating()
        self.activityView.isHidden = false;
    }
    
    func hiddenActivity() {
        self.activityView.stopAnimating()
        self.activityView.isHidden = true;
    }

    @IBAction func restoreAction(_ sender: Any) {
        self.showActivity()
        Appflow.shared.restorePurchases {[weak self] subscriber, error in
            guard let `self` = self else { return  }
            self.hiddenActivity()
            if error == nil {
                self.getIMSubscriberToDeal(subscriber)
            }
        }
    }
    
}

extension SkuListViewController: UITableViewDataSource,UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.productIDs.count
    }

    
    @available(iOS 2.0, *)
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        let cell = tableView.dequeueReusableCell(withIdentifier: "SkuListViewControllerCellID", for: indexPath)
        cell.textLabel?.numberOfLines = 0;
        let product_id = self.productIDs[indexPath.row]
        if let skProduct = self.skuDetailInfo?[product_id] {
            cell.textLabel?.text = skProduct.productIdentifier + " | " + self .getPriceLocale(product: skProduct) + skProduct.localizedDescription
        }
        return cell
    }
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 60
    }
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let product_id = self.productIDs[indexPath.row]
        if let skProduct = self.skuDetailInfo?[product_id] {
            if Appflow.shared.canMakePayment() {
                self.showActivity()
                Appflow.shared.purchaseSKProduct(skProduct) {[weak self] transaction, subscriber, error, canceled in
                    guard let `self` = self else { return }
                    self.hiddenActivity()
                    if canceled || error != nil {
                        print("Canceled")
                    }  else {
                        print("Purchase completed")
                        self.checkStatus()
                        self.updateUserInfo()
                    }
                    
                }
            }
            
        }

    }
    func checkStatus() {
        Appflow.shared.hasActiveSubscription({ [weak self] subscriber, error in
            guard let `self` = self else { return }
            if error == nil {
                self.getIMSubscriberToDeal(subscriber)
            }
        })
    }
    func getIMSubscriberToDeal(_ subscriber :IMSubscriber) {
        var status = "pro not active"
        if subscriber.isActive {
            status = "pro active"
        }
        self.statusLabel.text = "Subcription status: \(status)"
    }
    
    func updateUserInfo() {
        Appflow.shared.uploadUserInfo()
    }
    
    func getPriceLocale(product:SKProduct) -> String {
        let numberFormatter =  NumberFormatter()
         numberFormatter.formatterBehavior = .behavior10_4
         numberFormatter.numberStyle = .currency
         numberFormatter.locale = product.priceLocale
        guard let textPrirce = numberFormatter.string(from: product.price) else { return product.price.stringValue }
        return textPrirce
    }
}

