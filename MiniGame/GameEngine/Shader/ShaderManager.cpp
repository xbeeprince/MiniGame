//
//  ShaderManager.cpp
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#include "ShaderManager.hpp"
#include "Exception.hpp"

namespace GameEngine {

ShaderManager::ShaderManager() : m_numAttributes(0), m_programId(0), m_vertexShaderId(0), m_fragmentShaderId(0)  {
    
}

ShaderManager::~ShaderManager() {
    
}

void ShaderManager::CompileShaders(const string& vertex_shader_file_path, const string& fragment_shader_file_path) {
    m_programId = glCreateProgram();
    
    m_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    if (m_vertexShaderId == 0) {
        throw Exception("Vertex shader failed to be created!");
    }
    
    m_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    if (m_fragmentShaderId == 0) {
        throw Exception("Fragment shader failed to be created!");
    }
    
    CompileShader(vertex_shader_file_path, m_vertexShaderId);
    CompileShader(fragment_shader_file_path, m_fragmentShaderId);
}

void ShaderManager::LinkShaders() {
    
    glAttachShader(m_programId, m_vertexShaderId);
    glAttachShader(m_programId, m_fragmentShaderId);
    
    glLinkProgram(m_programId);
    
    GLuint isLinked = 0;
    glGetProgramiv(m_programId, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &maxLength);
        
        vector<char> errorLog(maxLength);
        glGetProgramInfoLog(m_programId, maxLength, &maxLength, &errorLog[0]);
        
        glDeleteProgram(m_programId);
        glDeleteShader(m_vertexShaderId);
        glDeleteShader(m_fragmentShaderId);
        
        cout << &(errorLog[0]) << endl;
        throw Exception("Shaders failed to link!");
    }
    
    glDetachShader(m_programId, m_vertexShaderId);
    glDetachShader(m_programId, m_fragmentShaderId);
    glDeleteProgram(m_vertexShaderId);
    glDeleteProgram(m_fragmentShaderId);
    
}

void ShaderManager::AddAttribute(const string &attributeName) {
    glBindAttribLocation(m_programId, m_numAttributes++, attributeName.c_str());
}

GLint ShaderManager::GetUniformLocation(const string &uniformName) {
    GLint location = glGetUniformLocation(m_programId, uniformName.c_str());
    if (location == GL_INVALID_INDEX) {
        throw Exception("Uniform " + uniformName + " not found in shader!");
    }
    
    return location;
}

void ShaderManager::Use() {
    glUseProgram(m_programId);
    
    for (int i = 0; i < m_numAttributes; i++) {
        glEnableVertexAttribArray(i);
    }
}

void ShaderManager::UnUse() {
    glUseProgram(0);
    
    for (int i = 0; i < m_numAttributes; i++) {
        glDisableVertexAttribArray(i);
    }
}

void ShaderManager::CompileShader(const string& filePath, GLuint id) {
    ifstream shaderFile(filePath);
    if (shaderFile.fail()){
        perror(filePath.c_str());
        throw Exception("Failed to open " + filePath);
    }
    
    string fileContent = "";
    string line;
    
    while (getline(shaderFile, line)) {
        fileContent += line + '\n';
    }
    
    shaderFile.close();
    
    const char* contentPtr = fileContent.c_str();
    glShaderSource(id, 1, &contentPtr, nullptr);
    
    glCompileShader(id);
    
    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint maxLength = 0;
        
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        vector<char> errorLog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
        
        glDeleteShader(id);
        
        cout << &(errorLog[0]) << endl;
        throw Exception("Shader " + filePath + " failed to compile");
    }
}

}
