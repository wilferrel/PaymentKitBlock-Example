//
//  AGAViewController.m
//  Card
//
//  Created by Wil Ferrel on 9/13/13.
//  Copyright (c) 2013 AvantGardeApps. All rights reserved.
//

#import "AGAViewController.h"


@interface AGAViewController ()

@end

@implementation AGAViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
//    _paymentView = [[PKView alloc] initWithFrame:CGRectMake(0, 25, 290, 45)];
    PKView* _cardView= [PKView cardPromptinView:self.view withFrame:CGRectMake(0, 25, 290, 45) ];
//  _paymentView = [PKView cardPromptinView:_paymentView withFrame:CGRectMake(0, 25, 290, 45)];

    [_cardView setCompletionBlock:^(BOOL validCard, PKCard *card, PKView *cardView) {
        if (validCard) {
            NSLog(@"Valid Card");
            NSLog(@"Card properties zip :%@",card.addressZip);
            NSLog(@"Card properties number :%@",card.number);
        }
        else
        {
            NSLog(@"Invalid Card");
        }
    }];
    [self.view addSubview:_cardView];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
