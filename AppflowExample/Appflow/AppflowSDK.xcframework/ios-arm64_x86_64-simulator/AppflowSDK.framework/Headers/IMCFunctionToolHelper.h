//
//  IMCFunctionToolHelper.h
//  ImplusAnalytics
//
//  Created by Volodymyr Nazarkevych on 03.01.2022.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface IMCFunctionToolHelper : NSObject
/**
 * MD5 encryption
 */
//- (NSString *) stringMD5(NSString *string);
- (NSString *) stringMD5:(NSString *)string;

/**
 * NSDictionary to jsonString
 */
- (NSString *) DataTOjsonString:(NSDictionary *) dict;
//- NSString* DataTOjsonString(NSDictionary *dict);

@end
