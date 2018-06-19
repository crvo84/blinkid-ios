//
//  MBGermanyCombinedRecognizer.h
//  BarDecoder
//
//  Created by DoDo on 17/05/2018.
//

#import "MBLegacyRecognizer.h"
#import "MBGermanyCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFullDocumentImage.h"
#import "MBSignatureImage.h"
#import "MBFaceImage.h"

#import "MBDigitalSignature.h"

#import "MBEncodeFaceImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBEncodeSignatureImage.h"

/**
 * German ID Combined Recognizer.
 *
 * German ID Combined recognizer is used for scanning both front and back side of German ID.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBGermanyCombinedRecognizer : MBLegacyRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFullDocumentImage, MBSignatureImage, MBFaceImage, MBEncodeFaceImage, MBEncodeFullDocumentImage, MBEncodeSignatureImage, MBDigitalSignature>

MB_INIT

/**
 * German ID Combined recognizer result
 */
@property (nonatomic, strong, readonly) MBGermanyCombinedRecognizerResult* result;

@end
