//
//  DataParamsCellTableViewCell.swift
//  ImplusAnalyticsSDK
//
//  Created by Volodymyr Nazarkevych on 20.12.2021.
//  Copyright © 2021 lin. All rights reserved.
//

import Foundation
import UIKit
import AppflowSDK

class DataParamsCellTableViewCell: UITableViewCell, UITextFieldDelegate {
    var endedit: ((_ name: String?, _ value: String?) -> Void)?
    
    @IBOutlet weak var cellTextLabel: UILabel!
    @IBOutlet weak var textView: UITextField!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        textView.delegate = self
        // Initialization code
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
        
        // Configure the view for the selected state
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        if var searchKey = textField.text {
            if let subRange = Range<String.Index>(range, in: searchKey) { searchKey.replaceSubrange(subRange, with: string) }
            if (searchKey.count) > 0 {
                if let endedit = endedit {
                    endedit(cellTextLabel.text, searchKey)
                }
            }
        }
        return true
    }
}
