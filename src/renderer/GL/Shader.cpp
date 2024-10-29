#include <antrock/renderer/GL/Shader.hpp>

Shader::Shader(std::string vertexShaderCode, std::string fragmentShaderCode)
	: vertexShaderCode(vertexShaderCode), fragmentShaderCode(fragmentShaderCode)
{
	createShader();
}

Shader::Shader(const char* vertexShaderCode, const char* fragmentShaderCode)
	: vertexShaderCode(vertexShaderCode), fragmentShaderCode(fragmentShaderCode)
{
	createShader();
}

Shader::~Shader()
{

}

void Shader::use()
{
	std::cout << "[INFO]: " << "Enabling shader" << "\n";
	glUseProgram(shaderID);
}



void Shader::createShader()
{
	std::cout << "[INFO]: " << "Starting shader compilation..." << "\n"; 
	std::cout << "[INFO]: " << "Vertex shader compilation started" << "\n"; 
	int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderCode);
	if (vertexShader == -1)
	{
		std::cout << "[ERROR]: " << "Vertex shader compilation failed!" << "\n";
		glDeleteShader(vertexShader);

		return;
	}
	else
		std::cout << "[INFO]: " << "Vertex shader compilation finished" << "\n"; 

	std::cout << "[INFO]: " << "Fragment shader compilation started" << "\n"; 
	int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
	if (vertexShader == -1)
	{
		std::cout << "[ERROR]: " << "Fragment shader compilation failed!" << "\n";
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return;
	}
	else
		std::cout << "[INFO]: " << "Fragment shader compilation finished" << "\n"; 

	std::cout << "[INFO]: " << "Creating shader program started" << "\n"; 
	shaderID = glCreateProgram();
	std::cout << "[INFO]: " << "Creating shader program finished" << "\n"; 
	
	std::cout << "[INFO]: " << "Linking shaders..." << "\n"; 
	glAttachShader(shaderID, vertexShader);
	glAttachShader(shaderID, fragmentShader);
	glLinkProgram(shaderID);

	GLint isLinked = 0;
	glGetProgramiv(shaderID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);

		glDeleteProgram(shaderID);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		
		std::cout << "[ERROR]: " << "Shader linking failed!" << "\n";
		std::cout << "[OPENGL]: " << "\n";
		for (auto c : infoLog)
			std::cout << c;


		std::cout << "\n";

		return;
	}

	// Always detach shaders after a successful link.
	glDetachShader(shaderID, vertexShader);
	glDetachShader(shaderID, fragmentShader);
}

int Shader::compileShader(unsigned int shaderType, const std::string& shaderSrc)
{
	std::cout << shaderSrc << std::endl;
	int compiledShaderID{};
	const char* shaderSrcs[] = { shaderSrc.c_str() };
	
	compiledShaderID = glCreateShader(shaderType);
	glShaderSource(compiledShaderID, 1, shaderSrcs, 0);
	glCompileShader(compiledShaderID);

	int isCompiled = 0;
	glGetShaderiv(compiledShaderID, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		int maxLength = 0;
		glGetShaderiv(compiledShaderID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(compiledShaderID, maxLength, &maxLength, &infoLog[0]);

		std::cout << "[OPENGL]: " << maxLength << " " << "\n";
		for (auto c : infoLog)
			std::cout << c;

		std::cout << "\n";

		return -1;
	}

	return compiledShaderID;
}

