//
//  ViewController.m
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#import "MiniGameViewController.h"

@interface MiniGameViewController ()

@end

@implementation MiniGameViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setupContext];
}

- (void)setupContext {
    EAGLContext *context = [[EAGLContext alloc]
                            initWithAPI:kEAGLRenderingAPIOpenGLES3];
    if (!context) NSLog(@"Failed to create ES context");
    GLKView *view = (GLKView *) self.view;
    view.context = context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    view.drawableColorFormat = GLKViewDrawableColorFormatSRGBA8888;
    EAGLContext.currentContext = context;
}

#pragma mark - GLKViewDelegate
- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {
    glClearColor(0.2, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}


@end
