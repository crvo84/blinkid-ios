//
//  PPCoordinator.h
//  PhotoPaySdk
//
//  Created by Jurica Cerovec on 11/19/11.
//  Copyright (c) 2011 Racuni.hr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "PPScanningViewController.h"

@protocol PPCoordinatorDelegate;
@protocol PPScanDelegate;
@class PPSettings;
@class PPCameraManager;
@class PPRecognitionResult;
@class PPOverlayViewController;
@class PPAccelerometerManager;

/**
 * This object is the mastermind of the recognition process.
 * It coordinates hardware control with the recognition algorithms.
 * Also, while it provides default implementation of UIViewController which is used,
 * it allows you to create your own UIViewController implementation and use
 * this object's methods for ensuring everything works
 */
@interface PPCoordinator : NSObject

/** Scanning settings pending to be used with [coordinator applySettings] method */
@property (nonatomic, strong) PPSettings *currentSettings;

/** delegate object for notifying the caller on recognition results */
@property (nonatomic, weak) id<PPScanDelegate> scanDelegate;

/** delegate object which will be control camera view related events */
@property (nonatomic, weak) id<PPCoordinatorDelegate> coordinatorDelegate;

/** Object which will take care of the camera */
@property (nonatomic, strong) PPCameraManager *cameraManager;

/** We need an acceleration manager object because we're interested in events regarding device movement */
@property (nonatomic, strong) PPAccelerometerManager *accelerometerManager;

/** Current orientation of overlay */
@property (nonatomic, assign) UIInterfaceOrientation overlayOrientation;

/**
 * Initializes the object in proper state
 * Sets the settigns for scanning, camera control, licensing and UI.
 *
 *  @param settings settings used for initialization
 *
 *  @return initialized coordinator object capable to perform scanning
 */
- (instancetype)initWithSettings:(PPSettings *)settings;

/**
 * Method creates a camera view controller which is responsible for displaying the 
 * camera input on the phone screen. Also, camera view controller delivers PhotoPay
 * results via PPPhotoPayDelegate object.
 *
 * Creating camera view controller with this method creates default overlay view
 */
- (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(id<PPScanDelegate>)delegate;

/**
 * Method creates a camera view controller which is responsible for displaying the
 * camera input on the phone screen. Also, camera view controller delivers PhotoPay
 * results via PPPhotoPayDelegate object
 *
 * With this method you can specify custom overlay view to be used on the camera display.
 * The only requirement for the overlay view is that it's a subclass of PPOverlayViewController
 */
- (UIViewController<PPScanningViewController> *)cameraViewControllerWithDelegate:(id<PPScanDelegate>)delegate
                                                          overlayViewController:(PPOverlayViewController *)overlayViewController;

/**
 * Method which is used to apply new settings in the scanning process.
 *
 * All settings in PPSettings object can be updated in runtime.
 * Usual use case is to update ScanSettings in the fly, to perform some complex scanning functionality.
 */
- (void)applySettings;

/**
 * This method returns true when scanning is unsupported on a specific device.
 * Error object contains description of the reason for that.
 */
+ (BOOL)isScanningUnsupported:(NSError **)error;

/**
 * This method returns the string that contains the library build version
 * information.
 */
+ (NSString *)getBuildVersionString;

@end