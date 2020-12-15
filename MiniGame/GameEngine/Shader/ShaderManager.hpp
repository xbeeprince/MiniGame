//
//  ShaderManager.hpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp
#include "Game.hpp"

namespace GameEngine {

class ShaderManager {
    
public:
    ShaderManager();
    ~ShaderManager();
    
    
    void CompileShaders(const string& vertex_shader_file_path, const string& fragment_shader_file_path);
    void LinkShaders();
    
    void AddAttribute(const string& attributeName);
    
    GLint GetUniformLocation(const string& uniformName);
    
    void Use();
    void UnUse();
    
private:
    
    int m_numAttributes;
    
    void CompileShader(const string& filePath, GLuint id);
    
    GLuint m_programId;
    
    GLuint m_vertexShaderId;
    GLuint m_fragmentShaderId;
};
}

#endif /* ShaderManager_hpp */
