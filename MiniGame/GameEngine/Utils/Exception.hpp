//
//  Exception.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#ifndef Exception_hpp
#define Exception_hpp
#include "Game.hpp"

namespace GameEngine {
class Exception {
  
public:
    Exception(const string& message) : reason(message) {
        
    }
    
    const std::string reason;
};
}

#endif /* Exception_hpp */
