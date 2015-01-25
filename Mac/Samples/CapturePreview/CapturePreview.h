/* -LICENSE-START-
 ** Copyright (c) 2011 Blackmagic Design
 **
 ** Permission is hereby granted, free of charge, to any person or organization
 ** obtaining a copy of the software and accompanying documentation covered by
 ** this license (the "Software") to use, reproduce, display, distribute,
 ** execute, and transmit the Software, and to prepare derivative works of the
 ** Software, and to permit third-parties to whom the Software is furnished to
 ** do so, all subject to the following:
 ** 
 ** The copyright notices in the Software and this entire statement, including
 ** the above license grant, this restriction and the following disclaimer,
 ** must be included in all copies of the Software, in whole or in part, and
 ** all derivative works of the Software, unless such copies or derivative
 ** works are solely in the form of machine-executable object code generated by
 ** a source language processor.
 ** 
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 ** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 ** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 ** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 ** DEALINGS IN THE SOFTWARE.
 ** -LICENSE-END-
 */

#import <Cocoa/Cocoa.h>
#include "DeckLinkAPI.h"
#include <vector>

// Forward declarations
class DeckLinkDeviceDiscovery;
class DeckLinkDevice;

typedef struct {
	// VITC timecodes and user bits for field 1 & 2
	NSString*	vitcF1Timecode;
	NSString*	vitcF1UserBits;
	NSString*	vitcF2Timecode;
	NSString*	vitcF2UserBits;
	
	// RP188 timecodes and user bits (VITC1, VITC2 and LTC)
	NSString*	rp188vitc1Timecode;
	NSString*	rp188vitc1UserBits;
	NSString*	rp188vitc2Timecode;
	NSString*	rp188vitc2UserBits;
	NSString*	rp188ltcTimecode;
	NSString*	rp188ltcUserBits;
} AncillaryDataStruct;

@interface CapturePreviewAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow*						window;
    
	DeckLinkDeviceDiscovery*		deckLinkDiscovery;
    IDeckLinkScreenPreviewCallback*	screenPreviewCallback;
    DeckLinkDevice*                 selectedDevice;
    
	// The following members store values & labels for the 8 pieces of ancillary data (VITC & RP188 F1/F2 timecodes & user bits) 
	NSMutableArray*					ancillaryDataValues;
	NSArray*						ancillaryDataTypes; 
	
	IBOutlet NSView*				previewView;
	
	IBOutlet NSPopUpButton*			deviceListPopup;
	IBOutlet NSPopUpButton*			modeListPopup;
	
	IBOutlet NSButton*				startStopButton;
	
	IBOutlet NSTextField*			noValidSource;
	IBOutlet NSButton*				applyDetectedVideoMode;
	IBOutlet NSTableView*			ancillaryDataTable;
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification;
- (void)applicationWillTerminate:(NSNotification *)notification;

- (void)showErrorMessage:(NSString*)message title:(NSString*)title;

- (IBAction)toggleStart:(id)sender;
- (IBAction)newDeviceSelected:(id)sender;
- (void)enableInterface:(BOOL)enabled;

- (void)refreshVideoModeList;
- (void)startCapture;
- (void)stopCapture;

- (void)addDevice:(IDeckLink*)deckLink;
- (void)removeDevice:(IDeckLink*)deckLink;

- (void)updateInputSourceState:(BOOL)state;
- (void)selectDetectedVideoModeWithIndex:(UInt32)newVideoModeIndex;
- (void)setAncillaryData:(AncillaryDataStruct*) latestAncillaryDataValues;
- (void)reloadAncillaryTable;

- (BOOL)shouldRestartCaptureWithNewVideoMode;

// NSTableView delegate
- (id)tableView:(NSTableView *)aTableView objectValueForTableColumn:(NSTableColumn *)aTableColumn row:(NSInteger)rowIndex;
- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView;


@property (assign) IBOutlet NSWindow *window;

@end
