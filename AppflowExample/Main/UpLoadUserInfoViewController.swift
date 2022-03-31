//
//  UpLoadUserInfoViewController.swift
//  appflow
//
//  Created by implus on 2022/3/30.
//

import UIKit
import AppflowSDK
class UpLoadUserInfoViewController: UIViewController {

    @IBOutlet weak var usernameTF: UITextField!
    @IBOutlet weak var emailTF: UITextField!
    @IBOutlet weak var phoneTF: UITextField!
    @IBOutlet weak var ageTF: UITextField!
    @IBOutlet weak var extTF: UITextField!
    @IBOutlet var genderCol: [UIButton]!
    var gender:Int = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }


    @IBAction func submitAction(_ sender: Any) {
        var age:Int?
        if let ageText = ageTF.text {
            age = Int(ageText) 
        }
        var extraAttribute:[String: Any] = [String: Any].init()
        if let username = usernameTF.text {
            extraAttribute["username"] = username
        }
        if let email = emailTF.text {
            extraAttribute["email"] = email
        }
        if let phone = phoneTF.text {
            extraAttribute["phone"] = phone
        }
        if let ext = extTF.text {
            extraAttribute["ext"] = ext
        }
        if let age = age {
            extraAttribute["age"] = age
        }
        if (gender != 0) {
            extraAttribute["gender"] = gender
        }
        //uploadUserInfo to extraAttribute
        Appflow.shared.purchases.uploadUserInfo(userId: "app_user_idxxxxx", extraAttribute: extraAttribute) {[weak self] _, _ in
            self?.navigationController?.popViewController(animated: true)
        }
    }
    
    @IBAction func genderActoion(_ sender: UIButton) {
        for but in genderCol {
            but.isSelected = false
            if sender == but {
                but.isSelected = true
                gender = sender.tag
            }
        }
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
