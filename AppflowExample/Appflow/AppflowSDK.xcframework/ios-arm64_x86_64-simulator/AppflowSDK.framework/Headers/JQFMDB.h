//
//  JQFMDB.h
//
//  Created by Joker on 17/3/7.
//  GitHub: https://github.com/gaojunquan/JQFMDB
//

#import <Foundation/Foundation.h>

@interface JQFMDB : NSObject


/**
 (primary key id, automatically created) Returns the last inserted primary key id
   @param tableName name of the table
 */
- (NSInteger)lastInsertPrimaryKeyId:(NSString *)tableName;

/**
 The singleton method creates a database. If you use shareDatabase to create it, JQFMDB.sqlite is created under NSDocumentDirectory by default, but as long as any one of these three methods is used to create a database successfully, you can use any of the three methods to obtain the same instance. The parameters can be optional or nil

          dbName database name such as: @"Users.sqlite", if dbName = nil, the default dbName=@"JQFMDB.sqlite"
          dbPath The path of the database, if dbPath = nil, the path defaults to NSDocumentDirectory
 */
+ (instancetype)shareDatabase;
+ (instancetype)shareDatabase:(NSString *)dbName;
+ (instancetype)shareDatabase:(NSString *)dbName path:(NSString *)dbPath;

/**
 Non-singleton method to create database

   @param dbName The name of the database such as: @"Users.sqlite"
          dbPath The path of the database, if dbPath = nil, the path defaults to NSDocumentDirectory
 */
- (instancetype)initWithDBName:(NSString *)dbName;
- (instancetype)initWithDBName:(NSString *)dbName path:(NSString *)dbPath;

/**
 Create a table Through the incoming model or dictionary (if it is a dictionary, note that the type should be written correctly), although it is possible, it is recommended to use the following model

   @param tableName name of the table
   @param parameters Set the fields of the table, you can pass model (runtime automatically generates fields) or dictionary (format: @{@"name":@"TEXT"})
   Whether @return was created successfully
 */
- (BOOL)jq_createTable:(NSString *)tableName dicOrModel:(id)parameters;

/**
 Ditto,
   @param nameArr does not allow attributes/keys in model or dic to generate table fields, such as: nameArr = @[@"name"], then attributes/keys named name are not allowed to generate table fields

 */
- (BOOL)jq_createTable:(NSString *)tableName dicOrModel:(id)parameters excludeName:(NSArray *)nameArr;

/**
 Added: Insert data into table

   @param tableName name of the table
   @param parameters The data to be inserted, which can be model or dictionary (format: @{@"name":@"Little Li"})
   @return whether the insertion was successful
 */
- (BOOL)jq_insertTable:(NSString *)tableName dicOrModel:(id)parameters;

/**
 Delete: delete data in the table according to conditions

   @param tableName name of the table
   @param format conditional statement, such as: @"where name = 'Xiao Li'"
   @return whether the deletion is successful
 */
- (BOOL)jq_deleteTable:(NSString *)tableName whereFormat:(NSString *)format requestId:(NSString *)requestId; 

/**
 Change: Change the data in the table according to the condition

   @param tableName name of the table
   @param parameters The data to be changed, which can be model or dictionary (format: @{@"name":@"Zhang San"})
   @param format conditional statement, such as: @"where name = 'Xiao Li'"
   @return whether the change was successful
 */
- (BOOL)jq_updateTable:(NSString *)tableName dicOrModel:(id)parameters whereFormat:(NSString *)format, ...;

/**
 Find: Find data in a table based on conditions

   @param tableName name of the table
   @param parameters Each search result is put into model (can be [Person class] or @"Person" or Person instance) or dictionary
   @param format conditional statement, such as:@"where name = 'Xiao Li'",
   @return stores the result in the array, the type of the elements in the array is the type of parameters
 */
- (NSArray *)jq_lookupTableWrapper:(NSString *)tableName dicOrModel:(id)parameters whereFormat:(NSString *)format;
- (NSArray *)jq_lookupTable:(NSString *)tableName dicOrModel:(id)parameters whereFormat:(NSString *)format, ...;

/**
 Bulk insert or change

   @param dicOrModelArray Array of insert/update data, you can also mix model and dictionary into array
   The array returned by @return stores the subscripts that were not inserted successfully, and the element type in the array is NSNumber
 */
- (NSArray *)jq_insertTable:(NSString *)tableName dicOrModelArray:(NSArray *)dicOrModelArray;

// `delete table
- (BOOL)jq_deleteTable:(NSString *)tableName;
// `empty table
- (BOOL)jq_deleteAllDataFromTable:(NSString *)tableName;
// `Does the table exist
- (BOOL)jq_isExistTable:(NSString *)tableName;
// `How many pieces of data are in the table
- (int)jq_tableItemCount:(NSString *)tableName;
// `Returns the field names in the table
- (NSArray *)jq_columnNameArray:(NSString *)tableName;

// `close the database
- (void)close;
// `Open the database (it has been opened each time the shareDatabase series of operations are performed, and if the db operation is performed after calling close, it needs to be re-opened or call shareDatabase)
- (void)open;

/**
 Add a new field. If you want to add a new field after the table is created, you can add the corresponding attribute in the original table model or the new model, and then pass in to add the field. This operation has been performed in the transaction.

   @param tableName name of the table
   @param parameters If you pass Model: the newly added fields in the database are attributes that the model does not have when creating the table, if you pass the dictionary format as @{@"newname":@"TEXT"}
   @param nameArr is not allowed to generate an array of property names for the field
   Whether @return was successful
 */
- (BOOL)jq_alterTable:(NSString *)tableName dicOrModel:(id)parameters excludeName:(NSArray *)nameArr;
- (BOOL)jq_alterTable:(NSString *)tableName dicOrModel:(id)parameters;


// =============================   thread safe operation    ===============================

/**
 Thread safety can be guaranteed by placing operation statements in blocks, such as:

   Person *p = [[Person alloc] init];
   p.name = @"Little Li";
   [jqdb jq_inDatabase:^{
   [jqdb jq_insertTable:@"users" dicOrModel:p];
   }];
 */
- (void)jq_inDatabase:(void (^)(void))block;


/**
 Transaction: Put the operation statement into the block to perform the rollback operation (*rollback = YES;)

   Person *p = [[Person alloc] init];
   p.name = @"Little Li";

   for (int i=0,i < 1000,i++) {
   [jq jq_inTransaction:^(BOOL *rollback) {
   BOOL flag = [jq jq_insertTable:@"users" dicOrModel:p];
   if (!flag) {
   *rollback = YES; //As long as one unsuccessful, rollback operation is performed
   return;
   }
   }];
   }

 */
- (void)jq_inTransaction:(void(^)(BOOL *rollback))block;


@end

