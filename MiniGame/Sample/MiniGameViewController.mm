//
//  ViewController.m
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#import "MiniGameViewController.hpp"
#include "Application.hpp"
#include "SampleGame.hpp"
#include "TestGame.hpp"
#include <string>


using namespace GameEngine;

@interface MiniGameViewController () {
    Application *_application;
    EAGLContext *_context;
}
@end

@implementation MiniGameViewController

-(instancetype)init {
    if (self = [super init]) {
        
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setupContext];
    
    self.preferredFramesPerSecond = 60;
    
    _application = new Application(new TestGame());
    
    NSString *resource = [[NSBundle mainBundle] resourcePath];
    std::string *res = new std::string([resource UTF8String]);
    _application->initialize(res);
    _application->ready((int)self.view.bounds.size.width * self.view.contentScaleFactor, (int)self.view.bounds.size.height * self.view.contentScaleFactor);
}

- (void)setupContext {
    _context = [[EAGLContext alloc]
                            initWithAPI:kEAGLRenderingAPIOpenGLES3];
    if (!_context) NSLog(@"Failed to create ES context");
    GLKView *view = (GLKView *) self.view;
    view.context = _context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    view.drawableColorFormat = GLKViewDrawableColorFormatSRGBA8888;
    
    EAGLContext.currentContext = _context;
    
}

#pragma mark - GLKViewDelegate
- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    _application->loop();
}

@end
