//
//  PurchaseViewController.swift
//  appflow
//
//  Created by Volodymyr Nazarkevych on 05.01.2022.
//

import Foundation
import UIKit
import AppflowSDK


class PurchaseViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    @IBOutlet var tableView: UITableView!
    var groups: [String : IMGroup]?
    @IBOutlet var statusLabel: UILabel!
    var activityIndicator: UIActivityIndicatorView?
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.delegate = self
        tableView.dataSource = self
        //TODO: Appflow.shared instead IMPurchase
        Appflow.shared.purchases.invalidateCache()
        Appflow.shared.getProductGroup ({ [self] groups, error in
            self.groups = groups
            tableView.reloadData()
        })
        
    }
    
   
   
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        checkStatus()
        if #available(iOS 13.0, *) {
            activityIndicator = UIActivityIndicatorView(style: .large)
        } else {
            // Fallback on earlier versions
        }
        activityIndicator?.alpha = 1.0
        activityIndicator?.center = view.center
        if let activityIndicator = activityIndicator {
            view.addSubview(activityIndicator)
            activityIndicator.startAnimating()
            activityIndicator.isHidden = true
        }
    }
    
    @IBAction func buttonAction(_ sender: Any) {
        let sandbox = Appflow.shared.purchases.isSandbox()
        print("\(sandbox != nil ? "YES" : "NO")")
        checkStatus()
    }
    
    @IBAction func invalidateCacheAction(_ sender: Any) {
       //TODO: Appflow.shared instead IMPurchase
        Appflow.shared.purchases.invalidateCache()
    }
    
    @IBAction func restoreAction(_ sender: Any) {
        Appflow.shared.restorePurchases ({ ent, error in
            print("restored")
        })
    }
    
    func checkStatus() {
        Appflow.shared.hasActiveSubscription({ [self] entitlements, error in
            var status = ""
            if ((entitlements["pro"]?.isActive()) != nil) {
                status = "pro active"
                statusLabel.textColor = UIColor.green
            } else {
                status = "pro not active"
                statusLabel.textColor = UIColor.red
            }
            statusLabel.text = "Subcription status: \(status)"
        })
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if let keys = groups?.keys {
            let allKeys = Array(keys)
            let curKey = allKeys[section]
            let curArray = groups?[curKey]
            return curArray?.products.count ?? 0
        }
        return 0
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return groups?.count ?? 0
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell = UITableViewCell()
        if let tableViewCell = tableView.dequeueReusableCell(withIdentifier: "cell") {
            cell = tableViewCell
        } else {
            cell = UITableViewCell(style: .default, reuseIdentifier: "cell")
        }
        
        guard let keys = groups?.keys  else { return cell }
        let allKeys = Array(keys)
        let curKey = allKeys[indexPath.section]
        let curArray = groups?[curKey]
        let imProduct = curArray?.products[indexPath.row]
        let product = imProduct?.product
        print(product?.productIdentifier)
        
        let indef = product?.productIdentifier
        let numberFormatter = NumberFormatter()
        numberFormatter.formatterBehavior = .behavior10_4
        numberFormatter.numberStyle = .currency
        numberFormatter.locale = product?.priceLocale
        guard let price = product?.price else { return cell }
        let priceString = numberFormatter.string(from: price)
        
        var isTrial = "NO"
        if #available(iOS 11.2, *) {
            if product?.introductoryPrice?.numberOfPeriods != nil {
                isTrial = "Yes"
            }
        } else {
            // Fallback on earlier versions
        }
        guard let indef = indef, let priceString = priceString  else { return cell }
        cell.textLabel?.text = "\(indef) | \(priceString) | trial: \(isTrial)"
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        guard let keys = groups?.keys else { return }
        
        let allKeys = Array(keys)
        let curKey = allKeys[indexPath.section]
        let curArray = groups?[curKey]
        
        guard let product = curArray?.products[indexPath.row] else { return }
        activityIndicator?.isHidden = false
        Appflow.shared.purchaseProduct(product) { [self] transaction, ent, error, canceled in
            if canceled || error != nil {
                print("Canceled")
            }  else {
                print("Purchase completed")
                checkStatus()
                updateUserInfo()
            }
            activityIndicator?.isHidden = true
            tableView.cellForRow(at: indexPath)?.isSelected = false
        }
    }
    func updateUserInfo() {
        Appflow.shared.purchases.uploadUserInfo { _, _ in
            
        }
    }
    
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        guard let keys = groups?.keys else { return nil }
        let allKeys = Array(keys)
        return allKeys[section]
    }
}
