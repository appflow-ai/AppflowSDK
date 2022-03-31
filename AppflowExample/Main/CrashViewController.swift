//
//  CrashViewController.swift
//  ImplusAnalyticsSDK
//
//  Created by Volodymyr Nazarkevych on 25.12.2021.
//  Copyright © 2021 lin. All rights reserved.
//

import Foundation
import UIKit
import AppflowSDK

struct Test {
    var a: Int
    var b: Int
}

class CrashViewController: UIViewController {
    @IBOutlet private weak var textView: UITextView!

    override func viewDidLoad() {
        super.viewDidLoad()
        IMRequestManager.shared.uploadCacheData { [self] obj in
            textView.text = textView.text + (obj as? String ?? "")
        } failureBlock: { [self] obj in
            textView.text = textView.text + (obj as? String ?? "")
        }
        
    
        // Do any additional setup after loading the view from its nib.
    }
    
    @IBAction func signaClick(_ sender: Any) {
        SignalTest().signalTest()
    }

    @IBAction func exceptionClick(_ sender: Any) {
        let array = ["tom", "xxx", "ooo"]
        array[5]
    }
}
