//
//  DataParams.swift
//  ImplusAnalyticsSDK
//
//  Created by Volodymyr Nazarkevych on 24.12.2021.
//  Copyright © 2021 lin. All rights reserved.
//

import Foundation
import UIKit
import AppflowSDK

class DataParams: UIView {
    var dataSource: [AnyHashable] = [kScreenViewName,kPlacement,kAdSource,kFormat,kEngagementTimeMsec]
    var dict: [AnyHashable : Any]?
    
    @IBOutlet weak var tableView: UITableView!
    var endedit: ((_ dict: [AnyHashable : Any]?) -> Void)?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        dict = [AnyHashable : Any]()
        backgroundColor = UIColor.black.withAlphaComponent(0.4)
        let tap = UITapGestureRecognizer(target: self, action: #selector(hide))
        tableView.register(DataParamsCellTableViewCell.self, forCellReuseIdentifier: "dcell")
        tableView.register(UINib(nibName: "DataParamsCellTableViewCell", bundle: Bundle.main), forCellReuseIdentifier: "dcell")

        tableView.delegate = self
        tableView.dataSource = self
        addGestureRecognizer(tap)
        tableView.rowHeight = 44
    }
    
    @objc func hide() {
        UIView.animate(withDuration: 0.2, animations: {
            CGAffineTransform(translationX: 0, y: UIScreen.main.bounds.size.height)
        }) { [self] finished in
            removeFromSuperview()
        }
    }
    
    func show() {
        UIApplication.shared.keyWindow?.addSubview(self)
    }
    
    @IBAction func okclick(_ sender: Any) {
        endEditing(true)
        if let endedit = endedit {
            endedit(dict)
        }
        hide()
    }
}
// MARK: - UITableViewDelegate,UITableViewDataSource
extension DataParams: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if let cell = tableView.dequeueReusableCell(withIdentifier: "dcell") as? DataParamsCellTableViewCell {
            cell.cellTextLabel.text = dataSource[indexPath.row] as? String
            cell.endedit = { [weak self] name, value in
                if let count = value?.count,
                   count > 0 {
                    self?.dict?[name] = value
                } else {
                    self?.dict?.removeValue(forKey: name)
                }
            }
            return cell
        }
        return UITableViewCell()
    }
}
