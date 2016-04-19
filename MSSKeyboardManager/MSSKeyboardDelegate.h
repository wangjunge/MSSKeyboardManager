//
//  MSSKeyboardDelegate.h
//
//  Created by Merrick Sapsford on 07/04/2016.
//  Copyright © 2016 Merrick Sapsford. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MSSKeyboardDelegate;

NS_ASSUME_NONNULL_BEGIN
@interface MSSKeyboardUpdate : NSObject

/**
 The frame of the keyboard at the beginning of the update.
 */
@property (nonatomic, assign, readonly) CGRect beginFrame;
/**
 The frame of the keyboard at the end of the update.
 */
@property (nonatomic, assign, readonly) CGRect endFrame;

/**
 The duration of the update animation.
 */
@property (nonatomic, assign, readonly) CGFloat animationDuration;
/**
 The update animation curve.
 */
@property (nonatomic, assign, readonly) UIViewAnimationCurve animationCurve;

/**
 Whether the update was summoned by the local app in split view.
 */
@property (nonatomic, assign, readonly) BOOL isLocal;

+ (instancetype)updateWithDictionary:(NSDictionary *)updateDictionary;

@end

@protocol MSSKeyboardDelegate <NSObject>
@optional

/**
 The keyboard will show.
 
 @param delegate
 The keyboard delegate.
 
 @param update
 The keyboard update
 */
- (void)keyboardDelegate:(MSSKeyboardDelegate *)delegate willShowKeyboardWithUpdate:(MSSKeyboardUpdate *)update;
/**
 The keyboard did show.
 
 @param delegate
 The keyboard delegate.
 
 @param update
 The keyboard update
 */
- (void)keyboardDelegate:(MSSKeyboardDelegate *)delegate didShowKeyboardWithUpdate:(MSSKeyboardUpdate *)update;
/**
 The keyboard will hide.
 
 @param delegate
 The keyboard delegate.
 
 @param update
 The keyboard update
 */
- (void)keyboardDelegate:(MSSKeyboardDelegate *)delegate willHideKeyboardWithUpdate:(MSSKeyboardUpdate *)update;
/**
 The keyboard did hide.
 
 @param delegate
 The keyboard delegate.
 
 @param update
 The keyboard update
 */
- (void)keyboardDelegate:(MSSKeyboardDelegate *)delegate didHideKeyboardWithUpdate:(MSSKeyboardUpdate *)update;

@end

@interface MSSKeyboardDelegate : NSObject

@property (nonatomic, weak, readonly) id<MSSKeyboardDelegate> responder;

+ (instancetype)keyboardDelegateForResponder:(id<MSSKeyboardDelegate>)responder;

@end
NS_ASSUME_NONNULL_END
