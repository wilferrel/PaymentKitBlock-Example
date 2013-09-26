//
//  PKPaymentField.h
//  PKPayment Example
//
//  Created by Alex MacCaw on 1/22/13.
//  Copyright (c) 2013 Stripe. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PKCard.h"
#import "PKCardNumber.h"
#import "PKCardExpiry.h"
#import "PKCardCVC.h"
#import "PKAddressZip.h"
#import "PKUSAddressZip.h"

@class PKView, PKTextField;
//Block
typedef void(^CompletionBlock)(BOOL validCard,PKCard *card,PKView *paymentView);


@protocol PKViewDelegate <NSObject>
@optional
- (void) paymentView:(PKView*)paymentView withCard:(PKCard*)card isValid:(BOOL)valid;
@end

@interface PKView : UIView <UITextFieldDelegate> {
    CompletionBlock _completionBlock;
    
@private
    BOOL isInitialState;
    BOOL isValidState;
    BOOL isUSAddress;
}

- (BOOL)isValid;

@property (readonly) PKCardNumber* cardNumber;
@property (readonly) PKCardExpiry* cardExpiry;
@property (readonly) PKCardCVC* cardCVC;
@property (readonly) PKAddressZip* addressZip;

@property IBOutlet UIView* innerView;
@property IBOutlet UIView* clipView;
@property IBOutlet PKTextField* cardNumberField;
@property IBOutlet PKTextField* cardExpiryField;
@property IBOutlet PKTextField* cardCVCField;
@property IBOutlet PKTextField* addressZipField;
@property IBOutlet UIImageView* placeholderView;
@property id <PKViewDelegate> delegate;
@property (readonly) PKCard* card;
@property (setter = setUSAddress:) BOOL usAddress;

//BLOCK
@property (nonatomic, copy)CompletionBlock completionBlock;
+ (PKView *)cardPromptinView:(UIView *)view withFrame:(CGRect)frame;
-(void)getCompletionBlock:(CompletionBlock)completionHandler;
-(void)setPrefilledCardNumber:(NSString*)scannedCardNumber;



@end
